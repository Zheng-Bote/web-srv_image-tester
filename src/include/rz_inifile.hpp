/**
 * @file rz_inifile.cpp
 * @author ZHENG Robert (www.robert.hase-zheng.net)
 * @brief classlib for inicpp.h
 * @details simple class for reading and writing the inifile
 * @date 2023-04-15
 * @copyright Copyright (c) 2023 ZHENG Robert
 */

#pragma once

#include "inicpp.h"
#include "rz_datetime.hpp"
#include "rz_string_lib.hpp"

class Inifile
{
public:
    Inifile();
    Inifile(std::string &progname);
    Inifile(std::string &path, std::string &progname);
    ~Inifile();

private:
    ini::IniFile myIni;

    std::string pathToInifile;

public:
    void createIni();
    std::tuple<bool, std::string> saveIniToFile(std::string &pathToFile);
    std::tuple<bool, std::string> loadIni(std::string &pathToFile);

    void setIniFileName(std::string &progname);
    void setIniFile(std::string &pathToInifile);
    std::string getInifile();
    void listIniEntries();
    std::map<std::string, std::string> getIniEntries();

    std::string getWebserverUrl();
    unsigned int getWebserverPort();
    std::string getSslCert();
    std::string getSslKey();
    std::string getSslPem();
    bool getUseSsl();

    std::string getSystemWriteDir();
    std::string getUploadPath();
};
