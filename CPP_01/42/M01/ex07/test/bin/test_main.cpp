/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/05 20:15:44 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <string>

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