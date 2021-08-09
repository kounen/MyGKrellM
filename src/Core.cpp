/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** Core
*/

#include "../inc/Core.hpp"

Core::Core(const int &identifier)
    : _identifier(identifier), _frequency(0), _activityPercentage(0),
      _prevTotal(0), _prevIdle(0), _lastFrequencyCall(0), _lastActivityPercentageCall(0)
{
    _modelName = LinuxCommands::runCommand(CPU_MODEL + std::to_string(identifier + 1) + "p'");

    size_t position = _modelName.find(':');
    _modelName.erase(0, position + 2);
}

Core::~Core()
{
}

size_t Core::getIdentifier() const
{
    return _identifier;
}

std::string Core::getModelName() const
{
    return _modelName;
}

float Core::getFrequency() //TODO WITH TIME
{
    if (time(0) > _lastFrequencyCall + FREQUENCY_PERIOD)
    {
        std::string frequency = LinuxCommands::runCommand(CPU_FREQUENCY + std::to_string(_identifier + 1) + "p'");

        size_t position = frequency.find(':');
        frequency.erase(0, position + 2);
        _frequency = std::stof(frequency);
        _lastFrequencyCall = time(0);
    }
    return _frequency;
}

size_t Core::getActivityPercentage() //TODO WITH TIME
{
    if (time(0) > _lastActivityPercentageCall + ACTIVITY_PERIOD)
    {
        std::stringstream activityPercentageStream;
        std::string activityPercentageString;
        size_t user, nice, system, idle, iowait, irq, softirq;

        activityPercentageString = LinuxCommands::runCommand(CPU_STAT + std::to_string(_identifier));
        activityPercentageStream << activityPercentageString.erase(0, 4);
        activityPercentageStream >> user >> nice >> system >> idle >> iowait >> irq >> softirq;

        size_t total = user + nice + system + idle + iowait + irq + softirq;
        size_t diffIdle = idle - _prevIdle;
        size_t diffTotal = total - _prevTotal;

        _activityPercentage = (1000 * (diffTotal - diffIdle) / diffTotal + 5) / 10;
        _prevTotal = total;
        _prevIdle = idle;

        _lastActivityPercentageCall = time(0);
    }
    return _activityPercentage;
}
