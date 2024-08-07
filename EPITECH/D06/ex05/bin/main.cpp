/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:33:43 PM 2024 Paradis
** Last update Thu Aug 7 9:12:18 PM 2024 Paradis
*/

#include "../include/SickKoala.hpp"
#include "../include/KoalaNurse.hpp"
#include "../include/KoalaDoctor.hpp"

#include "../include/SickKoalaList.hpp"
#include <iostream>

int main(void)
{
    SickKoala   patient("Koala");

    patient.poke();
    patient.takeDrug("Mars");
    patient.takeDrug("Kinder");
    patient.takeDrug("anything");
    patient.overDrive("Kreog! How's it going?");
    
    KoalaNurse  nurse(0);

    nurse.timeCheck();
    nurse.giveDrug(nurse.readReport(patient.getName() + ".report"), &patient);
    nurse.timeCheck();
    
    KoalaDoctor doctor("Doc");

    doctor.timeCheck();
    nurse.timeCheck();
    doctor.diagnose(&patient);
    nurse.giveDrug(nurse.readReport(patient.getName() + ".report"), &patient);
    doctor.timeCheck();
    nurse.timeCheck();


    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);

    std::cout << "append one node to the list:" << std::endl;
    sick.append(&sick2);
    sick.dump();
    std::cout << "Verify if the next node is sick2(patient2)" << std::endl;
    if (sick.getNext())
    {
        std::cout   << "print the next pointer name: "
                    << sick.getNext()->getContent()->getName() << std::endl;
        std::cout << "The name should be: patient2" << std::endl;
    }
    std::cout << "append some nodes to the list:" << std::endl;
    sick.append(&sick3);
    sick.append(&sick4);
    sick.dump();
    std::cout   << "Verify if we are at the end of the list:" 
                << std::boolalpha << sick.isEnd() << std::endl
                << "should be return false." << std::endl;
    std::cout << "Now we are going to clean the list:" << std::endl;
    sick.dump();
    sick.remove(&sick);
    sick.dump();
    sick.removeFromName("patient2");
    sick.dump();
    sick.remove(&sick3);
    sick.dump();
    sick.removeFromName("patient4");
    sick.dump();
    if(sick.isEnd())
        std::cout << "Lists cleaned up." << std::endl;
    else
        std::cerr << "You fail ! Boo !" << std::endl;
    return 0;
}