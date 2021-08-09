/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleSystem
*/

#ifndef MONITORMODULESYSTEM_HPP_
#define MONITORMODULESYSTEM_HPP_

#define SYSTEM_MODULE_NAME "ModuleSystem"

#include <sys/utsname.h>
#include <ctime>
#include <pwd.h>
#include <unistd.h>

#include "IMonitorModule.hpp"

class MonitorModuleSystem : public IMonitorModule
{
    public:
        MonitorModuleSystem();

        std::string getName() const override;

        std::string getHostname() const;
        std::string getOperatingSystem() const;
        std::string getKernelVersion() const;
        std::string getdateTime() const;

        std::string getUsername() const;

        void setSystemInformations();

    protected:
        std::string _hostname;
        std::string _operatingSystem;
        std::string _kernelVersion;
};

#endif /* !MONITORMODULESYSTEM_HPP_ */
