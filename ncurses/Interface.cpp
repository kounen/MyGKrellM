/*
** EPITECH PROJECT, 2021
** ncurses
** File description:
** Interface
*/

#include "Interface.hpp"
#include "../inc/MonitorModuleMemory.hpp"
#include "../inc/MonitorModuleSystem.hpp"
#include "IMonitorDisplay.hpp"
#include <fstream>
#include <ncurses.h>
#include <curses.h>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

InterfaceNcurses::InterfaceNcurses()
{
    this->container = {};
    this->cursor = 0;

}

InterfaceNcurses::~InterfaceNcurses()
{
}

void displayStick(WINDOW *win, std::vector<stick *>__sticks, winDim dim)
{
    if (__sticks.empty())
        return;
    for (int j = 0; j < (int)__sticks.size() && dim.x - 12 -j > 2; j++) {
        int startY = dim.y - __sticks[j]->heigth - 1;
        wattron(win, __sticks[j]->color);
        mvwvline(win, (startY <= 0) ? 1 : startY + 1, dim.x - 12 - j, 0, __sticks[j]->heigth - 1);
        wattroff(win, __sticks[j]->color);
    }
}

void InterfaceNcurses::setFocus(int idx)
{
    for (auto &e : this->container)
        if (e->isFocus())
            e->setFocus(false);
    this->container[idx]->setFocus(true);
}

void initColors()
{
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_GREEN);
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(6, COLOR_BLACK, COLOR_RED);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(9, COLOR_BLACK, COLOR_BLACK);
}

void InterfaceNcurses::updateInformation()
{
    for (auto &e : this->container)
        e->updateFunc();
}

void InterfaceNcurses::setFullscreen(int idx)
{
    if (this->container[idx]->isFullscreen() == false) {
        this->container[idx]->setFullscreen();
        for (auto &e : this->container)
            e->setIsDisplayed(false);
        this->container[idx]->setIsDisplayed(true);
    } else {
        this->container[idx]->setFullscreen();
        for (auto &e : this->container)
            e->setIsDisplayed(true);
    }
}

void InterfaceNcurses::initDefaultDisplay()
{
    int key = 0;
    initscr();
    noecho();
    cbreak();
    clear();
    initColors();
    nodelay(stdscr, true);

    // Add modules into vector
    this->container.push_back(new DisplaySys());
    this->container.push_back(new DisplayCPU());
    this->container.push_back(new DisplayNetwork());
    this->container.push_back(new DisplayMemory());
    setFocus(0);
    do {
        updateInformation();
        key = getch();

        switch (key) {
            case 'l':
                this->cursor += 1;
                if (this->cursor == static_cast<int>(this->container.size()))
                    this->cursor = 0;
                setFocus(this->cursor);
                break;
            case 'j':
                this->cursor -= 1;
                if (this->cursor == -1)
                    this->cursor = this->container.size() - 1;
                setFocus(this->cursor);
                break;
            case 'd':
                this->container.erase(this->container.begin() + cursor);
                this->cursor -= 1;
                clear();
                break;
                /*case 'f':
                  clear();
                  setFullscreen(this->cursor);
                  break;*/
            default:
                break;
        }
    } while ((key != 'q') && (key != 'Q'));
    endwin();
}
