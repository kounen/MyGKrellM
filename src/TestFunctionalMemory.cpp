/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** TestFunctionalMemory.cpp
*/

#include "../inc/TestFunctional.hpp"

void UnitTestMemory()
{
    GetInfoGraph action;
    MonitorModuleSystem system;

    action.getInfoGraph(&MonitorModuleMemory::getRamPercentage);
    std::cout << "-------- Ram Percentage ---------" << std::endl;
    std::cout << action.getValuePercentage() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getTotalRam);
    std::cout << "-------- Total Ram ---------" << std::endl;
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getUpTime);
    std::cout << "-------- Up Time ---------" << std::endl;
    std::cout << action.getValueString() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getBufferRam);
    std::cout << "-------- Buffer Ram ---------" << std::endl;
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getFreeRam);
    std::cout << "-------- Free Ram ---------" << std::endl;
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getFreeSwap);
    std::cout << "-------- Free Swap ---------" << std::endl;
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getName);
    std::cout << "-------- Name ---------" << std::endl;
    std::cout << action.getValueString() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getSharedRam);
    std::cout << "-------- Shared Ram ---------" << std::endl;
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getSwapPercentage);
    std::cout << "-------- Swap Percentage ---------" << std::endl;
    std::cout << action.getValuePercentage() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getUsedRam);
    std::cout << "-------- Used Ram ---------" << std::endl;
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getTotalSwap);
    std::cout << "-------- Total Swap ---------" << std::endl;
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getProcessesNumber);
    std::cout << "-------- Process Number ---------" << std::endl;
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" <<std::endl;

    action.getInfoGraph(&MonitorModuleMemory::getLoadAverage);
    std::cout << "-------- Load Average ---------" << std::endl;
    std::cout << action.getValueString() << std::endl;
    std::cout << "Test OK" <<std::endl;

    std::cout << "******* Test Memory OK *******" << std::endl;
    std::cout << std::endl;
}
