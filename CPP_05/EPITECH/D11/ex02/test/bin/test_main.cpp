/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex02/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jun 26 4:20:12 PM 2025 Paradis
** Last update Fri Jun 26 8:45:33 PM 2025 Paradis
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
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    // UniquePointer   ptr1;
    // UniquePointer   ptr2(new TestObject("Eccleston"));
    // // UniquePointer ptr3 ( ptr2 ) ; <- Does not compile !
    // ptr1 = new TestObject("Tennant");
    // ptr2 = new TestObject("Smith");
    // ptr1->touch();
    // (*ptr2).touch();

    // {
    //     UniquePointer   ptr4(new TestObject("Whittaker"));
    // }

    // ptr1.reset(new TestObject("Capaldi"));
    // ptr1.swap(ptr2);
    // // ptr1 = ptr2 ; <- Does not compile !
    // ptr2.reset();
}
