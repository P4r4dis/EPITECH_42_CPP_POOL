/*
** BloodOrange.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:22:19 PM 2025 Paradis
** Last update Fri Jun 5 9:04:57 PM 2025 Paradis
*/


#include "../include/BloodOrange.hpp"

BloodOrange::BloodOrange(void)  :   Orange("blood orange", 6)
{
}

BloodOrange::BloodOrange(const std::string& name, unsigned int vitamins, bool peeled)
    :   Orange(name, vitamins, peeled)
{
}

BloodOrange               &BloodOrange::operator=(const BloodOrange& bloodOrange)
{
    if (this != &bloodOrange)
    {
        _vitamins = bloodOrange._vitamins;
        _name = bloodOrange._name;
        _peeled = bloodOrange._peeled;
    }
    return *this;
}

BloodOrange::~BloodOrange()
{
}

BloodOrange::BloodOrange(const BloodOrange &bloodOrange)    :   
                                                Orange(bloodOrange._name,
                                                bloodOrange._vitamins,
                                                bloodOrange._peeled)
{
    if (this != &bloodOrange)
    {
        _vitamins = bloodOrange._vitamins;
        _name = bloodOrange._name;
        _peeled = bloodOrange._peeled;
    }
}

BloodOrange              *BloodOrange::clone(void) const
{
    return (new BloodOrange(*this));
}