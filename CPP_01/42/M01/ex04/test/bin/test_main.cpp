/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/02 19:46:02 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(stringPTR, Test_pointer_to_the_string, .init = redirect_all_stdout)
{
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::cout   << "string: " << str << std::endl
                << "stringPTR: " << *stringPTR << std::endl;
    cr_assert_stdout_eq_str
    (
        "string: HI THIS IS BRAIN\n"
        "stringPTR: HI THIS IS BRAIN\n"
    );
}

Test(stringREF, Test_reference_to_the_string, .init = redirect_all_stdout)
{
    std::string str = "HI THIS IS BRAIN";

    std::string &stringREF = str;
    std::cout   << "string: " << str << std::endl
                << "stringREF: " << stringREF << std::endl;
    cr_assert_stdout_eq_str
    (
        "string: HI THIS IS BRAIN\n"
        "stringREF: HI THIS IS BRAIN\n"
    );
}

Test(address, Test_address_pointer_to_the_string, .init = redirect_all_stdout)
{
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::cout   << "address string: " << &str << std::endl
                << "address stringPTR: " << &stringPTR << std::endl;
    cr_assert(ne(ptr, &str, &stringPTR));
}

Test(address, Test_address_reference_to_the_string, .init = redirect_all_stdout)
{
    std::string str = "HI THIS IS BRAIN";

    std::string &stringREF = str;
    std::cout   << "address string: " << &str << std::endl
                << "address stringREF: " << &stringREF << std::endl;
    cr_assert(eq(ptr, &str, &stringREF));
}