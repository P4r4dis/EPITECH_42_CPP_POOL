/*
** Almond.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:05:51 PM 2025 Paradis
** Last update Fri Jun 5 8:55:01 PM 2025 Paradis
*/

#ifndef 			__ALMOND_HPP__
	# define 		__ALMOND_HPP__

#include "ANut.hpp"
class	            Almond :   public ANut
{
    public:
        Almond(void);
        Almond(const std::string& name, unsigned int vitamins, bool peeled = false);
        Almond(const Almond& nut);
        Almond       &operator=(const Almond& nut);
        virtual ~Almond();

        virtual Almond  *clone(void) const;

    protected:
    private:
};

#endif 				/* !__ALMOND_HPP__ */
