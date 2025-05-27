/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 3:53:48 PM 2025 Paradis
** Last update Wed May 27 5:07:13 PM 2025 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/IFruit.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
class Dummy : public IFruit
{
    public:
        Dummy() { _name = "DummyFruit"; _vit = 10; _peeled = false;}
        ~Dummy() {}
        unsigned int getVitamins() const {return _vit;};
        std::string getName() const {return _name;};
        bool isPeeled() const {return _peeled;};
        void peel() {}
    private:
        std::string _name;
        unsigned int _vit;
        bool _peeled;
};

Test(IFruit, TEST_left_stream_operator_overload_ostream, .init = redirect_all_stdout)
{
    
    {
        Dummy fruit;

        std::cout << fruit << std::endl;

    }
    cr_assert_stdout_eq_str(
        "[name: \"DummyFruit\", vitamins: 10, peeled: false]\n"
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