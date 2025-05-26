/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:05:30 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/26 18:20:26 by Paradis          ###   ########.fr       */
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
#include "../../include/Character.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
///////////FOR COVERAGE :
class DummyMateria : public AMateria {
    public:
        DummyMateria()  {} //: AMateria("Unknown") {}
        DummyMateria(const std::string &type) : AMateria(type) {}
        DummyMateria(const DummyMateria &materia) : AMateria(materia) {}

        DummyMateria &operator=(const DummyMateria &materia) {
            AMateria::operator=(materia);
            return *this;
        }
        AMateria* clone() const override { return new DummyMateria(*this); }
        void use(ICharacter&) override {} // Vide, comme la base
    };

    class DummyCharacter : public ICharacter {
    public:
        std::string const &getName() const override {
            static std::string name = "TestChar";
            return name;
        }
        // void equip(AMateria*) override {}
        // void unequip(int) override {}
        // void use(int, ICharacter&) override {}
    };

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

Test(AMateria, default_constructor_coverage, .init = redirect_all_stdout)
{
    {
        DummyMateria d;
        cr_assert_str_eq(d.getType().c_str(), "Unknown");

        AMateria *amateria = d.clone();
        cr_assert(dynamic_cast<DummyMateria *>(amateria) != nullptr);
        cr_assert_eq(amateria->getType(), "Unknown");

        delete amateria;
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

Test(AMateria, copy_constructor_covarage)
{
    {
        DummyMateria d("ice");
        DummyMateria cpy(d);
        cr_assert(d.getType() == cpy.getType());
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
Test(AMateria, assignment_operator_coverage, .init = redirect_all_stdout)
{
    {
        DummyMateria a("ice");
        DummyMateria b("fire");

        b = a;
        cr_assert_eq(b.getType(), "ice");
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

Test(AMateria, use_method_coverage, .init = redirect_all_stdout)
{
    ICharacter  *test = new Character();

    DummyMateria *d = new DummyMateria("test");
    d->use(*test);
    delete d;

    AMateria *amateria = new Ice("ice");
    amateria->use(*test);
    delete amateria;

    AMateria *pure = new DummyMateria("pure");
    pure->AMateria::use(*test);
    delete pure;

    delete test;

    cr_assert(true, "use method display nothing");
}

Test(AMateria, use_method, .init = redirect_all_stdout)
{
    AMateria    *amateria = new Ice("ice");
    ICharacter  *test = new Character();

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

Test(Ice, use_method_display_msg, .init = redirect_all_stdout)
{
    {
        ICharacter      *me = new Character("Bob");
        Ice             ice;

        ice.use(*me);

        delete me;
    }
    cr_assert_stdout_eq_str
    (
        "* shoots an ice bolt at Bob *\n"
    );
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

Test(Cure, use_method_display_msg, .init = redirect_all_stdout)
{
    {
        ICharacter      *me = new Character("Bob");
        Cure            cure;

        cure.use(*me);

        delete me;
    }
    cr_assert_stdout_eq_str
    (
        "* heals Bob's wounds *\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            Character class                                //
///////////////////////////////////////////////////////////////////////////////
Test(Character, TEST_Character_Default_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Character    character;

        cr_assert_not_null(&character);
    }
}

Test(Character, TEST_Character_paramaterized_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Character    character("Bob");

        cr_assert_not_null(&character);
    }
}

Test(Character, TEST_Character_Copy_CTOR_isDefined, .init = redirect_all_stdout)
{
    {
        Character    character("Bob");
        Character    cpyCharacter(character);

        cr_assert_not_null(&character);
        cr_assert_not_null(&cpyCharacter);
    }
}

Test(Character, default_constructor, .init = redirect_all_stdout)
{
    {    
        Character    character;

        cr_assert(character.getName() == "Unknown");
    
    }
}

Test(Character, parameterized_constructor, .init = redirect_all_stdout)
{
    {
        Character    character("Bob");

        cr_assert_eq(character.getName(), "Bob");
    }
}

Test(Character, copy_constructor, .init = redirect_all_stdout)
{
    {
        Character    character;
        AMateria        *tmp = new Ice;

        character.equip(tmp);
        Character    cpyCharacter(character);

        cr_assert_eq(cpyCharacter.getName(), "Unknown");
    }
}

Test(Character, assignment_operator, .init = redirect_all_stdout)
{
    {
        Character    character("Bob");
        Character    assigned;
        AMateria        *tmp = new Ice;

        character.equip(tmp);
        assigned = character;
        character = assigned;

        cr_assert_eq(assigned.getName(), "Bob");
    }
}

Test(Character, destructor, .init = redirect_all_stdout)
{
    Character    character("Bob");
    
    cr_assert(true, "Destructor has no crash");
}

Test(Character, getName_method, .init = redirect_all_stdout)
{
    {
        Character    character("Bob");

        cr_assert_eq(character.getName(), "Bob");
    }
}

Test(Character, getName_after_copy, .init = redirect_all_stdout) 
{
    {
        Character    character("Bob");
        Character    cpyCharacter(character);

        cr_assert_eq(cpyCharacter.getName(), "Bob");
    }
}

Test(Character, equip_method_but_Materia_doesnt_exist, .init = redirect_all_stdout) 
{
    {
        ICharacter      *me = new Character("me");
        AMateria        *tmp = nullptr;

        me->equip(tmp);

        delete me;
    }
    cr_assert_stdout_eq_str
    (
        "Materia doesn't exist.\n"
    );
}

Test(Character, equip_method_can_equip_materia_should_display_msg, .init = redirect_all_stdout) 
{
    {
        ICharacter      *me = new Character("me");
        AMateria        *tmp = new Ice;

        me->equip(tmp->clone());
        me->equip(tmp->clone());
        me->equip(tmp->clone());
        me->equip(tmp->clone());

        delete me;
        delete tmp;
    }
    cr_assert_stdout_eq_str
    (
        "Emplacement 0 is equiped.\n"
        "Emplacement 1 is equiped.\n"
        "Emplacement 2 is equiped.\n"
        "Emplacement 3 is equiped.\n"
    );
}

Test(Character, equip_method_with_full_inventory_should_display_msg, .init = redirect_all_stdout) 
{
    {
        ICharacter *me = new Character("me");
        AMateria   *tmp = new Ice;

        for (int i = 0; i < 6; ++i) {
            AMateria *cloned = tmp->clone();
            me->equip(cloned);

            if (i >= INVENTORY_SIZE)
                delete cloned;
        }

        delete me;
        delete tmp;
    }
    cr_assert_stdout_eq_str
    (
        "Emplacement 0 is equiped.\n"
        "Emplacement 1 is equiped.\n"
        "Emplacement 2 is equiped.\n"
        "Emplacement 3 is equiped.\n"
        "Inventory is full.\n"
        "Inventory is full.\n"
    );
}

Test(Character, unequip_method_can_unequip_materia_display_msg, .init = redirect_all_stdout) 
{
    {
        AMateria *materias[INVENTORY_SIZE] = {nullptr};
        ICharacter *me = new Character("me");
        AMateria *tmp = new Ice;

        for (int i = 0; i < INVENTORY_SIZE; ++i) {
            materias[i] = tmp->clone();
            me->equip(materias[i]);
        }

        // Sauvegarde les pointeurs avant le unequip
        AMateria *unequipped[INVENTORY_SIZE] = {nullptr};
        for (int i = 0; i < INVENTORY_SIZE; ++i)
            unequipped[i] = materias[i];

        for (int i = 0; i < INVENTORY_SIZE; ++i)
            me->unequip(i);

        for (int i = 0; i < INVENTORY_SIZE; ++i)
            delete unequipped[i];

        delete tmp;  // prototype
        delete me;

    }
    cr_assert_stdout_eq_str
    (
        "Emplacement 0 is equiped.\n"
        "Emplacement 1 is equiped.\n"
        "Emplacement 2 is equiped.\n"
        "Emplacement 3 is equiped.\n"
        "Emplacement 0 is unequipped.\n"
        "Emplacement 1 is unequipped.\n"
        "Emplacement 2 is unequipped.\n"
        "Emplacement 3 is unequipped.\n"
    );
}

Test(Character, unequip_method_try_to_unequip_empty_slot_display_msg, .init = redirect_all_stdout) 
{
    {
        AMateria    *garbage = nullptr;
        Character   *me = new Character("me");
        AMateria    *tmp = new Ice;

        garbage = tmp->clone();
        me->equip(garbage);
        me->unequip(0);
        me->unequip(0);
        me->unequip(1);
        me->unequip(2);
        me->unequip(3);

        delete me;
        delete tmp;
        delete garbage;
    }


    cr_assert_stdout_eq_str
    (
        "Emplacement 0 is equiped.\n"
        "Emplacement 0 is unequipped.\n"
        "Emplacement 0 is empty.\n"
        "Emplacement 1 is empty.\n"
        "Emplacement 2 is empty.\n"
        "Emplacement 3 is empty.\n"
    );
}

Test(Character, unequip_method_use_wrong_index_display_msg, .init = redirect_all_stdout) 
{
    {
        ICharacter      *me = new Character("me");
        AMateria        *tmp = new Ice;

        me->equip(tmp->clone());
        me->unequip(-1);
        me->unequip(4);

        delete me;
        delete tmp;
    }
    cr_assert_stdout_eq_str
    (
        "Emplacement 0 is equiped.\n"
        "No slot at the index.\n"
        "No slot at the index.\n"
    );
}

Test(Character, use_method_use_wrong_index_display_msg, .init = redirect_all_stdout) 
{
    {
        ICharacter      *me = new Character("me");

        me->use(-1, *me);
        me->use(4, *me);

        delete me;
    }
    cr_assert_stdout_eq_str
    (
        "Emplacement -1 doesn't exist.\n"
        "Emplacement 4 doesn't exist.\n"
    );
}

Test(Character, use_method_try_to_use_empty_slot_display_msg, .init = redirect_all_stdout) 
{
    {
        ICharacter      *me = new Character("me");

        me->use(0, *me);
        me->use(1, *me);
        me->use(2, *me);
        me->use(3, *me);

        delete me;
    }
    cr_assert_stdout_eq_str
    (
        "Emplacement 0 is empty.\n"
        "Emplacement 1 is empty.\n"
        "Emplacement 2 is empty.\n"
        "Emplacement 3 is empty.\n"
    );
}

Test(Character, use_method_use_materia_display_msg, .init = redirect_all_stdout) 
{
    {
        ICharacter      *me = new Character("me");
        AMateria        *tmp = new Cure;

        me->equip(tmp->clone());
        me->equip(tmp->clone());
        me->equip(tmp->clone());
        me->equip(tmp->clone());
        me->use(0, *me);
        me->use(1, *me);
        me->use(2, *me);
        me->use(3, *me);

        delete me;
        delete tmp;
    }
    cr_assert_stdout_eq_str
    (
        "Emplacement 0 is equiped.\n"
        "Emplacement 1 is equiped.\n"
        "Emplacement 2 is equiped.\n"
        "Emplacement 3 is equiped.\n"
        "* heals me's wounds *\n"
        "Materia at the index: 0 is used.\n"
        "* heals me's wounds *\n"
        "Materia at the index: 1 is used.\n"
        "* heals me's wounds *\n"
        "Materia at the index: 2 is used.\n"
        "* heals me's wounds *\n"
        "Materia at the index: 3 is used.\n"
    );
}
////NOT FINIDHED 

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
// Test(main, Test_main)//, .init = redirect_all_stdout)
// {
    
//     {       
//         // IMateriaSource  src = new MateriaSource();

//         // src.learnMateria(new Cure());
//         // src.learnMateria(new Cure());

//         ICharacter      *me = new Character("me");
//         AMateria        *tmp = new Ice;
//         // tmp = src.createMateria("cure");
//         me->equip(tmp);
//         me->equip(tmp);

//         ICharacter      *bob = new Character("bob");

//         me->use(0, *bob);
//         me->use(1, *bob);
        
//         delete bob;
//         delete me;
//         // delete src;
//     }
// }


