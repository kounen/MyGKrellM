/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** LinuxCommands
*/

#include "../inc/LinuxCommands.hpp"

LinuxCommands::LinuxCommands()
{
}

LinuxCommands::~LinuxCommands()
{
}

std::string LinuxCommands::runCommand(const std::string &commandToRun)
{
    char commandBuffer[BUFFER_SIZE] = {0};
    std::string commandResult = "";

    FILE *stream = popen(commandToRun.c_str(), "r");

    try {
        if (!stream)
            throw Error("Popen Failed");
    } catch (const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return "";
    }

    while (!feof(stream))
    {
        if (fgets(commandBuffer, BUFFER_SIZE, stream))
        {
            commandResult += commandBuffer;
        }
    }
    pclose(stream);
    return commandResult;
}
