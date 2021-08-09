/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** TestFunctionalMemory.cpp
*/

#include "../inc/TestFunctional.hpp"

void UnitTestCPU()
{
    GetInfoGraph action;
    MonitorModuleCPU CPU;


    std::cout << "-------- Cores Number ---------" << std::endl;
    action.getInfoGraph(&MonitorModuleCPU::getCoresNumber);
    std::cout << action.getValueSize() << std::endl;
    std::cout << "Test OK" << std::endl;

    std::cout << "-------- Frequency CPU ---------" << std::endl;
    for (int i = 0; i < CPU.getCoresNumber() ; i++) {
        action.CoreIdentifier = i;
        action.getInfoGraph(&MonitorModuleCPU::getCoreFrequency);
        std::cout << action.getValueFloat() << std::endl;
    }
    std::cout << "Test OK" << std::endl;

    std::cout << "-------- Identifier CPU ---------" << std::endl;
    for (int i = 0; i < CPU.getCoresNumber() ; i++) {
        action.CoreIdentifier = i;
        action.getInfoGraph(&MonitorModuleCPU::getCoreIdentifier);
        std::cout << action.getValueSize() << std::endl;
    }
    std::cout << "Test OK" << std::endl;

    std::cout << "-------- Model Name CPU ---------" << std::endl;
    for (int i = 0; i < CPU.getCoresNumber() ; i++) {
        action.CoreIdentifier = i;
        action.getInfoGraph(&MonitorModuleCPU::getCoreModelName);
        std::cout << action.getValueString();
    }

    std::cout << "******* Test CPU OK *******" << std::endl;
    std::cout << std::endl;
}
