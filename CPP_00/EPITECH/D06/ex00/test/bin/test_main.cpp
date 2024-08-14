/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 19 6:34:24 PM 2024 Paradis
** Last update Fri Jul 25 5:49:47 PM 2024 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>
#include <cstdlib>

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

Test(MyCat, test_MyCat_MyCat_error_permission_denied, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;
        std::string fileName = "testFile";
        
        std::system(
            "touch testFile\n"
            "chmod 000 testFile\n"
            );
        myCat.myCat(fileName);
        std::system("rm -rf testFile");
    }
    cr_assert_stderr_eq_str
    (
        "my_cat: testFile: Permission denied\n"
    );
}

Test(MyCat, test_MyCat_isDirectory_isDefined, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;
        std::string fileName = "testDirectory";
        
        std::system(
            "mkdir testDirectory\n"
            );
        myCat.isDirectory(fileName);
        std::system("rm -rf testDirectory");
    }
}

Test(MyCat, test_MyCat_isDirectory_return_true, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;
        std::string fileName = "testDirectory";
        
        std::system(
            "mkdir testDirectory\n"
            );
        cr_assert(myCat.isDirectory(fileName) == true);
        std::system("rm -rf testDirectory");
    }
    cr_assert_stderr_eq_str
    (
        "my_cat: testDirectory: Is a directory\n"
    );
}

Test(MyCat, test_MyCat_isDirectory_return_false)
{
    {
        MyCat   myCat;
        std::string fileName = "testFile";
        
        std::system(
            "touch testFile\n"
            );
        cr_assert(myCat.isDirectory(fileName) == false);
        std::system("rm -rf testFile");
    }
}

Test(MyCat, test_MyCat_MyCat_error_is_a_directory, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;
        std::string fileName = "testDirectory";
        
        std::system(
            "mkdir testDirectory\n"
            );
        myCat.myCat(fileName);
        std::system("rm -rf testDirectory");
    }
    cr_assert_stderr_eq_str
    (
        "my_cat: testDirectory: Is a directory\n"
    );
}

Test(MyCat, test_MyCat_MyCat_error_file_name_too_long, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;
        std::string longFilename(300, 'a');
        myCat.myCat(longFilename);
    }
    cr_assert_stderr_eq_str
    (
        "my_cat: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa: File name too long\n"
    );
}

Test(MyCat, test_MyCat_MyCat_one_file, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;
        std::string fileName = "D06_ex00_fileTest1.txt";

        myCat.myCat(fileName.c_str());
    }
    cr_assert_stdout_eq_str
    (
        "I have something in this test"
    );
}

Test(MyCat, test_MyCat_MyCat_several_files, .init = redirect_all_stdout)
{
    {
        MyCat   myCat;
        std::string fileName[] = {"D06_ex00_fileTest1.txt", "D06_ex00_fileTest2.txt"};

        size_t size = sizeof(fileName) / sizeof(fileName[0]);
        for (size_t i  = 0; i < size; ++i)
            myCat.myCat(fileName[i]);
    }
    cr_assert_stdout_eq_str
    (
        "I have something in this testIn this in file i have the other"
    );
}
