/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:26:48 PM 2025 Paradis
** Last update Tue Feb 3 10:19:07 PM 2025 Paradis
*/

#include <criterion/criterion.h>
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
    Skat    skat;
    cr_assert_not_null(&skat);
}

Test(Skat, Test_CTOR_Catch_name_default_parameter, .init = redirect_all_stdout)
{
    Skat    skat;
    
    const std::string name = skat.name();
    cr_assert(name == "Bob");
}

Test(Skat, Test_CTOR_Catch_stimpaks_default_parameter, .init = redirect_all_stdout)
{
    Skat    skat;
    
    int stimPaks = skat.stimPaks();
    cr_assert(stimPaks == 15);
}

Test(Skat, Test_CTOR_Catch_name_parameter, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);
    
    const std::string name = skat.name();
    cr_assert(name == "Junior");
}

Test(Skat, Test_CTOR_Catch_stimpaks_parameter, .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);
    
    int &stimPaks = skat.stimPaks();
    cr_assert(stimPaks == 5);
}

Test(Skat, Test_stimPaks_function_can_modify__stimPaks_private_variable,
 .init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);
    

    skat.stimPaks();
    cr_assert(skat.stimPaks() == 5);
    skat.stimPaks() = 10;
    cr_assert(skat.stimPaks() == 10);
}

Test(Skat, Test_shareStimPaks_isDefinied,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    int stock = 0;
    int number = 2;
    skat.shareStimPaks(number, stock);
}

Test(Skat, Test_shareStimPaks_func_increments_by_number_the_stock,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    int stock = 0;
    int number = 2;
    skat.shareStimPaks(number, stock);
    cr_assert(stock == 2);
}

Test(Skat, Test_shareStimPaks_func_decrements_by_number_the_personal_stock,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    int stock = 0;
    int number = 2;
    skat.shareStimPaks(number, stock);
    cr_assert(stock == 2);
    cr_assert(skat.stimPaks() == 3);
}

Test(Skat, Test_shareStimPaks_func_do_nothing_if_nb_stimPak_shared_is_too_big,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    int stock = 0;
    int number = 6;
    skat.shareStimPaks(number, stock);
    cr_assert(stock == 0);
    cr_assert(skat.stimPaks() == 5);
    cr_assert_stdout_eq_str(
        "Don't be greedy\n"
    );
}

Test(Skat, Test_shareStimPaks_func_can_share_stimPaks_print_on_stdout,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    int stock = 0;
    int number = 3;
    skat.shareStimPaks(number, stock);
    cr_assert(stock == 3);
    cr_assert(skat.stimPaks() == 2);
    cr_assert_stdout_eq_str(
        "Keep the change.\n"
    );
}

Test(Skat, Test_addStimPaks_isDefinied,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);
    skat.addStimPaks(1);
}

Test(Skat, Test_addStimPaks_adds_stimPaks_to_the_personal_stock,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    cr_assert(skat.stimPaks() == 5);
    skat.addStimPaks(5);
    cr_assert(skat.stimPaks() == 10);
}

Test(Skat, Test_addStimPaks_print_on_stdout_if_nb_stimPaks_EQ_zero,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    skat.addStimPaks(0);
    cr_assert_stdout_eq_str("Hey boya, did you forget something?\n");
}

Test(Skat, Test_addStimPaks_print_on_stdout_if_nb_of_stimPaks_cant_be_negative,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    skat.addStimPaks(-10);
    cr_assert_stdout_eq_str("Hey boya, did you forget something?\n");
}

Test(Skat, Test_useStimPaks_isDefinied,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);
    skat.useStimPaks();
}

Test(Skat, Test_useStimPaks_decrements_stimPaks_personal_stock,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    cr_assert(skat.stimPaks() == 5);
    skat.useStimPaks();
    cr_assert(skat.stimPaks() == 4);
}

Test(Skat, Test_useStimPaks_print_msg_on_stdout_if_unit_can_use_stimPak,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 5);

    cr_assert(skat.stimPaks() == 5);
    skat.useStimPaks();
    cr_assert(skat.stimPaks() == 4);
    cr_assert_stdout_eq_str("Time to kick some ass and chew bubble gum.\n");
}

Test(Skat, Test_useStimPaks_print_msg_on_stdout_if_unit_cant_use_stimPak,
.init = redirect_all_stdout)
{
    Skat    skat("Junior", 0);

    skat.useStimPaks();
    cr_assert_stdout_eq_str("Mediiiiiic\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
Test(main, test_main, .init = redirect_all_stdout)
{
    {
        Skat s( "Junior", 5);
        std::cout << "Soldier " << s.name() << std::endl;
        // s.status();
        // s.useStimPaks(); 
    }
    cr_assert_stdout_eq_str
    (
        "Soldier Junior\n"
        "Soldier Junior reporting 5 stimpaks remaining sir!\n"
        "Time to kick some ass and chew bubble gum.\n"
    );
}
