/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:35:25 PM 2025 Paradis
** Last update Thu Jun 11 8:27:26 PM 2025 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>
#include <valgrind/valgrind.h>

#include "../../include/IFruit.hpp"
#include "../../include/AFruit.hpp"
#include "../../include/ABerry.hpp"
#include "../../include/ACitrus.hpp"
#include "../../include/ANut.hpp"
#include "../../include/Lemon.hpp"
#include "../../include/Orange.hpp"
#include "../../include/Strawberry.hpp"
#include "../../include/Almond.hpp"
#include "../../include/FruitBox.hpp"
#include "../../include/Grapefruit.hpp"
#include "../../include/BloodOrange.hpp"
#include "../../include/Raspberry.hpp"
#include "../../include/Coconut.hpp"
#include "../../include/FruitUtils.hpp"
#include "../../include/FruitFactory.hpp"
#include "../../include/FruitMixer.hpp"



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

class TestFruit : public AFruit
{
    public:
        TestFruit(const std::string& name)
            : AFruit(name, 0)
        {
            _vitamins = 0;
            _peeled = false;
            std::cout << _name << " lives." << std::endl;
        }

        virtual ~TestFruit() { std::cout << _name << " dies." << std::endl;}
    private:
};

// Test(IFruit, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
// {
//     {
//         Dummy fruit;

//         std::cout << fruit << std::endl;
//     }
//     cr_assert_stdout_eq_str
//     (
//         "[name: \"DummyFruit\", vitamins: 0, peeled: false]\n"
//     );
// }

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

Test(AFruit_clone, clone_method_returns_new_instance, .init = redirect_all_stdout)
{
    TestFruit   original("Tomato");
    AFruit      *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_eq(clone->isPeeled(), false);
    cr_assert_eq(clone->getName(), "Tomato");
    cr_assert_eq(clone->getVitamins(), 0);

    delete clone;
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

Test(Lemon_Clone, clone_returns_independent_copy)
{
    Lemon       original;
    IFruit      *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_neq(clone, &original);
    cr_assert_eq(clone->isPeeled(), original.isPeeled());
    cr_assert_eq(clone->getName(), original.getName());
    cr_assert_eq(clone->getVitamins(), original.getVitamins());

    delete clone;
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

Test(Orange_Clone, clone_returns_independent_copy)
{
    Orange       original;
    IFruit      *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_neq(clone, &original);
    cr_assert_eq(clone->isPeeled(), original.isPeeled());
    cr_assert_eq(clone->getName(), original.getName());
    cr_assert_eq(clone->getVitamins(), original.getVitamins());

    delete clone;
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
        Strawberry  strawberry;

        strawberry = fruit;
        cr_assert(strawberry.getVitamins() == fruit.getVitamins());
        cr_assert(strawberry.getName() == fruit.getName());
        cr_assert(strawberry.isPeeled() == fruit.isPeeled());
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

Test(Strawberry_Clone, clone_returns_independent_copy)
{
    Strawberry       original;
    IFruit          *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_neq(clone, &original);
    cr_assert_eq(clone->isPeeled(), original.isPeeled());
    cr_assert_eq(clone->getName(), original.getName());
    cr_assert_eq(clone->getVitamins(), original.getVitamins());

    delete clone;
}

///////////////////////////////////////////////////////////////////////////////
//                            Almond class                                   //
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

Test(Almond_Clone, clone_returns_independent_copy)
{
    Almond  original;
    IFruit  *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_neq(clone, &original);
    cr_assert_eq(clone->isPeeled(), original.isPeeled());
    cr_assert_eq(clone->getName(), original.getName());
    cr_assert_eq(clone->getVitamins(), original.getVitamins());

    delete clone;
}

///////////////////////////////////////////////////////////////////////////////
//                            Grapefruit class                               //
///////////////////////////////////////////////////////////////////////////////
Test(Grapefruit, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        Grapefruit fruit;

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "grapefruit");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Grapefruit, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        Grapefruit fruit("grapefruit", 5);

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "grapefruit");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Grapefruit, TEST_assignment_operator, .init = redirect_all_stdout)
{
    {
        Grapefruit  fruit("CopyGrapefruit", 5);
        Grapefruit  grape;

        grape = fruit;
        cr_assert(grape.getVitamins() == fruit.getVitamins());
        cr_assert(grape.getName() == fruit.getName());
        cr_assert(grape.isPeeled() == fruit.isPeeled());
    }
}

Test(Grapefruit, TEST_assignment_operator_self_assignment,
.init = redirect_all_stdout)
{
    {
        Grapefruit  fruit("CopyGrapefruit", 5);

        fruit = fruit;
        cr_assert(fruit.getVitamins() == fruit.getVitamins());
        cr_assert(fruit.getName() == fruit.getName());
        cr_assert(fruit.isPeeled() == fruit.isPeeled());
    }
}

Test(Grapefruit, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        Grapefruit fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(Grapefruit, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Grapefruit fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 5);
    }
}

Test(Grapefruit, TEST_getName_return_name, .init = redirect_all_stdout)
{
    {
        Grapefruit fruit;

        cr_assert(fruit.getName() == "grapefruit");
    }
}

Test(Grapefruit, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    {
        Grapefruit fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Grapefruit, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    {
        Grapefruit fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Grapefruit, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    {
        Grapefruit fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(Grapefruit, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Grapefruit fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"grapefruit\", vitamins: 0, peeled: false]\n"
    );
}

Test(Grapefruit_Clone, clone_returns_independent_copy)
{
    Grapefruit  original;
    IFruit      *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_neq(clone, &original);
    cr_assert_eq(clone->isPeeled(), original.isPeeled());
    cr_assert_eq(clone->getName(), original.getName());
    cr_assert_eq(clone->getVitamins(), original.getVitamins());

    delete clone;
}

///////////////////////////////////////////////////////////////////////////////
//                            BloodOrange class                              //
///////////////////////////////////////////////////////////////////////////////
Test(BloodOrange, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        BloodOrange fruit;

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "blood orange");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(BloodOrange, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        BloodOrange fruit("blood orange", 6);

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "blood orange");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(BloodOrange, TEST_assignment_operator, .init = redirect_all_stdout)
{
    {
        BloodOrange  fruit("CopyBloodOrange", 6);
        BloodOrange  orange;

        orange = fruit;
        cr_assert(orange.getVitamins() == fruit.getVitamins());
        cr_assert(orange.getName() == fruit.getName());
        cr_assert(orange.isPeeled() == fruit.isPeeled());
    }
}

Test(BloodOrange, TEST_assignment_operator_self_assignment,
.init = redirect_all_stdout)
{
    {
        BloodOrange  fruit("CopyBloodOrange", 6);

        fruit = fruit;
        cr_assert(fruit.getVitamins() == fruit.getVitamins());
        cr_assert(fruit.getName() == fruit.getName());
        cr_assert(fruit.isPeeled() == fruit.isPeeled());
    }
}

Test(BloodOrange, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        BloodOrange fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(BloodOrange, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        BloodOrange fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 6);
    }
}

Test(BloodOrange, TEST_getName_return_name, .init = redirect_all_stdout)
{
    {
        BloodOrange fruit;

        cr_assert(fruit.getName() == "blood orange");
    }
}

Test(BloodOrange, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    {
        BloodOrange fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(BloodOrange, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    {
        BloodOrange fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(BloodOrange, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    {
        BloodOrange fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(BloodOrange, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    {
        BloodOrange fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"blood orange\", vitamins: 0, peeled: false]\n"
    );
}

Test(BloodOrange_Clone, clone_returns_independent_copy)
{
    BloodOrange     original;
    IFruit          *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_neq(clone, &original);
    cr_assert_eq(clone->isPeeled(), original.isPeeled());
    cr_assert_eq(clone->getName(), original.getName());
    cr_assert_eq(clone->getVitamins(), original.getVitamins());

    delete clone;
}

///////////////////////////////////////////////////////////////////////////////
//                            Raspberry class                                //
///////////////////////////////////////////////////////////////////////////////
Test(Raspberry, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        Raspberry fruit;

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 5);
        cr_assert(fruit.getName() == "raspberry");
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Raspberry, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        Raspberry fruit("raspberry", 5);

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 5);
        cr_assert(fruit.getName() == "raspberry");
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Raspberry, TEST_assignment_operator, .init = redirect_all_stdout)
{
    {
        Raspberry  fruit("CopyRaspberry", 5);
        Raspberry  rasp;

        rasp = fruit;
        cr_assert(rasp.getVitamins() == fruit.getVitamins());
        cr_assert(rasp.getName() == fruit.getName());
        cr_assert(rasp.isPeeled() == fruit.isPeeled());
    }
}

Test(Raspberry, TEST_assignment_operator_self_assignment,
.init = redirect_all_stdout)
{
    {
        Raspberry  fruit("CopyRaspberry", 5);

        fruit = fruit;
        cr_assert(fruit.getVitamins() == fruit.getVitamins());
        cr_assert(fruit.getName() == fruit.getName());
        cr_assert(fruit.isPeeled() == fruit.isPeeled());
    }
}

Test(Raspberry, TEST_getVitamins_return_vitamins_even_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        Raspberry fruit;

        cr_assert(fruit.getVitamins() == 5);
    }
}

Test(Raspberry, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Raspberry fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 5);
    }
}

Test(Raspberry, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        Raspberry fruit;

        cr_assert(fruit.getName() == "raspberry");
    }
}

Test(Raspberry, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        Raspberry fruit;

        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Raspberry, TEST_peel_peel_fruit_is_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        Raspberry fruit;

        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Raspberry, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        Raspberry fruit;

        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(Raspberry, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Raspberry fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"raspberry\", vitamins: 5, peeled: true]\n"
    );
}

Test(Raspberry_Clone, clone_returns_independent_copy)
{
    Raspberry       original;
    IFruit          *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_neq(clone, &original);
    cr_assert_eq(clone->isPeeled(), original.isPeeled());
    cr_assert_eq(clone->getName(), original.getName());
    cr_assert_eq(clone->getVitamins(), original.getVitamins());

    delete clone;
}

///////////////////////////////////////////////////////////////////////////////
//                            Coconut class                                  //
///////////////////////////////////////////////////////////////////////////////
Test(Coconut, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        Coconut fruit;

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "coconut");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Coconut, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        Coconut fruit("coconut", 4);

        cr_assert_not_null(&fruit);
        cr_assert(fruit.getVitamins() == 0);
        cr_assert(fruit.getName() == "coconut");
        cr_assert(fruit.isPeeled() == false);
    }
}

Test(Coconut, TEST_assignment_operator, .init = redirect_all_stdout)
{
    {
        Coconut  fruit("CopyCoconut", 4);
        Coconut  coconut;

        coconut = fruit;
        cr_assert(coconut.getVitamins() == fruit.getVitamins());
        cr_assert(coconut.getName() == fruit.getName());
        cr_assert(coconut.isPeeled() == fruit.isPeeled());
    }
}

Test(Coconut, TEST_assignment_operator_self_assignment,
.init = redirect_all_stdout)
{
    {
        Coconut  fruit("CopyCoconut", 4);

        fruit = fruit;
        cr_assert(fruit.getVitamins() == fruit.getVitamins());
        cr_assert(fruit.getName() == fruit.getName());
        cr_assert(fruit.isPeeled() == fruit.isPeeled());
    }
}

Test(Coconut, TEST_getVitamins_return_zero_if_fruit_is_not_peeled,
.init = redirect_all_stdout)
{
    {
        Coconut fruit;

        cr_assert(fruit.getVitamins() == 0);
    }
}

Test(Coconut, TEST_getVitamins_return_vitamins_if_fruit_is_peeled,
.init = redirect_all_stdout)
{
    {
        Coconut fruit;

        fruit.peel();
        cr_assert(fruit.getVitamins() == 4);
    }
}

Test(Coconut, TEST_getName_return_name, .init = redirect_all_stdout)
{
    
    {
        Coconut fruit;

        cr_assert(fruit.getName() == "coconut");
    }
}

Test(Coconut, TEST_isPeeled_checks_if_fruit_is_peeled_or_not, .init = redirect_all_stdout)
{
    
    {
        Coconut fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Coconut, TEST_peel_peel_fruit_not_peeled_by_default, .init = redirect_all_stdout)
{
    
    {
        Coconut fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}

Test(Coconut, TEST_peel_do_nothing_if_fruit_is_already_peel, .init = redirect_all_stdout)
{
    
    {
        Coconut fruit;

        cr_assert(fruit.isPeeled() == false);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
        fruit.peel();
        cr_assert(fruit.isPeeled() == true);
    }
}


Test(Coconut, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Coconut fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"coconut\", vitamins: 0, peeled: false]\n"
    );
}

Test(Coconut_Clone, clone_returns_independent_copy)
{
    Coconut         original;
    IFruit          *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_neq(clone, &original);
    cr_assert_eq(clone->isPeeled(), original.isPeeled());
    cr_assert_eq(clone->getName(), original.getName());
    cr_assert_eq(clone->getVitamins(), original.getVitamins());

    delete clone;
}

///////////////////////////////////////////////////////////////////////////////
//                            FruitBox class                                 //
///////////////////////////////////////////////////////////////////////////////
Test(FruitBox, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        FruitBox box;

        cr_assert_not_null(&box);
        cr_assert(box.getSize() == 0);
        cr_assert(box.nbFruit() == 0);
    }
}

Test(FruitBox, TEST_paramaters_CTOR, .init = redirect_all_stdout)
{
    {
        FruitBox box(3);

        cr_assert_not_null(&box);
        cr_assert(box.getSize() == 3);
        cr_assert(box.nbFruit() == 0);
    }
}

Test(FruitBox, TEST_getSize_return_size_of_box,
.init = redirect_all_stdout)
{
    {
        FruitBox box(3);

        cr_assert(box.getSize() == 3);
    }
}

Test(FruitBox, TEST_nbFruit_return_numnber_of_fruit_in_the_box,
.init = redirect_all_stdout)
{
    {
        FruitBox box(3);

        cr_assert(box.nbFruit() == 0);
        Orange *orange = new Orange;

        cr_assert(box.pushFruit(orange) == true);
        cr_assert(box.nbFruit() == 1);
    }
}

Test(FruitBox, TEST_getFruit_return_fruit, .init = redirect_all_stdout)
{
    
    {
        FruitBox box(3);
        Orange *orange = new Orange;
        Lemon *lemon = new Lemon;
        Strawberry *berry = new Strawberry;

        cr_assert(box.pushFruit(orange) == true);
        cr_assert(box.pushFruit(lemon) == true);
        cr_assert(box.pushFruit(berry) == true);

        for (size_t i = 0; i < box.getSize(); ++i)
            cr_assert_not_null(box.getFruit(i));
    }
}

Test(FruitBox, TEST_getFruit_return_nullptr, .init = redirect_all_stdout)
{
    
    {
        FruitBox box(3);

        for (size_t i = 0; i < box.getSize(); ++i)
            cr_assert_null(box.getFruit(i));
    }
}

Test(FruitBox, TEST_getFruit_return_nullptr_because_wrong_index,
.init = redirect_all_stdout)
{
    
    {
        FruitBox box(3);

        cr_assert_null(box.getFruit(4));
    }
}

Test(FruitBox, TEST_pushFruit_with_null_fruitbox_should_return_false,
.init = redirect_all_stdout)
{
    {
        FruitBox box;
        Orange *orange = new Orange;

        cr_assert(box.pushFruit(orange) == false);

        delete orange;
    }
}

Test(FruitBox, TEST_pushFruit_with_null_fruit_should_return_false,
.init = redirect_all_stdout)
{
    {
        FruitBox box(3);
        Orange *orange = nullptr;

        cr_assert(box.pushFruit(orange) == false);
    }
}

Test(FruitBox, TEST_pushFruit_adds_fruit_should_return_true,
.init = redirect_all_stdout)
{
    {
        FruitBox box(3);
        Orange *orange = new Orange;

        cr_assert(box.pushFruit(orange) == true);
        cr_assert(box.pushFruit(orange) == false);

    }
}

Test(FruitBox,
TEST_pushFruit_adds_2_times_the_same_fruit_should_return_false,
.init = redirect_all_stdout)
{
    {
        FruitBox box(3);
        Orange *orange = new Orange;

        cr_assert(box.pushFruit(orange) == true);
        cr_assert(box.pushFruit(orange) == false);

    }
}

Test(FruitBox,
TEST_pushFruit_adds_more_fruits_than_fruitBox_size_should_return_false,
.init = redirect_all_stdout)
{
    {
        FruitBox box(3);
        Orange *orange = new Orange;
        Lemon *lemon = new Lemon;
        Strawberry *berry = new Strawberry;
        Almond *almond = new Almond;

        cr_assert(box.pushFruit(orange) == true);
        cr_assert(box.pushFruit(lemon) == true);
        cr_assert(box.pushFruit(berry) == true);
        cr_assert(box.pushFruit(almond) == false);

        delete almond;
    }
}

Test(FruitBox, TEST_popFruit_should_returns_fruit_that_has_been_removed,
.init = redirect_all_stdout)
{
    {
        FruitBox box(3);
        Orange *orange = new Orange;
        Lemon *lemon = new Lemon;
        Strawberry *berry = new Strawberry;
        IFruit *tmp = nullptr;

        cr_assert(box.pushFruit(orange) == true);
        cr_assert(box.pushFruit(lemon) == true);
        cr_assert(box.pushFruit(berry) == true);
        cr_assert(box.nbFruit() == 3);
        tmp = box.popFruit();
        cr_assert_not_null(tmp);
        cr_assert(box.nbFruit() == 2);

        delete tmp;
    }
}

Test(FruitBox,
TEST_popFruit_should_returns_nullptr_after_try_to_remove_fruit_that_is_in_null_box,
.init = redirect_all_stdout)
{
    {
        FruitBox box;
        Orange *orange = new Orange;
        IFruit *tmp = nullptr;

        cr_assert(box.pushFruit(orange) == false);
        cr_assert(box.nbFruit() == 0);

        tmp = box.popFruit();
        cr_assert_null(tmp);
        cr_assert(box.nbFruit() == 0);
        delete tmp;
        delete orange;
    }
}

Test(FruitBox,
TEST_left_stream_operator_overload_ostream_with_fruits_in_fruitbox,
.init = redirect_all_stdout)
{
    
    {
        FruitBox box(3);
        const FruitBox& cref = box;
        Orange *orange = new Orange;
        Lemon *lemon = new Lemon;
        Strawberry *berry = new Strawberry;

        cr_assert(box.pushFruit(orange) == true);
        cr_assert(box.pushFruit(lemon) == true);
        cr_assert(box.pushFruit(berry) == true);

        std::cout << cref << std::endl;

    }
    cr_assert_stdout_eq_str(
        "["
        "[name: \"orange\", vitamins: 0, peeled: false], "
        "[name: \"lemon\", vitamins: 0, peeled: false], "
        "[name: \"strawberry\", vitamins: 6, peeled: true]"
        "]\n"
    );
}

Test(FruitBox,
TEST_left_stream_operator_overload_ostream_with_empty_fruitBox,
.init = redirect_all_stdout)
{
    
    {
        FruitBox box;
        const FruitBox& cref = box;

        std::cout << cref << std::endl;
    }
    cr_assert_stdout_eq_str(
        "[]\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            FruitUtils class                               //
///////////////////////////////////////////////////////////////////////////////
Test(FruitUtils, TEST_default_CTOR, .init = redirect_all_stdout)
{
    {
        FruitUtils utils;

        cr_assert_not_null(&utils);
    }
}

Test(FruitUtils, TEST_sort_fruits, .init = redirect_all_stdout)
{
    {
        FruitUtils  utils;
        FruitBox    unsortedBox(8);
        FruitBox    lemonBox(8);
        FruitBox    citrusBox(8);
        FruitBox    berryBox(8);
        Orange      *orange = new Orange;
        Lemon       *lemon = new Lemon;
        Strawberry  *berry = new Strawberry;
        Almond      *almond = new Almond;
        Grapefruit  *grapefruit = new Grapefruit;
        BloodOrange *bloodOrange = new BloodOrange;
        Raspberry   *raspberry = new Raspberry;
        Coconut     *coconut = new Coconut;


        cr_assert(unsortedBox.pushFruit(orange) == true);
        cr_assert(unsortedBox.pushFruit(lemon) == true);
        cr_assert(unsortedBox.pushFruit(berry) == true);
        cr_assert(unsortedBox.pushFruit(almond) == true);
        cr_assert(unsortedBox.pushFruit(grapefruit) == true);
        cr_assert(unsortedBox.pushFruit(bloodOrange) == true);
        cr_assert(unsortedBox.pushFruit(raspberry) == true);
        cr_assert(unsortedBox.pushFruit(coconut) == true);

        utils.sort(unsortedBox, lemonBox, citrusBox, berryBox);

        std::cout << "unsorted: " << unsortedBox << std::endl;
        std::cout << "lemonBox: " << lemonBox << std::endl;
        std::cout << "citrusBox: " << citrusBox << std::endl;
        std::cout << "berryBox: " << berryBox << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "unsorted: [[name: \"almond\", vitamins: 0, peeled: false], [name: \"coconut\", vitamins: 0, peeled: false]]\n"
        "lemonBox: [[name: \"lemon\", vitamins: 0, peeled: false]]\n"
        "citrusBox: [[name: \"orange\", vitamins: 0, peeled: false], [name: \"grapefruit\", vitamins: 0, peeled: false], [name: \"blood orange\", vitamins: 0, peeled: false]]\n"
        "berryBox: [[name: \"strawberry\", vitamins: 6, peeled: true], [name: \"raspberry\", vitamins: 5, peeled: true]]\n"
    );
}

Test(FruitUtils, TEST_sort_unknown_fruit_goes_back_to_unsorted, .init = redirect_all_stdout)
{
    FruitBox unsorted(3);
    FruitBox lemonBox(1);
    FruitBox citrusBox(1);
    FruitBox berryBox(1);

    unsorted.pushFruit(new Almond);

    FruitUtils::sort(unsorted, lemonBox, citrusBox, berryBox);

    cr_assert_eq(unsorted.nbFruit(), 1);
    delete unsorted.popFruit();
}

Test(FruitUtils, TEST_sort_full_boxes_push_back_unsorted, .init = redirect_all_stdout)
{
    FruitBox unsorted(4);
    FruitBox lemonBox(1);
    FruitBox citrusBox(1);
    FruitBox berryBox(1);

    unsorted.pushFruit(new Lemon);
    unsorted.pushFruit(new Lemon);
    unsorted.pushFruit(new Orange);
    unsorted.pushFruit(new Strawberry);

    FruitUtils::sort(unsorted, lemonBox, citrusBox, berryBox);

    cr_assert_eq(lemonBox.nbFruit(), 1);
    cr_assert_eq(citrusBox.nbFruit(), 1);
    cr_assert_eq(berryBox.nbFruit(), 1);
    cr_assert_eq(unsorted.nbFruit(), 1);

    delete lemonBox.popFruit();
    delete citrusBox.popFruit();
    delete berryBox.popFruit();
    delete unsorted.popFruit();
}

Test(FruitUtils, TEST_sort_all_fruits_rejected, .init = redirect_all_stdout)
{
    FruitBox unsorted(3);
    FruitBox lemonBox(0);
    FruitBox citrusBox(0);
    FruitBox berryBox(0);

    unsorted.pushFruit(new Lemon);
    unsorted.pushFruit(new Orange);
    unsorted.pushFruit(new Strawberry);

    FruitUtils::sort(unsorted, lemonBox, citrusBox, berryBox);

    cr_assert_eq(unsorted.nbFruit(), 3);

    delete unsorted.popFruit();
    delete unsorted.popFruit();
    delete unsorted.popFruit();
}

Test(FruitUtils, TEST_sort_no_duplicate_push, .init = redirect_all_stdout)
{
    FruitBox unsorted(3);
    FruitBox lemonBox(2);

    Lemon *lemon = new Lemon;
    unsorted.pushFruit(lemon);

    FruitUtils::sort(unsorted, lemonBox, unsorted, unsorted);

    cr_assert_eq(lemonBox.pushFruit(lemon), false);

    delete lemonBox.popFruit();
}

Test(FruitUtils, TEST_pack, .init = redirect_all_stdout)
{
    {
        IFruit *fruits[26];
        int i = 0;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i] = nullptr;
        
        FruitBox **tmp = FruitUtils::pack(fruits, 6);
        for (size_t i = 0; tmp[i] != nullptr; ++i)
            std::cout << *tmp[i] << std::endl;
        
        for (size_t i = 0; tmp[i] != nullptr; ++i) {
            IFruit *f = nullptr;
            while ((f = tmp[i]->popFruit()) != nullptr)
                delete f;
            delete tmp[i];
        }
        delete[] tmp;
    }
    cr_assert_stdout_eq_str
    (
        "[[name: \"almond\", vitamins: 0, peeled: false], [name: \"blood orange\", vitamins: 0, peeled: false], [name: \"coconut\", vitamins: 0, peeled: false], [name: \"grapefruit\", vitamins: 0, peeled: false], [name: \"lemon\", vitamins: 0, peeled: false], [name: \"orange\", vitamins: 0, peeled: false]]\n"
        "[[name: \"raspberry\", vitamins: 5, peeled: true], [name: \"strawberry\", vitamins: 6, peeled: true], [name: \"almond\", vitamins: 0, peeled: false], [name: \"blood orange\", vitamins: 0, peeled: false], [name: \"coconut\", vitamins: 0, peeled: false], [name: \"grapefruit\", vitamins: 0, peeled: false]]\n"
        "[[name: \"lemon\", vitamins: 0, peeled: false], [name: \"orange\", vitamins: 0, peeled: false], [name: \"raspberry\", vitamins: 5, peeled: true], [name: \"strawberry\", vitamins: 6, peeled: true], [name: \"almond\", vitamins: 0, peeled: false], [name: \"blood orange\", vitamins: 0, peeled: false]]\n"
        "[[name: \"coconut\", vitamins: 0, peeled: false], [name: \"grapefruit\", vitamins: 0, peeled: false], [name: \"lemon\", vitamins: 0, peeled: false], [name: \"orange\", vitamins: 0, peeled: false], [name: \"raspberry\", vitamins: 5, peeled: true], [name: \"strawberry\", vitamins: 6, peeled: true]]\n"
        "[[name: \"almond\", vitamins: 0, peeled: false]]\n"
    );
}

Test(FruitUtils, TEST_pack_with_null_fruits, .init = redirect_all_stdout)
{
    {
        IFruit **fruits =  nullptr;
        
        FruitBox **tmp = FruitUtils::pack(fruits, 6);
        cr_assert_null(tmp);
    }
}

Test(FruitUtils, TEST_pack_with_fruit_array_has_null_content, .init = redirect_all_stdout)
{
    {
        IFruit *fruits[] =  {nullptr};
        
        FruitBox **tmp = FruitUtils::pack(fruits, 6);
        cr_assert_null(tmp);
    }
}

Test(FruitUtils, TEST_pack_with_fruitBox_has_no_sizeBox, .init = redirect_all_stdout)
{
    {
        IFruit *fruits[26];
        int i = 0;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i] = nullptr;
        
        FruitBox **tmp = FruitUtils::pack(fruits, 0);
        
        cr_assert_null(tmp);
        
        for (size_t i = 0; fruits[i] != nullptr; ++i)
            delete fruits[i];
    }
}

Test(FruitUtils_pack, TEST_shloud_move_content_of_fruit_array, .init = redirect_all_stdout)
{
    {
        IFruit *fruits[26];
        int i = 0;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i] = nullptr;
        
        FruitBox **tmp = FruitUtils::pack(fruits, 6);
        for (size_t i = 0; tmp[i] != nullptr; ++i)
            std::cout << *tmp[i] << std::endl;
        
        cr_assert_null(*fruits);
        for (size_t i = 0; tmp[i] != nullptr; ++i) {
            IFruit *f = nullptr;
            while ((f = tmp[i]->popFruit()) != nullptr)
                delete f;
            delete tmp[i];
        }
        delete[] tmp;
    }
}

Test(FruitUtils_unpack, TEST_Fruitbox_is_empty_after_be_unpacked, .init = redirect_all_stdout)
{
    {
        IFruit *fruits[26];
        int i = 0;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i] = nullptr;
        
        FruitBox **tmp = FruitUtils::pack(fruits, 6);
        IFruit **unpackedFruits = FruitUtils::unpack(tmp);
        
        cr_assert_not_null(unpackedFruits);
        
        for (size_t i = 0; unpackedFruits[i] != nullptr; ++i)
            std::cout << *unpackedFruits[i] << std::endl;
        
        for (size_t i = 0; tmp[i] != nullptr; ++i)
            delete tmp[i];
        delete [] tmp;

        for (size_t i = 0; unpackedFruits[i] != nullptr; ++i)
                delete unpackedFruits[i];
        delete [] unpackedFruits;
    }
    cr_assert_stdout_eq_str
    (
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
        "[name: \"blood orange\", vitamins: 0, peeled: false]\n"
        "[name: \"coconut\", vitamins: 0, peeled: false]\n"
        "[name: \"grapefruit\", vitamins: 0, peeled: false]\n"
        "[name: \"lemon\", vitamins: 0, peeled: false]\n"
        "[name: \"orange\", vitamins: 0, peeled: false]\n"
        "[name: \"raspberry\", vitamins: 5, peeled: true]\n"
        "[name: \"strawberry\", vitamins: 6, peeled: true]\n"
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
        "[name: \"blood orange\", vitamins: 0, peeled: false]\n"
        "[name: \"coconut\", vitamins: 0, peeled: false]\n"
        "[name: \"grapefruit\", vitamins: 0, peeled: false]\n"
        "[name: \"lemon\", vitamins: 0, peeled: false]\n"
        "[name: \"orange\", vitamins: 0, peeled: false]\n"
        "[name: \"raspberry\", vitamins: 5, peeled: true]\n"
        "[name: \"strawberry\", vitamins: 6, peeled: true]\n"
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
        "[name: \"blood orange\", vitamins: 0, peeled: false]\n"
        "[name: \"coconut\", vitamins: 0, peeled: false]\n"
        "[name: \"grapefruit\", vitamins: 0, peeled: false]\n"
        "[name: \"lemon\", vitamins: 0, peeled: false]\n"
        "[name: \"orange\", vitamins: 0, peeled: false]\n"
        "[name: \"raspberry\", vitamins: 5, peeled: true]\n"
        "[name: \"strawberry\", vitamins: 6, peeled: true]\n"
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
    );
}

Test(FruitUtils_unpack, TEST_should_return_nullptr_because_fruitBox_is_nullptr, .init = redirect_all_stdout)
{
    {
        IFruit *fruits[26];
        int i = 0;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i++] = new BloodOrange;
        fruits[i++] = new Coconut;
        fruits[i++] = new Grapefruit;
        fruits[i++] = new Lemon;
        fruits[i++] = new Orange;
        fruits[i++] = new Raspberry;
        fruits[i++] = new Strawberry;
        fruits[i++] = new Almond;
        fruits[i] = nullptr;
        
        FruitBox **tmp = FruitUtils::pack(fruits, 0);
        cr_assert_null(tmp);

        for (size_t i = 0; fruits[i] != nullptr; ++i)
            delete fruits[i];
        
        IFruit **unpackedFruits = FruitUtils::unpack(tmp);
        
        cr_assert_null(unpackedFruits);
    }
}

///////////////////////////////////////////////////////////////////////////////
//                            FruitFactory class                             //
///////////////////////////////////////////////////////////////////////////////
Test(FruitFactory_registerFruit, TEST_register_fruits, .init = redirect_all_stdout)
{
    {
        FruitFactory    factory;

        factory.registerFruit(new Orange);
        factory.registerFruit(new BloodOrange);
        factory.registerFruit(new Almond);
        factory.registerFruit(new Coconut);
        factory.registerFruit(new Almond);
        
        factory.display();
    }
    cr_assert_stdout_eq_str
    (
        "[name: \"orange\", vitamins: 0, peeled: false]\n"
        "[name: \"blood orange\", vitamins: 0, peeled: false]\n"
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
        "[name: \"coconut\", vitamins: 0, peeled: false]\n"
    );
}

Test(FruitFactory_registerFruit, TEST_replace_fruits_already_registered, .init = redirect_all_stdout)
{
    {
        FruitFactory    factory;

        factory.registerFruit(new Orange);
        factory.registerFruit(new Almond);
        factory.registerFruit(new Almond);
        factory.registerFruit(new Almond);
        factory.registerFruit(new Almond);
        
        factory.display();
    }
    cr_assert_stdout_eq_str
    (
        "[name: \"orange\", vitamins: 0, peeled: false]\n"
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
    );
}

Test(FruitFactory_unregisterFruit, TEST_unregister_fruits_already_registered, .init = redirect_all_stdout)
{
    {
        FruitFactory    factory;

        factory.registerFruit(new Orange);
        factory.registerFruit(new BloodOrange);
        factory.registerFruit(new Almond);
        factory.registerFruit(new Coconut);
        factory.registerFruit(new Almond);
        factory.unregisterFruit("almond");
        factory.unregisterFruit("blood orange");

        factory.display();
    }
    cr_assert_stdout_eq_str
    (
        "[name: \"orange\", vitamins: 0, peeled: false]\n"
        "[name: \"coconut\", vitamins: 0, peeled: false]\n"
    );
}

Test(FruitFactory_unregisterFruit, TEST_try_to_unregister_unknown_fruits, .init = redirect_all_stdout)
{
    {
        FruitFactory    factory;

        factory.registerFruit(new Orange);
        factory.registerFruit(new BloodOrange);
        factory.registerFruit(new Almond);
        factory.registerFruit(new Coconut);
        factory.registerFruit(new Almond);
        
        factory.unregisterFruit("banana");
        factory.unregisterFruit("coconut");
        
        factory.display();
    }
    cr_assert_stdout_eq_str
    (
        "[name: \"orange\", vitamins: 0, peeled: false]\n"
        "[name: \"blood orange\", vitamins: 0, peeled: false]\n"
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
    );
}

Test(FruitFactory_createFruit, TEST_create_fruit_registered, .init = redirect_all_stdout)
{
    {
        FruitFactory    factory;

        factory.registerFruit(new Orange);
        factory.registerFruit(new BloodOrange);
        factory.registerFruit(new Almond);
        factory.registerFruit(new Coconut);
        factory.registerFruit(new Almond);

        factory.unregisterFruit("banana");
        factory.unregisterFruit("coconut");
        
        IFruit          *fruit1 = factory.createFruit("almond");
        IFruit          *fruit2 = factory.createFruit("coconut");
        IFruit          *fruit3 = factory.createFruit("tomato");

        std::cout << *fruit1 << std::endl;
        std::cout << fruit2 << std::endl;
        std::cout << fruit3 << std::endl;

        delete fruit1;
    }
    cr_assert_stdout_eq_str
    (
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
        "0\n"
        "0\n"
    );
}

Test(FruitFactory_createFruit,
TEST_try_to_create_fruit_unregistered_or_unknown_should_return_nullptr,
.init = redirect_all_stdout)
{
    {
        FruitFactory    factory;

        factory.registerFruit(new Orange);
        factory.registerFruit(new BloodOrange);
        factory.registerFruit(new Almond);
        factory.registerFruit(new Coconut);
        factory.registerFruit(new Almond);

        factory.unregisterFruit("banana");
        factory.unregisterFruit("coconut");
        
        IFruit          *fruit1 = factory.createFruit("almond");
        IFruit          *fruit2 = factory.createFruit("coconut");
        cr_assert_null(fruit2);
        IFruit          *fruit3 = factory.createFruit("tomato");
        cr_assert_null(fruit3);

        std::cout << *fruit1 << std::endl;
        std::cout << fruit2 << std::endl;
        std::cout << fruit3 << std::endl;

        delete fruit1;
    }
    cr_assert_stdout_eq_str
    (
        "[name: \"almond\", vitamins: 0, peeled: false]\n"
        "0\n"
        "0\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            FruitMixer class                               //
///////////////////////////////////////////////////////////////////////////////
Test(FruitMixer_constructor, TEST_CTOR_isDefined, .init = redirect_all_stdout)
{
    FruitMixer  yourMixer;
}

Test(FruitMixer_getBlade,
TEST_should_return_nullptr_because_no_blade_set,
.init = redirect_all_stdout)
{
    {
        FruitBox    box(5);
        FruitMixer  yourMixer;
        IFruit      *fruit;
        
        cr_assert_null(yourMixer.getBlade());
        fruit = new Orange;
        fruit->peel();
        box.pushFruit(fruit);
        box.pushFruit(new Lemon);
        box.pushFruit(new Strawberry);
        box.pushFruit(new Almond);

        cr_assert(yourMixer.mixFruits(box) == 0);
    }
    cr_assert_stdout_eq_str
    (
        "mixer has no blade\n"
    );
}

Test(FruitMixer_setBlade,
TEST_getBlade_should_be_no_nullptr_after_setBlade,
.init = redirect_all_stdout)
{
    {
        FruitBox    box(5);
        FruitMixer  yourMixer;
        SteelBlade blade;
        IFruit      *fruit;
        
        cr_assert_null(yourMixer.getBlade());
        fruit = new Orange;
        fruit->peel();
        box.pushFruit(fruit);
        box.pushFruit(new Lemon);
        box.pushFruit(new Strawberry);
        box.pushFruit(new Almond);
        yourMixer.setBlade(&blade);
        cr_assert_not_null(yourMixer.getBlade());
        cr_assert(yourMixer.mixFruits(box) == 13);
    }
}


Test(FruitMixer_mixFruit,
TEST_should_return_zero_vitamins_because_no_blade_set,
.init = redirect_all_stdout)
{
    {
        FruitBox    box(5);
        FruitMixer  yourMixer;
        IFruit      *fruit;

        fruit = new Orange;
        fruit->peel();
        box.pushFruit(fruit);
        box.pushFruit(new Lemon);
        box.pushFruit(new Strawberry);
        box.pushFruit(new Almond);
        std::cout << box << std::endl;

        cr_assert(yourMixer.mixFruits(box) == 0);
    }
    cr_assert_stdout_eq_str
    (
        "[[name: \"orange\", vitamins: 7, peeled: true], [name: \"lemon\", vitamins: 0, peeled: false], [name: \"strawberry\", vitamins: 6, peeled: true], [name: \"almond\", vitamins: 0, peeled: false]]\n"
        "mixer has no blade\n"
    );
}

Test(FruitMixer_mixFruit,
TEST_should_return_vitamins_if_fruits_are_peeled,
.init = redirect_all_stdout)
{
    {
        FruitBox    box(5);
        FruitMixer  yourMixer;
        IFruitMixer &mixer(yourMixer);
        SteelBlade  blade;
        IFruit      *fruit;
        
        fruit = new Orange;
        fruit->peel();
        box.pushFruit(fruit);
        box.pushFruit(new Lemon);
        box.pushFruit(new Strawberry);
        box.pushFruit(new Almond);
        mixer.setBlade(&blade);
        std::cout << box << std::endl;
        cr_assert(mixer.mixFruits(box) == 13);
        std::cout << box << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "[[name: \"orange\", vitamins: 7, peeled: true], [name: \"lemon\", vitamins: 0, peeled: false], [name: \"strawberry\", vitamins: 6, peeled: true], [name: \"almond\", vitamins: 0, peeled: false]]\n"
        "[[name: \"lemon\", vitamins: 0, peeled: false], [name: \"almond\", vitamins: 0, peeled: false]]\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        FruitBox    box(5);
        FruitMixer  yourMixer;
        IFruitMixer &mixer(yourMixer);
        SteelBlade  blade;
        IFruit      *fruit;
        
        fruit = new Orange;
        fruit->peel();
        box.pushFruit(fruit);
        box.pushFruit(new Lemon);
        box.pushFruit(new Strawberry);
        box.pushFruit(new Almond);
        std::cout << box << std::endl;

        unsigned int vitamins = mixer.mixFruits(box);

        std::cout << "result: " << vitamins << std::endl;
        std::cout << box << std::endl;

        mixer.setBlade(&blade);
        vitamins = mixer.mixFruits(box);

        std::cout << "result: " << vitamins << std::endl;
        std::cout << box << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "[[name: \"orange\", vitamins: 7, peeled: true], [name: \"lemon\", vitamins: 0, peeled: false], [name: \"strawberry\", vitamins: 6, peeled: true], [name: \"almond\", vitamins: 0, peeled: false]]\n"
        "mixer has no blade\n"
        "result: 0\n"
        "[[name: \"orange\", vitamins: 7, peeled: true], [name: \"lemon\", vitamins: 0, peeled: false], [name: \"strawberry\", vitamins: 6, peeled: true], [name: \"almond\", vitamins: 0, peeled: false]]\n"
        "result: 13\n"
        "[[name: \"lemon\", vitamins: 0, peeled: false], [name: \"almond\", vitamins: 0, peeled: false]]\n"
    );
}