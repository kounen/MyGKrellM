/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** LinuxCommands
*/

#ifndef LINUXCOMMANDS_HPP_
#define LINUXCOMMANDS_HPP_

#define BUFFER_SIZE 128

#include <string>
#include "../inc/Error.hpp"
#include <iostream>

class LinuxCommands
{
    public:
        LinuxCommands();
        ~LinuxCommands();

        static std::string runCommand(const std::string &command);
};

#endif /* !LINUXCOMMANDS_HPP_ */
