/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/Test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jun 23 7:04:27 PM 2025 Paradis
** Last update Wed Aug 5 7:10:17 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/Picture.hpp"
#include "../../include/Toy.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


Test(Picture_constructor, Test_is_defined, .init = redirect_all_stdout)
{
    Picture     picture;

    cr_assert_not_null(&picture);
}

Test(Picture_getPictureFromFile,
    Test_with_empty_filename_data_should_set_to_empty_string_and_return_false,
    .init = redirect_all_stdout)
{
    {
        Picture     picture;

        cr_assert(picture.getPictureFromFile("") == false);
    }
    cr_assert_stderr_eq_str
    (
        "\n"
    );
}

Test(Picture_getPictureFromFile,
    Test_cant_open_file_data_should_set_to_error_and_return_false,
    .init = redirect_all_stdout)
{
    {
        Picture     picture;

        cr_assert(picture.getPictureFromFile("./test/files") == false);
    }
    cr_assert_stderr_eq_str
    (
        "ERROR\n"
    );
}

Test(Picture_getPictureFromFile,
    Test_open_file_and_return_true,
    .init = redirect_all_stdout)
{
    {
        Picture     picture;

        cr_assert(picture.getPictureFromFile("./file/alien.txt") == true);
        std::cout << picture.data << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "         _|_\n"
        "   ,_.-_' _ '_-._,\n"
        "    l (.)(.)(.) /\n"
        " _,  `l_-===-_/`  ,_\n"
        ">  |----\"\"\"\"\"----|  <\n"
        "`\"\"`--/   _-@-l--`\"\"`\n"
        "     |===L_I===|\n"
        "      l       /\n"
        "      _l__|__/_\n"
        "     `\"\"\"\"`\"\"\"\"`\n"
    );
}

Test(Picture_custom_constructor,
    Test_open_file_and_set_value_to_data,
    .init = redirect_all_stdout)
{
    {
        Picture     picture("./file/alien.txt");

        std::cout << picture.data << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "         _|_\n"
        "   ,_.-_' _ '_-._,\n"
        "    l (.)(.)(.) /\n"
        " _,  `l_-===-_/`  ,_\n"
        ">  |----\"\"\"\"\"----|  <\n"
        "`\"\"`--/   _-@-l--`\"\"`\n"
        "     |===L_I===|\n"
        "      l       /\n"
        "      _l__|__/_\n"
        "     `\"\"\"\"`\"\"\"\"`\n"
    );
}

Test(Picture_custom_constructor,
    Test_try_to_open_empty_file_and_data_shoukd_be_empty_string,
    .init = redirect_all_stdout)
{
    {
        Picture     picture("");

        cr_assert(picture.data == "");
        std::cout << picture.data << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        ""
    );
}

Test(Picture_custom_constructor,
    Test_cant_open_file_data_should_set_to_error_and_return_false,
    .init = redirect_all_stdout)
{
    {
        Picture     picture("./test/files");

        cr_assert(picture.data == "ERROR");
        std::cout << picture.data << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "ERROR"
    );
}


Test(Picture_Copy_constructor,
    Test_copy_constructor,
    .init = redirect_all_stdout)
{
    {
        Picture     picture("./file/alien.txt");
        Picture     copy(picture);

        cr_assert(picture.data == copy.data);
        std::cout << picture.data << std::flush;
        std::cout << copy.data << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "         _|_\n"
        "   ,_.-_' _ '_-._,\n"
        "    l (.)(.)(.) /\n"
        " _,  `l_-===-_/`  ,_\n"
        ">  |----\"\"\"\"\"----|  <\n"
        "`\"\"`--/   _-@-l--`\"\"`\n"
        "     |===L_I===|\n"
        "      l       /\n"
        "      _l__|__/_\n"
        "     `\"\"\"\"`\"\"\"\"`\n"
        "         _|_\n"
        "   ,_.-_' _ '_-._,\n"
        "    l (.)(.)(.) /\n"
        " _,  `l_-===-_/`  ,_\n"
        ">  |----\"\"\"\"\"----|  <\n"
        "`\"\"`--/   _-@-l--`\"\"`\n"
        "     |===L_I===|\n"
        "      l       /\n"
        "      _l__|__/_\n"
        "     `\"\"\"\"`\"\"\"\"`\n"
    );
}

Test(Picture_assignement_operator,
    Test_assign_an_constructor_to_another_constructor,
    .init = redirect_all_stdout)
{
    {
        Picture     picture("./file/alien.txt");
        Picture     copy;

        cr_assert(picture.data != copy.data);
        std::cout << picture.data << std::flush;
        std::cout << copy.data << std::flush;

        copy = picture;
        cr_assert(picture.data == copy.data);
        std::cout << picture.data << std::flush;
        std::cout << copy.data << std::flush;

    }
    cr_assert_stdout_eq_str
    (
        "         _|_\n"
        "   ,_.-_' _ '_-._,\n"
        "    l (.)(.)(.) /\n"
        " _,  `l_-===-_/`  ,_\n"
        ">  |----\"\"\"\"\"----|  <\n"
        "`\"\"`--/   _-@-l--`\"\"`\n"
        "     |===L_I===|\n"
        "      l       /\n"
        "      _l__|__/_\n"
        "     `\"\"\"\"`\"\"\"\"`\n"
        ""
        "         _|_\n"
        "   ,_.-_' _ '_-._,\n"
        "    l (.)(.)(.) /\n"
        " _,  `l_-===-_/`  ,_\n"
        ">  |----\"\"\"\"\"----|  <\n"
        "`\"\"`--/   _-@-l--`\"\"`\n"
        "     |===L_I===|\n"
        "      l       /\n"
        "      _l__|__/_\n"
        "     `\"\"\"\"`\"\"\"\"`\n"
        "         _|_\n"
        "   ,_.-_' _ '_-._,\n"
        "    l (.)(.)(.) /\n"
        " _,  `l_-===-_/`  ,_\n"
        ">  |----\"\"\"\"\"----|  <\n"
        "`\"\"`--/   _-@-l--`\"\"`\n"
        "     |===L_I===|\n"
        "      l       /\n"
        "      _l__|__/_\n"
        "     `\"\"\"\"`\"\"\"\"`\n"
    );
}

// ///////////////////////////////////////////////////////////////////////////////
// //                            Toy class                                      //
// ///////////////////////////////////////////////////////////////////////////////
Test(Toy_enum, Test_enum_is_defined, .init = redirect_all_stdout)
{
    {
        cr_assert(Toy::BASIC_TOY == 0);
        cr_assert(Toy::ALIEN == 1);
    }
}

Test(Toy_constructor, Test_constructor_is_defined, .init = redirect_all_stdout)
{
    {
        Toy     toto;

        cr_assert_not_null(&toto);
    }
}

Test(Toy_getType, Test_return_basic_type, .init = redirect_all_stdout)
{
    {
        Toy     toto;

        cr_assert(toto.getType() == Toy::BASIC_TOY);
    }
}

Test(Toy_getName, Test_return_name, .init = redirect_all_stdout)
{
    {
        Toy     toto;

        cr_assert(toto.getName() == "toy");
    }
}

Test(Toy_setName, Test_set_name, .init = redirect_all_stdout)
{
    {
        Toy     toto;

        cr_assert(toto.getName() == "toy");
        toto.setName("Buzz");
        cr_assert(toto.getName() == "Buzz");
    }
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    // Toy     toto;
    // Toy     ET(Toy::ALIEN, "green", "./alien.txt");

    // toto.setName("TOTO!");
    // if (toto.getType() == Toy::BASIC_TOY)
    //     std::cout   << "basic toy: " << toto.getName() << std::endl
    //                 << toto.getAscii() << std::endl;
    // if (ET.getType() == Toy::ALIEN)
    //     std::cout   << "this alien is : " << ET.getName() << std::endl
    //                 << ET.getAscii() << std::endl;
}
