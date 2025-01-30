/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:26:48 PM 2025 Paradis
** Last update Fri Jan 30 6:12:37 PM 2025 Paradis
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

Test(test, tesetname, .init = redirect_all_stdout)
{
    cr_assert(1 == 1);
}

///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////

Test(main, test_main, .init = redirect_all_stdout)
{
    // {

    // }
    // cr_assert_stdout_eq_str
    // (
    //     "Soldier Junior\n"
    //     "Soldier Junior reporting 5 stimpaks remaining sir!\n"
    //     "Time to kick some ass and chew bubble gum.\n"
    // );
}
