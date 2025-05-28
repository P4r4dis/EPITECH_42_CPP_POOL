/*
** Strawberry.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 5:52:17 PM 2025 Paradis
** Last update Thu May 28 6:17:47 PM 2025 Paradis
*/

#ifndef 			__STRAWBERRY_HPP__
	# define 		__STRAWBERRY_HPP__

#include "ABerry.hpp"

class	            Strawberry   :   public ABerry
{
    public:
        Strawberry(void);
        Strawberry(const std::string& name, unsigned int vitamins, bool peeled = true);
        Strawberry(const Strawberry& strawberry) = delete;
        Strawberry       &operator=(const Strawberry& strawberry);
        virtual ~Strawberry();

    protected:
    private:
};

#endif 				/* !__STRAWBERRY_HPP__ */
