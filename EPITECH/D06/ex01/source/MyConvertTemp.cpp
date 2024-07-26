/*
** MyConvertTemp.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex01/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jul 25 7:33:48 PM 2024 Paradis
** Last update Sat Jul 26 6:44:23 PM 2024 Paradis
*/

#include <iostream>
#include <sstream>
#include <iomanip>

#include "../include/MyConvertTemp.hpp"

MyConvertTemp::MyConvertTemp(void)
{}

MyConvertTemp::~MyConvertTemp(void)
{}

std::string         MyConvertTemp::myConversionToFahrenheit(std::string number)
{
    float               celsius = 0.0;
    float               result_fahr = 0.0;
    std::stringstream   strStream(number);
    std::ostringstream  outStream;
    
    strStream >> celsius;
    strStream.clear();
    if (!number.empty())
        result_fahr = (9.0 / 5.0) * celsius + 32;
    
    outStream   << std::fixed << std::setprecision(3) << result_fahr;
    return outStream.str();
}

std::string         MyConvertTemp::myConversionToCelsius(std::string number)
{
    float               fahrenheit = 0.0;
    float               result_cel = 0.0;
    std::stringstream   strStream(number);
    std::ostringstream  outStream;
    
    strStream >> fahrenheit;
    strStream.clear();
    if (!number.empty())
        result_cel = (5.0 / 9.0) * (fahrenheit - 32);
    outStream   << std::fixed << std::setprecision(3) << result_cel;
    return outStream.str();
}

void                MyConvertTemp::display(std::string temp, std::string type)
{
    if (type == "Fahrenheit")
    {           
        std::cout   << std::setw(16) << myConversionToCelsius(temp) 
                    << std::setw(16) << "Celsius" << std::endl;
    }
    else if (type == "Celsius")
    {
        std::cout   << std::setw(16) << myConversionToFahrenheit(temp) 
                    << std::setw(16) << "Fahrenheit" << std::endl;
    }
    else
        std::cout   << "You have to enter a number and the Scale (Fahrenheit or Celsius)"
                    << std::endl;
}

void                MyConvertTemp::process(void)
{
    std::string     line;
    std::string     temp;
    std::string     type;
    size_t          pos;

    std::getline(std::cin, line);
    pos = line.find(' ');
    if (pos != std::string::npos)
    {   
        type = line.substr(pos + 1);
        temp = line.erase(pos, pos - line.size());
    }
    display(temp, type);
}