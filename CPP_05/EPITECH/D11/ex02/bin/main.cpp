/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex02/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jun 26 2:08:38 PM 2025 Paradis
** Last update Fri Jun 26 6:09:41 PM 2025 Paradis
*/


#include <iostream>

#include "../include/UniquePointer.hpp"

int main ( void )
{
    UniquePointer   ptr1;
    UniquePointer   ptr2(new TestObject("Eccleston"));
    // // UniquePointer ptr3 ( ptr2 ) ; <- Does not compile !
    // ptr1 = new TestObject("Tennant");
    // ptr2 = new TestObject("Smith");
    // ptr1->touch();
    // (*ptr2).touch();

    // {
    //     UniquePointer   ptr4(new TestObject("Whittaker"));
    // }

    // ptr1.reset(new TestObject("Capaldi"));
    // ptr1.swap(ptr2);
    // // ptr1 = ptr2 ; <- Does not compile !
    // ptr2.reset();

    return 0;
}