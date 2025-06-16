/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:26:43 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/16 18:56:35 by Paradis          ###   ########.fr       */
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

Test(Bureaucrat_signForm, TEST_if_form_is_signed_print_msg_stdout,
.init = redirect_all_stdout)
{
    Form        form("A43", 42, 42);
    Bureaucrat  bureaucrat("Bob", 42);

    bureaucrat.signForm(form);
    cr_assert_stdout_eq_str
    (
        "Bob signed A43\n"
    );
}

Test(Bureaucrat_signForm, TEST_if_form_is_not_signed_print_msg_stdout,
.init = redirect_all_stdout)
{
    Form        form("A43", 42, 42);
    Bureaucrat  bureaucrat("Bob", 45);

    bureaucrat.signForm(form);
    cr_assert_stdout_eq_str
    (
        "Bob couldn't sign A43 because Error: Grade is too low.\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
//                            Form class                                     //
///////////////////////////////////////////////////////////////////////////////
Test(Form_CTOR, TEST_CTOR_correctly_created, .init = redirect_all_stdout)
{
    {
        Form    form("A43", 42, 20);

        cr_assert_not_null(&form);
    }
}

Test(Form_CTOR, TEST_CTOR_shouldndt_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_none_throw(Form form("A43", 42, 20));
    }
}

Test(Form_CTOR, TEST_CTOR_with_too_small_gradeToSign_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Form form("A43", 242, 20),
                        Form::GradeTooLowException);
    }
}

Test(Form_CTOR, TEST_CTOR_with_too_high_gradeToSign_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Form form("A43", 0, 20),
                        Form::GradeTooHighException);
    }
}

Test(Form_CTOR, TEST_CTOR_with_too_small_gradeToExecute_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Form form("A43", 42, 242),
                        Form::GradeTooLowException);
    }
}

Test(Form_CTOR, TEST_CTOR_with_too_high_gradeToExecute_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        cr_assert_throw(Form form("A43", 42, 0),
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
            Form    form("A43", 0, 20);
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
            Form    form("A43", 42, 0);
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
            Form    form("A43", 242, 20);
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
            Form    form("A43", 42, 242);
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
    Form    form("A43", 42, 42);

    cr_assert(form.getName() == "A43");
}

Test(Form_getisSigned, Test_return_isSigned, .init = redirect_all_stdout)
{
    Form    form("A43", 42, 42);

    cr_assert(form.getIsSigned() == false);
}

Test(Form_getGradeToSign, Test_return_gradeToSign, .init = redirect_all_stdout)
{
    Form    form("A43", 42, 42);

    cr_assert(form.getGradeToSign() == 42);
}

Test(Form_getGradeToExecute, Test_return_gradeToExecute,
.init = redirect_all_stdout)
{
    Form    form("A43", 42, 42);

    cr_assert(form.getGradeToSign() == 42);
}

Test(Form_copy_CTOR, TEST_simple_copy, .init = redirect_all_stdout)
{
    Form    form("A43", 42, 42);
    Form    copy(form);

    cr_assert(copy.getName() == form.getName());
    cr_assert(copy.getIsSigned() == form.getIsSigned());
    cr_assert(copy.getGradeToSign() == form.getGradeToSign());
    cr_assert(copy.getGradeToExecute() == form.getGradeToExecute());
}

Test(Form_assignment_operator, TEST_simple_assignement, .init = redirect_all_stdout)
{
    Form    form("A43", 42, 42);
    Form    copy("B75", 90, 50);

    cr_assert(copy.getName() != form.getName());
    cr_assert(copy.getIsSigned() == form.getIsSigned());
    cr_assert(copy.getGradeToSign() != form.getGradeToSign());
    cr_assert(copy.getGradeToExecute() != form.getGradeToExecute());

    copy = form;

    cr_assert(copy.getIsSigned() == form.getIsSigned());
}

Test(Form_beSigned, TEST_form_can_be_signed_by_bureaucrat,
.init = redirect_all_stdout)
{
    Form        form("A43", 42, 42);
    Bureaucrat  bureaucrat("Bob", 41);

    cr_assert(form.getIsSigned() == false);

    form.beSigned(bureaucrat);

    cr_assert(form.getIsSigned() == true);
}

Test(Form_beSigned,
TEST_form_can_be_signed_by_bureaucrat_if_grade_is_equal_to_gradToSign,
.init = redirect_all_stdout)
{
    Form        form("A43", 42, 42);
    Bureaucrat  bureaucrat("Bob", 42);

    cr_assert(form.getIsSigned() == false);

    form.beSigned(bureaucrat);

    cr_assert(form.getIsSigned() == true);
}

Test(Form_beSigned,
TEST_form_cant_be_signed_by_bureaucrat_and_throw_exception,
.init = redirect_all_stdout)
{
    Form        form("A43", 42, 42);
    Bureaucrat  bureaucrat("Bob", 43);

    cr_assert(form.getIsSigned() == false);

    cr_assert_throw(form.beSigned(bureaucrat), Bureaucrat::GradeTooLowException);
    cr_assert(form.getIsSigned() == false);
}

Test(Form_left_stream_operator,
TEST_left_stream_operator_overload_display_msg_stdout,
.init = redirect_all_stdout)
{
    {
        Form        form("A43", 42, 42);

        std::cout << form << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "Form name: A43\n"
        "Form grade to sign: 42\n"
        "Form grade to execute: 42\n"
        "Form is signed: false\n"
    );
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