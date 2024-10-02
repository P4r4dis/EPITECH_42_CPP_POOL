/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 7:45:48 PM 2024 Paradis
** Last update Thu Oct 2 8:58:39 PM 2024 Paradis
*/

#include "../include/Federation.hpp"
#include "../include/WarpSystem.hpp"
#include "../include/Borg.hpp"

#include <iostream>
int     main(void)
{
    Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 2);
    Federation::Starfleet::Captain James("James T. Kirk");
    Federation::Starfleet::Ensign Ensign("Pavel Chekov");
    Federation::Ship     Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::QuantumReactor QR2;
    WarpSystem::QuantumReactor QR3;

    WarpSystem::Core core(&QR);
    WarpSystem::Core core2(&QR2);
    WarpSystem::Core core3(&QR3);


    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote(&James);

    if (UssKreog.getLocation() == 0)
        std::cout << "USS Kreog: Current location is EARTH." << std::endl;

    std::cout << "USS Kreog: move to VULCAN." << std::endl;
    UssKreog.move(1, Destination::VULCAN);
    if (UssKreog.getLocation() == 1)
        std::cout << "USS Kreog: Current location is VULCAN." << std::endl;

    std::cout << "USS Kreog: move to EARTH." << std::endl;
    UssKreog.move(1);
    if (UssKreog.getLocation() == 0)
        std::cout << "USS Kreog: Current location is EARTH." << std::endl;

    std::cout << "USS Kreog: move to VULCAN." << std::endl;
    UssKreog.move(Destination::VULCAN);
    if (UssKreog.getLocation() == 1)
        std::cout << "USS Kreog: Current location is VULCAN." << std::endl;

    std::cout << "USS Kreog: move to EARTH." << std::endl;
    UssKreog.move();
    if (UssKreog.getLocation() == 0)
        std::cout << "USS Kreog: Current location is EARTH." << std::endl;

    Borg::Ship  Cube(20);
    Cube.setupCore(&core2);
    Cube.checkCore();

    if (Cube.getLocation() == 2)
        std::cout << "Borg Ship: Current location is UNICOMPLEX." << std::endl;

    std::cout << "Borg Ship: move to VULCAN." << std::endl;
    Cube.move(1, Destination::VULCAN);
    if (Cube.getLocation() == 1)
        std::cout << "Borg Ship: Current location is VULCAN." << std::endl;

    std::cout << "Borg Ship: move to UNICOMPLEX." << std::endl;
    Cube.move(1);
    if (Cube.getLocation() == 2)
        std::cout << "Borg Ship: Current location is UNICOMPLEX." << std::endl;

    std::cout << "Borg Ship: move to VULCAN." << std::endl;
    Cube.move(Destination::VULCAN);
    if (Cube.getLocation() == 1)
        std::cout << "Borg Ship: Current location is VULCAN." << std::endl;

    std::cout << "Borg Ship: move to UNICOMPLEX." << std::endl;
    Cube.move();
    if (Cube.getLocation() == 2)
        std::cout << "Borg Ship: Current location is UNICOMPLEX." << std::endl;

    Independent.setupCore(&core3);
    Independent.checkCore();
    if (Independent.getLocation() == 1)
        std::cout << "Independent Ship: Current location is VULCAN." << std::endl;

    std::cout << "Independent Ship: move to EARTH." << std::endl;
    Independent.move(1, Destination::EARTH);
    if (Independent.getLocation() == 0)
        std::cout << "Independent Ship: Current location is EARTH." << std::endl;

    std::cout << "Independent Ship: move to VULCAN." << std::endl;
    Independent.move(1);
    if (Independent.getLocation() == 1)
        std::cout << "Independent Ship: Current location is VULCAN." << std::endl;

    std::cout << "Independent Ship: move to UNICOMPLEX." << std::endl;
    Independent.move(Destination::UNICOMPLEX);
    if (Independent.getLocation() == 2)
        std::cout << "Independent Ship: Current location is UNICOMPLEX." << std::endl;

    std::cout << "Independent Ship: move to VULCAN." << std::endl;
    Independent.move();
    if (Independent.getLocation() == 1)
        std::cout << "Independent Ship: Current location is VULCAN." << std::endl;

    std::cout << "Time to War!" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() 
                << " has " << UssKreog.getTorpedo() 
                << " torpedoes" << std::endl;
    std::cout   << "Ship Borg has " << Cube.getWeaponFrequency() 
                << "GW Weapon Frequency" << std::endl;
    std::cout   << "Ship Borg can repair " << Cube.getRepair() 
                << " times" << std::endl;
    std::cout   << "Ship Borg's shield " << Cube.getShield() 
                << "%" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() << " tries to attack !"
                << std::endl;
    UssKreog.fire(&Cube);
    std::cout   << "Ship Borg's shield " << Cube.getShield() 
                << "%" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() 
                << " has " << UssKreog.getTorpedo()
                << " torpedoes" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() << " tries to attack with 2 torpedoes!"
                << std::endl;
    UssKreog.fire(2, &Cube);
    std::cout   << "Ship Borg's shield " << Cube.getShield() 
                << "%" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() 
                << " has " << UssKreog.getTorpedo()
                << " torpedoes" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() << " tries to attack !"
                << std::endl;
    UssKreog.fire(1, &Cube);
    std::cout   << "Ship Borg's shield " << Cube.getShield() 
                << "%" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() 
                << " has " << UssKreog.getTorpedo()
                << " torpedoes" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() << " tries to attack !"
                << std::endl;
    UssKreog.fire(1, &Cube);
    std::cout   << "Ship Borg's shield " << Cube.getShield() 
                << "%" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() 
                << " has " << UssKreog.getTorpedo()
                << " torpedoes" << std::endl;
    UssKreog.setTorpedo(20);
    std::cout   << "Ship USS " << UssKreog.getName() 
                << " has reloaded " << UssKreog.getTorpedo()
                << " torpedoes" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() << " tries to attack !"
                << std::endl;
    UssKreog.fire(20, &Cube);
    std::cout   << "Ship Borg's shield " << Cube.getShield() 
                << "%" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() 
                << " has " << UssKreog.getTorpedo()
                << " torpedoes" << std::endl;
    Cube.repair();
    std::cout   << "Ship Borg repair itself " << Cube.getShield() 
                << "%. Ship borg can be repaired "
                << Cube.getRepair() << " more times" << std::endl;
    std::cout   << "Ship Borg's shield " << Cube.getShield() 
                << "%" << std::endl;
    std::cout   << "Ship USS " << UssKreog.getName() 
                << "'s' shield " << UssKreog.getShield()
                << "%" << std::endl;
    UssKreog.fire(20, &Cube);
    std::cout   << "Ship Borg's tries to attack !" << std::endl;
    Cube.fire(&UssKreog);
    std::cout   << "Ship USS " << UssKreog.getName() 
                << "'s' shield " << UssKreog.getShield()
                << "%" << std::endl;

    Independent.checkCore();
    std::cout   << "Ship Borg's tries to attack !" << std::endl;
    Cube.fire(&Independent);
    Independent.checkCore();
    std::cout << "End of War!!!" << std::endl;

    return 0;
}