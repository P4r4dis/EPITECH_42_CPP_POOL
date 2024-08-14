/*
** SickKoala.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 5:25:17 PM 2024 Paradis
** Last update Sat Aug 9 5:25:19 PM 2024 Paradis
*/



#ifndef         SICKKOALA_HPP
    #define     SICKKOALA_HPP

#include <string>

class           SickKoala 
{
    public:
        SickKoala(std::string name);
        ~SickKoala(void);

        std::string         getName(void) const;

        void                poke(void);
        bool                takeDrug(std::string drug);
        void                overDrive(std::string str);

    protected:
    private:
        std::string         _name;
};

#endif          /* !SICKKOALA_HPP */
