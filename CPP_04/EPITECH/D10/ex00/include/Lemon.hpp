/*
** Lemon.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 9:18:10 PM 2025 Paradis
** Last update Thu May 28 5:39:54 PM 2025 Paradis
*/

#ifndef 			__LEMON_HPP__
	# define 		__LEMON_HPP__

#include "ACitrus.hpp"

class	            Lemon   :   public ACitrus
{
    public:
        Lemon(void);
        Lemon(const std::string& name, unsigned int vitamins, bool peeled = false);
        Lemon(const Lemon& lemon) = delete;
        Lemon       &operator=(const Lemon& lemon);
        virtual ~Lemon();

    protected:
    private:
};

#endif 				/* !__LEMON_HPP___ */
