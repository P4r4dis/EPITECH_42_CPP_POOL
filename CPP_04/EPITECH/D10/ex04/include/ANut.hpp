/*
** ANut.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 8:48:37 PM 2025 Paradis
** Last update Thu May 28 6:17:31 PM 2025 Paradis
*/

#ifndef 			__ANUT_HPP__
	# define 		__ANUT_HPP__

#include "AFruit.hpp"
class	            ANut : public AFruit
{
    public:
        ANut(void) = delete;
        ANut(const std::string& name, unsigned int vitamins, bool peeled = false);
        ANut(const ANut& aCitrus) = delete;
        ANut      &operator=(const ANut& aCitrus) = delete;
        virtual ~ANut() {}
    protected:
    private:
};

#endif 				/* !__ANUT_HPP__ */
