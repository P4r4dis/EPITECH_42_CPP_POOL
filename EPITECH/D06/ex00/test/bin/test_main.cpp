/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 19 6:34:24 PM 2024 Paradis
** Last update Sat Jul 19 8:13:21 PM 2024 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../include/MyCat.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(MyCat, test_MyCat_ctor_isDefined, .init = redirect_all_stdout)
{
    {
        MyCat myCat;
    }
    cr_assert_stdout_eq_str
    (
        ""
    );
}

Test(MyCat, test_MyCat_Usage_isDefined, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;

        myCat.usage();
    }
}

Test(MyCat, test_MyCat_Usage_output, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;

        myCat.usage();
    }
    cr_assert_stdout_eq_str
    (
        "my_cat: Usage: ./my_cat file [...]\n"
    );
}