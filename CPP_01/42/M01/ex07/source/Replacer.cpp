/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:10:56 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/04 19:40:43 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Replacer.hpp"

Replacer::Replacer(std::string fileName, std::string s1, std::string s2)
                    :   _fileName(fileName), _s1(s1), _s2(s2)
{}

Replacer::~Replacer(void)
{}

