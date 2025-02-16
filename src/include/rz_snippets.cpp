#include "rz_snippets.hpp"

#include <format>
#include <print>
#include <iostream>

Snippets::Snippets() {}

Snippets::~Snippets()
{
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
