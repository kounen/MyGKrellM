/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** system_plot
*/

#include "../inc/GetInfoGraph.hpp"
#include "../inc/MonitorModuleMemory.hpp"
#include "../inc/MonitorModuleSystem.hpp"
#include "../inc/UserSettings.hpp"
#include "../plot/PieChart.hpp"

void displayHostname(GetInfoGraph &action, sf::RenderWindow &window)
{
    sf::Vector2i pos = sf::Vector2i( 0 * (window.getSize().x - 150) / 3 + 150, window.getSize().y * 0);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

    sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string RAM = action.getValueString();

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("HostName");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM);
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayKernelVersion(GetInfoGraph &action, sf::RenderWindow &window)
{
    sf::Vector2i pos = sf::Vector2i( 1 * (window.getSize().x - 150) / 3 + 150, window.getSize().y * 0);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

    sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string RAM = action.getValueString();

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Kernel Version");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM);
    text_.setPosition(pos.x + window.getSize().y / 6 - 50, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayUsernameCol(GetInfoGraph &action, sf::RenderWindow &window)
{
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));
    sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);

    sf::RectangleShape line(sf::Vector2f(150, 2));
    line.setPosition(sf::Vector2f(0, 850));
    window.draw(line);

    std::string RAM = action.getValueString();

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("UserName :");
    text.setPosition(0, 850);
    text.setScale(0.8, 1);
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM);
    text_.setPosition(20, 900);
    window.draw(text);
    window.draw(text_);
}

void displayUpTime(GetInfoGraph &action, sf::RenderWindow &window)
{
    sf::Vector2i pos = sf::Vector2i( 2 * (window.getSize().x - 150) / 3 + 150, window.getSize().y * 0);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));
       sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string RAM = action.getValueString();

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Up time");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM);
    text_.setPosition(pos.x + window.getSize().y / 6 - 40, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayOperatingSystem(GetInfoGraph &action, sf::RenderWindow &window)
{
    sf::Vector2i pos = sf::Vector2i( 0 * (window.getSize().x - 150) / 3 + 150,   1 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

       sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string RAM = action.getValueString();

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Operating System");
    text.setPosition(pos.x + window.getSize().y / 6 - 40, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM);
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displaydateTime(GetInfoGraph &action, sf::RenderWindow &window)
{

    sf::Vector2i pos = sf::Vector2i( 1 * (window.getSize().x - 150) / 3 + 150,   1 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

       sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string RAM = action.getValueString().insert(11, "\n");

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("dateTime");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM);
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayCPUtemp(float temp, sf::RenderWindow &window)
{

    sf::Vector2i pos = sf::Vector2i( 2 * (window.getSize().x - 150) / 3 + 150,   1 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

       sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string Temp = std::to_string(temp);

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("CPU Temperature");
    text.setPosition(pos.x + window.getSize().y / 6 - 60, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(Temp.append(" C"));
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayDisktemp(float temp, sf::RenderWindow &window)
{

    sf::Vector2i pos = sf::Vector2i( 0 * (window.getSize().x - 150) / 3 + 150,   2 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

       sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string Temp = std::to_string(temp);

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Disk Temperature");
    text.setPosition(pos.x + window.getSize().y / 6 - 60, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(Temp.append(" C"));
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayNetworkRB(size_t temp, sf::RenderWindow &window)
{
sf::Vector2i pos = sf::Vector2i( 1 * (window.getSize().x - 150) / 3 + 150,   2 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

    std::map<int, std::string> Sizes = {
        {1, " Bytes"},
        {2, " Bytes"},
        {3, " Bytes"},
        {4, " Kbytes"},
        {5, " Kbytes"},
        {6, " Kbytes"},
        {7, " Megabytes"},
        {8, " Megabytes"},
        {9, " Megabytes"},
        {10, " Gigabytes"},
        {11, " Gigabytes"},
    };

    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);
    std::string Temp = "Received Bytes :\n";
    int bytes_order = std::log10(temp);
    Temp.append(std::to_string(temp / std::pow(10, bytes_order)));

    font.loadFromFile("font/OpenSans-Bold.ttf");
    sf::Text text_;
    text_.setFont(font);
    text_.setString(Temp.append(Sizes[bytes_order]));
    text_.setPosition(pos.x - 50 + window.getSize().y / 6, pos.y  - text_.getCharacterSize() - 8 + window.getSize().y / 12);
    window.draw(text_);
}
void displayNetworkRP(size_t temp, sf::RenderWindow &window)
{
sf::Vector2i pos = sf::Vector2i( 1 * (window.getSize().x - 150) / 3 + 150,   2 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

       sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string Temp = "Received Packets :\n";
    Temp.append(std::to_string(temp));

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Reception Speed");
    text.setPosition(pos.x + window.getSize().y / 6 - 50, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(Temp.append(" packets"));
    text_.setPosition(pos.x - 50 + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
    window.draw(text_);
}
void displayNetworkTB(size_t temp, sf::RenderWindow &window)
{
sf::Vector2i pos = sf::Vector2i( 2 * (window.getSize().x - 150) / 3 + 150,   2 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

    std::map<int, std::string> Sizes = {
        {1, " Bytes"},
        {2, " Bytes"},
        {3, " Bytes"},
        {4, " Kbytes"},
        {5, " Kbytes"},
        {6, " Kbytes"},
        {7, " Megabytes"},
        {8, " Megabytes"},
        {9, " Megabytes"},
        {10, " Gigabytes"},
        {11, " Gigabytes"},
    };

    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string Temp = "Transmit Bytes :\n";
    int bytes_order = std::log10(temp);
    Temp.append(std::to_string(temp/std::pow(10, bytes_order)));

    font.loadFromFile("font/OpenSans-Bold.ttf");
    sf::Text text_;
    text_.setFont(font);
    text_.setString(Temp.append(Sizes[bytes_order]));
    text_.setPosition(pos.x - 50 + window.getSize().y / 6, pos.y  - text_.getCharacterSize() - 8 + window.getSize().y / 12);
    window.draw(text_);
}
void displayNetworkTP(size_t temp, sf::RenderWindow &window)
{
sf::Vector2i pos = sf::Vector2i( 2 * (window.getSize().x - 150) / 3 + 150,   2 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));

       sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string Temp = "Transmit Packets :\n";
    Temp.append(std::to_string(temp));

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Transmission Speed");
    text.setPosition(pos.x - 50 + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(Temp.append(" packets"));
    text_.setPosition(pos.x - 50 + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayDiskUsage(size_t total, size_t used, size_t free, sf::RenderWindow &window)
{
    sf::Vector2i pos = sf::Vector2i( 1 * (window.getSize().x - 150) / 3 + 150, window.getSize().y * 0);
    sf::RectangleShape Contener(sf::Vector2f(2 * (float)(window.getSize().x - 150) / 3 - 4, (float) 2 * window.getSize().y / 3 - 4));
    sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);


    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Disk Usage ");
    text.setPosition(pos.x + window.getSize().y / 3, pos.y  - text.getCharacterSize() - 8 +  2 * window.getSize().y / 3 );
    window.draw(text);
    sw::PieChart pieChart;
    pieChart.slices.resize(2);
    pieChart.slices[0].color = sf::Color::Red;
    pieChart.slices[1].color = sf::Color::Green;
    pieChart.slices[0].size = (float)used / (float)total;
    pieChart.slices[1].size = (float)free / (float)total;
    pieChart.slices[0].explode = 0.04f;
    pieChart.slices[1].explode = 0.04f;
    pieChart.setSize({ sf::Vector2f(2 * (float)((window.getSize().x - 150) / 3 - 4) * 0.75f, (float) (2 * window.getSize().y / 3 - 4)) * 0.75f });
    pieChart.update();
    pieChart.setOrigin(pieChart.getSize() / 2.f);
    pieChart.setPosition(pos.x +  5 * window.getSize().y / 12, pos.y  - 8 +  2 * window.getSize().y / 6 );
    sf::Text _free;
    sf::Text _usage;
    sf::Text _total;
    _free.setFont(font);
    _usage.setFont(font);
    _total.setFont(font);

    _free.setString("Free Disk : " + std::to_string(free) + " Go");
    _usage.setString("Used Disk : " + std::to_string(used) + " Go");
    _total.setString("Size Disk Total : " + std::to_string(total) + "Go");

    _usage.setPosition(pos.x + window.getSize().x / 3 , pos.y + window.getSize().y / 6 );
    _free.setPosition(pos.x + 20, pos.y + window.getSize().y / 6 );
    _total.setPosition(pos.x, pos.y);
    window.draw(pieChart);

    window.draw(_free);
    window.draw(_usage);
    window.draw(_total);
}

void displayLoadAverage(GetInfoGraph action, sf::RenderWindow &window)
{
    sf::Vector2i pos = sf::Vector2i( 0 * (window.getSize().x - 150) / 3 + 150,   1 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));
        sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    std::string RAM = action.getValueString();

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Load average");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM);
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}