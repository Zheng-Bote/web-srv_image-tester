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

  msg = argv[0];
  sptr_ini_config->setIniFileName(msg);
  msg = sptr_ini_config->getInifile();
  sptr_snippets->checkFunctionReturn(sptr_ini_config->loadIni(msg), Snippets::Status::FATAL);

  // sptr_ini_config->listIniEntries();

  crow::SimpleApp app;

  std::string prog_ssl{"OFF"};
#ifdef PROG_SSL
  prog_ssl = "ON";
  app.ssl_file("/path/to/cert.crt", "/path/to/keyfile.key");
  // app.ssl_file("/path/to/pem_file.pem");
#else
  prog_ssl = "OFF";
#endif

  std::println("Webserver SSL is: {}", prog_ssl);

  CROW_ROUTE(app, "/")
  ([]()
   { return "Hello world"; });

  CROW_ROUTE(app, "/status")
  ([](const crow::request &, crow::response &res)
   {
        
        res.write("healthy");
        res.code = 200;
        res.end(); });

  CROW_ROUTE(app, "/static/<string>")
  ([](const crow::request &, crow::response &res, std::string para)
   {
        res.set_static_file_info("static/" + para);
        res.end(); });

  /* ################### */

  CROW_ROUTE(app, "/json")
  ([]
   {
    Filesystem fileSystem;
    //fileSystem.getListDirectory("/tmp");

    //crow::json::wvalue x({{"message", "Hello, World!"}});

     crow::json::wvalue x;
     std::unordered_map<std::string, std::string> uMap;
     uMap = fileSystem.getListDirectory("/tmp");
     for (const auto &n : uMap){
      x[n.first] = n.second;
     }
       //x["message2"] = "Hello, World.. Again!";
     return x; });

  CROW_ROUTE(app, "/jsons")
  ([](const crow::request &req)
   {
    crow::json::wvalue x;
    if (req.url_params.get("target") != nullptr)
    {
      Filesystem fileSystem;
      std::string path = req.url_params.get("target");
      std::unordered_map<std::string, std::string> uMap;
      uMap = fileSystem.getListDirectory(path);
      for (const auto &n : uMap)
      {
        x[n.first] = n.second;
      }        
    }
    else {
      x["message1"] = "Hello, World!";
      x["usage"] = "/json?target=/tmp";
    }
      return x; });

  CROW_ROUTE(app, "/params")
  ([](const crow::request &req)
   {
        std::ostringstream os;
        os << "Params: " << req.url_params << "\n\n";
        os << "The key 'foo' was " << (req.url_params.get("foo") == nullptr ? "not " : "") << "found.\n";
        os << "foo string: " << req.url_params.get("foo") << "\n\n";
         if (req.url_params.get("pew") != nullptr)
        {
            double countD = crow::utility::lexical_cast<double>(req.url_params.get("pew"));
            os << "The value of 'pew' is " << countD << '\n';
        }
        auto count = req.url_params.get_list("count");
        os << "The key 'count' contains " << count.size() << " value(s).\n";
        for (const auto& countVal : count)
        {
            os << " - " << countVal << '\n';
        }
        return crow::response{os.str()}; });

  CROW_ROUTE(app, "/main")
  ([](const crow::request &, crow::response &res)
   {
        //replace cat.jpg with your file path
        res.set_static_file_info("main.cpp");
        res.end(); });

  CROW_ROUTE(app, "/static")
  ([](const crow::request &, crow::response &res)
   {
        //replace cat.jpg with your file path
        res.set_static_file_info("static/erg.txt");
        res.end(); });

  CROW_ROUTE(app, "/template")
  ([]()
   {
      //crow::mustache::set_global_base("assets");

      auto page = crow::mustache::load("template.html");
            
      crow::mustache::context ctx;
      ctx["html_title"] = "Template";
      ctx["webserver_url"] = sptr_ini_config->getWebserverUrl();
      ctx["webserver_port"] = sptr_ini_config->getWebserverPort();
      ctx["build_type"] = PROG_BUILD_TYPE;


      return page.render(ctx); });

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
