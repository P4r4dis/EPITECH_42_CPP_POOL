/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex01/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jul 25 7:32:32 PM 2024 Paradis
** Last update Sat Jul 26 3:41:32 PM 2024 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../../include/MyConvertTemp.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(MyConvertTemp, Test_MyConvertTemp_isDefined)
{
    MyConvertTemp   myConvertTemp;
}

Test(MyConvertTemp, Test_MyConvertTemp_myConversionToFahrenheit_isDefined)
{
    MyConvertTemp   myConvertTemp;
    std::string     number;
    
    myConvertTemp.myConversionToFahrenheit(number);
}

Test(MyConvertTemp, Test_MyConvertTemp_myConversionToFahrenheit)
{
    MyConvertTemp   myConvertTemp;
    std::string     number = "-10";
    
    cr_assert(myConvertTemp.myConversionToFahrenheit(number) == "14.000");
}

Test(MyConvertTemp, Test_MyConvertTemp_myConversionToCelsius_isDefined)
{
    MyConvertTemp   myConvertTemp;
    std::string     number;
    
    myConvertTemp.myConversionToCelsius(number);
}

Test(MyConvertTemp, Test_MyConvertTemp_myConversionToCelsius)
{
    MyConvertTemp   myConvertTemp;
    std::string     number = "46.400";
    
    cr_assert(myConvertTemp.myConversionToCelsius(number) == "8.000");
}

// Test(MyConvertTemp, Test_MyConvertTemp_display_isDefined,
//                     .init = redirect_all_stdout)
// {
//     MyConvertTemp   myConvertTemp;
//     std::string     number = "-10";
//     std::string     type = "Fahrenheit";

//     myConvertTemp.display(myConvertTemp.myConversionToFahrenheit(number), type);
// }

// Test(MyConvertTemp, Test_MyConvertTemp_display_Fahrenheit_with_padding_of_16
//                     , .init = redirect_all_stdout)
// {
//     MyConvertTemp   myConvertTemp;
//     std::string     number = "-10";
//     std::string     type = "Fahrenheit";
    
//     myConvertTemp.display(myConvertTemp.myConversionToFahrenheit(number), type);
//     cr_assert_stdout_eq_str(
//         "          14.000      Fahrenheit\n"
//     );
// }