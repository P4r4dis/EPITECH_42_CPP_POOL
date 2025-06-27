/*
** List.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex03/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jun 27 6:50:29 PM 2025 Paradis
** Last update Sat Jun 27 8:50:57 PM 2025 Paradis
*/

#include "../include/List.hpp"

List::List(void)    :   _head(nullptr), _size(0)
{
}

List::~List()
{
    Node    *temp;

    while (_head)
    {
        temp = _head;
        if (temp->element)
            delete temp->element;
        
        _head = _head->next;
        delete temp;
    }

}

void        List::display(void)
{
    Node    *temp = _head;
    
    std::cout << "List:" << std::endl;
    if (temp == nullptr)
        std::cout << "NULLPTR" << std::endl;
    while (temp != nullptr)
    {
        if (temp->element)
            temp->element->touch();
        else
            std::cout << "NULLPTR" << std::endl;
        temp = temp->next;
    }
    std::cout << "End List" << std::endl;
}

void        List::pushBack(IObject *element)
{
    Node    *newNode = new Node(element);

    if (_head == nullptr)
    {
        _head = newNode;
        _size++;
    }
    else
    {
        Node    *temp = _head;

        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        _size++;
    }
}













// void        List::pushBack(IObject *element)
// {
//     Node    *newNode = new Node(element);

//     if (!_head)
//     {
//         _head = newNode;
//         _size++;
//     }
//     else
//     {
//         Node    *temp = _head;

//         while (temp->next)
//             temp = temp->next;
//         temp->next = newNode;
//         _size++;
//     }
// }