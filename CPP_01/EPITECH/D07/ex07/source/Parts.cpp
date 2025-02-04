/*
** Parts.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex07/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Feb 4 1:31:38 PM 2025 Paradis
** Last update Wed Feb 4 3:19:42 PM 2025 Paradis
*/

#include "../include/Parts.hpp"
#include <iostream>
#include <string>

Arms::Arms(std::string serial, bool functionnal)
                                                :   _serial(serial),
                                                    _functionnal(functionnal)
{}

Arms::~Arms(void)
{}

bool        Arms::isFunctionnal(void) const
{
    return _functionnal;
}

std::string Arms::serial(void) const
{
    return _serial;
}

void        Arms::informations(void)
{
    std::cout   << "\t[Parts] Arms " << _serial << " status : " 
                << (_functionnal ? "OK" : "KO") << std::endl;
}

Legs::Legs(std::string serial, bool functionnal)
                                                :   _serial(serial),
                                                    _functionnal(functionnal)
{}

Legs::~Legs(void)
{}

bool        Legs::isFunctionnal(void) const
{
    return _functionnal;
}

std::string Legs::serial(void) const
{
    return _serial;
}

void        Legs::informations(void)
{
    std::cout   << "\t[Parts] Legs " << _serial << " status : " 
                << (_functionnal ? "OK" : "KO") << std::endl;
}

Head::Head(std::string serial, bool functionnal)
                                                :   _serial(serial),
                                                    _functionnal(functionnal)
{}

Head::~Head(void)
{}

bool        Head::isFunctionnal(void) const
{
    return _functionnal;
}

std::string Head::serial(void) const
{
    return _serial;
}

void        Head::informations(void)
{
    std::cout   << "\t[Parts] Head " << _serial << " status : " 
                << (_functionnal ? "OK" : "KO") << std::endl;
}