/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** TestFunctionalMemory.cpp
*/

#include "../inc/TestFunctional.hpp"

void UnitTestSystem()
{
    GetInfoGraph action;
    MonitorModuleSystem system;

    system.setSystemInformations();
    std::cout << "-------- Host Name ---------" << std::endl;
    std::cout << system.getHostname() << std::endl;
    std::cout << "Test OK" <<std::endl;

    std::cout << "-------- Date Time ---------" << std::endl;
    action.getInfoGraph(&MonitorModuleSystem::getdateTime);
    std::cout << action.getValueString();
    std::cout << "Test OK" <<std::endl;

    std::cout << "-------- Kernel Version ---------" << std::endl;
    std::cout << system.getKernelVersion() << std::endl;
    std::cout << "Test OK" <<std::endl;

    std::cout << "-------- Operating System ---------" << std::endl;
    std::cout << system.getOperatingSystem() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleSystem::getUsername);
    std::cout << "-------- Operating System ---------" << std::endl;
    std::cout << action.getValueString() << std::endl;
    std::cout << "Test OK" <<std::endl;

    std::cout << "******* Test System OK *******" << std::endl;
    std::cout << std::endl;
}
