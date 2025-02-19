/**
 * @file rz_snippets.hpp
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX23 classlib with snippets
 * @details ragpicker for unsorted methods
 * @version 1.1.0
 * @date 2023-04-15
 *
 * @copyright Copyright (c) 2023 ZHENG Robert
 *
 */

#pragma once

#include <print>
#include <string>
#include <tuple>
#include <map>

class Snippets
{
public:
    Snippets();
    ~Snippets();

    std::map<std::string, std::string> getAbout();
    void setSslStatus(std::string &sslStatus);

private:
    std::string prog_ssl{"OFF"};

public:
    enum class Status
    {
        OK,
        ERROR,
        FATAL
    };
    bool checkFunctionReturn(std::tuple<bool, std::string> const &ret,
                             Status statusInstruction = Snippets::Status::ERROR);
};
