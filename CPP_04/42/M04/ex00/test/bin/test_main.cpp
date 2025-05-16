/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:59:06 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 20:11:36 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <string>

#include "../../include/Animal.hpp"
#include "../../include/Dog.hpp"
#include "../../include/Cat.hpp"
#include "../../include/WrongAnimal.hpp"
#include "../../include/WrongCat.hpp"


void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Animal, TEST_Animal_default_CTOR, .init = redirect_all_stdout)
{
    {
        Animal    animal;

        cr_assert_not_null(&animal);
    }
}

Test(Animal, TEST_Animal_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Animal    animal;
    }
    cr_assert_stdout_eq_str(
        "Animal Default Constructor created an Unknown animal.\n"
        "Animal Destructor destroyed a Unknown animal.\n"
    );
}

Test(Animal, TEST_Animal_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");

        cr_assert_not_null(&animal);
    }
}

Test(Animal, TEST_Animal_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");
    }
    cr_assert_stdout_eq_str(
        "Animal Custom Constructor created a Bear animal.\n"
        "Animal Destructor destroyed a Bear animal.\n"
    );
}

Test(Animal, TEST_Animal_copy_CTOR, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");
        Animal    cpyAnimal(animal);

        cr_assert_not_null(&animal);
        cr_assert_not_null(&cpyAnimal);
    }
}

Test(Animal, TEST_Animal_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");
        Animal    cpyAnimal(animal);
    }
    cr_assert_stdout_eq_str(
        "Animal Custom Constructor created a Bear animal.\n"
        "Animal Copy Constructor created a Bear animal.\n"
        "Animal Destructor destroyed a Bear animal.\n"
        "Animal Destructor destroyed a Bear animal.\n"

    );
}

Test(Animal, TEST_Animal_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");

        cr_assert(animal.getType() == "Bear");
        animal.setType("Bird");
        cr_assert(animal.getType() == "Bird");
    }
}

Test(Animal, TEST_Animal_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");
        Animal    animal2("Bear");

        animal2 = animal;

        cr_assert(animal.getType() == animal2.getType());
    }
}

Test(Animal, TEST_Animal_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");

        animal = animal;

        cr_assert(animal.getType() == animal.getType());
    }
}

Test(Animal, TEST_Animal_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");
        Animal    animal2("Bird");


        animal2 = animal;
        animal.setType("Mouse");

        cr_assert(animal2.getType() != animal.getType());
    }
}

Test(Animal, TEST_Animal_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        Animal    animal("Bear");
        Animal    animal2("Bird");
        Animal    &return_value = (animal2 = animal);
        

        cr_assert_eq(&return_value, &animal2);
    }
}

Test(Animal, TEST_Animal_makeSound_stdout, .init = redirect_all_stdout)
{
    {
        Animal  animal;
        Animal  animal2("Bear");

        animal.makeSound();
        animal2.makeSound();

    }
    
    cr_assert_stdout_eq_str
    (
        "Animal Default Constructor created an Unknown animal.\n"
        "Animal Custom Constructor created a Bear animal.\n"
        "Unknown animal sound.\n"
        "Bear animal sound.\n"
        "Animal Destructor destroyed a Bear animal.\n"
        "Animal Destructor destroyed a Unknown animal.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Dog class                                      //
///////////////////////////////////////////////////////////////////////////////

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
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Animal Destructor destroyed a Dog animal.\n"
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
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Animal Destructor destroyed a Dog animal.\n"
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
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Animal Copy Constructor created a Dog animal.\n"
        "Dog Copy Constructor created a Dog animal.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Animal Destructor destroyed a Dog animal.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Animal Destructor destroyed a Dog animal.\n"
    );
}

Test(Dog, TEST_Dog_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Dog     dog("Dog");

        cr_assert(dog.getType() == "Dog");
        dog.setType("Bird");
        cr_assert(dog.getType() == "Bird");
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
        Animal    &return_value = (dog2 = dog);
        

        cr_assert_eq(&return_value, &dog2);
    }
}

Test(Dog, TEST_Dog_makeSound_should_display_Dog_sound_stdout, .init = redirect_all_stdout)
{
    {
        Animal      *dog = new Dog();
        Animal      *dog2 = new Dog("Dog");
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
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Dog sound: OuafOuaf.\n"
        "Dog sound: OuafOuaf.\n"
        "Dog sound: OuafOuaf.\n"
        "Dog sound: OuafOuaf.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Animal Destructor destroyed a Dog animal.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Animal Destructor destroyed a Dog animal.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Animal Destructor destroyed a Dog animal.\n"
        "Dog Destructor destroyed a Dog animal.\n"
        "Animal Destructor destroyed a Dog animal.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            Cat class                                      //
///////////////////////////////////////////////////////////////////////////////

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
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Default Constructor created an Cat animal.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
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
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
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
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Animal Copy Constructor created a Cat animal.\n"
        "Cat Copy Constructor created a Cat animal.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
    );
}

Test(Cat, TEST_Cat_getters_and_setters, .init = redirect_all_stdout)
{
    {
        Cat     cat("Cat");

        cr_assert(cat.getType() == "Cat");
        cat.setType("Bird");
        cr_assert(cat.getType() == "Bird");
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
        Animal    &return_value = (cat2 = cat);
        

        cr_assert_eq(&return_value, &cat2);
    }
}

Test(Cat, TEST_Cat_makeSound_should_display_Cat_sound_stdout, .init = redirect_all_stdout)
{
    {
        Animal      *cat = new Cat();
        Animal      *cat2 = new Cat("Cat");
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
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Default Constructor created an Cat animal.\n"
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Default Constructor created an Cat animal.\n"
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Cat sound: MiaouMiaou.\n"
        "Cat sound: MiaouMiaou.\n"
        "Cat sound: MiaouMiaou.\n"
        "Cat sound: MiaouMiaou.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                      WrongAnimal class                                    //
///////////////////////////////////////////////////////////////////////////////

Test(WrongAnimal, TEST_WrongAnimal_default_CTOR, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal;

        cr_assert_not_null(&wrongAnimal);
    }
}

Test(WrongAnimal, TEST_WrongAnimal_default_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal;
    }
    cr_assert_stdout_eq_str(
        "WrongAnimal Default Constructor created an Unknown animal.\n"
        "WrongAnimal Destructor destroyed a Unknown animal.\n"
    );
}

Test(WrongAnimal, TEST_WrongAnimal_Custom_CTOR, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal("Bear");

        cr_assert_not_null(&wrongAnimal);
    }
}

Test(WrongAnimal, TEST_WrongAnimal_Custom_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal("Bear");
    }
    cr_assert_stdout_eq_str(
        "WrongAnimal Custom Constructor created a Bear animal.\n"
        "WrongAnimal Destructor destroyed a Bear animal.\n"
    );
}

Test(WrongAnimal, TEST_WrongAnimal_copy_CTOR, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal("Bear");
        WrongAnimal    cpyWrongAnimal(wrongAnimal);

        cr_assert_not_null(&wrongAnimal);
        cr_assert_not_null(&cpyWrongAnimal);
    }
}

Test(WrongAnimal, TEST_WrongAnimal_copy_CTOR_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal("Bear");
        WrongAnimal    cpyWrongAnimal(wrongAnimal);
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
        WrongAnimal    wrongAnimal("Bear");

        cr_assert(wrongAnimal.getType() == "Bear");
        wrongAnimal.setType("Bird");
        cr_assert(wrongAnimal.getType() == "Bird");
    }
}

Test(WrongAnimal, TEST_WrongAnimal_equal_operator_overload_simple_assignment, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal("Bear");
        WrongAnimal    wrongAnimal2("Bear");

        wrongAnimal2 = wrongAnimal;

        cr_assert(wrongAnimal.getType() == wrongAnimal2.getType());
    }
}

Test(WrongAnimal, TEST_WrongAnimal_equal_operator_overload_self_assignment, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal("Bear");

        wrongAnimal = wrongAnimal;

        cr_assert(wrongAnimal.getType() == wrongAnimal.getType());
    }
}

Test(WrongAnimal, TEST_WrongAnimal_equal_operator_overload_assignment_after_modified_an_object, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal("Bear");
        WrongAnimal    wrongAnimal2("Bird");


        wrongAnimal2 = wrongAnimal;
        wrongAnimal.setType("Mouse");

        cr_assert(wrongAnimal2.getType() != wrongAnimal.getType());
    }
}

Test(WrongAnimal, TEST_WrongAnimal_equal_operator_overload_return_assignment, .init = redirect_all_stdout)
{
    {
        WrongAnimal    wrongAnimal("Bear");
        WrongAnimal    wrongAnimal2("Bird");
        WrongAnimal    &return_value = (wrongAnimal2 = wrongAnimal);
        

        cr_assert_eq(&return_value, &wrongAnimal2);
    }
}

Test(WrongAnimal, TEST_WrongAnimal_makeSound_stdout, .init = redirect_all_stdout)
{
    {
        WrongAnimal  wrongAnimal;
        WrongAnimal  wrongAnimal2("Bear");

        wrongAnimal.makeSound();
        wrongAnimal2.makeSound();

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

///////////////////////////////////////////////////////////////////////////////
//                            WrongCat class                                 //
///////////////////////////////////////////////////////////////////////////////

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
////////////////////////////////////////////////////////////////////////////
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
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    
    {       
        // const Animal    *meta = new Animal();
        // const Animal    *j = new Cat();
        // const Animal    *i = new Cat();
    
        // std::cout << j->getType() << " " << std::endl;
        // std::cout << i->getType() << " " << std::endl;
    
        // i->makeSound(); //will output the cat sound!
        // j->makeSound();
        // meta->makeSound();
    
        // const WrongAnimal   *wrongMeta = new WrongAnimal();
        // const WrongAnimal   *wrongCat = new WrongCat();
    
        // std::cout << wrongMeta->getType() << " " << std::endl;
        // std::cout << wrongCat->getType() << " " << std::endl;
        
        // wrongMeta->makeSound(); //will output the cat sound!
        // wrongCat->makeSound();
    
        // delete meta;
        // delete j;
        // delete i;
        // delete wrongAnimal;
        // delete wrongCat;
    }

    // cr_assert_stdout_eq_str(

    // );
}