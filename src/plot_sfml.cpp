/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** plot_sfml
*/

#include "../inc/GetInfoGraph.hpp"
#include "../inc/MonitorModuleMemory.hpp"
#include "../inc/MonitorModuleSystem.hpp"
#include "../inc/MonitorModuleDisk.hpp"
#include "../inc/MonitorModuleNetwork.hpp"
#include "../inc/UserSettings.hpp"

void displayData(int state, sf::RenderWindow &window)
{
    GetInfoGraph action;
    MonitorModuleSystem system;
    MonitorModuleCPU CPU;
    MonitorModuleDisk Disk;
    MonitorModuleNetwork Net;

    displayUsernameCol(action.getInfoGraph(&MonitorModuleSystem::getUsername), window);
    if (state == UserSettings::WindowType::RAM) {
        displayRAMRamPercentage(action.getInfoGraph(&MonitorModuleMemory::getRamPercentage), window);
        displayRAMTotalRam(action.getInfoGraph(&MonitorModuleMemory::getTotalRam), window);
        displayRAMBufferRam(action.getInfoGraph(&MonitorModuleMemory::getBufferRam), window);
        displayRAMFreeRam(action.getInfoGraph(&MonitorModuleMemory::getFreeRam), window);
        displayRAMFreeSwap(action.getInfoGraph(&MonitorModuleMemory::getFreeSwap), window);
        displayRAMSharedRam(action.getInfoGraph(&MonitorModuleMemory::getSharedRam), window);
        displayRAMSwapPercentage(action.getInfoGraph(&MonitorModuleMemory::getSwapPercentage), window);
        displayRAMUsedRam(action.getInfoGraph(&MonitorModuleMemory::getUsedRam), window);
        displayRAMTotalSwap(action.getInfoGraph(&MonitorModuleMemory::getTotalSwap), window);
    } else if (state == UserSettings::WindowType::CPU) {
        for (int i = 0; i < CPU.getCoresNumber() ; i++) {
            action.CoreIdentifier = i;
            displayCoreFrequency(action.getInfoGraph(&MonitorModuleCPU::getCoreFrequency), CPU, window); // >> action.getValueFloat();
            displayCoreIdentifier(action.getInfoGraph(&MonitorModuleCPU::getCoreIdentifier), CPU, window); // >> action.getValueSize();
            displayCoreModelName(action.getInfoGraph(&MonitorModuleCPU::getCoreModelName), CPU, window); // >> action.getValueString();
        }
        action.getInfoGraph(&MonitorModuleMemory::getProcessesNumber);
        action.getInfoGraph(&MonitorModuleMemory::getLoadAverage);
    } else if (state == UserSettings::WindowType::System) {
        displayHostname(action.getInfoGraph(&MonitorModuleSystem::getHostname), window);
        displayKernelVersion(action.getInfoGraph(&MonitorModuleSystem::getKernelVersion), window);
        displayUpTime(action.getInfoGraph(&MonitorModuleMemory::getUpTime), window);
        displayOperatingSystem(action.getInfoGraph(&MonitorModuleSystem::getOperatingSystem), window);
        displaydateTime(action.getInfoGraph(&MonitorModuleSystem::getdateTime), window);
        displayCPUtemp(CPU.getCPUTemperature(), window);
        displayDisktemp(Disk.getDiskTemperature(), window);

        displayNetworkRB(Net.getReceiveBytes(), window);
        displayNetworkRP(Net.getReceivePackets(), window);
        displayNetworkTB(Net.getTransmitBytes(), window);
        displayNetworkTP(Net.getTransmitPackets(), window);
    } else if (state == UserSettings::WindowType::DashBoard) {
        displayRAMRamPercentage(action.getInfoGraph(&MonitorModuleMemory::getRamPercentage), window);
        action.getInfoGraph(&MonitorModuleMemory::getLoadAverage);
        displayDiskUsage(Disk.getTotalSize(), Disk.getUsedSize(), Disk.getFreeSize(), window);
        displayDisktemp(Disk.getDiskTemperature(), window);
        displayNetworkRB(Net.getReceiveBytes(), window);
        displayNetworkRP(Net.getReceivePackets(), window);
        displayNetworkTB(Net.getTransmitBytes(), window);
        displayNetworkTP(Net.getTransmitPackets(), window);
        displayLoadAverage(action.getInfoGraph(&MonitorModuleMemory::getLoadAverage), window);
    }
}

void graphManage(sf::RenderWindow &window, UserSettings &settings)
{
    int state = settings.getWindowState();
    displayData(state, window);
}