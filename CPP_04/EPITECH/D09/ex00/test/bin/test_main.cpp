/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 6 5:26:56 PM 2025 Paradis
** Last update Thu May 7 5:13:23 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Peasant.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Peasant, TEST_Peasant_default_CTOR, .init = redirect_all_stdout)
{
    {
        Peasant    peasant;

        cr_assert_not_null(&peasant);
    }
}

Test(Peasant, TEST_Peasant_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Peasant    peasant;
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Peasant    peasant("Jose Bove", 50);

        cr_assert_not_null(&peasant);
    }
}

Test(Peasant, TEST_Peasant_Custom_CTOR_with_power_under_Zero, .init = redirect_all_stdout)
{
    {
        Peasant    peasant("Jose Bove", -50);

        cr_assert(peasant.getPower() == 0);
    }
}

Test(Peasant, TEST_Peasant_Custom_CTOR_with_power_above_100, .init = redirect_all_stdout)
{
    {
        Peasant    peasant("Jose Bove", 500);

        cr_assert(peasant.getPower() == 100);
    }
}

Test(Peasant, TEST_Peasant_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Peasant    peasant("Jose Bove", 50);
    }
    cr_assert_stdout_eq_str(
        "Jose Bove goes for an adventure.\n"
        "Jose Bove is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_Custom_CTOR_with_empty_name_stdout, .init = redirect_all_stdout)
{
    {
        Peasant    peasant("", 50);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_Custom_CTOR_with_zero_power_stdout, .init = redirect_all_stdout)
{
    {
        Peasant    peasant("Jose Bove", 0);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Jose Bove is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_Copy_CTOR, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Jose Bove", 50);
        Peasant     copyPeasant(peasant);

        cr_assert_not_null(&peasant);
        cr_assert_not_null(&copyPeasant);

    }
}

Test(Peasant, TEST_Peasant_Copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Jose Bove", 50);
        Peasant     copyPeasant(peasant);
    }
    cr_assert_stdout_eq_str(
        "Jose Bove goes for an adventure.\n"
        "Jose Bove goes for an adventure.\n"
        "Jose Bove is back to his crops.\n"
        "Jose Bove is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Jose Bove", 50);

        cr_assert(peasant.getName() == "Jose Bove");
        peasant.setName("Pepe");
        cr_assert(peasant.getName() == "Pepe");

        cr_assert(peasant.getPower() == 50);
        peasant.setPower(-100);
        cr_assert(peasant.getPower() == 0);
        peasant.setPower(200);
        cr_assert(peasant.getPower() == 100);
        peasant.setPower(50);
        cr_assert(peasant.getPower() == 50);

        cr_assert(peasant.getHp() == 100);
        peasant.setHp(-100);
        cr_assert(peasant.getHp() == 0);
        peasant.setHp(200);
        cr_assert(peasant.getHp() == 100);
        peasant.setHp(50);
        cr_assert(peasant.getHp() == 50);
    }
}

Test(Peasant, TEST_Peasant_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);
        Peasant     peasant2("Jose Bove", 70);

        peasant2 = peasant;

        cr_assert(peasant.getName() == peasant2.getName());
        cr_assert(peasant.getPower() == peasant2.getPower());
        cr_assert(peasant.getHp() == peasant2.getHp());
    }
}

Test(Peasant, TEST_Peasant_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        peasant = peasant;

        cr_assert(peasant.getName() == peasant.getName());
        cr_assert(peasant.getPower() == peasant.getPower());
        cr_assert(peasant.getHp() == peasant.getHp());
    }
}

Test(Peasant, TEST_Peasant_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);
        Peasant     peasant2("Jose Bove", 70);

        peasant2 = peasant;
        peasant.setName("Pepe Mujica");

        cr_assert(peasant.getName() != peasant2.getName());
        cr_assert(peasant.getPower() == peasant2.getPower());
        cr_assert(peasant.getHp() == peasant2.getHp());
    }
}

Test(Peasant, TEST_Peasant_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);
        Peasant     peasant2("Jose Bove", 70);

        Peasant    &return_value = (peasant2 = peasant);

        cr_assert_eq(&return_value, &peasant2);
    }
}

Test(Peasant, TEST_Peasant_attack_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getHp() == 100);
        peasant.setHp(0);
        cr_assert(peasant.getHp() == 0);

        cr_assert(peasant.getPower() == 50);
        cr_assert(peasant.attack() == 0);
        cr_assert(peasant.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe is out of combat.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_attack_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 1);


        cr_assert(peasant.getPower() == 1);
        cr_assert(peasant.attack() == 0);
        cr_assert(peasant.getPower() == 1);
    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe is out of power.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_attack_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getPower() == 50);
        cr_assert(peasant.attack() == 5);
        cr_assert(peasant.getPower() == 40);

    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe tosses a stone.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_special_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getHp() == 100);
        peasant.setHp(0);
        cr_assert(peasant.getHp() == 0);

        cr_assert(peasant.getPower() == 50);
        cr_assert(peasant.special() == 0);
        cr_assert(peasant.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe is out of combat.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_special_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 1);


        cr_assert(peasant.getPower() == 1);
        peasant.setPower(0);
        cr_assert(peasant.special() == 0);
        cr_assert(peasant.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe is out of power.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_special_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getPower() == 50);
        cr_assert(peasant.special() == 0);
        cr_assert(peasant.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe doesn't know any special move.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_rest_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getHp() == 100);
        peasant.setHp(0);
        cr_assert(peasant.getHp() == 0);

        cr_assert(peasant.getPower() == 50);
        peasant.rest();
        cr_assert(peasant.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe is out of combat.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_rest_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 1);


        cr_assert(peasant.getPower() == 1);
        peasant.setPower(0);
        peasant.rest();
        cr_assert(peasant.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe is out of power.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_rest_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getPower() == 50);
        peasant.rest();
        cr_assert(peasant.getPower() == 80);

    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe takes a nap.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_damage_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getHp() == 100);
        peasant.setHp(0);
        cr_assert(peasant.getHp() == 0);

        peasant.damage(10);

    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe is out of combat.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_damage_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 1);


        cr_assert(peasant.getPower() == 1);
        peasant.setPower(0);
        cr_assert(peasant.getPower() == 0);

        peasant.damage(10);
    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe is out of power.\n"
        "Pepe is back to his crops.\n"
    );
}

Test(Peasant, TEST_Peasant_damage_stdout, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getHp() == 100);
        peasant.damage(10);
        cr_assert(peasant.getHp() == 90);
    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe takes 10 damage.\n"
        "Pepe is back to his crops.\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    
    {       
        Peasant peasant("Gildas", 42);
        peasant.damage(50);
        peasant.damage(100);
        peasant.damage(200);
        peasant.rest();
    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas takes 50 damage.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n"
    );
}