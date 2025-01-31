/*
** Skat.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:22:42 PM 2025 Paradis
** Last update Fri Jan 30 7:46:39 PM 2025 Paradis
*/


#ifndef 			__SKAT_HPP__
	# define 		__SKAT_HPP__

#include <string>

class	Skat
{
    public:
        Skat(const std::string &name = "Bob", int stimPaks = 15);
        ~Skat(void);
        
        int                 &stimPaks(void);
        const std::string   &name(void);
        void                shareStimPaks(int number, int stock);
        void                addStimPaks(unsigned int number);
        void                useStimPaks(void);
        void                status();
    protected:
    private:

        const std::string   &_name;
        int                 _stimPaks;
        int                 _number;
        int                 _stock;

};

#endif 				/* !__SKAT_HPP___ */
