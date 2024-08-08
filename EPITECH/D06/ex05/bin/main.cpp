/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:33:43 PM 2024 Paradis
** Last update Fri Aug 8 10:25:54 PM 2024 Paradis
*/

#include "../include/SickKoala.hpp"
#include "../include/KoalaNurse.hpp"
#include "../include/KoalaDoctor.hpp"

#include "../include/SickKoalaList.hpp"
#include "../include/KoalaNurseList.hpp"
#include "../include/KoalaDoctorList.hpp"
#include <iostream>

int main(void)
{
    SickKoala   patient("Koala");

    patient.poke();
    patient.takeDrug("Mars");
    patient.takeDrug("Kinder");
    patient.takeDrug("anything");
    patient.overDrive("Kreog! How's it going?");
    
    KoalaNurse  nurse(1);

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

    std::cout << "DOCTOR! HELP US!" << std::endl;
    KoalaDoctor       doctor2("Doc2");
    KoalaDoctor       doctor3("Doc3");
    KoalaDoctor       doctor4("Doc4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);

    std::cout << "append one node to the list:" << std::endl;
    doctorList.append(&doctorList2);
    doctorList.dump();
    std::cout << "Verify if the next node is doctor2(Doc2)" << std::endl;
    if (doctorList.getNext())
    {
        std::cout   << "print the next pointer name: "
                    << doctorList.getNext()->getContent()->getName() << std::endl;
        std::cout << "The name should be: Doc2" << std::endl;
    }
    std::cout << "append some nodes to the list:" << std::endl;
    doctorList.append(&doctorList3);
    doctorList.append(&doctorList4);
    doctorList.dump();
    std::cout   << "Verify if we are at the end of the list:" 
                << std::boolalpha << doctorList.isEnd() << std::endl
                << "should be return false." << std::endl;
    std::cout << "Now we are going to clean the list:" << std::endl;
    doctorList.dump();
    doctorList.remove(&doctorList);
    doctorList.dump();
    doctorList.removeFromName("Doc2");
    doctorList.dump();
    doctorList.remove(&doctorList3);
    doctorList.dump();
    doctorList.removeFromName("Doc4");
    doctorList.dump();
    if(doctorList.isEnd())
        std::cout << "Lists cleaned up." << std::endl;
    else
        std::cerr << "You fail ! Boo !" << std::endl;

    std::cout << "NURSES! HELP US!" << std::endl;
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);

    std::cout << "append one node to the list:" << std::endl;
    nurseList.append(&nurseList2);
    nurseList.dump();
    std::cout << "Verify if the next node is nurse2(2)" << std::endl;
    if (nurseList.getNext())
    {
        std::cout   << "print the next pointer name: "
                    << nurseList.getNext()->getContent()->getId() << std::endl;
        std::cout << "The name should be: Nurse2" << std::endl;
    }
    std::cout << "append some nodes to the list:" << std::endl;
    nurseList.append(&nurseList3);
    nurseList.append(&nurseList4);
    nurseList.dump();
    std::cout   << "Verify if we are at the end of the list:" 
                << std::boolalpha << nurseList.isEnd() << std::endl
                << "should be return false." << std::endl;
    std::cout << "Now we are going to clean the list:" << std::endl;
    nurseList.dump();
    nurseList.remove(&nurseList);
    nurseList.dump();
    nurseList.removeFromID(2);
    nurseList.dump();
    nurseList.remove(&nurseList3);
    nurseList.dump();
    nurseList.removeFromID(4);
    nurseList.dump();
    if(nurseList.isEnd())
        std::cout << "Lists cleaned up." << std::endl;
    else
        std::cerr << "You fail ! Boo !" << std::endl;
    return 0;
}