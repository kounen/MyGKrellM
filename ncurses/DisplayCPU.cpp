/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** DisplayModules
*/


#include "IMonitorDisplay.hpp"
#include "Interface.hpp"
#include <curses.h>
#include <iostream>

DisplayCPU::DisplayCPU()
    : _isFocus(false), _isDisplayed(true), _isFullscreen(false)
{
    this->_winDim = {
        .y = LINES - 1,
        .x = ((COLS / 2) - 1),
        .starty = 0,
        .startx = (COLS / 2) + 1
    };
    this->win = newwin(this->_winDim.y, this->_winDim.x, this->_winDim.starty,
            this->_winDim.startx);
    this->oldWinDim = this->_winDim;
}

DisplayCPU::~DisplayCPU()
{
    delwin(win);
}

winDim DisplayCPU::getWinDimension() const
{
    return _winDim;
}

bool DisplayCPU::isFocus() const
{
    return _isFocus;
}

bool DisplayCPU::isPorcentage() const
{
    return _isDisplayed;
}

bool DisplayCPU::isDisplayed() const
{
    return _isDisplayed;
}

void DisplayCPU::updateFunc()
{
    wclear(win);
    drawSquare();
    if (isFullscreen())
        updateGraphCPUFS();
    else updateGraphCPU();
}

WINDOW *DisplayCPU::getWindow() const
{
    return win;
}

void DisplayCPU::drawSquare() const
{
    if (isDisplayed() == false)
        return;
    if (isFocus())
        wattron(win, COLOR_PAIR(1));
    box(win, 0, 0);
    mvwprintw(win, 0, (_winDim.x / 2) - 2, "CPU Info");
    mvwprintw(win, 0, _winDim.x - 4, "100%%");
    mvwprintw(win, _winDim.y - 1, _winDim.x - 4, "100%%");
    mvwprintw(win, _winDim.y - 1, ((_winDim.x - 15) / 2) + 15, "50%%");
    mvwprintw(win, _winDim.y - 1, 12, "0%%");
}

void DisplayCPU::setFocus(bool focus)
{
    this->_isFocus = focus;
}

void DisplayCPU::setWinDimensions(winDim newDims)
{
    this->oldWinDim = this->_winDim;
    this->_winDim = newDims;
}

void DisplayCPU::resetDefaultDimensions()
{
    this->_winDim = this->oldWinDim;
}

winDim DisplayCPU::getLastWinDim() const
{
    return this->oldWinDim;
}

bool DisplayCPU::isFullscreen() const
{
    return _isFullscreen;
}

void DisplayCPU::setFullscreen()
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

void DisplayCPU::setIsDisplayed(bool disp)
{
    this->_isDisplayed = disp;
}
