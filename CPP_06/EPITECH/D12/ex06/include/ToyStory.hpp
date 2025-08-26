/*
** ToyStory.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 7 5:05:06 PM 2025 Paradis
** Last update Sun Aug 23 4:43:11 PM 2025 Paradis
*/

#ifndef 			__TOYSTORY_HPP__
	# define 		__TOYSTORY_HPP__

#include "Toy.hpp"

class	ToyStory
{
    public:
        virtual ~ToyStory(void) {};

        static void         tellMeAStory(const std::string &fileName,
                                    Toy &toy1,
                                    bool (Toy::*func1) (const std::string &),
                                    Toy &toy2,
                                    bool (Toy::*func2) (const std::string &));
                                    
        static void         printToyPictures(Toy &toy1, Toy &toy2);

    protected:
    private:
};

#endif 				/* !__TOYSTORY_HPP__ */
