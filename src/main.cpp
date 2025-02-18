/* clang++ -std=c++23 main.cpp -lpthread -o main */
/* https://github.com/CrowCpp */

#include <crow.h>
#include <iostream>
#include <print>
#include <tuple>
#include <unordered_map>

#include "include/rz_snippets.hpp"
#include "include/rz_datetime.hpp"
#include "include/rz_filesystem.h"
#include "include/rz_inifile.hpp"
#include "include/rz_config.h"
#include "include/rz_html.h"

// #define CROW_STATIC_DIRECTORY "assets/"

auto sptr_ini_config = std::make_shared<Inifile>();
auto sptr_snippets = std::make_shared<Snippets>();

int main(int argc, char *argv[])
{
  bool oknok{false};
  std::string msg{""};

  if (argc < 2)
  {
    msg = argv[0];
    sptr_ini_config->setIniFileName(msg);
    msg = sptr_ini_config->getInifile();
  }
  else
  {
    msg = argv[1];
  }
  sptr_snippets->checkFunctionReturn(sptr_ini_config->loadIni(msg), Snippets::Status::FATAL);

  // sptr_ini_config->listIniEntries();

  crow::SimpleApp app;

  std::string prog_ssl{"OFF"};
#ifdef PROG_SSL
  if (sptr_ini_config->getUseSsl())
  {
    prog_ssl = "ON";
    app.ssl_file(sptr_ini_config->getSslCert(), sptr_ini_config->getSslKey());
    // app.ssl_file("/path/to/cert.crt", "/path/to/keyfile.key");
    //  app.ssl_file("/path/to/pem_file.pem");
  }
  else
  {
    prog_ssl = "OFF";
  }
#else
  prog_ssl = "OFF";
#endif
  sptr_snippets->setSslStatus(prog_ssl);
  std::println("Webserver SSL is: {}", prog_ssl);

  /* ##### Routing ##### */

  CROW_ROUTE(app, "/")
  ([](const crow::request &, crow::response &res)
   {
        res.set_static_file_info("static/index.html");
        res.end(); });

  CROW_ROUTE(app, "/status")
  ([](const crow::request &, crow::response &res)
   {
        
        res.write("healthy");
        res.code = 200;
        res.end(); });

  CROW_ROUTE(app, "/listini")
  ([]
   {
        crow::json::wvalue x;
        for (const auto &i : sptr_ini_config->getIniEntries()){
            x[i.first] = i.second;
        }
        return x; });

  CROW_ROUTE(app, "/proginfo")
  ([]
   {
        crow::json::wvalue x;
        for (const auto &i : sptr_snippets->getAbout()){
            x[i.first] = i.second;
        }
        return x; });

  CROW_ROUTE(app, "/static/<string>")
  ([](const crow::request &, crow::response &res, std::string para)
   {
        res.set_static_file_info("static/" + para);
        res.end(); });

  CROW_ROUTE(app, "/dirls")
      .methods("POST"_method)([](const crow::request &req)
                              {
          auto x = crow::json::load(req.body);
          if (!x || !x.has("target")){
              return crow::response(400);
          }

          Filesystem fileSystem;
          crow::json::wvalue j;
          std::string path = x["target"].s();
          std::unordered_map<std::string, std::string> uMap;
          uMap = fileSystem.getListDirectory(path);
          for (const auto &n : uMap)
          {
            j[n.first] = n.second;
          }

          return crow::response{j}; });

  CROW_ROUTE(app, "/dirsize")
      .methods("POST"_method)([](const crow::request &req)
                              {
          auto x = crow::json::load(req.body);
          if (!x || !x.has("target")){
              return crow::response(400);
          }

          Filesystem fileSystem;
          crow::json::wvalue j;
          std::string path = x["target"].s();
          int size = fileSystem.calculateDirectorySize(path);
          j["directory size"] = path + ": " + std::to_string(size);
          
          return crow::response{j}; });

  CROW_ROUTE(app, "/crdirs")
      .methods("POST"_method)([](const crow::request &req)
                              {
          auto x = crow::json::load(req.body);
          if (!x || !x.has("target")){
              return crow::response(400);
          }
          std::cout << "target: " << x["target"] << std::endl;

          Filesystem fileSystem;
          crow::json::wvalue j;
          std::string path = x["target"].s();
          if(! fileSystem.createDirectories(path)){
            j["error"] = "failed creating " + path;
          }
          else{
            j["success"] = "created " + path;
          }

          return crow::response{j}; });

  CROW_ROUTE(app, "/static")
  ([](const crow::request &, crow::response &res)
   {
        //replace cat.jpg with your file path
        res.set_static_file_info("static/index.html");
        res.end(); });

  CROW_ROUTE(app, "/about")
  ([]()
   {
            crow::mustache::context ctx;
            ctx["webserver_url"] = sptr_ini_config->getWebserverUrl();
            ctx["webserver_port"] = sptr_ini_config->getWebserverPort();
            ctx["html_header"] = rz_html_lib::HTML_HEADER;
            ctx["html_footer"] = rz_html_lib::HTML_FOOTER;
            ctx["html_title"] = "About";

            auto page = crow::mustache::load("about.html");

            return page.render(ctx); });

  CROW_ROUTE(app, "/uploadfile")
      .methods(crow::HTTPMethod::Post)([](const crow::request &req)
                                       {
          crow::multipart::message file_message(req);
          crow::json::wvalue j;
          std::string pathToOutfile = sptr_ini_config->getUploadPath();

          for (const auto &part : file_message.part_map)
          {
              const auto& part_name = part.first;
              const auto& part_value = part.second;
              std::cout << "Part: " << part_name;
              if ("InputFile" == part_name)
              {
                  // Extract the file name
                  auto headers_it = part_value.headers.find("Content-Disposition");
                  if (headers_it == part_value.headers.end())
                  {
                    std::cout << "No Content-Disposition found";
                    j["error"] = "No Content-Disposition found";
                    //return crow::response(400);
                    return crow::response(j);
                  }
                  auto params_it = headers_it->second.params.find("filename");
                  if (params_it == headers_it->second.params.end())
                  {
                    std::cout << "Part with name \"InputFile\" should have a file";
                    j["error"] = "No file found";
                        return crow::response(j);
                  }
                  const std::string outfile_name{params_it->second};

                  for (const auto& part_header : part_value.headers)
                  {
                      const auto& part_header_name = part_header.first;
                      const auto& part_header_val = part_header.second;
                      std::cout << "Header: " << part_header_name << '=' << part_header_val.value;
                      for (const auto& param : part_header_val.params)
                      {
                          const auto& param_key = param.first;
                          const auto& param_val = param.second;
                          std::cout << " Param: " << param_key << ',' << param_val;
                      }
                  }

                  Filesystem fileSystem;
                  fileSystem.createDirectories(pathToOutfile);
                  pathToOutfile += "/" + outfile_name;
                  // Create a new file with the extracted file name and write file contents to it
                  std::ofstream out_file(pathToOutfile);
                  if (!out_file)
                  {
                    std::cout << " Write to file failed\n";
                    continue;
                  }
                  out_file << part_value.body;
                  out_file.close();
                  std::cout << " Contents written to " << outfile_name << '\n';
              }
              else
              {
                std::cout << " Value: " << part_value.body << '\n';
              }
          }
          j["success"] = "file uploaded: " + pathToOutfile;
          return crow::response(j); });

  std::string prog_build_type = PROG_BUILD_TYPE;
  if (prog_build_type.compare("Debug") == 0)
  {
    app.loglevel(crow::LogLevel::Debug);
  }
  else
  {
    app.loglevel(crow::LogLevel::Warning);
  }

  // app.port(8080).loglevel(crow::LogLevel::Debug).multithreaded().run();
  app.port(sptr_ini_config->getWebserverPort())
      .multithreaded()
      .run();
}
