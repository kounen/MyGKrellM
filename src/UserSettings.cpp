/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** UserSettings
*/

#include "../inc/UserSettings.hpp"

UserSettings::UserSettings()
{
    this->windowState = DashBoard;
}

UserSettings::~UserSettings()
{
}


int UserSettings::getWidth()
{
    return width;
}

void UserSettings::setWidth(int new_width)
{
    width = new_width;
}

int UserSettings::getHeight()
{
    return height;
}

void UserSettings::setHeight(int new_height)
{
    height = new_height;
}

int UserSettings::getWindowState()
{
    return windowState;
}

void UserSettings::setWindowState(int new_WindowState)
{
    if (new_WindowState < 1 && windowState == 0)
        windowState = 3;
    else
        windowState = new_WindowState % 4;
}