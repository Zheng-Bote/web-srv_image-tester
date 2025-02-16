/**
 * @file rz_string_lib.h
 * @author ZHENGH Bote (https://github.com/PacktPublishing/Modern-Cpp-Programming-Cookbook-Third-Edition)
 * @brief header-only; some string functions
 * @version 0.2.0
 * @date 2024-10-13
 *
 * @copyright Copyright (c) 2024 PacktPub
 *
 */

#pragma once

#include <string>
#include <algorithm>
#include <regex>

namespace rz_string_lib
{
  template <typename CharT>
  using tstring = std::basic_string<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

  template <typename CharT>
  using tstringstream = std::basic_stringstream<CharT, std::char_traits<CharT>, std::allocator<CharT>>;

  /**
   * @brief rz_string_lib::to_upper
   *
   * @tparam CharT
   * @param text
   * @return tstring<CharT>
   */
  template <typename CharT>
  inline tstring<CharT> to_upper(tstring<CharT> text)
  {
    std::transform(std::begin(text), std::end(text), std::begin(text), toupper);
    return text;
  }

  /**
   * @brief rz_string_lib::to_lower
   *
   * @tparam CharT
   * @param text
   * @return tstring<CharT>
   */
  template <typename CharT>
  inline tstring<CharT> to_lower(tstring<CharT> text)
  {
    std::transform(std::begin(text), std::end(text), std::begin(text), tolower);
    return text;
  }

  /**
   * @brief rz_string_lib::reverse
   *
   * @tparam CharT
   * @param text
   * @return tstring<CharT>
   */
  template <typename CharT>
  inline tstring<CharT> reverse(tstring<CharT> text)
  {
    std::reverse(std::begin(text), std::end(text));
    return text;
  }

  /**
   * @brief rz_string_lib::trim
   *
   * @tparam CharT
   * @param text
   * @return tstring<CharT>
   */
  template <typename CharT>
  inline tstring<CharT> trim(tstring<CharT> const &text)
  {
    auto first{text.find_first_not_of(' ')};
    auto last{text.find_last_not_of(' ')};
    return text.substr(first, (last - first + 1));
  }

  /**
   * @brief rz_string_lib::trimleft
   *
   * @tparam CharT
   * @param text
   * @return tstring<CharT>
   */
  template <typename CharT>
  inline tstring<CharT> trimleft(tstring<CharT> const &text)
  {
    auto first{text.find_first_not_of(' ')};
    return text.substr(first, text.size() - first);
  }

  /**
   * @brief rz_string_lib::trimright
   *
   * @tparam CharT
   * @param text
   * @return tstring<CharT>
   */
  template <typename CharT>
  inline tstring<CharT> trimright(tstring<CharT> const &text)
  {
    auto last{text.find_last_not_of(' ')};
    return text.substr(0, last + 1);
  }

  /**
   * @brief rz_string_lib::remove
   *
   * @tparam CharT
   * @param text
   * @return tstring<CharT>
   */
  template <typename CharT>
  inline tstring<CharT> remove(tstring<CharT> text, CharT const ch)
  {
    auto start = std::remove_if(std::begin(text), std::end(text), [=](CharT const c)
                                { return c == ch; });
    text.erase(start, std::end(text));
    return text;
  }

  /**
   * @brief std::string replace
   *
   * @param text
   * @param replaceWhat
   * @param replaceWith
   * @return std::string
   */
  inline std::string replace(std::string text, std::string replaceWhat, std::string replaceWith)
  {
    auto position = text.find(replaceWhat);
    while (position != std::string::npos)
    {
      text.replace(position, replaceWhat.size(), replaceWith);
      position = text.find(replaceWhat, position + replaceWhat.size());
    }
    return text;
  }

  /**
   * @brief rz_string_lib::split
   *
   * @tparam CharT
   * @param text
   * @return tstring<CharT>
   */
  template <typename CharT>
  inline std::vector<tstring<CharT>> split(tstring<CharT> text, CharT const delimiter)
  {
    auto sstr = tstringstream<CharT>{text};
    auto tokens = std::vector<tstring<CharT>>{};
    auto token = tstring<CharT>{};
    while (std::getline(sstr, token, delimiter))
    {
      if (!token.empty())
        tokens.push_back(token);
    }

    return tokens;
  }
}
