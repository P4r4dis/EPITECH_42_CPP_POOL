/*
** KoalaDoctor.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 30 5:58:15 PM 2024 Paradis
** Last update Wed Jul 30 6:08:59 PM 2024 Paradis
*/

#include <string>
#ifndef 			__KOALADOCTOR_HPP__
	# define 		__KOALADOCTOR_HPP__

class	KoalaDoctor
{
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor(void);

        std::string getName(void) const;

    protected:
    private:
    std::string     _name;
};

#endif 				/* !__KOALADOCTOR_HPP___ */
