/*
** Coconut.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:45:21 PM 2025 Paradis
** Last update Fri Jun 5 9:14:58 PM 2025 Paradis
*/



#ifndef 			__COCONUT_HPP__
	# define 		__COCONUT_HPP__

#include "ANut.hpp"
class	            Coconut :   public ANut
{
    public:
        Coconut(void);
        Coconut(const std::string& name, unsigned int vitamins, bool peeled = false);
        Coconut(const Coconut& coconut);
        Coconut       &operator=(const Coconut& coconut);
        virtual ~Coconut();

        virtual Coconut  *clone(void) const;
    protected:
    private:
};

#endif 				/* !__COCONUT_HPP__ */
