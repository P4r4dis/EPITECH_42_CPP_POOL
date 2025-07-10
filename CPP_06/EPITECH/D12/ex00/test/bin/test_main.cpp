/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/Test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jun 23 7:04:27 PM 2025 Paradis
** Last update Thu Jun 25 6:06:25 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/IDirectoryLister.hpp"
#include "../../include/DirectoryLister.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

///////////////////////////////////////////////////////////////////////////////
//                            IDirectoryLister class                         //
///////////////////////////////////////////////////////////////////////////////
Test(IDirectoryLister_Constructor, Test_CTOR_is_defined,
.init = redirect_all_stdout)
{
    IDirectoryLister  *dl = new DirectoryLister();

    cr_assert_not_null(&dl);
    if (dl)
        delete dl;
}

Test(IDirectoryLister_Custom_Constructor, Test_Custom_CTOR_is_defined,
.init = redirect_all_stdout)
{
    IDirectoryLister  *dl = new DirectoryLister("./test/", true);

    cr_assert_not_null(&dl);

    if (dl)
        delete dl;
}

Test(IDirectoryLister_get,
Test_get_return_empty_string_if_directory_is_not_open,
.init = redirect_all_stdout)
{
    IDirectoryLister  *dl = new DirectoryLister("./testfd/", true);

    std::string result = dl->get();
    
    cr_assert(result == "");
    cr_assert_stdout_eq_str
    (
        ""
    );

    if (dl)
        delete dl;
}

Test(IDirectoryLister_get,
Test_get_return_names_of_files_or_directories_with_no_hidden_files,
.init = redirect_all_stdout)
{
    IDirectoryLister  *dl = new DirectoryLister("./test/", false);

    for (std::string file = dl->get(); !file.empty(); file = dl->get())
        std::cout << file << std::endl;
    cr_assert_stdout_eq_str
    (
        "file1\n"
        "file2\n"
        "subdirectory\n"
    );

    if (dl)
        delete dl;
}

Test(IDirectoryLister_get,
Test_get_return_names_of_files_or_directories_with_hidden_files,
.init = redirect_all_stdout)
{
    IDirectoryLister  *dl = new DirectoryLister("./test/", true);

    for (std::string file = dl->get(); !file.empty(); file = dl->get())
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

    if (dl)
        delete dl;
}


Test(IDirectoryLister_open,
Test_open_directory_with_invalid_path_return_false,
.init = redirect_all_stdout)
{
    IDirectoryLister  *dl = new DirectoryLister("./test/", true);

    for (std::string file = dl->get(); !file.empty(); file = dl->get())
        std::cout << file << std::endl;

    cr_assert(dl->open("invalid path", true) == false);

    if (dl)
        delete dl;
}

Test(IDirectoryLister_open,
Test_open_directory_with_invalid_path_and_display_msg_error,
.init = redirect_all_stdout)
{
    IDirectoryLister  *dl = new DirectoryLister("./test/", true);

    for (std::string file = dl->get(); !file.empty(); file = dl->get())
        std::cout << file << std::endl;

    cr_assert(dl->open("invalid path", true) == false);
    cr_assert_stdout_eq_str
    (
        ".\n"
        "..\n"
        ".hidden\n"
        "file1\n"
        "file2\n"
        "subdirectory\n"
    );
    cr_assert_stderr_eq_str
    (
        "invalid path: No such file or directory\n"
    );

    if (dl)
        delete dl;
}

Test(IDirectoryLister_open,
Test_open_directory_return_true,
.init = redirect_all_stdout)
{
    IDirectoryLister  *dl = new DirectoryLister("./test/", true);

    for (std::string file = dl->get(); !file.empty(); file = dl->get())
        std::cout << file << std::endl;

    cr_assert(dl->open("invalid path", true) == false);
    cr_assert(dl->open("./test/", false) == true);

    if (dl)
        delete dl;
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
}

Test(DirectoryLister_open,
Test_open_directory_with_invalid_path_and_display_msg_error,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test", true);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;

    cr_assert(dl.open("invalid path", true) == false);
    cr_assert_stdout_eq_str
    (
        ".\n"
        "..\n"
        ".hidden\n"
        "file1\n"
        "file2\n"
        "subdirectory\n"
    );
    cr_assert_stderr_eq_str
    (
        "invalid path: No such file or directory\n"
    );
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

Test(DirectoryLister_getElemOfListByIndex,
Test_return_elements_of_list,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    for (size_t i = 0; !dl.get().empty(); i++)
        std::cout << dl.getElemOfListByIndex(i) << std::endl;

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

Test(DirectoryLister_getSize,
Test_return_the_size_of_List,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    cr_assert(dl.getSize() == 6);
}

Test(DirectoryLister_getIndex,
Test_return_the_index_of_List,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    size_t idx = 0;
    cr_assert(dl.getIndex() == 0);
    for (std::string file = dl.get(); !file.empty(); file = dl.get())
    {
        std::cout << file << std::endl;
        cr_assert(dl.getIndex() == ++idx);
    }
}

Test(DirectoryLister_getCapacity,
Test_return_the_capacity_of_List,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    cr_assert(dl.getCapacity() == dl.getSize());
}

Test(DirectoryLister_clean,
Test_clean_list_and_its_properties,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    size_t idx = 0;
    for (idx = 0; !dl.get().empty(); idx++)
        std::cout << dl.getElemOfListByIndex(idx) << std::endl;

    cr_assert(dl.getSize() == 6);
    cr_assert(dl.getIndex() == idx);
    cr_assert(dl.getCapacity() == dl.getSize());

    dl.clean();
    idx = 0;
    cr_assert(dl.getElemOfListByIndex(idx).empty() == true);
    cr_assert(dl.getSize() == 0);
    cr_assert(dl.getIndex() == idx);
    cr_assert(dl.getCapacity() == dl.getSize());
}

Test(DirectoryLister_resize,
Test_resize_the_capacity_of_the_list,
.init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    cr_assert(dl.getCapacity() == 6);
    dl.resize();
    cr_assert(dl.getCapacity() == 7);
    dl.resize();
    cr_assert(dl.getCapacity() == 8);
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    DirectoryLister dl("./test/", true);

    for (std::string file = dl.get(); !file.empty(); file = dl.get())
        std::cout << file << std::endl;

    dl.open("invalid path", true);
    if (dl.open("./test/", false) == true)
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
        "file1\n"
        "file2\n"
        "subdirectory\n"
    );
    cr_assert_stderr_eq_str
    (
        "invalid path: No such file or directory\n"
    );
}
