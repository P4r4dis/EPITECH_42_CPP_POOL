/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex08/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 5 3:53:37 PM 2025 Paradis
** Last update Thu Feb 5 4:13:08 PM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/KreogCom.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


Test(KreogCom_class, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    KreogCom    k(42, 42, 101010);

    cr_assert_not_null(&k);
}

//////////////////////////////////////////////////////////////
    // cr_assert_stdout_eq_str((
    //     "Soldier " + skat.name() + " reporting " 
    //     + std::to_string(skat.stimPaks()) 
    //     + " stimpaks remaining sir!\n").c_str()
    // );
///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    {
        KreogCom k(42, 42, 101010);

        // k.addCom(56, 25, 65);
        // k.addCom(73, 34, 51);

        // k.locateSquad();

        // k.removeCom();
        // k.removeCom();
    }
    cr_assert_stdout_eq_str
    (
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
