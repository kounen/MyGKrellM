/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleNetwork
*/

#ifndef MONITORMODULENETWORK_HPP_
#define MONITORMODULENETWORK_HPP_

#include <time.h>
#include <sstream>

#define NETWORK_MODULE_NAME "ModuleNetwork"
#define NET_INFOS "cat /proc/net/dev | grep wl | cut -d: -f2"
#define NETWORK_PERIOD 5

#include "../inc/IMonitorModule.hpp"
#include "../inc/LinuxCommands.hpp"

class MonitorModuleNetwork : public IMonitorModule
{
    public:
        MonitorModuleNetwork();

        // IMonitorModule methods
        std::string getName() const override;

        // Network getters
        size_t getReceiveBytes();
        size_t getReceivePackets();
        size_t getTransmitBytes();
        size_t getTransmitPackets();

        void resetNetworkInformations();

    private:
        size_t _receiveBytes;
        size_t _receivePackets;
        size_t _transmitBytes;
        size_t _transmitPackets;

        time_t _lastResetCall;
};

#endif /* !MONITORMODULENETWORK_HPP_ */
