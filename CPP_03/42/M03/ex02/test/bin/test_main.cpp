/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:58:37 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/29 18:51:26 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <string>

#include "../../include/ClapTrap.hpp"
#include "../../include/ScavTrap.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(ClapTrap, TEST_ClapTrap_default_CTOR, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap;

        cr_assert_not_null(&clapTrap);
    }
}

Test(ClapTrap, TEST_ClapTrap_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap;
    }
    cr_assert_stdout_eq_str(
        "ClapTrap ClapTrap Default CTOR called\n"
        "ClapTrap ClapTrap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("ClapTrap");

        cr_assert_not_null(&clapTrap);
    }
}

Test(ClapTrap, TEST_ClapTrap_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap DTOR called\n"
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
        ClapTrap    clapTrap("Clap");
        ClapTrap    cpyClapTrap(clapTrap);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap Copy CTOR called\n"
        "ClapTrap Clap DTOR called\n"
        "ClapTrap Clap DTOR called\n"
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

Test(ClapTrap, TEST_ClapTrap_attack_function_cant_performs_because_has_no_hit_points_stdout,
    .init = redirect_all_stdout)
    {
        {
            ClapTrap clapTrap("Clap");
            std::string target = "BadBoy";
            
            clapTrap.setHit(0);
            clapTrap.attack(target);
        }
        
        cr_assert_stdout_eq_str(
            "ClapTrap Clap Custom CTOR called\n"
            "ClapTrap Clap can't attack BadBoy, causing 0 points of damage!\n"
            "ClapTrap Clap has no hit or energy points\n"
            "ClapTrap Clap DTOR called\n"
        );
    }

Test(ClapTrap, TEST_ClapTrap_attack_function_cant_performs_because_has_no_energy_points_stdout,
.init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        clapTrap.setEnergy(0);
        clapTrap.attack("BadBoy");
    }

    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap can't attack BadBoy, causing 0 points of damage!\n"
        "ClapTrap Clap has no hit or energy points\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_attack_function_performs_attack_and_loses_1_energy_points, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        cr_assert(clapTrap.getEnergy() == 10);
        clapTrap.attack("BadBoy");
        cr_assert(clapTrap.getEnergy() == 9);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_attack_function_stdout, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        clapTrap.attack("BadBoy");
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_takeDamage_function_receives_damage_and_loses_hit_points,
.init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        cr_assert(clapTrap.getHit() == 10);
        clapTrap.takeDamage(2);
        cr_assert(clapTrap.getHit() == 8);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap receives 2 points of damage!\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_takeDamage_function_receives_more_damage_than_it_has_hit_points,
.init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        cr_assert(clapTrap.getHit() == 10);
        clapTrap.takeDamage(100);
        cr_assert(clapTrap.getHit() == 0);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap receives 100 points of damage!\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_takeDamage_function_cant_performs_because_it_has_no_hit_points,
.init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        clapTrap.setHit(0);
        clapTrap.takeDamage(100);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap can't receives damage because it has no hit points\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_takeDamage_function_stdout, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        clapTrap.takeDamage(100);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap receives 100 points of damage!\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_beRepaired_function_receives_hit_points_and_loses_energy_points,
.init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        cr_assert(clapTrap.getHit() == 10);
        cr_assert(clapTrap.getEnergy() == 10);
        clapTrap.beRepaired(2);
        cr_assert(clapTrap.getHit() == 12);
        cr_assert(clapTrap.getEnergy() == 9);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap receives 2 hit points!\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_beRepaired_function_cant_performs_because_it_has_no_hit_points,
.init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        clapTrap.setHit(0);
        clapTrap.beRepaired(100);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap can't receives hit points because it has no hit points\n"
        "ClapTrap Clap DTOR called\n"
    );
}

Test(ClapTrap, TEST_ClapTrap_beRepaired_function_cant_performs_because_it_has_no_energy_points,
.init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        clapTrap.setEnergy(0);
        clapTrap.beRepaired(100);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap can't receives hit points because it has no energy points\n"
        "ClapTrap Clap DTOR called\n"
    );
}
Test(ClapTrap, TEST_ClapTrap_beRepaired_function_stdout, .init = redirect_all_stdout)
{
    {
        ClapTrap    clapTrap("Clap");

        clapTrap.beRepaired(100);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Clap Custom CTOR called\n"
        "ClapTrap Clap receives 100 hit points!\n"
        "ClapTrap Clap DTOR called\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            ScavTrap class                                 //
///////////////////////////////////////////////////////////////////////////////
Test(ScavTrap, TEST_ScavTrap_default_CTOR, .init = redirect_all_stdout)
{
    {
        ScavTrap    ScavTrap;

        cr_assert_not_null(&ScavTrap);
    }
}

Test(ScavTrap, TEST_ScavTrap_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        ScavTrap    ScavTrap;
    }
    cr_assert_stdout_eq_str(
        "ClapTrap ClapTrap Default CTOR called\n"
        "ScavTrap ScavTrap Default CTOR called\n"
        "ScavTrap ScavTrap DTOR called\n"
        "ClapTrap ScavTrap DTOR called\n"
    );
}

Test(ScavTrap, TEST_ScavTrap_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        ScavTrap    ScavTrap("ScavTrap");

        cr_assert_not_null(&ScavTrap);
    }
}

Test(ScavTrap, TEST_ScavTrap_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        ScavTrap    ScavTrap("ScavTrap");
    }
    cr_assert_stdout_eq_str(
        "ClapTrap ScavTrap Custom CTOR called\n"
        "ScavTrap ScavTrap Custom CTOR called\n"
        "ScavTrap ScavTrap DTOR called\n"
        "ClapTrap ScavTrap DTOR called\n"
    );
}

Test(ScavTrap, TEST_ScavTrap_copy_CTOR, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("ScavTrap");
        ScavTrap    cpyScavTrap(scavTrap);

        cr_assert_not_null(&scavTrap);
        cr_assert_not_null(&cpyScavTrap);
    }
}

Test(ScavTrap, TEST_ScavTrap_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("ScavTrap");
        ScavTrap    cpyScavTrap(scavTrap);

    }
    cr_assert_stdout_eq_str(
        "ClapTrap ScavTrap Custom CTOR called\n"
        "ScavTrap ScavTrap Custom CTOR called\n"
        "ClapTrap ScavTrap Copy CTOR called\n"
        "ScavTrap ScavTrap Copy CTOR called\n"
        "ScavTrap ScavTrap DTOR called\n"
        "ClapTrap ScavTrap DTOR called\n"
        "ScavTrap ScavTrap DTOR called\n"
        "ClapTrap ScavTrap DTOR called\n"
    );
}

Test(ScavTrap, TEST_ScavTrap_getters_and_setters, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("ScavTrap");

        cr_assert(scavTrap.getName() == "ScavTrap");
        scavTrap.setName("NewScavTrap");
        cr_assert(scavTrap.getName() == "NewScavTrap");

        cr_assert(scavTrap.getHit() == 100);
        scavTrap.setHit(20);
        cr_assert(scavTrap.getHit() == 20);

        cr_assert(scavTrap.getEnergy() == 50);
        scavTrap.setEnergy(20);
        cr_assert(scavTrap.getEnergy() == 20);

        cr_assert(scavTrap.getAttack() == 20);
        scavTrap.setAttack(30);
        cr_assert(scavTrap.getAttack() == 30);
    }
}

Test(ScavTrap, TEST_ScavTrap_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("ScavTrap");
        ScavTrap    scavTrap2("ScavTrap2");

        scavTrap2 = scavTrap;

        cr_assert(scavTrap.getName() == scavTrap2.getName());
        cr_assert(scavTrap.getHit() == scavTrap2.getHit());
        cr_assert(scavTrap.getEnergy() == scavTrap2.getEnergy());
        cr_assert(scavTrap.getAttack() == scavTrap2.getAttack());
    }
}

Test(ScavTrap, TEST_ScavTrap_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("ScavTrap");

        scavTrap = scavTrap;

        cr_assert(scavTrap.getName() == scavTrap.getName());
        cr_assert(scavTrap.getHit() == scavTrap.getHit());
        cr_assert(scavTrap.getEnergy() == scavTrap.getEnergy());
        cr_assert(scavTrap.getAttack() == scavTrap.getAttack());
    }
}

Test(ScavTrap, TEST_ScavTrap_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("ScavTrap");
        ScavTrap    scavTrap2("ScavTrap2");

        scavTrap2 = scavTrap;
        scavTrap.setName("NewScavTrap");

        cr_assert(scavTrap2.getName() != scavTrap.getName());
        cr_assert(scavTrap2.getHit() == scavTrap.getHit());
        cr_assert(scavTrap2.getEnergy() == scavTrap.getEnergy());
        cr_assert(scavTrap2.getAttack() == scavTrap.getAttack());
    }
}

Test(ScavTrap, TEST_ScavTrap_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("ScavTrap");
        ScavTrap    scavTrap2("ScavTrap2");
        ScavTrap    &return_value = (scavTrap2 = scavTrap);

        cr_assert_eq(&return_value, &scavTrap2);
    }
}

Test(ScavTrap, TEST_ScavTrap_attack_function_cant_performs_because_has_no_hit_points_stdout,
.init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("Scav");
        std::string target = "BadBoy";
        
        scavTrap.setHit(0);
        scavTrap.attack(target);
    }
    
    cr_assert_stdout_eq_str(
        "ClapTrap Scav Custom CTOR called\n"
        "ScavTrap Scav Custom CTOR called\n"
        "ScavTrap Scav can't attack BadBoy, causing 0 points of damage!\n"
        "ScavTrap Scav has no hit or energy points\n"
        "ScavTrap Scav DTOR called\n"
        "ClapTrap Scav DTOR called\n"
    );
}

Test(ScavTrap, TEST_ScavTrap_attack_function_cant_performs_because_has_no_energy_points_stdout,
.init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("Scav");

        scavTrap.setEnergy(0);
        scavTrap.attack("BadBoy");
    }

    cr_assert_stdout_eq_str(
        "ClapTrap Scav Custom CTOR called\n"
        "ScavTrap Scav Custom CTOR called\n"
        "ScavTrap Scav can't attack BadBoy, causing 0 points of damage!\n"
        "ScavTrap Scav has no hit or energy points\n"
        "ScavTrap Scav DTOR called\n"
        "ClapTrap Scav DTOR called\n"
    );
}

Test(ScavTrap, TEST_ScavTrap_attack_function_performs_attack_and_loses_1_energy_points, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("Scav");

        cr_assert(scavTrap.getEnergy() == 50);
        scavTrap.attack("BadBoy");
        cr_assert(scavTrap.getEnergy() == 49);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Scav Custom CTOR called\n"
        "ScavTrap Scav Custom CTOR called\n"
        "ScavTrap Scav attacks BadBoy, causing 20 points of damage!\n"
        "ScavTrap Scav DTOR called\n"
        "ClapTrap Scav DTOR called\n"
    );
}

Test(ScavTrap, TEST_ScavTrap_attack_function_stdout, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("Scav");

        scavTrap.attack("BadBoy");
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Scav Custom CTOR called\n"
        "ScavTrap Scav Custom CTOR called\n"
        "ScavTrap Scav attacks BadBoy, causing 20 points of damage!\n"
        "ScavTrap Scav DTOR called\n"
        "ClapTrap Scav DTOR called\n"
    );
}

Test(ScavTrap, TEST_ScavTrap_guardGate_function_activates_guard_mode, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("Scav");

        cr_assert(scavTrap.getGuardGate() == false);
        scavTrap.guardGate();
        cr_assert(scavTrap.getGuardGate() == true);
    }
}

Test(ScavTrap, TEST_ScavTrap_guardGate_function_activates_guard_mode_with_stdout, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("Scav");

        cr_assert(scavTrap.getGuardGate() == false);
        scavTrap.guardGate();
        cr_assert(scavTrap.getGuardGate() == true);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Scav Custom CTOR called\n"
        "ScavTrap Scav Custom CTOR called\n"
        "ScavTrap Scav activates the guard mode!\n"
        "ScavTrap Scav DTOR called\n"
        "ClapTrap Scav DTOR called\n"
    );
}


Test(ScavTrap, TEST_ScavTrap_guardGate_function_desactivates_guard_mode, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("Scav");

        cr_assert(scavTrap.getGuardGate() == false);
        scavTrap.guardGate();
        cr_assert(scavTrap.getGuardGate() == true);
        scavTrap.guardGate();
        cr_assert(scavTrap.getGuardGate() == false);
    }
}

Test(ScavTrap, TEST_ScavTrap_guardGate_function_desactivates_guard_mode_with_stdout, .init = redirect_all_stdout)
{
    {
        ScavTrap    scavTrap("Scav");

        cr_assert(scavTrap.getGuardGate() == false);
        scavTrap.guardGate();
        cr_assert(scavTrap.getGuardGate() == true);
        scavTrap.guardGate();
        cr_assert(scavTrap.getGuardGate() == false);
    }
    cr_assert_stdout_eq_str(
        "ClapTrap Scav Custom CTOR called\n"
        "ScavTrap Scav Custom CTOR called\n"
        "ScavTrap Scav activates the guard mode!\n"
        "ScavTrap Scav desactivates the guard mode!\n"
        "ScavTrap Scav DTOR called\n"
        "ClapTrap Scav DTOR called\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    
    {       
        // ClapTrap    clapTrap("Clap");
        // ClapTrap	clone = clapTrap;

        // cr_assert(clapTrap.getName() == "Clap");
        // cr_assert(clapTrap.getHit() == 100);
        // cr_assert(clapTrap.getEnergy() == 50);
        // cr_assert(clapTrap.getAttack() == 20);

        // clapTrap.attack("BadBoy"); // 1st attack
        // clapTrap.attack("BadBoy"); // 2nd attack
        // clapTrap.attack("BadBoy"); // 3rd attack
        // clapTrap.attack("BadBoy"); // 4th attack
        // clapTrap.attack("BadBoy"); // 5th attack
        // clapTrap.attack("BadBoy"); // 6th attack
        // clapTrap.attack("BadBoy"); // 7th attack
        // clapTrap.attack("BadBoy"); // 8th attack
        // clapTrap.attack("BadBoy"); // 9th attack
        // clapTrap.attack("BadBoy"); // 10th attack
        // clapTrap.attack("BadBoy"); // out of energy
        // clapTrap.takeDamage(9); // 1 hp left
        // clapTrap.attack("BadBoy"); // out of energy
        // clapTrap.takeDamage(1); // 0 hp left
        // clapTrap.attack("BadBoy"); // already dead
        // clone.attack("Friend of BadBoy"); // 1st attack
        // clapTrap.beRepaired(10); // already dead

        // cr_assert(clapTrap.getName() == "Clap");
        // cr_assert(clapTrap.getHit() == 0);
        // cr_assert(clapTrap.getEnergy() == 0);
        // cr_assert(clapTrap.getAttack() == 0);
    }

    // cr_assert_stdout_eq_str(
    //     "ClapTrap CTOR called\n"
    //     "ClapTrap Copy CTOR called\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap attacks BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap can't attack BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap has no hit or energy points\n"
    //     "ClapTrap Clap receives 9 points of damage!\n"
    //     "ClapTrap Clap can't attack BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap has no hit or energy points\n"
    //     "ClapTrap Clap receives 1 points of damage!\n"
    //     "ClapTrap Clap can't attack BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap has no hit or energy points\n"
    //     "ClapTrap Clap attacks Friend of BadBoy, causing 0 points of damage!\n"
    //     "ClapTrap Clap can't receives hit points because it has no hit points\n"
    //     "ClapTrap DTOR called\n"
    //     "ClapTrap DTOR called\n"
    // );
}