/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/Test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jun 23 7:04:27 PM 2025 Paradis
** Last update Tue Jun 23 7:04:30 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/DirectoryLister.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
///////////////////////////////////////////////////////////////////////////////
//                            DirectoryLister class                          //
///////////////////////////////////////////////////////////////////////////////
Test(DirectoryLister_Constructor, Test_CTOR_is_defined,
.init = redirect_all_stdout)
{
    DirectoryLister dl;

    cr_assert_not_null(&dl);
}

Test(DirectoryLister_Copy_Constructor, Test_CopyCTOR_is_defined,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    cr_assert_not_null(&dl);
}

Test(DirectoryLister_getPath, Test_getPath_return_path,
.init = redirect_all_stdout)
{
    DirectoryLister dl;
    DirectoryLister dl2("./test/", true);

    cr_assert(dl.getPath() == "");
    cr_assert(dl2.getPath() == "./test/");
}

Test(DirectoryLister_getHidden, Test_getHidden_return_hidden,
.init = redirect_all_stdout)
{
    DirectoryLister dl;
    DirectoryLister dl2("./test/", true);

    cr_assert(dl.getHidden() == false);
    cr_assert(dl2.getHidden() == true);
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
// Test(main, test_main, .init = redirect_all_stdout)
// {
//     cr_assert(1 == 1);
//     DirectoryLister dl("./test/", true);

//     for (std::string file = dl.get(); !file.empty(); file = dl.get())
//         std::cout << file << std::endl;

//     dl.open("invalid path", true);
//     if (dl.open("./test/", false) == true)
//         for (std::string file = dl.get(); !file.empty(); file = dl.get())
//             std::cout << file << std::endl;
// }
