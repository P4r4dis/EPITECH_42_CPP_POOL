/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex06/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 8 7:27:43 PM 2025 Paradis
** Last update Thu Jul 9 6:32:02 PM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>


#include "../../include/IObject.hpp"
#include "../../include/UniquePointer.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

UniquePointer createObject(const std::string &name)
{
    UniquePointer   ptr = new TestObject(name);
    return ptr;
}

///////////////////////////////////////////////////////////////////////////////
//                            UniquePointer class                            //
///////////////////////////////////////////////////////////////////////////////
Test(UniquePointer_Constructor, Test_simple_CTOR,
.init = redirect_all_stdout)
{
    UniquePointer   ptr;

    cr_assert_not_null(&ptr);
}

Test(UniquePointer_Custom_Constructor, Test_custom_CTOR,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr(new TestObject("Eccleston"));
        ptr = new TestObject("Tennant");

        cr_assert_not_null(&ptr);
    }
}

Test(UniquePointer_assignement_operator, Test_custom_CTOR,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr(new TestObject("Eccleston"));
        ptr = new TestObject("Tennant");

        cr_assert_not_null(&ptr);
    }
}

Test(UniquePointer_Assignment_operator,
Test_Assigns_new_object_should_display_output,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr;

        ptr = new TestObject("Tennant");
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is dead\n"
    );
}

Test(UniquePointer_Assignment_operator,
Test_Replaces_old_object_and_display_output,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr;
        
        ptr = new TestObject("Tennant");
        ptr = new TestObject("Smith"); 
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Smith is alive\n"
        "Tennant is dead\n"
        "Smith is dead\n"
    );
}

Test(UniquePointer_Assignment_operator,
Test_Self_assign_does_nothing,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr;
        TestObject      *obj = new TestObject("Tennant");

        ptr = obj;
        ptr = obj;
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is dead\n"
    );
}

Test(UniquePointer_touch,
Test_touch_display_stdout,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr = new TestObject("Tennant");

        ptr.touch();
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is touched\n"
        "Tennant is dead\n"
    );
}

Test(UniquePointer_indirection_operator,
Test_indirection_operator,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr(new TestObject("Tennant"));

        (*ptr).touch();
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is touched\n"
        "Tennant is dead\n"
    );
}

Test(UniquePointer_member_of_pointer_operator,
Test_return_a_pointer_to_object,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr(new TestObject("Tennant"));

        ptr->touch();
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is touched\n"
        "Tennant is dead\n"
    );
}

Test(UniquePointer_reset,
Test_should_reset_the_pointer,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr = new TestObject("Tennant");
        UniquePointer   ptr2 = new TestObject("Smith");
        
        ptr.reset(new TestObject("Capaldi"));
        ptr2.reset();
        
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Smith is alive\n"
        "Capaldi is alive\n"
        "Tennant is dead\n"
        "Smith is dead\n"
        "Capaldi is dead\n"
    );
}

Test(UniquePointer_swap,
Test_should_swap_the_pointer,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr = new TestObject("Tennant");
        UniquePointer   ptr2 = new TestObject("Smith");
        
        ptr.reset(new TestObject("Capaldi"));
        ptr.swap(ptr2);
        ptr.touch(); // smith
        ptr2.touch();
        ptr2.reset();
        
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Smith is alive\n"
        "Capaldi is alive\n"
        "Tennant is dead\n"
        "Smith is touched\n"
        "Capaldi is touched\n"
        "Capaldi is dead\n"
        "Smith is dead\n"
    );
}

Test(UniquePointer_Move_CTOR,
Test_should_trasfert_ressources_to_another_object,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr = new TestObject("Tennant");
        UniquePointer   ptr2 = std::move(ptr);
        
        cr_assert(ptr.getUniquePointer() == nullptr);
        cr_assert(ptr2.getUniquePointer() != nullptr);
        
    }
}

Test(UniquePointer_Move_CTOR,
Test_should_transfert_ressources_to_another_object,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr = new TestObject("Tennant");
        UniquePointer   ptr2 = std::move(ptr);
        
        cr_assert(ptr.getUniquePointer() == nullptr);
        cr_assert(ptr2.getUniquePointer() != nullptr);
    }
}

Test(UniquePointer_Move_assignment_operator,
Test_should_assigns_ressources_to_another_object,
.init = redirect_all_stdout)
{
    {
        UniquePointer   ptr = new TestObject("Tennant");
        UniquePointer   ptr2 = new TestObject("Smith");
        
        ptr2 = std::move(ptr);
        cr_assert(ptr.getUniquePointer() != nullptr);
        cr_assert(ptr2.getUniquePointer() != nullptr);
    }
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    {
        UniquePointer   ptr1 = createObject("Charles de Gaulle");
        UniquePointer   ptr2 = createObject("Georges Pompidou");
        // UniquePointer ptr3 = ptr1 ; <- Does not compile
        {
            UniquePointer   tmp(new TestObject("Valery Giscard D'Estaing"));
            // ptr1 = tmp ; <- Does not compile
            ptr1 = std::move(tmp);
        }
        ptr2 = UniquePointer(new TestObject("Francois Mitterrand"));
        ptr1.reset(new TestObject("Jacques Chirac"));
        ptr1->touch();
    }
    cr_assert_stdout_eq_str
    (
        "Charles de Gaulle is alive\n"
        "Georges Pompidou is alive\n"
        "Valery Giscard D'Estaing is alive\n"
        "Charles de Gaulle is dead\n"
        "Francois Mitterrand is alive\n"
        "Georges Pompidou is dead\n"
        "Jacques Chirac is alive\n"
        "Valery Giscard D'Estaing is dead\n"
        "Jacques Chirac is touched\n"
        "Francois Mitterrand is dead\n"
        "Jacques Chirac is dead\n"
    );
}
