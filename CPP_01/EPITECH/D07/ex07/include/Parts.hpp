/*
** Parts.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex07/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Feb 4 1:31:20 PM 2025 Paradis
** Last update Wed Feb 4 2:13:16 PM 2025 Paradis
*/


#ifndef 			__Parts_HPP__
	# define 		__Parts_HPP__

#include <string>

class	Arms
{
    public:
        Arms(std::string serial = "A-01", bool functionnal = true);
        ~Arms(void);

        bool            isFunctionnal(void) const;
        std::string     serial(void) const;
        
    protected:
    private:
        std::string     _serial;
        bool            _functionnal;
};

#endif 				/* !__Parts_HPP__ */
