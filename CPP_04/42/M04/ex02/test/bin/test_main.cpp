/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:59:06 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 03:25:51 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>

#include "../../include/Aanimal.hpp"
#include "../../include/Dog.hpp"
#include "../../include/Cat.hpp"
#include "../../include/WrongAnimal.hpp"
#include "../../include/WrongCat.hpp"
#include "../../include/Brain.hpp"


void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Aanimal, TEST_Aanimal_CTOR, .init = redirect_all_stdout)
{
    {
        Aanimal    *animal;

        cr_assert_not_null(&animal);
    }
}



Test(Aanimal, TEST_Aanimal_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Aanimal    *animal = new Dog;

        
        cr_assert_not_null(&animal);
        delete animal;
    }
}

Test(Aanimal, TEST_Aanimal_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Aanimal    *animal = new Dog;
        
        delete animal;
    }
    cr_assert_stdout_eq_str
    (
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
    );
}

Test(Aanimal, TEST_Aanimal_copy_CTOR, .init = redirect_all_stdout)
{
    {
        Aanimal    *animal = new Dog;
        Aanimal    *cpyAanimal(animal);

        cr_assert_not_null(animal);
        cr_assert_not_null(cpyAanimal);

        delete animal;
    }
}

Test(Aanimal, TEST_Aanimal_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Aanimal    *animal = new Dog;
        Aanimal    *cpyAanimal(animal);

        cr_assert_not_null(animal);
        cr_assert_not_null(cpyAanimal);

        delete animal;
    }
    cr_assert_stdout_eq_str(
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
    );
}

Test(Aanimal, TEST_Aanimal_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Aanimal  *animal = new Dog;

        cr_assert(animal->getType() == "Dog");
        animal->setType("Bird");
        cr_assert(animal->getType() == "Bird");

        delete animal;
    }
}

Test(Aanimal, TEST_Aanimal_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Aanimal  *animal = new Dog();
        Aanimal  *animal2 = new Cat();

        *animal2 = *animal;

        cr_assert(animal->getType() == animal2->getType());

        delete animal;
        delete animal2;
    }
}

Test(Aanimal, TEST_Aanimal_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Aanimal  *animal = new Dog();
        animal = animal;

        cr_assert(animal->getType() == animal->getType());

        delete animal;
    }
}

Test(Aanimal,
TEST_Aanimal_equal_operator_overload_assignment_after_modified_an_object,
.init = redirect_all_stdout)
{
    {
        Aanimal  *animal = new Dog();
        Aanimal  *animal2 = new Cat();


        *animal2 = *animal;
        animal->setType("Mouse");

        cr_assert(animal2->getType() != animal->getType());

        delete animal;
        delete animal2;
    }
}

Test(Aanimal, TEST_Aanimal_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Aanimal  *animal = new Dog();
        Aanimal  *animal2 = new Cat();
        Aanimal   &return_value = (*animal2 = *animal);
        

        cr_assert_eq(&return_value, animal2);

        delete animal;
        delete animal2;
    }
}

Test(Aanimal, TEST_Aanimal_makeSound_stdout, .init = redirect_all_stdout)
{
    {
        Aanimal  *animal = new Dog();
        Aanimal  *animal2 = new Cat();

        animal->makeSound();
        animal2->makeSound();

        delete animal;
        delete animal2;
    }
    
    cr_assert_stdout_eq_str
    (
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Aanimal Custom Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Default Constructor created an Cat animal.\n"
        "Dog sound: OuafOuaf.\n"
        "Cat sound: MiaouMiaou.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
    );
}

Test(Aanimal, TEST_Aanimal_create_arrayAanimal_with_Dog, .init = redirect_all_stdout)
{
    {
	Aanimal *animals[50];

	for (int i = 0; i < 50; i++)
	{
		animals[i] = new Dog();
        cr_assert_not_null(animals[i]);
		animals[i]->makeSound();
		animals[i]->getBrain()->setIdea(0, "newIdea");
		std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[0] << std::endl;
        cr_assert(animals[i]->getBrain()->getIdeas()[0] == "newIdea");
	}

	std::cout << std::endl;

	for (int i = 0; i < 50; i++)
		delete animals[i];
    }
}

Test(Aanimal, TEST_Aanimal_create_arrayAanimal_with_Cat, .init = redirect_all_stdout)
{
    {
	Aanimal *animals[50];

	for (int i = 0; i < 50; i++)
	{
		animals[i] = new Cat();
        cr_assert_not_null(animals[i]);
		animals[i]->makeSound();
		animals[i]->getBrain()->setIdea(0, "newIdea");
		std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[0] << std::endl;
        cr_assert(animals[i]->getBrain()->getIdeas()[0] == "newIdea");
	}

	std::cout << std::endl;

	for (int i = 0; i < 50; i++)
		delete animals[i];
    }
}

// ///////////////////////////////////////////////////////////////////////////////
// //                            Dog class                                      //
// ///////////////////////////////////////////////////////////////////////////////

Test(Dog, TEST_Dog_default_CTOR, .init = redirect_all_stdout)
{
    {
        Dog     dog;

        cr_assert_not_null(&dog);
    }
}

Test(Dog, TEST_Dog_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Dog     dog;
    }
    cr_assert_stdout_eq_str(
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
    );
}

Test(Dog, TEST_Dog_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");

        cr_assert_not_null(&dog);
    }
}

Test(Dog, TEST_Dog_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");
    }
    cr_assert_stdout_eq_str
    (
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
    );
}

Test(Dog, TEST_Dog_copy_CTOR, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");
        Dog     copyDog(dog);

        cr_assert_not_null(&dog);
        cr_assert_not_null(&copyDog);
    }
}

Test(Dog, TEST_Dog_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");
        Dog     copyDog(dog);
    }
    cr_assert_stdout_eq_str(
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Aanimal Copy Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Copy Constructor created a Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
    );
}

Test(Dog, TEST_Dog_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");

        cr_assert(dog.getType() == "Dog");
        dog.setType("Bird");
        cr_assert(dog.getType() == "Bird");

        cr_assert(dog.getBrain()->getIdea(0) == "");
        dog.getBrain()->setIdea(0, "idea");
        cr_assert(dog.getBrain()->getIdea(0) == "idea");

        Brain   brain;

        brain.setIdea(0, "newIdea");
        dog.setBrain(&brain);
        cr_assert(dog.getBrain()->getIdea(0) == "newIdea");
    }
}

Test(Dog, TEST_Dog_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");
        Dog     dog2("Dog");

        dog2 = dog;

        cr_assert(dog.getType() == dog2.getType());
    }
}

Test(Dog, TEST_Dog_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");

        dog = dog;

        cr_assert(dog.getType() == dog.getType());
    }
}

Test(Dog, TEST_Dog_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");
        Dog     dog2("Bird");


        dog2 = dog;
        dog.setType("Mouse");

        cr_assert(dog2.getType() != dog.getType());
    }
}

Test(Dog, TEST_Dog_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");
        Dog     dog2("Bird");
        Aanimal    &return_value = (dog2 = dog);
        

        cr_assert_eq(&return_value, &dog2);
    }
}

Test(Dog, TEST_Dog_makeSound_should_display_Dog_sound_stdout, .init = redirect_all_stdout)
{
    {
        Aanimal      *dog = new Dog();
        Aanimal      *dog2 = new Dog("Dog");
        Dog         dog3;
        Dog         dog4("Dog");

        dog->makeSound();
        dog2->makeSound();
        dog3.makeSound();
        dog4.makeSound();

        delete dog;
        delete dog2;
    }
    cr_assert_stdout_eq_str
    (
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Aanimal Custom Constructor created a Dog animal.\n"
        "Brain Default Constructor called.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Dog sound: OuafOuaf.\n"
        "Dog sound: OuafOuaf.\n"
        "Dog sound: OuafOuaf.\n"
        "Dog sound: OuafOuaf.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
        "Brain Destructor called.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Aanimal Destructor destroyed a Dog animal.\n"
    );
}

Test(Dog, TEST_Dog_create_brain_at_construction_destroy_brain_at_the_destruction, .init = redirect_all_stdout)
{
    {
        const Aanimal     *dog = new Dog();

        cr_assert(dog->getBrain()->getIdea(0) == "");

        delete dog;
    }
}
// ///////////////////////////////////////////////////////////////////////////////
// //                            Cat class                                      //
// ///////////////////////////////////////////////////////////////////////////////

Test(Cat, TEST_Cat_default_CTOR, .init = redirect_all_stdout)
{
    {
        Cat     cat;

        cr_assert_not_null(&cat);
    }
}

Test(Cat, TEST_Cat_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Cat     cat;
    }
    cr_assert_stdout_eq_str(
        "Aanimal Custom Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Default Constructor created an Cat animal.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
    );
}

Test(Cat, TEST_Cat_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");

        cr_assert_not_null(&cat);
    }
}

Test(Cat, TEST_Cat_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");
    }
    cr_assert_stdout_eq_str
    (
        "Aanimal Custom Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
    );  
}

Test(Cat, TEST_Cat_copy_CTOR, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");
        Cat     copyCat(cat);

        cr_assert_not_null(&cat);
        cr_assert_not_null(&copyCat);
    }
}

Test(Cat, TEST_Cat_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");
        Cat     copyCat(cat);
    }
    cr_assert_stdout_eq_str(
        "Aanimal Custom Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Aanimal Copy Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Copy Constructor created a Cat animal.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
    );
}

Test(Cat, TEST_Cat_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");

        cr_assert(cat.getType() == "Cat");
        cat.setType("Bird");
        cr_assert(cat.getType() == "Bird");

        cr_assert(cat.getBrain()->getIdea(0) == "");
        cat.getBrain()->setIdea(0, "idea");
        cr_assert(cat.getBrain()->getIdea(0) == "idea");

        Brain   brain;

        brain.setIdea(0, "newIdea");
        cat.setBrain(&brain);
        cr_assert(cat.getBrain()->getIdea(0) == "newIdea");
    }
}

Test(Cat, TEST_Cat_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");
        Cat     cat2("Cat");

        cat2 = cat;

        cr_assert(cat.getType() == cat2.getType());
    }
}

Test(Cat, TEST_Cat_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");

        cat = cat;

        cr_assert(cat.getType() == cat.getType());
    }
}

Test(Cat, TEST_Cat_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");
        Cat     cat2("Bird");


        cat2 = cat;
        cat.setType("Mouse");

        cr_assert(cat2.getType() != cat.getType());
    }
}

Test(Cat, TEST_Cat_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");
        Cat     cat2("Bird");
        Aanimal    &return_value = (cat2 = cat);
        

        cr_assert_eq(&return_value, &cat2);
    }
}

Test(Cat, TEST_Cat_makeSound_should_display_Cat_sound_stdout, .init = redirect_all_stdout)
{
    {
        Aanimal      *cat = new Cat();
        Aanimal      *cat2 = new Cat("Cat");
        Cat         cat3;
        Cat         cat4("Cat");

        cat->makeSound();
        cat2->makeSound();
        cat3.makeSound();
        cat4.makeSound();

        delete cat;
        delete cat2;
    }
    
    cr_assert_stdout_eq_str
    (
        "Aanimal Custom Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Default Constructor created an Cat animal.\n"
        "Aanimal Custom Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Aanimal Custom Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Default Constructor created an Cat animal.\n"
        "Aanimal Custom Constructor created a Cat animal.\n"
        "Brain Default Constructor called.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Cat sound: MiaouMiaou.\n"
        "Cat sound: MiaouMiaou.\n"
        "Cat sound: MiaouMiaou.\n"
        "Cat sound: MiaouMiaou.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
        "Brain Destructor called.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Aanimal Destructor destroyed a Cat animal.\n"
    );
}

Test(Cat, TEST_Cat_create_brain_at_construction_destroy_brain_at_the_destruction, .init = redirect_all_stdout)
{
    {
        const Aanimal     *cat = new Cat();

        cr_assert(cat->getBrain()->getIdea(0) == "");

        delete cat;
    }
}
// ///////////////////////////////////////////////////////////////////////////////
// //                      WrongAnimal class                                    //
// ///////////////////////////////////////////////////////////////////////////////

Test(WrongAnimal, TEST_WrongAnimal_default_CTOR, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal;

        cr_assert_not_null(&wrongAanimal);
    }
}

Test(WrongAnimal, TEST_WrongAnimal_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal;
    }
    cr_assert_stdout_eq_str(
        "WrongAnimal Default Constructor created an Unknown animal.\n"
        "WrongAnimal Destructor destroyed a Unknown animal.\n"
    );
}

Test(WrongAnimal, TEST_WrongAnimal_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");

        cr_assert_not_null(&wrongAanimal);
    }
}

Test(WrongAnimal, TEST_WrongAnimal_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");
    }
    cr_assert_stdout_eq_str(
        "WrongAnimal Custom Constructor created a Bear animal.\n"
        "WrongAnimal Destructor destroyed a Bear animal.\n"
    );
}

Test(WrongAnimal, TEST_WrongAnimal_copy_CTOR, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");
        WrongAnimal    cpyWrongAnimal(wrongAanimal);

        cr_assert_not_null(&wrongAanimal);
        cr_assert_not_null(&cpyWrongAnimal);
    }
}

Test(WrongAnimal, TEST_WrongAnimal_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");
        WrongAnimal    cpyWrongAnimal(wrongAanimal);
    }
    cr_assert_stdout_eq_str(
        "WrongAnimal Custom Constructor created a Bear animal.\n"
        "WrongAnimal Copy Constructor created a Bear animal.\n"
        "WrongAnimal Destructor destroyed a Bear animal.\n"
        "WrongAnimal Destructor destroyed a Bear animal.\n"

    );
}

Test(WrongAnimal, TEST_WrongAnimal_getters_and_setters, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");

        cr_assert(wrongAanimal.getType() == "Bear");
        wrongAanimal.setType("Bird");
        cr_assert(wrongAanimal.getType() == "Bird");
    }
}

Test(WrongAnimal, TEST_WrongAnimal_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");
        WrongAnimal    wrongAanimal2("Bear");

        wrongAanimal2 = wrongAanimal;

        cr_assert(wrongAanimal.getType() == wrongAanimal2.getType());
    }
}

Test(WrongAnimal, TEST_WrongAnimal_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");

        wrongAanimal = wrongAanimal;

        cr_assert(wrongAanimal.getType() == wrongAanimal.getType());
    }
}

Test(WrongAnimal, TEST_WrongAnimal_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");
        WrongAnimal    wrongAanimal2("Bird");


        wrongAanimal2 = wrongAanimal;
        wrongAanimal.setType("Mouse");

        cr_assert(wrongAanimal2.getType() != wrongAanimal.getType());
    }
}

Test(WrongAnimal, TEST_WrongAnimal_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAanimal("Bear");
        WrongAnimal    wrongAanimal2("Bird");
        WrongAnimal    &return_value = (wrongAanimal2 = wrongAanimal);
        

        cr_assert_eq(&return_value, &wrongAanimal2);
    }
}

Test(WrongAnimal, TEST_WrongAnimal_makeSound_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal  wrongAanimal;
        WrongAnimal  wrongAanimal2("Bear");

        wrongAanimal.makeSound();
        wrongAanimal2.makeSound();

    }
    
    cr_assert_stdout_eq_str
    (
        "WrongAnimal Default Constructor created an Unknown animal.\n"
        "WrongAnimal Custom Constructor created a Bear animal.\n"
        "Unknown animal sound.\n"
        "Bear animal sound.\n"
        "WrongAnimal Destructor destroyed a Bear animal.\n"
        "WrongAnimal Destructor destroyed a Unknown animal.\n"
    );
}

// ///////////////////////////////////////////////////////////////////////////////
// //                            WrongCat class                                 //
// ///////////////////////////////////////////////////////////////////////////////

Test(WrongCat, TEST_WrongCat_default_CTOR, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat;

        cr_assert_not_null(&wrongCat);
    }
}

Test(WrongCat, TEST_WrongCat_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat;
    }
    cr_assert_stdout_eq_str(
        "WrongAnimal Custom Constructor created a WrongCat animal.\n"
        "WrongCat Default Constructor created an WrongCat animal.\n"
        "WrongCat Destructor destroyed a WrongCat animal.\n"
        "WrongAnimal Destructor destroyed a WrongCat animal.\n"
    );
}

Test(WrongCat, TEST_WrongCat_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");

        cr_assert_not_null(&wrongCat);
    }
}

Test(WrongCat, TEST_WrongCat_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");
    }
    cr_assert_stdout_eq_str
    (
        "WrongAnimal Custom Constructor created a WrongCat animal.\n"
        "WrongCat Custom Constructor created a WrongCat animal.\n"
        "WrongCat Destructor destroyed a WrongCat animal.\n"
        "WrongAnimal Destructor destroyed a WrongCat animal.\n"
    );
}

Test(WrongCat, TEST_WrongCat_copy_CTOR, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");
        WrongCat     copyWrongCat(wrongCat);

        cr_assert_not_null(&wrongCat);
        cr_assert_not_null(&copyWrongCat);
    }
}

Test(WrongCat, TEST_WrongCat_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");
        WrongCat     copyWrongCat(wrongCat);
    }
    cr_assert_stdout_eq_str(
        "WrongAnimal Custom Constructor created a WrongCat animal.\n"
        "WrongCat Custom Constructor created a WrongCat animal.\n"
        "WrongAnimal Copy Constructor created a WrongCat animal.\n"
        "WrongCat Copy Constructor created a WrongCat animal.\n"
        "WrongCat Destructor destroyed a WrongCat animal.\n"
        "WrongAnimal Destructor destroyed a WrongCat animal.\n"
        "WrongCat Destructor destroyed a WrongCat animal.\n"
        "WrongAnimal Destructor destroyed a WrongCat animal.\n"
    );
}

Test(WrongCat, TEST_WrongCat_getters_and_setters, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");

        cr_assert(wrongCat.getType() == "WrongCat");
        wrongCat.setType("Bird");
        cr_assert(wrongCat.getType() == "Bird");
    }
}

Test(WrongCat, TEST_WrongCat_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");
        WrongCat     wrongCat2("WrongCat");

        wrongCat2 = wrongCat;

        cr_assert(wrongCat.getType() == wrongCat2.getType());
    }
}

Test(WrongCat, TEST_WrongCat_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");

        wrongCat = wrongCat;

        cr_assert(wrongCat.getType() == wrongCat.getType());
    }
}

Test(WrongCat, TEST_WrongCat_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");
        WrongCat     wrongCat2("Bird");


        wrongCat2 = wrongCat;
        wrongCat.setType("Mouse");

        cr_assert(wrongCat2.getType() != wrongCat.getType());
    }
}

Test(WrongCat, TEST_WrongCat_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat("WrongCat");
        WrongCat     wrongCat2("Bird");
        WrongAnimal    &return_value = (wrongCat2 = wrongCat);
        

        cr_assert_eq(&return_value, &wrongCat2);
    }
}

Test(WrongCat, TEST_WrongCat_makeSound_stdout, .init = redirect_all_stdout)
{
    {
        WrongCat     wrongCat;
        WrongCat     wrongCat2("WrongCat");

        wrongCat.makeSound();
        wrongCat2.makeSound();
    }
    
    cr_assert_stdout_eq_str
    (
        "WrongAnimal Custom Constructor created a WrongCat animal.\n"
        "WrongCat Default Constructor created an WrongCat animal.\n"
        "WrongAnimal Custom Constructor created a WrongCat animal.\n"
        "WrongCat Custom Constructor created a WrongCat animal.\n"
        "WrongCat sound: MiaouMiaou.\n"
        "WrongCat sound: MiaouMiaou.\n"
        "WrongCat Destructor destroyed a WrongCat animal.\n"
        "WrongAnimal Destructor destroyed a WrongCat animal.\n"
        "WrongCat Destructor destroyed a WrongCat animal.\n"
        "WrongAnimal Destructor destroyed a WrongCat animal.\n"
    );
}
// ////////////////////////////////////////////////////////////////////////////
Test(makeSound, TEST_makeSound_with_wrong_animals_call_wrong_sound_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal   *wrongMeta = new WrongAnimal();
        WrongAnimal   *wrongCat = new WrongCat();

        wrongMeta->makeSound();
        wrongCat->makeSound();

        delete wrongMeta;
        delete wrongCat;
    }
    
    cr_assert_stdout_eq_str
    (
        "WrongAnimal Default Constructor created an Unknown animal.\n"
        "WrongAnimal Custom Constructor created a WrongCat animal.\n"
        "WrongCat Default Constructor created an WrongCat animal.\n"
        "Unknown animal sound.\n"
        "WrongCat animal sound.\n"
        "WrongAnimal Destructor destroyed a Unknown animal.\n"
        "WrongCat Destructor destroyed a WrongCat animal.\n"
        "WrongAnimal Destructor destroyed a WrongCat animal.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Brain class                                    //
///////////////////////////////////////////////////////////////////////////////

Test(Brain, TEST_Brain_default_CTOR, .init = redirect_all_stdout)
{
    {
        Brain     brain;

        cr_assert_not_null(&brain);
    }
}

Test(Brain, TEST_Brain_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Brain     brain;
    }
    cr_assert_stdout_eq_str(
        "Brain Default Constructor called.\n"
        "Brain Destructor called.\n"
    );
}

Test(Brain, TEST_Brain_copy_CTOR, .init = redirect_all_stdout)
{
    {
        Brain     brain;
        Brain     copyBrain(brain);

        cr_assert_not_null(&brain);
        cr_assert_not_null(&copyBrain);
    }
}

Test(Brain, TEST_Brain_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Brain     brain;
        Brain     copyBrain(brain);
    }
    cr_assert_stdout_eq_str(
        "Brain Default Constructor called.\n"
        "Brain Copy Constructor called.\n"
        "Brain Destructor called.\n"
        "Brain Destructor called.\n"
    );
}

Test(Brain, TEST_Brain_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Brain     brain;

        cr_assert_not_null(brain.getIdeas());
        for (size_t i = 0; i < SIZE; ++i)
            cr_assert(brain.getIdeas()[i] == "");

        std::string *newIdeas = new std::string[SIZE];
        for (size_t i = 0; i < SIZE; ++i)
            newIdeas[i] = "newIdeas";

        brain.setIdeas(newIdeas);
        for (size_t i = 0; i < SIZE; ++i)
            cr_assert(brain.getIdeas()[i] == "newIdeas");

        cr_assert(brain.getIdea(10) == "newIdeas");
        brain.setIdea(10, "oldIdea");
        cr_assert(brain.getIdea(10) == "oldIdea");

        delete [] newIdeas;
    }
}

Test(Brain, TEST_Brain_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Brain     brain;
        Brain     brain2;

        brain.setIdea(0, "idea");
        cr_assert(brain.getIdea(0) == "idea");

        brain2.setIdea(0, "newIdea");
        cr_assert(brain2.getIdea(0) == "newIdea");
        brain = brain2;

        cr_assert(brain.getIdea(0) == brain2.getIdea(0));
    }
}

Test(Brain, TEST_Brain_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Brain     brain;

        brain.setIdea(0, "idea");
        cr_assert(brain.getIdea(0) == "idea");

        brain = brain;

        cr_assert(brain.getIdea(0) == brain.getIdea(0));
    }
}

Test(Brain, TEST_Brain_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Brain     brain;
        Brain     brain2;

        brain.setIdea(0, "idea");
        cr_assert(brain.getIdea(0) == "idea");

        brain2.setIdea(0, "newIdea");
        cr_assert(brain2.getIdea(0) == "newIdea");

        brain2 = brain;
        brain.setIdea(0, "oldIdea");
        cr_assert(brain.getIdea(0) == "oldIdea");

        cr_assert(brain2.getIdea(0) != brain.getIdea(0));
    }
}

Test(Brain, TEST_Brain_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Brain     brain;
        Brain     brain2;

        brain.setIdea(0, "idea");
        cr_assert(brain.getIdea(0) == "idea");

        brain2.setIdea(0, "newIdea");
        cr_assert(brain2.getIdea(0) == "newIdea");

        Brain    &return_value = (brain2 = brain);
        

        cr_assert_eq(&return_value, &brain2);
    }
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    
    {       
        Aanimal *animals[100];

        for (int i = 0; i < 100; i++)
        {
            if (i % 2)
            {
                animals[i] = new Dog();
                animals[i]->getBrain()->setIdea(0, "Dog Idea");
                cr_assert(animals[i]->getBrain()->getIdeas()[0] == "Dog Idea");
            }
            else
            {
                animals[i] = new Cat();
                animals[i]->getBrain()->setIdea(0, "Cat Idea");
                cr_assert(animals[i]->getBrain()->getIdeas()[0] == "Cat Idea");
            }
            cr_assert_not_null(animals[i]);
            animals[i]->makeSound();
            std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[0] << std::endl;
        }

        for (int i = 0; i < 100; i++)
            delete animals[i];
    }
}