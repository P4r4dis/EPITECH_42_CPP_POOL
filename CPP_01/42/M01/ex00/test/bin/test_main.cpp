/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:20:06 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/28 15:50:44 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../include/Pony.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Pony, Test_Pony_class_isDefinied, .init = redirect_all_stdout)
{
    Pony    pony("Pony");
}


Test(Pony, Test_Pony_getName_isDefinied, .init = redirect_all_stdout)
{
    Pony    pony("Pony");

    pony.getName();
}

Test(Pony, Test_Pony_getName_return_name, .init = redirect_all_stdout)
{
    Pony    pony("Pony");

    cr_assert(pony.getName() == "Pony");
}

Test(Pony, Test_Pony_setName_isDefinied, .init = redirect_all_stdout)
{
    Pony    pony("Pony");

    pony.setName("NewPony");
}

Test(Pony, Test_Pony_setName_modify_name, .init = redirect_all_stdout)
{
    Pony    pony("Pony");

    cr_assert(pony.getName() == "Pony");
    pony.setName("NewPony");
    cr_assert(pony.getName() == "NewPony");
}