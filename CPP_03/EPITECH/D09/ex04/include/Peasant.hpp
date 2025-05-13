/*
** Peasant.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 7 5:26:38 PM 2025 Paradis
** Last update Thu May 7 6:28:00 PM 2025 Paradis
*/

#ifndef 			__PEASANT_HPP__
	# define 		__PEASANT_HPP__

#include <string>

class	            Peasant
{
    public:
        Peasant(void);
        Peasant(const std::string &name, int power);
        Peasant(const Peasant &obj);
        Peasant     &operator=(const Peasant &obj);
        virtual ~Peasant(void);

        const std::string   &getName(void) const;
        void                setName(const std::string &name);

        int                 getPower(void) const;
        void                setPower(int power);

        int                 getHp(void) const;
        void                setHp(int hp);

        int                 attack(void);
        int                 special(void);
        void                rest(void);
        void                damage(int damage);
    protected:
        std::string _name;
        int         _power;
        int         _hp;
    private:
};

#endif 				/* !__PEASANT_HPP___ */
