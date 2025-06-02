/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:31:10 PM 2025 Paradis
** Last update Tue Jun 2 8:33:08 PM 2025 Paradis
*/

#include <iostream>
#include "../include/FruitBox.hpp"
#include "../include/AFruit.hpp"

class TestFruit : public AFruit
{
    public:
        TestFruit(const std::string& name)
            : AFruit(name, 0)
        {
            _vitamins = 0;
            _peeled = false;
            std::cout << _name << " lives." << std::endl;
        }

        virtual ~TestFruit() { std::cout << _name << " dies." << std::endl;}
    private:
};

int     main(void)
{
    FruitBox        box(3);
    const FruitBox& cref = box;

    box.pushFruit(new TestFruit("Cerise"));
    box.pushFruit(new TestFruit("Framboise"));
    box.pushFruit(new TestFruit("Anis"));
    std::cout << cref << std::endl;

    IFruit          *tmp = new TestFruit("Serge");

    std::cout << box.pushFruit(tmp) << std::endl;
    delete tmp;

    tmp = box.popFruit();
    delete tmp;
    std::cout << cref << std::endl;
    
    return 0;
}