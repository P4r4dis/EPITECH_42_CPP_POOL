/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Feb 27 4:53:52 PM 2025 Paradis
** Last update Fri Feb 27 6:40:18 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/Droid.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Droid_class, TEST_Droid_default_CTOR_isDefined,
    .init = redirect_all_stdout)
{
    Droid   d;
    cr_assert_not_null(&d);
}

Test(Droid_class, TEST_Droid_default_CTOR_check_parameters,
    .init = redirect_all_stdout)
{
    Droid   d;
    
    cr_assert(d.getId() == "");
    cr_assert(d.getEnergy() == 50);
    cr_assert(d.getAttack() == 25);
    cr_assert(d.getToughness() == 15);
    cr_assert(d.getStatus()->compare("Standing by") == 0);
}

Test(Droid_class, TEST_Droid_default_CTOR_check_stdout,
    .init = redirect_all_stdout)
{
    {
        Droid   d;
    }
    cr_assert_stdout_eq_str(
        "Droid '' Activated\n"
        "Droid '' Destroyed\n"
    );
}

Test(Droid_class, TEST_Droid_custom_CTOR_isDefined, .init = redirect_all_stdout)
{
    Droid   d("Avenger");
    cr_assert_not_null(&d);
}

Test(Droid_class, TEST_Droid_custom_CTOR_check_parameters, .init = redirect_all_stdout)
{
    Droid   d("Avenger");
    
    cr_assert(d.getId() == "Avenger");
    cr_assert(d.getEnergy() == 50);
    cr_assert(d.getAttack() == 25);
    cr_assert(d.getToughness() == 15);
    cr_assert(d.getStatus()->compare("Standing by") == 0);
}

Test(Droid_class, TEST_Droid_custom_CTOR_check_stdout, .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");
    }
    cr_assert_stdout_eq_str(
        "Droid 'Avenger' Activated\n"
        "Droid 'Avenger' Destroyed\n"
    );
}

Test(Droid_class, TEST_Droid_copyCTOR_check_stdout, .init = redirect_all_stdout)
{
    {
        Droid   d1("Avenger");
        Droid   d(d1);

        cr_assert(d.getId() == "Avenger");
        cr_assert(d.getEnergy() == 50);
        cr_assert(d.getAttack() == 25);
        cr_assert(d.getToughness() == 15);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
    }
    cr_assert_stdout_eq_str(
        "Droid 'Avenger' Activated\n"
        "Droid 'Avenger' Activated, Memory Dumped\n"
        "Droid 'Avenger' Destroyed\n"
        "Droid 'Avenger' Destroyed\n"
    );
}

Test(Droid_class, TEST_Droid_assignment_operator_with_two_differents_CTOR,
    .init = redirect_all_stdout)
{
    {
        Droid   d;
        Droid   d1("Avenger");

        cr_assert(d.getId() == "");
        cr_assert(d.getEnergy() == 50);
        cr_assert(d.getAttack() == 25);
        cr_assert(d.getToughness() == 15);
        cr_assert(d.getStatus()->compare("Standing by") == 0);

        d = d1;

        cr_assert(d.getId() == "Avenger");
        cr_assert(d.getEnergy() == 50);
        cr_assert(d.getAttack() == 25);
        cr_assert(d.getToughness() == 15);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
    }
}

Test(Droid_class, TEST_Droid_assignment_operator_with_two_same_CTOR,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");

        cr_assert(d.getId() == "Avenger");
        cr_assert(d.getEnergy() == 50);
        cr_assert(d.getAttack() == 25);
        cr_assert(d.getToughness() == 15);
        cr_assert(d.getStatus()->compare("Standing by") == 0);

        d = d;

        cr_assert(d.getId() == "Avenger");
        cr_assert(d.getEnergy() == 50);
        cr_assert(d.getAttack() == 25);
        cr_assert(d.getToughness() == 15);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
    }
}