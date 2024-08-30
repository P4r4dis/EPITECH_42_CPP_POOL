/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/30 18:35:34 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Zombie.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Zombie, Test_Zombie_class_isDefinied, .init = redirect_all_stdout)
{
    Zombie  zombie("unknown");
}

Test(Zombie, Test_Zombie_destructor_output, .init = redirect_all_stdout)
{
    {
        Zombie  zombie("unknown");
    }
    cr_assert_stdout_eq_str
    (
        "unknown: Destroyed!\n"
    );
}


Test(Zombie, Test_Zombie_getName_isDefinied, .init = redirect_all_stdout)
{
    Zombie  zombie("unknown");
    zombie.getName();
}

Test(Zombie, Test_Zombie_getName_return_name, .init = redirect_all_stdout)
{
    Zombie  zombie("unknown");

    cr_assert(zombie.getName() == "unknown");
}

Test(Zombie, Test_Zombie_setName_isDefinied, .init = redirect_all_stdout)
{
    Zombie  zombie("unknown");

    zombie.setName("newName");
}

Test(Zombie, Test_Zombie_setName_correctly, .init = redirect_all_stdout)
{
    Zombie  zombie("unknown");

    cr_assert(zombie.getName() == "unknown");
    zombie.setName("newName");
    cr_assert(zombie.getName() == "newName");
}

Test(Zombie, Test_Zombie_announce_isDefinied, .init = redirect_all_stdout)
{
    Zombie  zombie("unknown");

    zombie.announce();
}

Test(Zombie, Test_Zombie_announce_output, .init = redirect_all_stdout)
{
    {
        Zombie  zombie("unknown");

        zombie.announce();
    }
    cr_assert_stdout_eq_str
    (
        "unknown: BraiiiiiiinnnzzzZ...\n"
        "unknown: Destroyed!\n"
    );
}

Test(newZombie, Test_newZombie_isDefinied, .init = redirect_all_stdout)
{
    Zombie  *ptrZombie = nullptr;
    
    ptrZombie = newZombie("unknown");
    delete ptrZombie;
}

Test(newZombie, Test_newZombie_created_outside_of_scope, .init = redirect_all_stdout)
{
    Zombie  *ptrZombie = nullptr;
    
    ptrZombie = newZombie("unknown");
    cr_assert(ptrZombie->getName() == "unknown");
    delete ptrZombie;
}

Test(randomChump, Test_randomChump_isDefinied, .init = redirect_all_stdout)
{
    randomChump("unknown");
}

Test(randomChump, Test_randomChump_output, .init = redirect_all_stdout)
{
    randomChump("unknown");
    cr_assert_stdout_eq_str
    (
        "unknown: BraiiiiiiinnnzzzZ...\n"
        "unknown: Destroyed!\n"
    );
}
