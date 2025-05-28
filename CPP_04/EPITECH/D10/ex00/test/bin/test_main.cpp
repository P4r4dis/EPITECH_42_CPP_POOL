/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 3:53:48 PM 2025 Paradis
** Last update Thu May 28 6:21:53 PM 2025 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/IFruit.hpp"
#include "../../include/AFruit.hpp"
#include "../../include/ABerry.hpp"
#include "../../include/ACitrus.hpp"
#include "../../include/ANut.hpp"
#include "../../include/Lemon.hpp"
#include "../../include/Orange.hpp"
#include "../../include/Strawberry.hpp"
#include "../../include/Almond.hpp"


void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
// class Dummy : public AFruit
// {
//     public:
//         Dummy(const std::string& name, unsigned int vitamins, bool peeled = false)  :   AFruit(name, vitamins)
//         { _name = name; _vitamins = vitamins; _peeled = peeled;}
//         ~Dummy() {}
//     private:
// };

class Dummy : public AFruit
{
    public:
        Dummy()  :   AFruit("DummyFruit", 10)
        { _name = "DummyFruit"; _vitamins = 10; _peeled = false;}
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

class DummyCitrus : public ACitrus
{
    public:
        DummyCitrus() : ACitrus("DummyCitrus", 4) {}
        ~DummyCitrus() {}
    private:
};

class DummyNut : public ANut
{
    public:
        DummyNut() : ANut("DummyNut", 2) {}
        ~DummyNut() {}
    private:
};

Test(IFruit, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    {
        Dummy fruit;

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
        Dummy fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(AFruit, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Dummy fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 10);
    }
}

Test(AFruit, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit;

        cr_assert(fruit.getName() == "DummyFruit");
    }
}

Test(AFruit, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(AFruit, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(AFruit, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit;

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
        Dummy fruit;

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
//                            ACitrus class                                   //
///////////////////////////////////////////////////////////////////////////////
Test(ACitrus, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        DummyCitrus fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(ACitrus, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        DummyCitrus fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 4);
    }
}

Test(ACitrus, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        DummyCitrus fruit;

        cr_assert(fruit.getName() == "DummyCitrus");
    }
}

Test(ACitrus, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        DummyCitrus fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(ACitrus, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        DummyCitrus fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(ACitrus, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        DummyCitrus fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(ACitrus, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        DummyCitrus fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"DummyCitrus\", vitamins: 0, peeled: false]\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            ANut class                                     //
///////////////////////////////////////////////////////////////////////////////
Test(ANut, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        DummyNut fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(ANut, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        DummyNut fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 2);
    }
}

Test(ANut, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        DummyNut fruit;

        cr_assert(fruit.getName() == "DummyNut");
    }
}

Test(ANut, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        DummyNut fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(ANut, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        DummyNut fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(ANut, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        DummyNut fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(ANut, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        DummyNut fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"DummyNut\", vitamins: 0, peeled: false]\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Lemon class                                   //
///////////////////////////////////////////////////////////////////////////////
Test(Lemon, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        Lemon fruit;

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "lemon");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Lemon, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        Lemon fruit("lemon", 4);

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "lemon");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Lemon, TEST_assignment_operator, .init = redirect_all_stdout)
{
    {
        Lemon  fruit("CopyLemon", 4);
        Lemon  lemon;

        lemon = fruit;
        cr_assert(lemon.getVitamins() == fruit.getVitamins());
        cr_assert(lemon.getName() == fruit.getName());
        cr_assert(lemon.isPeeled() == fruit.isPeeled());
    }
}

Test(Lemon, TEST_assignment_operator_self_assignment,
.init = redirect_all_stdout)
{
    {
        Lemon  fruit("CopyLemon", 4);

        fruit = fruit;
        cr_assert(fruit.getVitamins() == fruit.getVitamins());
        cr_assert(fruit.getName() == fruit.getName());
        cr_assert(fruit.isPeeled() == fruit.isPeeled());
    }
}

Test(Lemon, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        Lemon fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(Lemon, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Lemon fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 4);
    }
}

Test(Lemon, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        Lemon fruit;

        cr_assert(fruit.getName() == "lemon");
    }
}

Test(Lemon, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        Lemon fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Lemon, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        Lemon fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Lemon, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        Lemon fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(Lemon, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Lemon fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"lemon\", vitamins: 0, peeled: false]\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Orange class                                   //
///////////////////////////////////////////////////////////////////////////////
Test(Orange, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        Orange fruit;

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "orange");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Orange, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        Orange fruit("orange", 7);

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "orange");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Orange, TEST_assignment_operator, .init = redirect_all_stdout)
{
    {
        Orange  fruit("CopyOrange", 7);
        Orange  orange;

        orange = fruit;
        cr_assert(orange.getVitamins() == fruit.getVitamins());
        cr_assert(orange.getName() == fruit.getName());
        cr_assert(orange.isPeeled() == fruit.isPeeled());
    }
}

Test(Orange, TEST_assignment_operator_self_assignment,
.init = redirect_all_stdout)
{
    {
        Orange  fruit("CopyOrange", 7);

        fruit = fruit;
        cr_assert(fruit.getVitamins() == fruit.getVitamins());
        cr_assert(fruit.getName() == fruit.getName());
        cr_assert(fruit.isPeeled() == fruit.isPeeled());
    }
}

Test(Orange, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        Orange fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(Orange, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Orange fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 7);
    }
}

Test(Orange, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        Orange fruit;

        cr_assert(fruit.getName() == "orange");
    }
}

Test(Orange, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        Orange fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Orange, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        Orange fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Orange, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        Orange fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(Orange, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Orange fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"orange\", vitamins: 0, peeled: false]\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Strawberry class                               //
///////////////////////////////////////////////////////////////////////////////
Test(Strawberry, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        Strawberry fruit;

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 6);
        cr_assert(fruit.getName() == "strawberry");
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Strawberry, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        Strawberry fruit("strawberry", 6);

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 6);
        cr_assert(fruit.getName() == "strawberry");
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Strawberry, TEST_assignment_operator, .init = redirect_all_stdout)
{
    {
        Strawberry  fruit("CopyStrawberry", 6);
        Strawberry  orange;

        orange = fruit;
        cr_assert(orange.getVitamins() == fruit.getVitamins());
        cr_assert(orange.getName() == fruit.getName());
        cr_assert(orange.isPeeled() == fruit.isPeeled());
    }
}

Test(Strawberry, TEST_assignment_operator_self_assignment,
.init = redirect_all_stdout)
{
    {
        Strawberry  fruit("CopyStrawberry", 6);

        fruit = fruit;
        cr_assert(fruit.getVitamins() == fruit.getVitamins());
        cr_assert(fruit.getName() == fruit.getName());
        cr_assert(fruit.isPeeled() == fruit.isPeeled());
    }
}

Test(Strawberry, TEST_getVitamins_return_vitamins_even_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        Strawberry fruit;

        cr_assert(fruit.getVitamins() == 6);
    }
}

Test(Strawberry, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Strawberry fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 6);
    }
}

Test(Strawberry, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        Strawberry fruit;

        cr_assert(fruit.getName() == "strawberry");
    }
}

Test(Strawberry, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        Strawberry fruit;

        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Strawberry, TEST_peel_peel_fruit_is_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        Strawberry fruit;

        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Strawberry, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        Strawberry fruit;

        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(Strawberry, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Strawberry fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"strawberry\", vitamins: 6, peeled: true]\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Almond class                                      //
///////////////////////////////////////////////////////////////////////////////
Test(Almond, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        Almond fruit;

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "almond");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Almond, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        Almond fruit("almond", 2);

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "almond");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Almond, TEST_assignment_operator, .init = redirect_all_stdout)
{
    {
        Almond  fruit("CopyNut", 2);
        Almond  nut;

        nut = fruit;
        cr_assert(nut.getVitamins() == fruit.getVitamins());
        cr_assert(nut.getName() == fruit.getName());
        cr_assert(nut.isPeeled() == fruit.isPeeled());
    }
}

Test(Almond, TEST_assignment_operator_self_assignment,
.init = redirect_all_stdout)
{
    {
        Almond  fruit("CopyNut", 2);

        fruit = fruit;
        cr_assert(fruit.getVitamins() == fruit.getVitamins());
        cr_assert(fruit.getName() == fruit.getName());
        cr_assert(fruit.isPeeled() == fruit.isPeeled());
    }
}

Test(Almond, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        Almond fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(Almond, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Almond fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 2);
    }
}

Test(Almond, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        Almond fruit;

        cr_assert(fruit.getName() == "almond");
    }
}

Test(Almond, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        Almond fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Almond, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        Almond fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Almond, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        Almond fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(Almond, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Almond fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {       
        Orange          o;
        Strawberry      s;
        const Almond    a;
        IFruit&         f = o;

        std::cout   << o.getName() << ": " << o.getVitamins() << " vitamins" << std::endl;
        std::cout   << s << std::endl;
        std::cout   << a << std::endl;

        o.peel();
        std::cout   << f << std::endl;
    }

    cr_assert_stdout_eq_str(
        "orange: 0 vitamins\n"
        "[name: \"strawberry\", vitamins: 6, peeled: true]\n"
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
        "[name: \"orange\", vitamins: 7, peeled: true]\n"
    );
}