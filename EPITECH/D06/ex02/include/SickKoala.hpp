/*
** SickKoala.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 26 8:00:35 PM 2024 Paradis
** Last update Tue Jul 29 4:43:20 PM 2024 Paradis
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
