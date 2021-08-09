/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleNetwork
*/

#include "../inc/MonitorModuleNetwork.hpp"

MonitorModuleNetwork::MonitorModuleNetwork()
    : _receiveBytes(0), _receivePackets(0), _transmitBytes(0),
      _transmitPackets(0), _lastResetCall(0)
{
}

std::string MonitorModuleNetwork::getName() const
{
    return NETWORK_MODULE_NAME;
}

size_t MonitorModuleNetwork::getReceiveBytes()
{
    resetNetworkInformations();
    return _receiveBytes;
}

size_t MonitorModuleNetwork::getReceivePackets()
{
    resetNetworkInformations();
    return _receivePackets;
}

size_t MonitorModuleNetwork::getTransmitBytes()
{
    resetNetworkInformations();
    return _transmitBytes;
}

size_t MonitorModuleNetwork::getTransmitPackets()
{
    resetNetworkInformations();
    return _transmitPackets;
}

void MonitorModuleNetwork::resetNetworkInformations()
{
    if (time(0) > _lastResetCall + NETWORK_PERIOD)
    {
        std::string networkInfoString = LinuxCommands::runCommand(NET_INFOS);
        std::stringstream networkInfoStream;
        size_t receiveBytes, receivePackets, transmitBytes, transmitPackets, trash;

        networkInfoStream << networkInfoString;

        networkInfoStream   >> receiveBytes >> receivePackets
                            >> trash >> trash >> trash >> trash >> trash >> trash
                            >> transmitBytes >> transmitPackets;
        _receiveBytes = receiveBytes;
        _receivePackets = receivePackets;
        _transmitBytes = transmitBytes;
        _transmitPackets = transmitPackets;
        _lastResetCall = time(0);
    }
}
