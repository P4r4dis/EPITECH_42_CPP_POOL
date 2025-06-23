/*
** DirectoryLister.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jun 23 7:04:12 PM 2025 Paradis
** Last update Tue Jun 23 7:04:14 PM 2025 Paradis
*/

#include "../include/DirectoryLister.hpp"
#include <string>

DirectoryLister::DirectoryLister(void)  :   _path(""),
                                            _hidden(false)
{
}

DirectoryLister::DirectoryLister(const std::string &path, bool hidden)
    :   _path(path),
        _hidden(hidden)
{
}

DirectoryLister::~DirectoryLister()
{
}

std::string             DirectoryLister::getPath(void) const
{
    return _path;
}

bool                    DirectoryLister::getHidden(void) const
{
    return _hidden;
}
