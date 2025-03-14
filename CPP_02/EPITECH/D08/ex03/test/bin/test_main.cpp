/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex03/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Mar 11 5:56:14 PM 2025 Paradis
** Last update Sat Mar 14 6:28:44 PM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>
#include <limits>
#include <ostream>

#include "../../include/Droid.hpp"
#include "../../include/DroidMemory.hpp"
#include "../../include/Carrier.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void testMemory()
{
    DroidMemory mem1;

    mem1 += 42;
    std::cout << mem1 << std::endl;

    DroidMemory mem2;

    mem2 << mem1;
    mem2 >> mem1;
    mem2 << mem1;
    std::cout << mem2 << std::endl;
    std::cout << mem1 << std::endl;

    DroidMemory mem3 = mem1;
    DroidMemory mem4;

    mem4 = mem1 + mem3;
}

// static void testDroids ()
// {
//     Droid d("rudolf");
//     Droid d2("gaston");
//     size_t DuraSell = 40;

//     d << DuraSell;
//     d.setStatus(new std::string("having some reset"));
//     d2.setStatus(new std::string("having some reset"));
//     if (d2 != d && !(d == d2))
//         std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;

//     d(new std::string("take a coffee"), 20);
//     std::cout << d << std::endl;
//     while (d(new std::string("Patrol around"), 20))
//     {
//         if (!d(new std::string("Shoot some ennemies"), 50))
//             d(new std::string("Run Away"), 20);
//         std::cout << d << std::endl;
//     }
//     std::cout << d << std::endl;
// }

Test(Droid_class, TEST_Droid_custom_CTOR_isDefined, .init = redirect_all_stdout)
{
    Droid   d("Avenger");
    cr_assert_not_null(&d);
}

Test(Droid_class, TEST_Droid_custom_CTOR_check_parameters, .init = redirect_all_stdout)
{
    Droid   d("Avenger");
    
    cr_assert(d.getId() == "Avenger");
    cr_assert(d.getEnergy() == ENERGY);
    cr_assert(d.getAttack() == ATTACK);
    cr_assert(d.getToughness() == TOUGHNESS);
    cr_assert(d.getStatus()->compare("Standing by") == 0);
    cr_assert_not_null(d.getBattleData());

}

Test(Droid_class, TEST_Droid_custom_CTOR_check_stdout, .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");
    }
    cr_assert_stdout_eq_str(
        "Droid 'Avenger' Activated\n"
        "Droid 'Avenger' Destroyed\n"
    );
}

Test(Droid_class, TEST_Droid_copyCTOR_check_stdout, .init = redirect_all_stdout)
{
    {
        Droid   d1("Avenger");
        Droid   d(d1);

    }
    cr_assert_stdout_eq_str(
        "Droid 'Avenger' Activated\n"
        "Droid 'Avenger' Activated, Memory Dumped\n"
        "Droid 'Avenger' Destroyed\n"
        "Droid 'Avenger' Destroyed\n"
    );
}

Test(Droid_class, TEST_Droid_assignment_operator_with_two_differents_CTOR,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Thanos");
        Droid   d1("Avenger");

        cr_assert(d.getId() == "Thanos");
        cr_assert(d.getEnergy() == ENERGY);
        cr_assert(d.getAttack() == ATTACK);
        cr_assert(d.getToughness() == TOUGHNESS);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
        cr_assert_not_null(d.getBattleData());

        d = d1;

        cr_assert(d.getId() == "Avenger");
        cr_assert(d.getEnergy() == ENERGY);
        cr_assert(d.getAttack() == ATTACK);
        cr_assert(d.getToughness() == TOUGHNESS);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
        cr_assert(d.getBattleData()->getExp() == d1.getBattleData()->getExp());

    }
}

Test(Droid_class, TEST_Droid_assignment_operator_with_Energy_CTOR_is_different,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Thanos");
        Droid   d1("Avenger");

        cr_assert(d.getId() == "Thanos");
        cr_assert(d.getEnergy() == ENERGY);
        cr_assert(d.getAttack() == ATTACK);
        cr_assert(d.getToughness() == TOUGHNESS);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
        cr_assert_not_null(d.getBattleData());

        d1.setEnergy(100);
        d = d1;

        cr_assert(d.getId() == "Avenger");
        cr_assert(d.getEnergy() == ENERGY);
        cr_assert(d.getAttack() == ATTACK);
        cr_assert(d.getToughness() == TOUGHNESS);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
        cr_assert(d.getBattleData()->getExp() == d1.getBattleData()->getExp());

    }
}


Test(Droid_class, TEST_Droid_assignment_operator_with_two_same_CTOR,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");

        cr_assert(d.getId() == "Avenger");
        cr_assert(d.getEnergy() == ENERGY);
        cr_assert(d.getAttack() == ATTACK);
        cr_assert(d.getToughness() == TOUGHNESS);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
        cr_assert_not_null(d.getBattleData());

        d = d;

        cr_assert(d.getId() == "Avenger");
        cr_assert(d.getEnergy() == ENERGY);
        cr_assert(d.getAttack() == ATTACK);
        cr_assert(d.getToughness() == TOUGHNESS);
        cr_assert(d.getStatus()->compare("Standing by") == 0);
        cr_assert(d.getBattleData() == d.getBattleData());

    }
}

Test(Droid_class, TEST_setBattleData,
    .init = redirect_all_stdout)
{
    {
        Droid d("Thanos");

        cr_assert_not_null(d.getBattleData());
        cr_assert(d.getBattleData()->getExp() == 0);

        DroidMemory mem;
        mem += 42;
        d.setBattleData(&mem);

        cr_assert_not_null(d.getBattleData());
        cr_assert(d.getBattleData()->getExp() == 42);

        d.setBattleData(nullptr);
        cr_assert_not_null(d.getBattleData());

        d.setBattleData(&mem);
        cr_assert_not_null(d.getBattleData());
        cr_assert(d.getBattleData()->getExp() == 42);
    }
}

Test(Droid_class, TEST_setId,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Thanos");

        cr_assert(d.getId() == "Thanos");

        d.setId("Avenger");

        cr_assert(d.getId() == "Avenger");
    }
}

Test(Droid_class, TEST_setEnergy,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");
        
        cr_assert(d.getEnergy() == ENERGY);

        d.setEnergy(60);

        cr_assert(d.getEnergy() == 60);
    }
}

Test(Droid_class, TEST_setEnergy_cant_set_more_than_100,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");

        cr_assert(d.getEnergy() == ENERGY);

        d.setEnergy(100);

        cr_assert(d.getEnergy() == 100);
    }
}

Test(Droid_class, TEST_setEnergy_cant_set_less_than_zero,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");

        cr_assert(d.getEnergy() == ENERGY);

        d.setEnergy(-100);
        
        cr_assert(d.getEnergy() == 100);
    }
}

Test(Droid_class, TEST_setStatus,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");

        d.setStatus(nullptr);
        cr_assert(d.getStatus()->compare("Standing by") == 0);

        d.setStatus(new std::string("Pending by"));

        cr_assert(d.getStatus()->compare("Pending by") == 0);
    }
}

Test(Droid_class, TEST_operator_stream_insertion_overloaded_print_msg,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");

        std::cout << d << std::endl;
    }
    cr_assert_stdout_eq_str(
        "Droid 'Avenger' Activated\n"
        "Droid 'Avenger', Standing by, 50\n"
        "Droid 'Avenger' Destroyed\n"
    );
}

Test(Droid_class,
    TEST_operator_stream_insertion_overloaded_to_realod_droid_energy,
    .init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");
        size_t  Durasel = 200;
    
        cr_assert(Durasel == 200);
        cr_assert(d.getEnergy() == ENERGY);

        d << Durasel;
        
        cr_assert(Durasel == 150);
        cr_assert(d.getEnergy() == 100);
    }
}

Test(Droid_class,
    TEST_operator_stream_insertion_overloaded_realod_energy_with_chain_call,
.init = redirect_all_stdout)
{
    {
        Droid   d("Avenger");
        size_t  Durasel = 5;
        size_t  Durasel2 = 1;

        d << Durasel << Durasel2;
        
        cr_assert(Durasel == 0);
        cr_assert(Durasel2 == 0);
        cr_assert(d.getEnergy() == 56);
    }
}

Test(Droid_class, Test_operator_equal_identical_droids, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    cr_assert_eq(d1, d2);
}

Test(Droid_class, Test_operator_equal_same_instance, .init = redirect_all_stdout)
{
    Droid d1("R2D2");

    cr_assert(d1 == d1);
}

Test(Droid_class, Test_operator_equal_equal_models, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("C3PO");

    cr_assert(d1 == d2);
}

Test(Droid_class, Test_operator_equal_different_energy, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    d2.setEnergy(ENERGY);

    cr_assert(d1 == d2);
}

Test(Droid_class, Test_operator_equal_different_status, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    d2.setStatus(new std::string("Attack mode"));

    cr_assert_not(d1 == d2);
}

Test(Droid_class, Test_operator_not_equal_identical_droids, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    cr_assert_not((d1 != d2));
}

Test(Droid_class, Test_operator_not_equal_same_instance, .init = redirect_all_stdout)
{
    Droid d1("R2D2");

    cr_assert_not((d1 != d1));
}

Test(Droid_class, Test_operator_not_different_models, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("C3PO");

    cr_assert_not(d1 != d2);
}

Test(Droid_class, Test_operator_not_equal_different_energy, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    d2.setEnergy(ENERGY);

    cr_assert_not(d1 != d2);
}

Test(Droid_class, Test_operator_not_equal_different_status, .init = redirect_all_stdout)
{
    Droid d1("R2D2");
    Droid d2("R2D2");

    d2.setStatus(new std::string("Attack mode"));

    cr_assert(d1 != d2);
}

Test(Droid_class, Test_DroidMemory_created_during_Droid_construction,
    .init = redirect_all_stdout)
{
    Droid d1("R2D2");

    cr_assert_not_null(d1.getBattleData());
    cr_assert(d1.getBattleData()->getExp() == 0);
}

Test(Droid_class,
    TEST_Droid_operator_call_function_has_empty_task_return_false,
    .init = redirect_all_stdout)
{
    {
        testMemory();

        Droid d("rudolf");
        Droid d2("gaston");
        size_t DuraSell = 40;
    
        d << DuraSell;
        d.setStatus(new std::string("having some reset"));
        d2.setStatus(new std::string("having some reset"));
        // if (d2 != d && !(d == d2))
        //     std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;
        cr_assert(d(new std::string(""), 20) == false);
    }
}

Test(Droid_class,
    TEST_Droid_operator_call_function_has_enough_Energy_but_doesnt_have_enough_xp_return_false,
    .init = redirect_all_stdout)
{
    {
        testMemory();

        Droid d("rudolf");
        Droid d2("gaston");
        size_t DuraSell = 40;

        d << DuraSell;
        d.setStatus(new std::string("having some reset"));
        d2.setStatus(new std::string("having some reset"));

        // if (d2 != d && !(d == d2))
        //     std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;
        cr_assert(d.getEnergy() == ENERGY + 40);
        cr_assert(d(new std::string("take a coffee"), 20) == false);

    }
}

Test(Droid_class,
    TEST_Droid_operator_call_function_doesnt_have_enough_xp_return_false_and_use_Energy,
    .init = redirect_all_stdout)
{
    {
        testMemory();

        Droid d("rudolf");
        Droid d2("gaston");
        size_t DuraSell = 40;
    
        d << DuraSell;
        d.setStatus(new std::string("having some reset"));
        d2.setStatus(new std::string("having some reset"));

        // if (d2 != d && !(d == d2))
        //     std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;

        cr_assert(d.getEnergy() == ENERGY + 40);
        cr_assert(d(new std::string("take a coffee"), 20) == false);
        cr_assert(d.getEnergy() == (ENERGY + 40 - COST));

    }
}

Test(Droid_class,
    TEST_Droid_operator_call_function_return_false_but_increase_Exp_by_total_amount_of_expRequired,
    .init = redirect_all_stdout)
{
    {
        testMemory();

        Droid d("rudolf");
        Droid d2("gaston");
        size_t DuraSell = 40;
    
        d << DuraSell;
        d.setStatus(new std::string("having some reset"));
        d2.setStatus(new std::string("having some reset"));

        // if (d2 != d && !(d == d2))
        //     std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;

        cr_assert(d.getBattleData()->getExp() == 0);
        cr_assert(d(new std::string("take a coffee"), 20) == false);
        cr_assert(d.getBattleData()->getExp() == 20);

    }
}

Test(Droid_class,
    TEST_Droid_operator_call_function_task_fail_because_not_enough_exp_return_false_and_update_Status,
    .init = redirect_all_stdout)
{
    {
        testMemory();

        Droid d("rudolf");
        Droid d2("gaston");
        size_t DuraSell = 40;
    
        d << DuraSell;
        d.setStatus(new std::string("having some reset"));
        d2.setStatus(new std::string("having some reset"));

        // if (d2 != d && !(d == d2))
        //     std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;

        cr_assert(d.getStatus()->compare("having some reset") == 0);
        cr_assert(d(new std::string("take a coffee"), 20) == false);
        cr_assert(d.getStatus()->compare("take a coffee - Failed!") == 0);
        std::cout << d << std::endl;
    }
}

Test(Droid_class,
    TEST_Droid_operator_call_function_task_perform_task_and_return_true,
    .init = redirect_all_stdout)
{
    {
        testMemory();

        Droid d("rudolf");
        Droid d2("gaston");
        size_t DuraSell = 40;
    
        d << DuraSell;
        d.setStatus(new std::string("having some reset"));
        d2.setStatus(new std::string("having some reset"));

        // if (d2 != d && !(d == d2))
        //     std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;

        cr_assert(d.getStatus()->compare("having some reset") == 0);
        cr_assert(d(new std::string("take a coffee"), 20) == false);
        cr_assert(d.getStatus()->compare("take a coffee - Failed!") == 0);
        std::cout << d << std::endl;
        while (d(new std::string("Patrol around"), 20))
        {
            if (!d(new std::string("Shoot some ennemies"), 50))
                d(new std::string("Run Away"), 20);
            std::cout << d << std::endl;
        }
    }
}

Test(Droid_class,
    TEST_Droid_operator_call_function_try_to_performs_task_but_battery_low_and_return_false,
    .init = redirect_all_stdout)
{
    {
        testMemory();

        Droid d("rudolf");
        Droid d2("gaston");
        size_t DuraSell = 40;
    
        d << DuraSell;
        d.setStatus(new std::string("having some reset"));
        d2.setStatus(new std::string("having some reset"));

        // if (d2 != d && !(d == d2))
        //     std::cout << "a droid is a droid, all its matter is what it's doing" << std::endl;

        cr_assert(d.getStatus()->compare("having some reset") == 0);
        cr_assert(d(new std::string("take a coffee"), 20) == false);
        cr_assert(d.getStatus()->compare("take a coffee - Failed!") == 0);
        std::cout << d << std::endl;
        while (d(new std::string("Patrol around"), 20))
        {
            if (!d(new std::string("Shoot some ennemies"), 50))
                cr_assert(d(new std::string("Run Away"), 20));
            std::cout << d << std::endl;
        }
        std::cout << d << std::endl;
    }
    cr_assert_stdout_eq_str(
        "DroidMemory '1804289357', 42\n"
        "DroidMemory '1804289357', 126\n"
        "DroidMemory '846930886', 84\n"
        "Droid 'rudolf' Activated\n"
        "Droid 'gaston' Activated\n"
        "Droid 'rudolf', take a coffee - Failed!, 80\n"
        "Droid 'rudolf', Run Away - Completed!, 50\n"
        "Droid 'rudolf', Shoot some ennemies - Completed!, 30\n"
        "Droid 'rudolf', Shoot some ennemies - Completed!, 10\n"
        "Droid 'rudolf', Battery Low, 0\n"
        "Droid 'gaston' Destroyed\n"
        "Droid 'rudolf' Destroyed\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            DroidMemory class                              //
///////////////////////////////////////////////////////////////////////////////
Test(DroidMemory, TEST_DroidMemory_default_CTOR_isDefined,
    .init = redirect_all_stdout)
{
    DroidMemory   mem1;
    cr_assert_not_null(&mem1);
}

Test(DroidMemory, TEST_DroidMemory_default_CTOR_check_parameters,
.init = redirect_all_stdout)
{
    DroidMemory   mem1;
    
    cr_assert(mem1.getFingerPrint() > 0 && mem1.getFingerPrint() <= std::numeric_limits<int>::max());
    cr_assert(mem1.getExp() == 0);
}

Test(DroidMemory, TEST_DroidMemory_setFingerPrint,
    .init = redirect_all_stdout)
{
    DroidMemory   mem1;
    
    cr_assert(mem1.getFingerPrint() > 0 && mem1.getFingerPrint() <= std::numeric_limits<int>::max());

    mem1.setFingerPrint(0);

    cr_assert(mem1.getFingerPrint() == 0);
}

Test(DroidMemory, TEST_DroidMemory_setExp,
    .init = redirect_all_stdout)
{
    DroidMemory   mem1;
    
    cr_assert(mem1.getExp() == 0);

    mem1.setExp(100);

    cr_assert(mem1.getExp() == 100);
}

Test(DroidMemory, TEST_DroidMemory_copyCTOR_checks_parameters, .init = redirect_all_stdout)
{
    {
        DroidMemory   mem1;

        cr_assert(mem1.getFingerPrint() > 0 && mem1.getFingerPrint() <= std::numeric_limits<int>::max());
        cr_assert(mem1.getExp() == 0);

        DroidMemory   mem2(mem1);

        cr_assert(mem2.getFingerPrint() > 0 && mem2.getFingerPrint() <= std::numeric_limits<int>::max());
        cr_assert(mem2.getExp() == 0);
    }
}

Test(DroidMemory, TEST_DroidMemory_assignment_operator_with_two_differents_CTOR,
    .init = redirect_all_stdout)
{
    {
        DroidMemory   mem1;
        DroidMemory   mem2;

        cr_assert(mem1.getFingerPrint() > 0 && mem1.getFingerPrint() <= std::numeric_limits<int>::max());
        cr_assert(mem1.getExp() == 0);

        mem2 = mem1;

        cr_assert(mem2.getFingerPrint() > 0 && mem2.getFingerPrint() <= std::numeric_limits<int>::max());
        cr_assert(mem2.getExp() == 0);
    }
}

Test(DroidMemory, TEST_DroidMemory_assignment_operator_with_same_CTOR,
    .init = redirect_all_stdout)
{
    {
        DroidMemory   mem1;

        cr_assert(mem1.getFingerPrint() > 0 && mem1.getFingerPrint() <= std::numeric_limits<int>::max());
        cr_assert(mem1.getExp() == 0);

        mem1 = mem1;

        cr_assert(mem1.getFingerPrint() > 0 && mem1.getFingerPrint() <= std::numeric_limits<int>::max());
        cr_assert(mem1.getExp() == 0);
    }
}

Test(DroidMemory, TEST_DroidMemory_left_stream_operator_add_exp,
    .init = redirect_all_stdout)
{
    {
        DroidMemory   mem1;

        cr_assert(mem1.getExp() == 0);

        DroidMemory   mem2;
        mem2.setExp(42);
        cr_assert(mem2.getExp() == 42);

        mem1 << mem2;
        cr_assert(mem1.getExp() == 42);

    }
}

Test(DroidMemory,
    TEST_DroidMemory_left_stream_operator_performs_xor_of_the_Fingerprint,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        mem1 += 42;

        DroidMemory mem3;
        mem3 << mem1;
        mem3 >> mem1;
        mem3 << mem1;
        cr_assert(mem3.getFingerPrint() == 1804289357);
        cr_assert(mem3.getExp() == 126);

    }
}

Test(DroidMemory,
    TEST_DroidMemory_left_stream_operator_can_be_chain,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        cr_assert(mem1.getExp() == 0);

        DroidMemory     mem2;
        mem2.setExp(1);
        cr_assert(mem2.getExp() == 1);

        DroidMemory     mem3;
        mem3.setExp(1);
        cr_assert(mem3.getExp() == 1);
        mem1 << mem2 << mem3;
        cr_assert(mem1.getExp() == 2);
    }
}

Test(DroidMemory, TEST_DroidMemory_right_stream_operator_add_exp,
    .init = redirect_all_stdout)
{
    {
        DroidMemory   mem1;

        cr_assert(mem1.getExp() == 0);

        DroidMemory   mem2;
        mem2.setExp(42);
        cr_assert(mem2.getExp() == 42);

        mem1 >> mem2;
        cr_assert(mem2.getExp() == 42);

    }
}

Test(DroidMemory,
    TEST_DroidMemory_right_stream_operator_performs_xor_of_the_Fingerprint,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        mem1 += 42;

        DroidMemory mem3;
        mem3 << mem1;
        mem3 >> mem1;
        mem3 << mem1;
        cr_assert(mem1.getFingerPrint() == 846930886);
        cr_assert(mem1.getExp() == 84);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_right_stream_operator_can_be_chain,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        cr_assert(mem1.getExp() == 0);

        DroidMemory     mem2;
        mem2.setExp(1);
        cr_assert(mem2.getExp() == 1);

        DroidMemory     mem3;
        mem3.setExp(1);
        cr_assert(mem3.getExp() == 1);
        mem1 >> mem2 >> mem3;
        cr_assert(mem3.getExp() == 2);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_Plus_Equal_operator_add_exp_and_perform_XOR,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;

        cr_assert(mem1.getExp() == 0);
        cr_assert(mem1.getFingerPrint() > 0 &&
                mem1.getFingerPrint() <= std::numeric_limits<int>::max());
        mem1 += 42;
        cr_assert(mem1.getExp() == 42);
        cr_assert(mem1.getFingerPrint() == 1804289357);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_Plus_operator_overload,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;
        DroidMemory     mem3;
        mem1 += 42;
        cr_assert(mem1.getExp() == 42);
        cr_assert(mem1.getFingerPrint() == 1804289357);

        mem3 = mem1 + mem2;
        
        cr_assert(mem3.getExp() == 42);
        cr_assert(mem3.getFingerPrint() == (mem1.getFingerPrint() ^ mem2.getFingerPrint()));
    }
}

Test(DroidMemory,
    TEST_DroidMemory_left_stream_operator_overload_redirected_to_stdout,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;

        mem1 += 42;
        cr_assert(mem1.getExp() == 42);
        cr_assert(mem1.getFingerPrint() == 1804289357);
        std::cout << mem1 << std::endl;
    }
    cr_assert_stdout_eq_str(
        "DroidMemory '1804289357', 42\n"
    );
}

Test(DroidMemory,
    TEST_DroidMemory_plus_equal_operator_same_behavior_than_left_stream_operator_overloaded,
    .init = redirect_all_stdout)
{
    {
        DroidMemory   mem1;

        cr_assert(mem1.getExp() == 0);

        DroidMemory   mem2;
        mem2.setExp(42);
        cr_assert(mem2.getExp() == 42);
        size_t result = mem1.getFingerPrint() ^ mem2.getFingerPrint();
        mem1 += mem2;
        cr_assert(mem1.getExp() == 42);
        cr_assert(mem1.getFingerPrint() == result);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_equal_equal_operator_overloaded_compare_Exp_and_FingerPrint,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;
        DroidMemory     mem3(mem1);

        cr_assert_not((mem1 == mem2));
        cr_assert(mem1 == mem3);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_different_operator_overloaded_compare_Exp_and_FingerPrint,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;
        DroidMemory     mem3(mem1);

        cr_assert(mem1 != mem2);
        cr_assert_not(mem1 != mem3);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_less_than_operator_overloaded_compare_Exp,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;

        mem2 += 42;
        cr_assert(mem1 < mem2);
        cr_assert_not(mem2 < mem1);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_greater_than_operator_overloaded_compare_Exp,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;

        mem1 += 42;
        cr_assert(mem1 > mem2);
        cr_assert_not(mem2 > mem1);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_less_than_or_equal_operator_overloaded_compare_Exp,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;

        cr_assert(mem1 <= mem2);
        cr_assert(mem2 <= mem1);

        mem2 += 42;
        cr_assert(mem1 <= mem2);
        cr_assert_not(mem2 <= mem1);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_greater_than_or_equal_operator_overloaded_compare_Exp,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;

        cr_assert(mem1 >= mem2);
        cr_assert(mem2 >= mem1);

        mem1 += 42;
        cr_assert(mem1 >= mem2);
        cr_assert_not(mem2 >= mem1);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_less_than_operator_overloaded_compare_size_t,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;

        mem2 += 42;
        cr_assert(mem1 < mem2.getExp());
        cr_assert_not(mem2 < mem1);
    }
}

Test(DroidMemory,
    TEST_DroidMemory_greater_than_operator_overloaded_compare_size_t,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;

        mem1 += 42;
        cr_assert(mem1 > mem2.getExp());
        cr_assert_not(mem2 > mem1.getExp());
    }
}

Test(DroidMemory,
    TEST_DroidMemory_less_than_or_equal_operator_overloaded_compare_size_t,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;

        cr_assert(mem1 <= mem2.getExp());
        cr_assert(mem2 <= mem1.getExp());

        mem2 += 42;
        cr_assert(mem1 <= mem2.getExp());
        cr_assert_not(mem2 <= mem1.getExp());
    }
}

Test(DroidMemory,
    TEST_DroidMemory_greater_than_or_equal_operator_overloaded_compare_size_t,
    .init = redirect_all_stdout)
{
    {
        DroidMemory     mem1;
        DroidMemory     mem2;

        cr_assert(mem1 >= mem2.getExp());
        cr_assert(mem2 >= mem1.getExp());

        mem1 += 42;
        cr_assert(mem1 >= mem2.getExp());
        cr_assert_not(mem2 >= mem1.getExp());
    }
}
///////////////////////////////////////////////////////////////////////////////
//                            Carrier Class                                  //
///////////////////////////////////////////////////////////////////////////////

Test(Carrier, TEST_Carrier_custom_CTOR_isDefined,
    .init = redirect_all_stdout)
{
    Carrier   c("HellExpress");
    cr_assert_not_null(&c);
}

Test(Carrier, TEST_Carrier_custom_CTOR_check_parameters,
    .init = redirect_all_stdout)
    {
        Carrier   c("HellExpress");
        
        cr_assert(c.getId() == "HellExpress");
        cr_assert(c.getEnergy() == 300);
        cr_assert(c.getAttack() == 100);
        cr_assert(c.getToughness() == 90);
        cr_assert(c.getSpeed() == 0);
        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));
    }

Test(Carrier, TEST_Carrier_check_setters_without_setDroids,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");

        cr_assert(c.getId() == "HellExpress");
        c.setId("TEST");
        cr_assert(c.getId() == "TEST");

        cr_assert(c.getEnergy() == 300);
        c.setEnergy(200);
        cr_assert(c.getEnergy() == 200);

        cr_assert(c.getSpeed() == 0);
        c.setSpeed(300);
        cr_assert(c.getSpeed() == 300);

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));
    }

Test(Carrier, TEST_setDroids_position_less_than_zero,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");
        Droid       *d1 = new Droid("Commander");

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);
        c.setDroids(-1, d1);
        cr_assert(c.getSpeed() == 0);
        
        cr_assert_null(c.getDroids(-1));
        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        delete d1;
    }

Test(Carrier, TEST_setDroids_position_greater_than_MAXSIZE,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");
        Droid       *d1 = new Droid("Commander");

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);
        c.setDroids(10, d1);
        cr_assert(c.getSpeed() == 0);

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        delete d1;
    }

Test(Carrier, TEST_setDroids_pos_zero,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");
        Droid       *d1 = new Droid("Commander");

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);
        c.setDroids(0, d1);

        for (size_t i = 0; i < 5; ++i)
        {
            if (c.getDroids(i))
                cr_assert_not_null(c.getDroids(i));
            else
                cr_assert_null(c.getDroids(i));
        }
        cr_assert(c.getSpeed() == 90);
    }

Test(Carrier, TEST_setDroids_pos_one,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");
        Droid       *d1 = new Droid("Commander");

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);
        c.setDroids(1, d1);

        for (size_t i = 0; i < 5; ++i)
        {
            if (c.getDroids(i))
                cr_assert_not_null(c.getDroids(i));
            else
                cr_assert_null(c.getDroids(i));
        }
        cr_assert(c.getSpeed() == 90);
    }

Test(Carrier, TEST_setDroids_pos_two,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");
        Droid       *d1 = new Droid("Commander");

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);
        c.setDroids(2, d1);

        for (size_t i = 0; i < 5; ++i)
        {
            if (c.getDroids(i))
                cr_assert_not_null(c.getDroids(i));
            else
                cr_assert_null(c.getDroids(i));
        }
        cr_assert(c.getSpeed() == 90);
    }

Test(Carrier, TEST_setDroids_pos_three,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");
        Droid       *d1 = new Droid("Commander");

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);
        c.setDroids(3, d1);

        for (size_t i = 0; i < 5; ++i)
        {
            if (c.getDroids(i))
                cr_assert_not_null(c.getDroids(i));
            else
                cr_assert_null(c.getDroids(i));
        }
        cr_assert(c.getSpeed() == 90);
    }

Test(Carrier, TEST_setDroids_pos_four,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");
        Droid       *d1 = new Droid("Commander");

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);
        c.setDroids(4, d1);

        for (size_t i = 0; i < 5; ++i)
        {
            if (c.getDroids(i))
                cr_assert_not_null(c.getDroids(i));
            else
                cr_assert_null(c.getDroids(i));
        }
        cr_assert(c.getSpeed() == 90);
    }

Test(Carrier, TEST_setDroids_all_droids,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");

        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);

        for (size_t i = 0; i < 5; ++i)
        {
            Droid       *d1 = new Droid("Commander");
            c.setDroids(i, d1);
            if (c.getDroids(i))
                cr_assert_not_null(c.getDroids(i));
        }
        cr_assert(c.getSpeed() == 50);
    }

Test(Carrier, TEST_setDroids_at_pos_where_there_is_already_Droid,
    .init = redirect_all_stdout)
    {
        Carrier     c("HellExpress");
        Droid       *d1 = new Droid("Commander");
        Droid       *d2 = new Droid("Sergent");
        for (size_t i = 0; i < 5; ++i)
            cr_assert_null(c.getDroids(i));

        cr_assert(c.getSpeed() == 0);
        c.setDroids(0, d1);
        cr_assert_not_null(c.getDroids(0));
        cr_assert(c.getSpeed() == 90);
        
        c.setDroids(0, d2);
        cr_assert_not_null(c.getDroids(0));
        cr_assert(c.getSpeed() == 90);
    }

Test(Carrier, TEST_left_stream_operator_boarding_one_droids,
    .init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            
            c << d1;
            std::cout << c.getDroids(0)->getId() << std::endl;
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Commander\n"
            "Droid 'Commander' Destroyed\n"
        );
    }

Test(Carrier, TEST_left_stream_operator_boarding_more_droids_than_possible,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");
            Droid       *d6 = new Droid("Intruder");
            
            c << d1 << d2 << d3 << d4 << d5 << d6;
 
            for (size_t i = 0; i < MAX_SIZE; ++i)
            {
                if (c.getDroids(i) != nullptr)
                    std::cout << c.getDroids(i)->getId() << std::endl;
            }
            delete d6;
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "Droid 'Intruder' Activated\n"
            "Commander\n"
            "Sergent\n"
            "Troufiont\n"
            "Groupie\n"
            "BeerHolder\n"
            "Droid 'Intruder' Destroyed\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Sergent' Destroyed\n"
            "Droid 'Troufiont' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_left_stream_operator_boarding_null_droid,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = nullptr;
            
            c << d1 << d2 << d3 << d4 << d5;
 
            for (size_t i = 0; i < MAX_SIZE; ++i)
            {
                if (c.getDroids(i) != nullptr)
                    std::cout << c.getDroids(i)->getId() << std::endl;
            }
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Commander\n"
            "Sergent\n"
            "Troufiont\n"
            "Groupie\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Sergent' Destroyed\n"
            "Droid 'Troufiont' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
        );
    }

Test(Carrier, TEST_left_stream_operator_boarding_droids_update_speed,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");
            
            cr_assert(c.getSpeed() == 0);
            c << d1 << d2 << d3 << d4 << d5;
 
            for (size_t i = 0; i < MAX_SIZE; ++i)
            {
                if (c.getDroids(i) != nullptr)
                    std::cout << c.getDroids(i)->getId() << std::endl;
            }
            // cr_log_warn("%lu", c.getSpeed());
            cr_assert(c.getSpeed() == 50);
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "Commander\n"
            "Sergent\n"
            "Troufiont\n"
            "Groupie\n"
            "BeerHolder\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Sergent' Destroyed\n"
            "Droid 'Troufiont' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_left_stream_operator_boarding_same_droids_should_be_not_possible,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            
            c << d1 << d1 << d1;
 
            for (size_t i = 0; i < MAX_SIZE; ++i)
            {
                if (c.getDroids(i) != nullptr)
                    std::cout << c.getDroids(i)->getId() << std::endl;
            }
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Commander\n"
            "Droid 'Commander' Destroyed\n"
        );
    }

Test(Carrier, TEST_right_stream_operator_unborading_droids,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_right_stream_operator_unborading_more_droids_than_possible,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3 >> d4 >> d5;
            std::cout << c.getSpeed() << std::endl;
            c >> d1 >> d2 >> d3 >> d4 >> d5;
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "0\n"
        );
    }

Test(Carrier, TEST_right_stream_operator_unborading_droids_update_Speed,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c >> d4 >> d5;
            std::cout << c.getSpeed() << std::endl;
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "0\n"
        );
    }

Test(Carrier, TEST_bracket_operator_performs_access_to_Droids_slot,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            cr_assert(c[3]->getId() == "Groupie");
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_bracket_operator_performs_access_to_Droids_slot_and_can_be_replaced_by_other_droid,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c[0] = d1;
            cr_assert(c[0]->getId() == "Commander");
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_bracket_operator_performs_access_to_Droids_slot_and_can_be_replaced_by_nullptr,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c[0] = d1;
            cr_assert(c[0]->getId() == "Commander");
            c[0] = 0;
            cr_assert_null(c[0]);
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_bracket_operator_performs_access_to_Droids_slot_with_wrong_index_return_nullptr,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c[0] = d1;
            cr_assert(c[0]->getId() == "Commander");
            cr_assert_null(c[10]);
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_bitwiseNot_operator_checkup_carrier,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c[0] = d1;
            std::cout << (~c).getSpeed() << std::endl;
            cr_assert(c.getSpeed() == 70);
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "70\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_parenthesis_operator_performs_move_if_enough_Speed_and_Energy_return_true,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c[0] = d1;
            std::cout << (~c).getSpeed() << std::endl;

            cr_assert(c(4, 2) == true);
            cr_assert(c.getSpeed() == 70);
            cr_assert(c.getEnergy() == 222);
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "70\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_parenthesis_operator_return_false_cause_not_enough_energy,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c[0] = d1;
            std::cout << (~c).getSpeed() << std::endl;
            cr_assert(c(4, 2) == true);
            cr_assert(c.getSpeed() == 70);
            cr_assert(c.getEnergy() == 222);
            cr_assert(c(-15, 4) == false);
        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "70\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_parenthesis_operator_return_false_cause_not_enough_speed,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c[0] = d1;
            std::cout << (~c).getSpeed() << std::endl;
            cr_assert(c(4, 2) == true);
            c.setSpeed(0);
            cr_assert(c.getSpeed() == 0);
            cr_assert(c.getEnergy() == 222);
            cr_assert(c(-15, 4) == false);

        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "70\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }

Test(Carrier, TEST_left_stream_operator_display_informations,
.init = redirect_all_stdout)
    {
        {
            Carrier     c("HellExpress");
            Droid       *d1 = new Droid("Commander");
            Droid       *d2 = new Droid("Sergent");
            Droid       *d3 = new Droid("Troufiont");
            Droid       *d4 = new Droid("Groupie");
            Droid       *d5 = new Droid("BeerHolder");

            c << d1 << d2 << d3 << d4 << d5;
            std::cout << c.getSpeed() << d1 << std::endl;
            c >> d1 >> d2 >> d3;
            std::cout << c.getSpeed() << std::endl;
            c[0] = d1;
            std::cout << (~c).getSpeed() << std::endl;
            c(4, 2);
            std::cout << c << std::endl;

        }
        cr_assert_stdout_eq_str(
            "Droid 'Commander' Activated\n"
            "Droid 'Sergent' Activated\n"
            "Droid 'Troufiont' Activated\n"
            "Droid 'Groupie' Activated\n"
            "Droid 'BeerHolder' Activated\n"
            "500\n"
            "80\n"
            "70\n"
            "Carrier 'HellExpress' Droid(s) on-board:\n"
            "[0] : Droid 'Commander', Standing by, 50\n"
            "[1] : Free\n"
            "[2] : Free\n"
            "[3] : Droid 'Groupie', Standing by, 50\n"
            "[4] : Droid 'BeerHolder', Standing by, 50\n"
            "Speed : 70, Energy 222\n"
            "Droid 'Commander' Destroyed\n"
            "Droid 'Groupie' Destroyed\n"
            "Droid 'BeerHolder' Destroyed\n"
        );
    }
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////

// Test(main, Test_main, .init = redirect_all_stdout)
// {
//     {
//         Carrier c("HellExpress");
//         Droid *d1 = new Droid("Commander");
//         Droid *d2 = new Droid("Sergent");
//         Droid *d3 = new Droid("Troufiont");
//         Droid *d4 = new Droid("Groupie");
//         Droid *d5 = new Droid("BeerHolder");
        
        // c << d1 << d2 << d3 << d4 << d5;
        // std::cout << c.getSpeed() << d1 << std::endl;
        // c >> d1 >> d2 >> d3;
        // std::cout << c.getSpeed() << std::endl;
        // c[0] = d1;
        // std::cout << (~c).getSpeed() << std::endl;
        // c(4, 2);
        // std::cout << c << std::endl;
        // c(-15, 4);
        // std::cout << c << std::endl;
        // c[3] = 0;
        // c[4] = 0;
        // (~c)(-15, 4);
        // std::cout << c << std::endl;
//     }
//     cr_assert_stdout_eq_str(
//         "Droid 'Commander' Activated\n"
//         "Droid 'Sergent' Activated\n"
//         "Droid 'Troufiont' Activated\n"
//         "Droid 'Groupie' Activated\n"
//         "Droid 'BeerHolder' Activated\n"
//         "500\n"
//         "80\n"
//         "70\n"
        // "Carrier 'HellExpress' Droid(s) on-board:\n"
        // "[0] : Droid 'Commander', Standing by, 50\n"
        // "[1] : Free\n"
        // "[2] : Free\n"
        // "[3] : Droid 'Groupie', Standing by, 50\n"
        // "[4] : Droid 'BeerHolder', Standing by, 50\n"
        // "Speed : 70, Energy 222\n"
//         "Carrier 'HellExpress' Droid(s) on-board:\n"
//         "[0] : Droid 'Commander', Standing by, 50\n"
//         "[1] : Free\n"
//         "[2] : Free\n"
//         "[3] : Droid 'Groupie', Standing by, 50\n"
//         "[4] : Droid 'BeerHolder', Standing by, 50\n"
//         "Speed : 70, Energy 222\n"
//         "Carrier 'HellExpress' Droid(s) on-board:\n"
//         "[0] : Droid 'Commander', Standing by, 50\n"
//         "[1] : Free\n"
//         "[2] : Free\n"
//         "[3] : Free\n"
//         "[4] : Free\n"
//         "Speed : 90, Energy 13\n"
//         "Droid 'Commander' Destroyed\n"
//     );
// }