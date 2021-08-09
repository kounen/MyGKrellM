/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** MonitorModuleMemory
*/

#include "../inc/MonitorModuleMemory.hpp"

MonitorModuleMemory::MonitorModuleMemory()
	: _totalRam(0), _usedRam(0), _freeRam(0), _sharedRam(0), _bufferRam(0),
	  _totalSwap(0), _usedSwap(0), _freeSwap(0), _processesNumber(0)
{
}

std::string MonitorModuleMemory::getName() const
{
	return MEMORY_MODULE_NAME;
}

size_t MonitorModuleMemory::getTotalRam()
{
	resetMemoryInformations();
	return _totalRam;
}

size_t MonitorModuleMemory::getUsedRam()
{
	resetMemoryInformations();
	return _usedRam;
}

size_t MonitorModuleMemory::getFreeRam()
{
	resetMemoryInformations();
	return _freeRam;
}

size_t MonitorModuleMemory::getSharedRam()
{
	resetMemoryInformations();
	return _sharedRam;
}

size_t MonitorModuleMemory::getBufferRam()
{
	resetMemoryInformations();
	return _bufferRam;
}

int MonitorModuleMemory::getRamPercentage()
{
	resetMemoryInformations();
	return static_cast<int>((_usedRam * 100) / _totalRam);
}

size_t MonitorModuleMemory::getTotalSwap()
{
	resetMemoryInformations();
	return _totalSwap;
}

size_t MonitorModuleMemory::getUsedSwap()
{
	resetMemoryInformations();
	return _usedSwap;
}

size_t MonitorModuleMemory::getFreeSwap()
{
	resetMemoryInformations();
	return _freeSwap;
}

int MonitorModuleMemory::getSwapPercentage()
{
	resetMemoryInformations();
	return static_cast<int>((_usedSwap * 100) / _totalSwap);
}

std::string MonitorModuleMemory::getUpTime()
{
	resetMemoryInformations();
	return _uptime;
}

std::string MonitorModuleMemory::getLoadAverage()
{
	double loadAverages[3];
	std::stringstream loadAveragesStream;

	try
	{
		if (getloadavg(loadAverages, 3) == -1)
			throw Error("getloadavg failed");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	loadAveragesStream << std::setprecision(3) << loadAverages[0] << ", " << std::setprecision(3) << loadAverages[1] << ", " << std::setprecision(3) << loadAverages[2];
	return loadAveragesStream.str();
}

size_t MonitorModuleMemory::getProcessesNumber()
{
	resetMemoryInformations();
	return _processesNumber;
}

void MonitorModuleMemory::resetMemoryInformations() //TODO error handling
{
	const unsigned long megabyte = 1024 * 1024;
	const long minute = 60;
	const long hour = minute * 60;
	const long day = hour * 24;
	struct sysinfo si;

	try
	{
		if (sysinfo(&si) == -1)
			throw Error("sysinfo failed");
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	_totalRam = si.totalram / megabyte;
	_usedRam = (si.totalram - si.freeram) / megabyte;
	_freeRam = si.freeram / megabyte;
	_sharedRam = si.sharedram / megabyte;
	_bufferRam = si.bufferram / megabyte;
	_totalSwap = si.totalswap / megabyte;
	_usedSwap = (si.totalswap - si.freeswap) / megabyte;
	_freeSwap = si.freeswap / megabyte;
	_uptime = std::to_string(si.uptime / day) + " days, " + std::to_string((si.uptime % day) / hour) + ":" + std::to_string((si.uptime % hour) / minute) + ":" + std::to_string(si.uptime % minute);
	_processesNumber = static_cast<size_t>(si.procs);
}
