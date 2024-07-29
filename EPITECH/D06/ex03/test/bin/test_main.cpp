/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:37:17 PM 2024 Paradis
** Last update Tue Jul 29 7:36:22 PM 2024 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../include/SickKoala.hpp"
#include "../../include/KoalaNurse.hpp"

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

Test(KoalaNurse, Test_KoalaNurse_getId)
{
    {
        int          id = 0;
        KoalaNurse   nurse(id);

        cr_assert(nurse.getId() == 0);
    }
}

// Test(KoalaNurse, Test_KoalaNurse_giveDrug, .init = redirect_all_stdout)
// {
//     {
//         int             id = 0;
//         std::string     name = "Koala";
//         SickKoala       patient(name);
//         KoalaNurse      nurse(id);

//         // nurse.giveDrug("Mars", &patient);
//     }
//     cr_assert_stdout_eq_str
//     (
//         "Nurse 0: Finally some rest!\n"
//     );
// }