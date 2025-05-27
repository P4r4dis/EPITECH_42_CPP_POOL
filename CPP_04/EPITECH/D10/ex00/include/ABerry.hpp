/*
** ABerry.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 6:02:00 PM 2025 Paradis
** Last update Wed May 27 8:34:01 PM 2025 Paradis
*/

#ifndef 			__ABERRY_HPP__
	# define 		__ABERRY_HPP__
#include "AFruit.hpp"
class	            ABerry : public AFruit
{
    public:
        ABerry(void) = delete;
        ABerry(const std::string& name, unsigned int vitamins, bool peeled = true);
        ABerry(const ABerry& aBerry) = delete;
        ABerry      &operator=(const ABerry& aBerry) = delete;
        virtual ~ABerry() {}

        virtual void peel() {}
    protected:
    private:
};

#endif 				/* !__ABERRY_HPP__ */
