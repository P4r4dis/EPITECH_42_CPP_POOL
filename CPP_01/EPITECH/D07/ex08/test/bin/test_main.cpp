/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex08/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 5 3:53:37 PM 2025 Paradis
** Last update Tue Feb 10 7:23:21 PM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/KreogCom.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


Test(KreogCom_class, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    KreogCom    k(42, 42, 101010);

    cr_assert_not_null(&k);
}

Test(KreogCom_class, Test_CTOR_print_msg_when_CTOR_is_created_and_destroyed,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_addCom_func_which_adds_a_new_node_to_the_linked_list,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_addCom_func_which_adds_a_several_new_nodes_to_the_linked_list,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_getCom_func_return_nullptr_because_KreogCom_is_not_linked,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        cr_assert(k.getCom() == nullptr);

    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_getCom_func_return_ptr_to_the_KreogCom_linked_to_the_current_instance,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);

        cr_assert(k.getCom() != nullptr);
        cr_assert(k.getCom()->getX() == 56);

    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_getCom_func_return_ptr_to_the_correct_KreogCom_linked_to_current_instance,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);

        cr_assert(k.getCom() != nullptr);
        cr_assert(k.getCom()->getX() == 73);

    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_removeCom_func_delete_the_current_KreogCom_linked,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);

        k.removeCom();
        k.removeCom();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_ping_func_prints_current_KreogCom_informations_to_stdout,
.init = redirect_all_stdout)
{
    {
        KreogCom    k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);

        k.ping();
        
        k.removeCom();
        k.removeCom();
    }
    cr_assert_stdout_eq_str(
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 101010 currently at 42 42\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}

Test(KreogCom_class,
Test_locateSquad_func_prints_linked_and_current_KreogCom_infos_to_stdout,
.init = redirect_all_stdout)
    {
        {
            KreogCom    k(42, 42, 101010);
    
            k.addCom(56, 25, 65);
            k.addCom(73, 34, 51);
    
            k.locateSquad();
            
            k.removeCom();
            k.removeCom();
        }
        cr_assert_stdout_eq_str(
            "KreogCom 101010 initialized\n"
            "KreogCom 65 initialized\n"
            "KreogCom 51 initialized\n"
            "KreogCom 51 currently at 73 34\n"
            "KreogCom 65 currently at 56 25\n"
            "KreogCom 101010 currently at 42 42\n"
            "KreogCom 51 shutting down\n"
            "KreogCom 65 shutting down\n"
            "KreogCom 101010 shutting down\n"
        );
    }

///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    {
        KreogCom k(42, 42, 101010);

        k.addCom(56, 25, 65);
        k.addCom(73, 34, 51);

        k.locateSquad();

        k.removeCom();
        k.removeCom();
    }
    cr_assert_stdout_eq_str
    (
        "KreogCom 101010 initialized\n"
        "KreogCom 65 initialized\n"
        "KreogCom 51 initialized\n"
        "KreogCom 51 currently at 73 34\n"
        "KreogCom 65 currently at 56 25\n"
        "KreogCom 101010 currently at 42 42\n"
        "KreogCom 51 shutting down\n"
        "KreogCom 65 shutting down\n"
        "KreogCom 101010 shutting down\n"
    );
}
