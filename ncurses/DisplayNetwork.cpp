/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** DisplayModules
*/


#include "Interface.hpp"
#include <curses.h>
#include <iostream>

DisplayNetwork::DisplayNetwork()
    : _isFocus(false), _isDisplayed(true), _isFullscreen(false)
{
    this->_winDim = {
        .y = 6,
        .x = (COLS / 2) - 1,
        .starty = (LINES / 2) - 5,
        .startx = 0
    };
    this->win = newwin(this->_winDim.y, this->_winDim.x, this->_winDim.starty, this->_winDim.startx);
    this->oldWinDim = this->_winDim;
}

DisplayNetwork::~DisplayNetwork()
{
    delwin(win);
}

winDim DisplayNetwork::getWinDimension() const
{
    return _winDim;
}

bool DisplayNetwork::isFocus() const
{
    return _isFocus;
}

bool DisplayNetwork::isPorcentage() const
{
    return _isDisplayed;
}

bool DisplayNetwork::isDisplayed() const
{
    return _isDisplayed;
}

void DisplayNetwork::updateFunc()
{
    drawSquare();
    updateGraphNetwork();
}

WINDOW *DisplayNetwork::getWindow() const
{
    return win;
}

void DisplayNetwork::drawSquare() const
{
    if (isDisplayed() == false)
        return;
    if (isFocus())
        wattron(win, COLOR_PAIR(1));
    box(win, 0, 0);
    mvwprintw(win, 0, (_winDim.x / 2) - 6, "Network Info");
}

void DisplayNetwork::setFocus(bool focus)
{
    this->_isFocus = focus;
}

void DisplayNetwork::setIsDisplayed(bool disp)
{
    this->_isDisplayed = disp;
}

bool DisplayNetwork::isFullscreen() const
{
    return _isFullscreen;
}

void DisplayNetwork::setFullscreen()
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

void DisplayNetwork::setWinDimensions(winDim newDims)
{
    this->oldWinDim = this->_winDim;
    this->_winDim = newDims;
}

void DisplayNetwork::resetDefaultDimensions()
{
    this->_winDim = this->oldWinDim;
}

winDim DisplayNetwork::getLastWinDim() const
{
    return this->oldWinDim;
}
