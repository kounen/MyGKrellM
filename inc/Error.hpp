/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPrush3-lucas.guichard
** File description:
** Error.hpp
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <string>

class Error
{
private:
    std::string m_message;
public:
    Error(const std::string &message = "") throw() : m_message(message)
    {}

    virtual ~Error() throw()
    {}

    virtual const char* what() const throw()
    {
        return m_message.c_str();
    }
};

#endif
