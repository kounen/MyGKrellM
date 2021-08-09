/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** DisplayModules
*/


#include "Interface.hpp"
#include <curses.h>
#include <iostream>

DisplaySys::DisplaySys()
    :_isFocus(false), _isDisplayed(true), _isFullscreen(false)
{
    this->_winDim = {
        .y = ((LINES / 2)) - 5,
        .x = ((COLS / 2) - 1),
        .starty = 0,
        .startx = 0
    };
    this->win = newwin(this->_winDim.y, this->_winDim.x, this->_winDim.starty, this->_winDim.startx);
    this->oldWinDim = this->_winDim;
}

DisplaySys::~DisplaySys()
{
    delwin(win);
}

winDim DisplaySys::getWinDimension() const
{
    return _winDim;
}

bool DisplaySys::isFocus() const
{
    return _isFocus;
}

bool DisplaySys::isPorcentage() const
{
    return _isDisplayed;
}

bool DisplaySys::isDisplayed() const
{
    return _isDisplayed;
}

void DisplaySys::updateFunc()
{
    updateInfoSystem();
    drawSquare();
    wrefresh(win);
}

WINDOW *DisplaySys::getWindow() const
{
    return win;
}

void DisplaySys::drawSquare() const
{
    if (isDisplayed() == false)
        return;
    if (isFocus())
        wattron(win, COLOR_PAIR(1));
    box(win, 0, 0);
    mvwprintw(win, 0, (_winDim.x / 2) - 5, "System Info");
}

void DisplaySys::setFocus(bool focus)
{
    this->_isFocus = focus;
}

void DisplaySys::setIsDisplayed(bool disp)
{
    this->_isDisplayed = disp;
}

bool DisplaySys::isFullscreen() const
{
    return _isFullscreen;
}

void DisplaySys::setFullscreen()
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

void DisplaySys::setWinDimensions(winDim newDims)
{
    this->oldWinDim = this->_winDim;
    this->_winDim = newDims;
}

void DisplaySys::resetDefaultDimensions()
{
    this->_winDim = this->oldWinDim;
}

winDim DisplaySys::getLastWinDim() const
{
    return this->oldWinDim;
}
