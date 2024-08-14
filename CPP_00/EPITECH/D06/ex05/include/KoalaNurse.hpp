/*
** KoalaNurse.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jul 31 4:55:31 PM 2024 Paradis
** Last update Thu Jul 31 4:55:35 PM 2024 Paradis
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

        int             getId(void) const;
        bool            getTimeToWork(void) const;
        
        void            giveDrug(std::string drug, SickKoala *koala);
        void            timeCheck(void);
        std::string     readReport(std::string fileName);
    protected:
    private:
        int             _id;
        bool            _timeToWork;
};

#endif                  /* !__KOALANURSE_HPP__ */
