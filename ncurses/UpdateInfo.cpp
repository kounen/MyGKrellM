/*
** EPITECH PROJECT, 2021
** ncurses
** File description:
** UpdateInfo
*/

#include "../inc/GetInfoGraph.hpp"
#include "../inc/MonitorModuleNetwork.hpp"
#include "../inc/MonitorModuleDisk.hpp"
#include "Interface.hpp"
#include <cmath>
#include <curses.h>
#include <string.h>

int getStickFromPercentage(int per, int heigth)
{
    float doubleSize = ((float)per * (float)heigth) / (float)100.0;
    return (int)round(doubleSize);
}

void DisplayMemory::updateGraphMemory()
{
    std::ofstream loginfo;
    MonitorModuleMemory _memInfo;
    int sizeStick = 0;
    stick *__stick = new stick;
    stick *__stick2 = new stick;

    // Used RAM Info Graph
    sizeStick = getStickFromPercentage(_memInfo.getRamPercentage(), _winDim.y);
    __stick->color = COLOR_PAIR(4);
    __stick->heigth = sizeStick;
    sticksS.push_back(__stick);
    if ((int)sticksU.size() >= (getWinDimension()).x - 13) {
        sticksU.erase(sticksS.begin());
    }

    // Swap Info Graph
    sizeStick = getStickFromPercentage(_memInfo.getSwapPercentage(), _winDim.y);
    __stick2->color = COLOR_PAIR(5);
    __stick2->heigth = sizeStick;
    sticksS.push_back(__stick2);
    if ((int)sticksS.size() >= (getWinDimension()).x - 13) {
        sticksS.erase(sticksS.begin());
    }
}

void DisplayMemory::updateInfoMemory()
{
    GetInfoGraph _memInfo;
    size_t usedRAM = (_memInfo.getInfoGraph(&MonitorModuleMemory::getUsedRam)).getValueSize();
    size_t swapRAM = (_memInfo.getInfoGraph(&MonitorModuleMemory::getUsedSwap)).getValueSize();
    size_t usedRAMPer = (_memInfo.getInfoGraph(&MonitorModuleMemory::getRamPercentage)).getValuePercentage();
    size_t usedSwapPer = (_memInfo.getInfoGraph(&MonitorModuleMemory::getSwapPercentage)).getValuePercentage();

    int beginU = (_winDim.y / 4) - 2;

    if (isFocus()) {
        wattron(win, COLOR_PAIR(1));
        mvwvline(win, 0, _winDim.x - 11, 0, _winDim.y);
        wattroff(win, COLOR_PAIR(1));
    } else mvwvline(win, 0, _winDim.x - 11, 0, _winDim.y);
    mvwprintw(win, beginU > 0 ? beginU : 0, _winDim.x - 10, "Used RAM:");
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, beginU > 0 ? beginU + 1 : 1, _winDim.x - 10, "%d MB", usedRAM);
    mvwprintw(win, beginU > 0 ? beginU + 2 : 2, _winDim.x - 7, "%d%%", usedRAMPer);
    wattroff(win, COLOR_PAIR(1));
    if (isFocus()) {
        wattron(win, COLOR_PAIR(1));
        mvwhline(win, (_winDim.y / 2), _winDim.x - 10, 0, 11);
        wattroff(win, COLOR_PAIR(1));
    } else mvwhline(win, (_winDim.y / 2), _winDim.x - 10, 0, 11);
    mvwprintw(win, (int)((double)_winDim.y * 0.75), _winDim.x - 10, "Swap RAM:");
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, (int)((double)_winDim.y * 0.75) + 1, _winDim.x - 10, "%d MB", swapRAM);
    mvwprintw(win, (int)((double)_winDim.y * 0.75) + 2, _winDim.x - 7, "%d%%", usedSwapPer);
    wattroff(win, COLOR_PAIR(2));
}

void DisplaySys::updateInfoSystem()
{
    int middle = 2;
    std::ofstream loginfo;
    GetInfoGraph _sysInfo;
    std::string hostName = (_sysInfo.getInfoGraph(&MonitorModuleSystem::getHostname)).getValueString();
    std::string operatingSys = (_sysInfo.getInfoGraph(&MonitorModuleSystem::getOperatingSystem)).getValueString();
    std::string kernelVersion = (_sysInfo.getInfoGraph(&MonitorModuleSystem::getKernelVersion)).getValueString();
    std::string dateTime = (_sysInfo.getInfoGraph(&MonitorModuleSystem::getdateTime)).getValueString();
    std::string usrName = (_sysInfo.getInfoGraph(&MonitorModuleSystem::getUsername)).getValueString();
    std::string upTime = (_sysInfo.getInfoGraph(&MonitorModuleMemory::getUpTime)).getValueString();
    std::string loadAverage = (_sysInfo.getInfoGraph(&MonitorModuleMemory::getLoadAverage)).getValueString();

    MonitorModuleDisk disk;
    size_t diskTotal = disk.getTotalSize();
    size_t diskUsed = disk.getUsedSize();
    size_t diskFree = disk.getFreeSize();
    float diskTemp = disk.getDiskTemperature();

    MonitorModuleMemory memory;
    size_t totalRAM = (memory.getTotalRam() / 1024) + 1;
    size_t totalSwap = (memory.getTotalSwap() / 1024) + 1;

    mvwprintw(win, middle, 2, "Hi ");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, middle, 5, "%s !", usrName.c_str());
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 1, 2, "We are the ");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 1, 14, "%s,", dateTime.c_str());
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 2, 2, "you are currently viewing this on a ");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 2, 39, "%s", operatingSys.c_str());
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 2, 39 + (int)operatingSys.size(), " installation.");
    mvwprintw(win, middle + 3, 2, "which has the following kernel version: ");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 3, 42, "%s.", kernelVersion.c_str());
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 4, 2, "By the way, your hostname is ");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 4, 31, "%s.", hostName.c_str());
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 6, 2, "Damn! Your uptime is ");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 6, 23, "%s.", upTime.c_str());
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 8, 2, "Here your load average (for 1min, 5min, 15min respectively) :");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 8, 64, "%s.", loadAverage.c_str());
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 10, 2, "On your hard disk, you are using ");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 10, 35, "%dGB/%dGB", diskUsed, diskTotal);
    wattroff(win, COLOR_PAIR(3));
    mvwprintw(win, middle + 11, 2, "Well, you have always %dGB free space.", diskFree);
    mvwprintw(win, middle + 12, 2, "The hard disk temperature is %.1f degrees.", diskTemp);
    mvwprintw(win, middle + 14, 2, "You have a RAM of %dGB.", totalRAM);
    mvwprintw(win, middle + 15, 2, "You have a Swap of %dGB.", totalSwap);
    wrefresh(win);
}

void DisplayCPU::updateGraphCPU() const
{
    MonitorModuleCPU _CPUinfo;
    int totalCPU = _CPUinfo.getCoresNumber();
    float CPUTemp = _CPUinfo.getCPUTemperature();
    float freq = 0;
    int heigth = 0;
    int activity = 0;
    int freqHz = 0;
    int s = (_winDim.y - 2) / totalCPU;
    std::string modelName = "";

    mvwprintw(win, 2, 2, "The processor temperature is ");
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, 2, 33, "%.1f degrees.", CPUTemp);
    wattroff(win, COLOR_PAIR(3));
    for (int i = 0; i / s < totalCPU; i += s)  {
        freqHz = _CPUinfo.getCoreFrequency(i / s);
        freq = (freqHz * 100) / _CPUinfo.getMaxFrequency();
        heigth = getStickFromPercentage(round(freq), _winDim.x - 15);
        modelName = _CPUinfo.getCoreModelName(i / s);
        wattron(win, COLOR_PAIR(4));
        mvwhline(win, _winDim.y - 2 - i, 15, 0, heigth);
        wattroff(win, COLOR_PAIR(4));
        activity = _CPUinfo.getCoreActivityPercentage(i / s);
        heigth = getStickFromPercentage(activity, _winDim.x - 15);
        wattron(win, COLOR_PAIR(5));
        mvwhline(win, _winDim.y - 3 - i, 15, 0, heigth);
        wattroff(win, COLOR_PAIR(5));
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win, _winDim.y - 2 - i, 2, "freq: %dMHz", freqHz);
        wattroff(win, COLOR_PAIR(1));
        wattron(win, COLOR_PAIR(2));
        mvwprintw(win, _winDim.y - 3 - i, 2, "activity: %d%%", activity);
        wattroff(win, COLOR_PAIR(2));
        mvwprintw(win, _winDim.y - 4 - i, 2, "CPU %d, %s", i / s, modelName.c_str());
    }
    wrefresh(win);
}

void DisplayCPU::updateGraphCPUFS()
{
}

void DisplayNetwork::updateGraphNetwork() const
{
    MonitorModuleNetwork _netInfo;
    size_t transmittedBytes = _netInfo.getTransmitBytes();
    size_t receivedBytes = _netInfo.getReceiveBytes();
    size_t transmitPackages = _netInfo.getTransmitPackets();
    size_t receivedPackages = _netInfo.getReceivePackets();
    int middle = _winDim.x / 4;

    if (isFocus()) {
        wattron(win, COLOR_PAIR(1));
        mvwvline(win, 1, _winDim.x / 2, 0, _winDim.y - 2);
        wattroff(win, COLOR_PAIR(1));
    }
    else mvwvline(win, 1, _winDim.x / 2, 0, _winDim.y - 2);
    mvwprintw(win, 1, middle - 9 > 0 ? middle - 9 : 0, "TRANSMITTED BYTES:");
    wattron(win, COLOR_PAIR(7));
    mvwprintw(win, 2, middle - 6 > 0 ? middle - 6 : 0, "%d bytes", transmittedBytes);
    wattroff(win, COLOR_PAIR(7));
    mvwprintw(win, 3, middle - 12 > 0 ? middle - 12 : 0, "TRANSMITTED PACKAGES: ");
    wattron(win, COLOR_PAIR(7));
    mvwprintw(win, 4, middle - 8 > 0 ? middle - 8 : 0, "%d packages", transmitPackages);
    wattroff(win, COLOR_PAIR(7));
    mvwprintw(win, 1, (static_cast<double>(_winDim.x)* 0.75) - 7, "RECEIVED BYTES: ");
    wattron(win, COLOR_PAIR(7));
    mvwprintw(win, 2, (static_cast<double>(_winDim.x)* 0.75) - 6, "%d bytes", receivedBytes);
    wattroff(win, COLOR_PAIR(7));
    mvwprintw(win, 3, (static_cast<double>(_winDim.x)* 0.75) - 9, "RECEIVED PACKAGES: ");
    wattron(win, COLOR_PAIR(7));
    mvwprintw(win, 4, (static_cast<double>(_winDim.x)* 0.75) - 8, "%d packages", receivedPackages);
    wattroff(win, COLOR_PAIR(7));
    wrefresh(win);
}
