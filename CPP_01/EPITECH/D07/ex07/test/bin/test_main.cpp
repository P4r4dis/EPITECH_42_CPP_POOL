/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:26:48 PM 2025 Paradis
** Last update Wed Feb 4 2:06:49 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Parts.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

///////////////////////////////////////////////////////////////////////////////
//                                      Arms                                 //
///////////////////////////////////////////////////////////////////////////////
Test(Parts_Arms_class, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    Arms    arms;
    cr_assert_not_null(&arms);
}

Test(Parts_Arms_class,
Test_isFunctionnal_func_Catch_functionnal_default_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Arms    arms;
    
    cr_assert(arms.isFunctionnal() == true);
}

Test(Parts_Arms_class,
Test_isFunctionnal_func_Catch_functionnal_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Arms    arms("A-01", true);
    
    cr_assert(arms.isFunctionnal() == true);
}

Test(Parts_Arms_class,
Test_isFunctionnal_func_Catch_functionnal_parameter_of_CTOR_return_false,
.init = redirect_all_stdout)
{
    Arms    arms("A-01", false);
    
    cr_assert(arms.isFunctionnal() == false);
}
    // cr_assert_stdout_eq_str((
    //     "Soldier " + skat.name() + " reporting " 
    //     + std::to_string(skat.stimPaks()) 
    //     + " stimpaks remaining sir!\n").c_str()
    // );
///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
Test(main, test_main, .init = redirect_all_stdout)
{
    {
        // KoalaBot kb;
        // std::cout << std::boolalpha << kb.status() << std::endl;
        // kb.informations();
    }
    cr_assert_stdout_eq_str
    (
        "true\n"
        "[KoalaBot] Bob-01\n"
        "     [Parts] Arms A-01 status : OK\n"
        "     [Parts] Legs L-01 status : OK\n"
        "     [Parts] Head H-01 status : OK\n"
    );
}
