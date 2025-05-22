/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:59:06 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/22 17:52:23 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/AMateria.hpp"


void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(AMateria, TEST_AMateria_Default_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        AMateria    amateria;

        cr_assert_not_null(&amateria);
    }
}

Test(AMateria, TEST_AMateria_paramaterized_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        AMateria    amateria("ice");

        cr_assert_not_null(&amateria);
    }
}

Test(AMateria, TEST_AMateria_Copy_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        AMateria    amateria;
        AMateria    cpyAmateria(amateria);

        cr_assert_not_null(&amateria);
        cr_assert_not_null(&cpyAmateria);
    }
}

Test(AMateria, default_constructor, .init = redirect_all_stdout)
{
    {    
        AMateria    materia;
        cr_assert_eq(materia.getType(), "Unknown");
    }
}

Test(AMateria, parameterized_constructor, .init = redirect_all_stdout)
{
    {
        AMateria    materia("Fire");
        cr_assert_eq(materia.getType(), "Fire");
    }
}

Test(AMateria, copy_constructor)
{
    {
        AMateria    original("Ice");
        AMateria    copy(original);
        cr_assert_eq(copy.getType(), "Ice");
    }
}

Test(AMateria, assignment_operator, .init = redirect_all_stdout)
{
    {
        AMateria    original("Water");
        AMateria    assigned;

        assigned = original;
        cr_assert_eq(assigned.getType(), "Water");
    }
}

Test(AMateria, destructor, .init = redirect_all_stdout)
{
    AMateria    *materia = new AMateria("Earth");

    delete materia;
    cr_assert(true, "Destructor has no crash");
}

Test(AMateria, getType_method, .init = redirect_all_stdout)
{
    {
        AMateria    materia("Air");

        cr_assert_eq(materia.getType(), "Air");
    }
}

Test(AMateria, getType_after_copy, .init = redirect_all_stdout) 
{
    {
        AMateria    original("Lightning");
        AMateria    copy(original);

        cr_assert_eq(copy.getType(), "Lightning");
    }
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
// Test(main, Test_main, .init = redirect_all_stdout)
// {
    
//     {       
//         IMateriaSource  *src = new MateriaSource();

//         src->learnMateria(new Ice());
//         src->learnMateria(new Cure());

//         ICharacter      *me = new Character("me");
//         AMateria        *tmp;

//         tmp = src->createMateria("ice");
//         me->equip(tmp);
//         tmp = src->createMateria("cure");
//         me->equip(tmp);

//         ICharacter      *bob = new Character("bob");

//         me->use(0, *bob);
//         me->use(1, *bob);
        
//         delete bob;
//         delete me;
//         delete src;
//     }
// }