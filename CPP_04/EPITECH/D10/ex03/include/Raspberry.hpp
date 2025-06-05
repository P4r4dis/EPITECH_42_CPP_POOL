/*
** Raspberry.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:37:00 PM 2025 Paradis
** Last update Wed Jun 3 2:38:07 PM 2025 Paradis
*/

#ifndef 			__RASPBERRY_HPP__
	# define 		__RASPBERRY_HPP__

#include "ABerry.hpp"

class	            Raspberry   :   public ABerry
{
    public:
        Raspberry(void);
        Raspberry(const std::string& name, unsigned int vitamins, bool peeled = true);
        Raspberry(const Raspberry& raspberry) = delete;
        Raspberry       &operator=(const Raspberry& raspberry);
        virtual ~Raspberry();

    protected:
    private:
};

#endif 				/* !__RASPBERRY_HPP__ */
