/*
** HealthPotion.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 14 4:32:20 PM 2025 Paradis
** Last update Fri May 15 7:17:49 PM 2025 Paradis
*/

#ifndef 			__HEALTHPOTION_HPP__
	# define 		__HEALTHPOTION_HPP__

#include "IPotion.hpp"

#define HEALTH_POTION 1

class	            HealthPotion    :   public IPotion
{
    public:
        HealthPotion(void);
        virtual ~HealthPotion(void);

        virtual int     getValuePotion(void) const;
        virtual int     getStatusPotion(void) const;
    protected:
    private:
        int         _HP;
};

#endif 				/* !__HEALTHPOTION_HPP___ */
