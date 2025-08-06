/*
** Buzz.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex03/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 6:53:03 PM 2025 Paradis
** Last update Thu Aug 6 6:54:08 PM 2025 Paradis
*/

#ifndef 			__BUZZ_HPP__
	# define 		__BUZZ_HPP__

#include "Toy.hpp"
class	            Buzz    :   public Toy
{
    public:
        Buzz(const std::string &name, const std::string &fileName = "./buzz.txt");
        virtual ~Buzz();

        virtual void    speak(const std::string &str);
    protected:
    private:
};

#endif 				/* !__BUZZ_HPP__ */
