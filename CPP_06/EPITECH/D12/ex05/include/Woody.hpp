/*
** Woody.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 8:37:52 PM 2025 Paradis
** Last update Thu Aug 6 8:52:30 PM 2025 Paradis
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
