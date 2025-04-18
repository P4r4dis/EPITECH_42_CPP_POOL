/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:58:37 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/18 17:41:25 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/ClapTrap.hpp"
void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ClapTrap, TEST_ClapTrap_default_CTOR, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");

        cr_assert_not_null(&clapTrap);
    }
}

Test(ClapTrap, TEST_ClapTrap_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");
    }
    cr_assert_stdout_eq_str(
        "CTOR called\n"
        "DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_copy_CTOR, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");
        ClapTrap    cpyClapTrap(clapTrap);

        cr_assert_not_null(&clapTrap);
        cr_assert_not_null(&cpyClapTrap);
    }
}

Test(ClapTrap, TEST_ClapTrap_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");
        ClapTrap    cpyClapTrap(clapTrap);
    }
    cr_assert_stdout_eq_str(
        "CTOR called\n"
        "Copy CTOR called\n"
        "DTOR called\n"
        "DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_getters_and_setters, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");

        cr_assert(clapTrap.getName() == "ClapTrap");
        clapTrap.setName("NewClap");
        cr_assert(clapTrap.getName() == "NewClap");

        cr_assert(clapTrap.getHit() == 10);
        clapTrap.setHit(20);
        cr_assert(clapTrap.getHit() == 20);

        cr_assert(clapTrap.getEnergy() == 10);
        clapTrap.setEnergy(20);
        cr_assert(clapTrap.getEnergy() == 20);

        cr_assert(clapTrap.getAttack() == 0);
        clapTrap.setAttack(20);
        cr_assert(clapTrap.getAttack() == 20);
    }
}

Test(ClapTrap, TEST_ClapTrap_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");
        ClapTrap    clapTrap2("ClapTrap2");

        clapTrap2 = clapTrap;

        cr_assert(clapTrap.getName() == clapTrap2.getName());
        cr_assert(clapTrap.getHit() == clapTrap2.getHit());
        cr_assert(clapTrap.getEnergy() == clapTrap2.getEnergy());
        cr_assert(clapTrap.getAttack() == clapTrap2.getAttack());
    }
}

Test(ClapTrap, TEST_ClapTrap_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");

        clapTrap = clapTrap;

        cr_assert(clapTrap.getName() == clapTrap.getName());
        cr_assert(clapTrap.getHit() == clapTrap.getHit());
        cr_assert(clapTrap.getEnergy() == clapTrap.getEnergy());
        cr_assert(clapTrap.getAttack() == clapTrap.getAttack());
    }
}

Test(ClapTrap, TEST_ClapTrap_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");
        ClapTrap    clapTrap2("ClapTrap2");


        clapTrap2 = clapTrap;
        clapTrap.setName("NewClap");

        cr_assert(clapTrap2.getName() != clapTrap.getName());
        cr_assert(clapTrap2.getHit() == clapTrap.getHit());
        cr_assert(clapTrap2.getEnergy() == clapTrap.getEnergy());
        cr_assert(clapTrap2.getAttack() == clapTrap.getAttack());
    }
}

Test(ClapTrap, TEST_ClapTrap_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");
        ClapTrap    clapTrap2("ClapTrap2");
        ClapTrap    &return_value = (clapTrap2 = clapTrap);
        

        cr_assert_eq(&return_value, &clapTrap2);
    }
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////

Test(main, Test_main, .init = redirect_all_stdout)
{
    {
      
    }
}