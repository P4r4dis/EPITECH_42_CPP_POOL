/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/17 19:49:14 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>

#include "../../include/Logger.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Logger, Test_Logger_class_isDefined, .init = redirect_all_stdout)
{
    std::string     fileName = "42/M01/ex09/test/logger.log";
    Logger          logger(fileName);
    cr_assert_not_null(&logger);
}

Test(Logger, Test_Logger_class_basics, .init = redirect_all_stdout)
{
    std::string     fileName = "42/M01/ex09/test/logger.log";
    Logger          logger(fileName);

    cr_assert_not_null(&logger);

    cr_assert(logger.getFileName() == fileName);
    cr_assert(logger.getFileStream().is_open() == true);
}

Test(Logger, Test_Logger_log_isDefined, .init = redirect_all_stdout)
{
    std::string     fileName = "42/M01/ex09/test/logger.log";
    Logger          logger(fileName);

    logger.log("", "");
}

Test(Logger, Test_Logger_log_logToConsole, .init = redirect_all_stdout)
{
    std::string     fileName = "42/M01/ex09/test/logger.log";
    Logger          logger(fileName);
    std::ostringstream oss;
    time_t t = time(nullptr);
    std::string result = asctime(localtime(&t));
    std::string msg = "Hello";

    result.erase(result.length() - 1);
    oss << "[" + result + "]: " << msg;
    logger.log("Console", msg);
    // std::cout << oss.str() << std::endl;
    cr_assert_stdout_eq_str((oss.str() + "\n").c_str());
}

Test(Logger, Test_Logger_log_logToFile, .init = redirect_all_stdout)
{
    std::string     fileName = "42/M01/ex09/test/logger.log";
    Logger          logger(fileName);

    logger.log("File", "Hello");
    logger.log("File", "And Bye bye");

    std::ifstream ifs(fileName);
    cr_assert(ifs.is_open() == true);
    std::string line;
    while (std::getline(ifs, line, '\0'))
        std::cout << line << std::flush;
    ifs.close();
    cr_assert(ifs.is_open() == false);
    cr_assert_stdout_eq_str(line.c_str());
}

Test(Logger, Test_Logger_log_logToFile_Error_file_not_open,
    .init = redirect_all_stdout)
{
    std::string     fileName = "42/M01/ex09/test/logger.log";
    Logger          logger(fileName);

    logger.log("File", "Hello");
    logger.getFileStream().close();
    cr_assert(logger.getFileStream().is_open() == false);
    logger.log("File", "And Bye bye");

    cr_assert_stderr_eq_str((
        "Error: File <" + fileName + "> is not open.\n").c_str()
    );
}

Test(Logger, Test_Logger_log_unknown_destination,
    .init = redirect_all_stdout)
{
    std::string     fileName = "42/M01/ex09/test/logger.log";
    Logger          logger(fileName);
    std::string     dest = "Anything";
    
    logger.log("Anything", "Hello");

    cr_assert_stderr_eq_str(
        ("Error: Destination " + dest
        + " is unknown. Choose between <Console> and <File>.\n").c_str()
    );
}