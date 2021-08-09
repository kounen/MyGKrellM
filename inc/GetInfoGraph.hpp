/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** GetInfoGraph.hpp
*/

#ifndef GETINFOGRAPH_HPP_
#define GETINFOGRAPH_HPP_
#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include "MonitorModuleMemory.hpp"
#include "MonitorModuleSystem.hpp"
#include "MonitorModuleCPU.hpp"
#include <SFML/Graphics.hpp>

class GetInfoGraph
{
private:
    MonitorModuleMemory m_action;
    MonitorModuleSystem m_action_system;
    MonitorModuleCPU m_action_cpu;

    std::string _color;
    size_t _size;
    int _Percentage;
    std::string _String;
    float nb_float;
public:
    using methodSize_t = size_t (MonitorModuleMemory::*)();
    using methodInt = int (MonitorModuleMemory::*)();
    using methodStringConst = std::string (MonitorModuleMemory::*)() const;
    using methodString = std::string (MonitorModuleMemory::*)();

    using methodStringConstSystem = std::string (MonitorModuleSystem::*)() const;

    using methodIntCPU = int (MonitorModuleCPU::*)() const;
    using methodFloatCPU = float (MonitorModuleCPU::*)(int) const;
    using methodSize_tCPU = size_t (MonitorModuleCPU::*)(int) const;
    using methodStringCPU = std::string (MonitorModuleCPU::*)(int) const;

    GetInfoGraph();
    ~GetInfoGraph();

    GetInfoGraph &getInfoGraph(methodSize_t action);
    GetInfoGraph &getInfoGraph(methodInt action);
    GetInfoGraph &getInfoGraph(methodString action);
    GetInfoGraph &getInfoGraph(methodStringConst action);

    GetInfoGraph &getInfoGraph(methodStringConstSystem action);

    GetInfoGraph &getInfoGraph(methodIntCPU action);
    GetInfoGraph &getInfoGraph(methodFloatCPU action);
    GetInfoGraph &getInfoGraph(methodSize_tCPU action);
    GetInfoGraph &getInfoGraph(methodStringCPU action);

    size_t getValueSize() const;
    int getValuePercentage() const;
    std::string getValueString() const;
    float getValueFloat() const;
    sf::Color getColor() const;
    int CoreIdentifier;
};

void displayRAMRamPercentage(GetInfoGraph action, sf::RenderWindow &window);
void displayRAMTotalRam(GetInfoGraph action, sf::RenderWindow &window);
void displayRAMBufferRam(GetInfoGraph action, sf::RenderWindow &window);
void displayRAMFreeRam(GetInfoGraph action, sf::RenderWindow &window);
void displayRAMFreeSwap(GetInfoGraph action, sf::RenderWindow &window);
void displayRAMSharedRam(GetInfoGraph action, sf::RenderWindow &window);
void displayRAMSwapPercentage(GetInfoGraph action, sf::RenderWindow &window);
void displayRAMUsedRam(GetInfoGraph action, sf::RenderWindow &window);
void displayRAMTotalSwap(GetInfoGraph action, sf::RenderWindow &window);
void displayCoreFrequency(GetInfoGraph action, MonitorModuleCPU CPU, sf::RenderWindow &window);
void displayCoreIdentifier(GetInfoGraph action, MonitorModuleCPU CPU, sf::RenderWindow &window);
void displayCoreModelName(GetInfoGraph action, MonitorModuleCPU CPU, sf::RenderWindow &window);
void displayHostname(GetInfoGraph &, sf::RenderWindow &);
void displayKernelVersion(GetInfoGraph &, sf::RenderWindow &);
void displayUpTime(GetInfoGraph &, sf::RenderWindow &);
void displayOperatingSystem(GetInfoGraph &, sf::RenderWindow &);
void displaydateTime(GetInfoGraph &, sf::RenderWindow &);
void displayUsernameCol(GetInfoGraph &action, sf::RenderWindow &window);
void displayCPUtemp(float temp, sf::RenderWindow &window);
void displayDisktemp(float temp, sf::RenderWindow &window);

void displayNetworkRB(size_t, sf::RenderWindow &winfo);
void displayNetworkRP(size_t, sf::RenderWindow &winfo);
void displayNetworkTB(size_t, sf::RenderWindow &winfo);
void displayNetworkTP(size_t, sf::RenderWindow &winfo);
void displayDiskUsage(size_t, size_t, size_t, sf::RenderWindow &window);
void displayLoadAverage(GetInfoGraph action, sf::RenderWindow &window);

#endif
