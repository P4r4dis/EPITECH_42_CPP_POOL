/*
** Parts.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex07/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Feb 4 1:31:38 PM 2025 Paradis
** Last update Wed Feb 4 1:50:03 PM 2025 Paradis
*/

#include "../include/Parts.hpp"

Arms::Arms(std::string serial, bool functionnal)
                                                :   _serial(serial),
                                                    _functionnal(functionnal)
{}

Arms::~Arms(void)
{}