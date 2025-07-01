/*
** SharedPointer.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex04/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 1 4:10:13 PM 2025 Paradis
** Last update Wed Jul 1 7:02:09 PM 2025 Paradis
*/

#include "../include/SharedPointer.hpp"

SharedPointer::SharedPointer(void)  :   _sharedPtr(nullptr),
                                        _count(nullptr)
{
}

SharedPointer::SharedPointer(IObject *object)
    :   _sharedPtr(object), _count(new size_t(_sharedPtr ? 1 : 0))
{
}

SharedPointer::SharedPointer(const SharedPointer &object)
    :   _sharedPtr(object._sharedPtr), _count(object._count)
{
    if (_count)
        (*_count)++;
}

SharedPointer   &SharedPointer::operator=(const SharedPointer &object)
{
    if (this != &object)
    {
        if (_count && --(*_count) == 0)
        {
            delete _sharedPtr;
            delete _count;
        }

        _sharedPtr = object._sharedPtr;
        _count = object._count;
        if (_count)
            ++(*_count);
    }
    return *this;
}

SharedPointer   &SharedPointer::operator=(IObject *rhs)
{
    if (_sharedPtr != rhs)
    {
        if (_count && --(*_count) == 0)
        {
            delete _sharedPtr;
            delete _count;
        }
        _sharedPtr = rhs;
        _count = (_sharedPtr ? new size_t(1) : nullptr);
    }
    return *this;
}

SharedPointer::~SharedPointer(void)
{
    if (_count && --(*_count) == 0)
    {
        delete _sharedPtr;
        delete _count;
    }
}

void        SharedPointer::touch(void)
{
    _sharedPtr->touch();
}

IObject     &SharedPointer::operator*(void)
{
    return *_sharedPtr;
}

IObject     *SharedPointer::operator->(void)
{
    return _sharedPtr;
}

void        SharedPointer::reset(IObject *ptr)
{
    // if (_sharedPtr)
    //     delete _sharedPtr;
    // _sharedPtr = ptr;
    if (_count && --(*_count) == 0)
    {
        delete _sharedPtr;
        delete _count;
    }
    _sharedPtr = ptr;
    _count = (_sharedPtr ? new size_t(1) : nullptr);


}

void        SharedPointer::swap(SharedPointer &ptr)
{
    IObject *temp = nullptr;
    
    temp = _sharedPtr;
    _sharedPtr = ptr._sharedPtr;
    ptr._sharedPtr = temp;

    size_t *tmp = nullptr;
    tmp = _count;
    _count = ptr._count;
    ptr._count = tmp;
    // std::swap(_sharedPtr, ptr._sharedPtr);
    // std::swap(_count, ptr._count);
}

size_t      SharedPointer::use_count(void)
{
    return _count ? *_count : 0;
}