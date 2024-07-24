/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 19 6:34:24 PM 2024 Paradis
** Last update Thu Jul 24 3:47:36 PM 2024 Paradis
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

Test(MyCat, test_MyCat_MyCat_error_file_not_found, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;
        std::string fileName = "fileName";
        
        myCat.myCat(fileName);
    }
    cr_assert_stderr_eq_str
    (
        "my_cat: fileName: No such file or directory\n"
    );
}

// #include <cstdlib>
            // "mkdir tmp\n"
            // "cd tmp\n"
            // "fakeroot mknod fakeDirectory b 7 0\n"
// Test(MyCat, test_MyCat_MyCat_error_permission_denied)//, .init = redirect_all_stdout)
// {
//     {
//         MyCat   myCat;
//         std::string fileName = "testFile";
        
//         std::system(
//             "touch testFile\n"
//             "chmod 000 testFile\n"
//             );
//         myCat.myCat(fileName);
//         std::system("rm -rf testFile");
//     }
    // cr_assert_stderr_eq_str
    // (
    //     "my_cat: fileName: No such file or directory\n"
    // );
// }

// #include <iostream>
// int main(int ac, char **av)
// {
//     MyCat myCat;
//     if (ac < 1)
//         std::cout << "error ac" << std::endl;
//     else
//         myCat.myCat(av[0]);
//     return 0;
// }