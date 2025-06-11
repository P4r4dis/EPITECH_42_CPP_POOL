/*
** Orange.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 9:27:33 PM 2025 Paradis
** Last update Fri Jun 5 9:16:48 PM 2025 Paradis
*/

#ifndef 			__ORANGE_HPP__
	# define 		__ORANGE_HPP__

#include "ACitrus.hpp"

class	            Orange   :   public ACitrus
{
    public:
        Orange(void);
        Orange(const std::string& name, unsigned int vitamins, bool peeled = false);
        Orange(const Orange& orange);
        Orange       &operator=(const Orange& orange);
        virtual ~Orange();

        virtual Orange   *clone(void) const;
    protected:
    private:
};

#endif 				/* !__ORANGE_HPP__ */
