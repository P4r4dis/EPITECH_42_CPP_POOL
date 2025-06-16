/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:26:43 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/16 15:39:53 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include <iostream>

#include "../../include/Bureaucrat.hpp"
#include "../../include/Form.hpp"


void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Bureaucrat_CTOR, TEST_CTOR_correctly_created, .init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("name", 42);

        cr_assert_not_null(&bureau);
    }
}

Test(Bureaucrat_CTOR, TEST_CTOR_shouldndt_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_none_throw(Bureaucrat bureau("name", 42));
    }
}

Test(Bureaucrat_CTOR, TEST_CTOR_with_too_small_grade_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Bureaucrat("name", 242),
                        Bureaucrat::GradeTooLowException);
    }
}

Test(Bureaucrat_CTOR, TEST_CTOR_with_too_high_grade_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Bureaucrat("name", 0),
                        Bureaucrat::GradeTooHighException);
    }
}

Test(Bureaucrat_CTOR,
TEST_CTOR_with_try_catch_should_throw_GradeTooHighException_exception_stderr,
.init = redirect_all_stdout)
{
    {
        try
        {
            Bureaucrat bureau("name", 0);
        } catch (Bureaucrat::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too high.\n"
    );
}

Test(Bureaucrat_CTOR,
TEST_CTOR_with_try_catch_should_throw_GradeTooLowException_exception_stderr,
.init = redirect_all_stdout)
{
    {
        try
        {
            Bureaucrat bureau("name", 151);
        } catch (Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too low.\n"
    );
}

Test(Bureaucrat_getName, TEST_getName_should_return_name,
.init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("name", 42);

        cr_assert(bureau.getName() == "name");
    }
}

Test(Bureaucrat_getGrade, TEST_getGrade_should_return_grade,
.init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("name", 42);

        cr_assert(bureau.getGrade() == 42);
    }
}

Test(Bureaucrat_increment, TEST_increment_grade,
.init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("name", 42);

        cr_assert(bureau.getGrade() == 42);
        bureau.increment();
        cr_assert(bureau.getGrade() == 41);
    }
}

Test(Bureaucrat_increment,
TEST_increment_grade_should_throw_exception_if_overflow,
.init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("name", 1);

        cr_assert(bureau.getGrade() == 1);
        cr_assert_throw(bureau.increment(),
                        Bureaucrat::GradeTooHighException);
    }
}

Test(Bureaucrat_decrement, TEST_decrement_grade,
.init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("name", 42);

        cr_assert(bureau.getGrade() == 42);
        bureau.decrement();
        cr_assert(bureau.getGrade() == 43);
    }
}

Test(Bureaucrat_decrement,
TEST_decrement_grade_should_throw_exception_if_overflow,
.init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("name", 150);

        cr_assert(bureau.getGrade() == 150);
        cr_assert_throw(bureau.decrement(),
                        Bureaucrat::GradeTooLowException);
    }
}

Test(Bureaucrat_left_stream_operator,
TEST_left_stream_operator_overload_display_msg,
.init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("Bob", 42);

        std::cout << bureau << std::endl;
    }
    cr_assert_stdout_eq_str("Bob, bureaucrat grade 42.\n");
}

///////////////////////////////////////////////////////////////////////////////
//                            Form class                                     //
///////////////////////////////////////////////////////////////////////////////
Test(Form_CTOR, TEST_CTOR_correctly_created, .init = redirect_all_stdout)
{
    {
        Form    form("Bob", 42, 20);

        cr_assert_not_null(&form);
    }
}

Test(Form_CTOR, TEST_CTOR_shouldndt_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_none_throw(Form form("Bob", 42, 20));
    }
}

Test(Form_CTOR, TEST_CTOR_with_too_small_gradeToSign_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Form form("Bob", 242, 20),
                        Form::GradeTooLowException);
    }
}

Test(Form_CTOR, TEST_CTOR_with_too_high_gradeToSign_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Form form("Bob", 0, 20),
                        Form::GradeTooHighException);
    }
}

Test(Form_CTOR, TEST_CTOR_with_too_small_gradeToExecute_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Form form("Bob", 42, 242),
                        Form::GradeTooLowException);
    }
}

Test(Form_CTOR, TEST_CTOR_with_too_high_gradeToExecute_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Form form("Bob", 42, 0),
                        Form::GradeTooHighException);
    }
}

Test(Form_what,
TEST_gradeToSign_is_too_high_should_throw_GradeTooHighException,
.init = redirect_all_stdout)
{
    {
        try
        {
            Form    form("Bob", 0, 20);
        } catch (Form::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too high.\n"
    );
}

Test(Form_what,
TEST_gradeToExecute_is_too_high_should_throw_GradeTooHighException,
.init = redirect_all_stdout)
{
    {
        try
        {
            Form    form("Bob", 42, 0);
        } catch (Form::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too high.\n"
    );
}

Test(Form_what,
TEST_gradeToSign_is_too_low_should_throw_GradeTooLowException,
.init = redirect_all_stdout)
{
    {
        try
        {
            Form    form("Bob", 242, 20);
        } catch (Form::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too low.\n"
    );
}

Test(Form_what,
TEST_gradeToExecute_is_too_low_should_throw_GradeTooLowException,
.init = redirect_all_stdout)
{
    {
        try
        {
            Form    form("Bob", 42, 242);
        } catch (Form::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too low.\n"
    );
}

Test(Form_getName, Test_return_name, .init = redirect_all_stdout)
{
    Form    form("Bob", 42, 42);

    cr_assert(form.getName() == "Bob");
}

Test(Form_getisSigned, Test_return_isSigned, .init = redirect_all_stdout)
{
    Form    form("Bob", 42, 42);

    cr_assert(form.getIsSigned() == false);
}
///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
    {
        Bureaucrat bureau("Bob", 42);

        cr_assert(bureau.getName() == "Bob");
        cr_assert(bureau.getGrade() == 42);
        bureau.increment();
        cr_assert(bureau.getGrade() == 41);
        bureau.decrement();
        cr_assert(bureau.getGrade() == 42);
        std::cout << bureau << std::endl;

        try
        {
            Bureaucrat bureau("name", 1);

            cr_assert(bureau.getName() == "name");
            cr_assert(bureau.getGrade() == 1);
            bureau.increment();
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        try
        {
            Bureaucrat bureau("name", 150);

            cr_assert(bureau.getName() == "name");
            cr_assert(bureau.getGrade() == 150);
            bureau.decrement();
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

    }
    cr_assert_stdout_eq_str("Bob, bureaucrat grade 42.\n");
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too high.\n"
        "Error: Grade is too low.\n"
    );
}