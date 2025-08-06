/*
** Woody.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 7:34:33 PM 2025 Paradis
** Last update Thu Aug 6 7:34:35 PM 2025 Paradis
*/

#ifndef 			__WOODY_HPP__
	# define 		__WOODY_HPP__

#include "Toy.hpp"
class	            Woody    :   public Toy
{
    public:
        Woody(const std::string &name, const std::string &fileName = "./woody.txt");
        virtual ~Woody(void);

        virtual void    speak(const std::string &str);
        
    protected:
    private:
};
#endif 				/* !__WOODY_HPP___ */
