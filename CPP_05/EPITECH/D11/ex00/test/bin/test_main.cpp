/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/Test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jun 23 7:04:27 PM 2025 Paradis
** Last update Wed Jun 24 9:48:03 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

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

Test(DirectoryLister_Custom_Constructor, Test_Custom_CTOR_is_defined,
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

// Test(DirectoryLister_getDirectory, Test_getDirectory_return_dir,
// .init = redirect_all_stdout)
// {
//     DirectoryLister dl;
//     DirectoryLister dl2("./test/", true);

//     cr_assert_null(dl.getDirectory());
//     cr_assert_not_null(dl2.getDirectory());
// }

Test(DirectoryLister_get,
Test_get_return_empty_string_if_directory_is_not_open,
.init = redirect_all_stdout)
{
    DirectoryLister dl2("./testefd/", true);

    std::string result = dl2.get();
    
    cr_assert(result == "");
    cr_assert_stdout_eq_str
    (
        ""
    );
}

Test(DirectoryLister_get,
Test_get_return_names_of_files_or_directories_with_no_hidden_files,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", false);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;
    cr_assert_stdout_eq_str
    (
        "file1\n"
        "file2\n"
        "subdirectory\n"
    );
}

Test(DirectoryLister_get,
Test_get_return_names_of_files_or_directories_with_hidden_files,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;
    cr_assert_stdout_eq_str
    (
        ".\n"
        "..\n"
        ".hidden\n"
        "file1\n"
        "file2\n"
        "subdirectory\n"
    );
}


Test(DirectoryLister_open,
Test_open_directory_with_invalid_path_return_false,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;

    cr_assert(dl.open("invalid path", true) == false);
    // if (dl.open("./test/", false) == true)
    //     for (std::string file = dl.get(); !file.empty(); file = dl.get())
    //         std::cout << file << std::endl;

}

Test(DirectoryLister_open,
Test_open_directory_with_invalid_path_and_display_msg_error,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;

    cr_assert(dl.open("invalid path", true) == false);
    cr_assert_stdout_eq_str("");
    // if (dl.open("./test/", false) == true)
    //     for (std::string file = dl.get(); !file.empty(); file = dl.get())
    //         std::cout << file << std::endl;

}

Test(DirectoryLister_open,
Test_open_directory_return_true,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;

    cr_assert(dl.open("invalid path", true) == false);
    cr_assert(dl.open("./test/", false) == true);
}

// TODO:
//  -   push + commit
//  -   getters
//  -   unit test for getters
//  -   unit test clean
//  -   unit test resize
//  -   main
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    // DirectoryLister dl("./test/", true);

    // for (std::string file = dl.get(); !file.empty(); file = dl.get())
    //     std::cout << file << std::endl;

    // dl.open("invalid path", true);
    // if (dl.open("./test/", false) == true)
    //     for (std::string file = dl.get(); !file.empty(); file = dl.get())
    //         std::cout << file << std::endl;
}
