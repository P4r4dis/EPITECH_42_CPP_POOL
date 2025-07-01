/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex04/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 1 4:11:08 PM 2025 Paradis
** Last update Wed Jul 1 7:06:35 PM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>


#include "../../include/IObject.hpp"
#include "../../include/SharedPointer.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

///////////////////////////////////////////////////////////////////////////////
//                            SharedPointer class                            //
///////////////////////////////////////////////////////////////////////////////
Test(SharedPointer_Constructor, Test_simple_CTOR,
.init = redirect_all_stdout)
{
    SharedPointer   ptr;

    cr_assert_not_null(&ptr);
}

Test(SharedPointer_Custom_Constructor, Test_custom_CTOR,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr(new TestObject("Eccleston"));
        ptr = new TestObject("Tennant");

        cr_assert_not_null(&ptr);
    }
}

Test(SharedPointer_Copy_Constructor, Test_Copy_CTOR,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr(new TestObject("Eccleston"));
        SharedPointer   ptr2(ptr);

        ptr2.touch();
    }
    cr_assert_stdout_eq_str
    (
        "Eccleston is alive\n"
        "Eccleston is touched\n"
        "Eccleston is dead\n"
    );
}

Test(SharedPointer_assignement_operator, Test_Assigns_new_object,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr(new TestObject("Eccleston"));
        SharedPointer   ptr2(new TestObject("Smith"));

        ptr = ptr2;

        cr_assert_not_null(&ptr);
    }
}

Test(SharedPointer_Assignment_operator,
Test_Assigns_new_object_should_display_output,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr(new TestObject("Eccleston"));
        SharedPointer   ptr2(new TestObject("Smith"));

        ptr = ptr2;
    }
    cr_assert_stdout_eq_str
    (
        "Eccleston is alive\n"
        "Smith is alive\n"
        "Eccleston is dead\n"
        "Smith is dead\n"
    );
}

Test(SharedPointer_assignement_operator, Test_assigns_pointer,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr(new TestObject("Eccleston"));
        
        ptr = new TestObject("Tennant");

        cr_assert_not_null(&ptr);
    }
}

Test(SharedPointer_Assignment_operator,
Test_Assigns_new_pointer_should_display_output,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr;

        ptr = new TestObject("Tennant");
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is dead\n"
    );
}

Test(SharedPointer_Assignment_operator,
Test_Replaces_old_pointer_and_display_output,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr;
        
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

Test(SharedPointer_Assignment_operator,
Test_Self_pointer_assignment_does_nothing,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr;
        TestObject      *obj = new TestObject("Tennant");

        ptr = obj;
        ptr = obj;
        ptr = ptr;
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is dead\n"
    );
}

Test(SharedPointer_touch,
Test_touch_display_stdout,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr = new TestObject("Tennant");

        ptr.touch();
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is touched\n"
        "Tennant is dead\n"
    );
}

Test(SharedPointer_indirection_operator,
Test_indirection_operator,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr(new TestObject("Tennant"));

        (*ptr).touch();
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is touched\n"
        "Tennant is dead\n"
    );
}

Test(SharedPointer_member_of_pointer_operator,
Test_return_a_pointer_to_object,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr(new TestObject("Tennant"));

        ptr->touch();
    }
    cr_assert_stdout_eq_str
    (
        "Tennant is alive\n"
        "Tennant is touched\n"
        "Tennant is dead\n"
    );
}

Test(SharedPointer_reset,
Test_should_reset_the_pointer,
.init = redirect_all_stdout)
{
    {
        SharedPointer ptr1;
        SharedPointer ptr2(new TestObject( "O'Neill"));
        SharedPointer ptr3(ptr2);
        
        ptr1 = ptr3;
        ptr2->touch();
        std::cout << ptr1 . use_count () << std::endl;
        ptr1.reset(new TestObject("Carter"));
        std::cout << ptr1.use_count() << std::endl;       
    }
    cr_assert_stdout_eq_str
    (
        "O'Neill is alive\n"
        "O'Neill is touched\n"
        "3\n"
        "Carter is alive\n"
        "1\n"
        "O'Neill is dead\n"
        "Carter is dead\n"
    );
}

Test(SharedPointer_swap,
Test_should_swap_the_pointer,
.init = redirect_all_stdout)
{
    {
        SharedPointer   ptr = new TestObject("Tennant");
        SharedPointer   ptr2 = new TestObject("Smith");
        
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

Test(SharedPointer_use_count,
Test_should_return_the_number_of_instance_of_sharedPointer,
.init = redirect_all_stdout)
{
    {
        SharedPointer ptr1;
        SharedPointer ptr2(new TestObject( "O'Neill"));
        SharedPointer ptr3(ptr2);
        
        ptr1 = ptr3;
        ptr2->touch();
        cr_assert(ptr1.use_count() == 3);
        ptr1.reset(new TestObject("Carter"));
        cr_assert(ptr1.use_count() == 1);
        ptr3.swap(ptr1);
        (*ptr3).touch();
        ptr1.reset();
        cr_assert(ptr1.use_count() == 0);
    }
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    {
        SharedPointer ptr1;
        SharedPointer ptr2(new TestObject( "O'Neill"));
        SharedPointer ptr3(ptr2);
        
        ptr1 = ptr3;
        ptr2->touch();
        std::cout << ptr1 . use_count () << std::endl;
        ptr1.reset(new TestObject("Carter"));
        std::cout << ptr1.use_count() << std::endl;
        ptr3.swap(ptr1);
        (*ptr3).touch();
        ptr1.reset();
        std::cout << ptr1.use_count() << std::endl;
        ptr2 = new TestObject("Jackson");
    }
    cr_assert_stdout_eq_str
    (
        "O'Neill is alive\n"
        "O'Neill is touched\n"
        "3\n"
        "Carter is alive\n"
        "1\n"
        "Carter is touched\n"
        "0\n"
        "Jackson is alive\n"
        "O'Neill is dead\n"
        "Carter is dead\n"
        "Jackson is dead\n"
    );
}
