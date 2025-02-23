#include "rz_snippets.hpp"

#include <format>
#include <print>
#include <iostream>
#include <map>

#include "rz_config.h"

/**
 * @brief Snippets::Snippets
 */
Snippets::Snippets() {}

/**
 * @brief Snippets::~Snippets
 */
Snippets::~Snippets()
{
}

/**
 * @brief Snippets::getAbout
 * @return std::map<std::string, std::string>
 */
std::map<std::string, std::string> Snippets::getAbout()
{
    std::map<std::string, std::string> aboutMap;
    aboutMap["PROG_NAME"] = PROG_NAME;
    aboutMap["PROG_VERSION"] = PROG_VERSION;
    aboutMap["PROG_HOMEPAGE"] = PROG_HOMEPAGE;
    aboutMap["PROG_DESCRIPTION"] = PROG_DESCRIPTION;
    aboutMap["PROG_BUILD_TYPE"] = PROG_BUILD_TYPE;

    prog_ssl.compare("ON") == 0 ? aboutMap["PROG_SSL"] = "ON" : aboutMap["PROG_SSL"] = "OFF";

    return aboutMap;
}

/**
 * @brief Snippets::setSslStatus
 * @param sslStatus
 */
void Snippets::setSslStatus(std::string &sslStatus)
{
    prog_ssl = sslStatus;
}

/**
 * @brief Snippets::checkFunctionReturn
 * @param ret (tuple <bool, string>; from called function)
 * @param statusInstruction (OK, ERROR, FATAL, how to handle the ret value)
 * @return bool
 * @description false & ERROR: PLOG_ERROR & return bool, fasle & FATAL: PLOG_FATAL & exit(1)
 */
bool Snippets::checkFunctionReturn(const std::tuple<bool, std::string> &ret,
                                   Status statusInstruction)
{
    bool oknok{false};
    Status status = statusInstruction;
    std::string msg{"blank"};
    std::tie(oknok, msg) = ret;

    if (oknok)
    {
        std::println("checkFunction OK: {}", msg);
    }
    else
    {
        std::cerr << std::format("checkFunction NOK: {}", msg);
        switch (status)
        {
        case Status::OK:
            break;
        case Status::ERROR:
            std::cerr << msg << std::endl;
            oknok = false;
            break;
        case Status::FATAL:
            std::cerr << msg << std::endl;
            exit(EXIT_FAILURE);
            break;
        }
    }
    return oknok;
}
