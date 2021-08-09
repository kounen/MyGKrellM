/*
** EPITECH PROJECT, 2021
** INTERFACE_HPP_
** File description:
** Interface
*/


#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include <fstream>
#include <string>
#include <ncurses.h>
#include <vector>
#include "IMonitorDisplay.hpp"


class IMonitorModule;

struct stick {
    int heigth;
    int color;
};

class InterfaceNcurses {
    public:
        InterfaceNcurses();
        ~InterfaceNcurses();

        void initDefaultDisplay();
        void setFocus(int idx);
        void setFullscreen(int idx);
        void updateInformation();

    protected:
        std::vector<IMonitorDisplay *> container;
        int cursor;
        std::ofstream logfile;
};

class DisplayMemory : public IMonitorDisplay {
    public:
        DisplayMemory();
        ~DisplayMemory() override;
        winDim getWinDimension() const override;
        bool isFocus() const override;
        bool isPorcentage() const override;
        bool isDisplayed() const override;
        void updateFunc() override;
        void updateInfoMemory();
        void updateGraphMemory();
        WINDOW *getWindow() const override;
        void drawSquare() const override;

        void setWinDimensions(winDim) override;
        void resetDefaultDimensions() override;
        bool isFullscreen() const override;

        std::vector<stick*>getSticksUsedRAM() const;
        std::vector<stick*>getSticksSwapRAM() const;

        void setFocus(bool focus) override;
        void setIsDisplayed(bool disp) override;
        void setFullscreen() override;
        winDim getLastWinDim() const;

    private:
        std::vector<stick*>sticksU;
        std::vector<stick*>sticksS;
        bool _isFocus;
        bool _isDisplayed;
        bool _isFullscreen;
        winDim _winDim;
        WINDOW *win;
        winDim oldWinDim;
};

class DisplayCPU : public IMonitorDisplay {
    public:
        DisplayCPU();
        ~DisplayCPU() override;
        winDim getWinDimension() const override;
        bool isFocus() const override;
        bool isPorcentage() const override;
        bool isDisplayed() const override;
        void updateFunc() override;
        void updateGraphCPU() const;
        WINDOW *getWindow() const override;
        void drawSquare() const override;

        void setFocus(bool focus) override;

        void setWinDimensions(winDim) override;
        void resetDefaultDimensions() override;
        bool isFullscreen() const override;
        void setFullscreen() override;
        winDim getLastWinDim() const;
        void setIsDisplayed(bool disp) override;
        void updateGraphCPUFS();

    private:
        bool _isFocus;
        bool _isDisplayed;
        bool _isFullscreen;
        winDim _winDim;
        WINDOW *win;
        winDim oldWinDim;
};

class DisplayNetwork : public IMonitorDisplay {
    public:
        DisplayNetwork();
        ~DisplayNetwork() override;
        winDim getWinDimension() const override;
        bool isFocus() const override;
        bool isPorcentage() const override;
        bool isDisplayed() const override;
        void updateFunc() override;
        void updateGraphNetwork() const;
        WINDOW *getWindow() const override;
        void drawSquare() const override;

        void setFocus(bool focus) override;

        void setWinDimensions(winDim) override;
        void resetDefaultDimensions() override;
        bool isFullscreen() const override;
        void setIsDisplayed(bool disp) override;
        void setFullscreen() override;
        winDim getLastWinDim() const;

    private:
        bool _isFocus;
        bool _isDisplayed;
        bool _isFullscreen;
        winDim _winDim;
        WINDOW *win;
        winDim oldWinDim;
};

class DisplaySys : public IMonitorDisplay {
    public:
        DisplaySys();
        ~DisplaySys() override;
        winDim getWinDimension() const override;
        bool isFocus() const override;
        bool isPorcentage() const override;
        bool isDisplayed() const override;
        void updateFunc() override;
        WINDOW *getWindow() const override;
        void drawSquare() const override;
        void updateInfoSystem();

        void setFocus(bool focus) override;
        void setFullscreen() override;

        void setWinDimensions(winDim) override;
        void resetDefaultDimensions() override;
        bool isFullscreen() const override;
        void setIsDisplayed(bool disp) override;
        winDim getLastWinDim() const;

    private:
        bool _isFocus;
        bool _isDisplayed;
        bool _isFullscreen;
        winDim _winDim;
        WINDOW *win;
        winDim oldWinDim;
};

void displayStick(WINDOW *win, std::vector<stick *>__sticks, winDim dim);
#endif /* INTERFACE_HPP_ */
