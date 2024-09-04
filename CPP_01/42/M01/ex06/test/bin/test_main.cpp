/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/04 16:28:47 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Weapon.hpp"
#include "../../include/HumanA.hpp"
#include "../../include/HumanB.hpp"
void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Weapon, Test_Weapon_CTOR_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
}

Test(Weapon, Test_Weapon_getType_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");

    weapon.getType();
}

Test(Weapon, Test_Weapon_getType_return_type_string, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");

    cr_assert(weapon.getType() == "crude spiked club");
}

Test(Weapon, Test_Weapon_setType_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");

    weapon.setType("some other type of club");
}

Test(Weapon, Test_Weapon_setType_new_type_string, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");

    cr_assert(weapon.getType() == "crude spiked club");
    weapon.setType("some other type of club");
    cr_assert(weapon.getType() == "some other type of club");
}

Test(HumanA, Test_HumanA_CTOR_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA humanA = HumanA("bob", weapon);
}

Test(HumanA, Test_HumanA_getName_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA humanA = HumanA("bob", weapon);

    humanA.getName();
}

Test(HumanA, Test_HumanA_getName_return_name, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA  humanA = HumanA("bob", weapon);

    cr_assert(humanA.getName() == "bob");
}

Test(HumanA, Test_HumanA_setName_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA humanA = HumanA("bob", weapon);

    humanA.setName("boby");
}

Test(HumanA, Test_HumanA_setName_new_name, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA humanA = HumanA("bob", weapon);

    cr_assert(humanA.getName() == "bob");
    humanA.setName("boby");
    cr_assert(humanA.getName() == "boby");
}

Test(HumanA, Test_HumanA_getWeapon_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA  humanA = HumanA("bob", weapon);

    humanA.getWeapon();
}

Test(HumanA, Test_HumanA_getWeapon_return_weapon, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA humanA = HumanA("bob", weapon);

    cr_assert(humanA.getWeapon().getType() == "crude spiked club");
    cr_assert(humanA.getWeapon().getType() == weapon.getType());
}

Test(HumanA, Test_HumanA_setWeapon_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");\
    Weapon weapon2 = Weapon("crude");

    HumanA  humanA = HumanA("bob", weapon);

    humanA.setWeapon(weapon2);
}

Test(HumanA, Test_HumanA_setWeapon_new_weapon, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    Weapon weapon2 = Weapon("crude");
    HumanA humanA = HumanA("bob", weapon);

    cr_assert(humanA.getWeapon().getType() == "crude spiked club");
    humanA.setWeapon(weapon2);
    cr_assert(humanA.getWeapon().getType() == "crude");
}

Test(HumanA, Test_HumanA_attack_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA humanA = HumanA("bob", weapon);

    humanA.attack();
}

Test(HumanA, Test_HumanA_attack_output, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA humanA = HumanA("bob", weapon);

    humanA.attack();
    cr_assert_stdout_eq_str(
        "bob attacks with their crude spiked club\n"
    );
}

Test(HumanB, Test_HumanB_CTOR_isDefined, .init = redirect_all_stdout)
{
    HumanB humanB = HumanB("jim");
}

Test(HumanB, Test_HumanB_getName_isDefined, .init = redirect_all_stdout)
{
    HumanB humanB = HumanB("jim");

    humanB.getName();
}

Test(HumanB, Test_HumanB_getName_return_name, .init = redirect_all_stdout)
{
    HumanB  humanB = HumanB("jim");

    cr_assert(humanB.getName() == "jim");
}

Test(HumanB, Test_HumanB_setName_isDefined, .init = redirect_all_stdout)
{
    HumanB humanB = HumanB("jim");

    humanB.setName("boby");
}

Test(HumanB, Test_HumanB_setName_new_name, .init = redirect_all_stdout)
{
    HumanB humanB = HumanB("jim");

    cr_assert(humanB.getName() == "jim");
    humanB.setName("boby");
    cr_assert(humanB.getName() == "boby");
}

Test(HumanB, Test_HumanB_getWeapon_isDefined, .init = redirect_all_stdout)
{
    HumanB  humanB = HumanB("jim");

    humanB.getWeapon();
}

Test(HumanB, Test_HumanB_getWeapon_return_weapon_NULL, .init = redirect_all_stdout)
{
    HumanB humanB = HumanB("jim");

    cr_assert_null(humanB.getWeapon());
}

Test(HumanB, Test_HumanB_setWeapon_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("some other type of club");
    HumanB  humanB = HumanB("jim");

    humanB.setWeapon(weapon);
}

Test(HumanB, Test_HumanB_setWeapon_new_weapon, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("some other type of club");
    HumanB humanB = HumanB("jim");

    cr_assert_null(humanB.getWeapon());
    humanB.setWeapon(weapon);
    cr_assert_not_null(humanB.getWeapon());
    cr_assert(humanB.getWeapon()->getType() == "some other type of club");
}

Test(HumanB, Test_HumanB_attack_isDefined, .init = redirect_all_stdout)
{
    HumanB humanB = HumanB("jim");

    humanB.attack();
}

Test(HumanB, Test_HumanB_attack_output_with_no_weapon, .init = redirect_all_stdout)
{
    HumanB humanB = HumanB("jim");

    humanB.attack();
    cr_assert_stdout_eq_str(
        ""
    );
}

Test(HumanB, Test_HumanB_attack_output, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("some other type of club");
    HumanB humanB = HumanB("jim");

    humanB.setWeapon(weapon);
    humanB.attack();
    cr_assert_stdout_eq_str(
        "jim attacks with their some other type of club\n"
    );
}

Test(main, Test_main)//, .init = redirect_all_stdout)
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}