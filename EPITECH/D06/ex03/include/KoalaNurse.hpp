/*
** KoalaNurse.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex03/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jul 29 6:34:21 PM 2024 Paradis
** Last update Tue Jul 29 7:02:54 PM 2024 Paradis
*/

#include <string>

#ifndef                 __KOALANURSE_HPP__
    #define             __KOALANURSE_HPP__

class   KoalaNurse 
{
    public:
        KoalaNurse(std::string id);
        ~KoalaNurse(void);

        std::string     getId(void) const;

    protected:
    private:
        std::string     _id;
};

#endif                  /* !__KOALANURSE_HPP__ */
