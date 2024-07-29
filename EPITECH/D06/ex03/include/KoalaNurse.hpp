/*
** KoalaNurse.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:34:21 PM 2024 Paradis
** Last update Tue Jul 29 8:11:30 PM 2024 Paradis
*/

#include <string>

#include "SickKoala.hpp"

#ifndef                 __KOALANURSE_HPP__
    #define             __KOALANURSE_HPP__

class   KoalaNurse 
{
    public:
        KoalaNurse(int id);
        ~KoalaNurse(void);

        int     getId(void) const;
        bool    getTimeToWork(void) const;
        
        void    giveDrug(std::string drug, SickKoala *koala);
        void    timeCheck(void);
    protected:
    private:
        int     _id;
        bool    _timeToWork;
};

#endif                  /* !__KOALANURSE_HPP__ */
