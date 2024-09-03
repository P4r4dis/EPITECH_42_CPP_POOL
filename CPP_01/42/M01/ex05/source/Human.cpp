/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:47:06 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 18:07:13 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Human.hpp"
#include <string>

Human::Human(void)
{}

Human::~Human(void)
{}

std::string Human::identify(void) const
{
    return _brain.identify();
}