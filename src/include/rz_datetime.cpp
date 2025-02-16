/**
 * @file rz_datetime.cpp
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 datetime lib
 * @version 2.2.0
 * @date 2023-03-25
 *
 * @copyright Copyright (c) 2023 ZHENG Robert
 *
 */

// https://en.cppreference.com/w/cpp/chrono/duration/formatter

#include "rz_datetime.hpp"

/**
 * @brief Construct a new Date Time:: Date Time object
 *
 */
DateTime::DateTime()
{
}

DateTime::~DateTime() {}

/**
 * @brief DateTime::getUtcDateTime
 *
 * @return std::string (eg: 2024-10-09T12:29+0000)
 */
std::string DateTime::getUtcDateTimeSys()
{
  auto epoch = std::chrono::utc_clock::now();
  return std::format("{0:%F}T{0:%R%z}", epoch);
}

/**
 * @brief DateTime::getUtcDateTimeHuman
 *
 * @return std::string (eg: 2024-10-09 12:29:21)
 */
std::string DateTime::getUtcDateTimeHuman()
{
  using std::chrono::floor;

  auto epoch = std::chrono::utc_clock::now();
  auto humanTime = floor<std::chrono::seconds>(epoch);

  return std::format("{0:%F} {0:%T}", humanTime);
}

/**
 * @brief DateTime::getFormatedUtcDateTimeHuman
 *
 * @param format (eg: YYYY, YYYY-MM-DD, YYYY-MM-DD_HH-MM, YYYY-MM-DD_HH-MM-SS, HH-MM, HH-MM-SS)
 * @return std::string
 */
std::string DateTime::getFormatedUtcDateTimeHuman(const std::string &format)
{
  using std::chrono::floor;

  auto epoch = std::chrono::utc_clock::now();
  auto humanTime = floor<std::chrono::seconds>(epoch);
  std::string ret{std::format("{0:%F} {0:%T}", humanTime)};

  if (format.compare("YYYY") == 0)
  {
    return std::format("{0:%Y}", humanTime);
  }
  if (format.compare("YYYY-MM-DD") == 0)
  {
    return std::format("{0:%Y-%m-%d}", humanTime);
  }
  if (format.compare("YYYY-MM-DD_HH-MM") == 0)
  {
    return std::format("{0:%Y-%m-%d_%H-%M}", humanTime);
  }
  if (format.compare("YYYY-MM-DD_HH-MM-SS") == 0)
  {
    return std::format("{0:%Y-%m-%d_%H-%M-%S}", humanTime);
  }
  if (format.compare("HH-MM") == 0)
  {
    return std::format("{0:%H-%M}", humanTime);
  }
  if (format.compare("HH-MM-SS") == 0)
  {
    return std::format("{0:%H-%M-%S}", humanTime);
  }
  return ret;
}

/**
 * @brief DateTime::getLocalTime
 *
 * @return std::string (eg: 2024-10-09T12:29+0200)
 */
std::string DateTime::getLocalTimeSys()
{
  using std::chrono::floor;

  auto utcTime = std::chrono::system_clock::now();
  auto localTime = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);
  auto local_Time = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);

  return std::format("{0:%F}T{0:%R%z}", local_Time);
}

/**
 * @brief DateTime::getLocalTimeHuman
 *
 * @return std::string (eg: 2024-10-09 12:29:21)
 */
std::string DateTime::getLocalTimeHuman()
{
  using std::chrono::floor;

  auto utcTime = std::chrono::system_clock::now();
  auto localTime = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);
  auto humanTime = floor<std::chrono::seconds>(localTime.get_local_time());

  return std::format("{0:%F} {0:%T}", humanTime);
}

/**
 * @brief DateTime::getFormatedLocalDateTimeHuman
 *
 * @param format (eg: YYYY, YYYY-MM-DD, YYYY-MM-DD_HH-MM, YYYY-MM-DD_HH-MM-SS, HH-MM, HH-MM-SS)
 * @return std::string
 */
std::string DateTime::getFormatedLocalDateTimeHuman(const std::string &format)
{
  using std::chrono::floor;

  auto epoch = std::chrono::utc_clock::now();
  auto humanTime = floor<std::chrono::seconds>(epoch);
  std::string ret{std::format("{0:%F} {0:%T}", humanTime)};

  if (format.compare("YYYY") == 0)
  {
    return std::format("{0:%Y}", humanTime);
  }
  if (format.compare("YYYY-MM-DD") == 0)
  {
    return std::format("{0:%Y-%m-%d}", humanTime);
  }
  if (format.compare("YYYY-MM-DD_HH-MM") == 0)
  {
    return std::format("{0:%Y-%m-%d_%H-%M}", humanTime);
  }
  if (format.compare("YYYY-MM-DD_HH-MM-SS") == 0)
  {
    return std::format("{0:%Y-%m-%d_%H-%M-%S}", humanTime);
  }
  if (format.compare("HH-MM") == 0)
  {
    return std::format("{0:%H-%M}", humanTime);
  }
  if (format.compare("HH-MM-SS") == 0)
  {
    return std::format("{0:%H-%M-%S}", humanTime);
  }
  return ret;
}

/**
 * @brief DateTime::getCurrentZoneOffset
 *
 * @return std::string (eg: +0200)
 */
std::string DateTime::getCurrentZoneOffset()
{
  // auto offset = std::chrono::current_zone()->get_info(std::chrono::system_clock::now()).offset;
  // return std::format("{%Ez}", offset);

  using std::chrono::floor;

  auto utcTime = std::chrono::system_clock::now();
  auto localTime = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);
  auto local_Time = std::chrono::zoned_time(std::chrono::current_zone(), utcTime);

  return std::format("{0:%z}", local_Time);
}

/**
 * @brief DateTime::showAllTimezones
 *
 */
void DateTime::showAllTimezones()
{
  const std::chrono::tzdb &tzdb{std::chrono::get_tzdb()};
  const std::vector<std::chrono::time_zone> &tzs{tzdb.zones};
  for (const std::chrono::time_zone &tz : tzs)
  {
      std::println("{}", tz.name());
  }
}

/**
 * @brief DateTime::findTimezoneTime
 *
 * @param endName (eg: London)
 * @return std::string
 */
std::string DateTime::findTimezoneTime(const std::string &endName)
{
  std::string ret{""};
  const std::chrono::tzdb &tzdb{std::chrono::get_tzdb()};
  const std::vector<std::chrono::time_zone> &tzs{tzdb.zones};
  const auto &res{std::find_if(tzs.begin(), tzs.end(), [&endName](const std::chrono::time_zone &tz)
                               {
    std::string name{tz.name()};
    return name.ends_with(endName); })};

  if (res != tzs.end())
  {
    try
    {
      const std::string_view myLocation{res->name()};
      const std::chrono::time_point now{std::chrono::system_clock::now()};
      const std::chrono::zoned_time zt_1{myLocation, now};
      // std::cout << myLocation << ": " << zt_1 << '\n';
      ret = std::format("{} {:%Y-%m-%d %H:%M}", myLocation, zt_1);
      // std::cout << "format: " << erg << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::println("{}", e.what());
    }
  }
  return ret;
}
