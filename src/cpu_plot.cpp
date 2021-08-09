/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** cpu_plot
*/

#include "../inc/GetInfoGraph.hpp"
#include "../inc/MonitorModuleMemory.hpp"
#include "../inc/MonitorModuleSystem.hpp"
#include "../inc/UserSettings.hpp"

void displayCoreFrequency(GetInfoGraph action, MonitorModuleCPU CPU, sf::RenderWindow &window)
{
    float pertcentage = (float)action.CoreIdentifier / (float)CPU.getCoresNumber();
    sf::Vector2i pos = sf::Vector2i(1 * (window.getSize().x - 150) / 2 + 150, window.getSize().y * pertcentage);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 2 - 4, (float) window.getSize().y * (float)1 / (float) CPU.getCoresNumber() ));
    sf::RectangleShape Usage(sf::Vector2f((float)(window.getSize().x - 150) / 3, (float) window.getSize().y * (float)1 / ((float) CPU.getCoresNumber() * 3 )));
    sf::RectangleShape BoxUsage(sf::Vector2f((float)(window.getSize().x - 150) / 3, (float) window.getSize().y * (float)1 / ((float) CPU.getCoresNumber() * 3 )));
    sf::Text freq;
    std::string freq_txt("Frequency : ");
    sf::Font font;

    freq_txt.append(std::to_string(CPU.getCoreFrequency(action.CoreIdentifier))).append(" MHz");
    font.loadFromFile("font/OpenSans-Bold.ttf");
    freq.setString(freq_txt);
    freq.setFont(font);
    freq.setPosition(sf::Vector2f(pos.x + window.getSize().y / 18, pos.y + (float) window.getSize().y * (float)1 / (3 * (float) CPU.getCoresNumber())));
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);
    float scaleX = action.getValueFloat() / CPU.getMaxFrequency();
    freq.setFillColor(sf::Color::Black);
    sf::Color col(0, 0, 0);
    if (scaleX < 0.5) {
        col.g = 255;
        col.r = 255 * scaleX;
    } else {
        col.r = 255;
        col.g = 255 * 2 * (1 - scaleX);
    }

    Usage.setScale(scaleX, 1);
    Usage.setFillColor(col);
    BoxUsage.setOutlineThickness(5);
    BoxUsage.setOutlineColor(sf::Color(255, 255, 255));
    BoxUsage.setFillColor(sf::Color(0, 0, 0, 0));
    Usage.setPosition(pos.x + window.getSize().y / 18, pos.y + (float) window.getSize().y * (float)1 / (3 * (float) CPU.getCoresNumber()) );
    BoxUsage.setPosition(pos.x + window.getSize().y / 18, pos.y + (float) window.getSize().y * (float)1 / (3 * (float) CPU.getCoresNumber()) );
    window.draw(Usage);
    window.draw(BoxUsage);
    window.draw(freq);
}

void displayCoreIdentifier(GetInfoGraph action, MonitorModuleCPU CPU, sf::RenderWindow &window)
{
    float pertcentage = (float)action.CoreIdentifier / (float)CPU.getCoresNumber();
    sf::Vector2i pos = sf::Vector2i(1 * (window.getSize().x - 150) / 4 + 150, window.getSize().y * pertcentage);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 4 - 4, (float) window.getSize().y * (float)1 / (float) CPU.getCoresNumber() ));

    sf::RectangleShape Usage(sf::Vector2f((float)(window.getSize().x - 150) / 6, (float) window.getSize().y * (float)1 / ((float) CPU.getCoresNumber() * 3 )));
    sf::RectangleShape BoxUsage(sf::Vector2f((float)(window.getSize().x - 150) / 6, (float) window.getSize().y * (float)1 / ((float) CPU.getCoresNumber() * 3 )));
    sf::Text freq;
    std::string freq_txt("Activity : ");
    sf::Font font;
    freq_txt.append(std::to_string(CPU.getCoreActivityPercentage(action.CoreIdentifier)));
    freq_txt.append("%");
    font.loadFromFile("font/OpenSans-Bold.ttf");
    freq.setString(freq_txt);
    freq.setFont(font);
    freq.setPosition(sf::Vector2f(pos.x + window.getSize().y / 18, pos.y + (float) window.getSize().y * (float)1 / (3 * (float) CPU.getCoresNumber())));
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);
    float scaleX = CPU.getCoreActivityPercentage(action.CoreIdentifier) / 100.00f;
    freq.setFillColor(sf::Color::Black);
    sf::Color col(0, 0, 0);
    if (scaleX < 0.5) {
        col.g = 255;
        col.r = 255 * scaleX;
    } else {
        col.r = 255;
        col.g = 255 * 2 * (1 - scaleX);
    }

    Usage.setScale(scaleX, 1);
    Usage.setFillColor(col);
    BoxUsage.setOutlineThickness(5);
    BoxUsage.setOutlineColor(sf::Color(255, 255, 255));
    BoxUsage.setFillColor(sf::Color(0, 0, 0, 0));
    Usage.setPosition(pos.x + window.getSize().y / 18, pos.y + (float) window.getSize().y * (float)1 / (3 * (float) CPU.getCoresNumber()) );
    BoxUsage.setPosition(pos.x + window.getSize().y / 18, pos.y + (float) window.getSize().y * (float)1 / (3 * (float) CPU.getCoresNumber()) );
    window.draw(Usage);
    window.draw(BoxUsage);
    window.draw(freq);
}

void displayCoreModelName(GetInfoGraph action, MonitorModuleCPU CPU, sf::RenderWindow &window)
{
    float pertcentage = (float)action.CoreIdentifier / (float)CPU.getCoresNumber();
    sf::Vector2i pos = sf::Vector2i(150, window.getSize().y * pertcentage);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 4 - 4, (float) window.getSize().y * (float)1 / (float) CPU.getCoresNumber() ));
    sf::Text title;
    sf::Text value;
    sf::Font font;

    font.loadFromFile("font/OpenSans-Bold.ttf");
    title.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string CPU_name = action.getValueString();

    font.loadFromFile("font/OpenSans-Bold.ttf");
    title.setString(std::string("CPU ").append(std::to_string(action.CoreIdentifier)));
    title.setPosition(pos.x, pos.y + 2 + (window.getSize().y / (float)(CPU.getCoresNumber())) - title.getCharacterSize() - 8);
    value.setFont(font);
    value.setString(CPU_name.substr(0, 17).append("..."));
    value.setPosition(pos.x, pos.y + 2);
    window.draw(title);
    window.draw(value);
}