/**
 * @file rz_filesystem.cpp
 * @author ZHENG Bote (robert.hase-zheng.net)
 * @brief CXX20 filesystem library
 * @version 2.0.0
 * @date 2023-03-24
 *
 * @copyright Copyright (c) 2023 ZHENG Robert
 *
 */

#include "rz_filesystem.h"

/**
 * @brief Filesystem::Filesystem
 */
Filesystem::Filesystem() {}

/**
 * @brief Filesystem::createDirectory
 * @param p
 * @return bool
 */
bool Filesystem::createDirectory(const std::filesystem::path &p) noexcept
{
    std::filesystem::path dir = p;

    if (std::filesystem::create_directory(dir, ec))
    {
        std::cout << "Directory created successfully\n";
        return true;
    }
    else
    {
        std::cout << "Failed to create directory\n";
        // std::cout << ec.message() << '\n';
    }

    return false;
}

/**
 * @brief Filesystem::createDirectories
 * @param p
 * @return bool
 */
bool Filesystem::createDirectories(const std::filesystem::path &p) noexcept
{
    std::filesystem::path nested = p;

    try
    {
        if (std::filesystem::create_directories(nested))
        {
            std::cout << "Nested directories created successfully\n";
            return true;
        }
        else
        {
            std::cout << "Failed to create nested directories\n";
            // std::cout << ec.message() << '\n';
        }
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }

    return false;
}

/**
 * @brief Filesystem::copyDirectories
 * @description skip_existing | recursive | directories_only
 * @param src
 * @param dest
 * @return
 */
bool Filesystem::copyDirectories(const std::filesystem::path &src,
                                 const std::filesystem::path &dest) noexcept
{
    const auto copyOptions = std::filesystem::copy_options::skip_existing | std::filesystem::copy_options::recursive | std::filesystem::copy_options::directories_only;
    try
    {
        std::filesystem::copy(src, dest, copyOptions);
        std::cout << "Directories copied successfully\n";
        return true;
    }
    catch (std::filesystem::filesystem_error &e)
    {
        std::cout << e.what() << '\n';
    }
    return false;
}

/**
 * @brief Filesystem::removeDirectory
 * @param p
 * @return bool
 */
bool Filesystem::removeDirectory(const std::filesystem::path &p) noexcept
{
    std::filesystem::path dir = p;

    try
    {
        if (std::filesystem::remove(dir))
        {
            std::cout << "Directory removed\n";
            return true;
        }
        else
        {
            std::cout << "Failed to remove the directory...\n";
            std::cout << ec.message() << '\n';
        }
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }

    return false;
}

/**
 * @brief Filesystem::removeDirectories
 * @param p
 * @return bool
 */
bool Filesystem::removeDirectories(const std::filesystem::path &p) noexcept
{
    std::filesystem::path dir = p;

    try
    {
        const auto cnt = std::filesystem::remove_all(dir);
        std::cout << std::format("removed {} items\n", cnt);
        return true;
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }

    return false;
}

/**
 * @brief Filesystem::isDirectory
 * @param p
 * @return bool
 */
bool Filesystem::isDirectory(const std::filesystem::path &p)
{
    if (std::filesystem::is_directory(p))
    {
        std::cout << "It's a directory\n";
        return true;
    }

    return false;
}

/**
 * @brief Filesystem::listDirectory
 * @param p
 */
void Filesystem::listDirectory(const std::filesystem::path &p)
{
    std::filesystem::path dir = p;

    for (const auto &entry : std::filesystem::directory_iterator(p))
        std::cout << entry.path() << '\n';
}

std::unordered_map<std::string, std::string> Filesystem::getListDirectory(const std::filesystem::path &p)
{
    std::filesystem::path dir = p;
    std::unordered_map<std::string, std::string> uMap;

    if (!Filesystem::isDirectory(p))
    {
        uMap["error"] = "Not a directory: " + p.string();
        return uMap;
    }

    for (const auto &entry : std::filesystem::directory_iterator(p))
    {
        std::filesystem::path path = entry.path();
        // std::cout << "Item: " << entry.path() << " " << Filesystem::getFilePermission(path) << std::endl;
        uMap[entry.path()] = Filesystem::getFilePermission(path);
    }
    return uMap;
}

/**
 * @brief Filesystem::listDirectories
 * @param p
 * @param tabs
 */
void Filesystem::listDirectories(const std::filesystem::path &p, unsigned tabs)
{
    try
    {
        for (const auto &entry : std::filesystem::directory_iterator(p))
        {
            if (tabs > 0)
            {
                std::cout << std::string(tabs, '-');
            }
            if (entry.is_regular_file())
            {
                std::cout << "-> " << std::filesystem::path(entry).filename() << "\n";
            }
            else
            {
                std::cout << entry.path().stem().c_str() << '\n';
            }
            if (entry.is_directory())
            {
                listDirectories(entry.path(), tabs + 1);
            }
        }
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
}

/**
 * @brief Filesystem::showDirectoryTree
 * @param path
 * @return bool
 */
bool Filesystem::showDirectoryTree(const std::string &p)
{
    std::string treePath = "tree " + p;

    // static_cast<void>(std::system(treePath.c_str()));
    uint_fast32_t ret = std::system(treePath.c_str());
    if (ret == 0)
    {
        return true;
    }
    return true;
}

/** @brief Filesystem::calculateDirectorySize
 *  @param dir
 *  @return std::uintmax_t
 */
std::uintmax_t Filesystem::calculateDirectorySize(const std::filesystem::path &dir)
{
    std::uintmax_t size = 0;
    for (const auto &entry : std::filesystem::recursive_directory_iterator(dir))
    {
        if (std::filesystem::is_regular_file(entry.path()))
        {
            size += std::filesystem::file_size(entry.path());
        }
    }
    return size;
}

/**
 * @brief Filesystem::copyFile
 * @description update_existing
 * @param src
 * @param dest
 * @return bool
 */
bool Filesystem::copyFile(const std::filesystem::path &src,
                          const std::filesystem::path &dest) noexcept
{
    const auto copyOptions = std::filesystem::copy_options::update_existing;

    std::filesystem::copy(src, dest, copyOptions);
    try
    {
        std::filesystem::copy(src, dest, copyOptions);
        std::cout << "File copied successfully\n";
        return true;
    }
    catch (std::filesystem::filesystem_error &e)
    {
        std::cout << e.what() << '\n';
    }

    return false;
}

bool Filesystem::copyFiles(const std::filesystem::path &src,
                           const std::filesystem::path &dest) noexcept
{
    const auto copyOptions = std::filesystem::copy_options::update_existing | std::filesystem::copy_options::skip_symlinks;

    std::filesystem::copy(src, dest, copyOptions);

    return false;
}

/**
 * @brief Filesystem::copyFilesRecursive
 * @description update_existing | recursive | skip_symlinks
 * @param src
 * @param dest
 * @return bool
 */
bool Filesystem::copyFilesRecursive(const std::filesystem::path &src,
                                    const std::filesystem::path &dest) noexcept
{
    const auto copyOptions = std::filesystem::copy_options::update_existing | std::filesystem::copy_options::recursive | std::filesystem::copy_options::skip_symlinks;
    try
    {
        std::filesystem::copy(src, dest, copyOptions);
        std::cout << "Directory content copied successfully\n";
        return true;
    }
    catch (std::filesystem::filesystem_error &e)
    {
        std::cout << e.what() << '\n';
    }

    return false;
}

/**
 * @brief Filesystem::isFile
 *
 * @param p
 * @return true
 * @return false
 */
bool Filesystem::isFile(const std::filesystem::path &p)
{
    if (std::filesystem::is_regular_file(p))
    {
        std::cout << "It's a file\n";
        return true;
    }

    return false;
}

/**
 * @brief Filesystem::getFilePermission
 *
 * @param file
 * @return std::string rwxrwxr-x
 */
std::string Filesystem::getFilePermission(const std::filesystem::path &file)
{
    std::filesystem::perms p = std::filesystem::status(file).permissions();

    filePerms f_perms;

    (p & std::filesystem::perms::owner_read) != std::filesystem::perms::none ? f_perms.owner_read = "r" : f_perms.owner_read = "-";
    (p & std::filesystem::perms::owner_write) != std::filesystem::perms::none ? f_perms.owner_write = "w" : f_perms.owner_write = "-";
    (p & std::filesystem::perms::owner_exec) != std::filesystem::perms::none ? f_perms.owner_execute = "x" : f_perms.owner_execute = "-";
    (p & std::filesystem::perms::group_read) != std::filesystem::perms::none ? f_perms.group_read = "r" : f_perms.group_read = "-";
    (p & std::filesystem::perms::group_write) != std::filesystem::perms::none ? f_perms.group_write = "w" : f_perms.group_write = "-";
    (p & std::filesystem::perms::group_exec) != std::filesystem::perms::none ? f_perms.group_execute = "x" : f_perms.group_execute = "-";
    (p & std::filesystem::perms::others_read) != std::filesystem::perms::none ? f_perms.others_read = "r" : f_perms.others_read = "-";
    (p & std::filesystem::perms::others_write) != std::filesystem::perms::none ? f_perms.others_write = "w" : f_perms.others_write = "-";
    (p & std::filesystem::perms::others_exec) != std::filesystem::perms::none ? f_perms.others_execute = "x" : f_perms.others_execute = "-";
    return (f_perms.owner_read + f_perms.owner_write + f_perms.owner_execute + f_perms.group_read + f_perms.group_write + f_perms.group_execute + f_perms.others_read + f_perms.others_write + f_perms.others_execute);
}

/**
 * @brief Filesystem::getLastWriteTime
 *
 * @param file
 * @return std::string (UTC, eg 2024-10-09T07:41+0000)
 */
std::string Filesystem::getLastWriteTime(const std::filesystem::path &file)
{
    // std::setlocale(LC_TIME, "de_DE.UTF-8");
    auto ftime = std::filesystem::last_write_time(file);
    return std::format("{0:%F}T{0:%R%z}", ftime);
}

/**
 * @brief Filesystem::showFileSizeHuman
 *
 * @param file
 */
void Filesystem::showFileSizeHuman(const std::filesystem::path &file) noexcept
{
    try
    {
        std::cout << std::filesystem::path(file).filename() << " size: " << HumanReadable{std::filesystem::file_size(file)} << '\n';
    }
    catch (std::filesystem::filesystem_error &e)
    {
        std::cout << e.what() << '\n';
    }
}

/**
 * @brief Filesystem::getFileSize
 *
 * @param file
 * @return std::uintmax_t
 */
std::uintmax_t Filesystem::getFileSize(const std::filesystem::path &file)
{
    return std::filesystem::file_size(file);
}

/**
 * @brief Filesystem::getAbsolutePath
 *
 * @param p
 * @return std::string
 */
std::string Filesystem::getAbsolutePath(const std::filesystem::path &p)
{
    return std::filesystem::absolute(p);
}

/**
 * @brief Filesystem::getRelativePath
 *
 * @param basePath
 * @param absolutePath
 * @return std::string
 */
std::string Filesystem::getRelativePath(const std::filesystem::path &basePath, const std::filesystem::path &absolutePath)
{
    return std::filesystem::relative(absolutePath, basePath);
}

/**
 * @brief Filesystem::getDiskCapacity
 *
 * @param fs
 * @return std::uintmax_t
 */
std::uintmax_t Filesystem::getDiskCapacity(std::string const &fs)
{
    std::filesystem::space_info device = std::filesystem::space(fs);
    return device.capacity;
}

/**
 * @brief Filesystem::getDiskFree
 *
 * @param fs
 * @return std::uintmax_t
 */
std::uintmax_t Filesystem::getDiskFree(std::string const &fs)
{
    std::filesystem::space_info device = std::filesystem::space(fs);
    return device.free;
}

/**
 * @brief Filesystem::getDiskAvailable
 *
 * @param fs
 * @return std::uintmax_t
 */
std::uintmax_t Filesystem::getDiskAvailable(std::string const &fs)
{
    std::filesystem::space_info device = std::filesystem::space(fs);
    return device.available;
}

/**
 * @brief Filesystem::diskUsagePercent
 *
 * @param si
 * @param is_privileged
 * @return std::uintmax_t
 */
std::uintmax_t Filesystem::diskUsagePercent(const std::filesystem::space_info &si, bool is_privileged) noexcept
{
    const uint32_t hundred = 100;
    if (constexpr std::uintmax_t X(-1);
        si.capacity == 0 || si.free == 0 || si.available == 0 ||
        si.capacity == X || si.free == X || si.available == X)
        return hundred;

    std::uintmax_t unused_space = si.free, capacity = si.capacity;
    if (!is_privileged)
    {
        const std::uintmax_t privileged_only_space = si.free - si.available;
        unused_space -= privileged_only_space;
        capacity -= privileged_only_space;
    }
    const std::uintmax_t used_space{capacity - unused_space};
    return hundred * used_space / capacity;
}
/**
 * @brief Filesystem::printDiskSpaceInfo
 *
 * @param dir
 * @param width
 */
void Filesystem::printDiskSpaceInfo(std::string const &dir, int width)
{
    const uint32_t kB = 1024;
    (std::cout << std::left).imbue(std::locale("en_GB.UTF-8"));

    for (const auto s : {"Capacity", "Free", "Available", "Use%", "Dir"})
        std::cout << "│ " << std::setw(width) << s << ' ';

    std::cout << '\n';

    std::error_code ec;
    const std::filesystem::space_info si = std::filesystem::space(dir);
    for (auto x : {si.capacity / kB, si.free / kB, si.available / kB, diskUsagePercent(si)})
        std::cout << "│ " << std::setw(width) << static_cast<std::intmax_t>(x) << ' ';
    std::cout << "│ " << dir << '\n';
}

void Filesystem::setFileStructure(std::string &pathToFile)
{
    namespace fs = std::filesystem;
    fs::path file_path = pathToFile;

    fileStruct.fileName = file_path.filename().string();
    fileStruct.fileBasename = file_path.stem().string();
    fileStruct.fileSuffix = file_path.extension().string();
    fileStruct.fileAbolutePath = file_path.string();
    fileStruct.size = fs::file_size(file_path);
    // fileStruct.last_modified = fs::last_write_time(file_path);

    // std::time_t modified_time = std::chrono::system_clock::to_time_t(last_modified);
    // std::cout << "Last Modified: " << std::ctime(&modified_time);
}
