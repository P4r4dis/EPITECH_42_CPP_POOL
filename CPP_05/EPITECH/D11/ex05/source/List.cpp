/*
** List.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 1 7:24:06 PM 2025 Paradis
** Last update Sat Jul 4 8:00:29 PM 2025 Paradis
*/

#include "../include/List.hpp"

List::List(void)    :   _head(nullptr), _size(0)
{
}

List::~List()
{
    clear();
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

bool        List::empty(void) const
{
    return (_size == 0 ? true : false);

}

size_t      List::size(void) const
{
    return _size;
}

IObject     *&List::front(void)
{
    if (empty() == true)
        throw InvalidOperationException();
    return _head->element;
}

IObject     *List::front(void) const
{
    if (empty() == true)
        throw InvalidOperationException();
    return _head->element;
}

IObject     *&List::back(void)
{
    if (empty() == true)
        throw InvalidOperationException();

    Node *tmp = _head;

    while (tmp->next)
        tmp = tmp->next;
    return tmp->element;
}

IObject     *List::back(void) const
{
    if (empty() == true)
        throw InvalidOperationException();

    Node *tmp = _head;

    while (tmp->next)
        tmp = tmp->next;
    return tmp->element;
}

void        List::pushBack(IObject *element)
{
    Node    *newNode = new Node(element);

    if (_head == nullptr)
        _head = newNode;
    else
    {
        Node    *temp = _head;

        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    _size++;
}

void        List::pushFront(IObject *element)
{
    Node    *newElement = new Node(element);

    if (!_head)
        _head = newElement;
    else
    {
        Node *temp = _head;

        _head = newElement;
        _head->next = temp;
    }
    _size++;
}

void        List::popFront(void)
{
    if (_head)
    {
        Node *temp = _head;

        _head = temp->next;
        delete temp->element;
        delete temp;
        _size--;
    }
    else
        throw InvalidOperationException();
}

void        List::popBack(void)
{
    if (_head)
    {
        if (_head->next == nullptr)
        {
            delete _head->element;
            delete _head;
            _head = nullptr;
        }
        else
        {
            Node *temp = _head;
            while (temp->next->next)
                temp = temp->next;

            delete temp->next->element;
            delete temp->next;
            temp->next = nullptr;
        }
        _size--;
    }
    else
        throw InvalidOperationException();
}

void        List::clear(void)
{
    if (_head)
    {
        while(_head)
        {
            Node    *temp = _head;

            _head = _head->next;

            delete temp->element;
            delete temp;
        }
        _size = 0;
    }
}

void        List::forEach(void (*function)(IObject *))
{
    for (Node *temp = _head; temp; temp = temp->next)
        (*function)(temp->element);
}

List::Iterator      List::begin(void) const
{
    List::Iterator it(_head);

    return it;
}

List::Iterator      List::end(void) const
{
    List::Iterator it(nullptr);

    return it;
}

List::Iterator      List::erase(List::Iterator it)
{
    Node *currCheck = _head;
    Node *prev = nullptr;
    Node *curr = _head;

    while (currCheck) {
        if (currCheck == it.getCurrentNode())
            break;
        currCheck = currCheck->next;
    }
    if (currCheck == nullptr || !curr)
        throw InvalidIteratorException();

    // Suppression du premier élément
    if (it.getCurrentNode() == _head) {
        Node *toDelete = _head;
        _head = _head->next;
        delete toDelete->element;
        delete toDelete;
        --_size;
        return Iterator(_head);
    }

    // Suppression au milieu / fin

    while (curr && curr != it.getCurrentNode()) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    Iterator ret(curr->next);
    delete curr->element;
    delete curr;
    --_size;
    return ret;
}

List::Iterator      List::insert(List::Iterator it, IObject *obj)
{

   Node *currCheck = _head;
    while (currCheck) {
        if (currCheck == it.getCurrentNode())
            break;
        currCheck = currCheck->next;
    }
    if (it.getCurrentNode() != nullptr && currCheck == nullptr) {
        delete obj;
        throw InvalidIteratorException();
    }

    Node *newNode = new Node(obj);

    if (it.getCurrentNode() == nullptr) {
        if (_head == nullptr) {
            _head = newNode;
        } else {
            Node *tmp = _head;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = newNode;
        }
        ++_size;
        return Iterator(newNode);
    }

    if (it.getCurrentNode() == _head) {
        newNode->next = _head;
        _head = newNode;
        ++_size;
        return Iterator(newNode);
    }

    Node *prev = nullptr;
    Node *curr = _head;
    while (curr && curr != it.getCurrentNode()) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = newNode;
    newNode->next = curr;
    ++_size;

    return Iterator(newNode);
}
////////////////////////////////////////////////////////////////////////////////
List::Iterator::Iterator(Node *node)    :   _currentNode(node)
{}

List::Iterator::~Iterator(void)
{}

IObject             *List::Iterator::operator*(void) const
{
    if (!_currentNode)
        throw OutOfRangeException();
    return _currentNode->element;
}

List::Iterator      &List::Iterator::operator++(void)
{
    if (!_currentNode)
        throw OutOfRangeException();
    _currentNode = _currentNode->next;
    return (*this);
}

bool                List::Iterator::operator==(const Iterator &it) const
{
    return _currentNode == it._currentNode;
}

bool                List::Iterator::operator!=(const Iterator &it) const
{
    return _currentNode != it._currentNode;
}

List::Node                *List::Iterator::getCurrentNode(void) const
{
    return _currentNode;
}