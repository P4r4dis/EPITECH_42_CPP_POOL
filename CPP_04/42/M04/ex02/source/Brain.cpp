/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:53:22 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/19 18:14:19 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain(void)  :   ideas(new std::string[SIZE])
{
    for (size_t i = 0; i < SIZE; ++i)
        ideas[i] = "";
    std::cout   << "Brain Default Constructor called." << std::endl;
}

Brain::Brain(const Brain &brain)    :   ideas(new std::string[SIZE])
{
    for (size_t i = 0; i < SIZE; ++i)
        ideas[i] = brain.ideas[i];
    std::cout   << "Brain Copy Constructor called." << std::endl;
}

Brain               &Brain::operator=(const Brain &brain)
{
    if (this != &brain)
    {
        if (ideas)
            delete [] ideas;
        ideas = new std::string[SIZE];
        for (size_t i = 0; i < SIZE; ++i)
            ideas[i] = brain.ideas[i];
    }
    return *this;
}
Brain::~Brain(void)
{
    if (ideas)
        delete [] ideas;
    std::cout   << "Brain Destructor called." << std::endl;
}

std::string         *Brain::getIdeas(void) const
{
    return ideas;
}

void                Brain::setIdeas(std::string *newIdeas)
{
    for (size_t i = 0; i < SIZE; ++i)
        ideas[i] = newIdeas[i];
}

std::string         Brain::getIdea(size_t index) const
{
    return ideas[index];
}

void                Brain::setIdea(size_t index, std::string idea)
{
    ideas[index] = idea;
}