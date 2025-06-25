/*
** DirectoryLister.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jun 23 7:04:12 PM 2025 Paradis
** Last update Wed Jun 24 9:41:01 PM 2025 Paradis
*/

#include "../include/DirectoryLister.hpp"
#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <string>

static int compareStrings(const void* a, const void* b) {
    const std::string* sa = *(const std::string**)a;
    const std::string* sb = *(const std::string**)b;
    return sa->compare(*sb);
}

DirectoryLister::DirectoryLister(void)  :   _path(""),
                                            _hidden(false),
                                            _list(nullptr), 
                                            _size(0),
                                            _index(0),
                                            _capacity(0),
                                            _entry(nullptr)
{
}

DirectoryLister::DirectoryLister(const std::string &path, bool hidden)
    :   _path(path),
        _hidden(hidden),
        _list(nullptr), 
        _size(0),
        _index(0),
        _capacity(0),
        _entry(nullptr)
{
    DIR     *dirp = opendir(_path.c_str());

    if (dirp)
    {
        _list = new std::string*[_capacity];

        while ((_entry = readdir(dirp)))
        {
            std::string name(_entry->d_name);
            if (!_hidden && name[0] == '.')
                continue;

            if (_size == _capacity)
                resize();
            _list[_size++] = new std::string(name);
        }
        closedir(dirp);
        qsort(_list, _size, sizeof(std::string*),
            compareStrings);
    }
}

DirectoryLister::~DirectoryLister()
{
    if (_list)
    {
        for (size_t i = 0; i < _size; i++)
            delete _list[i];
        delete [] _list;
    }
}

std::string             DirectoryLister::getPath(void) const
{
    return _path;
}

bool                    DirectoryLister::getHidden(void) const
{
    return _hidden;
}

std::string             DirectoryLister::get(void)
{
    if (_index < _size)
        return *_list[_index++];
    return "";
}

bool
DirectoryLister::open(const std::string& path, bool hidden)
{
    DIR *dirp = opendir(path.c_str());
    
    clean();
    if (dirp)
    {
        while ((_entry = readdir(dirp)))
        {
            std::string name(_entry->d_name);
            if (!hidden && name[0] == '.')
                continue;

            if (_size == _capacity)
                resize();
            _list[_size++] = new std::string(name);
        }
        qsort(_list, _size, sizeof(std::string*),
            compareStrings);
        closedir(dirp);
        return true;
    }
    else
    {
        perror(path.c_str());
        return false;
    }
}

void                    DirectoryLister::clean(void)
{
    for (size_t i = 0; i < _size; ++i)
        delete _list[i];
    delete[] _list;
    _capacity = 0;
    _list = nullptr;
    _size = 0;
    _index = 0;
}

void                    DirectoryLister::resize(void)
{
    _capacity += 1;
    std::string **newList = new std::string*[_capacity];
    
    for (size_t i = 0; i < _size; ++i)
        newList[i] = _list[i];
    delete[] _list;
    _list = newList;
}