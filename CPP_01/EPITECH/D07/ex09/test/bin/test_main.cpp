/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex09/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Feb 10 7:32:56 PM 2025 Paradis
** Last update Wed Feb 11 7:54:44 PM 2025 Paradis
*/




#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <iostream>

#include "../../include/Phaser.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Sounds_class, Test_REGULAR_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Regular == "Piouuuuuu");
}

Test(Sounds_class, Test_PLASMA_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Plasma == "Fiouuuuuz");
}

Test(Sounds_class, Test_ROCKET_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Rocket == "Booooooom");
}

Test(Phaser_class, Test_Enum_AmmoType_REGULAR_const_variable,
.init = redirect_all_stdout)
{
    cr_assert(Phaser::AmmoType::REGULAR == 0);
}

Test(Phaser_class, Test_Enum_AmmoType_PLASMA_const_variable,
.init = redirect_all_stdout)
{
    cr_assert(Phaser::AmmoType::PLASMA == 1);
}

Test(Phaser_class, Test_Enum_AmmoType_ROCKET_const_variable,
.init = redirect_all_stdout)
{
    cr_assert(Phaser::AmmoType::ROCKET == 2);
}

Test(Phaser_class, Test_constructor_default_parameter,
.init = redirect_all_stdout)
{
    Phaser p;

    cr_assert(p.getMaxAmmo() == 20);
    cr_assert(p.getNbAmmos() == 20);
    cr_assert(p.getType() == Phaser::AmmoType::REGULAR);
    cr_assert(p.getEmptyMagazine() == 0);
    cr_assert_not_null(p.getMagazine());
}

Test(Phaser_class, Test_if_magazine_is_correctly_filled,
.init = redirect_all_stdout)
{
    Phaser p;

    Phaser::AmmoType *magazine = p.getMagazine();
    for (int i = 0; i < p.getMaxAmmo(); ++i)
        cr_assert(magazine[i] == p.getType());
}

Test(Phaser_class, Test_fire_func_print_to_stdout_REGULAR_sounds_Ammo_loaded,
.init = redirect_all_stdout)
{
    {
        Phaser p(1, Phaser::REGULAR);

        p.fire();
    }
    cr_assert_stdout_eq_str(
        "Piouuuuuu\n"
    );
}

Test(Phaser_class, Test_fire_func_print_to_stdout_PLASMA_sounds_Ammo_loaded,
.init = redirect_all_stdout)
{
    {
        Phaser p(1, Phaser::PLASMA);

        p.fire();
    }
    cr_assert_stdout_eq_str(
        "Fiouuuuuz\n"
    );
}

Test(Phaser_class, Test_fire_func_print_to_stdout_ROCKET_sounds_Ammo_loaded,
.init = redirect_all_stdout)
{
    {
        Phaser p(1, Phaser::ROCKET);

        p.fire();
    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
    );
}

Test(Phaser_class, Test_fire_func_nbAmmos_decrements,
.init = redirect_all_stdout)
{
    {
        Phaser p(1, Phaser::ROCKET);

        cr_assert(p.getNbAmmos() == 1);
        p.fire();
        cr_assert(p.getNbAmmos() == 0);
    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
    );
}

Test(Phaser_class, Test_fire_func_print_to_stdout_if_magazine_is_empty,
.init = redirect_all_stdout)
{
    {
        Phaser p(0, Phaser::PLASMA);

        p.fire();
        cr_assert(p.getNbAmmos() == 0);
    }
    cr_assert_stdout_eq_str(
        "Clip empty, please reload\n"
    );
}

Test(Phaser_class, Test_fire_func_magazine_is_shifted_by_one,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getNbAmmos() == 2);
        p.fire();
        cr_assert(p.getNbAmmos() == 1);
        cr_assert(p.getMagazine()[0] == p.getType());
    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
    );
}

Test(Phaser_class,
Test_ejectClip_ejects_magazine_and_reduces_amount_of_munition_to_0,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getNbAmmos() == 2);
        p.ejectClip();
        cr_assert(p.getNbAmmos() == 0);
        cr_assert_null(p.getMagazine());


    }
}

Test(Phaser_class,
Test_changeType_changes_the_default_type_for_the_Phaser,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getType() == Phaser::ROCKET);
        p.changeType(Phaser::REGULAR);
        cr_assert(p.getType() == Phaser::REGULAR);
    }
}

Test(Phaser_class,
Test_changeType_changes_default_type_to_REGULAR_type_and_print_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getType() == Phaser::ROCKET);
        p.changeType(Phaser::REGULAR);
        cr_assert(p.getType() == Phaser::REGULAR);
    }
    cr_assert_stdout_eq_str(
        "Switching ammo to type: regular\n"
    );
}

Test(Phaser_class,
Test_changeType_changes_default_type_to_PLASMA_type_and_print_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getType() == Phaser::ROCKET);
        p.changeType(Phaser::PLASMA);
        cr_assert(p.getType() == Phaser::PLASMA);
    }
    cr_assert_stdout_eq_str(
        "Switching ammo to type: plasma\n"
    );
}

Test(Phaser_class,
Test_changeType_changes_default_type_to_ROCKET_type_and_print_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::REGULAR);

        cr_assert(p.getType() == Phaser::REGULAR);
        p.changeType(Phaser::ROCKET);
        cr_assert(p.getType() == Phaser::ROCKET);
    }
    cr_assert_stdout_eq_str(
        "Switching ammo to type: rocket\n"
    );
}

Test(Phaser_class,
    Test_changeType_changes_default_type_to_same_type_and_print_msg_to_stdout,
    .init = redirect_all_stdout)
    {
        {
            Phaser p(2, Phaser::ROCKET);
    
            cr_assert(p.getType() == Phaser::ROCKET);
            p.changeType(Phaser::ROCKET);
            cr_assert(p.getType() == Phaser::ROCKET);
        }
        cr_assert_stdout_eq_str(
            "Switching ammo to type: rocket\n"
        );
    }
///////////////////////////////////////////////////////////////////////////////
//                                  Main
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        Phaser p(5, Phaser::ROCKET);

        p.fire();
        // p.reload();

        // std::cout << "Firing all ammunition" << std::endl;
        // while (p.getCurrentAmmos() > 0)
        //     p.fire();
    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
        "Reloading...\n"
        "Firing all ammunitions\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
    );
}