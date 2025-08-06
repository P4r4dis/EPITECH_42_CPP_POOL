/*
** Toy.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex04/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 7:35:01 PM 2025 Paradis
** Last update Thu Aug 6 7:59:31 PM 2025 Paradis
*/

#include "../include/Toy.hpp"
#include <iostream>

Toy::Toy(void)  :   _type(BASIC_TOY),
                    _name("toy"),
                    _fileName(""),
                    _picture()
{
}

Toy::Toy(ToyType toyType, const std::string &name, const std::string &file)
    :   _type(toyType),
        _name(name),
        _fileName(file),
        _picture(_fileName)
{
}

Toy::~Toy()
{
}

Toy::ToyType     Toy::getType(void) const
{
    return _type;
}

std::string     Toy::getName(void) const
{
    return _name;
}

void            Toy::setName(const std::string &name)
{
    _name = name;
}

std::string     Toy::getAscii(void) const
{
    return _picture.data;
}

bool            Toy::setAscii(const std::string &picture)
{
    if (_picture.getPictureFromFile(picture))
        return true;
    return false;

}

void            Toy::speak(const std::string &str)
{
    std::cout   << _name << " \"" << str << "\"" << std::endl;
}

std::ostream    &operator<<(std::ostream &os, const Toy &toy)
{
    os  << toy.getName() << std::endl << toy.getAscii()
        << std::endl;
        
    return os;
}