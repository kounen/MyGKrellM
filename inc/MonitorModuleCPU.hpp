/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleCPU
*/

#ifndef MONITORMODULECPU_HPP_
#define MONITORMODULECPU_HPP_

#define CPU_MODULE_NAME "ModuleCPU"

#define CORES_NUMBER "cat /proc/cpuinfo | grep processor | wc -l"
#define MAX_FREQUENCY "lscpu | grep max | cut -d: -f2"
#define CPU_TEMPERATURE "sensors | grep \"Package id\" | cut -d: -f2 | sed 's/  +//'"

#include "../inc/IMonitorModule.hpp"
#include "../inc/LinuxCommands.hpp"
#include "../inc/Core.hpp"

class MonitorModuleCPU : public IMonitorModule
{
    public:

        MonitorModuleCPU();
        ~MonitorModuleCPU();

        // Get Module Name
        std::string getName() const override;

        // Getters
        int getCoresNumber() const;
        Core &getCore(int identifier) const;
        float getCoreFrequency(int identifier) const;
        size_t getCoreIdentifier(int identifier) const;
        std::string getCoreModelName(int identifier) const;
        size_t getCoreActivityPercentage(int identifier) const;

        float getMaxFrequency() const;

        float getCPUTemperature() const;

    private:
        int  _coresNumber;
        Core **_cores;
};

#endif /* !MONITORMODULECPU_HPP_ */
