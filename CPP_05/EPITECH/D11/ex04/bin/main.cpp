/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex04/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 1 4:00:46 PM 2025 Paradis
** Last update Wed Jul 1 7:09:37 PM 2025 Paradis
*/

#include <iostream>

#include "../include/SharedPointer.hpp"

int main(void)
{
    SharedPointer ptr1;
    SharedPointer ptr2(new TestObject( "O'Neill"));
    SharedPointer ptr3(ptr2);
    
    ptr1 = ptr3;
    ptr2->touch();
    std::cout << ptr1 . use_count () << std::endl;
    ptr1.reset(new TestObject("Carter"));
    std::cout << ptr1.use_count() << std::endl;
    ptr3.swap(ptr1);
    (*ptr3).touch();
    ptr1.reset();
    std::cout << ptr1.use_count() << std::endl;
    ptr2 = new TestObject("Jackson");

    return 0;
}