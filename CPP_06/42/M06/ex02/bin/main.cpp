/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:30:10 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/29 18:18:53 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/Utils.hpp"

#include <iostream>
int     main(void)
{
	std::cout << "Generating a random class derived from Base" << std::endl;
	Base	*base = generate();
	std::cout << "Identifying the class as pointer to Base" << std::endl;
	identify(base);
    Base    &ref = *base;
	std::cout << "Identifying the class as reference to Base" << std::endl;
	identify(ref);
    
	delete base;
    return 0;
}