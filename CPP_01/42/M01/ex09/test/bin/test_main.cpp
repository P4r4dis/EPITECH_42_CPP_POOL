/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/17 17:11:07 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Logger.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Logger, Test_Logger_class_isDefined, .init = redirect_all_stdout)
{
    std::string     fileName = "log";
    Logger          logger(fileName);
    cr_assert_not_null(&logger);
}

Test(Logger, Test_Logger_class_basics, .init = redirect_all_stdout)
{
    std::string     fileName = "log";
    Logger          logger(fileName);

    cr_assert_not_null(&logger);

    cr_assert(logger.getFileName() == fileName);
    cr_assert(logger.getFileStream().is_open() == true);
}
