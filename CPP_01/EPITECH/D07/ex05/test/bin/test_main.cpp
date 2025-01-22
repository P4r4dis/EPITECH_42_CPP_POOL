/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex05/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jan 21 6:27:18 PM 2025 Paradis
** Last update Thu Jan 22 2:41:39 AM 2025 Paradis
*/


#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Exam.hpp"

bool Exam::cheat = false;


void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Exam, test_Exam_CTOR_isDefined, .init = redirect_all_stdout)
{
    Exam e = Exam(&Exam::cheat);
    cr_assert_not_null(&e);
}

Test(Exam, test_Exam_start_function_isDefined, .init = redirect_all_stdout)
{
    Exam e = Exam(&Exam::cheat);

    e.start(0);
}

Test(Exam, test_Exam_start_function_without_cheat_with_stdout,
    .init = redirect_all_stdout)
{
    Exam e = Exam(&Exam::cheat);
    cr_assert_not_null(&e);

    e.start(3);
    cr_assert_stdout_eq_str
    (
        "[The exam is starting]\n"
        "3 Klingon vessels appeared out of nowhere.\n"
        "they are fully armed and shielded\n"
        "This exam is hard... you lost again.\n"
    );
}

Test(ExamFunctionality, test_assign_KobayashiMaru_Pointer
    , .init = redirect_all_stdout) {
    Exam e = Exam(&Exam::cheat);

    e.kobayashiMaru = &Exam::start;

    cr_assert_not_null(e.kobayashiMaru, "kobayashiMaru pointer should not be null.");
}

Test(ExamFunctionality, test_invoke_KobayashiMaru_Function, .init = redirect_all_stdout) {
    Exam e = Exam(&Exam::cheat);

    e.kobayashiMaru = &Exam::start;

    (e.*e.kobayashiMaru)(3);

    cr_assert_stdout_eq_str(
        "[The exam is starting]\n"
        "3 Klingon vessels appeared out of nowhere.\n"
        "they are fully armed and shielded\n"
        "This exam is hard... you lost again.\n"
    );
}

Test(Exam, test_invoke_KobayashiMaru_Function_With_Cheat
    , .init = redirect_all_stdout) {
    Exam e = Exam(&Exam::cheat);

    e.kobayashiMaru = &Exam::start;
    Exam::cheat = true;

    (e.*e.kobayashiMaru)(4);

    cr_assert_stdout_eq_str(
        "[The exam is starting]\n"
        "4 Klingon vessels appeared out of nowhere.\n"
        "they are fully armed and shielded\n"
        "What the... someone changed the parameters of the exam !\n"
    );

    Exam::cheat = false;
}

Test(Exam, test_isCheating_function_isDefined
    , .init = redirect_all_stdout)
{
    Exam e = Exam(&Exam::cheat);

    e.isCheating();
}

Test(Exam, test_isCheating_function_return_false
    , .init = redirect_all_stdout)
{
    Exam e = Exam(&Exam::cheat);

    cr_assert(e.isCheating() == false);
}

Test(Exam, test_isCheating_function_return_true
    , .init = redirect_all_stdout)
{
    Exam e = Exam(&Exam::cheat);
    Exam::cheat = true;
    cr_assert(e.isCheating() == true);
    Exam::cheat = false;

}
///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////

Test(main, test_main, .init = redirect_all_stdout)
{
    {
        Exam    e = Exam(&Exam::cheat);
        e.kobayashiMaru = &Exam::start;

        (e.*e.kobayashiMaru)(3);
        Exam::cheat = true;
        if (e.isCheating())
            (e.*e.kobayashiMaru)(4);
    }
    cr_assert_stdout_eq_str
    (
        "[The exam is starting]\n"
        "3 Klingon vessels appeared out of nowhere.\n"
        "they are fully armed and shielded\n"
        "This exam is hard... you lost again.\n"
        "[The exam is starting]\n"
        "4 Klingon vessels appeared out of nowhere.\n"
        "they are fully armed and shielded\n"
        "What the... someone changed the parameters of the exam !\n"
    );
}
