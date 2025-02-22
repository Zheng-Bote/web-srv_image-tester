/**
 * @file rz_filesystem.h
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 filesystem library
 * @version 2.0.0
 * @date 2023-03-24
 *
 * @copyright Copyright (c)2023 ZHENG Robert
 *
 */

#pragma once

#include <filesystem>
#include <format>
#include <print>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <cmath>

#include <unordered_map>

/**
 * @brief The Filesystem class
 */
class Filesystem
{
public:
  Filesystem();

  struct fileStructure
  {
    std::string fileName{""};        // 2014-04-18_203353.jpg
    std::string fileBasename{""};    // 2014-04-18_203353
    std::string fileSuffix{""};      // jpg
    std::string fileAbolutePath{""}; // /home/zb_bamboo/DEV/__NEW__/CPP/qt_convert_image/images
    uintmax_t size{0};               // in bytes
    std::chrono::system_clock::time_point last_modified;
  };

private:
  std::error_code ec{};
  fileStructure fileStruct;

  struct filePerms
  {
    std::string owner_read{"-"};
    std::string owner_write{'-'};
    std::string owner_execute{'-'};
    std::string group_read{"-"};
    std::string group_write{'-'};
    std::string group_execute{'-'};
    std::string others_read{"-"};
    std::string others_write{'-'};
    std::string others_execute{'-'};
  };

  struct HumanReadable
  {
    std::uintmax_t size{};

    template <typename Os>
    friend Os &operator<<(Os &os, HumanReadable hr)
    {
      int i{};
      double mantissa = hr.size;
      for (; mantissa >= 1024.; ++i)
      {
        mantissa /= 1024.;
      }
      mantissa = std::ceil(mantissa * 10.) / 10.;
      os << mantissa << "BKMGTPE"[i];
      return i == 0 ? os : os << "B (" << hr.size << ')';
    }
  };

public:
  // directories
  bool createDirectory(const std::filesystem::path &p) noexcept;
  bool createDirectories(const std::filesystem::path &p) noexcept;
  bool copyDirectories(const std::filesystem::path &src, const std::filesystem::path &dest) noexcept;
  bool removeDirectory(const std::filesystem::path &p) noexcept;
  bool removeDirectories(const std::filesystem::path &p) noexcept;
  bool isDirectory(const std::filesystem::path &p);
  bool showDirectoryTree(const std::string &p);

  void listDirectory(const std::filesystem::path &p);
  std::unordered_map<std::string, std::string> getListDirectory(const std::filesystem::path &p);
  void listDirectories(const std::filesystem::path &p, unsigned tabs = 0);

  std::uintmax_t calculateDirectorySize(const std::filesystem::path &dir);

  // files
  void setFileStructure(std::string &pathToFile);
  bool copyFile(const std::filesystem::path &src, const std::filesystem::path &dest) noexcept;
  bool copyFiles(const std::filesystem::path &src, const std::filesystem::path &dest) noexcept;
  bool copyFilesRecursive(const std::filesystem::path &src,
                          const std::filesystem::path &dest) noexcept;
  bool isFile(const std::filesystem::path &p);

  void showFileSizeHuman(const std::filesystem::path &file) noexcept;

  std::string getFileSizeHuman(const std::filesystem::path &file) noexcept;

  std::string getFilePermission(const std::filesystem::path &file);
  std::string getLastWriteTime(const std::filesystem::path &file);
  std::uintmax_t getFileSize(const std::filesystem::path &file);

  // mixed
  std::string
  getAbsolutePath(const std::filesystem::path &p);
  std::string getRelativePath(const std::filesystem::path &basePath, const std::filesystem::path &absolutePath);

  std::uintmax_t getDiskCapacity(std::string const &fs);
  std::uintmax_t getDiskFree(std::string const &fs);
  std::uintmax_t getDiskAvailable(std::string const &fs);

  std::uintmax_t
  diskUsagePercent(const std::filesystem::space_info &si,
                   bool is_privileged = false) noexcept;
  void printDiskSpaceInfo(std::string const &dir, int width = 14);

  std::unordered_map<std::string, std::string> getVisibleMounts();
};
