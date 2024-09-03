/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 18:25:04 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Brain.hpp"
#include "../../include/Human.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Brain, Test_Brain_CTOR_isDefined, .init = redirect_all_stdout)
{
    Brain   brain;
}

Test(Brain, Test_Brain_identify_isDefined, .init = redirect_all_stdout)
{
    Brain   brain;

    brain.identify();
}

Test(Brain, Test_Brain_identify_return_validAddress)//, .init = redirect_all_stdout)
{
    Brain   brain;

    cr_assert(brain.identify().substr(0, 2) == "0x");
}

Test(Human, Test_Human_CTOR_isDefined, .init = redirect_all_stdout)
{
    Human   human;
}

Test(Human, Test_Human_identify_isDefined, .init = redirect_all_stdout)
{
    Human   human;

    human.identify();
}

Test(Human, Test_Human_identify_calls_Brain_identify_return_validAddress)//, .init = redirect_all_stdout)
{
    Human   human;

    cr_assert(human.identify().substr(0, 2) == "0x");
}

Test(Human, Test_Human_getBrain_isDefined, .init = redirect_all_stdout)
{
    Human   human;

    human.getBrain();
}

Test(Human, Test_Human_getBrain_reference_is_not_null, .init = redirect_all_stdout)
{
    Human   human;

    cr_assert_not_null(&human.getBrain());
}

Test(Human, Test_Human_getBrain_return_same_address_of_Brain_Instance, .init = redirect_all_stdout)
{
    Human   human;

    const Brain &ref = human.getBrain();
    const Brain &ref2 = human.getBrain();

    cr_assert_eq(&ref, &ref2);
}