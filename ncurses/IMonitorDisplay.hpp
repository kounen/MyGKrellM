/*
** EPITECH PROJECT, 2021
** IMONITORDISPLAY_HPP_
** File description:
** IMonitorDisplay
*/


#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <vector>
#include <ncurses.h>

struct winDim {
    int y;
    int x;
    int starty;
    int startx;
};

class sticks;
class IMonitorDisplay {
    public:
        IMonitorDisplay() {};
        virtual ~IMonitorDisplay() {};

        virtual winDim getWinDimension() const = 0;
        virtual bool isFocus() const = 0;
        virtual bool isPorcentage() const = 0;
        virtual bool isDisplayed() const = 0;
        virtual bool isFullscreen() const = 0;
        virtual void updateFunc() = 0;
        virtual WINDOW *getWindow() const = 0;
        virtual void drawSquare() const = 0;
        virtual void setFocus(bool) = 0;
        virtual void setWinDimensions(winDim) = 0;
        virtual void resetDefaultDimensions() = 0;
        virtual void setFullscreen() = 0;
        virtual void setIsDisplayed(bool) = 0;
};

#endif /* IMONITORDISPLAY_HPP_ */
