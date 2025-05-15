/*
** ICharacter.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 13 5:43:50 PM 2025 Paradis
** Last update Fri May 15 7:20:21 PM 2025 Paradis
*/

#ifndef 			__ICHARACTER_HPP__
	# define 		__ICHARACTER_HPP__

#include <string>
#include "HealthPotion.hpp"
#include "PowerPotion.hpp"
#include "PoisonPotion.hpp"

class	            ICharacter
{
    public:
        virtual     ~ICharacter(void) = 0;

        virtual int                 attack(void) = 0;
        virtual int                 special(void) = 0;
        virtual void                rest(void) = 0;
        virtual void                damage(int damage) = 0;

        virtual const std::string   &getName(void) const = 0;
        virtual void                setName(const std::string &name) = 0;

        virtual int                 getPower(void) const = 0;
        virtual void                setPower(int power) = 0;

        virtual int                 getHp(void) const = 0;
        virtual void                setHp(int hp) = 0;

        virtual void                drink(const IPotion& potion) = 0;
        virtual void                drink(const HealthPotion& potion) = 0;
        virtual void                drink(const PowerPotion& potion) = 0;
        virtual void                drink(const PoisonPotion& potion) = 0;

    protected:
    private:
};

#endif 				/* !__ICHARACTER_HPP___ */
