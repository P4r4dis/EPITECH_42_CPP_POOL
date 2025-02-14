/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 4:08:44 PM 2025 Paradis
** Last update Sat Feb 14 4:50:16 PM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Squad.hpp"

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

Test(Skat_class, test_com_returns_valid_reference, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
    
    KreogCom &comRef = skat.com();

    cr_assert_eq(&comRef, &skat.com());

    cr_assert_eq(comRef.getX(), 42);
}

Test(Skat_class, test_com_allows_method_calls, .init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        KreogCom &comRef = skat.com();

        comRef.ping();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 101010 currently at 42 42\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat_class, test_com_reference_persistence, .init = redirect_all_stdout) {
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

    KreogCom &comRef1 = skat.com();

    // Create another Skat
    Skat    skat2("Junior2", 15, 323232, 32, 32, Phaser::PLASMA);

    // Ensure comRef1 is still pointing to the correct KreogCom
    cr_assert_eq(comRef1.getX(), 42);
}


Test(KreogCom_class,
Test_addCom_func_which_adds_a_new_node_to_the_linked_list,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
        KreogCom    *k = new KreogCom(56, 25, 65);

        skat.com().addCom(k);
        cr_assert(skat.com().getNext() == k);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_addCom_func_which_adds_a_several_new_nodes_to_the_linked_list,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
        KreogCom    *k = new KreogCom(56, 25, 65);
        KreogCom    *k2 = new KreogCom(73, 34, 51);
        
        skat.com().addCom(k);
        skat.com().addCom(k2);

        cr_assert(skat.com().getNext() == k2);
        cr_assert(skat.com().getNext()->getNext() == k);


    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Squad, Test_CTOR_not_null,
.init = redirect_all_stdout)
{
    Squad   squad;
    
    cr_assert_not_null(&squad);
}

#include <iostream>
Test(Squad, Test_CTOR_Catchs_default_all_parameters,
.init = redirect_all_stdout)
{
    {
        Squad   squad;
        
        int                 posXBegin = squad.getPosXBegin();
        int                 posYBegin = squad.getPosYBegin();
        Phaser::AmmoType    type = squad.getAmmoType();
        int                 size = squad.size();
        Skat                **skat = squad.getPtrSkat();

        cr_assert(posXBegin == 0);
        cr_assert(posYBegin == 0);
        cr_assert(type == Phaser::ROCKET);
        cr_assert(size == 5);
        cr_assert_not_null(skat);
        for (int i = 0; i < squad.size(); ++i)
        {
            cr_assert(skat[i]->getSkatX() == i * 10);
            cr_assert(skat[i]->getSkatY() == i * 15);
            cr_assert_not_null(skat[i]);
        }
        cr_assert_null(skat[size]);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 0 initialized\n"
        "KreogCom 1 initialized\n"
        "KreogCom 2 initialized\n"
        "KreogCom 3 initialized\n"
        "KreogCom 4 initialized\n"
        "KreogCom 0 shutting down\n"
        "KreogCom 1 shutting down\n"
        "KreogCom 2 shutting down\n"
        "KreogCom 3 shutting down\n"
        "KreogCom 4 shutting down\n"
    );
}

Test(Squad, Test_CTOR_Catchs_all_parameters,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        
        int                 posXBegin = squad.getPosXBegin();
        int                 posYBegin = squad.getPosYBegin();
        Phaser::AmmoType    type = squad.getAmmoType();
        int                 size = squad.size();
        Skat                **skat = squad.getPtrSkat();

        cr_assert(posXBegin == 0);
        cr_assert(posYBegin == 0);
        cr_assert(type == Phaser::REGULAR);
        cr_assert(size == 5);
        cr_assert_not_null(skat);
        for (int i = 0; i < squad.size(); ++i)
        {
            cr_assert(skat[i]->getSkatX() == i * 10);
            cr_assert(skat[i]->getSkatY() == i * 15);
            cr_assert_not_null(skat[i]);
        }
        cr_assert_null(skat[size]);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 0 initialized\n"
        "KreogCom 1 initialized\n"
        "KreogCom 2 initialized\n"
        "KreogCom 3 initialized\n"
        "KreogCom 4 initialized\n"
        "KreogCom 0 shutting down\n"
        "KreogCom 1 shutting down\n"
        "KreogCom 2 shutting down\n"
        "KreogCom 3 shutting down\n"
        "KreogCom 4 shutting down\n"
    );
}

Test(Squad, Test_CTOR_prints_to_stdout,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 0 initialized\n"
        "KreogCom 1 initialized\n"
        "KreogCom 2 initialized\n"
        "KreogCom 3 initialized\n"
        "KreogCom 4 initialized\n"
        "KreogCom 0 shutting down\n"
        "KreogCom 1 shutting down\n"
        "KreogCom 2 shutting down\n"
        "KreogCom 3 shutting down\n"
        "KreogCom 4 shutting down\n"
    );
}

Test(Squad, Test_forEach_funct_quit_function_if_beginIdx_smaller_than_zero,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        squad.foreach(-1, &Skat::locate);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 0 initialized\n"
        "KreogCom 1 initialized\n"
        "KreogCom 2 initialized\n"
        "KreogCom 3 initialized\n"
        "KreogCom 4 initialized\n"
        "KreogCom 0 shutting down\n"
        "KreogCom 1 shutting down\n"
        "KreogCom 2 shutting down\n"
        "KreogCom 3 shutting down\n"
        "KreogCom 4 shutting down\n"
    );
}

Test(Squad, Test_forEach_funct_quit_function_if_beginIdx_is_out_of_range,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        squad.foreach(10, &Skat::locate);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 0 initialized\n"
        "KreogCom 1 initialized\n"
        "KreogCom 2 initialized\n"
        "KreogCom 3 initialized\n"
        "KreogCom 4 initialized\n"
        "KreogCom 0 shutting down\n"
        "KreogCom 1 shutting down\n"
        "KreogCom 2 shutting down\n"
        "KreogCom 3 shutting down\n"
        "KreogCom 4 shutting down\n"
    );
}

Test(Squad, Test_forEach_funct_use_other_function_for_each_Skat,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        squad.foreach(0, &Skat::locate);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 0 initialized\n"
        "KreogCom 1 initialized\n"
        "KreogCom 2 initialized\n"
        "KreogCom 3 initialized\n"
        "KreogCom 4 initialized\n"
        "KreogCom 0 currently at 0 0\n"
        "KreogCom 1 currently at 10 15\n"
        "KreogCom 2 currently at 20 30\n"
        "KreogCom 3 currently at 30 45\n"
        "KreogCom 4 currently at 40 60\n"
        "KreogCom 0 shutting down\n"
        "KreogCom 1 shutting down\n"
        "KreogCom 2 shutting down\n"
        "KreogCom 3 shutting down\n"
        "KreogCom 4 shutting down\n"
    );
}

Test(Squad, Test_fire_funct_prints_to_stdout,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        squad.fire();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 0 initialized\n"
        "KreogCom 1 initialized\n"
        "KreogCom 2 initialized\n"
        "KreogCom 3 initialized\n"
        "KreogCom 4 initialized\n"
        "Bang\n"
        "Bang\n"
        "Bang\n"
        "Bang\n"
        "Bang\n"
        "KreogCom 0 shutting down\n"
        "KreogCom 1 shutting down\n"
        "KreogCom 2 shutting down\n"
        "KreogCom 3 shutting down\n"
        "KreogCom 4 shutting down\n"
    );
}

Test(Squad, Test_localisation_funct_prints_position_to_stdout,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        squad.localisation();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 0 initialized\n"
        "KreogCom 1 initialized\n"
        "KreogCom 2 initialized\n"
        "KreogCom 3 initialized\n"
        "KreogCom 4 initialized\n"
        "KreogCom 0 currently at 0 0\n"
        "KreogCom 1 currently at 10 15\n"
        "KreogCom 2 currently at 20 30\n"
        "KreogCom 3 currently at 30 45\n"
        "KreogCom 4 currently at 40 60\n"
        "KreogCom 0 shutting down\n"
        "KreogCom 1 shutting down\n"
        "KreogCom 2 shutting down\n"
        "KreogCom 3 shutting down\n"
        "KreogCom 4 shutting down\n"
    );
}