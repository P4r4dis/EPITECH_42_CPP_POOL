/*
** Grapefruit.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:09:36 PM 2025 Paradis
** Last update Wed Jun 3 2:11:26 PM 2025 Paradis
*/

#ifndef 			__GRAPEFRUIT_HPP__
	# define 		__GRAPEFRUIT_HPP__
#include "ACitrus.hpp"

class	Grapefruit  :   public ACitrus
{
    public:
        Grapefruit(void);
        Grapefruit(const std::string& name, unsigned int vitamins, bool peeled = false);
        Grapefruit(const Grapefruit& grapeFruit) = delete;
        Grapefruit       &operator=(const Grapefruit& grapeFruit);
        virtual ~Grapefruit();

    protected:
    private:
};

#endif 				/* !__GRAPEFRUIT_HPP__ */