/*
** Peasant.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 7 5:26:38 PM 2025 Paradis
** Last update Thu May 14 4:41:38 PM 2025 Paradis
*/

#ifndef 			__PEASANT_HPP__
	# define 		__PEASANT_HPP__

#include <string>
#include "ICharacter.hpp"
class	            Peasant :   public ICharacter // IPotion + ipotion call drink
{
    public:
        Peasant(void);
        Peasant(const std::string &name, int power);
        Peasant(const Peasant &obj);
        Peasant     &operator=(const Peasant &obj);
        virtual ~Peasant(void);

        virtual const std::string   &getName(void) const;
        virtual void                setName(const std::string &name);

        virtual int                 getPower(void) const;
        virtual void                setPower(int power);

        virtual int                 getHp(void) const;
        virtual void                setHp(int hp);

        virtual int                 attack(void);
        virtual int                 special(void);
        virtual void                rest(void);
        virtual void                damage(int damage);
    protected:
        std::string _name;
        int         _power;
        int         _hp;
    private:
};

#endif 				/* !__PEASANT_HPP___ */
