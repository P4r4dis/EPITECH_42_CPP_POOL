/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Feb 27 4:53:52 PM 2025 Paradis
** Last update Sat Feb 28 8:40:49 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <cstddef>
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

Test(Droid_class, TEST_setId,
    .init = redirect_all_stdout)
{
    {
        Droid   d;

        cr_assert(d.getId() == "");

        d.setId("Avenger");

        cr_assert(d.getId() == "Avenger");
    }
}

Test(Droid_class, TEST_setEnergy,
    .init = redirect_all_stdout)
{
    {
        Droid   d;
        
        cr_assert(d.getEnergy() == 50);

        d.setEnergy(60);

        cr_assert(d.getEnergy() == 60);
    }
}

Test(Droid_class, TEST_setEnergy_cant_set_more_than_100,
    .init = redirect_all_stdout)
{
    {
        Droid   d;

        cr_assert(d.getEnergy() == 50);

        d.setEnergy(350);

        cr_assert(d.getEnergy() == 100);
    }
}

Test(Droid_class, TEST_setEnergy_cant_set_less_than_zero,
    .init = redirect_all_stdout)
{
    {
        Droid   d;

        cr_assert(d.getEnergy() == 50);

        d.setEnergy(-100);
        
        cr_assert(d.getEnergy() == 100);
    }
}

Test(Droid_class, TEST_setStatus,
    .init = redirect_all_stdout)
{
    {
        Droid   d;

        cr_assert(d.getStatus()->compare("Standing by") == 0);

        d.setStatus(new std::string("Pending by"));

        cr_assert(d.getStatus()->compare("Pending by") == 0);
    }
}

Test(Droid_class, TEST_operator_stream_insertion_overloaded_print_msg,
    .init = redirect_all_stdout)
{
    {
        Droid   d;

        std::cout << d << std::endl;
    }
    cr_assert_stdout_eq_str(
        "Droid '' Activated\n"
        "Droid '', Standing by, 50\n"
        "Droid '' Destroyed\n"
    );
}

Test(Droid_class,
    TEST_operator_stream_insertion_overloaded_to_realod_droid_energy,
    .init = redirect_all_stdout)
{
    {
        Droid   d;
        size_t  Durasel = 200;
    
        cr_assert(Durasel == 200);
        cr_assert(d.getEnergy() == 50);

        d << Durasel;
        
        cr_assert(Durasel == 150);
        cr_assert(d.getEnergy() == 100);
    }
}

Test(Droid_class,
    TEST_operator_stream_insertion_overloaded_realod_energy_with_chain_call,
.init = redirect_all_stdout)
{
    {
        Droid   d;
        size_t  Durasel = 5;
        size_t  Durasel2 = 1;

        d << Durasel << Durasel2;
        
        cr_assert(Durasel == 0);
        cr_assert(Durasel2 == 0);
        cr_assert(d.getEnergy() == 56);
    }
}

Test(Droid_class, Test_operator_equal_identical_droids, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    cr_assert_eq(d1, d2);
}

Test(Droid_class, Test_operator_equal_same_instance, .init = redirect_all_stdout)
{
    Droid d1("R2D2");

    cr_assert(d1 == d1);
}

Test(Droid_class, Test_operator_equal_different_models, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("C3PO");

    cr_assert_not((d1 == d2));
}

Test(Droid_class, Test_operator_equal_different_energy, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    d2.setEnergy(50);

    cr_assert(d1 == d2);
}

Test(Droid_class, Test_operator_equal_different_status, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    d2.setStatus(new std::string("Attack mode"));

    cr_assert_not(d1 == d2);
}

Test(Droid_class, Test_operator_not_equal_identical_droids, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    cr_assert_not((d1 != d2));
}

Test(Droid_class, Test_operator_not_equal_same_instance, .init = redirect_all_stdout)
{
    Droid d1("R2D2");

    cr_assert_not((d1 != d1));
}

Test(Droid_class, Test_operator_not_equal_different_models, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("C3PO");

    cr_assert(d1 != d2);
}

Test(Droid_class, Test_operator_not_equal_different_energy, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    d2.setEnergy(50);

    cr_assert_not(d1 != d2);
}

Test(Droid_class, Test_operator_not_equal_different_status, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    d2.setStatus(new std::string("Attack mode"));

    cr_assert(d1 != d2);
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////



Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        Droid   d;
        Droid   d1("Avenger");
        size_t  Durasel = 200;
    
        std::cout << d << std::endl;
        std::cout << d1 << std::endl;
    
        d = d1;
        d.setStatus (new std::string("Kill Kill Kill!"));
        d << Durasel;
    
        std::cout << d << "--" << Durasel << std::endl;
    
        Droid d2 = d;
        d.setId("Rex");
        std::cout << (d2 != d) << std::endl;
    }
    cr_assert_stdout_eq_str(
        "Droid '' Activated\n"
        "Droid 'Avenger' Activated\n"
        "Droid '', Standing by, 50\n"
        "Droid 'Avenger', Standing by, 50\n"
        "Droid 'Avenger', Kill Kill Kill!, 100--150\n"
        "Droid 'Avenger' Activated, Memory Dumped\n"
        "1\n"
        "Droid 'Avenger' Destroyed\n"
        "Droid 'Avenger' Destroyed\n"
        "Droid 'Rex' Destroyed\n"
    );
}