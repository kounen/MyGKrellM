/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleMemory
*/

#ifndef MONITORMODULEMEMORY_HPP_
#define MONITORMODULEMEMORY_HPP_

#define MEMORY_MODULE_NAME "ModuleMemory"

#include <sys/sysinfo.h>
#include <iomanip>

#include "IMonitorModule.hpp"

class MonitorModuleMemory : public IMonitorModule
{
    public:
        // Ctor
        MonitorModuleMemory();

        // IMonitorModule methods
        std::string getName() const override;

        // Getter ram infos
        size_t getTotalRam();
        size_t getUsedRam();
        size_t getFreeRam();
        size_t getSharedRam();
        size_t getBufferRam();
        int getRamPercentage();

        // Getter swap infos
        size_t getTotalSwap();
        size_t getUsedSwap();
        size_t getFreeSwap();
        int getSwapPercentage();

        // Getter uptime
        std::string getUpTime();

        // Getter load average
        std::string getLoadAverage();

        // Getter current processes number
        size_t getProcessesNumber();

        // Set module memory infos
        void resetMemoryInformations();

    private:
        // Ram infos
        size_t _totalRam;
        size_t _usedRam;
        size_t _freeRam;
        size_t _sharedRam;
        size_t _bufferRam;

        // Swap infos
        size_t _totalSwap;
        size_t _usedSwap;
        size_t _freeSwap;

        // Uptime info
        std::string _uptime;

        // Current processes number
        size_t _processesNumber;
};

#endif /* !MONITORMODULEMEMORY_HPP_ */
