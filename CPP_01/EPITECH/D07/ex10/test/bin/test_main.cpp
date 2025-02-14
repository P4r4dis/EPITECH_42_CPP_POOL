/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 4:08:44 PM 2025 Paradis
** Last update Sat Feb 14 7:26:30 PM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <iostream>

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

Test(Squad, Test_CTOR_Catchs_default_all_parameters,
.init = redirect_all_stdout)
{
    {
        Squad   squad;
        
        int                 posXBegin = squad.getPosXBegin();
        int                 posYBegin = squad.getPosYBegin();
        Phaser::AmmoType    type = squad.getAmmoType();
        int                 size = squad.size();
        Skat                **skat = squad.skats();

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
        Skat                **skat = squad.skats();

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

Test(Squad, Test_at_funct_return_nullptr_because_idx_is_negatif,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        Skat *ptr = squad.at(-1);

        cr_assert_null(ptr);
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

Test(Squad, Test_at_funct_return_nullptr_because_idx_is__out_of_range,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        Skat *ptr = squad.at(10);

        cr_assert_null(ptr);
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

Test(Squad, Test_at_funct_returns_Skat_at_the_index,
.init = redirect_all_stdout)
{
    {
        Squad   squad(0, 0, Phaser::REGULAR);
        for (int i = 0; i < squad.size(); ++i)
        {
            Skat *ptr = squad.at(i);
            cr_assert_not_null(&ptr[i]);
        }
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

///////////////////////////////////////////////////////////////////////////////
//                            KreogCom CLASS                                 //
///////////////////////////////////////////////////////////////////////////////


Test(KreogCom_class, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    KreogCom    k(42, 42, 101010);

    cr_assert_not_null(&k);
}

Test(KreogCom_class, Test_CTOR_print_msg_when_CTOR_is_created_and_destroyed,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_getCom_func_return_nullptr_because_KreogCom_is_not_linked,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        cr_assert(k.getCom() == nullptr);

    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_getCom_func_return_ptr_to_the_KreogCom_linked_to_the_current_instance,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);

        cr_assert(k.getCom() != nullptr);
        cr_assert(k.getCom()->getX() == 56);

    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_getCom_func_return_ptr_to_the_correct_KreogCom_linked_to_current_instance,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);

        cr_assert(k.getCom() != nullptr);
        cr_assert(k.getCom()->getX() == 73);

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

Test(KreogCom_class,
Test_removeCom_func_delete_the_current_KreogCom_linked,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);

        k.removeCom();
        k.removeCom();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_ping_func_prints_current_KreogCom_informations_to_stdout,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);

        k.ping();
        
        k.removeCom();
        k.removeCom();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 101010 currently at 42 42\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_locateSquad_func_prints_linked_and_current_KreogCom_infos_to_stdout,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);

        k.locateSquad();
        
        k.removeCom();
        k.removeCom();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 51 currently at 73 34\n"
        "KreogCom 65 currently at 56 25\n"
        "KreogCom 101010 currently at 42 42\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                              Phaser class                                 //
///////////////////////////////////////////////////////////////////////////////
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
    cr_assert(p.getCurrentAmmos() == 20);
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
        "Bang\n"
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
        "Fwooosh\n"
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

        cr_assert(p.getCurrentAmmos() == 1);
        p.fire();
        cr_assert(p.getCurrentAmmos() == 0);
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
        cr_assert(p.getCurrentAmmos() == 0);
    }
    cr_assert_stdout_eq_str(
        "Clip empty, please reload\n"
    );
}

Test(Phaser_class, Test_fire_func_magazine_is_shifted_as_LIFO,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getCurrentAmmos() == 2);
        p.fire();
        cr_assert(p.getCurrentAmmos() == 1);
        cr_assert(p.getMagazine()[0] == p.getType());
    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
    );
}

Test(Phaser_class,
Test_ejectClip_ejects_magazine_and_reduces_amount_of_ammunition_to_0,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getCurrentAmmos() == 2);
        p.ejectClip();
        cr_assert(p.getCurrentAmmos() == 0);
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

Test(Phaser_class,
Test_reload_func_reload_the_weapon_with_its_default_ammunition_type,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getCurrentAmmos() == 2);
        cr_assert(p.getType() == Phaser::ROCKET);
        for (int i = 0; i < p.getMaxAmmo(); ++i)
            p.fire();
        cr_assert(p.getCurrentAmmos() == 0);
        p.reload();
        cr_assert(p.getCurrentAmmos() == 2);
        cr_assert(p.getType() == Phaser::ROCKET);
    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
        "Booooooom\n"
        "Reloading...\n"
    );
}

Test(Phaser_class,
Test_reload_func_reload_weapon_with_default_ammunition_type_after_ejectClip,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        cr_assert(p.getCurrentAmmos() == 2);
        cr_assert(p.getType() == Phaser::ROCKET);
        p.ejectClip();
        cr_assert(p.getCurrentAmmos() == 0);
        p.reload();
        cr_assert(p.getCurrentAmmos() == 2);
        cr_assert(p.getType() == Phaser::ROCKET);
    }
    cr_assert_stdout_eq_str(
        "Reloading...\n"
    );
}

Test(Phaser_class,
Test_reload_func_reload_weapon_and_prints_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        p.reload();
        cr_assert(p.getCurrentAmmos() == 2);
        cr_assert(p.getType() == Phaser::ROCKET);
    }
    cr_assert_stdout_eq_str(
        "Reloading...\n"
    );
}

Test(Phaser_class,
Test_addAmmo_func_prints_msg_to_stdout_if_clip_is_full,
.init = redirect_all_stdout)
{
    {
        Phaser p(2, Phaser::ROCKET);

        p.addAmmo(Phaser::ROCKET);
    }
    cr_assert_stdout_eq_str(
        "Clip full\n"
    );
}

Test(Phaser_class,
Test_addAmmo_func_adds_ammunition_with_the_same_type,
.init = redirect_all_stdout)
{
    {
        Phaser p(5, Phaser::ROCKET);

        cr_assert(p.getCurrentAmmos() == 5);
        p.fire();
        cr_assert(p.getCurrentAmmos() == 4);
        p.addAmmo(Phaser::ROCKET);
        cr_assert(p.getCurrentAmmos() == 5);

    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
    );
}

Test(Phaser_class,
Test_addAmmo_func_adds_several_ammunitions_with_the_same_type,
.init = redirect_all_stdout)
{
    {
        Phaser p(5, Phaser::ROCKET);

        cr_assert(p.getCurrentAmmos() == 5);
        p.fire();
        p.fire();
        p.fire();
        cr_assert(p.getCurrentAmmos() == 2);
        p.addAmmo(Phaser::ROCKET);
        p.addAmmo(Phaser::ROCKET);
        p.addAmmo(Phaser::ROCKET);
        cr_assert(p.getCurrentAmmos() == 5);

    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
    );
}

Test(Phaser_class,
Test_addAmmo_func_adds_several_ammunitions_with_other_types,
.init = redirect_all_stdout)
{
    {
        Phaser p(5, Phaser::ROCKET);

        cr_assert(p.getCurrentAmmos() == 5);
        p.fire();
        p.fire();
        p.fire();
        cr_assert(p.getCurrentAmmos() == 2);
        p.addAmmo(Phaser::REGULAR);
        p.addAmmo(Phaser::PLASMA);
        p.addAmmo(Phaser::ROCKET);
        cr_assert(p.getCurrentAmmos() == 5);
        std::cout << "Firing all ammunitions" << std::endl;
        while (p.getCurrentAmmos() > 0)
            p.fire();
    }
    cr_assert_stdout_eq_str(
        "Booooooom\n"
        "Booooooom\n"
        "Booooooom\n"
        "Firing all ammunitions\n"
        "Booooooom\n"
        "Fwooosh\n"
        "Bang\n"
        "Booooooom\n"
        "Booooooom\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                                Skat Class                                 //
///////////////////////////////////////////////////////////////////////////////

Test(Skat, Test_CTOR_Catch_name_default_parameter, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
    
    const std::string name = skat.name();
    cr_assert(name == "Junior");
}

Test(Skat, Test_CTOR_Catch_stimpaks_default_parameter, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
    
    int stimPaks = skat.stimPaks();
    cr_assert(stimPaks == 5);
}

Test(Skat, Test_CTOR_Catch_name_parameter, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
    
    const std::string name = skat.name();
    cr_assert(name == "Junior");
}

Test(Skat, Test_CTOR_Catch_stimpaks_parameter, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
    
    int &stimPaks = skat.stimPaks();
    cr_assert(stimPaks == 5);
}

Test(Skat, Test_shareStimPaks_isDefinied,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

    int stock = 0;
    int number = 2;
    skat.shareStimPaks(number, stock);
}

Test(Skat, Test_shareStimPaks_func_increments_by_number_the_stock,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

    int stock = 0;
    int number = 2;
    skat.shareStimPaks(number, stock);
    cr_assert(stock == 2);
}

Test(Skat, Test_shareStimPaks_func_decrements_by_number_the_personal_stock,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

    int stock = 0;
    int number = 2;
    skat.shareStimPaks(number, stock);
    cr_assert(stock == 2);
    cr_assert(skat.stimPaks() == 3);
}

Test(Skat, Test_shareStimPaks_func_do_nothing_if_nb_stimPak_shared_is_too_big,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        int stock = 0;
        int number = 6;
        cr_assert(number >= skat.stimPaks());
        skat.shareStimPaks(number, stock);
        cr_assert(stock == 0);
        cr_assert(skat.stimPaks() == 5);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Don't be greedy\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat, Test_shareStimPaks_func_can_share_stimPaks_print_on_stdout,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        int stock = 0;
        int number = 3;
        skat.shareStimPaks(number, stock);
        cr_assert(stock == 3);
        cr_assert(skat.stimPaks() == 2);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Keep the change.\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat, Test_addStimPaks_isDefinied,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
    skat.addStimPaks(1);
}

Test(Skat, Test_addStimPaks_adds_stimPaks_to_the_personal_stock,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

    cr_assert(skat.stimPaks() == 5);
    skat.addStimPaks(5);
    cr_assert(skat.stimPaks() == 10);
}

Test(Skat, Test_addStimPaks_print_on_stdout_if_nb_stimPaks_EQ_zero,
.init = redirect_all_stdout)
{
    {    
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        skat.addStimPaks(0);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Hey boya, did you forget something?\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat, Test_addStimPaks_print_on_stdout_if_nb_of_stimPaks_cant_be_negative,
.init = redirect_all_stdout)
{
    {
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        skat.addStimPaks(-10);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Hey boya, did you forget something?\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat, Test_useStimPaks_isDefinied,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
    skat.useStimPaks();
}

Test(Skat, Test_useStimPaks_decrements_stimPaks_personal_stock,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

    cr_assert(skat.stimPaks() == 5);
    skat.useStimPaks();
    cr_assert(skat.stimPaks() == 4);
}

Test(Skat, Test_useStimPaks_print_msg_on_stdout_if_unit_can_use_stimPak,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);

        cr_assert(skat.stimPaks() == 5);
        skat.useStimPaks();
        cr_assert(skat.stimPaks() == 4);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Time to kick some ass and chew bubble gum.\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat, Test_useStimPaks_print_msg_on_stdout_if_unit_cant_use_stimPak,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 0, 101010, 42, 42, Phaser::ROCKET);

        skat.useStimPaks();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Mediiiiiic\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(Skat, Test_status_func_isDefinied,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
    skat.status();
}

Test(Skat, Test_status_func_print_msg_on_stdout,
.init = redirect_all_stdout)
{
    {
        Skat    skat("Junior", 5, 101010, 42, 42, Phaser::ROCKET);
        skat.status();
    }
   
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "Soldier Junior reporting 5 stimpaks remaining sir!\n"
        "KreogCom 101010 shutting down\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////
Test(Squad, Test_main_function_imp,
.init = redirect_all_stdout)
{
    {
        Squad   s(0, 0, Phaser::REGULAR);

        s.fire();

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