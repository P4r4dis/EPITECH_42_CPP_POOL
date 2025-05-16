/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex01/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 7 5:29:47 PM 2025 Paradis
** Last update Thu May 7 8:21:09 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Peasant.hpp"
#include "../../include/Knight.hpp"

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

Test(Peasant, TEST_Peasant_rest_many_times, .init = redirect_all_stdout)
{
    {
        Peasant     peasant("Pepe", 50);

        cr_assert(peasant.getPower() == 50);
        peasant.rest();
        cr_assert(peasant.getPower() == 80);
        peasant.rest();
        cr_assert(peasant.getPower() == 100);
        peasant.rest();
        cr_assert(peasant.getPower() == 100);
    }
    cr_assert_stdout_eq_str(
        "Pepe goes for an adventure.\n"
        "Pepe takes a nap.\n"
        "Pepe takes a nap.\n"
        "Pepe takes a nap.\n"
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
//                            Knight class                                   //
///////////////////////////////////////////////////////////////////////////////
Test(Knight, TEST_Knight_default_CTOR, .init = redirect_all_stdout)
{
    {
        Knight    knight;

        cr_assert_not_null(&knight);
    }
}

Test(Knight, TEST_Knight_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Knight    knight;
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A knight with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown takes off his armor.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Knight    knight("Arthur", 50);

        cr_assert_not_null(&knight);
    }
}

Test(Knight, TEST_Knight_Custom_CTOR_with_power_under_Zero, .init = redirect_all_stdout)
{
    {
        Knight    knight("Arthur", -50);

        cr_assert(knight.getPower() == 0);
    }
}

Test(Knight, TEST_Knight_Custom_CTOR_with_power_above_100, .init = redirect_all_stdout)
{
    {
        Knight    knight("Arthur", 500);

        cr_assert(knight.getPower() == 100);
    }
}

Test(Knight, TEST_Knight_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Knight    knight("Arthur", 50);
    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_Custom_CTOR_with_empty_name_stdout, .init = redirect_all_stdout)
{
    {
        Knight    knight("", 50);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A knight with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown takes off his armor.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_Custom_CTOR_with_zero_power_stdout, .init = redirect_all_stdout)
{
    {
        Knight    knight("Arthur", 0);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A knight with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}


Test(Knight, TEST_Knight_Copy_CTOR, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);
        Knight     copyKnight(knight);

        cr_assert_not_null(&knight);
        cr_assert_not_null(&copyKnight);

    }
}

Test(Knight, TEST_Knight_Copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);
        Knight     copyKnight(knight);
    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getName() == "Arthur");
        knight.setName("Pepe");
        cr_assert(knight.getName() == "Pepe");

        cr_assert(knight.getPower() == 50);
        knight.setPower(-100);
        cr_assert(knight.getPower() == 0);
        knight.setPower(200);
        cr_assert(knight.getPower() == 100);
        knight.setPower(50);
        cr_assert(knight.getPower() == 50);

        cr_assert(knight.getHp() == 100);
        knight.setHp(-100);
        cr_assert(knight.getHp() == 0);
        knight.setHp(200);
        cr_assert(knight.getHp() == 100);
        knight.setHp(50);
        cr_assert(knight.getHp() == 50);
    }
}

Test(Knight, TEST_Knight_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);
        Knight     knight2("Jose Bove", 70);

        knight2 = knight;

        cr_assert(knight.getName() == knight2.getName());
        cr_assert(knight.getPower() == knight2.getPower());
        cr_assert(knight.getHp() == knight2.getHp());
    }
}

Test(Knight, TEST_Knight_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        knight = knight;

        cr_assert(knight.getName() == knight.getName());
        cr_assert(knight.getPower() == knight.getPower());
        cr_assert(knight.getHp() == knight.getHp());
    }
}

Test(Knight, TEST_Knight_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);
        Knight     knight2("Jose Bove", 70);

        knight2 = knight;
        knight.setName("Pepe Mujica");

        cr_assert(knight.getName() != knight2.getName());
        cr_assert(knight.getPower() == knight2.getPower());
        cr_assert(knight.getHp() == knight2.getHp());
    }
}

Test(Knight, TEST_Knight_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);
        Knight     knight2("Jose Bove", 70);

        Knight    &return_value = (knight2 = knight);

        cr_assert_eq(&return_value, &knight2);
    }
}


Test(Knight, TEST_Knightt_attack_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getHp() == 100);
        knight.setHp(0);
        cr_assert(knight.getHp() == 0);

        cr_assert(knight.getPower() == 50);
        cr_assert(knight.attack() == 0);
        cr_assert(knight.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur is out of combat.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_attack_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 1);


        cr_assert(knight.getPower() == 1);
        cr_assert(knight.attack() == 0);
        cr_assert(knight.getPower() == 1);
    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur is out of power.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_attack_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getPower() == 50);
        cr_assert(knight.attack() == 20);
        cr_assert(knight.getPower() == 40);

    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}


Test(Knight, TEST_Knight_special_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getHp() == 100);
        knight.setHp(0);
        cr_assert(knight.getHp() == 0);

        cr_assert(knight.getPower() == 50);
        cr_assert(knight.special() == 0);
        cr_assert(knight.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur is out of combat.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_special_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 1);


        cr_assert(knight.getPower() == 1);
        knight.setPower(0);
        cr_assert(knight.special() == 0);
        cr_assert(knight.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur is out of power.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_special_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getPower() == 50);
        cr_assert(knight.special() == 50);
        cr_assert(knight.getPower() == 20);

    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur impales his enemy.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_rest_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getHp() == 100);
        knight.setHp(0);
        cr_assert(knight.getHp() == 0);

        cr_assert(knight.getPower() == 50);
        knight.rest();
        cr_assert(knight.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur is out of combat.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_rest_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 1);


        cr_assert(knight.getPower() == 1);
        knight.setPower(0);
        knight.rest();
        cr_assert(knight.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur is out of power.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_rest_many_times, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getPower() == 50);
        knight.rest();
        cr_assert(knight.getPower() == 100);
        knight.rest();
        cr_assert(knight.getPower() == 100);
        knight.rest();
        cr_assert(knight.getPower() == 100);

    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur eats.\n"
        "Arthur eats.\n"
        "Arthur eats.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_rest_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getPower() == 50);
        knight.rest();
        cr_assert(knight.getPower() == 100);

    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur eats.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_damage_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getHp() == 100);
        knight.setHp(0);
        cr_assert(knight.getHp() == 0);

        knight.damage(10);

    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur is out of combat.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_damage_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 1);


        cr_assert(knight.getPower() == 1);
        knight.setPower(0);
        cr_assert(knight.getPower() == 0);

        knight.damage(10);
    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur is out of power.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, TEST_Knight_damage_stdout, .init = redirect_all_stdout)
{
    {
        Knight     knight("Arthur", 50);

        cr_assert(knight.getHp() == 100);
        knight.damage(10);
        cr_assert(knight.getHp() == 90);
    }
    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur takes 10 damage.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    
    {       
        Knight knight("Arthur", 20);

        knight.attack();
        knight.special();
        knight.rest();
        knight.special();
        knight.damage(50);
    }

    cr_assert_stdout_eq_str(
    "Arthur goes for an adventure.\n"
    "Arthur vows to protect the kingdom.\n"
    "Arthur strikes with his sword.\n"
    "Arthur is out of power.\n"
    "Arthur eats.\n"
    "Arthur impales his enemy.\n"
    "Arthur takes 50 damage.\n"
    "Arthur takes off his armor.\n"
    "Arthur is back to his crops.\n"
    );
}