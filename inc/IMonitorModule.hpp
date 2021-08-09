/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <string>
#include "../inc/Error.hpp"
#include <iostream>

class IMonitorModule
{
    public:
        // Dtor
        virtual ~IMonitorModule() {}

        // Get module name
        virtual std::string getName() const = 0;
};

#endif
