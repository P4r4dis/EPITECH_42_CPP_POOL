/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:20:59 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/19 19:15:06 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Harl.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Harl, Test_Harl_class_isDefined, .init = redirect_all_stdout)
{
    Harl    harl;
    cr_assert_not_null(&harl);
}

Test(Harl, Test_Harl_complain_isDefined, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level;
    
    harl.complain(level);
}

Test(Harl, Test_Harl_complain_error_level_output, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level;
    
    harl.complain(level);
    cr_assert_stderr_eq_str
    (
        ("Error: level <" + level + 
        "> is unknown. Choose between: DEBUG, INFO, WARNING, ERROR.\n").c_str()
    );
}

Test(Harl, Test_Harl_complain_with_debug_level_output, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "DEBUG";
    
    harl.complain(level);
    cr_assert_stdout_eq_str
    (
        "[ DEBUG ]\n"
        "I love having extra bacon for my "
        "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
        "I really do!\n"
    );
}

Test(Harl, Test_Harl_complain_with_info_level_output, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "INFO";
    
    harl.complain(level);
    cr_assert_stdout_eq_str
    (
        "[ INFO ]\n"
        "I cannot believe adding extra bacon costs more money.\n"
        "You didn't put enough bacon in my burger!\n"
        "If you did, I wouldn't be asking for more!\n"
    );
}

Test(Harl, Test_Harl_complain_with_warning_level_output, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "WARNING";
    
    harl.complain(level);
    cr_assert_stdout_eq_str
    (
        "[ WARNING ]\n"
        "I think I deserve to have some extra bacon for free.\n"
        "I've been coming for years "
        "whereas you started working here since last month.\n"
    );
}

Test(Harl, Test_Harl_complain_with_error_level_output, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "ERROR";
    
    harl.complain(level);
    cr_assert_stdout_eq_str
    (
        "[ ERROR ]\n"
        "This is unacceptable, I want to speak to the manager now.\n"
    );
}

Test(Harl, Test_Harl_dispatcher_isDefined, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level;
    
    harl.dispatcher(level);
}

Test(Harl, Test_Harl_dispatcher_default_error_output, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "I am not sure how tired I am today...";
    
    harl.dispatcher(level);
    cr_assert_stderr_eq_str(
        "[ Probably complaining about insignificant problems ]\n"
    );
}

Test(Harl, Test_Harl_dispatcher_with_DEBUG_level, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "DEBUG";
    
    harl.dispatcher(level);
    cr_assert_stdout_eq_str(
        "[ DEBUG ]\n"
        "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
        "I really do!\n"
        "\n"
        "[ INFO ]\n"
        "I cannot believe adding extra bacon costs more money.\n"
        "You didn't put enough bacon in my burger!\n"
        "If you did, I wouldn't be asking for more!\n"
        "\n"
        "[ WARNING ]\n"
        "I think I deserve to have some extra bacon for free.\n"
        "I've been coming for years whereas you started working here since last month.\n"
        "\n"
        "[ ERROR ]\n"
        "This is unacceptable, I want to speak to the manager now.\n"
        "\n"
    );
}

Test(Harl, Test_Harl_dispatcher_with_INFO_level, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "INFO";
    
    harl.dispatcher(level);
    cr_assert_stdout_eq_str(
        "[ INFO ]\n"
        "I cannot believe adding extra bacon costs more money.\n"
        "You didn't put enough bacon in my burger!\n"
        "If you did, I wouldn't be asking for more!\n"
        "\n"
        "[ WARNING ]\n"
        "I think I deserve to have some extra bacon for free.\n"
        "I've been coming for years whereas you started working here since last month.\n"
        "\n"
        "[ ERROR ]\n"
        "This is unacceptable, I want to speak to the manager now.\n"
        "\n"
    );
}

Test(Harl, Test_Harl_dispatcher_with_WARNING_level, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "WARNING";
    
    harl.dispatcher(level);
    cr_assert_stdout_eq_str(
        "[ WARNING ]\n"
        "I think I deserve to have some extra bacon for free.\n"
        "I've been coming for years whereas you started working here since last month.\n"
        "\n"
        "[ ERROR ]\n"
        "This is unacceptable, I want to speak to the manager now.\n"
        "\n"
    );
}

Test(Harl, Test_Harl_dispatcher_with_ERROR_level, .init = redirect_all_stdout)
{
    Harl    harl;
    std::string level = "ERROR";
    
    harl.dispatcher(level);
    cr_assert_stdout_eq_str(
        "[ ERROR ]\n"
        "This is unacceptable, I want to speak to the manager now.\n"
        "\n"
    );
}