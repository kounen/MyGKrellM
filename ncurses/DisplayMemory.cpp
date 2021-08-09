/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** DisplayModules
*/


#include "Interface.hpp"
#include "../inc/MonitorModuleMemory.hpp"
#include <curses.h>
#include <iostream>

DisplayMemory::DisplayMemory()
    :sticksU({}), sticksS({}), _isFocus(false), _isDisplayed(true), _isFullscreen(false)
{
    this->_winDim = {
        .y = ((LINES / 2)) - 1,
        .x = ((COLS / 2) - 1),
        .starty = (LINES/ 2) + 1,
        .startx = 0
    };
    this->win = newwin(this->_winDim.y, this->_winDim.x, this->_winDim.starty, this->_winDim.startx);
    this->oldWinDim = this->_winDim;
}

DisplayMemory::~DisplayMemory()
{
    delwin(win);
}

winDim DisplayMemory::getWinDimension() const
{
    return _winDim;
}

bool DisplayMemory::isFocus() const
{
    return _isFocus;
}

bool DisplayMemory::isPorcentage() const
{
    return _isDisplayed;
}

bool DisplayMemory::isDisplayed() const
{
    return _isDisplayed;
}

void DisplayMemory::updateFunc()
{
    static int fst_call = 0;
    MonitorModuleMemory _memInfo;
    int currentProcesses =_memInfo.getProcessesNumber();

    wclear(win);
    updateInfoMemory();
    updateGraphMemory();
    drawSquare();
    wrefresh(win);
    displayStick(win, sticksU, _winDim);
    displayStick(win, sticksS, _winDim);
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, _winDim.y - 2, (_winDim.x - 13) / 2 - 23, "Current process(es): %d", currentProcesses);
    wattroff(win, COLOR_PAIR(1));
    wrefresh(win);
    fst_call ++;
}

WINDOW *DisplayMemory::getWindow() const
{
    return win;
}

void DisplayMemory::drawSquare() const
{
    if (isDisplayed() == false)
        return;
    if (isFocus())
        wattron(win, COLOR_PAIR(1));
    box(win, 0, 0);
    mvwprintw(win, 0, (_winDim.x / 2) - 4, "RAM Info");
    mvwprintw(win, 0, 0, "100%%");
    mvwprintw(win, (_winDim.y / 2) - 1, 0, "50%%");
    mvwprintw(win, _winDim.y - 1, 0, "0%%");
}

std::vector<stick*> DisplayMemory::getSticksUsedRAM() const
{
    return sticksU;
}

std::vector<stick*> DisplayMemory::getSticksSwapRAM() const
{
    return sticksS;
}

void DisplayMemory::setFocus(bool focus)
{
    this->_isFocus = focus;
}

void DisplayMemory::setIsDisplayed(bool disp)
{
    this->_isDisplayed = disp;
}

void DisplayMemory::setFullscreen()
{
    if (_isFullscreen == false) {
        winDim newDims = {
            .y = LINES,
            .x = COLS,
            .starty = 0,
            .startx = 0
        };
        setWinDimensions(newDims);
        _isFullscreen = true;
    } else {
        resetDefaultDimensions();
        _isFullscreen = false;
    }
}

bool DisplayMemory::isFullscreen() const
{
    return _isFullscreen;
}

void DisplayMemory::setWinDimensions(winDim newDims)
{
    this->oldWinDim = this->_winDim;
    this->_winDim = newDims;
}

void DisplayMemory::resetDefaultDimensions()
{
    this->_winDim = this->oldWinDim;
}

winDim DisplayMemory::getLastWinDim() const
{
    return this->oldWinDim;
}
