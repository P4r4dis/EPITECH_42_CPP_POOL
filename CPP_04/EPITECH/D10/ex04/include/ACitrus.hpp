/*
** ACitrus.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 8:48:37 PM 2025 Paradis
** Last update Thu May 28 6:17:23 PM 2025 Paradis
*/

#ifndef 			__ACITRUS_HPP__
	# define 		__ACITRUS_HPP__

#include "AFruit.hpp"
class	            ACitrus : public AFruit
{
    public:
        ACitrus(void) = delete;
        ACitrus(const std::string& name, unsigned int vitamins, bool peeled = false);
        ACitrus(const ACitrus& aCitrus) = delete;
        ACitrus      &operator=(const ACitrus& aCitrus) = delete;
        virtual ~ACitrus() {}
    protected:
    private:
};

#endif 				/* !__ACITRUS_HPP__ */
