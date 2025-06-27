/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex03/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jun 27 6:16:48 PM 2025 Paradis
** Last update Sat Jun 27 6:18:10 PM 2025 Paradis
*/

#include <iostream>

#include "../include/IObject.hpp"
#include "../include/List.hpp"

void touch(IObject *object)
{
    if (object != nullptr)
        object->touch();
}

int main ( void )
{
    try {
        List    list;
        list.pushBack(new TestObject("Kermit"));
        list.pushBack(new TestObject("Miss Piggy"));
        list.pushFront(nullptr);
        list.front() = new TestObject("Fozzie");
        list.pushBack(nullptr);
        list.forEach(touch);
        list.clear();
        list.popBack();
        list.pushFront(new TestObject("Gonzo"));
    } catch (const List::InvalidOperationException &e) {
        std::cout << "Invalid operation on a list" << std::endl;
    }

    return 0;
}