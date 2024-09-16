/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/11 17:57:04 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
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

Test(Replacer, Test_Replacer_sed_replace_one_letter, .init = redirect_all_stdout)
{
    std::string file = "one_letter_to_replace.txt";
    std::string s1 = "a";
    std::string s2 = "Hello my new world";
    std::string line;

    Replacer    replacer(file, s1, s2);
    std::ifstream ifs(file);
    if(std::getline(ifs, line, '\0'))
        std::cout   << "Read " << file << " before sed():\n"
                    << line << "\n" << std::endl;
    cr_assert(ifs.is_open() == true);
    ifs.close();
    cr_assert(ifs.is_open() == false);

    replacer.sed();

    ifs.open(file + ".replace");
    cr_assert(ifs.is_open() == true);
    if(std::getline(ifs, line, '\0'))
        std::cout   << "Read " << file + ".replace" << " after sed():\n"
                    << line << std::endl;
    ifs.close();
    cr_assert(ifs.is_open() == false);
    cr_assert_stdout_eq_str(
        "Read one_letter_to_replace.txt before sed():\n"
        "a\n\n"
        "Read one_letter_to_replace.txt.replace after sed():\n"
        "Hello my new world\n"
    );
}

Test(Replacer, Test_Replacer_sed_replace_one_word, .init = redirect_all_stdout)
{
    std::string file = "one_word_to_replace.txt";
    std::string s1 = "Hell";
    std::string s2 = "Hello my new world";
    std::ifstream ifs(file);
    std::string line;

    cr_assert(ifs.is_open() == true);
    if(std::getline(ifs, line, '\0'))
        std::cout   << "Read " << file << " before sed():"
                    << std::endl << line << std::endl << std::endl;
    ifs.close();
    cr_assert(ifs.is_open() == false);
    Replacer    replacer(file, s1, s2);

    replacer.sed();
    ifs.open(file + ".replace");
    cr_assert(ifs.is_open() == true);
    if(std::getline(ifs, line, '\0'))
        std::cout   << "Read " << file + ".replace" << " after sed():"
                    << std::endl << line << std::endl;
    ifs.close();
    cr_assert(ifs.is_open() == false);
    cr_assert_stdout_eq_str(
        "Read one_word_to_replace.txt before sed():\n"
        "Hell this is not a real Hell.\n\n"
        "Read one_word_to_replace.txt.replace after sed():\n"
        "Hello my new world this is not a real Hello my new world.\n"
    );
}

Test(Replacer, Test_Replacer_sed_replace_several_words_in_txt, .init = redirect_all_stdout)
{
    std::string file = "txt_to_replace.txt";
    std::string s1 = "Lorem ipsum";
    std::string s2 = "Hello my new world";
    std::ifstream ifs(file);
    std::string line;

    cr_assert(ifs.is_open() == true);
    if(std::getline(ifs, line, '\0'))
        std::cout   << "Read " << file << " before sed():"
                    << std::endl << line << std::endl << std::endl;
    ifs.close();
    cr_assert(ifs.is_open() == false);
    Replacer    replacer(file, s1, s2);

    replacer.sed();
    ifs.open(file + ".replace");
    cr_assert(ifs.is_open() == true);
    if(std::getline(ifs, line, '\0'))
        std::cout   << "Read " << file + ".replace" << " after sed():"
                    << std::endl << line << std::endl;
    ifs.close();
    cr_assert(ifs.is_open() == false);
    cr_assert_stdout_eq_str(
        "Read txt_to_replace.txt before sed():\n"
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
        "Lorem ipsum Praesent in laoreet mi, sit amet efficitur leo.\n\n"


        "Read txt_to_replace.txt.replace after sed():\n"
        "Hello my new world dolor sit amet, consectetur adipiscing elit.\n"
        "Morbi varius, odio vel egestas gravida, Hello my new world neque lorem fringilla mi, non aliquam urna eros a tellus.\n"
        "Sed convallis a Hello my new world orci sed egestas.\n"
        "Integer Hello my new world sagittis lacinia cursus.\n"
        "Hello my new world Quisque nec odio et diam rhoncus mollis.\n"
        "Suspendisse arcu nisi, pretium Hello my new world sed ex ac, Hello my new world bibendum congue metus.\n"
        "Vivamus ut Hello my new world arcu sapien.\n"
        "Hello my new world Curabitur sit amet neque vitae purus rhoncus tincidunt.\n"
        "Aliquam vel Hello my new world  venenatis ante.\n"
        "Hello my new world Donec tristique metus in turpis tincidunt rhoncus.\n"
        "Hello my new world Praesent in laoreet mi, sit amet efficitur leo.\n"
    );
}

Test(Replacer, Test_Replacer_sed_ifsteram_open_file_error, .init = redirect_all_stdout)
{
    std::string file = "txt_tdso_replace.txt";
    std::string s1 = "Lorem ipsum";
    std::string s2 = "Hello my new world";

    Replacer    replacer(file, s1, s2);
    replacer.sed();
    cr_assert_stderr_eq_str(
        "Error: File <txt_tdso_replace.txt> is not open.\n"
    );
}

Test(Replacer, Test_sed_output_file_not_open, .init = redirect_all_stdout)
{
    std::string path = "./test_dir/";
    mkdir(path.c_str(), 0755);

    std::string file = "testfile.txt";
    std::string s1 = "Hello";
    std::string s2 = "Hi";

    std::ofstream dummyFile((path + file).c_str());
    dummyFile << "Hello World";
    dummyFile.close();

    chmod(path.c_str(), 0555);

    Replacer replacer(path + file, s1, s2);
    replacer.sed();

    cr_assert_stderr_eq_str(("Error: File <" + path + file + ".replace> is not open.\n").c_str());

    chmod(path.c_str(), 0755);
    remove((path + file).c_str());
    rmdir(path.c_str());
}