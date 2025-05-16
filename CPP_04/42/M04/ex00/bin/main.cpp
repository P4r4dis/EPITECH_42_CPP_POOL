/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:31:28 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/15 20:43:35 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/WrongAnimal.hpp"
#include <iostream>

int main()
{
    const Animal    *meta = new Animal();
    const Animal    *j = new Dog();
    const Animal    *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal   *wrongMeta = new WrongAnimal();
    const WrongAnimal   *wrongCat = new WrongCat();

    std::cout << wrongMeta->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongMeta->makeSound(); //will output the cat sound!
    wrongCat->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrongAnimal;
    delete wrongCat;
    return 0;
