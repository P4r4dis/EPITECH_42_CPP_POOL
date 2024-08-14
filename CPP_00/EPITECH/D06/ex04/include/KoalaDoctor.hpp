/*
** KoalaDoctor.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 30 5:58:15 PM 2024 Paradis
** Last update Wed Aug 13 5:29:13 PM 2024 Paradis
*/

#include <string>

#include "SickKoala.hpp"
#ifndef 			__KOALADOCTOR_HPP__
	# define 		__KOALADOCTOR_HPP__

class	KoalaDoctor
{
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor(void);

        std::string     getName(void) const;
        bool            getTimeCheck(void) const;

        void            timeCheck(void);
        void            diagnose(SickKoala *patient);

    protected:
    private:
        std::string     _name;
        bool            _timeCheck;
};

#endif 				/* !__KOALADOCTOR_HPP___ */
