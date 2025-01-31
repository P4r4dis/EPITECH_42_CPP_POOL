/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:26:48 PM 2025 Paradis
** Last update Sat Jan 31 1:04:33 AM 2025 Paradis
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

// TO DO: stimpack function can modify _stimPaks variable;
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
