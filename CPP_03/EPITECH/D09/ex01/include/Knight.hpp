/*
** Knight.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 7 5:27:11 PM 2025 Paradis
** Last update Thu May 7 7:34:19 PM 2025 Paradis
*/

#ifndef 			__KNIGHT_HPP__
	# define 		__KNIGHT_HPP__

    #include "Peasant.hpp"
    
class	            Knight  :   public Peasant
{
    public:
        Knight(void);
        Knight(const std::string &name, int power);
        Knight(const Knight &obj);
        Knight      &operator=(const Knight &obj);
        virtual ~Knight(void);

        int         attack(void);

    protected:
    private:
};

#endif 				/* !__KNIGHT_HPP___ */
