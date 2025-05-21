/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:31:28 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 03:19:25 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include <iostream>

int main()
{
    Animal *animals[100];

    for (int i = 0; i < 100; i++)
    {
        if (i % 2)
        {
            animals[i] = new Dog();
            animals[i]->getBrain()->setIdea(0, "Dog Idea");
        }
        else
        {
            animals[i] = new Cat();
            animals[i]->getBrain()->setIdea(0, "Cat Idea");
        }
        animals[i]->makeSound();
        std::cout << "Idea: " << animals[i]->getBrain()->getIdeas()[0] << std::endl;
    }

    for (int i = 0; i < 100; i++)
        delete animals[i];
    
    return 0;
}