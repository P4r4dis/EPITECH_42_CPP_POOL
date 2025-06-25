/*
** SafeDirectoryLister.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 25 7:45:39 PM 2025 Paradis
** Last update Thu Jun 25 9:28:23 PM 2025 Paradis
*/

#include "../include/SafeDirectoryLister.hpp"

static int compareStrings(const void* a, const void* b) {
    const std::string* sa = *(const std::string**)a;
    const std::string* sb = *(const std::string**)b;
    return sa->compare(*sb);
}

SafeDirectoryLister::SafeDirectoryLister(void)  :   _path(""),
                                                    _hidden(false),
                                                    _list(nullptr), 
                                                    _size(0),
                                                    _index(0),
                                                    _capacity(0),
                                                    _entry(nullptr)
{
}

SafeDirectoryLister::SafeDirectoryLister(const std::string &path, bool hidden)
    :   _path(path),
        _hidden(hidden),
        _list(nullptr), 
        _size(0),
        _index(0),
        _capacity(0),
        _entry(nullptr)
{
    open(_path, _hidden);
}

SafeDirectoryLister::~SafeDirectoryLister()
{
    if (_list)
    {
        for (size_t i = 0; i < _size; i++)
            delete _list[i];
        delete [] _list;
    }
}

std::string             SafeDirectoryLister::getPath(void) const
{
    return _path;
}

bool                    SafeDirectoryLister::getHidden(void) const
{
    return _hidden;
}

std::string
SafeDirectoryLister::getElemOfListByIndex(size_t idx) const
{
    if (_list == nullptr || idx >= _size)
        return "";
    return *_list[idx];
}

size_t                   SafeDirectoryLister::getSize(void) const
{
    return _size;
}

size_t                   SafeDirectoryLister::getIndex(void) const
{
    return _index;
}

size_t                   SafeDirectoryLister::getCapacity(void) const
{
    return _capacity;
}

std::string             SafeDirectoryLister::get(void)
{
    if (_index < _size)
        return *_list[_index++];
    
    throw IDirectoryLister::NoMoreFileException();
}

bool
SafeDirectoryLister::open(const std::string& path, bool hidden)
{
    clean();
    _path = path;
    _hidden = hidden;
    DIR *dirp = opendir(_path.c_str());
    
    if (!dirp)
        throw IDirectoryLister::OpenFailureException();
    while ((_entry = readdir(dirp)))
    {
        std::string name(_entry->d_name);
        if (!_hidden && name[0] == '.')
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

void                    SafeDirectoryLister::clean(void)
{
    for (size_t i = 0; i < _size; ++i)
        delete _list[i];
    delete[] _list;
    _capacity = 0;
    _list = nullptr;
    _size = 0;
    _index = 0;
}

void                    SafeDirectoryLister::resize(void)
{
    _capacity += 1;
    std::string **newList = new std::string*[_capacity];
    
    for (size_t i = 0; i < _size; ++i)
        newList[i] = _list[i];
    delete[] _list;
    _list = newList;
}