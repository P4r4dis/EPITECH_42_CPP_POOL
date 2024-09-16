/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/16 19:59:00 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Human.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Human, Test_Human_class_isDefined, .init = redirect_all_stdout)
{
    Human human;
    cr_assert_not_null(&human);
}

Test(Human, Test_Human_action_isDefined, .init = redirect_all_stdout)
{
    Human human;
    std::string target = "Joe";
    
    human.action("melee attack", target);
}

Test(Human, Test_Human_action_meleeAttack, .init = redirect_all_stdout)
{
    Human human;
    std::string target = "Joe";
    
    human.action("melee attack", target);
    cr_assert_stdout_eq_str
    (
        ("Human launches his melee attack on " + target + "\n").c_str()
    );
}

Test(Human, Test_Human_action_rangedAttack, .init = redirect_all_stdout)
{
    Human human;
    std::string target = "Joe";
    
    human.action("ranged attack", target);
    cr_assert_stdout_eq_str
    (
        ("Human launches his ranged attack on " + target + "\n").c_str()
    );
}

Test(Human, Test_Human_action_intimidatingShout, .init = redirect_all_stdout)
{
    Human human;
    std::string target = "Joe";
    
    human.action("intimidating shout", target);
    cr_assert_stdout_eq_str
    (
        ("Human launches his intimidating shout on " + target + "\n").c_str()
    );
}

Test(Human, Test_Human_action_unknown_action_name, .init = redirect_all_stdout)
{
    Human human;
    std::string target = "Joe";
    
    human.action("magical attack", target);
    cr_assert_stdout_eq_str
    (
        "Unknown action: magical attack\n"
    );
}