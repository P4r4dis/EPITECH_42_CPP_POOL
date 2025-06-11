/*
** FruitMixer.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 11 2:53:50 AM 2025 Paradis
** Last update Thu Jun 11 8:02:00 PM 2025 Paradis
*/

#ifndef 			__FRUITMIXER_HPP__
	# define 		__FRUITMIXER_HPP__

#include "IFruitMixer.hpp"

class	            FruitMixer  :   public IFruitMixer
{
    public:
        FruitMixer(void);
        FruitMixer(const FruitMixer &fruitMixer) = delete;
        FruitMixer  &operator=(const FruitMixer &fruitMixer) = delete;
        virtual ~FruitMixer();

        unsigned int    mixFruits(FruitBox &box);
        virtual void    setBlade(SteelBlade *blade);
        SteelBlade      *getBlade(void) const;

    protected:
    private:
        SteelBlade  *_blade;
};

#endif 				/* !__FRUITMIXER_HPP__ */
