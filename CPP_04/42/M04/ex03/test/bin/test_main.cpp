/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:05:30 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/22 20:38:58 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/AMateria.hpp"
#include "../../include/Ice.hpp"
#include "../../include/Cure.hpp"
#include "../../include/ICharacter.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(AMateria, TEST_AMateria_Default_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        AMateria    *amateria = new Ice;

        cr_assert_not_null(&amateria);

        delete amateria;
    }
}

Test(AMateria, TEST_AMateria_paramaterized_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        AMateria    *amateria = new Ice("ice");

        cr_assert_not_null(&amateria);

        delete amateria;
    }
}

Test(AMateria, TEST_AMateria_Copy_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        AMateria    *amateria = new Ice("ice");
        AMateria    *cpyAmateria = amateria->clone();

        cr_assert_not_null(&amateria);
        cr_assert_not_null(&cpyAmateria);

        delete amateria;
        delete cpyAmateria;
    }
}

Test(AMateria, default_constructor, .init = redirect_all_stdout)
{
    {    
        AMateria    *amateria = new Ice;

        cr_assert_eq(amateria->getType(), "ice");
        
        delete amateria;
    }
}

Test(AMateria, parameterized_constructor, .init = redirect_all_stdout)
{
    {
        AMateria    *amateria = new Ice("ice");

        cr_assert_eq(amateria->getType(), "ice");

        delete amateria;
    }
}

Test(AMateria, copy_constructor)
{
    {
        AMateria    *amateria = new Ice("ice");
        AMateria    *cpyAmateria = amateria->clone();

        cr_assert_eq(cpyAmateria->getType(), "ice");

        delete amateria;
        delete cpyAmateria;
    }
}

Test(AMateria, assignment_operator, .init = redirect_all_stdout)
{
    {
        AMateria    *amateria = new Ice("ice");
        AMateria    *assigned;

        assigned = amateria;
        cr_assert_eq(assigned->getType(), "ice");

        delete amateria;
    }
}

Test(AMateria, destructor, .init = redirect_all_stdout)
{
    AMateria    *amateria = new Ice("ice");

    delete amateria;
    
    cr_assert(true, "Destructor has no crash");
}

Test(AMateria, getType_method, .init = redirect_all_stdout)
{
    {
        AMateria    *amateria = new Ice("ice");

        cr_assert_eq(amateria->getType(), "ice");

        delete amateria;
    }
}

Test(AMateria, getType_after_copy, .init = redirect_all_stdout) 
{
    {
        AMateria    *amateria = new Ice("ice");
        AMateria    *cpyAmateria = amateria->clone();

        cr_assert_eq(cpyAmateria->getType(), "ice");

        delete amateria;
        delete cpyAmateria;
    }
}

Test(AMateria, clone_method_returns_new_instance, .init = redirect_all_stdout)
{
    Ice         original;
    AMateria    *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_eq(clone->getType(), "ice");

    delete clone;
}

Test(AMateria, use_method, .init = redirect_all_stdout)
{
    class DummyCharacter : public ICharacter {
    public:
        DummyCharacter() : _name("Dummy") {}
        std::string const &getName() const {
            return _name;
        }

    private:
        std::string _name;
    };
    
    AMateria    *amateria = new Ice("ice");
    ICharacter  *test = new DummyCharacter();

    amateria->use(*test);

    delete amateria;
    delete test;

    cr_assert(true, "use method display nothing");
}
///////////////////////////////////////////////////////////////////////////////
//                            Ice class                                      //
///////////////////////////////////////////////////////////////////////////////
Test(Ice, TEST_Ice_Default_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Ice    ice;

        cr_assert_not_null(&ice);
    }
}

Test(Ice, TEST_Ice_paramaterized_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Ice    ice("ice");

        cr_assert_not_null(&ice);
    }
}

Test(Ice, TEST_Ice_Copy_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Ice    ice("ice");
        Ice    cpyAmateria(ice);

        cr_assert_not_null(&ice);
        cr_assert_not_null(&cpyAmateria);
    }
}

Test(Ice, default_constructor, .init = redirect_all_stdout)
{
    {    
        Ice    ice;

        cr_assert_eq(ice.getType(), "ice");
    
    }
}

Test(Ice, parameterized_constructor, .init = redirect_all_stdout)
{
    {
        Ice    ice("ice");

        cr_assert_eq(ice.getType(), "ice");
    }
}

Test(Ice, copy_constructor)
{
    {
        Ice    ice("ice");
        Ice    cpyAmateria(ice);

        cr_assert_eq(cpyAmateria.getType(), "ice");
    }
}

Test(Ice, assignment_operator, .init = redirect_all_stdout)
{
    {
        Ice    ice("ice");
        Ice    assigned;

        assigned = ice;
        cr_assert_eq(assigned.getType(), "ice");
    }
}

Test(Ice, destructor, .init = redirect_all_stdout)
{
    Ice    ice("ice");
    
    cr_assert(true, "Destructor has no crash");
}

Test(Ice, getType_method, .init = redirect_all_stdout)
{
    {
        Ice    ice("ice");

        cr_assert_eq(ice.getType(), "ice");
    }
}

Test(Ice, getType_after_copy, .init = redirect_all_stdout) 
{
    {
        Ice    ice("ice");
        Ice    cpyAmateria(ice);

        cr_assert_eq(cpyAmateria.getType(), "ice");
    }
}

Test(Ice, clone_method_returns_new_instance, .init = redirect_all_stdout)
{
    Ice         original;
    Ice         *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_eq(clone->getType(), "ice");

    delete clone;
}
///////////////////////////////////////////////////////////////////////////////
//                            Cure class                                      //
///////////////////////////////////////////////////////////////////////////////
Test(Cure, TEST_Cure_Default_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Cure    cure;

        cr_assert_not_null(&cure);
    }
}

Test(Cure, TEST_Cure_paramaterized_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Cure    cure("cure");

        cr_assert_not_null(&cure);
    }
}

Test(Cure, TEST_Cure_Copy_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Cure    cure("cure");
        Cure    cpyCure(cure);

        cr_assert_not_null(&cure);
        cr_assert_not_null(&cpyCure);
    }
}

Test(Cure, default_constructor, .init = redirect_all_stdout)
{
    {    
        Cure    cure;

        cr_assert_eq(cure.getType(), "cure");
    
    }
}

Test(Cure, parameterized_constructor, .init = redirect_all_stdout)
{
    {
        Cure    cure("cure");

        cr_assert_eq(cure.getType(), "cure");
    }
}

Test(Cure, copy_constructor)
{
    {
        Cure    cure("cure");
        Cure    cpyCure(cure);

        cr_assert_eq(cpyCure.getType(), "cure");
    }
}

Test(Cure, assignment_operator, .init = redirect_all_stdout)
{
    {
        Cure    cure("cure");
        Cure    assigned;

        assigned = cure;
        cr_assert_eq(assigned.getType(), "cure");
    }
}

Test(Cure, destructor, .init = redirect_all_stdout)
{
    Cure    cure("cure");
    
    cr_assert(true, "Destructor has no crash");
}

Test(Cure, getType_method, .init = redirect_all_stdout)
{
    {
        Cure    cure("cure");

        cr_assert_eq(cure.getType(), "cure");
    }
}

Test(Cure, getType_after_copy, .init = redirect_all_stdout) 
{
    {
        Cure    cure("cure");
        Cure    cpyCure(cure);

        cr_assert_eq(cpyCure.getType(), "cure");
    }
}

Test(Cure, clone_method_returns_new_instance, .init = redirect_all_stdout)
{
    Cure         original;
    Cure         *clone = original.clone();

    cr_assert_not_null(clone);
    cr_assert_eq(clone->getType(), "cure");

    delete clone;
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
// Test(main, Test_main, .init = redirect_all_stdout)
// {
    
//     {       
//         IMateriaSource  src = new MateriaSource();

//         src.learnMateria(new Cure());
//         src.learnMateria(new Cure());

//         ICharacter      me = new Character("me");
//         Cure        tmp;

//         tmp = src.createMateria("cure");
//         me.equip(tmp);
//         tmp = src.createMateria("cure");
//         me.equip(tmp);

//         ICharacter      bob = new Character("bob");

//         me.use(0, bob);
//         me.use(1, bob);
        
//         delete bob;
//         delete me;
//         delete src;
//     }
// }