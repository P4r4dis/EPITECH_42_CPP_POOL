/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:12:48 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/02 19:42:58 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     main(void)
{
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::cout   << "string: " << str << std::endl
                << "stringPTR: " << *stringPTR << std::endl;
    std::cout   << "address string: " << &str << std::endl
                << "address stringPTR: " << &stringPTR << std::endl;
    return 0;
}