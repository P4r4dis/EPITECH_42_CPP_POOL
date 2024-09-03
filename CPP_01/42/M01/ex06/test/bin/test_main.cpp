/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 19:59:05 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Weapon.hpp"

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