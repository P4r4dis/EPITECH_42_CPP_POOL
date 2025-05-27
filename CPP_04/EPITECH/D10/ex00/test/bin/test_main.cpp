/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 3:53:48 PM 2025 Paradis
** Last update Wed May 27 8:23:40 PM 2025 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/IFruit.hpp"
#include "../../include/AFruit.hpp"
#include "../../include/ABerry.hpp"
void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
class Dummy : public AFruit
{
    public:
        Dummy(const std::string& name, unsigned int vitamins, bool peeled = false)  :   AFruit(name, vitamins)
        { _name = name; _vitamins = vitamins; _peeled = peeled;}
        ~Dummy() {}
    private:
};

class DummyBerry : public ABerry
{
    public:
        DummyBerry() : ABerry("DummyBerry", 6, true) {}
        ~DummyBerry() {}
    private:
};
Test(IFruit, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    {
        Dummy fruit("DummyFruit", 10);

        std::cout << fruit << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "[name: \"DummyFruit\", vitamins: 0, peeled: false]\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            AFruit class                                   //
///////////////////////////////////////////////////////////////////////////////
Test(AFruit, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        Dummy fruit("DummyFruit", 10);

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(AFruit, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Dummy fruit("DummyFruit", 10);

        fruit.peel();
        cr_assert(fruit.getVitamins() == 10);
    }
}

Test(AFruit, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit("DummyFruit", 10);

        cr_assert(fruit.getName() == "DummyFruit");
    }
}

Test(AFruit, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit("DummyFruit", 10);

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(AFruit, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit("DummyFruit", 10);

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(AFruit, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit("DummyFruit", 10);

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(AFruit, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit("DummyFruit", 10);

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"DummyFruit\", vitamins: 0, peeled: false]\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            ABerry class                                   //
///////////////////////////////////////////////////////////////////////////////

Test(ABerry, TEST_getVitamins_return_vitamins,
.init = redirect_all_stdout)
{
    {
        DummyBerry fruit;

        cr_assert(fruit.getVitamins() == 6);
    }
}

Test(ABerry, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        DummyBerry fruit;

        cr_assert(fruit.getName() == "DummyBerry");
    }
}

Test(ABerry, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        DummyBerry fruit;

        cr_assert(fruit.isPeeled() == true);
    }
}

Test(ABerry, TEST_peel_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        DummyBerry fruit;

        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(ABerry, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        DummyBerry fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"DummyBerry\", vitamins: 6, peeled: true]\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
// Test(main, Test_main, .init = redirect_all_stdout)
// {
//     {       
//         Orange          o;
//         Strawberry      s;
//         const Almond    a;
//         IFruit&         f = o;

//         std::cout   << o.getName() << ": " << o.getVitamins() << " vitamins" << std::endl;
//         std::cout   << s << std::endl;
//         std::cout   << a << std::endl;

//         o.peel();
//         std::cout   << f << std::endl;
//     }

//     cr_assert_stdout_eq_str(
//         "orange: 0 vitamins\n"
//         "[name: \"strawberry\", vitamins: 6, peeled: true]\n"
//         "[name: \"almond\", vitamins: 0, peeled: false]\n"
//         "[name: \"orange\", vitamins: 7, peeled: true]\n"
//     );
// }