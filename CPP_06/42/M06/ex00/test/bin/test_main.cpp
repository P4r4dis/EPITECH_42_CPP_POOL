/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:51:29 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/23 18:46:28 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/ScalarConverter.hpp"
#include "../../include/Utils.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Utils_isPseudoLiteral, TEST_check_if_string_is_a_literal,
.init = redirect_all_stdout)
{
    {
        std::string pos_inff = "+inff";
        std::string neg_inff = "-inff";
        std::string pos_inf = "+inf";
        std::string neg_inf = "-inf";
        std::string nan = "nan";
        std::string nanf = "nanf";

        cr_assert(Utils::isPseudoLiteral(pos_inff) == true);
        cr_assert(Utils::isPseudoLiteral(neg_inff) == true);
        cr_assert(Utils::isPseudoLiteral(pos_inf) == true);
        cr_assert(Utils::isPseudoLiteral(neg_inf) == true);
        cr_assert(Utils::isPseudoLiteral(nan) == true);
        cr_assert(Utils::isPseudoLiteral(nanf) == true);
    }
}

Test(Utils_isChar, TEST_check_if_string_length_is_different_of_one,
.init = redirect_all_stdout)
{
    {
        std::string A = "a";
        std::string string = "hello";

        cr_assert(Utils::isChar(A) == true);
        cr_assert(Utils::isChar(string) == false);
    }
}

#include <iostream>
Test(Utils_isChar, TEST_should_return_true_for_any_character,
.init = redirect_all_stdout)
{
    {
        for (int i = -127; i < 128; ++i)
        {
            std::string str(1, i);
            cr_assert(Utils::isChar(str) == true);
        }
    }
}

Test(Utils_isInt, TEST_should_return_true_if_is_neg_number,
.init = redirect_all_stdout)
{
    {
        std::string str = std::to_string(-5423543);
        cr_assert(Utils::isInt(str) == true);
    }
}

Test(Utils_isInt, TEST_should_return_true_if_is_pos_number,
.init = redirect_all_stdout)
{
    {
        std::string str = std::to_string(4515243);
        cr_assert(Utils::isInt(str) == true);
    }
}

Test(Utils_isInt, TEST_should_return_false_if_its_not_integer,
.init = redirect_all_stdout)
{
    {
        std::string str = "4321jk413";
        cr_assert(Utils::isInt(str) == false);
    }
}

Test(Utils_isFloat, TEST_should_return_false_if_its_not_float,
.init = redirect_all_stdout)
{
    {
        std::string str = "12.23ffffff";

        cr_assert(Utils::isFloat(str) == false);
    }
}

Test(Utils_isFloat, TEST_should_return_true_if_its_float,
.init = redirect_all_stdout)
{
    {
        std::string str = "12.23f";
        
        cr_assert(Utils::isFloat(str) == true);
    }
}

Test(Utils_isFloat, TEST_should_return_true_if_its_neg_float,
.init = redirect_all_stdout)
{
    {
        std::string str = "-12.23f";
        
        cr_assert(Utils::isFloat(str) == true);
    }
}

Test(Utils_isDouble, TEST_should_return_false_if_its_not_double,
.init = redirect_all_stdout)
{
    {
        std::string str = "12.23gsfd";

        cr_assert(Utils::isDouble(str) == false);
    }
}

Test(Utils_isDouble, TEST_should_return_true_if_its_double,
.init = redirect_all_stdout)
{
    {
        std::string str = "12.23";
        
        cr_assert(Utils::isDouble(str) == true);
    }
}


Test(Utils_isisDouble, TEST_should_return_true_if_its_neg_double,
.init = redirect_all_stdout)
{
    {
        std::string str = "-12.23";
        
        cr_assert(Utils::isDouble(str) == true);
    }
}

Test(Utils_isChar, TEST_should_return_true_if_char_is_printable,
.init = redirect_all_stdout)
{
    {
        for (int i = -127; i < 128; ++i)
        {
            std::string str(1, i);
            if (Utils::isPrintable(str))
            {
                std::cout << str << std::endl;
                cr_assert(Utils::isPrintable(str) == true);
            }
            else
                cr_assert(Utils::isPrintable(str) == false);
        }
    }
    cr_assert_stdout_eq_str
    (
        " \n"
        "!\n"
        "\"\n"
        "#\n"
        "$\n"
        "%\n"
        "&\n"
        "'\n"
        "(\n"
        ")\n"
        "*\n"
        "+\n"
        ",\n"
        "-\n"
        ".\n"
        "/\n"
        "0\n"
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
        "8\n"
        "9\n"
        ":\n"
        ";\n"
        "<\n"
        "=\n"
        ">\n"
        "?\n"
        "@\n"
        "A\n"
        "B\n"
        "C\n"
        "D\n"
        "E\n"
        "F\n"
        "G\n"
        "H\n"
        "I\n"
        "J\n"
        "K\n"
        "L\n"
        "M\n"
        "N\n"
        "O\n"
        "P\n"
        "Q\n"
        "R\n"
        "S\n"
        "T\n"
        "U\n"
        "V\n"
        "W\n"
        "X\n"
        "Y\n"
        "Z\n"
        "[\n"
        "\\\n"
        "]\n"
        "^\n"
        "_\n"
        "`\n"
        "a\n"
        "b\n"
        "c\n"
        "d\n"
        "e\n"
        "f\n"
        "g\n"
        "h\n"
        "i\n"
        "j\n"
        "k\n"
        "l\n"
        "m\n"
        "n\n"
        "o\n"
        "p\n"
        "q\n"
        "r\n"
        "s\n"
        "t\n"
        "u\n"
        "v\n"
        "w\n"
        "x\n"
        "y\n"
        "z\n"
        "{\n"
        "|\n"
        "}\n"
        "~\n"
    );
}

Test(Utils_printLiteral, TEST_printLiteral_inff,
.init = redirect_all_stdout)
{
    {
        std::string pos_inff = "+inff";
        std::string neg_inff = "-inff";

        Utils::printLiteral(pos_inff);
        Utils::printLiteral(neg_inff);

    }
    cr_assert_stdout_eq_str
    (
        "char: impossible\n"
        "int: impossible\n"
        "float: +inff\n"
        "double: +inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: -inff\n"
        "double: -inf\n"
    );
}

Test(Utils_printLiteral, TEST_printLiteral_inf,
.init = redirect_all_stdout)
{
    {

        std::string pos_inf = "+inf";
        std::string neg_inf = "-inf";

        Utils::printLiteral(pos_inf);
        Utils::printLiteral(neg_inf);
    }
    cr_assert_stdout_eq_str
    (
        "char: impossible\n"
        "int: impossible\n"
        "float: +inff\n"
        "double: +inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: -inff\n"
        "double: -inf\n"
    );
}

Test(Utils_printLiteral, TEST_printLiteral_nan,
.init = redirect_all_stdout)
{
    {
        std::string nan = "nan";
        std::string nanf = "nanf";

        Utils::printLiteral(nan);
        Utils::printLiteral(nanf);
    }
    cr_assert_stdout_eq_str
    (
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan\n"
    );
}

Test(Utils_printChar, TEST_try_to_print_NON_DISPLAYABLE_character,
.init = redirect_all_stdout)
{
    {
        std::string var = "\0";
        Utils::printChar(var);
    }
    cr_assert_stdout_eq_str
    (
        "char: Non displayable\n"
    );
}

Test(Utils_printChar, TEST_try_to_print_impossible_character,
.init = redirect_all_stdout)
{
    {
        std::string var = "5432";
        Utils::printChar(var);
    }
    cr_assert_stdout_eq_str
    (
        "char: impossible\n"
    );
}

Test(Utils_printChar, TEST_try_to_print_any_type_of_character,
.init = redirect_all_stdout)
{
    {
        std::string var = "a";
        Utils::printChar(var); // 'a'
        var = "'a'";
        Utils::printChar(var); // 'a'
        var = "-42";
        Utils::printChar(var); // Non displayable
        var = "42";
        Utils::printChar(var); // '*'

        var = "0";
        Utils::printChar(var); // Non displayable

        var = "'0'";
        Utils::printChar(var); // '0'
        var = "\0";
        Utils::printChar(var); // Non displayable
        var = "42.0f";
        Utils::printChar(var); // '*'
        var = "-42.0f";
        Utils::printChar(var); // Non displayable
        var = "0.0f";
        Utils::printChar(var); // Non displayable
        var = "4.2";
        Utils::printChar(var); // Non displayable
        var = "-4.2";
        Utils::printChar(var); // Non displayable
        var = "0.0";
        Utils::printChar(var); // Non displayable
    }
    cr_assert_stdout_eq_str
    (
        "char: 'a'\n"
        "char: 'a'\n"
        "char: Non displayable\n"
        "char: '*'\n"
        "char: Non displayable\n"
        "char: '0'\n"
        "char: Non displayable\n"
        "char: '*'\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
    );
}

Test(Utils_printChar, TEST_try_to_print_character_between_apostrophe,
.init = redirect_all_stdout)
{
    {
        std::string var = "'a'";
        Utils::printChar(var);
    }
    cr_assert_stdout_eq_str
    (
        "char: 'a'\n"
    );
}

Test(Utils_printChar, TEST_if_variable_is_several_character_should_print_impossible,
.init = redirect_all_stdout)
{
    {
        std::string var = "rqew";
        Utils::printChar(var);
    }
    cr_assert_stdout_eq_str
    (
        "char: impossible\n"
    );
}

Test(Utils_printChar, TEST_print_character,
.init = redirect_all_stdout)
{
    {
        for (int i = -127; i < 128; ++i)
        {
            std::string str = std::to_string(i);
            // std::cout << "index: " << i << ", str: " << str << ", ";
            Utils::printChar(str);
        }
 
    }
//}
    cr_assert_stdout_eq_str
    (
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: Non displayable\n"
        "char: ' '\n"
        "char: '!'\n"
        "char: '\"'\n"
        "char: '#'\n"
        "char: '$'\n"
        "char: '%'\n"
        "char: '&'\n"
        "char: '''\n"
        "char: '('\n"
        "char: ')'\n"
        "char: '*'\n"
        "char: '+'\n"
        "char: ','\n"
        "char: '-'\n"
        "char: '.'\n"
        "char: '/'\n"
        "char: '0'\n"
        "char: '1'\n"
        "char: '2'\n"
        "char: '3'\n"
        "char: '4'\n"
        "char: '5'\n"
        "char: '6'\n"
        "char: '7'\n"
        "char: '8'\n"
        "char: '9'\n"
        "char: ':'\n"
        "char: ';'\n"
        "char: '<'\n"
        "char: '='\n"
        "char: '>'\n"
        "char: '?'\n"
        "char: '@'\n"
        "char: 'A'\n"
        "char: 'B'\n"
        "char: 'C'\n"
        "char: 'D'\n"
        "char: 'E'\n"
        "char: 'F'\n"
        "char: 'G'\n"
        "char: 'H'\n"
        "char: 'I'\n"
        "char: 'J'\n"
        "char: 'K'\n"
        "char: 'L'\n"
        "char: 'M'\n"
        "char: 'N'\n"
        "char: 'O'\n"
        "char: 'P'\n"
        "char: 'Q'\n"
        "char: 'R'\n"
        "char: 'S'\n"
        "char: 'T'\n"
        "char: 'U'\n"
        "char: 'V'\n"
        "char: 'W'\n"
        "char: 'X'\n"
        "char: 'Y'\n"
        "char: 'Z'\n"
        "char: '['\n"
        "char: '\\'\n"
        "char: ']'\n"
        "char: '^'\n"
        "char: '_'\n"
        "char: '`'\n"
        "char: 'a'\n"
        "char: 'b'\n"
        "char: 'c'\n"
        "char: 'd'\n"
        "char: 'e'\n"
        "char: 'f'\n"
        "char: 'g'\n"
        "char: 'h'\n"
        "char: 'i'\n"
        "char: 'j'\n"
        "char: 'k'\n"
        "char: 'l'\n"
        "char: 'm'\n"
        "char: 'n'\n"
        "char: 'o'\n"
        "char: 'p'\n"
        "char: 'q'\n"
        "char: 'r'\n"
        "char: 's'\n"
        "char: 't'\n"
        "char: 'u'\n"
        "char: 'v'\n"
        "char: 'w'\n"
        "char: 'x'\n"
        "char: 'y'\n"
        "char: 'z'\n"
        "char: '{'\n"
        "char: '|'\n"
        "char: '}'\n"
        "char: '~'\n"
        "char: Non displayable\n"
    );
}

Test(Utils_printInt, TEST_try_to_print_out_of_range_integer,
.init = redirect_all_stdout)
{
    {
        std::string var = "2147483648";
        Utils::printInt(var);
        var = "-2147483649";
        Utils::printInt(var);
    }
    cr_assert_stdout_eq_str
    (
        "int: impossible\n"
        "int: impossible\n"
    );
}

Test(Utils_printInt, TEST_try_to_print_integer,
.init = redirect_all_stdout)
{
    {
        std::string var = "0";
        Utils::printInt(var);
        var = "1";
        Utils::printInt(var);
        var = "10";
        Utils::printInt(var);
        var = "100";
        Utils::printInt(var);
        var = "1000";
        Utils::printInt(var);
        var = "10000";
        Utils::printInt(var);
        var = "100000";
        Utils::printInt(var);
        var = "1000000";
        Utils::printInt(var);
        var = "10000000";
        Utils::printInt(var);
        var = "100000000";
        Utils::printInt(var);
        var = "1000000000";
        Utils::printInt(var);
        var = "10000000000";
        Utils::printInt(var);
        var = "-10000000000";
        Utils::printInt(var);
        var = "-1000000000";
        Utils::printInt(var);
        var = "-100000000";
        Utils::printInt(var);
        var = "-10000000";
        Utils::printInt(var);
        var = "-1000000";
        Utils::printInt(var);
        var = "-100000";
        Utils::printInt(var);
        var = "-10000";
        Utils::printInt(var);
        var = "-1000";
        Utils::printInt(var);
        var = "-100";
        Utils::printInt(var);
        var = "-10";
        Utils::printInt(var);
        var = "-1";
        Utils::printInt(var);
    }
    cr_assert_stdout_eq_str
    (
        "int: 0\n"
        "int: 1\n"
        "int: 10\n"
        "int: 100\n"
        "int: 1000\n"
        "int: 10000\n"
        "int: 100000\n"
        "int: 1000000\n"
        "int: 10000000\n"
        "int: 100000000\n"
        "int: 1000000000\n"
        "int: impossible\n"
        "int: impossible\n"
        "int: -1000000000\n"
        "int: -100000000\n"
        "int: -10000000\n"
        "int: -1000000\n"
        "int: -100000\n"
        "int: -10000\n"
        "int: -1000\n"
        "int: -100\n"
        "int: -10\n"
        "int: -1\n"
    );
}

Test(Utils_printFloat, TEST_try_to_print_out_of_range_float,
.init = redirect_all_stdout)
{
    {
        float min = std::numeric_limits<float>::lowest();
        float max = std::numeric_limits<float>::max();
        std::string var = std::to_string(min + min);
        Utils::printFloat(var);
        var = std::to_string(max + max);
        Utils::printFloat(var);
    }
    cr_assert_stdout_eq_str
    (
        "float: impossible\n"
        "float: impossible\n"
    );
}

Test(Utils_printFloat, TEST_try_to_print_float,
.init = redirect_all_stdout)
{
    {
        std::string var = "42.00";
        Utils::printFloat(var);
        var = "5432.5423";
        Utils::printFloat(var);
        var = "-42.00";
        Utils::printFloat(var);
        var = "-5432.5423";
        Utils::printFloat(var);
        var = "0.00";
        Utils::printFloat(var);
        var = "0";
        Utils::printFloat(var);
        var = "nan";
        Utils::printFloat(var);
        var = "NAN";
        Utils::printFloat(var);
        var = "reqw";
        Utils::printFloat(var);
    }
    cr_assert_stdout_eq_str
    (
        "float: 42.0f\n"
        "float: 5432.54f\n"
        "float: -42.0f\n"
        "float: -5432.54f\n"
        "float: 0.0f\n"
        "float: 0.0f\n"
        "float: nanf\n"
        "float: nanf\n"
        "float: impossible\n"
    );
}

Test(Utils_printDouble, TEST_try_to_print_out_of_range_double,
.init = redirect_all_stdout)
{
    {
        double min = std::numeric_limits<double>::lowest();
        double max = std::numeric_limits<double>::max();
        std::string var = std::to_string(min + min);

        Utils::printDouble(var);
        var = std::to_string(max + max);
        Utils::printDouble(var);
    }
    cr_assert_stdout_eq_str
    (
        "double: impossible\n"
        "double: impossible\n"
    );
}

Test(Utils_printDouble, TEST_try_to_print_double,
.init = redirect_all_stdout)
{
    {
        std::string var = "42.00";
        Utils::printDouble(var);
        var = "5432.5423";
        Utils::printDouble(var);
        var = "-42.00";
        Utils::printDouble(var);
        var = "-5432.5423";
        Utils::printDouble(var);
        var = "0.00";
        Utils::printDouble(var);
        var = "0";
        Utils::printDouble(var);
        var = "nan";
        Utils::printDouble(var);
        var = "NAN";
        Utils::printDouble(var);
    }
    cr_assert_stdout_eq_str
    (
        "double: 42.0\n"
        "double: 5432.54\n"
        "double: -42.0\n"
        "double: -5432.54\n"
        "double: 0.0\n"
        "double: 0.0\n"
        "double: nan\n"
        "double: nan\n"
    );
}

//////////////////////////////////////////////////////////////
Test(ScalarConverter_convert, TEST_convert_pseudo_literal,
.init = redirect_all_stdout)
{
    {
        std::string pos_inff = "+inff";
        std::string neg_inff = "-inff";
        std::string pos_inf = "+inf";
        std::string neg_inf = "-inf";
        std::string nan = "nan";
        std::string nanf = "nanf";

        ScalarConverter::convert(pos_inff);
        ScalarConverter::convert(neg_inff);
        ScalarConverter::convert(pos_inf);
        ScalarConverter::convert(neg_inf);
        ScalarConverter::convert(nan);
        ScalarConverter::convert(nanf);
    }
    cr_assert_stdout_eq_str
    (
        "char: impossible\n"
        "int: impossible\n"
        "float: +inff\n"
        "double: +inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: -inff\n"
        "double: -inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: +inff\n"
        "double: +inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: -inff\n"
        "double: -inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan\n"
    );
}

Test(ScalarConverter_convert, TEST_convert_Char,
.init = redirect_all_stdout)
{
    {

        std::string str = "a";
        ScalarConverter::convert(str);
        str = "'b'";
        ScalarConverter::convert(str);
        str = "reqw";
        ScalarConverter::convert(str);
        str = "0";
        ScalarConverter::convert(str);
        str = "'0'";
        ScalarConverter::convert(str);
        str = "nan";
        ScalarConverter::convert(str);
        str = "42.0f";
        ScalarConverter::convert(str);
        str = "'c'";
        ScalarConverter::convert(str);
        str = "'a'";
        ScalarConverter::convert(str);
        str = "0";
        ScalarConverter::convert(str);
        str = "-42";
        ScalarConverter::convert(str);
        str = "42";
        ScalarConverter::convert(str);
        str = "0.0f";
        ScalarConverter::convert(str);
        str = "-4.2f";
        ScalarConverter::convert(str);
        str = "4.2f";
        ScalarConverter::convert(str);
        str = "-inff";
        ScalarConverter::convert(str);
        str = "+inff";
        ScalarConverter::convert(str);
        str = "nanf";
        ScalarConverter::convert(str);
        str = "0.0";
        ScalarConverter::convert(str);
        str = "-4.2";
        ScalarConverter::convert(str);
        str = "4.2";
        ScalarConverter::convert(str);
        str = "-inf";
        ScalarConverter::convert(str);
        str = "+inf";
        ScalarConverter::convert(str);
        str = "nan";
        ScalarConverter::convert(str);
    }
    cr_assert_stdout_eq_str
    (
        "char: 'a'\n"
        "int: 97\n"
        "float: 97.0f\n"
        "double: 97.0\n"
        "char: 'b'\n"
        "int: 98\n"
        "float: 98.0f\n"
        "double: 98.0\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: impossible\n"
        "double: impossible\n"
        "char: Non displayable\n"
        "int: 0\n"
        "float: 0.0f\n"
        "double: 0.0\n"
        "char: '0'\n"
        "int: 48\n"
        "float: 48.0f\n"
        "double: 48.0\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan\n"
        "char: '*'\n"
        "int: 42\n"
        "float: 42.0f\n"
        "double: 42.0\n"
        "char: 'c'\n"
        "int: 99\n"
        "float: 99.0f\n"
        "double: 99.0\n"
        "char: 'a'\n"
        "int: 97\n"
        "float: 97.0f\n"
        "double: 97.0\n"
        "char: Non displayable\n"
        "int: 0\n"
        "float: 0.0f\n"
        "double: 0.0\n"
        "char: Non displayable\n"
        "int: -42\n"
        "float: -42.0f\n"
        "double: -42.0\n"
        "char: '*'\n"
        "int: 42\n"
        "float: 42.0f\n"
        "double: 42.0\n"
        "char: Non displayable\n"
        "int: 0\n"
        "float: 0.0f\n"
        "double: 0.0\n"
        "char: Non displayable\n"
        "int: -4\n"
        "float: -4.2f\n"
        "double: -4.2\n"
        "char: Non displayable\n"
        "int: 4\n"
        "float: 4.2f\n"
        "double: 4.2\n" //
        "char: impossible\n"
        "int: impossible\n"
        "float: -inff\n"
        "double: -inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: +inff\n"
        "double: +inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan\n"
        "char: Non displayable\n"
        "int: 0\n"
        "float: 0.0f\n"
        "double: 0.0\n"
        "char: Non displayable\n"
        "int: -4\n"
        "float: -4.2f\n"
        "double: -4.2\n"
        "char: Non displayable\n"
        "int: 4\n"
        "float: 4.2f\n"
        "double: 4.2\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: -inff\n"
        "double: -inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: +inff\n"
        "double: +inf\n"
        "char: impossible\n"
        "int: impossible\n"
        "float: nanf\n"
        "double: nan\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        {
            int ac = 1;

            if (ac == 1)
                std::cout   << "You need to add an argument like: " << std::endl
                            << "- A literal char: 'a' or 'b'..." << std::endl
                            << "- A literal int: 42 or 56..." << std::endl
                            << "- A literal float: 42.0f or 43.4f..." << std::endl
                            << "- A literal double: 4.2 or 6.5..." << std::endl;
        }

            const char *av[] = {"program", "42"};

            ScalarConverter::convert(av[1]);
    }
    cr_assert_stdout_eq_str
    (
        "You need to add an argument like: \n"
        "- A literal char: 'a' or 'b'...\n"
        "- A literal int: 42 or 56...\n"
        "- A literal float: 42.0f or 43.4f...\n"
        "- A literal double: 4.2 or 6.5...\n"
        "char: '*'\n"
        "int: 42\n"
        "float: 42.0f\n"
        "double: 42.0\n"
    );
}