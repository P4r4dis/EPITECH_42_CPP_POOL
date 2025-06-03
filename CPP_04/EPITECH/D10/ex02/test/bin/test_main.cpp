/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:35:25 PM 2025 Paradis
** Last update Wed Jun 3 2:44:10 PM 2025 Paradis
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
#include "../../include/FruitBox.hpp"
#include "../../include/Grapefruit.hpp"
#include "../../include/BloodOrange.hpp"
#include "../../include/Raspberry.hpp"
#include "../../include/Coconut.hpp"


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
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {       
        FruitBox        box(3);
        const FruitBox& cref = box;

        box.pushFruit(new TestFruit("Cerise"));
        box.pushFruit(new TestFruit("Framboise"));
        box.pushFruit(new TestFruit("Anis"));
        std::cout << cref << std::endl;

        IFruit          *tmp = new TestFruit("Serge");

        std::cout << box.pushFruit(tmp) << std::endl;
        delete tmp;

        tmp = box.popFruit();
        delete tmp;
        std::cout << cref << std::endl;
    }

    cr_assert_stdout_eq_str(
        "Cerise lives.\n"
        "Framboise lives.\n"
        "Anis lives.\n"
        "[[name: \"Cerise\", vitamins: 0, peeled: false], [name: \"Framboise\", vitamins: 0, peeled: false], [name: \"Anis\", vitamins: 0, peeled: false]]\n"
        "Serge lives.\n"
        "0\n"
        "Serge dies.\n"
        "Cerise dies.\n"
        "[[name: \"Framboise\", vitamins: 0, peeled: false], [name: \"Anis\", vitamins: 0, peeled: false]]\n"
        "Framboise dies.\n"
        "Anis dies.\n"
    );
}