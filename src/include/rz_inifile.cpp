/**
 * @file rz_inifile.cpp
 * @author ZHENG Robert (www.robert.hase-zheng.net)
 * @brief classlib for inicpp.h
 * @details simple class for reading and writing the inifile
 * @date 2023-04-15
 * @copyright Copyright (c) 2023 ZHENG Robert
 */

#include <string>
#include <format>
#include <print>
#include <filesystem>
#include <iostream>

#include "rz_inifile.hpp"

/**
 * @brief Inifile::Inifile
 */
Inifile::Inifile()
{
}

/**
 * @brief Inifile::Inifile
 * @param progname
 */
Inifile::Inifile(std::string &progname)
{
    std::string file = progname + ".ini";
    Inifile::loadIni(file);
}

/**
 * @brief Inifile::Inifile
 * @param path
 * @param progname
 */
Inifile::Inifile(std::string &path, std::string &progname)
{
    std::string pathToFile = path + "/" + progname + ".ini";
    Inifile::loadIni(pathToFile);
}

/**
 * @brief Inifile::~Inifile
 */
Inifile::~Inifile()
{
}

/**
 * @brief Inifile::setIniFileName
 * @param progname
 */
void Inifile::setIniFileName(std::string &progname)
{
    Inifile::pathToInifile = progname + ".ini";
}

/**
 * @brief Inifile::setIniFile
 * @param pathToInifile
 */
void Inifile::setIniFile(std::string &pathToInifile)
{
    Inifile::pathToInifile = pathToInifile;
}

/**
 * @brief Inifile::getInifile
 * @return std::string
 */
std::string Inifile::getInifile()
{
    return Inifile::pathToInifile;
}

/**
 * @brief Inifile::createIni
 */
void Inifile::createIni()
{
    myIni["Webserver"]["url"] = "http://localhost";
    myIni["Webserver"]["port"] = 8080;

    myIni["Webserver"]["ssl_certfile"] = "/path/to/cert.crt";
    myIni["Webserver"]["ssl_keyfile"] = "/path/to/keyfile.key";
    myIni["Webserver"]["ssl_pemfile"] = "none";

    myIni["Webserver"]["write_dir"] = "/tmp";
    myIni["Webserver"]["upload_dir"] = "/tmp/crow_web/uploads";

    /*
    myIni["System"]["PROG_NAME"] = PROG_NAME;
    myIni["System"]["PROG_VERSION"] = PROG_VERSION;
    myIni["System"]["PROG_HOMEPAGE"] = PROG_HOMEPAGE;
    myIni["System"]["PROG_DESCRIPTION"] = PROG_DESCRIPTION;
    myIni["System"]["PROG_BUILD_TYPE"] = PROG_BUILD_TYPE;
    */
}

/**
 * @brief Inifile::saveIniToFile
 * @param pathToFile
 * @return std::tuple<bool, std::string>
 */
std::tuple<bool, std::string> Inifile::saveIniToFile(std::string &pathToFile)
{
    try
    {
        myIni.save(pathToFile);
    }
    catch (...)
    {
        std::cerr << "Write Ini failed; " << pathToFile << std::endl;
        return std::make_tuple(false, "Write Ini failed: " + pathToFile);
    }

    return std::make_tuple(true, "Write Ini successfull: " + pathToFile);
}

/**
 * @brief Inifile::loadIni
 * @param pathToFile
 * @return std::tuple<bool, std::string>
 */
std::tuple<bool, std::string> Inifile::loadIni(std::string &pathToFile)
{
    if (std::filesystem::exists(pathToFile) == 0)
    {
        std::cerr << "doesn't exist or is not readable: " << pathToFile << std::endl;
        // Inifile::pathToInifile = "";
        return std::make_tuple(false, "doesn't exist or is not readable: " + pathToFile);
    }

    Inifile::pathToInifile = pathToFile;
    myIni.load(pathToFile);

    if (myIni.size() < 1)
    {
        std::cerr << "wrong INI size " << myIni.size() << ", should be at least 1 section." << std::endl;

        return std::make_tuple(false,
                               "wrong INI size, should be at least 1 section: " + myIni.size());
    }
    return std::make_tuple(true, "Inifile loaded: " + pathToFile);
}

/**
 * @brief Inifile::getWebserverUrl
 * @return std::string
 */
std::string Inifile::getWebserverUrl()
{
    return myIni["Webserver"]["url"].as<std::string>();
}

/**
 * @brief Inifile::getWebserverPort
 * @return unsigned int
 */
unsigned int Inifile::getWebserverPort()
{
    return myIni["Webserver"]["port"].as<unsigned int>();
}

/**
 * @brief Inifile::getSslCert
 * @return std::string
 */
std::string Inifile::getSslCert()
{
    return myIni["Webserver"]["ssl_certfile"].as<std::string>();
}

/**
 * @brief Inifile::getSslKey
 * @return std::string
 */
std::string Inifile::getSslKey()
{
    return myIni["Webserver"]["ssl_keyfile"].as<std::string>();
}

/**
 * @brief Inifile::getSslPem
 * @return std::string
 */
std::string Inifile::getSslPem()
{
    return myIni["Webserver"]["ssl_pemfile"].as<std::string>();
}

/**
 * @brief Inifile::getUseSsl
 * @return bool
 */
bool Inifile::getUseSsl()
{
    return myIni["Webserver"]["use_ssl"].as<bool>();
}

/**
 * @brief Inifile::getSystemWriteDir
 * @return std::string
 */
std::string Inifile::getSystemWriteDir()
{
    return myIni["Webserver"]["write_dir"].as<std::string>();
}

/**
 * @brief Inifile::getUploadPath
 * @return std::string
 */
std::string Inifile::getUploadPath()
{
    return myIni["Webserver"]["upload_dir"].as<std::string>();
}

/**
 * @brief Inifile::listIniEntries()
 * @return void
 */
void Inifile::listIniEntries()
{
    std::println("Parsed ini contents");
    std::println("Has {} sections", myIni.size());
    for (const auto &sectionPair : myIni)
    {
        const std::string &sectionName = sectionPair.first;
        const ini::IniSection &section = sectionPair.second;

        std::string out = "\nSection '" + sectionName + "' has " + std::to_string(section.size()) + " fields";
        int len = (int)out.length();

        // std::cout << "Section '" << sectionName << "' has " << section.size() << " fields" << std::endl;
        std::println("{}", out);
        std::cout << std::setfill('*') << std::setw(len) << "\n";

        for (const auto &fieldPair : sectionPair.second)
        {
            const std::string &fieldName = fieldPair.first;
            const ini::IniField &field = fieldPair.second;

            std::println("{}={}", fieldName, field.as<std::string>());
        }
    }
}

/**
 * @brief Inifile::getIniEntries
 * @return std::map<std::string, std::string>
 */
std::map<std::string, std::string> Inifile::getIniEntries()
{
    std::map<std::string, std::string> iniMap;

    for (const auto &sectionPair : myIni)
    {
        const std::string &sectionName = sectionPair.first;
        const ini::IniSection &section = sectionPair.second;

        for (const auto &fieldPair : sectionPair.second)
        {
            const std::string &fieldName = fieldPair.first;
            const ini::IniField &field = fieldPair.second;

            iniMap[sectionName + ": " + fieldName] = field.as<std::string>();
        }
    }

    return iniMap;
}
