/*
** Paladin.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 7:42:00 PM 2025 Paradis
** Last update Wed May 13 6:35:21 PM 2025 Paradis
*/

#ifndef 			__PALADIN_HPP__
	# define 		__PALADIN_HPP__

    #include "Knight.hpp"
    #include "Priest.hpp"
    
class	            Paladin :   public Knight, public Priest
{
    public:
        Paladin(void);
        Paladin(const std::string &name, int power);
        Paladin(const Paladin &obj);
        Paladin      &operator=(const Paladin &obj);
        virtual ~Paladin(void);

        int         attack(void);
        int         special(void);
        void        rest(void);

    protected:
    private:
};

#endif 				/* !__PALADIN_HPP___ */
