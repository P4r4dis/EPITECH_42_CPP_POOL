/*
** UniquePointer.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jun 26 4:26:51 PM 2025 Paradis
** Last update Fri Jun 26 9:20:57 PM 2025 Paradis
*/

#include "../include/UniquePointer.hpp"

UniquePointer::UniquePointer(void)  :   _uniquePtr(nullptr)
{}

UniquePointer::UniquePointer(IObject *object)
    :   _uniquePtr(object)
{}

UniquePointer   &UniquePointer::operator=(IObject *rhs)
{
    if (this != rhs)
    {
        if (_uniquePtr != rhs)
            delete _uniquePtr;
        _uniquePtr = rhs;
    }
    return *this;
}

UniquePointer::~UniquePointer(void)
{
    if (_uniquePtr)
        delete _uniquePtr;
}

void        UniquePointer::touch(void)
{
    _uniquePtr->touch();
}

IObject     &UniquePointer::operator*(void)
{
    return *_uniquePtr;
}

IObject     *UniquePointer::operator->(void)
{
    return _uniquePtr;
}

void        UniquePointer::reset(IObject *ptr)
{
    if (_uniquePtr)
        delete _uniquePtr;
    _uniquePtr = ptr;
}

void        UniquePointer::swap(UniquePointer &ptr)
{
    IObject *temp = nullptr;
    
    temp = _uniquePtr;
    _uniquePtr = ptr._uniquePtr;
    ptr._uniquePtr = temp;
    
    // std::swap(_uniquePtr, ptr._uniquePtr);
}