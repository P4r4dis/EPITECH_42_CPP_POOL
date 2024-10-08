/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex04/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 30 5:33:47 PM 2024 Paradis
** Last update Wed Aug 13 5:29:26 PM 2024 Paradis
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