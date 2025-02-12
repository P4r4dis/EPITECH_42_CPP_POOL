/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 4:08:44 PM 2025 Paradis
** Last update Thu Feb 12 5:03:05 PM 2025 Paradis
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
    Phaser              *ptrPhaser = skat.getPtrPhaser();

    cr_assert(name == "Junior");
    cr_assert(stimPaks == 5);
    cr_assert(serial == 101010);
    cr_assert(x == 42);
    cr_assert(y == 42);
    cr_assert(type == Phaser::REGULAR);
    cr_assert_not_null(&ptrKreogCom);
    cr_assert_not_null(&ptrPhaser);
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
