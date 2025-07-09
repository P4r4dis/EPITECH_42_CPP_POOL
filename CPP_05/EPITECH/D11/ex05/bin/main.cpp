/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex05/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 1 7:23:37 PM 2025 Paradis
** Last update Wed Jul 8 7:10:55 PM 2025 Paradis
*/

#include <iostream>

#include "../include/IObject.hpp"
#include "../include/List.hpp"

void touch(IObject *object)
{
    if (object != nullptr)
        object->touch();
}

int main(void)
{
    try {
        List    list1;

        list1.pushBack(new TestObject("Naruto"));
        list1.pushBack(new TestObject("Sasuke"));
        list1.pushBack(new TestObject("Sakura"));
        list1.pushBack(nullptr);
        list1.pushBack(new TestObject("Serge"));

        for (List::Iterator it = list1.begin(); it != list1.end(); ++it)
            if (*it != nullptr)
                (*it)->touch();

        list1.erase(list1.erase(list1.begin()));
        list1.insert(list1.begin(), new TestObject("Orochimaru"));
        list1.insert(list1.end(), new TestObject("Tsunade"));
        list1.forEach(touch);

        List    list2;
        
        list2.pushFront(new TestObject("Jiraya"));
        list1.erase(list2.begin());
    } catch (const List::Iterator::OutOfRangeException &e) {
        std::cout << "Iterator out of range" << std::endl;
    } catch (const List::InvalidIteratorException &e) {
        std::cout << "Invalid iterator" << std::endl;
    }
    return 0;
}