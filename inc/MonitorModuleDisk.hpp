/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleDisk
*/

#ifndef MONITORMODULEDISK_HPP_
#define MONITORMODULEDISK_HPP_

#define DISK_MODULE_NAME "ModuleDisk"
#define DISK_TEMPERATURE "sensors | grep Composite | cut -d: -f2 | sed 's/    +//'"

#include <sys/statvfs.h>

#include "../inc/IMonitorModule.hpp"
#include "../inc/LinuxCommands.hpp"

class MonitorModuleDisk : public IMonitorModule
{
    public:
        MonitorModuleDisk();

        // Get Module Name
        std::string getName() const override;

        size_t getTotalSize();
        size_t getUsedSize();
        size_t getFreeSize();

        float getDiskTemperature() const;

        void resetDiskInformations();

    private:
        size_t _totalSize;
        size_t _usedSize;
        size_t _freeSize;
};

#endif /* !MONITORMODULEDISK_HPP_ */
