/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex03/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jun 27 6:16:37 PM 2025 Paradis
** Last update Tue Jun 30 8:51:28 PM 2025 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>


#include "../../include/IObject.hpp"
#include "../../include/List.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// void touch(IObject *object)
// {
//     if (object != nullptr)
//         object->touch();
// }

Test(List_Constructor, Test_Constructor, .init = redirect_all_stdout)
{
    List    list;

    cr_assert_not_null(&list);
}

Test(List_display, Test_display_all_elements_of_the_list,
.init = redirect_all_stdout)
{
    List    list;

    list.display();
    cr_assert_stdout_eq_str
    (
        "List:\n"
        "NULLPTR\n"
        "End List\n"
    );
}

Test(List_pushBack, Test_if_List_is_empty_add_element_at_the_beginning,
.init = redirect_all_stdout)
{
    {
        List    list;

        list.pushBack(new TestObject(("Kermit")));
        list.display();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "List:\n"
        "Kermit is touched\n"
        "End List\n"
        "Kermit is dead\n"
    );
}

Test(List_pushBack, Test_add_element_of_the_list_at_the_end,
.init = redirect_all_stdout)
{
    {
        List    list;

        list.pushBack(new TestObject(("Kermit")));
        list.pushBack(new TestObject(("Kermit2")));
        list.display();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "List:\n"
        "Kermit is touched\n"
        "Kermit2 is touched\n"
        "End List\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
    );
}

Test(List_pushBack, Test_add_NULL_element_of_the_list_at_the_end,
.init = redirect_all_stdout)
{
    {
        List    list;

        list.pushBack(new TestObject(("Kermit")));
        list.pushBack(nullptr);
        list.pushBack(new TestObject(("Kermit2")));
        list.display();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "List:\n"
        "Kermit is touched\n"
        "NULLPTR\n"
        "Kermit2 is touched\n"
        "End List\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
    );
}

Test(List_empty, Test_should_return_true,
.init = redirect_all_stdout)
{
    {
        List    list;

        cr_assert(list.empty() == true);
    }
}

Test(List_empty, Test_should_return_false,
.init = redirect_all_stdout)
{
    {
        List    list;

        cr_assert(list.empty() == true);

        list.pushBack(new TestObject(("Kermit")));

        cr_assert(list.empty() == false);
    }
}

Test(List_size, Test_should_return_zero,
.init = redirect_all_stdout)
{
    {
        List    list;

        cr_assert(list.size() == 0);
    }
}

Test(List_size, Test_should_not_return_zero,
.init = redirect_all_stdout)
{
    {
        List    list;

        cr_assert(list.size() == 0);

        list.pushBack(new TestObject(("Kermit")));

        cr_assert(list.size() == 1);
    }
}

Test(List_front, Test_should_throw_exception_if_first_node_is_null,
.init = redirect_all_stdout)
{
    {
        try
        {
            List    list;
            list.front();
        } catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            const List    list;
            list.front();
        } catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    cr_assert_stdout_eq_str
    (
        "Error: Invalid operation\n"
        "Error: Invalid operation\n"
    );
}

Test(List_front, Test_return_first_element_of_the_list,
.init = redirect_all_stdout)
{
    {

        List    list;

        list.pushBack(new TestObject(("Kermit")));
        list.pushBack(new TestObject(("Kermit2")));
        list.pushBack(new TestObject(("Kermit3")));

        IObject *tmp = list.front();
        
        tmp->touch();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "Kermit3 is alive\n"
        "Kermit is touched\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
        "Kermit3 is dead\n"
    );
}

Test(List_front, Test_return_first_element_of_the_const_list,
.init = redirect_all_stdout)
{
    {
            List list;

        list.pushBack(new TestObject("Kermit"));
        list.pushBack(new TestObject("Kermit2"));
        list.pushBack(new TestObject("Kermit3"));

        const List &ref = list;  // convert to const by reference

        IObject *tmp = ref.front();  // calls const verion of front()

        tmp->touch();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "Kermit3 is alive\n"
        "Kermit is touched\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
        "Kermit3 is dead\n"
    );
}

Test(List_back, Test_should_throw_exception_if_list_is_empty,
.init = redirect_all_stdout)
{
    {
        try
        {
            List    list;
            list.back();
        } catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            const List    list;
            list.back();
        } catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    cr_assert_stdout_eq_str
    (
        "Error: Invalid operation\n"
        "Error: Invalid operation\n"
    );
}

Test(List_back, Test_return_the_last_element_of_the_list,
.init = redirect_all_stdout)
{
    {

        List    list;

        list.pushBack(new TestObject(("Kermit")));
        list.pushBack(new TestObject(("Kermit2")));
        list.pushBack(new TestObject(("Kermit3")));

        IObject *tmp = list.back();
        
        tmp->touch();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "Kermit3 is alive\n"
        "Kermit3 is touched\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
        "Kermit3 is dead\n"
    );
}

Test(List_back, Test_return_the_last_element_of_the_const_list,
.init = redirect_all_stdout)
{
    {
            List list;

        list.pushBack(new TestObject("Kermit"));
        list.pushBack(new TestObject("Kermit2"));
        list.pushBack(new TestObject("Kermit3"));

        const List &ref = list;  // convert to const by reference

        IObject *tmp = ref.back();  // calls const verion of front()

        tmp->touch();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "Kermit3 is alive\n"
        "Kermit3 is touched\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
        "Kermit3 is dead\n"
    );
}

Test(List_pushFront, Test_if_List_is_empty_add_element_at_the_beginning,
.init = redirect_all_stdout)
{
    {
        List    list;

        list.pushFront(new TestObject(("Kermit")));
        cr_assert(list.size() == 1);
        list.display();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "List:\n"
        "Kermit is touched\n"
        "End List\n"
        "Kermit is dead\n"
    );
}

Test(List_pushFront, Test_add_element_at_the_begenning_of_the_list,
.init = redirect_all_stdout)
{
    {
        List    list;

        list.pushFront(new TestObject(("Kermit")));
        list.pushFront(new TestObject(("Kermit2")));
        list.pushFront(new TestObject(("Kermit3")));
        cr_assert(list.size() == 3);
        list.display();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "Kermit3 is alive\n"
        "List:\n"
        "Kermit3 is touched\n"
        "Kermit2 is touched\n"
        "Kermit is touched\n"
        "End List\n"
        "Kermit3 is dead\n"
        "Kermit2 is dead\n"
        "Kermit is dead\n"
    );
}

Test(List_pushFront, Test_add_NULL_element_at_the_beginning_of_the_list,
.init = redirect_all_stdout)
{
    {
        {
            List    list;

            list.pushFront(new TestObject(("Kermit")));
            list.pushFront(new TestObject(("Kermit2")));
            list.pushFront(new TestObject(("Kermit3")));
            list.pushFront(nullptr);
            cr_assert(list.size() == 4);
            list.display();
        }
        cr_assert_stdout_eq_str
        (
            "Kermit is alive\n"
            "Kermit2 is alive\n"
            "Kermit3 is alive\n"
            "List:\n"
            "NULLPTR\n"
            "Kermit3 is touched\n"
            "Kermit2 is touched\n"
            "Kermit is touched\n"
            "End List\n"
            "Kermit3 is dead\n"
            "Kermit2 is dead\n"
            "Kermit is dead\n"
        );
    }
}

Test(List_popFront, Test_delete_first_element_of_the_list,
.init = redirect_all_stdout)
{
    {
        {
            List    list;

            list.pushFront(new TestObject(("Kermit")));
            list.pushFront(new TestObject(("Kermit2")));
            list.pushFront(new TestObject(("Kermit3")));
            list.pushFront(nullptr);
            list.popFront();
            cr_assert(list.size() == 3);
            list.display();
        }
        cr_assert_stdout_eq_str
        (
            "Kermit is alive\n"
            "Kermit2 is alive\n"
            "Kermit3 is alive\n"
            "List:\n"
            "Kermit3 is touched\n"
            "Kermit2 is touched\n"
            "Kermit is touched\n"
            "End List\n"
            "Kermit3 is dead\n"
            "Kermit2 is dead\n"
            "Kermit is dead\n"
        );
    }
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    // {
    //     try {
    //         List    list;
    //         list.pushBack(new TestObject("Kermit"));
    //         list.pushBack(new TestObject("Miss Piggy"));
    //         list.pushFront(nullptr);
    //         list.front() = new TestObject("Fozzie");
    //         list.pushBack(nullptr);
    //         list.forEach(touch);
    //         list.clear();
    //         list.popBack();
    //         list.pushFront(new TestObject("Gonzo"));
    //     } catch (const List::InvalidOperationException &e) {
    //         std::cout << "Invalid operation on a list" << std::endl;
    //     }
    // }
    // cr_assert_stdout_eq_str
    // (

    // );
}
