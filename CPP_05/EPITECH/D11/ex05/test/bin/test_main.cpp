/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex03/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jun 27 6:16:37 PM 2025 Paradis
** Last update Thu Jul 2 4:30:00 PM 2025 Paradis
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

void touch(IObject *object)
{
    if (object != nullptr)
        object->touch();
}

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
        "Invalid operation on a list\n"
        "Invalid operation on a list\n"
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
        "Invalid operation on a list\n"
        "Invalid operation on a list\n"
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

Test(List_popFront, Test_remove_element_for_empty_list,
.init = redirect_all_stdout)
{
    {
        {
            try
            {
                List    list;

                cr_assert(list.empty() == true);
                list.popFront();
            }
            catch (List::InvalidOperationException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        cr_assert_stdout_eq_str
        (
            "Invalid operation on a list\n"
        );
    }
}

Test(List_popBack, Test_remove_element_for_empty_list,
.init = redirect_all_stdout)
{
    {
        {
            try
            {
                List    list;

                cr_assert(list.empty() == true);
                list.popBack();
            }
            catch (List::InvalidOperationException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        cr_assert_stdout_eq_str
        (
            "Invalid operation on a list\n"
        );
    }
}

Test(List_popBack, Test_delete_first_element_of_the_list,
.init = redirect_all_stdout)
{
    {
        {
            List    list;

            list.pushFront(new TestObject(("Kermit")));

            list.popBack();
            cr_assert(list.size() == 0);
            list.display();
        }
        cr_assert_stdout_eq_str
        (
            "Kermit is alive\n"
            "Kermit is dead\n"
            "List:\n"
            "NULLPTR\n"
            "End List\n"
        );
    }
}

Test(List_popBack, Test_delete_the_last_element_of_the_list,
.init = redirect_all_stdout)
{
    {
        {
            List    list;

            list.pushBack(new TestObject(("Kermit")));
            list.pushBack(new TestObject(("Kermit2")));
            list.pushBack(new TestObject(("Kermit3")));
            list.popBack();
            cr_assert(list.size() == 2);
            list.display();
        }
        cr_assert_stdout_eq_str
        (
            "Kermit is alive\n"
            "Kermit2 is alive\n"
            "Kermit3 is alive\n"
            "Kermit3 is dead\n"
            "List:\n"
            "Kermit is touched\n"
            "Kermit2 is touched\n"
            "End List\n"
            "Kermit is dead\n"
            "Kermit2 is dead\n"
        );
    }
}

Test(List_popBack, Test_delete_the_last_element_nullptr_of_the_list,
.init = redirect_all_stdout)
{
    {
        {
            List    list;

            list.pushBack(new TestObject(("Kermit")));
            list.pushBack(new TestObject(("Kermit2")));
            list.pushBack(new TestObject(("Kermit3")));
            list.pushBack(nullptr);

            list.popBack();
            cr_assert(list.size() == 3);
            list.display();
        }
        cr_assert_stdout_eq_str
        (
            "Kermit is alive\n"
            "Kermit2 is alive\n"
            "Kermit3 is alive\n"
            "List:\n"
            "Kermit is touched\n"
            "Kermit2 is touched\n"
            "Kermit3 is touched\n"
            "End List\n"
            "Kermit is dead\n"
            "Kermit2 is dead\n"
            "Kermit3 is dead\n"

        );
    }
}

Test(List_clear, Test_remove_all_element_of_the_list_and_set_size_to_zero,
.init = redirect_all_stdout)
{
    {
        {
            List    list;

            list.pushBack(new TestObject(("Kermit")));
            list.pushBack(new TestObject(("Kermit2")));
            list.pushBack(new TestObject(("Kermit3")));
            list.pushBack(nullptr);

            cr_assert(list.size() == 4);
            list.display();
            list.clear();
            list.display();
            cr_assert(list.size() == 0);
        }
        cr_assert_stdout_eq_str
        (
            "Kermit is alive\n"
            "Kermit2 is alive\n"
            "Kermit3 is alive\n"
            "List:\n"
            "Kermit is touched\n"
            "Kermit2 is touched\n"
            "Kermit3 is touched\n"
            "NULLPTR\n"
            "End List\n"
            "Kermit is dead\n"
            "Kermit2 is dead\n"
            "Kermit3 is dead\n"
            "List:\n"
            "NULLPTR\n"
            "End List\n"
        );
    }
}

Test(List_forEach, Test_performs_functions_for_easch_elements_of_the_list,
.init = redirect_all_stdout)
{
    {
        {
            List    list;

            list.pushBack(new TestObject(("Kermit")));
            list.pushBack(new TestObject(("Kermit2")));
            list.pushBack(nullptr);
            list.pushBack(new TestObject(("Kermit3")));
            list.forEach(touch);
        }
        cr_assert_stdout_eq_str
        (
            "Kermit is alive\n"
            "Kermit2 is alive\n"
            "Kermit3 is alive\n"
            "Kermit is touched\n"
            "Kermit2 is touched\n"
            "Kermit3 is touched\n"
            "Kermit is dead\n"
            "Kermit2 is dead\n"
            "Kermit3 is dead\n"
        );
    }
}

Test(List_begin, Test_returns_an_iterator_to_the_first_element_of_the_list,
.init = redirect_all_stdout)
{
    {
        {
            List    list;

            list.pushBack(new TestObject(("Kermit")));
            list.pushBack(new TestObject(("Kermit2")));
            list.pushBack(new TestObject(("Kermit3")));

            List::Iterator it = list.begin();
            (*it)->touch();
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
}

Test(List_begin, Test_returns_nullptr,
.init = redirect_all_stdout)
{
    {

            List    list;

            list.pushBack(nullptr);

            List::Iterator it = list.begin();
            cr_assert_null(*it);
    }
}

Test(List_end, Test_returns_an_iterator_to_the_end_of_the_list,
.init = redirect_all_stdout)
{
    {
        List    list;

        list.pushBack(new TestObject(("Kermit")));
        list.pushBack(new TestObject(("Kermit2")));
        list.pushBack(new TestObject(("Kermit3")));

        List::Iterator it = list.end();
        cr_assert_throw(*it, List::Iterator::OutOfRangeException);
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "Kermit3 is alive\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
        "Kermit3 is dead\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            List::Iterator class                           //
///////////////////////////////////////////////////////////////////////////////

Test(List__Iterator_CTOR,
Test_CTOR_isDefined,
.init = redirect_all_stdout)
{
    {
        {
            List::Iterator it;

            cr_assert_not_null(&it);
        }
    }
}

Test(List__Iterator_indirection_Operator,
Test_throw_exception,
.init = redirect_all_stdout)
{
    {
        {
            List::Iterator it;

            cr_assert_throw(*it, List::Iterator::OutOfRangeException);
        }
    }
}

Test(List__Iterator_indirection_Operator,
Test_throw_exception_and_display_msg_stderr,
.init = redirect_all_stdout)
{
    {
        try
        {
            List::Iterator it;

            cr_assert_null(*it);
        }
        catch (List::Iterator::OutOfRangeException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Iterator out of range\n"
    );
}

Test(List__Iterator_Increment_Operator,
Test_advances_the_iterator_to_the_next_node,
.init = redirect_all_stdout)
{
    {
        List    list;

        list.pushBack(new TestObject(("Kermit")));
        list.pushBack(new TestObject(("Kermit2")));
        list.pushBack(new TestObject(("Kermit3")));

        List::Iterator it = list.begin();
        if (*it != nullptr)
            (*it)->touch();
        ++it;
        if (*it != nullptr)
            (*it)->touch();
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "Kermit3 is alive\n"
        "Kermit is touched\n"
        "Kermit2 is touched\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
        "Kermit3 is dead\n"
    );
}

Test(List__Iterator_Increment_Operator,
Test_try_to_increment_nullptr_node_and_should_to_throw_exception,
.init = redirect_all_stdout)
{
    {
        List    list;

        list.pushBack(new TestObject(("Kermit")));
        list.pushBack(new TestObject(("Kermit2")));
        list.pushBack(new TestObject(("Kermit3")));

        List::Iterator it = list.end();
        cr_assert_throw(++it, List::Iterator::OutOfRangeException);
    }
    cr_assert_stdout_eq_str
    (
        "Kermit is alive\n"
        "Kermit2 is alive\n"
        "Kermit3 is alive\n"
        "Kermit is dead\n"
        "Kermit2 is dead\n"
        "Kermit3 is dead\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, test_main, .init = redirect_all_stdout)
{
    // {
    //     try {
    //         List    list1;

    //         list1.pushBack(new TestObject("Naruto"));
    //         list1.pushBack(new TestObject("Sasuke"));
    //         list1.pushBack(new TestObject("Sakura"));
    //         list1.pushBack(nullptr);
    //         list1.pushBack(new TestObject("Serge"));

    //         for (List::Iterator it = list1.begin(); it != list1.end(); ++it)
    //             if (*it != nullptr)
    //                 (*it)->touch();

    //         list1.erase(list1.erase(list1.begin()));
    //         list1.insert(list1.begin(), new TestObject("Orochimaru"));
    //         list1.insert(list1.end(), new TestObject("Tsunade"));
    //         list1.forEach(touch);

    //         List    list2;
            
    //         list2.pushFront(new TestObject("Jiraya"));
    //         list1.erase(list2.begin());
    //     } catch (const List::Iterator::OutOfRangeException &e) {
    //         std::cout << "Iterator out of range" << std::endl;
    //     } catch (const List::InvalidIteratorException &e) {
    //         std::cout << "Invalid iterator" << std::endl;
    //     }
    // }
    // cr_assert_stdout_eq_str
    // (
    //     "Naruto is alive\n"
    //     "Sasuke is alive\n"
    //     "Sakura is alive\n"
    //     "Serge is alive\n"
    //     "Naruto is touched\n"
    //     "Sasuke is touched\n"
    //     "Sakura is touched\n"
    //     "Serge is touched\n"
    //     "Naruto is dead\n"
    //     "Sasuke is dead\n"
    //     "Orochimaru is alive\n"
    //     "Tsunade is alive\n"
    //     "Orochimaru is touched\n"
    //     "Sakura is touched\n"
    //     "Serge is touched\n"
    //     "Tsunade is touched\n"
    //     "Jiraya is alive\n"
    //     "Jiraya is dead\n"
    //     "Orochimaru is dead\n"
    //     "Sakura is dead\n"
    //     "Serge is dead\n"
    //     "Tsunade is dead\n"
    //     "Invalid iterator\n"
    // );
}
