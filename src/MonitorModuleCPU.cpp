/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleCPU
*/

#include "../inc/MonitorModuleCPU.hpp"

MonitorModuleCPU::MonitorModuleCPU()
    : _coresNumber(std::stoi(LinuxCommands::runCommand(CORES_NUMBER)))
{
    _cores = new Core *[_coresNumber];

    for (int i = 0; i < _coresNumber; i++)
    {
        _cores[i] = new Core(i);
    }
}

MonitorModuleCPU::~MonitorModuleCPU()
{
}

std::string MonitorModuleCPU::getName() const
{
    return CPU_MODULE_NAME;
}

int MonitorModuleCPU::getCoresNumber() const
{
    return _coresNumber;
}

float MonitorModuleCPU::getCoreFrequency(int identifier) const
{
    try
    {
        if (0 > identifier && identifier >= _coresNumber)
        {
            throw Error("Identifier is not correct");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    return (_cores[identifier]->getFrequency());
}

size_t MonitorModuleCPU::getCoreIdentifier(int identifier) const
{
    try
    {
        if (0 > identifier && identifier >= _coresNumber)
        {
            throw Error("Identifier is not correct");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    return (_cores[identifier]->getIdentifier());
}

std::string MonitorModuleCPU::getCoreModelName(int identifier) const
{
    try
    {
        if (0 > identifier && identifier >= _coresNumber)
        {
            throw Error("Identifier is not correct");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    return (_cores[identifier]->getModelName());
}

size_t MonitorModuleCPU::getCoreActivityPercentage(int identifier) const
{
    try
    {
        if (0 > identifier && identifier >= _coresNumber)
        {
            throw Error("Identifier is not correct");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    return (_cores[identifier]->getActivityPercentage());
}

float MonitorModuleCPU::getMaxFrequency() const
{
    std::string maxFrequencyString = LinuxCommands::runCommand(MAX_FREQUENCY);
    std::stringstream maxFrequencyStream;

    maxFrequencyStream << maxFrequencyString;
    return std::stof(maxFrequencyStream.str());
}

float MonitorModuleCPU::getCPUTemperature() const
{
    std::string CPUTemperature = LinuxCommands::runCommand(CPU_TEMPERATURE);
    try
    {
        if (CPUTemperature == "")
        {
            throw Error("Sensors command doesn't exist");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    size_t position = CPUTemperature.find('C');
    return std::stof(CPUTemperature.erase(position - 2));
}
