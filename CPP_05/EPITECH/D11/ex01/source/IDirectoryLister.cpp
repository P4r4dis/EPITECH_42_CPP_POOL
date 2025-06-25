/*
** IDirectoryLister.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 25 6:45:30 PM 2025 Paradis
** Last update Thu Jun 25 7:25:00 PM 2025 Paradis
*/

#include "../include/IDirectoryLister.hpp"
#include <cstring>


const char  *IDirectoryLister::OpenFailureException::what(void) const throw()
{
    return std::strerror(ENOENT);
}

const char  *IDirectoryLister::NoMoreFileException::what(void) const throw()
{
    return "End of stream";
}

