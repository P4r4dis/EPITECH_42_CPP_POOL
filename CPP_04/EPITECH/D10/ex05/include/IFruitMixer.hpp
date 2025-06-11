/*
** IFruitMixer.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 11 2:45:16 AM 2025 Paradis
** Last update Thu Jun 11 6:39:48 PM 2025 Paradis
*/

#ifndef 			__IFRUITMIXER_HPP__
	# define 		__IFRUITMIXER_HPP__

// #include "FruitMixer.hpp"
#include "FruitBox.hpp"

class SteelBlade;
// class FruitMixer;

class	            IFruitMixer
{
    public:
        virtual ~IFruitMixer(void) {};

        virtual void            setBlade(SteelBlade *blade) = 0;
        virtual unsigned int    mixFruits(FruitBox &box) = 0;
    protected:
    private:
};

class               SteelBlade
{
    public:
        SteelBlade(void) {};
        virtual ~SteelBlade(void) {};
    private:
};
#endif 				/* !__IFRUITMIXER_HPP__ */
