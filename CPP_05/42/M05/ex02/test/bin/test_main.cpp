/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:07:07 by Paradis           #+#    #+#             */
/*   Updated: 2025/06/18 16:44:20 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/logging.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/output.h>

#include <iostream>

#include "../../include/Bureaucrat.hpp"
#include "../../include/AForm.hpp"
#include "../../include/ShrubberyCreationForm.hpp"
#include "../../include/RobotomyRequestForm.hpp"
#include "../../include/PresidentialPardonForm.hpp"




void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

#ifndef                 __DUMMYFORM_HPP__
#define                 __DUMMYFORM_HPP__

#include <ostream>

class Bureaucrat;

#define HIGHEST 1
#define LOWEST  150
class DummyForm : public AForm {
    public:
        DummyForm(const std::string &name, const size_t gradeToSign,
                  const size_t gradeToExecute)
            : AForm(name, gradeToSign, gradeToExecute) {}

        DummyForm(const DummyForm &cpy)
            : AForm(cpy) {}

        DummyForm &operator=(const DummyForm &form) {
            if (this != &form)
                AForm::operator=(form);
            return *this;
        }

        virtual ~DummyForm() {}

        void beSigned(const Bureaucrat &bureaucrat)  {
            AForm::beSigned(bureaucrat);
        }

        void execute(Bureaucrat const &executor) const {
            (void)executor;
            // Dummy implementation for testing
        }

        virtual void executeAction() const
        {
            std::fstream    file("Form_shrubbery", std::fstream::out);
            
            if (file.is_open())
            {
                file    << "       _-_" << std::endl;
                file    << "    /~~   ~~\\" << std::endl;
                file    << " /~~         ~~\\" << std::endl;
                file    << "{               }" << std::endl;
                file    << " \\  _-     -_  /" << std::endl;
                file    << "   ~  \\ //  ~" << std::endl;
                file    << "_- -   | | _- _" << std::endl;
                file    << "  _ -  | |   -_" << std::endl;
                file    << "      /   \\" << std::endl;
                file    << "     /     \\" << std::endl;
            }
            file.close();
        }
};

#endif //               !_DUMMYFORM_HPP__

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
    // AForm       form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
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
    // AForm       form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    Bureaucrat  bureaucrat("Bob", 45);

    bureaucrat.signForm(form);
    cr_assert_stdout_eq_str
    (
        "Bob couldn't sign A43 because Error: Grade is too low.\n"
    );
}

Test(Bureaucrat_executeForm, TEST_exception_catched_because_form_not_signed,
.init = redirect_all_stdout)
{
    // AForm       form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    Bureaucrat  bureaucrat("Bob", 45);

    bureaucrat.executeForm(form);
    cr_assert_stdout_eq_str
    (
        "Bob can't execute form A43 because Error: is not signed.\n"
    );
}

Test(Bureaucrat_executeForm,
TEST_exception_catched_and_display_msg_because_grade_to_execute_is_too_low,
.init = redirect_all_stdout)
{
    // AForm       form("A43", 42, 42);
    DummyForm   dummy("A43", 130, 42);
    AForm       &form = dummy;
    Bureaucrat  bureaucrat("Bob", 45);
    bureaucrat.signForm(form);

    bureaucrat.executeForm(form);

    cr_assert_stdout_eq_str
    (
        "Bob signed A43\n"
        "Bob can't execute form A43 because Error: Grade is too low.\n"
    );
}

Test(Bureaucrat_executeForm, TEST_execute_form, .init = redirect_all_stdout)
{
    // AForm       form("A43", 42, 42);
    DummyForm   dummy("A43", 130, 42);
    AForm       &form = dummy;
    Bureaucrat  bureaucrat("Bob", 41);
    bureaucrat.signForm(form);

    bureaucrat.executeForm(form);
    cr_assert_stdout_eq_str
    (
        "Bob signed A43\n"
        "Bob executed form A43\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            AForm class                                     //
///////////////////////////////////////////////////////////////////////////////
Test(AForm_CTOR, TEST_CTOR_correctly_created, .init = redirect_all_stdout)
{
    {
        // AForm    form("A43", 42, 20);
        DummyForm   dummy("A43", 42, 20);
        AForm       &form = dummy;
        
        cr_assert_not_null(&form);
    }
}

Test(AForm_CTOR, TEST_CTOR_shouldndt_throw_exception,
.init = redirect_all_stdout)
{
    {
        // cr_assert_none_throw(AForm form("A43", 42, 20));
        cr_assert_none_throw(
            DummyForm   dummy("A43", 42, 20);
            // AForm       &form = dummy;
        );
    }
}

Test(AForm_CTOR, TEST_CTOR_with_too_small_gradeToSign_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        // cr_assert_throw(AForm form("A43", 242, 20),
        //                 AForm::GradeTooLowException);
        cr_assert_throw(
            DummyForm   dummy("A43", 242, 20);,
            AForm::GradeTooLowException
        );
    }
}

Test(AForm_CTOR, TEST_CTOR_with_too_high_gradeToSign_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        // cr_assert_throw(AForm form("A43", 0, 20),
        //                 AForm::GradeTooHighException);
        cr_assert_throw(
            DummyForm   dummy("A43", 0, 20);,
            // AForm       &form = dummy;,
            AForm::GradeTooHighException
        );
    }
}

Test(AForm_CTOR, TEST_CTOR_with_too_small_gradeToExecute_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        // cr_assert_throw(AForm form("A43", 42, 242),
        //                 AForm::GradeTooLowException);
        cr_assert_throw(
            DummyForm   dummy("A43", 42, 242);,
            // AForm       &form = dummy;,
            AForm::GradeTooLowException
        );
    }
}

Test(AForm_CTOR, TEST_CTOR_with_too_high_gradeToExecute_should_throw_exception,
.init = redirect_all_stdout)
{
    {
        // cr_assert_throw(AForm form("A43", 42, 0),
        //                 AForm::GradeTooHighException);
        cr_assert_throw(
            DummyForm   dummy("A43", 42, 0);,
            // AForm       &form = dummy;,
            AForm::GradeTooHighException
        );
    }
}

Test(AForm_what,
TEST_gradeToSign_is_too_high_should_throw_GradeTooHighException,
.init = redirect_all_stdout)
{
    {
        try
        {
            // AForm    form("A43", 0, 20);
            DummyForm   dummy("A43", 0, 20);
            // AForm       &form = dummy;
        } catch (AForm::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too high.\n"
    );
}

Test(AForm_what,
TEST_gradeToExecute_is_too_high_should_throw_GradeTooHighException,
.init = redirect_all_stdout)
{
    {
        try
        {
            // AForm    form("A43", 42, 0);
            DummyForm   dummy("A43", 42, 0);
            // AForm       &form = dummy;
        } catch (AForm::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too high.\n"
    );
}

Test(AForm_what,
TEST_gradeToSign_is_too_low_should_throw_GradeTooLowException,
.init = redirect_all_stdout)
{
    {
        try
        {
            // AForm    form("A43", 242, 20);
            DummyForm   dummy("A43", 242, 20);
            // AForm       &form = dummy;
        } catch (AForm::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too low.\n"
    );
}

Test(AForm_what,
TEST_gradeToExecute_is_too_low_should_throw_GradeTooLowException,
.init = redirect_all_stdout)
{
    {
        try
        {
            // AForm    form("A43", 42, 242);
            DummyForm   dummy("A43", 42, 242);
            // AForm       &form = dummy;
        } catch (AForm::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    cr_assert_stderr_eq_str
    (
        "Error: Grade is too low.\n"
    );
}

Test(AForm_getName, Test_return_name, .init = redirect_all_stdout)
{
    // AForm    form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    cr_assert(form.getName() == "A43");
}

Test(AForm_getisSigned, Test_return_isSigned, .init = redirect_all_stdout)
{
    // AForm    form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;

    cr_assert(form.getIsSigned() == false);
}

Test(AForm_getGradeToSign, Test_return_gradeToSign, .init = redirect_all_stdout)
{
    // AForm    form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    
    cr_assert(form.getGradeToSign() == 42);
}

Test(AForm_getGradeToExecute, Test_return_gradeToExecute,
.init = redirect_all_stdout)
{
    // AForm    form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    
    cr_assert(form.getGradeToSign() == 42);
}

Test(AForm_copy_CTOR, TEST_simple_copy, .init = redirect_all_stdout)
{
    // AForm    form("A43", 42, 42);
    // AForm    copy(form);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    DummyForm   copy(dummy);

    cr_assert(copy.getName() == form.getName());
    cr_assert(copy.getIsSigned() == form.getIsSigned());
    cr_assert(copy.getGradeToSign() == form.getGradeToSign());
    cr_assert(copy.getGradeToExecute() == form.getGradeToExecute());
}

Test(AForm_assignment_operator, TEST_simple_assignement, .init = redirect_all_stdout)
{
    // AForm    form("A43", 42, 42);
    // AForm    copy("B75", 90, 50);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    DummyForm   copy("B75", 90, 50);
    
    cr_assert(copy.getName() != form.getName());
    cr_assert(copy.getIsSigned() == form.getIsSigned());
    cr_assert(copy.getGradeToSign() != form.getGradeToSign());
    cr_assert(copy.getGradeToExecute() != form.getGradeToExecute());

    copy = dummy;

    cr_assert(copy.getIsSigned() == form.getIsSigned());
}

Test(AForm_beSigned, TEST_form_can_be_signed_by_bureaucrat,
.init = redirect_all_stdout)
{
    // AForm       form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    Bureaucrat  bureaucrat("Bob", 41);

    cr_assert(form.getIsSigned() == false);

    form.beSigned(bureaucrat);

    cr_assert(form.getIsSigned() == true);
}

Test(AForm_beSigned,
TEST_form_can_be_signed_by_bureaucrat_if_grade_is_equal_to_gradToSign,
.init = redirect_all_stdout)
{
    // AForm       form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    Bureaucrat  bureaucrat("Bob", 42);

    cr_assert(form.getIsSigned() == false);

    form.beSigned(bureaucrat);

    cr_assert(form.getIsSigned() == true);
}

Test(AForm_beSigned,
TEST_form_cant_be_signed_by_bureaucrat_and_throw_exception,
.init = redirect_all_stdout)
{
    // AForm       form("A43", 42, 42);
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    Bureaucrat  bureaucrat("Bob", 43);

    cr_assert(form.getIsSigned() == false);

    cr_assert_throw(form.beSigned(bureaucrat), Bureaucrat::GradeTooLowException);
    cr_assert(form.getIsSigned() == false);
}

Test(AForm_left_stream_operator,
TEST_left_stream_operator_overload_display_msg_stdout,
.init = redirect_all_stdout)
{
    {
        // AForm        form("A43", 42, 42);
        DummyForm   dummy("A43", 42, 42);
        AForm       &form = dummy;
        
        std::cout << form << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "AForm name: A43\n"
        "AForm grade to sign: 42\n"
        "AForm grade to execute: 42\n"
        "AForm is signed: false\n"
    );
}

Test(AForm_execute, Test_checks_if_form_is_signed, .init = redirect_all_stdout)
{
    DummyForm   dummy("A43", 42, 42);
    AForm       &form = dummy;
    Bureaucrat  bureau("Bob", 30);

    try 
    {
        form.execute(bureau);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "Error: is not signed.\n"
    );
}

Test(AForm_execute, Test_checks_if_grade_of_executor_is_correct,
.init = redirect_all_stdout)
{
    DummyForm   dummy("A43", 50, 42);
    AForm       &form = dummy;
    Bureaucrat  bureau("Bob", 43);
    bureau.signForm(form);
    try 
    {
        form.execute(bureau);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "Bob signed A43\n"
        "Error: Grade is too low.\n"
    );
}

Test(AForm_execute, Test_execute_Form, .init = redirect_all_stdout)
{
        DummyForm   dummy("A43", 50, 42);

    // ShrubberyCreationForm   shrubbery("Form");
    // AForm                   &form = shrubbery;
        AForm                   &form = dummy;

    Bureaucrat              bureau("Bob", 30);
    std::string             myText;
    std::fstream            file;

    bureau.signForm(form);
    form.execute(bureau);
    // file.open(shrubbery.getTarget() + "_shrubbery", std::fstream::in);
    file.open("Form_shrubbery", std::fstream::in);

    while (getline (file, myText))
        std::cout << myText << std::endl;
    file.close();
    cr_assert_stdout_eq_str
    (
        "Bob signed A43\n"
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      /   \\\n"
        "     /     \\\n"
    );
    // cr_assert_stdout_eq_str
    // (
    //     "Bob signed ShrubberyCreationForm\n"
    //     "       _-_\n"
    //     "    /~~   ~~\\\n"
    //     " /~~         ~~\\\n"
    //     "{               }\n"
    //     " \\  _-     -_  /\n"
    //     "   ~  \\ //  ~\n"
    //     "_- -   | | _- _\n"
    //     "  _ -  | |   -_\n"
    //     "      /   \\\n"
    //     "     /     \\\n"
    // );
}

///////////////////////////////////////////////////////////////////////////////
//                            ShrubberyCreationForm class                    //
///////////////////////////////////////////////////////////////////////////////
Test(ShrubberyCreationForm_CTOR,
    TEST_CTOR_correctly_created, .init = redirect_all_stdout)
{
    {
        ShrubberyCreationForm   shrubbery("Form");
        
        cr_assert_not_null(&shrubbery);
    }
}

Test(ShrubberyCreationForm_getTarget,
    TEST_return_target, .init = redirect_all_stdout)
{
    {
        ShrubberyCreationForm   shrubbery("Form");
        
        cr_assert(shrubbery.getTarget() == "Form");
    }
}

Test(ShrubberyCreationForm_copy_CTOR, TEST_simple_copy,
    .init = redirect_all_stdout)
{
    ShrubberyCreationForm   shrubbery("Form");
    ShrubberyCreationForm   copy(shrubbery);

    cr_assert(copy.getTarget() == shrubbery.getTarget());
}

Test(ShrubberyCreationForm_assignment_operator,
    TEST_simple_assignement, .init = redirect_all_stdout)
{
    ShrubberyCreationForm   shrubbery("Form");
    ShrubberyCreationForm   assigned("Form2");

    cr_assert(assigned.getTarget() != shrubbery.getTarget());
    assigned = shrubbery;
    cr_assert(assigned.getTarget() == shrubbery.getTarget());

}

Test(ShrubberyCreationForm_executeAction,
    TEST_create_file_and_write_to_it, .init = redirect_all_stdout)
{
    ShrubberyCreationForm   shrubbery("Form");
    std::string             myText;
    std::fstream            file;

    shrubbery.executeAction();
    file.open(shrubbery.getTarget() + "_shrubbery", std::fstream::in);
    while (getline (file, myText))
        std::cout << myText << std::endl;
    file.close();
    cr_assert_stdout_eq_str
    (
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      /   \\\n"
        "     /     \\\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                            RobotomyRequestForm class                      //
///////////////////////////////////////////////////////////////////////////////
Test(RobotomyRequestForm_CTOR,
    TEST_CTOR_correctly_created, .init = redirect_all_stdout)
{
    {
        RobotomyRequestForm   robot("Form");
        
        cr_assert_not_null(&robot);
    }
}

Test(RobotomyRequestForm_getTarget,
    TEST_return_target, .init = redirect_all_stdout)
{
    {
        RobotomyRequestForm   robot("Form");
        
        cr_assert(robot.getTarget() == "Form");
    }
}

Test(RobotomyRequestForm_copy_CTOR, TEST_simple_copy,
    .init = redirect_all_stdout)
{
    RobotomyRequestForm   robot("Form");
    RobotomyRequestForm   copy(robot);

    cr_assert(copy.getTarget() == robot.getTarget());
}

Test(RobotomyRequestForm_assignment_operator,
    TEST_simple_assignement, .init = redirect_all_stdout)
{
    RobotomyRequestForm   robot("Form");
    RobotomyRequestForm   assigned("Form2");

    cr_assert(assigned.getTarget() != robot.getTarget());
    assigned = robot;
    cr_assert(assigned.getTarget() == robot.getTarget());

}

static int mockRandValue = 0;

// Mock de rand()
extern "C" int rand() {
    return mockRandValue;
}

Test(RobotomyRequestForm_executeAction,
    TEST_robotomy_success, .init = redirect_all_stdout)
{
    mockRandValue = 0;
    RobotomyRequestForm robot("Form");
    robot.executeAction();
    cr_assert_stdout_eq_str("Form has been robotomized successfully.\n");
}

Test(RobotomyRequestForm_executeAction,
    TEST_robotomy_failure, .init = redirect_all_stdout)
{
    mockRandValue = 1;
    RobotomyRequestForm robot("Form");
    robot.executeAction();
    cr_assert_stdout_eq_str("Form robotomization failed.\n");
}

///////////////////////////////////////////////////////////////////////////////
//                            PresidentialPardonForm class                   //
///////////////////////////////////////////////////////////////////////////////
Test(PresidentialPardonForm_CTOR,
    TEST_CTOR_correctly_created, .init = redirect_all_stdout)
{
    {
        PresidentialPardonForm   pres("Form");
        
        cr_assert_not_null(&pres);
    }
}

Test(PresidentialPardonForm_getTarget,
    TEST_return_target, .init = redirect_all_stdout)
{
    {
        PresidentialPardonForm   pres("Form");
        
        cr_assert(pres.getTarget() == "Form");
    }
}

Test(PresidentialPardonForm_copy_CTOR, TEST_simple_copy,
    .init = redirect_all_stdout)
{
    PresidentialPardonForm   pres("Form");
    PresidentialPardonForm   copy(pres);

    cr_assert(copy.getTarget() == pres.getTarget());
}

Test(PresidentialPardonForm_assignment_operator,
    TEST_simple_assignement, .init = redirect_all_stdout)
{
    PresidentialPardonForm   pres("Form");
    PresidentialPardonForm   assigned("Form2");

    cr_assert(assigned.getTarget() != pres.getTarget());
    assigned = pres;
    cr_assert(assigned.getTarget() == pres.getTarget());

}

Test(PresidentialPardonForm_executeAction,
    TEST_execute_the_form_action, .init = redirect_all_stdout)
{
    PresidentialPardonForm pres("Form");
    pres.executeAction();
    cr_assert_stdout_eq_str("Form has been pardoned by Zaphod Beeblebrox.\n");
}

///////////////////////////////////////////////////////////////////////////////
//                            TEST main                                      //
///////////////////////////////////////////////////////////////////////////////
Test(main, Test_main, .init = redirect_all_stdout)
{
	Bureaucrat	            bureaucrat      = Bureaucrat("bureaucrat", 3);
	ShrubberyCreationForm	f1 = ShrubberyCreationForm("A43");
	RobotomyRequestForm		f2 = RobotomyRequestForm("B28");
	PresidentialPardonForm	f3 = PresidentialPardonForm("C57");
	
	bureaucrat.executeForm(f1);
	bureaucrat.signForm(f1);
	bureaucrat.executeForm(f1);

	PresidentialPardonForm	f4 = f3;
	bureaucrat.signForm(f4);
	bureaucrat.executeForm(f4);

	bureaucrat.executeForm(f2);
	bureaucrat.signForm(f2);
	bureaucrat.executeForm(f2);
    cr_assert_stdout_eq_str
    (
        "bureaucrat can't execute form ShrubberyCreationForm because Error: is not signed.\n"
        "bureaucrat signed ShrubberyCreationForm\n"
        "bureaucrat executed form ShrubberyCreationForm\n"
        "bureaucrat signed PresidentialPardonForm\n"
        "C57 has been pardoned by Zaphod Beeblebrox.\n"
        "bureaucrat executed form PresidentialPardonForm\n"
        "bureaucrat can't execute form RobotomyRequestForm because Error: is not signed.\n"
        "bureaucrat signed RobotomyRequestForm\n"
        "B28 has been robotomized successfully.\n"
        "bureaucrat executed form RobotomyRequestForm\n"
    );
}