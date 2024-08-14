/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 5:26:34 PM 2024 Paradis
** Last update Wed Aug 13 5:50:18 PM 2024 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>
#include <iostream>

#include "../../include/SickKoala.hpp"
#include "../../include/KoalaNurse.hpp"
#include "../../include/KoalaDoctor.hpp"

#include "../../include/SickKoalaList.hpp"
#include "../../include/KoalaNurseList.hpp"
#include "../../include/KoalaDoctorList.hpp"

#include "../../include/Hospital.hpp"
void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(SickKoala, Test_SickKoala_CTOR_isDefined, .init = redirect_all_stdout)
{
    std::string name = "koala";
    SickKoala   patient(name);

    cr_assert_not_null(&patient);
}

Test(SickKoala, Test_SickKoala_DTOR_output, .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        SickKoala   patient(name);
    }
    cr_assert_stdout_eq_str(
        "Mr.koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoala, Test_SickKoala_getName, .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        SickKoala   patient(name);

        cr_assert(patient.getName() == "koala");
    }
}


Test(SickKoala, Test_SickKoala_poke_standard_output, .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        SickKoala   patient(name);

        patient.poke();
    }
    cr_assert_stdout_eq_str
    (
        "Mr.koala: Gooeeeeerrk!!\n"
        "Mr.koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoala, Test_SickKoala_not_matchs_with_string_and_return_false
            , .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        SickKoala   patient(name);

        cr_assert(patient.takeDrug(name) == false);
    }
}

Test(SickKoala, Test_SickKoala_not_matchs_with_string_and_return_false_with_stdout
            , .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        SickKoala   patient(name);

        cr_assert(patient.takeDrug(name) == false);
    }
    cr_assert_stdout_eq_str
    (
        "Mr.koala: Goerkreog!\n"
        "Mr.koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoala, Test_SickKoala_matchs_with_Mars_string_and_return_true
            , .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        std::string drug = "Mars";
        SickKoala   patient(name);

        cr_assert(patient.takeDrug(drug) == true);
    }
}

Test(SickKoala, Test_SickKoala_matchs_with_Mars_string_and_return_true_with_stdout
            , .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        std::string drug = "Mars";
        SickKoala   patient(name);

        cr_assert(patient.takeDrug(drug) == true);
    }
    cr_assert_stdout_eq_str
    (
        "Mr.koala: Mars, and it kreogs!\n"
        "Mr.koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoala, Test_SickKoala_matchs_with_Kinder_string_and_return_true
            , .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        std::string drug = "Kinder";
        SickKoala   patient(name);

        cr_assert(patient.takeDrug(drug) == true);
    }
}

Test(SickKoala, Test_SickKoala_matchs_with_Kinder_string_and_return_true_with_stdout
            , .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        std::string drug = "Kinder";
        SickKoala   patient(name);

        cr_assert(patient.takeDrug(drug) == true);
    }
    cr_assert_stdout_eq_str
    (
        "Mr.koala: There is a toy inside!\n"
        "Mr.koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoala, Test_SickKoala_overDrive, .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        std::string str = "Kreog! Im a peace!";
        SickKoala   patient(name);

        patient.overDrive(str);
    }
}

Test(SickKoala, Test_SickKoala_overDrive_replace_one_occurence_Kreog_by_1337
, .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        std::string str = "Kreog! Im a peace!";
        SickKoala   patient(name);

        patient.overDrive(str);
    }
    cr_assert_stdout_eq_str
    (
        "Mr.koala: 1337! Im a peace!\n"
        "Mr.koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoala, Test_SickKoala_overDrive_replace_several_occurence_Kreog_by_1337
, .init = redirect_all_stdout)
{
    {
        std::string name = "koala";
        std::string str = "Kreog! Im a peace, Kreog!";
        SickKoala   patient(name);

        patient.overDrive(str);
    }
    cr_assert_stdout_eq_str
    (
        "Mr.koala: 1337! Im a peace, 1337!\n"
        "Mr.koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(KoalaNurse, Test_KoalaNurse_CTOR, .init = redirect_all_stdout)
{
    int          id = 0;
    KoalaNurse   nurse(id);
    
    cr_assert_not_null(&nurse);
}

Test(KoalaNurse, Test_KoalaNurse_DTOR_output, .init = redirect_all_stdout)
{
    {
        int          id = 0;
        KoalaNurse   nurse(id);
    }
    cr_assert_stdout_eq_str
    (
        "Nurse 0: Finally some rest!\n"
    );
}

Test(KoalaNurse, Test_KoalaNurse_getId, .init = redirect_all_stdout)
{
    {
        int          id = 0;
        KoalaNurse   nurse(id);

        cr_assert(nurse.getId() == 0);
    }
}

Test(KoalaNurse, Test_KoalaNurse_giveDrug_isDefined, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "Koala";
        SickKoala       patient(name);
        KoalaNurse      nurse(id);

        nurse.giveDrug("Mars", &patient);
    }
}

Test(KoalaNurse, Test_KoalaNurse_giveDrug_Mars_stdout, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "Koala";
        std::string     drug = "Mars";
        SickKoala       patient(name);
        KoalaNurse      nurse(id);

        nurse.giveDrug(drug, &patient);
    }
    cr_assert_stdout_eq_str
    (
        "Mr.Koala: Mars, and it kreogs!\n"
        "Nurse 0: Finally some rest!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(KoalaNurse, Test_KoalaNurse_giveDrug_Kinder_stdout, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "Koala";
        std::string     drug = "Kinder";
        SickKoala       patient(name);
        KoalaNurse      nurse(id);

        nurse.giveDrug(drug, &patient);
    }
    cr_assert_stdout_eq_str
    (
        "Mr.Koala: There is a toy inside!\n"
        "Nurse 0: Finally some rest!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(KoalaNurse, Test_KoalaNurse_giveDrug_anything_stdout, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "Koala";
        std::string     drug = "anything";
        SickKoala       patient(name);
        KoalaNurse      nurse(id);

        nurse.giveDrug(drug, &patient);
    }
    cr_assert_stdout_eq_str
    (
        "Mr.Koala: Goerkreog!\n"
        "Nurse 0: Finally some rest!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(KoalaNurse, Test_KoalaNurse_timeCheck_isDefined, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        KoalaNurse      nurse(id);

        nurse.timeCheck();
    }
}

Test(KoalaNurse, Test_KoalaNurse_getTimeToWork_return_false
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        KoalaNurse      nurse(id);

        cr_assert(nurse.getTimeToWork() == false);
    }
}

Test(KoalaNurse, Test_KoalaNurse_timeCheck_with_timeToWork_return_true
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        KoalaNurse      nurse(id);

        cr_assert(nurse.getTimeToWork() == false);
        nurse.timeCheck();
        cr_assert(nurse.getTimeToWork() == true);
    }
}

Test(KoalaNurse, Test_KoalaNurse_timeCheck_working_stdout
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        KoalaNurse      nurse(id);

        cr_assert(nurse.getTimeToWork() == false);
        nurse.timeCheck();
        cr_assert(nurse.getTimeToWork() == true);
    }
    cr_assert_stdout_eq_str
    (
        "Nurse 0: Time to get to work!\n"
        "Nurse 0: Finally some rest!\n"
    );
}

Test(KoalaNurse, Test_KoalaNurse_timeCheck_not_working_stdout
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        KoalaNurse      nurse(id);

        cr_assert(nurse.getTimeToWork() == false);
        nurse.timeCheck();
        cr_assert(nurse.getTimeToWork() == true);
        nurse.timeCheck();
        cr_assert(nurse.getTimeToWork() == false);
    }
    cr_assert_stdout_eq_str
    (
        "Nurse 0: Time to get to work!\n"
        "Nurse 0: Time to go home to my eucalyptus forest!\n"
        "Nurse 0: Finally some rest!\n"
    );
}

Test(KoalaNurse, Test_KoalaNurse_readReport_isDefined
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "Koala";
        SickKoala       patient(name);
        std::string     fileName = patient.getName();
        KoalaNurse      nurse(id);

        nurse.readReport(fileName);
    }
}

Test(KoalaNurse, Test_KoalaNurse_readReport_construct_fileName
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "koala";
        SickKoala       patient(name);
        std::string     fileName = patient.getName();
        KoalaNurse      nurse(id);

        cr_assert(nurse.readReport(fileName) == "");
    }
}

Test(KoalaNurse, Test_KoalaNurse_readReport_not_open_file
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "koala";
        SickKoala       patient(name);
        std::string     fileName = patient.getName();
        KoalaNurse      nurse(id);

        cr_assert(nurse.readReport(fileName) == "");
    }
}

Test(KoalaNurse, Test_KoalaNurse_readReport_openFile_and_readFile
                , .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "Koalax";
        SickKoala       patient(name);
        std::string     fileName = patient.getName();
        KoalaNurse      nurse(id);

        cr_assert(nurse.readReport("Koalax.report") == "Maroilles");
    }
}

Test(KoalaNurse, Test_KoalaNurse_readReport_output
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "Koalax";
        SickKoala       patient(name);
        std::string     fileName = patient.getName() + ".report";
        KoalaNurse      nurse(id);
        
        cr_assert(nurse.readReport(fileName) == "Maroilles");
    }
    cr_assert_stdout_eq_str
    (
        "Nurse 0: Kreog! Mr.Koalax needs a Maroilles!\n"
        "Nurse 0: Finally some rest!\n"
        "Mr.Koalax: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(KoalaDoctor, Test_KoalaDoctor_CTOR, .init = redirect_all_stdout)
{
    KoalaDoctor  doctor("Doc");
    
    cr_assert_not_null(&doctor);
}

Test(KoalaDoctor, Test_KoalaDoctor_CTOR_output, .init = redirect_all_stdout)
{
    KoalaDoctor  doctor("Doc");
    
    cr_assert_stdout_eq_str
    (
        "Dr.Doc: I'm Dr.Doc! How do you kreog?\n"
    );
}

Test(KoalaDoctor, Test_KoalaDoctor_getName, .init = redirect_all_stdout)
{
    KoalaDoctor  doctor("Doc");
    
    cr_assert(doctor.getName() == "Doc");
}

Test(KoalaDoctor, Test_KoalaDoctor_getTimeCheck, .init = redirect_all_stdout)
{
    KoalaDoctor  doctor("Doc");
    
    cr_assert(doctor.getTimeCheck() == false);
}

Test(KoalaDoctor, Test_KoalaDoctor_timeCheck_call_getTimeCheck_return_true,
                                                .init = redirect_all_stdout)
{
    KoalaDoctor  doctor("Doc");
    
    cr_assert(doctor.getTimeCheck() == false);
    doctor.timeCheck();
    cr_assert(doctor.getTimeCheck() == true);
}

Test(KoalaDoctor,
Test_KoalaDoctor_timeCheck_call_getTimeCheck_return_true_with_stdout,
                                        .init = redirect_all_stdout)
{
    KoalaDoctor  doctor("Doc");
    
    cr_assert(doctor.getTimeCheck() == false);
    doctor.timeCheck();
    cr_assert(doctor.getTimeCheck() == true);
    cr_assert_stdout_eq_str
    (
        "Dr.Doc: I'm Dr.Doc! How do you kreog?\n"
        "Dr.Doc: Time to get to work!\n"
    );
}

Test(KoalaDoctor,
Test_KoalaDoctor_timeCheck_call_getTimeCheck_return_false_with_stdout,
                                        .init = redirect_all_stdout)
{
    KoalaDoctor  doctor("Doc");
    
    cr_assert(doctor.getTimeCheck() == false);
    doctor.timeCheck();
    cr_assert(doctor.getTimeCheck() == true);
    doctor.timeCheck();
    cr_assert(doctor.getTimeCheck() == false);
    cr_assert_stdout_eq_str
    (
        "Dr.Doc: I'm Dr.Doc! How do you kreog?\n"
        "Dr.Doc: Time to get to work!\n"\
        "Dr.Doc: Time to go home to my eucalyptus forest!\n"
    );
}

Test(KoalaDoctor, Test_KoalaDoctor_diagnose_isDefined,
                            .init = redirect_all_stdout)
{
    KoalaDoctor     doctor("Doc");
    SickKoala       patient("Koalax");

    doctor.diagnose(&patient);
}

Test(KoalaDoctor, Test_KoalaDoctor_diagnose_call_SickKoala_poke_stdout,
                                            .init = redirect_all_stdout)
{
    {
        KoalaDoctor     doctor("Doc");
        SickKoala       patient("Koalax");

        doctor.diagnose(&patient);
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doc: I'm Dr.Doc! How do you kreog?\n"
        "Dr.Doc: So what's goerking you Mr.Koalax?\n"
        "Mr.Koalax: Gooeeeeerrk!!\n"
        "Mr.Koalax: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(KoalaDoctor, Test_KoalaDoctor_diagnose_create_fileReport,
                                    .init = redirect_all_stdout)
{
    {
        KoalaDoctor     doctor("Doc");
        SickKoala       patient("Koalax");

        doctor.diagnose(&patient);
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doc: I'm Dr.Doc! How do you kreog?\n"
        "Dr.Doc: So what's goerking you Mr.Koalax?\n"
        "Mr.Koalax: Gooeeeeerrk!!\n"
        "Mr.Koalax: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(KoalaDoctor, Test_KoalaDoctor_diagnose_open_fileReport,
                                    .init = redirect_all_stdout)
{
    {
        KoalaDoctor     doctor("Doc");
        SickKoala       patient("Koalax");

        doctor.diagnose(&patient);
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doc: I'm Dr.Doc! How do you kreog?\n"
        "Dr.Doc: So what's goerking you Mr.Koalax?\n"
        "Mr.Koalax: Gooeeeeerrk!!\n"
        "Mr.Koalax: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(KoalaDoctor, Test_KoalaDoctor_diagnose_write_report,
.init = redirect_all_stdout)
{
    {
        KoalaDoctor     doctor("Doc");
        SickKoala       patient("Koalax");
        KoalaNurse      nurse(0);

        doctor.diagnose(&patient);
        cr_assert(nurse.readReport(patient.getName() + ".report") == "Maroilles");
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doc: I'm Dr.Doc! How do you kreog?\n"
        "Dr.Doc: So what's goerking you Mr.Koalax?\n"
        "Mr.Koalax: Gooeeeeerrk!!\n"
        "Nurse 0: Kreog! Mr.Koalax needs a Maroilles!\n"
        "Nurse 0: Finally some rest!\n"
        "Mr.Koalax: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoalaList, Test_SickKoalaList_CTOR_isDefined, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);
    
    cr_assert_not_null(&sick);
}

Test(SickKoalaList, Test_SickKoalaList_getContent_isDefined, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    cr_assert_not_null(sick.getContent());
}

Test(SickKoalaList, Test_SickKoalaList_getContent_acces_to_pointer, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    cr_assert(sick.getContent()->getName() == "Koala");
}

Test(SickKoalaList, Test_SickKoalaList_getNext_return_nullptr, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    cr_assert_null(sick.getNext());
}

Test(SickKoalaList, Test_SickKoalaList_getNext_return_ptr_on_next, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    cr_assert_null(sick.getNext());
}

Test(SickKoalaList, Test_SickKoalaList_isEnd_return_true, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    cr_assert(sick.isEnd() == true);
}

Test(SickKoalaList, Test_SickKoalaList_isEnd_return_false, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);

    sick.append(&sick2);
    cr_assert(sick.isEnd() == false);
}

Test(SickKoalaList, Test_SickKoalaList_isEnd_after_clean_list_return_true, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);

    sick.append(&sick2);
    sick.append(&sick3);
    sick.dump();

    sick.remove(&sick);
    sick.dump();
    sick.removeFromName("patient2");
    sick.dump();
    sick.remove(&sick3);
    sick.dump();


    cr_assert_null(sick.getNext());
    cr_assert(sick.isEnd() == true);
}

Test(SickKoalaList, Test_SickKoalaList_append_isDefined, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);

    sick.append(&sick2);
}

Test(SickKoalaList, Test_SickKoalaList_append_nodeList_is_nullptr
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoalaList   sick(&patient);
    SickKoalaList   *sick2 = nullptr;

    cr_assert_null(sick2);
    sick.append(sick2);
}

Test(SickKoalaList, Test_SickKoalaList_append_nodeList_is_nullptr_stderr
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoalaList   sick(&patient);
    SickKoalaList   *sick2 = nullptr;

    cr_assert_null(sick2);
    sick.append(sick2);
    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a null node.\n"
    );
}

Test(SickKoalaList, Test_SickKoalaList_append_sickKoala_is_nullptr
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       *patient2 = nullptr;
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(patient2);

    cr_assert_null(patient2);
    sick2.append(&sick);
}

Test(SickKoalaList, Test_SickKoalaList_append_one_node
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);

    sick2.append(&sick);
    cr_assert(sick2.getContent()->getName() == "patient2");
    cr_assert(sick2.getNext()->getContent()->getName() == "Koala");
}

Test(SickKoalaList, Test_SickKoalaList_append_should_avoid_same_node
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    sick2.append(&sick);
    sick2.append(&sick3);
    sick2.append(&sick4);
    sick2.append(&sick4);
    sick2.append(&sick3);

    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a duplicate node.\n"
        "Error: Trying to append a duplicate node.\n"
    );
}

Test(SickKoalaList, Test_SickKoalaList_append_several_nodes
, .init = redirect_all_stdout)
{
    { 
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick(&patient);
        SickKoalaList   sick2(&patient2);
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        sick2.append(&sick);
        sick2.append(&sick3);
        sick2.append(&sick4);

        SickKoalaList *current = &sick2;

        while (current != nullptr)
        {
            if (current->getContent())
                cr_assert(current->getContent()->getName() != "");

            current = current->getNext();
        }
    }
}

Test(SickKoalaList, Test_SickKoalaList_getFromName_isDefinied
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    sick2.append(&sick);
    sick2.append(&sick3);
    sick2.append(&sick4);
    sick2.append(&sick4);
    sick2.append(&sick3);

    sick2.getFromName("Koala");
}

Test(SickKoalaList, Test_SickKoalaList_getFromName_not_matches_should_nullptr
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    sick2.append(&sick);
    sick2.append(&sick3);
    sick2.append(&sick4);
    sick2.append(&sick4);
    sick2.append(&sick3);

    cr_assert(sick2.getFromName("glitch") == nullptr);
}

Test(SickKoalaList, Test_SickKoalaList_getFromName_matches_should_ptr_to_sickKoala
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    sick2.append(&sick);
    sick2.append(&sick3);
    sick2.append(&sick4);
    sick2.append(&sick4);
    sick2.append(&sick3);

    cr_assert(sick2.getFromName("Koala")->getName() == "Koala");
    cr_assert(sick2.getFromName("patient2")->getName() == "patient2");
    cr_assert(sick2.getFromName("patient3")->getName() == "patient3");
    cr_assert(sick2.getFromName("patient4")->getName() == "patient4");
}

Test(SickKoalaList, Test_SickKoalaList_remove_isDefined
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    sick2.append(&sick);
    sick2.append(&sick3);
    sick2.append(&sick4);
    sick2.append(&sick4);
    sick2.append(&sick3);

    sick2.remove(&sick3);
}

Test(SickKoalaList, Test_SickKoalaList_remove_unknow
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    SickKoala       patient3("patient3");
    SickKoalaList   sick3(&patient3);
    sick.remove(&sick3);
    cr_assert(sick.remove(&sick3) == &sick);
}

Test(SickKoalaList, Test_SickKoalaList_remove_nodeList_is_nullptr
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoalaList   sick(&patient);
    SickKoalaList   *sick2 = nullptr;
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    sick.append(sick2);
    sick.append(&sick3);
    sick.append(&sick4);
    cr_assert_null(sick2);
    cr_assert(sick.remove(sick2)->getContent()->getName() == "Koala");
}

Test(SickKoalaList, Test_SickKoalaList_remove_nodeList_is_nullptr_with_output
, .init = redirect_all_stdout)
{
    {
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoalaList   sick(&patient);
        SickKoalaList   *sick2 = nullptr;
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        sick.append(sick2);
        sick.append(&sick3);
        sick.append(&sick4);
        cr_assert_null(sick2);
        cr_assert(sick.remove(sick2)->getContent()->getName() == "Koala");
    }
    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a null node.\n"
        "Error: Trying to delete a null node.\n"
    );
    cr_assert_stdout_eq_str
    (
        "Mr.patient4: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient3: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient2: Kreooogg!! I'm cuuuured!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoalaList, Test_SickKoalaList_remove_from_list_with_only_one_node
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);

    SickKoalaList   sick(&patient);

    cr_assert_null(sick.remove(&sick)->getContent());
}

Test(SickKoalaList, Test_SickKoalaList_remove_first_nodeList
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    sick.append(&sick2);
    sick.append(&sick3);
    sick.append(&sick4);

    cr_assert_null(sick.remove(&sick)->getContent());
}

Test(SickKoalaList, Test_SickKoalaList_remove_a_nodeList
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoala       patient5("patient5");

    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    SickKoalaList   sick5(&patient5);
    sick.append(&sick2);
    sick.append(&sick3);
    sick.append(&sick4);

    sick.remove(&sick3);
    SickKoalaList *current = &sick;

    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());
        current = current->getNext();
    }
}

Test(SickKoalaList, Test_SickKoalaList_remove_several_nodeList,
.init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoala       patient5("patient5");

    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    SickKoalaList   sick5(&patient5);
    sick.append(&sick2);
    sick.append(&sick3);
    sick.append(&sick4);

    sick.remove(&sick);
    sick.remove(&sick2);
    sick.remove(&sick3);
    sick.remove(&sick4);
    
    SickKoalaList *current = &sick;

    while (current != nullptr)
    {
        if (!current->getContent())
            cr_assert_null(current->getContent());
        current = current->getNext();
    }
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_isDefined
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);

    sick.append(&sick2);
    sick.append(&sick3);
    sick.append(&sick4);

    sick.removeFromName("Koala");
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_from_empty_list
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   test(nullptr);

    test.removeFromName("Koala");
    cr_assert_null(test.getContent());
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_the_first_node
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    sick.removeFromName("Koala");
    cr_assert_null(sick.getContent());
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_the_first_node_several_times
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    sick.removeFromName("Koala");
    sick.removeFromName("Koala");
    cr_assert_null(sick.getContent());
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_a_node
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    
    sick.append(&sick2);
    sick.append(&sick3);
    sick.append(&sick4);

    sick.removeFromName("patient3");

    SickKoalaList *current = &sick;

    std::cout << "Patients: " << std::flush;
    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());

        if (current->getNext())
            std::cout << ", " << std::flush;
        else
            std::cout << ".\n"  << std::flush;
        current = current->getNext();
    }
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_a_same_node_several_times , .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoala       patient3("patient3");
    SickKoala       patient4("patient4");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);
    SickKoalaList   sick3(&patient3);
    SickKoalaList   sick4(&patient4);
    
    sick.append(&sick2);
    sick.append(&sick3);
    sick.append(&sick4);

    sick.removeFromName("patient3");
    sick.removeFromName("patient3");
    sick.removeFromName("patient4");
    sick.removeFromName("patient3");

    SickKoalaList *current = &sick;

    std::cout << "Patients: " << std::flush;
    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());

        if (current->getNext())
            std::cout << ", " << std::flush;
        else
            std::cout << ".\n"  << std::flush;
        current = current->getNext();
    }
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_first_node_stdout
, .init = redirect_all_stdout)
{
    {
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick(&patient);
        SickKoalaList   sick2(&patient2);
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        
        sick.append(&sick2);
        sick.append(&sick3);
        sick.append(&sick4);

        sick.removeFromName("Koala");
        sick.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Patients: patient2, patient3, patient4.\n"
        "Mr.patient4: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient3: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient2: Kreooogg!! I'm cuuuured!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_a_node_stdout
, .init = redirect_all_stdout)
{
    {
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick(&patient);
        SickKoalaList   sick2(&patient2);
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        
        sick.append(&sick2);
        sick.append(&sick3);
        sick.append(&sick4);

        sick.removeFromName("patient3");

        SickKoalaList *current = &sick;

        std::cout << "Patients: " << std::flush;
        while (current != nullptr)
        {
            if (current->getContent())
                std::cout << current->getContent()->getName() << std::flush;

            if (current->getNext())
                std::cout << ", " << std::flush;
            else
                std::cout << ".\n"  << std::flush;
            current = current->getNext();
        }
    }
    cr_assert_stdout_eq_str
    (
        "Patients: Koala, patient2, patient4.\n"
        "Mr.patient4: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient3: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient2: Kreooogg!! I'm cuuuured!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoalaList, Test_SickKoalaList_removeFromName_several_node_stdout
 , .init = redirect_all_stdout)
{
    {
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick(&patient);
        SickKoalaList   sick2(&patient2);
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        
        sick.append(&sick2);
        sick.append(&sick3);
        sick.append(&sick4);

        sick.removeFromName("Koala");
        sick.removeFromName("patient2");
        sick.removeFromName("patient3");
        sick.removeFromName("patient4");

        SickKoalaList *current = &sick;

        std::cout << "Patients: " << std::flush;
        while (current != nullptr)
        {
            if (!current->getContent())
                std::cout << "[nullptr]" << std::flush;
            std::cout << ".\n"  << std::flush;
            current = current->getNext();
        }
    }
    cr_assert_stdout_eq_str
    (
        "Patients: [nullptr].\n"
        "Mr.patient4: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient3: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient2: Kreooogg!! I'm cuuuured!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoalaList, Test_SickKoalaList_dump_isDefined, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);
    sick.dump();
    cr_assert_not_null(&sick);
}

Test(SickKoalaList, Test_SickKoalaList_dump_display_list_stdout, .init = redirect_all_stdout)
{
    {
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick(&patient);
        SickKoalaList   sick2(&patient2);
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        
        sick.append(&sick2);
        sick.append(&sick3);
        sick.append(&sick4);
        
        sick.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Patients: Koala, patient2, patient3, patient4.\n"
        "Mr.patient4: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient3: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient2: Kreooogg!! I'm cuuuured!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoalaList, Test_SickKoalaList_dump_display_list_with_first_node_removed_stdout,
 .init = redirect_all_stdout)
{
    {
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick(&patient);
        SickKoalaList   sick2(&patient2);
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        
        sick.append(&sick2);
        sick.append(&sick3);
        sick.append(&sick4);
        
        sick.remove(&sick);
        sick.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Patients: [NULL], patient2, patient3, patient4.\n"
        "Mr.patient4: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient3: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient2: Kreooogg!! I'm cuuuured!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoalaList, 
Test_SickKoalaList_dump_display_list_with_first_node_removedFromName_stdout,
  .init = redirect_all_stdout)
{
    {
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick(&patient);
        SickKoalaList   sick2(&patient2);
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        
        sick.append(&sick2);
        sick.append(&sick3);
        sick.append(&sick4);
        
        sick.removeFromName(name);
        sick.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Patients: patient2, patient3, patient4.\n"
        "Mr.patient4: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient3: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient2: Kreooogg!! I'm cuuuured!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}

Test(SickKoalaList,
Test_SickKoalaList_dump_display_list_with_first_node_removed_with_another_node_stdout,
.init = redirect_all_stdout)
{
    {
        std::string     name = "Koala";
        SickKoala       patient(name);
        SickKoala       patient2("patient2");
        SickKoala       patient3("patient3");
        SickKoala       patient4("patient4");
        SickKoalaList   sick(&patient);
        SickKoalaList   sick2(&patient2);
        SickKoalaList   sick3(&patient3);
        SickKoalaList   sick4(&patient4);
        
        sick.append(&sick2);
        sick.append(&sick3);
        sick.append(&sick4);
        
        sick.remove(&sick3);
        sick.removeFromName(name);
        sick.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Patients: patient2, patient4.\n"
        "Mr.patient4: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient3: Kreooogg!! I'm cuuuured!\n"
        "Mr.patient2: Kreooogg!! I'm cuuuured!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
    );
}


Test(KoalaDoctorList, Test_KoalaDoctorList_CTOR_isDefined, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);
    
    cr_assert_not_null(&doctorList);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_getContent_isDefined, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);

    cr_assert_not_null(doctorList.getContent());
}

Test(KoalaDoctorList, Test_KoalaDoctorList_getContent_acces_to_pointer, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);

    cr_assert(doctorList.getContent()->getName() == "Doctor");
}

Test(KoalaDoctorList, Test_KoalaDoctorList_getNext_return_nullptr, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);

    cr_assert_null(doctorList.getNext());
}

Test(KoalaDoctorList, Test_KoalaDoctorList_getNext_return_ptr_on_next, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);

    cr_assert_null(doctorList.getNext());
}

Test(KoalaDoctorList, Test_KoalaDoctorList_isEnd_return_true, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);

    cr_assert(doctorList.isEnd() == true);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_isEnd_return_false, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);

    doctorList.append(&doctorList2);
    cr_assert(doctorList.isEnd() == false);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_isEnd_after_clean_list_return_true, .init = redirect_all_stdout)
{
    std::string       name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);

    doctorList.append(&doctorList2);
    doctorList.append(&doctorList3);
    doctorList.dump();

    doctorList.remove(&doctorList);
    doctorList.dump();
    doctorList.removeFromName("Doctor2");
    doctorList.dump();
    doctorList.remove(&doctorList3);
    doctorList.dump();


    cr_assert_null(doctorList.getNext());
    cr_assert(doctorList.isEnd() == true);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_append_isDefined, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);

    doctorList.append(&doctorList2);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_append_nodeList_is_nullptr
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   *doctorList2 = nullptr;

    cr_assert_null(doctorList2);
    doctorList.append(doctorList2);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_append_nodeList_is_nullptr_stderr
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   *doctorList2 = nullptr;

    cr_assert_null(doctorList2);
    doctorList.append(doctorList2);
    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a null node.\n"
    );
}

Test(KoalaDoctorList, Test_KoalaDoctorList_append_doctorListDoctor_is_nullptr
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       *doctor2 = nullptr;
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(doctor2);

    cr_assert_null(doctor2);
    doctorList2.append(&doctorList);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_append_one_node
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);

    doctorList2.append(&doctorList);
    cr_assert(doctorList2.getContent()->getName() == "Doctor2");
    cr_assert(doctorList2.getNext()->getContent()->getName() == "Doctor");
}

Test(KoalaDoctorList, Test_KoalaDoctorList_append_should_avoid_same_node
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    doctorList2.append(&doctorList);
    doctorList2.append(&doctorList3);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList3);

    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a duplicate node.\n"
        "Error: Trying to append a duplicate node.\n"
    );
}

Test(KoalaDoctorList, Test_KoalaDoctorList_append_several_nodes
, .init = redirect_all_stdout)
{
    { 
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   doctorList2(&doctor2);
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        doctorList2.append(&doctorList);
        doctorList2.append(&doctorList3);
        doctorList2.append(&doctorList4);

        KoalaDoctorList *current = &doctorList2;

        while (current != nullptr)
        {
            if (current->getContent())
                cr_assert(current->getContent()->getName() != "");

            current = current->getNext();
        }
    }
}

Test(KoalaDoctorList, Test_KoalaDoctorList_getFromName_isDefinied
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    doctorList2.append(&doctorList);
    doctorList2.append(&doctorList3);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList3);

    doctorList2.getFromName("Doctor");
}

Test(KoalaDoctorList, Test_KoalaDoctorList_getFromName_not_matches_should_nullptr
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    doctorList2.append(&doctorList);
    doctorList2.append(&doctorList3);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList3);

    cr_assert(doctorList2.getFromName("glitch") == nullptr);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_getFromName_matches_should_ptr_to_doctorListDoctor
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    doctorList2.append(&doctorList);
    doctorList2.append(&doctorList3);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList3);

    cr_assert(doctorList2.getFromName("Doctor")->getName() == "Doctor");
    cr_assert(doctorList2.getFromName("Doctor2")->getName() == "Doctor2");
    cr_assert(doctorList2.getFromName("Doctor3")->getName() == "Doctor3");
    cr_assert(doctorList2.getFromName("Doctor4")->getName() == "Doctor4");
}

Test(KoalaDoctorList, Test_KoalaDoctorList_remove_isDefined
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    doctorList2.append(&doctorList);
    doctorList2.append(&doctorList3);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList4);
    doctorList2.append(&doctorList3);

    doctorList2.remove(&doctorList3);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_remove_unknow_node
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);

    cr_assert(doctorList.remove(&doctorList2) == &doctorList);
}

Test(KoalaDoctorList, Test_KoalaDoctorList_remove_nodeList_is_nullptr
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   *doctorList2 = nullptr;
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    doctorList.append(doctorList2);
    doctorList.append(&doctorList3);
    doctorList.append(&doctorList4);
    cr_assert_null(doctorList2);
    cr_assert(doctorList.remove(doctorList2)->getContent()->getName() == "Doctor");
}

Test(KoalaDoctorList, Test_KoalaDoctorList_remove_nodeList_is_nullptr_with_output
, .init = redirect_all_stdout)
{
    {
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   *doctorList2 = nullptr;
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        doctorList.append(doctorList2);
        doctorList.append(&doctorList3);
        doctorList.append(&doctorList4);
        cr_assert_null(doctorList2);
        cr_assert(doctorList.remove(doctorList2)->getContent()->getName() == "Doctor");
    }
    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a null node.\n"
        "Error: Trying to delete a null node.\n"
    );
    cr_assert_stdout_eq_str
    (
        "Dr.Doctor: I'm Dr.Doctor! How do you kreog?\n"
        "Dr.Doctor2: I'm Dr.Doctor2! How do you kreog?\n"
        "Dr.Doctor3: I'm Dr.Doctor3! How do you kreog?\n"
        "Dr.Doctor4: I'm Dr.Doctor4! How do you kreog?\n"
    );
}

Test(KoalaDoctorList, Test_KoalaDoctorList_remove_node_from_list_with_only_one_node
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);

    KoalaDoctorList   doctorList(&doctor);

    cr_assert_null(doctorList.remove(&doctorList)->getContent());
}


Test(KoalaDoctorList, Test_KoalaDoctorList_remove_first_nodeList
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    doctorList.append(&doctorList2);
    doctorList.append(&doctorList3);
    doctorList.append(&doctorList4);

    cr_assert_null(doctorList.remove(&doctorList)->getContent());
}

Test(KoalaDoctorList, Test_KoalaDoctorList_remove_a_nodeList
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctor       doctor5("doctor5");

    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    KoalaDoctorList   doctorList5(&doctor5);
    doctorList.append(&doctorList2);
    doctorList.append(&doctorList3);
    doctorList.append(&doctorList4);

    doctorList.remove(&doctorList3);
    KoalaDoctorList *current = &doctorList;

    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());

        current = current->getNext();
    }
}

Test(KoalaDoctorList, Test_KoalaDoctorList_remove_several_nodeList,
.init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctor       doctor5("doctor5");

    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    KoalaDoctorList   doctorList5(&doctor5);
    doctorList.append(&doctorList2);
    doctorList.append(&doctorList3);
    doctorList.append(&doctorList4);

    doctorList.remove(&doctorList);
    doctorList.remove(&doctorList2);
    doctorList.remove(&doctorList3);
    doctorList.remove(&doctorList4);
    
    KoalaDoctorList *current = &doctorList;

    while (current != nullptr)
    {
        if (!current->getContent())
            cr_assert_null(current->getContent());
        current = current->getNext();
    }
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_isDefined
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);

    doctorList.append(&doctorList2);
    doctorList.append(&doctorList3);
    doctorList.append(&doctorList4);

    doctorList.removeFromName("Doctor3");
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_from_empty_list
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   test(nullptr);

    cr_assert_null(test.removeFromName("Doctor")->getContent());
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_the_first_node
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);
    doctorList.removeFromName("Doctor");

    // cr_assert_null(doctorList.getContent());
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_the_first_node_several_times
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);
    doctorList.removeFromName("Doctor");
    doctorList.removeFromName("Doctor");

    cr_assert_null(doctorList.getContent());
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_a_node
, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    
    doctorList.append(&doctorList2);
    doctorList.append(&doctorList3);
    doctorList.append(&doctorList4);

    doctorList.removeFromName("Doctor3");

    KoalaDoctorList *current = &doctorList;

    std::cout << "Doctors: " << std::flush;
    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());

        if (current->getNext())
            std::cout << ", " << std::flush;
        else
            std::cout << ".\n"  << std::flush;
        current = current->getNext();
    }
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_a_same_node_several_times , .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctor       doctor2("Doctor2");
    KoalaDoctor       doctor3("Doctor3");
    KoalaDoctor       doctor4("Doctor4");
    KoalaDoctorList   doctorList(&doctor);
    KoalaDoctorList   doctorList2(&doctor2);
    KoalaDoctorList   doctorList3(&doctor3);
    KoalaDoctorList   doctorList4(&doctor4);
    
    doctorList.append(&doctorList2);
    doctorList.append(&doctorList3);
    doctorList.append(&doctorList4);

    doctorList.removeFromName("Doctor3");
    doctorList.removeFromName("Doctor3");
    doctorList.removeFromName("Doctor4");
    doctorList.removeFromName("Doctor3");

    KoalaDoctorList *current = &doctorList;

    std::cout << "Doctors: " << std::flush;
    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());

        if (current->getNext())
            std::cout << ", " << std::flush;
        else
            std::cout << ".\n"  << std::flush;
        current = current->getNext();
    }
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_first_node_stdout
, .init = redirect_all_stdout)
{
    {
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   doctorList2(&doctor2);
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        
        doctorList.append(&doctorList2);
        doctorList.append(&doctorList3);
        doctorList.append(&doctorList4);

        doctorList.removeFromName("Doctor");

        doctorList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doctor: I'm Dr.Doctor! How do you kreog?\n"
        "Dr.Doctor2: I'm Dr.Doctor2! How do you kreog?\n"
        "Dr.Doctor3: I'm Dr.Doctor3! How do you kreog?\n"
        "Dr.Doctor4: I'm Dr.Doctor4! How do you kreog?\n"
        "Doctors: Doctor2, Doctor3, Doctor4.\n"
    );
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_a_node_stdout
, .init = redirect_all_stdout)
{
    {
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   doctorList2(&doctor2);
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        
        doctorList.append(&doctorList2);
        doctorList.append(&doctorList3);
        doctorList.append(&doctorList4);

        doctorList.removeFromName("Doctor3");

        KoalaDoctorList *current = &doctorList;

        std::cout << "Doctors: " << std::flush;
        while (current != nullptr)
        {
            if (current->getContent())
                std::cout << current->getContent()->getName() << std::flush;

            if (current->getNext())
                std::cout << ", " << std::flush;
            else
                std::cout << ".\n"  << std::flush;
            current = current->getNext();
        }
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doctor: I'm Dr.Doctor! How do you kreog?\n"
        "Dr.Doctor2: I'm Dr.Doctor2! How do you kreog?\n"
        "Dr.Doctor3: I'm Dr.Doctor3! How do you kreog?\n"
        "Dr.Doctor4: I'm Dr.Doctor4! How do you kreog?\n"
        "Doctors: Doctor, Doctor2, Doctor4.\n"
    );
}

Test(KoalaDoctorList, Test_KoalaDoctorList_removeFromName_several_node_stdout
, .init = redirect_all_stdout)
{
    {
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   doctorList2(&doctor2);
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        
        doctorList.append(&doctorList2);
        doctorList.append(&doctorList3);
        doctorList.append(&doctorList4);

        doctorList.removeFromName("Doctor");
        doctorList.removeFromName("Doctor2");
        doctorList.removeFromName("Doctor3");
        doctorList.removeFromName("Doctor4");

        KoalaDoctorList *current = &doctorList;

        std::cout << "Doctors: " << std::flush;
        while (current != nullptr)
        {
            if (!current->getContent())
                std::cout << "[nullptr]" << std::flush;                
            current = current->getNext();
        }
        std::cout << ".\n"  << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doctor: I'm Dr.Doctor! How do you kreog?\n"
        "Dr.Doctor2: I'm Dr.Doctor2! How do you kreog?\n"
        "Dr.Doctor3: I'm Dr.Doctor3! How do you kreog?\n"
        "Dr.Doctor4: I'm Dr.Doctor4! How do you kreog?\n"
        "Doctors: [nullptr].\n"
    );
}

Test(KoalaDoctorList, Test_KoalaDoctorList_dump_isDefined, .init = redirect_all_stdout)
{
    std::string     name = "Doctor";
    KoalaDoctor       doctor(name);
    KoalaDoctorList   doctorList(&doctor);
    
    doctorList.dump();
}

Test(KoalaDoctorList, Test_KoalaDoctorList_dump_display_list_stdout, .init = redirect_all_stdout)
{
    {
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   doctorList2(&doctor2);
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        
        doctorList.append(&doctorList2);
        doctorList.append(&doctorList3);
        doctorList.append(&doctorList4);
        
        doctorList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doctor: I'm Dr.Doctor! How do you kreog?\n"
        "Dr.Doctor2: I'm Dr.Doctor2! How do you kreog?\n"
        "Dr.Doctor3: I'm Dr.Doctor3! How do you kreog?\n"
        "Dr.Doctor4: I'm Dr.Doctor4! How do you kreog?\n"
        "Doctors: Doctor, Doctor2, Doctor3, Doctor4.\n"
    );
}

Test(KoalaDoctorList, Test_KoalaDoctorList_dump_display_list_with_first_node_removed_stdout,
 .init = redirect_all_stdout)
{
    {
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   doctorList2(&doctor2);
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        
        doctorList.append(&doctorList2);
        doctorList.append(&doctorList3);
        doctorList.append(&doctorList4);
        
        doctorList.remove(&doctorList);
        doctorList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doctor: I'm Dr.Doctor! How do you kreog?\n"
        "Dr.Doctor2: I'm Dr.Doctor2! How do you kreog?\n"
        "Dr.Doctor3: I'm Dr.Doctor3! How do you kreog?\n"
        "Dr.Doctor4: I'm Dr.Doctor4! How do you kreog?\n"
        "Doctors: [NULL], Doctor2, Doctor3, Doctor4.\n"
    );
}

Test(KoalaDoctorList, 
Test_KoalaDoctorList_dump_display_list_with_first_node_removedFromName_stdout,
  .init = redirect_all_stdout)
{
    {
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   doctorList2(&doctor2);
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        
        doctorList.append(&doctorList2);
        doctorList.append(&doctorList3);
        doctorList.append(&doctorList4);
        
        doctorList.removeFromName(name);
        doctorList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doctor: I'm Dr.Doctor! How do you kreog?\n"
        "Dr.Doctor2: I'm Dr.Doctor2! How do you kreog?\n"
        "Dr.Doctor3: I'm Dr.Doctor3! How do you kreog?\n"
        "Dr.Doctor4: I'm Dr.Doctor4! How do you kreog?\n"
        "Doctors: Doctor2, Doctor3, Doctor4.\n"
    );
}

Test(KoalaDoctorList,
Test_KoalaDoctorList_dump_display_list_with_first_node_removed_with_another_node_stdout,
.init = redirect_all_stdout)
{
    {
        std::string     name = "Doctor";
        KoalaDoctor       doctor(name);
        KoalaDoctor       doctor2("Doctor2");
        KoalaDoctor       doctor3("Doctor3");
        KoalaDoctor       doctor4("Doctor4");
        KoalaDoctorList   doctorList(&doctor);
        KoalaDoctorList   doctorList2(&doctor2);
        KoalaDoctorList   doctorList3(&doctor3);
        KoalaDoctorList   doctorList4(&doctor4);
        
        doctorList.append(&doctorList2);
        doctorList.append(&doctorList3);
        doctorList.append(&doctorList4);
        
        doctorList.remove(&doctorList3);
        doctorList.removeFromName(name);
        doctorList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Dr.Doctor: I'm Dr.Doctor! How do you kreog?\n"
        "Dr.Doctor2: I'm Dr.Doctor2! How do you kreog?\n"
        "Dr.Doctor3: I'm Dr.Doctor3! How do you kreog?\n"
        "Dr.Doctor4: I'm Dr.Doctor4! How do you kreog?\n"
        "Doctors: Doctor2, Doctor4.\n"
    );
}

Test(KoalaNurseList, Test_KoalaNurseList_CTOR_isDefined, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);
    
    cr_assert_not_null(&nurseList);
}

Test(KoalaNurseList, Test_KoalaNurseList_getContent_isDefined, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);

    cr_assert_not_null(nurseList.getContent());
}

Test(KoalaNurseList, Test_KoalaNurseList_getContent_acces_to_pointer, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);

    cr_assert(nurseList.getContent()->getId() == 1);
}

Test(KoalaNurseList, Test_KoalaNurseList_getNext_return_nullptr, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);

    cr_assert_null(nurseList.getNext());
}

Test(KoalaNurseList, Test_KoalaNurseList_getNext_return_ptr_on_next, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);

    cr_assert_null(nurseList.getNext());
}

Test(KoalaNurseList, Test_KoalaNurseList_isEnd_return_true, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);

    cr_assert(nurseList.isEnd() == true);
}

Test(KoalaNurseList, Test_KoalaNurseList_isEnd_return_false, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);

    nurseList.append(&nurseList2);
    cr_assert(nurseList.isEnd() == false);
}

Test(KoalaNurseList, Test_KoalaNurseList_isEnd_after_clean_list_return_true, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);

    nurseList.append(&nurseList2);
    nurseList.append(&nurseList3);
    nurseList.dump();

    nurseList.remove(&nurseList);
    nurseList.dump();
    nurseList.removeFromID(2);
    nurseList.dump();
    nurseList.remove(&nurseList3);
    nurseList.dump();


    cr_assert_null(nurseList.getNext());
    cr_assert(nurseList.isEnd() == true);
}

Test(KoalaNurseList, Test_KoalaNurseList_append_isDefined, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);

    nurseList.append(&nurseList2);
}

Test(KoalaNurseList, Test_KoalaNurseList_append_nodeList_is_nullptr
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   *nurseList2 = nullptr;

    cr_assert_null(nurseList2);
    nurseList.append(nurseList2);
}

Test(KoalaNurseList, Test_KoalaNurseList_append_nodeList_is_nullptr_stderr
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   *nurseList2 = nullptr;

    cr_assert_null(nurseList2);
    nurseList.append(nurseList2);
    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a null node.\n"
    );
}

Test(KoalaNurseList, Test_KoalaNurseList_append_nurseListNurse_is_nullptr
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       *nurse2 = nullptr;
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(nurse2);

    cr_assert_null(nurse2);
    nurseList2.append(&nurseList);
}

Test(KoalaNurseList, Test_KoalaNurseList_append_one_node
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);

    nurseList2.append(&nurseList);
    cr_assert(nurseList2.getContent()->getId() == 2);
    cr_assert(nurseList2.getNext()->getContent()->getId() == 1);
}

Test(KoalaNurseList, Test_KoalaNurseList_append_should_avoid_same_node
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    nurseList2.append(&nurseList);
    nurseList2.append(&nurseList3);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList3);

    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a duplicate node.\n"
        "Error: Trying to append a duplicate node.\n"
    );
}

Test(KoalaNurseList, Test_KoalaNurseList_append_several_nodes
, .init = redirect_all_stdout)
{
    { 
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   nurseList2(&nurse2);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        nurseList2.append(&nurseList);
        nurseList2.append(&nurseList3);
        nurseList2.append(&nurseList4);

        KoalaNurseList *current = &nurseList2;

        while (current != nullptr)
        {
            if (current->getContent())
                cr_assert(current->getContent()->getId() != 0); //shit test

            current = current->getNext();
        }
    }
}

Test(KoalaNurseList, Test_KoalaNurseList_getFromName_isDefinied
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    nurseList2.append(&nurseList);
    nurseList2.append(&nurseList3);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList3);

    nurseList2.getFromID(1);
}

Test(KoalaNurseList, Test_KoalaNurseList_getFromName_not_matches_should_nullptr
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    nurseList2.append(&nurseList);
    nurseList2.append(&nurseList3);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList3);

    cr_assert(nurseList2.getFromID(5) == nullptr);
}

Test(KoalaNurseList, Test_KoalaNurseList_getFromName_matches_should_ptr_to_nurseListNurse
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    nurseList2.append(&nurseList);
    nurseList2.append(&nurseList3);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList3);

    cr_assert(nurseList2.getFromID(1)->getId() == 1);
    cr_assert(nurseList2.getFromID(2)->getId() == 2);
    cr_assert(nurseList2.getFromID(3)->getId() == 3);
    cr_assert(nurseList2.getFromID(4)->getId() == 4);
}

Test(KoalaNurseList, Test_KoalaNurseList_remove_isDefined
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    nurseList2.append(&nurseList);
    nurseList2.append(&nurseList3);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList4);
    nurseList2.append(&nurseList3);

    nurseList2.remove(&nurseList3);
}

Test(KoalaNurseList, Test_KoalaNurseList_remove_unknow_node
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);

    cr_assert(nurseList.remove(&nurseList2) == &nurseList);
}

Test(KoalaNurseList, Test_KoalaNurseList_remove_nodeList_is_nullptr
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   *nurseList2 = nullptr;
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    nurseList.append(nurseList2);
    nurseList.append(&nurseList3);
    nurseList.append(&nurseList4);
    cr_assert_null(nurseList2);
    cr_assert(nurseList.remove(nurseList2)->getContent()->getId() == 1);
}

Test(KoalaNurseList, Test_KoalaNurseList_remove_nodeList_is_nullptr_with_output
, .init = redirect_all_stdout)
{
    {
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   *nurseList2 = nullptr;
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        nurseList.append(nurseList2);
        nurseList.append(&nurseList3);
        nurseList.append(&nurseList4);
        cr_assert_null(nurseList2);
        cr_assert(nurseList.remove(nurseList2)->getContent()->getId() == 1);
    }
    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a null node.\n"
        "Error: Trying to delete a null node.\n"
    );
    cr_assert_stdout_eq_str
    (
        "Nurse 4: Finally some rest!\n"
        "Nurse 3: Finally some rest!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

Test(KoalaNurseList, Test_KoalaNurseList_remove_node_from_list_with_only_one_node
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);

    KoalaNurseList   nurseList(&nurse);

    cr_assert_null(nurseList.remove(&nurseList)->getContent());
}


Test(KoalaNurseList, Test_KoalaNurseList_remove_first_nodeList
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    nurseList.append(&nurseList2);
    nurseList.append(&nurseList3);
    nurseList.append(&nurseList4);

    cr_assert_null(nurseList.remove(&nurseList)->getContent());
}

Test(KoalaNurseList, Test_KoalaNurseList_remove_a_nodeList
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurse       nurse5(5);

    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    KoalaNurseList   nurseList5(&nurse5);
    nurseList.append(&nurseList2);
    nurseList.append(&nurseList3);
    nurseList.append(&nurseList4);

    nurseList.remove(&nurseList3);
    KoalaNurseList *current = &nurseList;

    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());

        current = current->getNext();
    }
}

Test(KoalaNurseList, Test_KoalaNurseList_remove_several_nodeList,
.init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurse       nurse5(5);

    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    KoalaNurseList   nurseList5(&nurse5);
    nurseList.append(&nurseList2);
    nurseList.append(&nurseList3);
    nurseList.append(&nurseList4);

    nurseList.remove(&nurseList);
    nurseList.remove(&nurseList2);
    nurseList.remove(&nurseList3);
    nurseList.remove(&nurseList4);
    
    KoalaNurseList *current = &nurseList;

    while (current != nullptr)
    {
        if (!current->getContent())
            cr_assert_null(current->getContent());
        current = current->getNext();
    }
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_isDefined
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);

    nurseList.append(&nurseList2);
    nurseList.append(&nurseList3);
    nurseList.append(&nurseList4);

    nurseList.removeFromID(3);
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_from_empty_list
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   test(nullptr);

    cr_assert_null(test.removeFromID(1)->getContent());
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_the_first_node
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);

    nurseList.removeFromID(1);
    cr_assert_null(nurseList.getContent());
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_the_first_node_several_times
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);
    nurseList.removeFromID(1);
    nurseList.removeFromID(1);
    cr_assert_null(nurseList.getContent());
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_a_node
, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    
    nurseList.append(&nurseList2);
    nurseList.append(&nurseList3);
    nurseList.append(&nurseList4);

    nurseList.removeFromID(3);

    KoalaNurseList *current = &nurseList;

    std::cout << "Nurses: " << std::flush;
    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());

        if (current->getNext())
            std::cout << ", " << std::flush;
        else
            std::cout << ".\n"  << std::flush;
        current = current->getNext();
    }
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_a_same_node_several_times , .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurse       nurse2(2);
    KoalaNurse       nurse3(3);
    KoalaNurse       nurse4(4);
    KoalaNurseList   nurseList(&nurse);
    KoalaNurseList   nurseList2(&nurse2);
    KoalaNurseList   nurseList3(&nurse3);
    KoalaNurseList   nurseList4(&nurse4);
    
    nurseList.append(&nurseList2);
    nurseList.append(&nurseList3);
    nurseList.append(&nurseList4);

    nurseList.removeFromID(3);
    nurseList.removeFromID(3);
    nurseList.removeFromID(4);
    nurseList.removeFromID(3);

    KoalaNurseList *current = &nurseList;

    std::cout << "Nurses: " << std::flush;
    while (current != nullptr)
    {
        if (current->getContent())
            cr_assert_not_null(current->getContent());

        if (current->getNext())
            std::cout << ", " << std::flush;
        else
            std::cout << ".\n"  << std::flush;
        current = current->getNext();
    }
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_first_node_stdout
, .init = redirect_all_stdout)
{
    {
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   nurseList2(&nurse2);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        
        nurseList.append(&nurseList2);
        nurseList.append(&nurseList3);
        nurseList.append(&nurseList4);

        nurseList.removeFromID(1);
        nurseList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Nurses: 2, 3, 4.\n"
        "Nurse 4: Finally some rest!\n"
        "Nurse 3: Finally some rest!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_a_node_stdout
, .init = redirect_all_stdout)
{
    {
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   nurseList2(&nurse2);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        
        nurseList.append(&nurseList2);
        nurseList.append(&nurseList3);
        nurseList.append(&nurseList4);

        nurseList.removeFromID(3);

        KoalaNurseList *current = &nurseList;

        std::cout << "Nurses: " << std::flush;
        while (current != nullptr)
        {
            if (current->getContent())
                std::cout << current->getContent()->getId() << std::flush;

            if (current->getNext())
                std::cout << ", " << std::flush;
            else
                std::cout << ".\n"  << std::flush;
            current = current->getNext();
        }
    }
    cr_assert_stdout_eq_str
    (
        "Nurses: 1, 2, 4.\n"
        "Nurse 4: Finally some rest!\n"
        "Nurse 3: Finally some rest!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

Test(KoalaNurseList, Test_KoalaNurseList_removeFromName_several_node_stdout
, .init = redirect_all_stdout)
{
    {
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   nurseList2(&nurse2);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        
        nurseList.append(&nurseList2);
        nurseList.append(&nurseList3);
        nurseList.append(&nurseList4);

        nurseList.removeFromID(1);
        nurseList.removeFromID(2);
        nurseList.removeFromID(3);
        nurseList.removeFromID(4);

        KoalaNurseList *current = &nurseList;

        std::cout << "Nurses: " << std::flush;
        while (current != nullptr)
        {
            if (!current->getContent())
                std::cout << "[nullptr]" << std::flush;                
            current = current->getNext();
        }
        std::cout << ".\n"  << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "Nurses: [nullptr].\n"
        "Nurse 4: Finally some rest!\n"
        "Nurse 3: Finally some rest!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

Test(KoalaNurseList, Test_KoalaNurseList_dump_isDefined, .init = redirect_all_stdout)
{
    KoalaNurse       nurse(1);
    KoalaNurseList   nurseList(&nurse);
    
    nurseList.dump();
}

Test(KoalaNurseList, Test_KoalaNurseList_dump_display_list_stdout, .init = redirect_all_stdout)
{
    {
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   nurseList2(&nurse2);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        
        nurseList.append(&nurseList2);
        nurseList.append(&nurseList3);
        nurseList.append(&nurseList4);
        
        nurseList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Nurses: 1, 2, 3, 4.\n"
        "Nurse 4: Finally some rest!\n"
        "Nurse 3: Finally some rest!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

Test(KoalaNurseList, Test_KoalaNurseList_dump_display_list_with_first_node_removed_stdout,
 .init = redirect_all_stdout)
{
    {
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   nurseList2(&nurse2);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        
        nurseList.append(&nurseList2);
        nurseList.append(&nurseList3);
        nurseList.append(&nurseList4);
        
        nurseList.remove(&nurseList);
        nurseList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Nurses: [NULL], 2, 3, 4.\n"
        "Nurse 4: Finally some rest!\n"
        "Nurse 3: Finally some rest!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

Test(KoalaNurseList, 
Test_KoalaNurseList_dump_display_list_with_first_node_removedFromName_stdout,
  .init = redirect_all_stdout)
{
    {
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   nurseList2(&nurse2);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        
        nurseList.append(&nurseList2);
        nurseList.append(&nurseList3);
        nurseList.append(&nurseList4);
        
        nurseList.removeFromID(1);
        nurseList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Nurses: 2, 3, 4.\n"
        "Nurse 4: Finally some rest!\n"
        "Nurse 3: Finally some rest!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

Test(KoalaNurseList,
Test_KoalaNurseList_dump_display_list_with_first_node_removed_with_another_node_stdout,
.init = redirect_all_stdout)
{
    {
        KoalaNurse       nurse(1);
        KoalaNurse       nurse2(2);
        KoalaNurse       nurse3(3);
        KoalaNurse       nurse4(4);
        KoalaNurseList   nurseList(&nurse);
        KoalaNurseList   nurseList2(&nurse2);
        KoalaNurseList   nurseList3(&nurse3);
        KoalaNurseList   nurseList4(&nurse4);
        
        nurseList.append(&nurseList2);
        nurseList.append(&nurseList3);
        nurseList.append(&nurseList4);
        
        nurseList.remove(&nurseList3);
        nurseList.removeFromID(1);
        nurseList.dump();
    }
    cr_assert_stdout_eq_str
    (
        "Nurses: 2, 4.\n"
        "Nurse 4: Finally some rest!\n"
        "Nurse 3: Finally some rest!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

Test(Hospital, Test_Hospital_CTOR_isDefined, .init = redirect_all_stdout)
{
    Hospital    bellevue;

    cr_assert_not_null(&bellevue);
}

Test(Hospital, Test_Hospital_private_attributs_should_be_nullptr, .init = redirect_all_stdout)
{
    Hospital    bellevue;

    cr_assert_null(bellevue.getSickKoalaList());
    cr_assert_null(bellevue.getKoalaNurseList());
    cr_assert_null(bellevue.getKoalaDoctorList());
}

Test(Hospital, Test_Hospital_addDoctor_isDefined, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaDoctor     cox("Cox");
    KoalaDoctorList doc1(&cox);

    bellevue.addDoctor(&doc1);
}

Test(Hospital, Test_Hospital_addDoctor_one_node_koalaDoctorList_not_null, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaDoctor     cox("Cox");
    KoalaDoctorList doc1(&cox);

    bellevue.addDoctor(&doc1);
    cr_assert_not_null(bellevue.getKoalaDoctorList());
}

Test(Hospital, Test_Hospital_addDoctor_several_nodes_koalaDoctorList_not_null, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaDoctor     cox("Cox");
    KoalaDoctor     house("House");
    KoalaDoctor     tired("Boudur-Oulot");
    KoalaDoctorList doc1(&cox);
    KoalaDoctorList doc2(&house);
    KoalaDoctorList doc3(&tired);

    bellevue.addDoctor(&doc1);
    bellevue.addDoctor(&doc2);
    bellevue.addDoctor(&doc3);

    cr_assert_not_null(bellevue.getKoalaDoctorList()->getFromName("Cox"));
    cr_assert_not_null(bellevue.getKoalaDoctorList()->getFromName("House"));
    cr_assert_not_null(bellevue.getKoalaDoctorList()->getFromName("Boudur-Oulot"));
    cr_assert(bellevue.getKoalaDoctorList()->getFromName("Cox")->getName() == "Cox");
    cr_assert(bellevue.getKoalaDoctorList()->getFromName("House")->getName() == "House");
    cr_assert(bellevue.getKoalaDoctorList()->getFromName("Boudur-Oulot")->getName() == "Boudur-Oulot");
}

Test(Hospital, Test_Hospital_addDoctor_duplicate_node_output, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaDoctor     cox("Cox");
    KoalaDoctorList doc1(&cox);

    bellevue.addDoctor(&doc1);
    bellevue.addDoctor(&doc1);

    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a duplicate node.\n"
    );
}

Test(Hospital, Test_Hospital_addDoctor_output, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaDoctor     cox("Cox");
    KoalaDoctor     house("House");
    KoalaDoctor     tired("Boudur-Oulot");
    KoalaDoctorList doc1(&cox);
    KoalaDoctorList doc2(&house);
    KoalaDoctorList doc3(&tired);

    bellevue.addDoctor(&doc1);
    bellevue.addDoctor(&doc2);
    bellevue.addDoctor(&doc3);

    cr_assert_stdout_eq_str
    (
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n"
        "Dr.House: I'm Dr.House! How do you kreog?\n"
        "Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n"
        "[HOSPITAL] Doctor Cox just arrived!\n"
        "Dr.Cox: Time to get to work!\n"
        "[HOSPITAL] Doctor House just arrived!\n"
        "Dr.House: Time to get to work!\n"
        "[HOSPITAL] Doctor Boudur-Oulot just arrived!\n"
        "Dr.Boudur-Oulot: Time to get to work!\n"       
    );
}

Test(Hospital, Test_Hospital_addSick_isDefined, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    SickKoala       cancer("Ganepar");
    SickKoalaList   sick1(&cancer);

    bellevue.addSick(&sick1);
}

Test(Hospital, Test_Hospital_addSick_one_node_SickKoalaList_not_null, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    SickKoala       cancer("Ganepar");
    SickKoalaList   sick1(&cancer);

    bellevue.addSick(&sick1);

    cr_assert_not_null(bellevue.getSickKoalaList());
}

Test(Hospital, Test_Hospital_addSick_duplicate_node_output, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    SickKoala       cancer("Ganepar");
    SickKoalaList   sick1(&cancer);

    bellevue.addSick(&sick1);
    bellevue.addSick(&sick1);

    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a duplicate node.\n"
    );
}

Test(Hospital, Test_Hospital_addSick_several_nodes_SickKoalaList_not_null, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    SickKoala       cancer("Ganepar");
    SickKoala       gangrene("Scarface");
    SickKoala       measles("RedFace");
    SickKoala       smallpox("Varia");
    SickKoala       fracture("Falter");
    SickKoalaList   sick1(&cancer);
    SickKoalaList   sick4(&gangrene);
    SickKoalaList   sick3(&measles);
    SickKoalaList   sick2(&smallpox);
    SickKoalaList   sick5(&fracture);

    bellevue.addSick(&sick1);
    bellevue.addSick(&sick2);
    bellevue.addSick(&sick3);
    bellevue.addSick(&sick4);
    bellevue.addSick(&sick5);
    cr_assert_not_null(bellevue.getSickKoalaList()->getFromName("Ganepar"));
    cr_assert_not_null(bellevue.getSickKoalaList()->getFromName("Scarface"));
    cr_assert_not_null(bellevue.getSickKoalaList()->getFromName("RedFace"));
    cr_assert_not_null(bellevue.getSickKoalaList()->getFromName("Varia"));
    cr_assert_not_null(bellevue.getSickKoalaList()->getFromName("Falter"));
    cr_assert(bellevue.getSickKoalaList()->getFromName("Ganepar")->getName() == "Ganepar");
    cr_assert(bellevue.getSickKoalaList()->getFromName("Scarface")->getName() == "Scarface");
    cr_assert(bellevue.getSickKoalaList()->getFromName("RedFace")->getName() == "RedFace");
    cr_assert(bellevue.getSickKoalaList()->getFromName("Varia")->getName() == "Varia");
    cr_assert(bellevue.getSickKoalaList()->getFromName("Falter")->getName() == "Falter");
}

Test(Hospital, Test_Hospital_addSick_output, .init = redirect_all_stdout)
{
    {
        Hospital        bellevue;
        SickKoala       cancer("Ganepar");
        SickKoala       gangrene("Scarface");
        SickKoala       measles("RedFace");
        SickKoala       smallpox("Varia");
        SickKoala       fracture("Falter");
        SickKoalaList   sick1(&cancer);
        SickKoalaList   sick4(&gangrene);
        SickKoalaList   sick3(&measles);
        SickKoalaList   sick2(&smallpox);
        SickKoalaList   sick5(&fracture);

        bellevue.addSick(&sick1);
        bellevue.addSick(&sick2);
        bellevue.addSick(&sick3);
        bellevue.addSick(&sick4);
        bellevue.addSick(&sick5);
    }
    cr_assert_stdout_eq_str
    (
        "[HOSPITAL] Patient Ganepar just arrived!\n"
        "[HOSPITAL] Patient Varia just arrived!\n"
        "[HOSPITAL] Patient RedFace just arrived!\n"
        "[HOSPITAL] Patient Scarface just arrived!\n"
        "[HOSPITAL] Patient Falter just arrived!\n"
        "Mr.Falter: Kreooogg!! I'm cuuuured!\n"
        "Mr.Varia: Kreooogg!! I'm cuuuured!\n"
        "Mr.RedFace: Kreooogg!! I'm cuuuured!\n"
        "Mr.Scarface: Kreooogg!! I'm cuuuured!\n"
        "Mr.Ganepar: Kreooogg!! I'm cuuuured!\n"
    );
}







Test(Hospital, Test_Hospital_addNurse_isDefined, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaNurse       nurse(1);
    KoalaNurseList   nurse1(&nurse);

    bellevue.addNurse(&nurse1);
}

Test(Hospital, Test_Hospital_addNurse_one_node_KoalaNurseList_not_null, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaNurse       nurse(1);
    KoalaNurseList   nurse1(&nurse);

    bellevue.addNurse(&nurse1);

    cr_assert_not_null(bellevue.getKoalaNurseList());
}

Test(Hospital, Test_Hospital_addSick_several_nodes_addNurse_not_null, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaNurse       nurse(1);
    KoalaNurse       nursy(2);

    KoalaNurseList   nurse1(&nurse);
    KoalaNurseList   nurse2(&nursy);

    bellevue.addNurse(&nurse1);
    bellevue.addNurse(&nurse2);

    cr_assert_not_null(bellevue.getKoalaNurseList()->getFromID(1));
    cr_assert_not_null(bellevue.getKoalaNurseList()->getFromID(2));

    cr_assert(bellevue.getKoalaNurseList()->getFromID(1)->getId() == 1);
    cr_assert(bellevue.getKoalaNurseList()->getFromID(2)->getId() == 2);
}

Test(Hospital, Test_Hospital_addNurse_duplicate_node_output, .init = redirect_all_stdout)
{
    Hospital        bellevue;
    KoalaNurse       nurse(1);
    KoalaNurseList   nurse1(&nurse);

    bellevue.addNurse(&nurse1);
    bellevue.addNurse(&nurse1);

    cr_assert_stderr_eq_str
    (
        "Error: Trying to append a duplicate node.\n"
    );
}

Test(Hospital, Test_Hospital_addNurse_output, .init = redirect_all_stdout)
{
    {
        Hospital            bellevue;
        KoalaNurse          nurse(1);
        KoalaNurse          nursy(2);

        KoalaNurseList      nurse1(&nurse);
        KoalaNurseList      nurse2(&nursy);

        bellevue.addNurse(&nurse1);
        bellevue.addNurse(&nurse2);
    }
    cr_assert_stdout_eq_str
    (
        "[HOSPITAL] Nurse 1 just arrived!\n"
        "Nurse 1: Time to get to work!\n"
        "[HOSPITAL] Nurse 2 just arrived!\n"
        "Nurse 2: Time to get to work!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}

// FINAL MAIN
Test(Hospital, Test_Hospital_main_function, .init = redirect_all_stdout)
{
    {
        srandom(42);
        KoalaDoctor     cox("Cox");
        KoalaDoctor     house("House");
        KoalaDoctor     tired("Boudur-Oulot");
        KoalaDoctorList doc1(&cox);
        KoalaDoctorList doc2(&house);
        KoalaDoctorList doc3(&tired);
        KoalaNurse      ratched(1);
        KoalaNurse      betty(2);
        KoalaNurseList  nurse1(&ratched);
        KoalaNurseList  nurse2(&betty);
        SickKoala       cancer("Ganepar");
        SickKoala       gangrene("Scarface");
        SickKoala       measles("RedFace");
        SickKoala       smallpox("Varia");
        SickKoala       fracture("Falter");
        SickKoalaList   sick1(&cancer);
        SickKoalaList   sick4(&gangrene);
        SickKoalaList   sick3(&measles);
        SickKoalaList   sick2(&smallpox);
        SickKoalaList   sick5(&fracture);
        {
            Hospital    bellevue;
            bellevue.addDoctor(&doc1);
            bellevue.addDoctor(&doc2);
            bellevue.addDoctor(&doc3);
            bellevue.addSick(&sick1);
            bellevue.addSick(&sick2);
            bellevue.addSick(&sick3);
            bellevue.addSick(&sick4);
            bellevue.addSick(&sick5);
            bellevue.addNurse(&nurse1);
            bellevue.addNurse(&nurse2);
            bellevue.addSick(&sick4);
            bellevue.run();
        }
        if (nurse1.isEnd() && sick1.isEnd() && doc1.isEnd())
            std::cout << "Lists cleaned up." << std::endl;

    }
    cr_assert_stdout_eq_str
    (
        "Dr.Cox: I'm Dr.Cox! How do you kreog?\n"
        "Dr.House: I'm Dr.House! How do you kreog?\n"
        "Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?\n"
        "[HOSPITAL] Doctor Cox just arrived!\n"
        "Dr.Cox: Time to get to work!\n"
        "[HOSPITAL] Doctor House just arrived!\n"
        "Dr.House: Time to get to work!\n"
        "[HOSPITAL] Doctor Boudur-Oulot just arrived!\n"
        "Dr.Boudur-Oulot: Time to get to work!\n"
        "[HOSPITAL] Patient Ganepar just arrived!\n"
        "[HOSPITAL] Patient Varia just arrived!\n"
        "[HOSPITAL] Patient RedFace just arrived!\n"
        "[HOSPITAL] Patient Scarface just arrived!\n"
        "[HOSPITAL] Patient Falter just arrived!\n"
        "[HOSPITAL] Nurse 1 just arrived!\n"
        "Nurse 1: Time to get to work!\n"
        "[HOSPITAL] Nurse 2 just arrived!\n"
        "Nurse 2: Time to get to work!\n"
        "[HOSPITAL] Work starting with:\n"
        "Doctors: Cox, House, Boudur-Oulot.\n"
        "Nurses: 1, 2.\n"
        "Patients: Ganepar, Varia, RedFace, Scarface, Falter.\n"
        "Dr.Cox: So what's goerking you Mr.Ganepar?\n"
        "Mr.Ganepar: Gooeeeeerrk!!\n"
        "Nurse 1: Kreog! Mr.Ganepar needs a Kinder!\n"
        "Mr.Ganepar: There is a toy inside!\n"
        "Dr.House: So what's goerking you Mr.Varia?\n"
        "Mr.Varia: Gooeeeeerrk!!\n"
        "Nurse 2: Kreog! Mr.Varia needs a Mars!\n"
        "Mr.Varia: Mars, and it kreogs!\n"
        "Dr.Boudur-Oulot: So what's goerking you Mr.RedFace?\n"
        "Mr.RedFace: Gooeeeeerrk!!\n"
        "Nurse 1: Kreog! Mr.RedFace needs a Kinder!\n"
        "Mr.RedFace: There is a toy inside!\n"
        "Dr.Cox: So what's goerking you Mr.Scarface?\n"
        "Mr.Scarface: Gooeeeeerrk!!\n"
        "Nurse 2: Kreog! Mr.Scarface needs a Kinder!\n"
        "Mr.Scarface: There is a toy inside!\n"
        "Dr.House: So what's goerking you Mr.Falter?\n"
        "Mr.Falter: Gooeeeeerrk!!\n"
        "Nurse 1: Kreog! Mr.Falter needs a Crunch!\n"
        "Mr.Falter: Goerkreog!\n"
        "Nurse 1: Time to go home to my eucalyptus forest!\n"
        "Nurse 2: Time to go home to my eucalyptus forest!\n"
        "Dr.Cox: Time to go home to my eucalyptus forest!\n"
        "Dr.House: Time to go home to my eucalyptus forest!\n"
        "Dr.Boudur-Oulot: Time to go home to my eucalyptus forest!\n"
        "Lists cleaned up.\n"
        "Mr.Falter: Kreooogg!! I'm cuuuured!\n"
        "Mr.Varia: Kreooogg!! I'm cuuuured!\n"
        "Mr.RedFace: Kreooogg!! I'm cuuuured!\n"
        "Mr.Scarface: Kreooogg!! I'm cuuuured!\n"
        "Mr.Ganepar: Kreooogg!! I'm cuuuured!\n"
        "Nurse 2: Finally some rest!\n"
        "Nurse 1: Finally some rest!\n"
    );
}