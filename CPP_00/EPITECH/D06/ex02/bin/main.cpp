/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex02/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 26 7:59:50 PM 2024 Paradis
** Last update Tue Jul 29 6:13:39 PM 2024 Paradis
*/



#include "../include/SickKoala.hpp"

int main(void)
{
    SickKoala   patient("Koala");

    patient.poke();
    patient.takeDrug("Mars");
    patient.takeDrug("Kinder");
    patient.takeDrug("anything");
    patient.overDrive("Kreog! How's it going?");
    return 0;
}