/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#define CPU_MODEL "cat /proc/cpuinfo | grep \"model name\" | sed -n '"
#define CPU_FREQUENCY "cat /proc/cpuinfo | grep MHz | sed -n '"
#define CPU_STAT "cat /proc/stat | grep cpu"

#define FREQUENCY_PERIOD 5
#define ACTIVITY_PERIOD 5

#include <string>
#include <sstream>
#include <time.h>

#include "../inc/LinuxCommands.hpp"

class Core
{
    public:
        Core(const int &identifier);
        ~Core();

        size_t getIdentifier() const;
        std::string getModelName() const;
        float getFrequency();
        size_t getActivityPercentage();

    private:
        size_t _identifier;
        std::string _modelName;
        float _frequency;
        size_t _activityPercentage;

        size_t _prevTotal;
        size_t _prevIdle;

        time_t _lastFrequencyCall;
        time_t _lastActivityPercentageCall;
};

#endif /* !CORE_HPP_ */
