/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** main_sfml
*/

#include "../inc/UserSettings.hpp"

void Events(sf::RenderWindow &window, UserSettings &settings)
{
    sf::Event event;
    while (window.pollEvent(event)) {
        settings.isMouseLeftButtonClick = false;
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            settings.setWindowState((settings.getWindowState() - 1));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            settings.setWindowState((settings.getWindowState() + 1));
    }

}

bool mouseInEntity(sf::RenderWindow &window, sf::Text entity)
{
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    // retrieve the bounding box of the sprite
    sf::FloatRect bounds = entity.getGlobalBounds();

    // hit test
    return (bounds.contains(mouse));
}

void MenuChanger(sf::Text &text, UserSettings &settings, int type, sf::RenderWindow &window)
{
    if (mouseInEntity(window, text) || settings.getWindowState() == type) {
        text.setFillColor(sf::Color::White);
        if (mouseInEntity(window, text))
            text.setStyle(sf::Text::Underlined);
        if (mouseInEntity(window, text) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            settings.setWindowState(type);
    }
    else
        text.setFillColor(sf::Color(77, 97, 107));

}

void printMenus(sf::RenderWindow &window, UserSettings &settings)
{
    sf::Text CPU;
    sf::Text System;
    sf::Text RAM;
    sf::Text Disk;
    sf::Text DashBoard;
    sf::Font font;
    std::vector<sf::Text> textArray;

    if (!font.loadFromFile("font/OpenSans-Regular.ttf"))
        exit(2);
    DashBoard.setString("DashBoard");
    Disk.setString("Disk");
    CPU.setString("CPU");
    System.setString("System");
    RAM.setString("RAM");
    CPU.setFont(font);
    Disk.setFont(font);
    DashBoard.setFont(font);
    System.setFont(font);
    RAM.setFont(font);
    DashBoard.setCharacterSize(23);
    DashBoard.setOrigin((float)30 / 2, (window.getSize().y / 4) / 2);
    RAM.setOrigin((float)50 / 2, ( 2 * window.getSize().y / 4) / 2);
    CPU.setOrigin((float)50 / 2, (3 * window.getSize().y / 4) / 2);
    System.setOrigin((float)50 / 2, (4 * window.getSize().y / 4) / 2);
    Disk.setOrigin((float)50 / 2, (5 * window.getSize().y / 4) / 2);
    DashBoard.setPosition((float)30, window.getSize().y / 4);
    RAM.setPosition((float)50,  2 * window.getSize().y / 4);
    CPU.setPosition((float)50, 3 * window.getSize().y / 4);
    System.setPosition((float)50, 4 * window.getSize().y / 4);
    Disk.setPosition((float)50, 5 * window.getSize().y / 4);

    MenuChanger(DashBoard, settings, 0, window);
    MenuChanger(RAM, settings, 1, window);
    MenuChanger(CPU, settings, 2, window);
    MenuChanger(System, settings, 3, window);
    MenuChanger(Disk, settings, 4, window);
    window.draw(DashBoard);
    window.draw(RAM);
    window.draw(CPU);
    window.draw(System);
}

void printLine(sf::RenderWindow &window)
{
    sf::RectangleShape line(sf::Vector2f(2, window.getSize().y));
    line.setOrigin(1, window.getSize().y / 2);
    line.setPosition(sf::Vector2f(150, window.getSize().y / 2));
    window.draw(line);
}

void menuManage(sf::RenderWindow &window, UserSettings &settings)
{
    printLine(window);
    printMenus(window, settings);

}

void Draw(sf::RenderWindow &window, UserSettings &settings)
{
    graphManage(window, settings);
    menuManage(window, settings);
}

int main_sfml()
{
    sf::Clock genClock;
    UserSettings settings;
    sf::ContextSettings settings_;
    settings_.antialiasingLevel = 128;


    sf::RenderWindow window(sf::VideoMode(settings.getWidth(), settings.getHeight()), "Computer vitals", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(15);

    while (window.isOpen()) {
        Events(window, settings);
        if (sf::Time(genClock.getElapsedTime()).asMilliseconds() > 50) {
            genClock.restart();
            window.clear(sf::Color(53, 66, 78));
            Draw(window, settings);
        }
        window.display();
    }
    return 0;
}