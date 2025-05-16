/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:59:06 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 18:16:53 by Paradis          ###   ########.fr       */
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

Test(Dog, TEST_Dog_makeSound_stdout, .init = redirect_all_stdout)
{
    {
        Dog     dog;
        Dog     dog2("Dog");

        dog.makeSound();
        dog2.makeSound();

    }
    
    cr_assert_stdout_eq_str
    (
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Default Constructor created an Dog animal.\n"
        "Animal Custom Constructor created a Dog animal.\n"
        "Dog Custom Constructor created a Dog animal.\n"
        "Dog animal sound.\n"
        "Dog animal sound.\n"
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

Test(Cat, TEST_Cat_makeSound_stdout, .init = redirect_all_stdout)
{
    {
        Cat     cat;
        Cat     cat2("Cat");

        cat.makeSound();
        cat2.makeSound();

    }
    
    cr_assert_stdout_eq_str
    (
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Default Constructor created an Cat animal.\n"
        "Animal Custom Constructor created a Cat animal.\n"
        "Cat Custom Constructor created a Cat animal.\n"
        "Cat animal sound.\n"
        "Cat animal sound.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
        "Cat Destructor destroyed a Cat animal.\n"
        "Animal Destructor destroyed a Cat animal.\n"
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