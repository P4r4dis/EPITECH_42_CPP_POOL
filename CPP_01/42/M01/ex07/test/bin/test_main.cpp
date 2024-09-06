/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/06 16:33:10 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../../include/Replacer.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Replacer, Test_Replacer_CTOR_isDefined, .init = redirect_all_stdout)
{
    std::string file = "file";
    std::string s1 = "Hello World";
    std::string s2 = "Hello my new world";

    Replacer    replacer(file, s1, s2);
}

Test(Replacer, Test_Replacer_openfile_isDefined, .init = redirect_all_stdout)
{
    std::string file = "file";
    std::string s1 = "Hello World";
    std::string s2 = "Hello my new world";

    Replacer    replacer(file, s1, s2);

    replacer.openFile(file);
}

Test(Replacer, Test_Replacer_openfile_return_ifsteram, .init = redirect_all_stdout)
{
    std::string file = "file";
    std::string s1 = "Hello World";
    std::string s2 = "Hello my new world";
    std::ifstream inputStream;

    Replacer    replacer(file, s1, s2);

    inputStream = replacer.openFile(file);
    cr_assert(inputStream.is_open() == false);
}

Test(Replacer, Test_Replacer_openfile_error_output, .init = redirect_all_stdout)
{
    std::string file = "file";
    std::string s1 = "Hello World";
    std::string s2 = "Hello my new world";
    std::ifstream inputStream;

    Replacer    replacer(file, s1, s2);

    inputStream = replacer.openFile(file);
    cr_assert(inputStream.is_open() == false);
    cr_assert_stderr_eq_str
    (
        "Error: Cannot open file <file>\n"
    );
}

Test(Replacer, Test_Replacer_openfile_file_is_open, .init = redirect_all_stdout)
{
    std::string file = "file.txt";
    std::string s1 = "Hello World";
    std::string s2 = "Hello my new world";
    std::ifstream inputStream;

    Replacer    replacer(file, s1, s2);

    inputStream = replacer.openFile("../" + file);
    cr_assert(inputStream.is_open() == true);
}

Test(Replacer, Test_Replacer_readFile_isDefined, .init = redirect_all_stdout)
{
    std::string file = "file.txt";
    std::string s1 = "Lorem ipsum";
    std::string s2 = "Hello my new world";
    std::ifstream inputStream;

    Replacer    replacer(file, s1, s2);

    inputStream = replacer.openFile("../" + file);
    cr_assert(inputStream.is_open() == true);
    replacer.readFile(inputStream);
}

Test(Replacer, Test_Replacer_readFile_with_file_not_open_error_output,
                .init = redirect_all_stdout)
{
    std::string file = "file";
    std::string s1 = "Hello World";
    std::string s2 = "Hello my new world";
    std::ifstream inputStream;

    Replacer    replacer(file, s1, s2);

    inputStream = replacer.openFile(file);
    cr_assert(inputStream.is_open() == false);
    replacer.readFile(inputStream);
    cr_assert_stderr_eq_str
    (
        "Error: Cannot open file <file>\n"
        "Error: Cannot open file <file>\n"
        "Error: Cannot read file <file>\n"
    );
}

Test(Replacer, Test_Replacer_readFile_error_read, .init = redirect_all_stdout)
{
    std::string file = "file.txt";
    std::string s1 = "Hello World";
    std::string s2 = "Hello my new world";
    std::ifstream inputStream;

    Replacer    replacer(file, s1, s2);

    inputStream = replacer.openFile("../" + file);
    cr_assert(inputStream.is_open() == true);
    replacer.readFile(inputStream);
    replacer.readFile(inputStream);
    cr_assert_stderr_eq_str
    (
        "Error: Cannot read file <file.txt>\n"
    );
}

Test(Replacer, Test_Replacer_readFile_file, .init = redirect_all_stdout)
{
    std::string file = "file.txt";
    std::string s1 = "Lorem ipsum";
    std::string s2 = "Hello my new world";
    std::ifstream inputStream;
    std::string contentFile;

    Replacer    replacer(file, s1, s2);

    inputStream = replacer.openFile("../" + file);
    cr_assert(inputStream.is_open() == true);
    contentFile = replacer.readFile(inputStream);
    std::cout << contentFile << std::endl;
    cr_assert_stdout_eq_str(
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
        "Morbi varius, odio vel egestas gravida, Lorem ipsum neque lorem fringilla mi, non aliquam urna eros a tellus.\n"
        "Sed convallis a Lorem ipsum orci sed egestas.\n"
        "Integer Lorem ipsum sagittis lacinia cursus.\n"
        "Lorem ipsum Quisque nec odio et diam rhoncus mollis.\n"
        "Suspendisse arcu nisi, pretium Lorem ipsum sed ex ac, Lorem ipsum bibendum congue metus.\n"
        "Vivamus ut Lorem ipsum arcu sapien.\n"
        "Lorem ipsum Curabitur sit amet neque vitae purus rhoncus tincidunt.\n"
        "Aliquam vel Lorem ipsum  venenatis ante.\n"
        "Lorem ipsum Donec tristique metus in turpis tincidunt rhoncus.\n"
        "Lorem ipsum Praesent in laoreet mi, sit amet efficitur leo.\n"
    );
}