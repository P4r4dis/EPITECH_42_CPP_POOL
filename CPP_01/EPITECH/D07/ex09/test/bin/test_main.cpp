/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex09/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Feb 10 7:32:56 PM 2025 Paradis
** Last update Tue Feb 10 9:14:42 PM 2025 Paradis
*/




#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Sounds.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

std::string Sounds::Regular = "Piouuuuuu";
std::string Sounds::Plasma = "Fiouuuuuz";
std::string Sounds::Rocket = "Booooooom";

Test(Sounds_class, Test_Regular_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Regular == "Piouuuuuu");
}

Test(Sounds_class, Test_Plasma_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Plasma == "Fiouuuuuz");
}

Test(Sounds_class, Test_Rocket_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Rocket == "Booooooom");
}

///////////////////////////////////////////////////////////////////////////////
//                                  Main
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
// Test(main, Test_main, .init = redirect_all_stdout)
// {
//     {
//         Phaser p(5, Phaser::ROCKET);

//         p.fire();
//         p.reload();

//         std::cout << "Firing all ammunition" << std::endl;
//         while (p.getCurrentAmmos() > 0)
//             p.fire();
//     }
//     cr_assert_stdout_eq_str(
//         "Booooooom\n"
//         "Reloading...\n"
//         "Firing all ammunitions\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//         "Booooooom\n"
//     );
// }