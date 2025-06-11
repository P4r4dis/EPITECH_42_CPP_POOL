/*
** Strawberry.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 5:52:17 PM 2025 Paradis
** Last update Fri Jun 5 9:17:19 PM 2025 Paradis
*/

#ifndef 			__STRAWBERRY_HPP__
	# define 		__STRAWBERRY_HPP__

#include "ABerry.hpp"

class	            Strawberry   :   public ABerry
{
    public:
        Strawberry(void);
        Strawberry(const std::string& name, unsigned int vitamins, bool peeled = true);
        Strawberry(const Strawberry& strawberry);
        Strawberry       &operator=(const Strawberry& strawberry);
        virtual ~Strawberry();

        virtual Strawberry   *clone(void) const;
    protected:
    private:
};

#endif 				/* !__STRAWBERRY_HPP__ */
