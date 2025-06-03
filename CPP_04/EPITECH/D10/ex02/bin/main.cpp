/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:31:10 PM 2025 Paradis
** Last update Wed Jun 3 7:01:50 PM 2025 Paradis
*/

#include <iostream>
#include "../include/FruitBox.hpp"
#include "../include/AFruit.hpp"
#include "../include/FruitUtils.hpp"
#include "../include/Orange.hpp"
#include "../include/Lemon.hpp"
#include "../include/Strawberry.hpp"
#include "../include/Almond.hpp"
#include "../include/Grapefruit.hpp"
#include "../include/BloodOrange.hpp"
#include "../include/Raspberry.hpp"
#include "../include/Coconut.hpp"

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
        FruitUtils  utils;
        FruitBox    unsortedBox(9);
        FruitBox    lemonBox(8);
        FruitBox    citrusBox(8);
        FruitBox    berryBox(8);
        Orange      *orange = new Orange;
        Lemon       *lemon = new Lemon;
        Strawberry  *berry = new Strawberry;
        Almond      *almond = new Almond;
        Grapefruit  *grapefruit = new Grapefruit;
        BloodOrange *bloodOrange = new BloodOrange;
        Raspberry   *raspberry = new Raspberry;
        Coconut     *coconut = new Coconut;
        TestFruit   *testFruit = new TestFruit("Apple");

        unsortedBox.pushFruit(orange);
        unsortedBox.pushFruit(lemon);
        unsortedBox.pushFruit(berry);
        unsortedBox.pushFruit(almond);
        unsortedBox.pushFruit(grapefruit);
        unsortedBox.pushFruit(bloodOrange);
        unsortedBox.pushFruit(raspberry);
        unsortedBox.pushFruit(coconut);
        unsortedBox.pushFruit(testFruit);

        utils.sort(unsortedBox, lemonBox, citrusBox, berryBox);

        std::cout << "unsorted: " << unsortedBox << std::endl;
        std::cout << "lemonBox: " << lemonBox << std::endl;
        std::cout << "citrusBox: " << citrusBox << std::endl;
        std::cout << "berryBox: " << berryBox << std::endl;
    
    return 0;
}