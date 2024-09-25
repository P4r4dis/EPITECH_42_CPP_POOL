/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 7:45:48 PM 2024 Paradis
** Last update Thu Sep 25 7:33:52 PM 2024 Paradis
*/

#include "../include/Federation.hpp"
#include "../include/WarpSystem.hpp"
#include "../include/Borg.hpp"


int     main(void)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
    Federation::Starfleet::Captain James("James T. Kirk");
    Federation::Starfleet::Ensign Ensign("Pavel Chekov");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::Core core(&QR);
    WarpSystem::Core core2 (&QR2);

    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote(&James);

    Borg::Ship  Cube;
    Cube.setupCore(&core2);
    Cube.checkCore();
    return 0;
}