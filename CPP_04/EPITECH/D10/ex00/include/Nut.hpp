/*
** Nut.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:05:51 PM 2025 Paradis
** Last update Thu May 28 6:07:11 PM 2025 Paradis
*/

#ifndef 			__NUT_HPP__
	# define 		__NUT_HPP__

#include "ANut.hpp"
class	            Nut :   public ANut
{
    public:
        Nut(void);
        Nut(const std::string& name, unsigned int vitamins, bool peeled = false);
        Nut(const Nut& nut) = delete;
        Nut       &operator=(const Nut& nut);
        virtual ~Nut();

    protected:
    private:
};

#endif 				/* !__NUT_HPP__ */
