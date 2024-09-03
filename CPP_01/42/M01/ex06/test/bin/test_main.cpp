/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 20:52:50 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Weapon.hpp"
#include "../../include/HumanA.hpp"
void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Weapon, Test_Weapon_CTOR_isDefined, .init = redirect_all_stdout)
{
    Weapon  weapon = Weapon("crude spiked club");
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
    HumanA  humanA = HumanA("bob", weapon);
}

Test(HumanA, Test_HumanA_getName_isDefined, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA  humanA = HumanA("bob", weapon);

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
    HumanA  humanA = HumanA("bob", weapon);

    humanA.setName("boby");
}

Test(HumanA, Test_HumanA_setName_new_name, .init = redirect_all_stdout)
{
    Weapon weapon = Weapon("crude spiked club");
    HumanA  humanA = HumanA("bob", weapon);

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
    const Weapon &weapon = Weapon("crude spiked club");
    HumanA humanA = HumanA("bob", weapon);

    cr_assert(humanA.getWeapon().getType() == weapon.getType());
}