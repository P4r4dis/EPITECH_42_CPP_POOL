/*
** Buzz.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 7 4:55:26 PM 2025 Paradis
** Last update Fri Aug 7 4:55:28 PM 2025 Paradis
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
        virtual bool    speak_es(const std::string &str);
    protected:
    private:
};

#endif 				/* !__BUZZ_HPP__ */
