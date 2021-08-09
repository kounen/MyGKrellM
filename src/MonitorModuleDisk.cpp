/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleDisk
*/

#include "../inc/MonitorModuleDisk.hpp"

MonitorModuleDisk::MonitorModuleDisk()
    : _totalSize(0), _usedSize(0), _freeSize(0)
{
}

std::string MonitorModuleDisk::getName() const
{
    return DISK_MODULE_NAME;
}

size_t MonitorModuleDisk::getTotalSize()
{
    resetDiskInformations();
    return _totalSize;
}

size_t MonitorModuleDisk::getUsedSize()
{
    resetDiskInformations();
    return _usedSize;
}

size_t MonitorModuleDisk::getFreeSize()
{
    resetDiskInformations();
    return _freeSize;
}

float MonitorModuleDisk::getDiskTemperature() const
{
    std::string diskTemperature = LinuxCommands::runCommand(DISK_TEMPERATURE);
    try
    {
        if (diskTemperature == "")
        {
            throw Error("Sensors command doesn't exist");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    size_t position = diskTemperature.find('C');
    return std::stof(diskTemperature.erase(position - 2));
}

void MonitorModuleDisk::resetDiskInformations() //TODO Error handling
{
    struct statvfs stat;

    if (statvfs("/home", &stat) != 0)
    {
        return;
    }
    _totalSize = ((((stat.f_blocks * stat.f_bsize) / 1024) / 1024) / 1024);
    _freeSize = ((((stat.f_bfree * stat.f_bsize) / 1024) / 1024) / 1024);

    if (statvfs("/", &stat) != 0)
    {
        return;
    }
    _totalSize += ((((stat.f_blocks * stat.f_bsize) / 1024) / 1024) / 1024);
    _freeSize += ((((stat.f_bfree * stat.f_bsize) / 1024) / 1024) / 1024);

    if (statvfs("/dev", &stat) != 0)
    {
        return;
    }
    _totalSize += ((((stat.f_blocks * stat.f_bsize) / 1024) / 1024) / 1024);
    _freeSize += ((((stat.f_bfree * stat.f_bsize) / 1024) / 1024) / 1024);

    if (statvfs("/tmp", &stat) != 0)
    {
        return;
    }
    _totalSize += ((((stat.f_blocks * stat.f_bsize) / 1024) / 1024) / 1024);
    _freeSize += ((((stat.f_bfree * stat.f_bsize) / 1024) / 1024) / 1024);

    if (statvfs("/run", &stat) != 0)
    {
        return;
    }
    _totalSize += ((((stat.f_blocks * stat.f_bsize) / 1024) / 1024) / 1024);
    _freeSize += ((((stat.f_bfree * stat.f_bsize) / 1024) / 1024) / 1024);

    _usedSize = _totalSize - _freeSize;
}