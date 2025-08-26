/*
** Woody.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 7 4:55:43 PM 2025 Paradis
** Last update Fri Aug 7 4:55:45 PM 2025 Paradis
*/

#ifndef 			__WOODY_HPP__
	# define 		__WOODY_HPP__

#include "Toy.hpp"
class	            Woody    :   public Toy
{
    public:
        Woody(const std::string &name, const std::string &fileName = "./woody.txt");
        virtual ~Woody(void);

        virtual bool    speak(const std::string &str);
    protected:
    private:
};
#endif 				/* !__WOODY_HPP___ */
