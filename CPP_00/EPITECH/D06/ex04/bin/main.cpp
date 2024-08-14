/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:33:43 PM 2024 Paradis
** Last update Wed Jul 30 9:21:27 PM 2024 Paradis
*/

#include "../include/SickKoala.hpp"
#include "../include/KoalaNurse.hpp"
#include "../include/KoalaDoctor.hpp"
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
    return 0;
}