/*
** MyConvertTemp.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jul 25 7:34:27 PM 2024 Paradis
** Last update Sat Jul 26 4:11:46 PM 2024 Paradis
*/



#ifndef         MY_CONVERT_TEMP_HPP
    #define     MY_CONVERT_TEMP_HPP

#include <string>

class           MyConvertTemp 
{
    public:
        MyConvertTemp(void);
        ~MyConvertTemp(void);

        std::string     myConversionToFahrenheit(std::string number);
        std::string     myConversionToCelsius(std::string number);
        void            display(std::string temp, std::string type);
    protected:
    private:
};

#endif          /* !MY_CONVERT_TEMP_HPP */
