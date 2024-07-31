/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jul 31 4:52:25 PM 2024 Paradis
** Last update Thu Jul 31 10:29:14 PM 2024 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../include/SickKoala.hpp"
#include "../../include/KoalaNurse.hpp"
#include "../../include/KoalaDoctor.hpp"

#include "../../include/SickKoalaList.hpp"

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
        std::string     name = "Koala";
        SickKoala       patient(name);
        std::string     fileName = patient.getName();
        KoalaNurse      nurse(id);

        cr_assert(nurse.readReport("Koala.report") == "Morphine");
    }
}

Test(KoalaNurse, Test_KoalaNurse_readReport_output
, .init = redirect_all_stdout)
{
    {
        int             id = 0;
        std::string     name = "Koala";
        SickKoala       patient(name);
        std::string     fileName = patient.getName() + ".report";
        KoalaNurse      nurse(id);
        
        cr_assert(nurse.readReport(fileName) == "Morphine");
    }
    cr_assert_stdout_eq_str
    (
        "Nurse 0: Kreog! Mr.Koala needs a Morphine!\n"
        "Nurse 0: Finally some rest!\n"
        "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
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

// Test(KoalaDoctor, Test_KoalaDoctor_diagnose_stdout,
//                             .init = redirect_all_stdout)
// {
//     {
//         KoalaDoctor     doctor("Doc");
//         SickKoala       patient("Koala");

//         doctor.diagnose(&patient);
//     }
//     cr_assert_stdout_eq_str
//     (
//         "Dr.Doc: I'm Dr.Doc! How do you kreog?\n"
//         "Dr.Doc: So what's goerking you Mr.Koala?\n"
//         "Mr.Koala: Kreooogg!! I'm cuuuured!\n"
//     );
// }

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

// Test(SickKoalaList, Test_SickKoalaList_getNext_return_ptr_on_next, .init = redirect_all_stdout)
// {
//     std::string     name = "Koala";
//     SickKoala       patient(name);
//     SickKoalaList   sick(&patient);

//     cr_assert_not_null(sick.getNext());
// }

Test(SickKoalaList, Test_SickKoalaList_isEnd_return_true, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoalaList   sick(&patient);

    cr_assert(sick.isEnd() == true);
}

// Test(SickKoalaList, Test_SickKoalaList_isEnd_return_false, .init = redirect_all_stdout)
// {
//     std::string     name = "Koala";
//     SickKoala       patient(name);
//     SickKoalaList   sick(&patient);

//     cr_assert(sick.isEnd() == false);
// }

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

Test(SickKoalaList, Test_SickKoalaList_append_same_node
, .init = redirect_all_stdout)
{
    std::string     name = "Koala";
    SickKoala       patient(name);
    SickKoala       patient2("patient2");
    SickKoalaList   sick(&patient);
    SickKoalaList   sick2(&patient2);

    sick2.append(&sick);
    sick2.append(&sick);
    cr_assert(sick2.getContent()->getName() == "patient2");
    cr_assert(sick2.getNext()->getContent()->getName() == "Koala");
}

#include <iostream>
Test(SickKoalaList, Test_SickKoalaList_append_several_nodes
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
    SickKoalaList *current = &sick2;
    std::cout << "printList:" << std::endl;

    // Il manque les CR_ASSERT
    while (current != nullptr)
    {
		if (current->getContent())
			std::cout << current->getContent()->getName() << std::flush;
		else
			std::cout << "[nullptr]" << std::flush;
		if (current->getNext())
			std::cout << ", " << std::flush;
		else
			std::cout << ".\n"  << std::flush;
		current = current->getNext();
    }
}