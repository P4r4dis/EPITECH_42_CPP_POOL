/*
** PoisonPotion.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 14 5:50:48 PM 2025 Paradis
** Last update Fri May 15 7:48:16 PM 2025 Paradis
*/

#ifndef 			__POISONPOTION_HPP__
	# define 		__POISONPOTION_HPP__

    #include "IPotion.hpp"
    #define POISON_POTION 3
class	            PoisonPotion    :   public IPotion
{
    public:
        PoisonPotion(void);
        virtual ~PoisonPotion(void);

        virtual int         getValuePotion(void) const;
        virtual int         getStatusPotion(void) const;

    protected:
    private:
        int         _poison;
};

#endif 				/* !__POISONPOTION_HPP___ */
