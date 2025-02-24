/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:00:25 by Paradis           #+#    #+#             */
/*   Updated: 2025/02/24 20:47:52 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>
#include <limits>

#include "../../include/Fixed.hpp"
#include "../../include/Point.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Fixed_class, Test_default_CTOR_isDefined, .init = redirect_all_stdout)
{
    Fixed a;

    cr_assert_not_null(&a);
}

Test(Fixed_class, Test_default_CTOR_initializes_FixedValue_to_zero,
.init = redirect_all_stdout)
{
    Fixed a;

    cr_assert(a.getRawBits() == 0);
}

Test(Fixed_class, Test_getRawBits_func_returns_FixedValue,
.init = redirect_all_stdout)
{
    {
        Fixed a;

        cr_assert(a.getRawBits() == 0);
    }
}

Test(Fixed_class, Test_Copy_CTOR_isDefined, .init = redirect_all_stdout)
{
    Fixed a;
    Fixed b(a);
    cr_assert_not_null(&b);
}

Test(Fixed_class, Test_Copy_CTOR_copy_instance,
.init = redirect_all_stdout)
{
    Fixed a;
    Fixed b(a);
    cr_assert(b.getRawBits() == 0);
    cr_assert(b.getRawBits() == a.getRawBits());
}

Test(Fixed_class, Test_assigment_operator,
.init = redirect_all_stdout)
{
    Fixed a;
    Fixed b;

    b = a;
    cr_assert(b.getRawBits() == a.getRawBits());
}

Test(Fixed_class, Test_setRawBits_allows_to_change_FixedValue,
.init = redirect_all_stdout)
{
    Fixed a;

    cr_assert(a.getRawBits() == 0);
    a.setRawBits(42);
    cr_assert(a.getRawBits() == 42);
}

Test(Fixed_class, Test_getFractionalBits_func_returns_fractionalBits,
.init = redirect_all_stdout)
{
    Fixed a;

    cr_assert(a.getFractionalBits() == 8);
}


Test(Fixed_class, Test_custom_CTOR_take_integer_isDefined, .init = redirect_all_stdout)
{
    Fixed const a(10);

    cr_assert_not_null(&a);
}

Test(Fixed_class, Test_custom_CTOR_initializes_FixedValue_value,
.init = redirect_all_stdout)
{
    Fixed const a(10);

    cr_assert(a.getRawBits() == 10 << 8);
}

Test(Fixed_class, Test_custom_CTOR_take_float_isDefined, .init = redirect_all_stdout)
{
    Fixed const a(42.42f);

    cr_assert_not_null(&a);
}

Test(Fixed_class, Test_custom_CTOR_taking_float_initializes_FixedValue_value,
.init = redirect_all_stdout)
{
    Fixed const a(42.42f);

    cr_assert(a.getRawBits() == roundf(42.42f * (1 << 8)));
}


Test(Fixed_class, Test_toFloat_funct_converts_FixedValue_to_float,
.init = redirect_all_stdout)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    
    a = Fixed(1234.4321f);

    cr_assert_float_eq(a.toFloat(), 1234.43, 0.01);
    cr_assert_float_eq(b.toFloat(), 10, 0.0001);
    cr_assert_float_eq(c.toFloat(), 42.4219, 0.0001);
    cr_assert_float_eq(d.toFloat(), 10, 0.0001);
}

Test(Fixed_class, Test_overload_operator_stream_insertion,
.init = redirect_all_stdout)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    
    a = Fixed(1234.4321f);

    cr_assert_float_eq(a.toFloat(), 1234.43, 0.01);
    cr_assert_float_eq(b.toFloat(), 10, 0.0001);
    cr_assert_float_eq(c.toFloat(), 42.4219, 0.0001);
    cr_assert_float_eq(d.toFloat(), 10, 0.0001);
}

Test(Fixed_class,
Test_operator_stream_insertion_overloaded_prints_msg_to_stdout,
.init = redirect_all_stdout)
{
    {
        Fixed a;
        Fixed const b(10);
        Fixed const c(42.42f);
        Fixed const d(b);
        
        a = Fixed(1234.4321f);

        cr_assert_float_eq(a.toFloat(), 1234.43, 0.01);
        cr_assert_float_eq(b.toFloat(), 10, 0.0001);
        cr_assert_float_eq(c.toFloat(), 42.4219, 0.0001);
        cr_assert_float_eq(d.toFloat(), 10, 0.0001);

        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
    }
    cr_assert_stdout_eq_str(
        "a is 1234.43\n"
        "b is 10\n"
        "c is 42.4219\n"
        "d is 10\n"
    );
}

Test(Fixed_class, Test_toInt_funct_converts_FixedValue_to_integer,
.init = redirect_all_stdout)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    
    a = Fixed(1234.4321f);

    cr_assert(a.toInt() == 1234);
    cr_assert(b.toInt() == 10);
    cr_assert(c.toInt() == 42);
    cr_assert(d.toInt() == 10);
}

Test(Fixed_class, Test_greater_than_operator_basic_overload,
.init = redirect_all_stdout)
{
    Fixed a(10);
    Fixed b(5);
    
    cr_assert(a > b);
    cr_assert_not(b > a);
}

Test(Fixed_class, Test_greater_than_operator_overload_with_equal_values,
.init = redirect_all_stdout)
{
    Fixed a(7);
    Fixed b(7);

    cr_assert_not(a > b);
    cr_assert_not(b > a);
}

Test(Fixed_class, Test_greater_than_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed a(-3);
    Fixed b(-7);

    cr_assert(a > b);
    cr_assert_not(b > a);
}

Test(Fixed_class, Test_greater_than_operator_overload_with_mixed_values,
.init = redirect_all_stdout)
{
    Fixed a(-5);
    Fixed b(2);

    cr_assert_not(a > b);
    cr_assert(b > a);
}

Test(Fixed_class, Test_greater_than_operator_overload_with_large_values,
.init = redirect_all_stdout)
{
    Fixed a(1000000);
    Fixed b(500000);

    cr_assert(a > b);
    cr_assert_not(b > a);
}

Test(Fixed_class, Test_greater_than_or_equal_operator_basic_overload,
.init = redirect_all_stdout)
{
    Fixed a(10);
    Fixed b(5);
    
    cr_assert(a >= b);
    cr_assert_not(b >= a);
}

Test(Fixed_class, Test_greater_than_or_equal_operator_overload_with_equal_values,
.init = redirect_all_stdout)
{
    Fixed a(7);
    Fixed b(7);

    cr_assert(a >= b);
    cr_assert(b >= a);
}

Test(Fixed_class, Test_greater_than_or_equal_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed a(-3);
    Fixed b(-7);

    cr_assert(a >= b);
    cr_assert_not(b >= a);
}

Test(Fixed_class, Test_greater_than_or_equal_operator_overload_with_mixed_values,
.init = redirect_all_stdout)
{
    Fixed a(-5);
    Fixed b(2);

    cr_assert_not(a >= b);
    cr_assert(b >= a);
}

Test(Fixed_class, Test_greater_than_or_equal_operator_overload_with_large_values,
.init = redirect_all_stdout)
{
    Fixed a(1000000);
    Fixed b(500000);

    cr_assert(a >= b);
    cr_assert_not(b >= a);
}

Test(Fixed_class, Test_less_than_operator_basic_overload,
.init = redirect_all_stdout)
{
    Fixed a(5);
    Fixed b(10);
    
    cr_assert(a < b);
    cr_assert_not(b < a);
}

Test(Fixed_class, Test_less_than_operator_overload_with_equal_values,
.init = redirect_all_stdout)
{
    Fixed a(7);
    Fixed b(7);

    cr_assert_not(a < b);
    cr_assert_not(b < a);
}

Test(Fixed_class, Test_less_than_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed a(-7);
    Fixed b(-3);

    cr_assert(a < b);
    cr_assert_not(b < a);
}

Test(Fixed_class, Test_less_than_operator_overload_with_mixed_values,
.init = redirect_all_stdout)
{
    Fixed a(2);
    Fixed b(-5);

    cr_assert_not(a < b);
    cr_assert(b < a);
}

Test(Fixed_class, Test_less_than_operator_overload_with_large_values,
.init = redirect_all_stdout)
{
    Fixed a(500000);
    Fixed b(1000000);

    cr_assert(a < b);
    cr_assert_not(b < a);
}

Test(Fixed_class, Test_less_than_or_equal_operator_basic_overload,
.init = redirect_all_stdout)
{
    Fixed a(5);
    Fixed b(10);
    
    cr_assert(a <= b);
    cr_assert_not(b <= a);
}

Test(Fixed_class, Test_less_than_or_equal_operator_overload_with_equal_values,
.init = redirect_all_stdout)
{
    Fixed a(7);
    Fixed b(7);

    cr_assert(a <= b);
    cr_assert(b <= a);
}

Test(Fixed_class,
    Test_less_than_or_equal_operator_overload_with_negative_values,
    .init = redirect_all_stdout)
{
    Fixed a(-7);
    Fixed b(-3);

    cr_assert(a <= b);
    cr_assert_not(b <= a);
}

Test(Fixed_class, Test_less_than_or_equal_operator_overload_with_mixed_values,
.init = redirect_all_stdout)
{
    Fixed a(2);
    Fixed b(-5);

    cr_assert_not(a <= b);
    cr_assert(b <= a);
}

Test(Fixed_class, Test_less_than_or_equal_operator_overload_with_large_values,
.init = redirect_all_stdout)
{
    Fixed a(500000);
    Fixed b(1000000);

    cr_assert(a <= b);
    cr_assert_not(b <= a);
}

Test(Fixed_class, Test_equal_equal_operator_basic_overload,
.init = redirect_all_stdout)
{
    Fixed a(5);
    Fixed b(10);
    
    cr_assert_not(a == b);
    cr_assert_not(b == a);
}

Test(Fixed_class, Test_equal_equal_operator_overload_with_equal_values,
.init = redirect_all_stdout)
{
    Fixed a(7);
    Fixed b(7);

    cr_assert(a == b);
    cr_assert(b == a);
}

Test(Fixed_class, Test_equal_equal_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed a(-7);
    Fixed b(-3);

    cr_assert_not(a == b);
    cr_assert_not(b == a);
}

Test(Fixed_class, Test_equal_equal_operator_overload_with_mixed_values,
.init = redirect_all_stdout)
{
    Fixed a(2);
    Fixed b(-5);

    cr_assert_not(a == b);
    cr_assert_not(b == a);
}

Test(Fixed_class, Test_equal_equal_operator_overload_with_large_values,
.init = redirect_all_stdout)
{
    Fixed a(500000);
    Fixed b(1000000);

    cr_assert_not(a == b);
    cr_assert_not(b == a);
}

Test(Fixed_class, Test_different_operator_basic_overload,
.init = redirect_all_stdout)
{
    Fixed a(5);
    Fixed b(10);
    
    cr_assert(a != b);
    cr_assert(b != a);
}

Test(Fixed_class, Test_different_operator_overload_with_equal_values,
.init = redirect_all_stdout)
{
    Fixed a(7);
    Fixed b(7);

    cr_assert_not(a != b);
    cr_assert_not(b != a);
}

Test(Fixed_class, Test_different_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed a(-7);
    Fixed b(-3);

    cr_assert(a != b);
    cr_assert(b != a);
}

Test(Fixed_class, Test_different_operator_overload_with_mixed_values,
.init = redirect_all_stdout)
{
    Fixed a(2);
    Fixed b(-5);

    cr_assert(a != b);
    cr_assert(b != a);
}

Test(Fixed_class, Test_different_operator_overload_with_large_values,
.init = redirect_all_stdout)
{
    Fixed a(500000);
    Fixed b(1000000);

    cr_assert(a != b);
    cr_assert(b != a);
}

Test(Fixed_class, Test_addition_operator_overload_basic,
.init = redirect_all_stdout)
{
    Fixed   a(10);
    Fixed   b(5);
    Fixed   result = a + b;

    cr_assert_eq(result.toInt(), 15);
}

Test(Fixed_class, Test_addition_operator_overload_with_zero,
.init = redirect_all_stdout)
{
    Fixed   a(7);
    Fixed   b(0);
    Fixed   result = a + b;

    cr_assert_eq(result.toInt(), 7);
}

Test(Fixed_class, Test_addition_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed   a(-3);
    Fixed   b(7);
    Fixed   result = a + b;

    cr_assert_eq(result.toInt(), 4);
}

Test(Fixed_class, Test_addition_operator_overload_both_negative,
.init = redirect_all_stdout)
{
    Fixed   a(-5);
    Fixed   b(-2);
    Fixed   result = a + b;

    cr_assert_eq(result.toInt(), -7);
}

Test(Fixed_class, Test_addition_operator_overload_large_values,
.init = redirect_all_stdout)
{
    Fixed   a(1000000);
    Fixed   b(500000);
    Fixed   result = a + b;

    cr_assert_eq(result.toInt(), 1500000);
}

Test(Fixed_class, Test_addition_operator_overload_overflow,
.init = redirect_all_stdout)
{
    Fixed   a(std::numeric_limits<int>::max());
    Fixed   b(1);
    Fixed   result = a + b;


    cr_assert(result.toInt() >= 0);
}

Test(Fixed_class, Test_addition_operator_overload_negative_overflow,
.init = redirect_all_stdout)
{
    Fixed   a(std::numeric_limits<int>::max());
    Fixed   b(-1);
    Fixed   result = a + b;

    cr_assert(result.toInt() <= 0);
}

Test(Fixed_class, Test_subtraction_operator_overload_basic,
.init = redirect_all_stdout)
{
    Fixed   a(10);
    Fixed   b(5);
    Fixed   result = a - b;

    cr_assert_eq(result.toInt(), 5);
}

Test(Fixed_class, Test_subtraction_operator_overload_with_zero,
.init = redirect_all_stdout)
{
    Fixed   a(7);
    Fixed   b(0);
    Fixed   result = a - b;

    cr_assert_eq(result.toInt(), 7);
}

Test(Fixed_class, Test_subtraction_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed   a(-3);
    Fixed   b(7);
    Fixed   result = a - b;

    cr_assert_eq(result.toInt(), -10);
}

Test(Fixed_class, Test_subtraction_operator_overload_both_negative,
.init = redirect_all_stdout)
{
    Fixed   a(-5);
    Fixed   b(-2);
    Fixed   result = a - b;

    cr_assert_eq(result.toInt(), -3);
}

Test(Fixed_class, Test_subtraction_operator_overload_large_values,
.init = redirect_all_stdout)
{
    Fixed   a(1000000);
    Fixed   b(500000);
    Fixed   result = a - b;

    cr_assert_eq(result.toInt(), 500000);
}

Test(Fixed_class, Test_subtraction_operator_overload_overflow,
.init = redirect_all_stdout)
{
    Fixed   a(std::numeric_limits<int>::max());
    Fixed   b(1);
    Fixed   result = a - b;

    cr_assert(result.toInt() <= 0);
}

Test(Fixed_class, Test_subtraction_operator_overload_negative_overflow,
.init = redirect_all_stdout)
{
    Fixed   a(std::numeric_limits<int>::max());
    Fixed   b(-1);
    Fixed   result = a - b;

    cr_assert(result.toInt() >= 0);
}

Test(Fixed_class, Test_multiplication_operator_overload_basic,
.init = redirect_all_stdout)
{
    Fixed   a(10);
    Fixed   b(5);
    Fixed   result = a * b;

    cr_assert_eq(result.toInt(), 50);
}

Test(Fixed_class, Test_multiplication_operator_overload_with_zero,
.init = redirect_all_stdout)
{
    Fixed   a(7);
    Fixed   b(0);
    Fixed   result = a * b;

    cr_assert_eq(result.toInt(), 0);
}

Test(Fixed_class, Test_multiplication_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed   a(-3);
    Fixed   b(7);
    Fixed   result = a * b;

    cr_assert_eq(result.toInt(), -21);
}

Test(Fixed_class, Test_multiplication_operator_overload_both_negative,
.init = redirect_all_stdout)
{
    Fixed   a(-5);
    Fixed   b(-2);
    Fixed   result = a * b;

    cr_assert_eq(result.toInt(), 10);
}

Test(Fixed_class, Test_multiplication_operator_overload_large_values,
.init = redirect_all_stdout)
{
    Fixed   a(1000000);
    Fixed   b(500000);
    Fixed   result = a * b;

    cr_assert(result.toInt() <= 0);
}

Test(Fixed_class, Test_multiplication_operator_overload_overflow,
.init = redirect_all_stdout)
{
    Fixed   a(std::numeric_limits<int>::max());
    Fixed   b(1);
    Fixed   result = a * b;

    cr_assert(result.toInt() <= 0);
}

Test(Fixed_class, Test_multiplication_operator_overload_negative_overflow,
.init = redirect_all_stdout)
{
    Fixed   a(std::numeric_limits<int>::min());
    Fixed   b(-1);
    Fixed   result = a * b;

    cr_assert(result.toInt() <= 0);
}

Test(Fixed_class, Test_division_operator_overload_basic,
.init = redirect_all_stdout)
{
    Fixed   a(10);
    Fixed   b(5);
    Fixed   result = a / b;

    cr_assert_eq(result.toInt(), a.toInt() / b.toInt());
}

Test(Fixed_class, Test_division_operator_overload_with_zero,
.init = redirect_all_stdout)
{
    Fixed   a(7);
    Fixed   b(0);
    Fixed   result = a / b;

    cr_assert_eq(result.toInt(), 0);
}

Test(Fixed_class, Test_division_operator_overload_with_negative_values,
.init = redirect_all_stdout)
{
    Fixed   a(-3);
    Fixed   b(7);
    Fixed   result = a / b;

    cr_assert_eq(result.toInt(), a.toInt() / b.toInt());
}

Test(Fixed_class, Test_division_operator_overload_both_negative,
.init = redirect_all_stdout)
{
    Fixed   a(-5);
    Fixed   b(-2);
    Fixed   result = a / b;

    cr_assert_eq(result.toInt(), a.toInt() / b.toInt());
}

Test(Fixed_class, Test_division_operator_overload_large_values,
.init = redirect_all_stdout)
{
    Fixed   a(1000000);
    Fixed   b(500000);
    Fixed   result = a / b;

    cr_assert(result.toInt() == a.toInt() / b.toInt());
}

Test(Fixed_class, Test_division_operator_overload_overflow,
.init = redirect_all_stdout)
{
    Fixed   a(std::numeric_limits<int>::max());
    Fixed   b(1);
    Fixed   result = a / b;

    cr_assert(result.toInt() == a.toInt() / b.toInt());
}

Test(Fixed_class, Test_division_operator_overload_negative_overflow,
.init = redirect_all_stdout)
{
    Fixed   a(std::numeric_limits<int>::max());
    Fixed   b(-1);
    Fixed   result = a / b;

    cr_assert(result.toInt() == a.toInt() / b.toInt());
}

Test(Fixed_class, Test_pre_increment_operator, .init = redirect_all_stdout)
{
    Fixed a(10);
    ++a;

    cr_assert_eq(a.getRawBits(), 2561);
}

Test(Fixed_class, Test_post_increment_operator, .init = redirect_all_stdout)
{
    Fixed a(10);
    Fixed old_a = a++; // Sauvegarde l'ancienne valeur

    cr_assert_eq(old_a.getRawBits(), 2560);
    cr_assert_eq(a.getRawBits(), 2561);
}


Test(Fixed_class, Test_pre_decrement_operator, .init = redirect_all_stdout)
{
    Fixed a(10);
    --a;

    cr_assert_eq(a.getRawBits(), 2559);
}

Test(Fixed_class, Test_post_decrement_operator, .init = redirect_all_stdout)
{
    Fixed a(10);
    Fixed old_a = a--; // Sauvegarde l'ancienne valeur

    cr_assert_eq(old_a.getRawBits(), 2560);
    cr_assert_eq(a.getRawBits(), 2559);
}

Test(Fixed_class, Test_min_function_mutable, .init = redirect_all_stdout)
{
    Fixed a(10);
    Fixed b(5);
    Fixed &result = Fixed::min(a, b);

   cr_assert_eq(&result, &b);
}

Test(Fixed_class, Test_min_function_const, .init = redirect_all_stdout)
{
    const Fixed a(10);
    const Fixed b(3);
    const Fixed &result = Fixed::min(a, b);

   cr_assert_eq(&result, &b);
}

Test(Fixed_class, Test_min_function_equal_values, .init = redirect_all_stdout)
{
    Fixed a(7);
    Fixed b(7);
    Fixed &result = Fixed::min(a, b);


    cr_assert_eq(&result, &a);
}

Test(Fixed_class, Test_min_function_negative_values,
    .init = redirect_all_stdout)
{
    Fixed a(-5);
    Fixed b(-10);
    Fixed &result = Fixed::min(a, b);

    cr_assert_eq(&result, &b);
}

Test(Fixed_class, Test_max_function_mutable, .init = redirect_all_stdout)
{
    Fixed a(10);
    Fixed b(5);
    Fixed &result = Fixed::max(a, b);

   cr_assert_eq(&result, &a);
}

Test(Fixed_class, Test_max_function_const, .init = redirect_all_stdout)
{
    const Fixed a(10);
    const Fixed b(3);
    const Fixed &result = Fixed::max(a, b);

   cr_assert_eq(&result, &a);
}

Test(Fixed_class, Test_max_function_equal_values, .init = redirect_all_stdout)
{
    Fixed a(7);
    Fixed b(7);
    Fixed &result = Fixed::max(a, b);


    cr_assert_eq(&result, &a);
}

Test(Fixed_class, Test_max_function_negative_values,
    .init = redirect_all_stdout)
{
    Fixed a(-5);
    Fixed b(-10);
    Fixed &result = Fixed::max(a, b);

    cr_assert_eq(&result, &a);
}

///////////////////////////////////////////////////////////////////////////////
//                            Point class                                    //
///////////////////////////////////////////////////////////////////////////////
Test(Point_class, Test_default_CTOR_isDefined, .init = redirect_all_stdout)
{
    Point p;

    cr_assert_not_null(&p);
}

Test(Point_Tests, TEST_Default_constructor_initializes_to_zero
    , .init = redirect_all_stdout)
{
    Point p;
    cr_assert_eq(p.getX().toFloat(), 0.0f);
    cr_assert_eq(p.getY().toFloat(), 0.0f);
    cr_assert_eq(p.getX().toInt(), 0);
    cr_assert_eq(p.getY().toInt(), 0);
}


Test(Point_Tests, TEST_Constructor_with_parameters,
    .init = redirect_all_stdout)
{
    Point p(3.5f, -2.7f);

    cr_assert_float_eq(p.getX().toFloat(), 3.5f, 0.01f);
    cr_assert_float_eq(p.getY().toFloat(), -2.7f, 0.01f);
}

Test(Point_Tests, TEST_Copy_constructor, .init = redirect_all_stdout)
{
    Point p1(4.2f, 1.1f);
    Point p2(p1);

    cr_assert_float_eq(p2.getX().toFloat(), 4.2f, 0.01f);    
    cr_assert_float_eq(p2.getY().toFloat(), 1.1f, 0.01f);
}

Test(Point_Tests,
TEST_Assignment_operator_does_nothing_because_x_and_y_are_const,
.init = redirect_all_stdout)
{
    Point p1(2.2f, 3.3f);
    Point p2;

    p2 = p1;
    
    cr_assert_float_eq(p2.getX().toFloat(), 0.0f, 0.01f);
    cr_assert_float_eq(p2.getY().toFloat(), 0.0f, 0.01f);
}

Test(Point_Tests, Getters, , .init = redirect_all_stdout)
{
    Point p(-7.8f, 6.2f);
    cr_assert_float_eq(p.getX().toFloat(), -7.8f, 0.01f);
    cr_assert_float_eq(p.getY().toFloat(), 6.2f, 0.01f);
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////


Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
    }
    cr_assert_stdout_eq_str(
        "0\n"
        "0.00390625\n"
        "0.00390625\n"
        "0.00390625\n"
        "0.0078125\n"
        "10.1016\n"
        "10.1016\n"
    );
}