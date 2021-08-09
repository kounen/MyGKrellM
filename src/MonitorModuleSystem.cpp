/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleSystem
*/

#include "../inc/MonitorModuleSystem.hpp"

MonitorModuleSystem::MonitorModuleSystem()
{
    struct utsname uts;

    try
    {
        if (uname(&uts) == -1)
            throw Error("uname failed");
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    _hostname = uts.nodename;
    _operatingSystem = uts.sysname;
    _kernelVersion = uts.release;
}

std::string MonitorModuleSystem::getName() const
{
    return SYSTEM_MODULE_NAME;
}

std::string MonitorModuleSystem::getHostname() const
{
    return _hostname;
}

std::string MonitorModuleSystem::getOperatingSystem() const
{
    return _operatingSystem;
}

std::string MonitorModuleSystem::getKernelVersion() const
{
    return _kernelVersion;
}

std::string MonitorModuleSystem::getdateTime() const
{
    time_t actualDateTime = time(0);

    return ctime(&actualDateTime);
}

void MonitorModuleSystem::setSystemInformations() //TODO handling error
{

}

std::string MonitorModuleSystem::getUsername() const //TODO error handling
{
    struct passwd *pwd = getpwuid(getuid());

    try
    {
        if (!pwd)
        {
            throw Error("getpwuid failed");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return "";
    }
    return pwd->pw_name;
}
