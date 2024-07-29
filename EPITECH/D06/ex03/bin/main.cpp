/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:33:43 PM 2024 Paradis
** Last update Tue Jul 29 6:33:46 PM 2024 Paradis
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