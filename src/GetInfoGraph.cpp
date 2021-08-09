/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** GetInfoGraph.cpp
*/

#include "../inc/GetInfoGraph.hpp"

GetInfoGraph::GetInfoGraph()
{
    CoreIdentifier = 0;
}

GetInfoGraph::~GetInfoGraph()
{
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodSize_t action)
{
    size_t size = (m_action.*action)();

    _size = size;
    return (*this);
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodInt action)
{
    int Percentage = (m_action.*action)();

    if (Percentage >= 80)
        _color = "red";
    else if (Percentage >= 50)
        _color = "Yellow";
    else
        _color = "green";

    _Percentage = Percentage;
    return (*this);
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodString action)
{
    std::string string = (m_action.*action)();

    _String = string;
    return (*this);
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodStringConst action)
{
    std::string string = (m_action.*action)();

    _String = string;
    return (*this);
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodStringConstSystem action)
{
    std::string string = (m_action_system.*action)();

    _String = string;
    return (*this);
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodIntCPU action)
{
    int size = (m_action_cpu.*action)();

    _size = size;
    return (*this);
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodFloatCPU action)
{
    float size = (m_action_cpu.*action)(CoreIdentifier);

    nb_float = size;
    return (*this);
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodSize_tCPU action)
{
    size_t size = (m_action_cpu.*action)(CoreIdentifier);

    _size = size;
    return (*this);
}

GetInfoGraph &GetInfoGraph::getInfoGraph(methodStringCPU action)
{
    std::string string = (m_action_cpu.*action)(CoreIdentifier);

    _String = string;
    return (*this);
}

size_t GetInfoGraph::getValueSize() const { return _size; }
int GetInfoGraph::getValuePercentage() const { return _Percentage; }
std::string GetInfoGraph::getValueString() const { return _String; }
float GetInfoGraph::getValueFloat() const { return nb_float; }
sf::Color GetInfoGraph::getColor() const
{
    if (_color == "red")
        return sf::Color::Red;
    else if (_color == "green")
        return sf::Color::Green;
    return sf::Color::Yellow;
}
