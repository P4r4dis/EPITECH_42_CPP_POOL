/*
** Buzz.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 8:37:35 PM 2025 Paradis
** Last update Thu Aug 6 8:52:11 PM 2025 Paradis
*/

#ifndef 			__BUZZ_HPP__
	# define 		__BUZZ_HPP__

#include "Toy.hpp"
class	            Buzz    :   public Toy
{
    public:
        Buzz(const std::string &name, const std::string &fileName = "./buzz.txt");
        virtual ~Buzz();

        virtual bool    speak(const std::string &str);
    protected:
    private:
};

#endif 				/* !__BUZZ_HPP__ */
