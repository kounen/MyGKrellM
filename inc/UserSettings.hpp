/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** UserSettings
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <cmath>

class UserSettings {
    public:
        UserSettings();
        ~UserSettings();
        int getWidth();
        void setWidth(int);
        int getHeight();
        void setHeight(int);
        int getWindowState();
        void setWindowState(int);
        enum WindowType {DashBoard, RAM, CPU, System};
        int isMouseLeftButtonClick = false;

    protected:
        int windowState;
        int width = 1500;
        int height = 1000;
};

void graphManage(sf::RenderWindow &, UserSettings &);
bool mouseInEntity(sf::RenderWindow &window, sf::Text entity);
int main_sfml();