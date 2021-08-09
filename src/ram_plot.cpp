/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** ram_plot
*/

#include "../inc/GetInfoGraph.hpp"
#include "../inc/MonitorModuleMemory.hpp"
#include "../inc/MonitorModuleSystem.hpp"
#include "../inc/UserSettings.hpp"

void displayRAMRamPercentage(GetInfoGraph action, sf::RenderWindow &window)
{
    sf::Vector2i pos = sf::Vector2i( 0 * (window.getSize().x - 150) / 3 + 150, window.getSize().y * 0);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    sf::Text text;
    sf::Font font;
    window.draw(Contener);

    static sf::VertexArray graph(sf::LinesStrip, 0);
    static sf::VertexArray _graph(sf::LinesStrip, 0);
    static sf::VertexArray graph_(sf::LinesStrip, 0);
    static int old = action.getValuePercentage();
    static unsigned int time = Contener.getGlobalBounds().left;

    sf::Color color = old == action.getValuePercentage() ? action.getColor() : sf::Color(255, 94, 0);
    old = action.getValuePercentage();
    float height_graph = (window.getSize().y / 3) - 1;

    height_graph -= ((float)action.getValuePercentage()/100.00) * ((float)window.getSize().y / 3.0 - 4.0);

    graph.append(sf::Vertex(sf::Vector2f(time += 2, height_graph), color));
    graph_.append(sf::Vertex(sf::Vector2f(time, height_graph - 1), color));
    _graph.append(sf::Vertex(sf::Vector2f(time, height_graph + 1), color));

    if (Contener.getGlobalBounds().left + Contener.getGlobalBounds().width < time + 2) {
        graph = sf::VertexArray(sf::LinesStrip, 0);
        _graph = sf::VertexArray(sf::LinesStrip, 0);
        graph_ = sf::VertexArray(sf::LinesStrip, 0);
        time = Contener.getGlobalBounds().left;
    }

    std::string RAM("RAM Usage: ");
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);

    if (height_graph > pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3)
        text.setPosition(pos.x, pos.y);
    else
        text.setPosition(pos.x, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );

    text.setString(RAM.append(std::to_string(action.getValuePercentage())).append("%"));

    window.draw(graph);
    window.draw(graph_);
    window.draw(_graph);
    window.draw(text);
}

void displayRAMTotalRam(GetInfoGraph action, sf::RenderWindow &window)
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

    std::string RAM = std::to_string(action.getValueSize());

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("RAM Total");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM + " Mo");
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayRAMBufferRam(GetInfoGraph action, sf::RenderWindow &window)
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

    std::string RAM = std::to_string(action.getValueSize());

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("RAM Buffer");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM + " Mo");
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayRAMFreeRam(GetInfoGraph action, sf::RenderWindow &window)
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

    std::string RAM = std::to_string(action.getValueSize());

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Free RAM");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM + " Mo");
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayRAMFreeSwap(GetInfoGraph action, sf::RenderWindow &window)
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

    std::string RAM = std::to_string(action.getValueSize());

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Free RAM swap");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM + " Mo");
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayRAMSharedRam(GetInfoGraph action, sf::RenderWindow &window)
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

    std::string RAM = std::to_string(action.getValueSize());

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("RAM Shared");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM + " Mo");
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayRAMSwapPercentage(GetInfoGraph action, sf::RenderWindow &window)
{
    sf::Vector2i pos = sf::Vector2i( 0 * (window.getSize().x - 150) / 3 + 150,   2 * window.getSize().y / 3);
    sf::RectangleShape Contener(sf::Vector2f((float)(window.getSize().x - 150) / 3 - 4, (float) window.getSize().y / 3 - 4));
    sf::Text text;
    sf::Font font;
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString("displayRAMSwapPercentage");
    text.setPosition(pos.x, pos.y);
    Contener.setFillColor(sf::Color(0, 0, 0, 0));
    Contener.setOutlineThickness(2);
    Contener.setOutlineColor(sf::Color(1, 1, 1, 127));
    Contener.setPosition((float)pos.x + 2, (float) pos.y + 2);
    window.draw(Contener);

    static sf::VertexArray graph(sf::LinesStrip, 0);
    static sf::VertexArray _graph(sf::LinesStrip, 0);
    static sf::VertexArray graph_(sf::LinesStrip, 0);
    static int old = action.getValuePercentage();
    static unsigned int time = Contener.getGlobalBounds().left;

    sf::Color color = old == action.getValuePercentage() ? action.getColor() : sf::Color(255, 94, 0);
    old = action.getValuePercentage();
    float height_graph = ( 3 * window.getSize().y / 3) - 1;
    height_graph -= ((float)action.getValuePercentage()/100.00) * ((float)window.getSize().y / 3.0 - 4.0);
    graph.append(sf::Vertex(sf::Vector2f(time += 2, height_graph), color));
    graph_.append(sf::Vertex(sf::Vector2f(time, height_graph - 1), color));
    _graph.append(sf::Vertex(sf::Vector2f(time, height_graph + 1), color));
    if (Contener.getGlobalBounds().left + Contener.getGlobalBounds().width < time + 2) {
        graph = sf::VertexArray(sf::LinesStrip, 0);
        _graph = sf::VertexArray(sf::LinesStrip, 0);
        graph_ = sf::VertexArray(sf::LinesStrip, 0);
        time = Contener.getGlobalBounds().left;
    }
    std::string Swap("RAM Swap: ");
    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setString(Swap.append(std::to_string(action.getValuePercentage())).append("%"));
    if (height_graph > pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3)
        text.setPosition(pos.x, pos.y);
    else
        text.setPosition(pos.x, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_info;
    text_info.setFont(font);
    text_info.setString("(?)");
    text_info.setPosition(pos.x, pos.y - text_info.getCharacterSize() - 8 + window.getSize().y / 3 );
    window.draw(graph);
    window.draw(graph_);
    window.draw(_graph);
        window.draw(text);
}

void displayRAMUsedRam(GetInfoGraph action, sf::RenderWindow &window)
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

    std::string RAM = std::to_string(action.getValueSize());

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("RAM Used");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM + " Mo");
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}

void displayRAMTotalSwap(GetInfoGraph action, sf::RenderWindow &window)
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

    std::string RAM = std::to_string(action.getValueSize());

    font.loadFromFile("font/OpenSans-Bold.ttf");
    text.setString("Total RAM swap");
    text.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 3 );
    sf::Text text_;
    text_.setFont(font);
    text_.setString(RAM + " Mo");
    text_.setPosition(pos.x + window.getSize().y / 6, pos.y  - text.getCharacterSize() - 8 + window.getSize().y / 6);
    window.draw(text);
    window.draw(text_);
}
