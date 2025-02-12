/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 4:08:44 PM 2025 Paradis
** Last update Thu Feb 12 10:05:17 PM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Skat.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


Test(Skat, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::REGULAR);
    cr_assert_not_null(&skat);
}

Test(Skat, Test_CTOR_Catchs_all_parameters, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::REGULAR);
    
    const std::string   name = skat.name();
    int                 stimPaks = skat.stimPaks();
    int                 serial = skat.getSkatSerial();
    int                 x = skat.getSkatX();
    int                 y = skat.getSkatY();
    Phaser::AmmoType    type = skat.getSkatType();
    KreogCom            *ptrKreogCom = skat.getPtrKreogCom();
    Phaser              *ptrSkat = skat.getPtrPhaser();
    int                 maxAmmunition = ptrSkat->getMaxAmmo();
    int                 ammunition = ptrSkat->getCurrentAmmos();

    cr_assert(name == "Junior");
    cr_assert(stimPaks == 5);
    cr_assert(serial == 101010);
    cr_assert(x == 42);
    cr_assert(y == 42);
    cr_assert(type == Phaser::REGULAR);
    cr_assert_not_null(&ptrKreogCom);
    cr_assert_not_null(&ptrSkat);
    cr_assert(maxAmmunition == 20);
    cr_assert(ammunition == 20);
}

Test(Skat, Test_stimPaks_function_can_modify__stimPaks_private_variable,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::REGULAR);
    

    skat.stimPaks();
    cr_assert(skat.stimPaks() == 5);
    skat.stimPaks() = 10;
    cr_assert(skat.stimPaks() == 10);
}


Test(Skat_class, Test_fire_func_print_to_stdout_REGULAR_sounds_Ammo_loaded,
.init = redirect_all_stdout)
    {
        {
            Skat    skat("Junior", 5, 101010, 42, 42, Phaser::REGULAR);
    
            skat.fire();
        }
        cr_assert_stdout_eq_str(
            "KreogCom 101010 initialized\n"
            "Bang\n"
            "KreogCom 101010 shutting down\n"
        );
    }
    
Test(Skat_class, Test_fire_func_print_to_stdout_PLASMA_sounds_Ammo_loaded,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::PLASMA);

        skat.fire();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Fwooosh\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat_class, Test_fire_func_print_to_stdout_ROCKET_sounds_Ammo_loaded,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        skat.fire();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Booooooom\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat_class, Test_fire_func_nbAmmos_decrements,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 20);
        skat.fire();
        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 19);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Booooooom\n"
        "KreogCom 101010 shutting down\n"    );
}

Test(Skat_class, Test_fire_func_print_to_stdout_if_magazine_is_empty,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        for (; skat.getPtrPhaser()->getCurrentAmmos() != 0;)
            skat.fire();
        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 0);
        skat.fire();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Clip empty, please reload\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat_class, Test_fire_func_magazine_is_shifted_as_LIFO,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 20);
        skat.fire();
        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 19);
        cr_assert(skat.getPtrPhaser()->getMagazine()[0] == skat.getSkatType());
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Booooooom\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat,
Test_locate_func_prints_linked_and_current_KreogCom_infos_to_stdout,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        skat.locate();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 101010 currently at 42 42\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat,
Test_reload_func_reload_the_weapon_with_its_default_ammunition_type,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 20);
        cr_assert(skat.getSkatType() == Phaser::ROCKET);
        for (int i = 0; i < skat.getPtrPhaser()->getMaxAmmo(); ++i)
            skat.getPtrPhaser()->fire();
        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 0);
        skat.reload();
        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 20);
        cr_assert(skat.getSkatType() == Phaser::ROCKET);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Reloading...\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat,
Test_reload_func_reload_weapon_with_default_ammunition_type_after_ejectClip,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 20);
        cr_assert(skat.getSkatType() == Phaser::ROCKET);
        skat.getPtrPhaser()->ejectClip();
        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 0);
        skat.reload();
        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 20);
        cr_assert(skat.getSkatType() == Phaser::ROCKET);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Reloading...\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat,
Test_reload_func_reload_weapon_and_prints_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        skat.reload();
        cr_assert(skat.getPtrPhaser()->getCurrentAmmos() == 20);
        cr_assert(skat.getSkatType() == Phaser::ROCKET);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Reloading...\n"
        "KreogCom 101010 shutting down\n"
    );
}
