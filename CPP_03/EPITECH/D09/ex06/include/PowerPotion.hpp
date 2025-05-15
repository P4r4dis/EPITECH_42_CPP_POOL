/*
** PowerPotion.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 14 5:48:57 PM 2025 Paradis
** Last update Fri May 15 7:48:59 PM 2025 Paradis
*/

#ifndef 			__POWERPOTION_HPP__
	# define 		__POWERPOTION_HPP__

#define POWER_POTION 2
#include "IPotion.hpp"
class	            PowerPotion :   public IPotion
{
    public:
        PowerPotion(void);
        virtual ~PowerPotion(void);

        virtual int         getValuePotion(void) const;
        virtual int         getStatusPotion(void) const;

    protected:
    private:
        int         _PP;
};

#endif 				/* !__POWERPOTION_HPP___ */
