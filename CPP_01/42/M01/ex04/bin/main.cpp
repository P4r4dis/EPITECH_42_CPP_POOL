/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 21:12:48 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/02 19:51:41 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout   << "address string: " << &str << std::endl
                << "address stringPTR: " << &stringPTR << std::endl
                << "address stringREF: " << &stringREF << std::endl;

    std::cout   << "string: " << str << std::endl
                << "stringPTR: " << *stringPTR << std::endl
                << "stringREF: " << stringREF << std::endl;

    return 0;
}