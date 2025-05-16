/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex01/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 7 5:29:47 PM 2025 Paradis
** Last update Fri May 15 8:01:08 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/Peasant.hpp"
#include "../../include/Knight.hpp"
#include "../../include/Enchanter.hpp"
#include "../../include/Priest.hpp"
#include "../../include/Paladin.hpp"
#include "../../include/ICharacter.hpp"
#include "../../include/HealthPotion.hpp"
#include "../../include/IPotion.hpp"

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
//                            Enchanter class                                   //
///////////////////////////////////////////////////////////////////////////////
Test(Enchanter, TEST_Enchanter_default_CTOR, .init = redirect_all_stdout)
{
    {
        Enchanter    enchanter;

        cr_assert_not_null(&enchanter);
    }
}

Test(Enchanter, TEST_Enchanter_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter    enchanter;
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown closes his spellbook.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Enchanter    enchanter("Merlin", 50);

        cr_assert_not_null(&enchanter);
    }
}

Test(Enchanter, TEST_Enchanter_Custom_CTOR_with_power_under_Zero, .init = redirect_all_stdout)
{
    {
        Enchanter    enchanter("Merlin", -50);

        cr_assert(enchanter.getPower() == 0);
    }
}

Test(Enchanter, TEST_Enchanter_Custom_CTOR_with_power_above_100, .init = redirect_all_stdout)
{
    {
        Enchanter    enchanter("Merlin", 500);

        cr_assert(enchanter.getPower() == 100);
    }
}

Test(Enchanter, TEST_Enchanter_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter    enchanter("Merlin", 50);
    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_Custom_CTOR_with_empty_name_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter    enchanter("", 50);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown closes his spellbook.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_Custom_CTOR_with_zero_power_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter    enchanter("Merlin", 0);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}


Test(Enchanter, TEST_Enchanter_Copy_CTOR, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);
        Enchanter     copyEnchanter(enchanter);

        cr_assert_not_null(&enchanter);
        cr_assert_not_null(&copyEnchanter);

    }
}

Test(Enchanter, TEST_Enchanter_Copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);
        Enchanter     copyEnchanter(enchanter);
    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getName() == "Merlin");
        enchanter.setName("Pepe");
        cr_assert(enchanter.getName() == "Pepe");

        cr_assert(enchanter.getPower() == 50);
        enchanter.setPower(-100);
        cr_assert(enchanter.getPower() == 0);
        enchanter.setPower(200);
        cr_assert(enchanter.getPower() == 100);
        enchanter.setPower(50);
        cr_assert(enchanter.getPower() == 50);

        cr_assert(enchanter.getHp() == 100);
        enchanter.setHp(-100);
        cr_assert(enchanter.getHp() == 0);
        enchanter.setHp(200);
        cr_assert(enchanter.getHp() == 100);
        enchanter.setHp(50);
        cr_assert(enchanter.getHp() == 50);
    }
}

Test(Enchanter, TEST_Enchanter_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);
        Enchanter     enchanter2("Jose Bove", 70);

        enchanter2 = enchanter;

        cr_assert(enchanter.getName() == enchanter2.getName());
        cr_assert(enchanter.getPower() == enchanter2.getPower());
        cr_assert(enchanter.getHp() == enchanter2.getHp());
    }
}

Test(Enchanter, TEST_Enchanter_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        enchanter = enchanter;

        cr_assert(enchanter.getName() == enchanter.getName());
        cr_assert(enchanter.getPower() == enchanter.getPower());
        cr_assert(enchanter.getHp() == enchanter.getHp());
    }
}

Test(Enchanter, TEST_Enchanter_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);
        Enchanter     enchanter2("Jose Bove", 70);

        enchanter2 = enchanter;
        enchanter.setName("Pepe Mujica");

        cr_assert(enchanter.getName() != enchanter2.getName());
        cr_assert(enchanter.getPower() == enchanter2.getPower());
        cr_assert(enchanter.getHp() == enchanter2.getHp());
    }
}

Test(Enchanter, TEST_Enchanter_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);
        Enchanter     enchanter2("Jose Bove", 70);

        Enchanter    &return_value = (enchanter2 = enchanter);

        cr_assert_eq(&return_value, &enchanter2);
    }
}


Test(Enchanter, TEST_Enchantert_attack_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getHp() == 100);
        enchanter.setHp(0);
        cr_assert(enchanter.getHp() == 0);

        cr_assert(enchanter.getPower() == 50);
        cr_assert(enchanter.attack() == 0);
        cr_assert(enchanter.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin is out of combat.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_attack_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 10);

        enchanter.setPower(0);
        cr_assert(enchanter.getPower() == 0);
        cr_assert(enchanter.attack() == 0);
        cr_assert(enchanter.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin is out of power.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_attack_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getPower() == 50);
        cr_assert(enchanter.attack() == 0);
        cr_assert(enchanter.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin doesn't know how to fight.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_special_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getHp() == 100);
        enchanter.setHp(0);
        cr_assert(enchanter.getHp() == 0);

        cr_assert(enchanter.getPower() == 50);
        cr_assert(enchanter.special() == 0);
        cr_assert(enchanter.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin is out of combat.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_special_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 1);


        cr_assert(enchanter.getPower() == 1);
        enchanter.setPower(0);
        cr_assert(enchanter.special() == 0);
        cr_assert(enchanter.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin is out of power.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_special_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getPower() == 50);
        cr_assert(enchanter.special() == 99);
        cr_assert(enchanter.getPower() == 0);

    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin casts a fireball.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_rest_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getHp() == 100);
        enchanter.setHp(0);
        cr_assert(enchanter.getHp() == 0);

        cr_assert(enchanter.getPower() == 50);
        enchanter.rest();
        cr_assert(enchanter.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin is out of combat.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_rest_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 1);


        cr_assert(enchanter.getPower() == 1);
        enchanter.setPower(0);
        enchanter.rest();
        cr_assert(enchanter.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin is out of power.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_rest_many_times, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getPower() == 50);
        enchanter.rest();
        cr_assert(enchanter.getPower() == 100);
        enchanter.rest();
        cr_assert(enchanter.getPower() == 100);
        enchanter.rest();
        cr_assert(enchanter.getPower() == 100);

    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin meditates.\n"
        "Merlin meditates.\n"
        "Merlin meditates.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_rest_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getPower() == 50);
        enchanter.rest();
        cr_assert(enchanter.getPower() == 100);

    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin meditates.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_damage_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getHp() == 100);
        enchanter.setHp(0);
        cr_assert(enchanter.getHp() == 0);

        enchanter.damage(10);

    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin is out of combat.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_damage_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 1);


        cr_assert(enchanter.getPower() == 1);
        enchanter.setPower(0);
        cr_assert(enchanter.getPower() == 0);

        enchanter.damage(10);
    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin is out of power.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(Enchanter, TEST_Enchanter_damage_stdout, .init = redirect_all_stdout)
{
    {
        Enchanter     enchanter("Merlin", 50);

        cr_assert(enchanter.getHp() == 100);
        enchanter.damage(10);
        cr_assert(enchanter.getHp() == 90);
    }
    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin takes 10 damage.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Priest class                                   //
///////////////////////////////////////////////////////////////////////////////
Test(Priest, TEST_Priest_default_CTOR, .init = redirect_all_stdout)
{
    {
        Priest    priest;

        cr_assert_not_null(&priest);
    }
}

Test(Priest, TEST_Priest_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Priest    priest;
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A priest with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown finds peace.\n"
        "Unknown closes his spellbook.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Priest    priest("Trichelieu", 50);

        cr_assert_not_null(&priest);
    }
}

Test(Priest, TEST_Priest_Custom_CTOR_with_power_under_Zero, .init = redirect_all_stdout)
{
    {
        Priest    priest("Trichelieu", -50);

        cr_assert(priest.getPower() == 0);
    }
}

Test(Priest, TEST_Priest_Custom_CTOR_with_power_above_100, .init = redirect_all_stdout)
{
    {
        Priest    priest("Trichelieu", 500);

        cr_assert(priest.getPower() == 100);
    }
}

Test(Priest, TEST_Priest_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Priest    priest("Trichelieu", 50);
    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_Custom_CTOR_with_empty_name_stdout, .init = redirect_all_stdout)
{
    {
        Priest    priest("", 50);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A priest with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown finds peace.\n"
        "Unknown closes his spellbook.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_Custom_CTOR_with_zero_power_stdout, .init = redirect_all_stdout)
{
    {
        Priest    priest("Trichelieu", 0);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A priest with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}


Test(Priest, TEST_Priest_Copy_CTOR, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);
        Priest     copyPriest(priest);

        cr_assert_not_null(&priest);
        cr_assert_not_null(&copyPriest);

    }
}

Test(Priest, TEST_Priest_Copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);
        Priest     copyPriest(priest);
    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getName() == "Trichelieu");
        priest.setName("Pepe");
        cr_assert(priest.getName() == "Pepe");

        cr_assert(priest.getPower() == 50);
        priest.setPower(-100);
        cr_assert(priest.getPower() == 0);
        priest.setPower(200);
        cr_assert(priest.getPower() == 100);
        priest.setPower(50);
        cr_assert(priest.getPower() == 50);

        cr_assert(priest.getHp() == 100);
        priest.setHp(-100);
        cr_assert(priest.getHp() == 0);
        priest.setHp(200);
        cr_assert(priest.getHp() == 100);
        priest.setHp(50);
        cr_assert(priest.getHp() == 50);
    }
}

Test(Priest, TEST_Priest_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);
        Priest     priest2("Jose Bove", 70);

        priest2 = priest;

        cr_assert(priest.getName() == priest2.getName());
        cr_assert(priest.getPower() == priest2.getPower());
        cr_assert(priest.getHp() == priest2.getHp());
    }
}

Test(Priest, TEST_Priest_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        priest = priest;

        cr_assert(priest.getName() == priest.getName());
        cr_assert(priest.getPower() == priest.getPower());
        cr_assert(priest.getHp() == priest.getHp());
    }
}

Test(Priest, TEST_Priest_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);
        Priest     priest2("Jose Bove", 70);

        priest2 = priest;
        priest.setName("Pepe Mujica");

        cr_assert(priest.getName() != priest2.getName());
        cr_assert(priest.getPower() == priest2.getPower());
        cr_assert(priest.getHp() == priest2.getHp());
    }
}

Test(Priest, TEST_Priest_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);
        Priest     priest2("Jose Bove", 70);

        Priest    &return_value = (priest2 = priest);

        cr_assert_eq(&return_value, &priest2);
    }
}


Test(Priest, TEST_Priestt_attack_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getHp() == 100);
        priest.setHp(0);
        cr_assert(priest.getHp() == 0);

        cr_assert(priest.getPower() == 50);
        cr_assert(priest.attack() == 0);
        cr_assert(priest.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu is out of combat.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_attack_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 10);

        priest.setPower(0);
        cr_assert(priest.getPower() == 0);
        cr_assert(priest.attack() == 0);
        cr_assert(priest.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu is out of power.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_attack_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getPower() == 50);
        cr_assert(priest.attack() == 0);
        cr_assert(priest.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu doesn't know how to fight.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}


Test(Priest, TEST_Priest_special_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getHp() == 100);
        priest.setHp(0);
        cr_assert(priest.getHp() == 0);

        cr_assert(priest.getPower() == 50);
        cr_assert(priest.special() == 0);
        cr_assert(priest.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu is out of combat.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_special_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 1);


        cr_assert(priest.getPower() == 1);
        priest.setPower(0);
        cr_assert(priest.special() == 0);
        cr_assert(priest.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu is out of power.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_special_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getPower() == 50);
        cr_assert(priest.special() == 99);
        cr_assert(priest.getPower() == 0);

    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu casts a fireball.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_rest_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getHp() == 100);
        priest.setHp(0);
        cr_assert(priest.getHp() == 0);

        cr_assert(priest.getPower() == 50);
        priest.rest();
        cr_assert(priest.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu is out of combat.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_rest_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 1);


        cr_assert(priest.getPower() == 1);
        priest.setPower(0);
        priest.rest();
        cr_assert(priest.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu is out of power.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_rest_many_times, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getPower() == 50);
        priest.rest();
        cr_assert(priest.getPower() == 100);
        priest.rest();
        cr_assert(priest.getPower() == 100);
        priest.rest();
        cr_assert(priest.getPower() == 100);

    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu prays.\n"
        "Trichelieu prays.\n"
        "Trichelieu prays.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_rest_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getPower() == 50);
        priest.rest();
        cr_assert(priest.getPower() == 100);

    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu prays.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_damage_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getHp() == 100);
        priest.setHp(0);
        cr_assert(priest.getHp() == 0);

        priest.damage(10);

    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu is out of combat.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_damage_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 1);


        cr_assert(priest.getPower() == 1);
        priest.setPower(0);
        cr_assert(priest.getPower() == 0);

        priest.damage(10);
    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu is out of power.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(Priest, TEST_Priest_damage_stdout, .init = redirect_all_stdout)
{
    {
        Priest     priest("Trichelieu", 50);

        cr_assert(priest.getHp() == 100);
        priest.damage(10);
        cr_assert(priest.getHp() == 90);
    }
    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu takes 10 damage.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Paladin class                                  //
///////////////////////////////////////////////////////////////////////////////
Test(Paladin, TEST_Paladin_default_CTOR, .init = redirect_all_stdout)
{
    {
        Paladin    paladin;

        cr_assert_not_null(&paladin);
    }
}

Test(Paladin, TEST_Paladin_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin;
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A knight with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A priest with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A paladin with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown is blessed.\n"
        "Unknown finds peace.\n"
        "Unknown closes his spellbook.\n"
        "Unknown takes off his armor.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);

        cr_assert_not_null(&paladin);
    }
}

Test(Paladin, TEST_Paladin_Custom_CTOR_with_power_under_Zero, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", -50);

        cr_assert(paladin.getPower() == 0);
    }
}

Test(Paladin, TEST_Paladin_Custom_CTOR_with_power_above_100, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 500);

        cr_assert(paladin.getPower() == 100);
    }
}

Test(Paladin, TEST_Paladin_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);
    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_Custom_CTOR_with_empty_name_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("", 50);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A knight with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A priest with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A paladin with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Unknown is blessed.\n"
        "Unknown finds peace.\n"
        "Unknown closes his spellbook.\n"
        "Unknown takes off his armor.\n"
        "Unknown is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_Custom_CTOR_with_zero_power_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 0);
    }
    cr_assert_stdout_eq_str(
        "A peasant with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A knight with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A enchanter with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A priest with no name or power points is like a pony that isn't pink: nonsense.\n"
        "A paladin with no name or power points is like a pony that isn't pink: nonsense.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}


Test(Paladin, TEST_Paladin_Copy_CTOR, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);
        Paladin     copyPaladin(paladin);

        cr_assert_not_null(&paladin);
        cr_assert_not_null(&copyPaladin);

    }
}

Test(Paladin, TEST_Paladin_Copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);
        Paladin     copyPaladin(paladin);
    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);

        cr_assert(paladin.getName() == "Uther");
        paladin.setName("Pepe");
        cr_assert(paladin.getName() == "Pepe");

        cr_assert(paladin.getPower() == 50);
        paladin.setPower(-100);
        cr_assert(paladin.getPower() == 0);
        paladin.setPower(200);
        cr_assert(paladin.getPower() == 100);
        paladin.setPower(50);
        cr_assert(paladin.getPower() == 50);

        cr_assert(paladin.getHp() == 100);
        paladin.setHp(-100);
        cr_assert(paladin.getHp() == 0);
        paladin.setHp(200);
        cr_assert(paladin.getHp() == 100);
        paladin.setHp(50);
        cr_assert(paladin.getHp() == 50);
    }
}

Test(Paladin, TEST_Paladin_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);
        Paladin    paladin2("Uther2", 70);

        paladin2 = paladin;

        cr_assert(paladin.getName() == paladin2.getName());
        cr_assert(paladin.getPower() == paladin2.getPower());
        cr_assert(paladin.getHp() == paladin2.getHp());
    }
}

Test(Paladin, TEST_Paladin_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);

        paladin = paladin;

        cr_assert(paladin.getName() == paladin.getName());
        cr_assert(paladin.getPower() == paladin.getPower());
        cr_assert(paladin.getHp() == paladin.getHp());
    }
}

Test(Paladin, TEST_Paladin_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);
        Paladin    paladin2("Uther2", 70);

        paladin2 = paladin;
        paladin.setName("Pepe Mujica");

        cr_assert(paladin.getName() != paladin2.getName());
        cr_assert(paladin.getPower() == paladin2.getPower());
        cr_assert(paladin.getHp() == paladin2.getHp());
    }
}

Test(Paladin, TEST_Priest_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);
        Paladin    paladin2("Uther2", 70);

        Paladin    &return_value = (paladin2 = paladin);

        cr_assert_eq(&return_value, &paladin2);
    }
}


Test(Paladin, TEST_Paladin_attack_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);

        cr_assert(paladin.getHp() == 100);
        paladin.setHp(0);
        cr_assert(paladin.getHp() == 0);

        cr_assert(paladin.getPower() == 50);
        cr_assert(paladin.attack() == 0);
        cr_assert(paladin.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is out of combat.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_attack_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 10);

        paladin.setPower(0);
        cr_assert(paladin.getPower() == 0);
        cr_assert(paladin.attack() == 0);
        cr_assert(paladin.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is out of power.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_attack_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);

        cr_assert(paladin.getPower() == 50);
        cr_assert(paladin.attack() == 20);
        cr_assert(paladin.getPower() == 40);

    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther strikes with his sword.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}


Test(Paladin, TEST_Paladin_special_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Paladin    paladin("Uther", 50);

        cr_assert(paladin.getHp() == 100);
        paladin.setHp(0);
        cr_assert(paladin.getHp() == 0);

        cr_assert(paladin.getPower() == 50);
        cr_assert(paladin.special() == 0);
        cr_assert(paladin.getPower() == 50);
    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is out of combat.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_special_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 1);


        cr_assert(paladin.getPower() == 1);
        paladin.setPower(0);
        cr_assert(paladin.special() == 0);
        cr_assert(paladin.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is out of power.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_special_stdout, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 50);

        cr_assert(paladin.getPower() == 50);
        cr_assert(paladin.special() == 99);
        cr_assert(paladin.getPower() == 0);

    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther casts a fireball.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_rest_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 50);

        cr_assert(paladin.getHp() == 100);
        paladin.setHp(0);
        cr_assert(paladin.getHp() == 0);

        cr_assert(paladin.getPower() == 50);
        paladin.rest();
        cr_assert(paladin.getPower() == 50);

    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is out of combat.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_rest_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 1);

        cr_assert(paladin.getPower() == 1);
        paladin.setPower(0);
        paladin.rest();
        cr_assert(paladin.getPower() == 0);
    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is out of power.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_rest_many_times, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 50);

        cr_assert(paladin.getPower() == 50);
        paladin.rest();
        cr_assert(paladin.getPower() == 100);
        paladin.rest();
        cr_assert(paladin.getPower() == 100);
        paladin.rest();
        cr_assert(paladin.getPower() == 100);

    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther prays.\n"
        "Uther prays.\n"
        "Uther prays.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_rest_stdout, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 50);

        cr_assert(paladin.getPower() == 50);
        paladin.rest();
        cr_assert(paladin.getPower() == 100);

    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther prays.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_damage_but_is_out_of_health_stdout, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 50);

        cr_assert(paladin.getHp() == 100);
        paladin.setHp(0);
        cr_assert(paladin.getHp() == 0);

        paladin.damage(10);

    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is out of combat.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_damage_but_is_out_of_power_stdout, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 1);

        cr_assert(paladin.getPower() == 1);
        paladin.setPower(0);
        cr_assert(paladin.getPower() == 0);

        paladin.damage(10);
    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther is out of power.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, TEST_Paladin_damage_stdout, .init = redirect_all_stdout)
{
    {
        Paladin     paladin("Uther", 50);

        cr_assert(paladin.getHp() == 100);
        paladin.damage(10);
        cr_assert(paladin.getHp() == 90);
    }
    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther takes 10 damage.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            ICharacter                                     //
///////////////////////////////////////////////////////////////////////////////
Test(ICharacter, Test_ICharacter_for_Peasant_function_stdout, .init = redirect_all_stdout)
{
    
    {       
        ICharacter *peasant = new Peasant("Gildas", 42);
    
        peasant->attack();
        peasant->special();
        peasant->rest();
        peasant->damage(50);

        std::cout   << peasant->getName() << ": "
                    << peasant->getHp() << " health points, "
                    << peasant->getPower() << " power points."
                    << std::endl;

        delete peasant;
    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas tosses a stone.\n"
        "Gildas doesn't know any special move.\n"
        "Gildas takes a nap.\n"
        "Gildas takes 50 damage.\n"
        "Gildas: 50 health points, 62 power points.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(ICharacter, Test_ICharacter_for_Knight_function_stdout, .init = redirect_all_stdout)
{
    
    {       
        ICharacter *knight = new Knight("Arthur", 50);
    
        knight->attack();
        knight->special();
        knight->rest();
        knight->damage(50);

        std::cout   << knight->getName() << ": "
                    << knight->getHp() << " health points, "
                    << knight->getPower() << " power points."
                    << std::endl;

        delete knight;
    }

    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur impales his enemy.\n"
        "Arthur eats.\n"
        "Arthur takes 50 damage.\n"
        "Arthur: 50 health points, 60 power points.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(ICharacter, Test_ICharacter_for_Enchanter_function_stdout, .init = redirect_all_stdout)
{
    
    {       
        ICharacter *enchanter = new Enchanter("Merlin", 99);
    
        enchanter->attack();
        enchanter->special();
        enchanter->rest();
        enchanter->damage(50);

        std::cout   << enchanter->getName() << ": "
                    << enchanter->getHp() << " health points, "
                    << enchanter->getPower() << " power points."
                    << std::endl;

        delete enchanter;
    }

    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin doesn't know how to fight.\n"
        "Merlin casts a fireball.\n"
        "Merlin meditates.\n"
        "Merlin takes 50 damage.\n"
        "Merlin: 50 health points, 100 power points.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
    );
}

Test(ICharacter, Test_ICharacter_for_Priest_function_stdout, .init = redirect_all_stdout)
{
    
    {       
        ICharacter *priest = new Priest("Trichelieu", 99);
    
        priest->attack();
        priest->special();
        priest->rest();
        priest->damage(50);

        std::cout   << priest->getName() << ": "
                    << priest->getHp() << " health points, "
                    << priest->getPower() << " power points."
                    << std::endl;

        delete priest;
    }

    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu doesn't know how to fight.\n"
        "Trichelieu casts a fireball.\n"
        "Trichelieu prays.\n"
        "Trichelieu takes 50 damage.\n"
        "Trichelieu: 50 health points, 100 power points.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
    );
}

Test(ICharacter, Test_ICharacter_for_Paladin_function_stdout, .init = redirect_all_stdout)
{
    
    {       
        ICharacter *paladin = new Paladin("Uther", 99);
    
        paladin->attack();
        paladin->special();
        paladin->rest();
        paladin->damage(50);

        std::cout   << paladin->getName() << ": "
                    << paladin->getHp() << " health points, "
                    << paladin->getPower() << " power points."
                    << std::endl;

        delete paladin;
    }

    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther strikes with his sword.\n"
        "Uther casts a fireball.\n"
        "Uther prays.\n"
        "Uther takes 50 damage.\n"
        "Uther: 50 health points, 100 power points.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            HealthPotion class                             //
///////////////////////////////////////////////////////////////////////////////
Test(HealthPotion, Test_HealPotion_is_defined, .init = redirect_all_stdout)
{
    HealthPotion    healthPotion;

    cr_assert_not_null(&healthPotion);
}

Test(PowerPotion, Test_PowerPotion_is_defined, .init = redirect_all_stdout)
{
    PowerPotion    powerPotion;

    cr_assert_not_null(&powerPotion);
}

Test(PoisonPotion, Test_PoisonPotion_is_defined, .init = redirect_all_stdout)
{
    PoisonPotion    poisonPotion;

    cr_assert_not_null(&poisonPotion);
}

Test(IPotion, Test_Peasant_use_drink_func_with_HealthPotion, .init = redirect_all_stdout)
{
    
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        HealthPotion    health_potion;
    
        cr_assert(peasant->getName() == "Gildas");
        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);
        peasant->setHp(50);
        cr_assert(peasant->getHp() == 50);

        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(health_potion);
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;

        cr_assert(peasant->getName() == "Gildas");
        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);
    
        delete peasant;
    }
}

Test(IPotion, Test_Peasant_use_drink_func_with_HealthPotion_stdout, .init = redirect_all_stdout)
{
    
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        HealthPotion    health_potion;
    
        peasant->setHp(50);

        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(health_potion);
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        delete peasant;
    }
    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas: 50HP, 42 PP.\n"
        "Gildas feels rejuvenated.\n"
        "Gildas: 100HP, 42 PP.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(IPotion, Test_Peasant_use_drink_func_with_PowerPotion_stdout, .init = redirect_all_stdout)
{
    
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PowerPotion     power_potion;
        HealthPotion    health_potion;
    
        peasant->setHp(50);

        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(health_potion);
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;

        peasant->drink(power_potion);

        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
        
        delete peasant;
    }
    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas: 50HP, 42 PP.\n"
        "Gildas feels rejuvenated.\n"
        "Gildas: 100HP, 42 PP.\n"
        "Gildas's power is restored.\n"
        "Gildas: 100HP, 92 PP.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(IPotion, Test_Peasant_use_drink_func_with_PoisonPotion_stdout, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PoisonPotion    poison_potion;
        HealthPotion    health_potion;
        IPotion         &potion = health_potion;
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(poison_potion);
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(potion) ;
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        delete peasant;
    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas: 100HP, 42 PP.\n"
        "Gildas has been poisoned.\n"
        "Gildas: 50HP, 42 PP.\n"
        "Gildas drinks a mysterious potion.\n"
        "Gildas: 100HP, 42 PP.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(IPotion, Test_Peasant_use_drink_func_with_MysteriousPoisonPotion_stdout, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PoisonPotion    poison_potion;
        IPotion         &potion = poison_potion;
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(potion) ;
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        delete peasant;
    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas: 100HP, 42 PP.\n"
        "Gildas drinks a mysterious potion.\n"
        "Gildas: 50HP, 42 PP.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(IPotion, Test_Peasant_use_drink_func_with_MysteriousPowerPotion_stdout, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PowerPotion     power_potion;
        IPotion         &potion = power_potion;
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(potion) ;
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        delete peasant;
    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas: 100HP, 42 PP.\n"
        "Gildas drinks a mysterious potion.\n"
        "Gildas: 100HP, 92 PP.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(IPotion, Test_Peasant_chain_PoisonPotion, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PoisonPotion    poison_potion;
    
        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(poison_potion);

        cr_assert(peasant->getHp() == 50);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(poison_potion);

        cr_assert(peasant->getHp() == 0);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(poison_potion);

        cr_assert(peasant->getHp() == 0);
        cr_assert(peasant->getPower() == 42);

        delete peasant;
    }
}

Test(IPotion, Test_Peasant_chain_PowerPotion, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PowerPotion     power_potion;
    
        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(power_potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 92);

        peasant->drink(power_potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 100);

        peasant->drink(power_potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 100);

        delete peasant;
    }
}

Test(IPotion, Test_Peasant_chain_HealthPotion, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        HealthPotion    health_potion;
    
        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(health_potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(health_potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(health_potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);
        
        delete peasant;
    }
}

Test(IPotion, Test_Peasant_chain_Mysterious_HealthPotion, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        HealthPotion    health_potion;
        IPotion         &potion = health_potion;
    
        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);
        
        delete peasant;
    }
}

Test(IPotion, Test_Peasant_chain_Mysterious_PowerPotion, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PowerPotion     power_potion;
        IPotion         &potion = power_potion;

    
        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 92);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 100);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 100);
        
        delete peasant;
    }
}

Test(IPotion, Test_Peasant_chain_Mysterious_PoisonPotion, .init = redirect_all_stdout)
{
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PoisonPotion    poison_potion;
        IPotion         &potion = poison_potion;

        cr_assert(peasant->getHp() == 100);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 50);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 0);
        cr_assert(peasant->getPower() == 42);

        peasant->drink(potion);

        cr_assert(peasant->getHp() == 0);
        cr_assert(peasant->getPower() == 42);
        
        delete peasant;
    }
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    
    {       
        ICharacter      *peasant = new Peasant("Gildas", 42);
        PoisonPotion    poison_potion;
        HealthPotion    health_potion;
        IPotion         &potion = health_potion;
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(poison_potion);
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        peasant->drink(potion) ;
    
        std::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
        << peasant->getPower() << " PP." << std::endl;
    
        delete peasant;
    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas: 100HP, 42 PP.\n"
        "Gildas has been poisoned.\n"
        "Gildas: 50HP, 42 PP.\n"
        "Gildas drinks a mysterious potion.\n"
        "Gildas: 100HP, 42 PP.\n"
        "Gildas is back to his crops.\n"
    );
}