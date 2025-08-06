/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex02/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 5:30:33 PM 2025 Paradis
** Last update Thu Aug 6 6:39:50 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/Picture.hpp"
#include "../../include/Toy.hpp"
#include "../../include/Buzz.hpp"
#include "../../include/Woody.hpp"

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
}

Test(Picture_getPictureFromFile,
    Test_cant_open_file_data_should_set_to_error_and_return_false,
    .init = redirect_all_stdout)
{
    {
        Picture     picture;

        cr_assert(picture.getPictureFromFile("./test/files") == false);
    }
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
    Test_try_to_open_empty_filename_and_data_shoukd_be_ERROR,
    .init = redirect_all_stdout)
{
    {
        Picture     picture("");

        cr_assert(picture.data == "ERROR");
        std::cout << picture.data << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "ERROR"
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
        cr_assert(Toy::BUZZ == 2);
        cr_assert(Toy::WOODY == 3);
    }
}

Test(Toy_constructor, Test_constructor_is_defined, .init = redirect_all_stdout)
{
    {
        Toy     toto;

        cr_assert_not_null(&toto);
    }
}

Test(Toy_custom_constructor, Test_custom_constructor_is_defined,
    .init = redirect_all_stdout)
{
    {
        Toy     ET(Toy::ALIEN, "green", "./file/alien.txt");

        cr_assert_not_null(&ET);
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

Test(Toy_getAscii, Test_returns_the_toy_picture_as_a_string,
    .init = redirect_all_stdout)
{
    {
        Toy     ET(Toy::ALIEN, "green", "./file/alien.txt");

        std::cout << ET.getAscii() << std::flush;
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

Test(Toy_setAscii, Test_set_picture_to_file_content_and_return_true,
    .init = redirect_all_stdout)
{
    {
        Toy     toto;

        cr_assert(toto.getAscii() == "");
        cr_assert(toto.setAscii("./file/alien.txt") == true);
        std::cout << toto.getAscii() << std::flush;
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

Test(Toy_setAscii, Test_set_picture_to_empty_filename_and_return_false,
    .init = redirect_all_stdout)
{
    {
        Toy     toto;

        cr_assert(toto.getAscii() == "");
        cr_assert(toto.setAscii("") == false);
        std::cout << toto.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "ERROR"
    );
}

Test(Toy_setAscii, Test_set_picture_with_wrong_filename_and_return_false,
.init = redirect_all_stdout)
{
    {
        Toy     toto;

        cr_assert(toto.getAscii() == "");
        cr_assert(toto.setAscii("test/test/test") == false);
        std::cout << toto.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "ERROR"
    );
}

// ///////////////////////////////////////////////////////////////////////////////
// //                            Buzz class                                     //
// ///////////////////////////////////////////////////////////////////////////////
Test(Buzz_constructor, Test_constructor_is_defined, .init = redirect_all_stdout)
{
    {
        Buzz     buzzy("Buzz");

        cr_assert_not_null(&buzzy);
    }
}

Test(Buzz_getType, Test_return_basic_type, .init = redirect_all_stdout)
{
    {
        Buzz     buzzy("Buzz");

        cr_assert(buzzy.getType() == Toy::BUZZ);
    }
}

Test(Buzz_getName, Test_return_name, .init = redirect_all_stdout)
{
    {
        Buzz     buzzy("Buzz");

        cr_assert(buzzy.getName() == "Buzz");
    }
}

Test(Buzz_setName, Test_set_name, .init = redirect_all_stdout)
{
    {
        Buzz     buzzy("Buzz");

        cr_assert(buzzy.getName() == "Buzz");
        buzzy.setName("Toy");
        cr_assert(buzzy.getName() == "Toy");
    }
}

Test(Buzz_getAscii, Test_returns_the_toy_picture_as_a_string,
    .init = redirect_all_stdout)
{
    {
        Buzz     buzzy("Buzz", "./file/buzz.txt");

        std::cout << buzzy.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
"                                                  .\n"
"                                                 //\n"
"                          ___                   ////\n"
"                       .-'___`-.               |  |\n"
"                     .' .'_ _'. '.            /~~/\n"
"                     | (| b d |) |          /.    /\n"
"                     |  |  '  |  |         /..  /\n"
",                   ,|  | `-' |  |,       /   ./\n"
"|'-------------''\"\"/.|  /l___/l  |.l\"\"''-/   (/------'|\n"
"|            ____ _.-'l   /   '-._____.-'   l         |\n"
"|.----------/   ._| _    .---. ===  |_.'l   /--------.|\n"
"'          / l  | |l_l _ l=v=/  _   | |  l /          '\n"
"          /   l | | l_l_l ~~~  (_)  | |  .'\n"
"         /_.-'/ \"'|`'--.__.^.__.--'`|'\"'`\n"
"        (    /    l                 /\n"
"        l__.-:     `,..---'\"'---..,'\n"
"         l'  |       :--..___..--:\n"
"          l~~|        l         /\n"
"          /   l       |`.     .'|\n"
"          |  ||       |  :___:  |\n"
"          ||||_       |   | |   |\n"
"          ||||        |   | |   |\n"
"          ````        |.-.| |.-.|\n"
"                      |`-'| |`-'|\n"
"                      |   | |   |\n"
"                     /    | |    l\n"
"                    |_____| |_____|\n"
"                    ':---:-'-:---:'\n"
"                    /    |   |    l\n"
"                   /.---.|   |.---.l\n"
"                   `.____;   :____.'\n"
    );
}

Test(Buzz_setAscii, Test_set_picture_to_file_content_and_return_true,
    .init = redirect_all_stdout)
{
    {
        Buzz     buzzy("Buzz");

        cr_assert(buzzy.getAscii() == "ERROR");
        cr_assert(buzzy.setAscii("./file/buzz.txt") == true);
        std::cout << buzzy.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
"                                                  .\n"
"                                                 //\n"
"                          ___                   ////\n"
"                       .-'___`-.               |  |\n"
"                     .' .'_ _'. '.            /~~/\n"
"                     | (| b d |) |          /.    /\n"
"                     |  |  '  |  |         /..  /\n"
",                   ,|  | `-' |  |,       /   ./\n"
"|'-------------''\"\"/.|  /l___/l  |.l\"\"''-/   (/------'|\n"
"|            ____ _.-'l   /   '-._____.-'   l         |\n"
"|.----------/   ._| _    .---. ===  |_.'l   /--------.|\n"
"'          / l  | |l_l _ l=v=/  _   | |  l /          '\n"
"          /   l | | l_l_l ~~~  (_)  | |  .'\n"
"         /_.-'/ \"'|`'--.__.^.__.--'`|'\"'`\n"
"        (    /    l                 /\n"
"        l__.-:     `,..---'\"'---..,'\n"
"         l'  |       :--..___..--:\n"
"          l~~|        l         /\n"
"          /   l       |`.     .'|\n"
"          |  ||       |  :___:  |\n"
"          ||||_       |   | |   |\n"
"          ||||        |   | |   |\n"
"          ````        |.-.| |.-.|\n"
"                      |`-'| |`-'|\n"
"                      |   | |   |\n"
"                     /    | |    l\n"
"                    |_____| |_____|\n"
"                    ':---:-'-:---:'\n"
"                    /    |   |    l\n"
"                   /.---.|   |.---.l\n"
"                   `.____;   :____.'\n"
    );
}

Test(Buzz_setAscii, Test_set_picture_to_empty_filename_and_return_false,
    .init = redirect_all_stdout)
{
    {
        Buzz     buzzy("Buzz");

        cr_assert(buzzy.setAscii("") == false);
        cr_assert(buzzy.getAscii() == "ERROR");

        std::cout << buzzy.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "ERROR"
    );
}

Test(Buzz_setAscii, Test_set_picture_with_wrong_filename_and_return_false,
.init = redirect_all_stdout)
{
    {
        Buzz     buzzy("Buzz");

        cr_assert(buzzy.setAscii("test/test/test") == false);
        cr_assert(buzzy.getAscii() == "ERROR");
        std::cout << buzzy.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "ERROR"
    );
}

// ///////////////////////////////////////////////////////////////////////////////
// //                            Buzz class                                     //
// ///////////////////////////////////////////////////////////////////////////////
Test(Woody_constructor, Test_constructor_is_defined, .init = redirect_all_stdout)
{
    {
        Woody     woody("Woody");

        cr_assert_not_null(&woody);
    }
}

Test(Woody_getType, Test_return_basic_type, .init = redirect_all_stdout)
{
    {
        Woody     woody("Woody");

        cr_assert(woody.getType() == Toy::WOODY);
    }
}

Test(Woody_getName, Test_return_name, .init = redirect_all_stdout)
{
    {
        Woody     woody("Woody");

        cr_assert(woody.getName() == "Woody");
    }
}

Test(Woody_setName, Test_set_name, .init = redirect_all_stdout)
{
    {
        Woody     woody("Woody");

        cr_assert(woody.getName() == "Woody");
        woody.setName("Toy");
        cr_assert(woody.getName() == "Toy");
    }
}

Test(Woody_getAscii, Test_returns_the_toy_picture_as_a_string,
    .init = redirect_all_stdout)
{
    {
        Woody     woody("Woody", "./file/woody.txt");

        std::cout << woody.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
"           .-'\"\"\"'-.\n"
"      ,____|_______|____,\n"
"       '._____________.'\n"
"           |.-- --.|\n"
"           |(o) (o)|\n"
"          (|       |)\n"
"           |   U   |\n"
" __        | .___. |\n"
"/|||       |       |\n"
"||||       :       :\n"
"|  |/)      `.___.'\n"
" l  /       __) (__\n"
"  l/l      /l l / /l\n"
"   l l    /l l ^ / /l\n"
"    l l  / |  |0_/l_ l\n"
"     l l/ /|  | l  /l l\n"
"      l  / |  |0//ll l l\n"
"       l/  | /   l |  l l\n"
"           |/ .-. l|  / /\n"
"        .-'|-( ~ )-| / /\n"
"        l  |--`-'--|/ /\n"
"         l |       | /\n"
"          l|   |   |/\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |___|___|\n"
"          `|---|---|'\n"
"          *|   |   |*\n"
"           |_._|_._|\n"
"          /'  /|l  'l\n"
"         /   /^ ^l   l\n"
"        /__.'     `.__l\n"
    );
}

Test(Woody_setAscii, Test_set_picture_to_file_content_and_return_true,
    .init = redirect_all_stdout)
{
    {
        Woody     woody("Woody");

        cr_assert(woody.getAscii() == "ERROR");
        cr_assert(woody.setAscii("./file/woody.txt") == true);
        std::cout << woody.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
"           .-'\"\"\"'-.\n"
"      ,____|_______|____,\n"
"       '._____________.'\n"
"           |.-- --.|\n"
"           |(o) (o)|\n"
"          (|       |)\n"
"           |   U   |\n"
" __        | .___. |\n"
"/|||       |       |\n"
"||||       :       :\n"
"|  |/)      `.___.'\n"
" l  /       __) (__\n"
"  l/l      /l l / /l\n"
"   l l    /l l ^ / /l\n"
"    l l  / |  |0_/l_ l\n"
"     l l/ /|  | l  /l l\n"
"      l  / |  |0//ll l l\n"
"       l/  | /   l |  l l\n"
"           |/ .-. l|  / /\n"
"        .-'|-( ~ )-| / /\n"
"        l  |--`-'--|/ /\n"
"         l |       | /\n"
"          l|   |   |/\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |___|___|\n"
"          `|---|---|'\n"
"          *|   |   |*\n"
"           |_._|_._|\n"
"          /'  /|l  'l\n"
"         /   /^ ^l   l\n"
"        /__.'     `.__l\n"
    );
}

Test(Woody_setAscii, Test_set_picture_to_empty_filename_and_return_false,
    .init = redirect_all_stdout)
{
    {
        Woody     woody("Woody");

        cr_assert(woody.setAscii("") == false);
        cr_assert(woody.getAscii() == "ERROR");

        std::cout << woody.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "ERROR"
    );
}

Test(Woody_setAscii, Test_set_picture_with_wrong_filename_and_return_false,
.init = redirect_all_stdout)
{
    {
        Woody     woody("Woody");

        cr_assert(woody.setAscii("test/test/test") == false);
        cr_assert(woody.getAscii() == "ERROR");
        std::cout << woody.getAscii() << std::flush;
    }
    cr_assert_stdout_eq_str
    (
        "ERROR"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    {
        Toy     toto;
        Toy     ET(Toy::ALIEN, "green", "./file/alien.txt");//"./alien.txt");
        Woody   woody("Woody", "./file/woody.txt");
        Buzz    buzzy("Buzz", "./file/buzz.txt");

        toto.setName("TOTO !");
        if (toto.getType() == Toy::BASIC_TOY)
            std::cout   << "basic toy: " << toto.getName() << std::endl
                        << toto.getAscii() << std::flush; // << std::endl;
        if (ET.getType() == Toy::ALIEN)
            std::cout   << "this alien is: " << ET.getName() << std::endl
                        << ET.getAscii() << std::flush;// << std::endl;

        if (woody.getType() == Toy::WOODY)
            std::cout   << "this toy is: " << woody.getName() << std::endl
                        << woody.getAscii() << std::flush;// << std::endl;

        if (buzzy.getType() == Toy::BUZZ)
            std::cout   << "this toy is: " << buzzy.getName() << std::endl
                        << buzzy.getAscii() << std::flush;// << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "basic toy: TOTO !\n"
        "this alien is: green\n"
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
        "this toy is: Woody\n"
"           .-'\"\"\"'-.\n"
"      ,____|_______|____,\n"
"       '._____________.'\n"
"           |.-- --.|\n"
"           |(o) (o)|\n"
"          (|       |)\n"
"           |   U   |\n"
" __        | .___. |\n"
"/|||       |       |\n"
"||||       :       :\n"
"|  |/)      `.___.'\n"
" l  /       __) (__\n"
"  l/l      /l l / /l\n"
"   l l    /l l ^ / /l\n"
"    l l  / |  |0_/l_ l\n"
"     l l/ /|  | l  /l l\n"
"      l  / |  |0//ll l l\n"
"       l/  | /   l |  l l\n"
"           |/ .-. l|  / /\n"
"        .-'|-( ~ )-| / /\n"
"        l  |--`-'--|/ /\n"
"         l |       | /\n"
"          l|   |   |/\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |   |   |\n"
"           |___|___|\n"
"          `|---|---|'\n"
"          *|   |   |*\n"
"           |_._|_._|\n"
"          /'  /|l  'l\n"
"         /   /^ ^l   l\n"
"        /__.'     `.__l\n"
        "this toy is: Buzz\n"
"                                                  .\n"
"                                                 //\n"
"                          ___                   ////\n"
"                       .-'___`-.               |  |\n"
"                     .' .'_ _'. '.            /~~/\n"
"                     | (| b d |) |          /.    /\n"
"                     |  |  '  |  |         /..  /\n"
",                   ,|  | `-' |  |,       /   ./\n"
"|'-------------''\"\"/.|  /l___/l  |.l\"\"''-/   (/------'|\n"
"|            ____ _.-'l   /   '-._____.-'   l         |\n"
"|.----------/   ._| _    .---. ===  |_.'l   /--------.|\n"
"'          / l  | |l_l _ l=v=/  _   | |  l /          '\n"
"          /   l | | l_l_l ~~~  (_)  | |  .'\n"
"         /_.-'/ \"'|`'--.__.^.__.--'`|'\"'`\n"
"        (    /    l                 /\n"
"        l__.-:     `,..---'\"'---..,'\n"
"         l'  |       :--..___..--:\n"
"          l~~|        l         /\n"
"          /   l       |`.     .'|\n"
"          |  ||       |  :___:  |\n"
"          ||||_       |   | |   |\n"
"          ||||        |   | |   |\n"
"          ````        |.-.| |.-.|\n"
"                      |`-'| |`-'|\n"
"                      |   | |   |\n"
"                     /    | |    l\n"
"                    |_____| |_____|\n"
"                    ':---:-'-:---:'\n"
"                    /    |   |    l\n"
"                   /.---.|   |.---.l\n"
"                   `.____;   :____.'\n"
    );
}
