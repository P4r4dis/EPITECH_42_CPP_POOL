/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex02/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 26 8:02:10 PM 2024 Paradis
** Last update Tue Jul 29 4:26:17 PM 2024 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../include/SickKoala.hpp"

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