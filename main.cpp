/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** main.cpp
*/

#include <cstring>
#include "inc/TestFunctional.hpp"
#include "ncurses/Interface.hpp"
#include "inc/UserSettings.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2 || (std::strcmp(argv[1], "--tests") != 0 && std::strcmp(argv[1], "--text-mode") != 0 && std::strcmp(argv[1], "--graphical-mode") != 0))
    {
        std::cerr << "ERROR: Bad or missing argument!" << std::endl
                  << "--tests             to run units tests" << std::endl
                  << "--text-mode         to run MyGKrellm in text mode" << std::endl
                  << "--graphical-mode    to run MyGKrellm in graphical mode" << std::endl;
    }
    else if (std::strcmp(argv[1], "--tests") == 0)
    {
        UnitTestMemory();
        UnitTestSystem();
        UnitTestCPU();
    }
    else if (std::strcmp(argv[1], "--text-mode") == 0)
    {
        InterfaceNcurses textMode;
        textMode.initDefaultDisplay();
    }
    else
    {
        main_sfml();
    }
    return 0;
}
