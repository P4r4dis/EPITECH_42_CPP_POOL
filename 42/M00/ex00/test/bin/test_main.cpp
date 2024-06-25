#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../include/Megaphone.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

#include <iostream>
Test(Megaphone, test_Megaphone_without_argv, .init = redirect_all_stdout)
{
    {
        char* av[] = { nullptr };
        Megaphone(0, av);
    }
    cr_assert_stdout_eq_str
    (
        "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"
    );
}

Test(Megaphone, test_Megaphone_one_argv, .init = redirect_all_stdout)
{
    {
        char test[] = {"shhhhh... I think the students are asleep..."};
        char * str = test;
        char* av[] = { nullptr, str};
        Megaphone obj(2, av);
    }
    
    cr_assert_stdout_eq_str
    (
        "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...\n"
    );
}

Test(Megaphone, test_Megaphone_multiple_argv, .init = redirect_all_stdout)
{
    {
        char test0[] = "Damnit";
        char test1[] = " ! ";
        char test2[] = "Sorry students, I thought this thing was off.";
        char* av[] = {nullptr, test0, test1, test2};
        Megaphone obj(4, av);
    }
    
    cr_assert_stdout_eq_str
    (
        "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\n"
    );
}
