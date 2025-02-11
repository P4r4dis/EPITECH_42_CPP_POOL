/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex09/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Feb 10 7:32:56 PM 2025 Paradis
** Last update Wed Feb 11 4:28:00 PM 2025 Paradis
*/




#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <iostream>

#include "../../include/Phaser.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Sounds_class, Test_REGULAR_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Regular == "Piouuuuuu");
}

Test(Sounds_class, Test_PLASMA_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Plasma == "Fiouuuuuz");
}

Test(Sounds_class, Test_ROCKET_const_class_variable,
.init = redirect_all_stdout)
{
    cr_assert(Sounds::Rocket == "Booooooom");
}

Test(Phaser_class, Test_Enum_AmmoType_REGULAR_const_variable,
.init = redirect_all_stdout)
{
    cr_assert(Phaser::AmmoType::REGULAR == 0);
}

Test(Phaser_class, Test_Enum_AmmoType_PLASMA_const_variable,
.init = redirect_all_stdout)
{
    cr_assert(Phaser::AmmoType::PLASMA == 1);
}

Test(Phaser_class, Test_Enum_AmmoType_ROCKET_const_variable,
.init = redirect_all_stdout)
{
    cr_assert(Phaser::AmmoType::ROCKET == 2);
}

Test(Phaser_class, Test_constructor_default_parameter,
.init = redirect_all_stdout)
{
    Phaser p;

    cr_assert(p.getMaxAmmo() == 20);
    cr_assert(p.getNbAmmos() == 20);
    cr_assert(p.getType() == Phaser::AmmoType::REGULAR);
    cr_assert(p.getEmptyMagazine() == 0);
    cr_assert_not_null(p.getMagazine());
}

Test(Phaser_class, Test_if_magazine_is_correctly_filled,
.init = redirect_all_stdout)
{
    Phaser p;

    Phaser::AmmoType *magazine = p.getMagazine();
    for (int i = 0; i < p.getMaxAmmo(); ++i)
        cr_assert(magazine[i] == p.getType());
}

// Test(Phaser_class, Test_constructor_default_parameter,
//     .init = redirect_all_stdout)
//     {
//         Phaser p;
    
//         cr_assert(p.getMaxAmmo() == 20);
//         cr_assert(p.getNbAmmos() == 20);
//         cr_assert(p.getType() == Phaser::AmmoType::REGULAR);
//         cr_assert(p.getEmptyMagazine() == 0);
//         cr_assert_not_null(p.getMagazine());
//     }

///////////////////////////////////////////////////////////////////////////////
//                                  Main
///////////////////////////////////////////////////////////////////////////////
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