/*
** KoalaBot.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex07/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Feb 4 3:40:13 PM 2025 Paradis
** Last update Wed Feb 4 6:32:55 PM 2025 Paradis
*/

#ifndef 			__KOALABOT_HPP__
	# define 		__KOALABOT_HPP__

#include <string>
#include "Parts.hpp"

class	            KoalaBot
{
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();

        std::string getSerial(void) const;
        Arms        *getArms(void) const;
        Legs        *getLegs(void) const;
        Head        *getHead(void) const;

        void        setParts(Arms &arms);
        void        setParts(Legs &legs);
        void        setParts(Head &head);

        void        swapParts(Arms &arms);
        void        swapParts(Legs &legs);
        void        swapParts(Head &head);
    protected:
    private:
        std::string _serial;
        Arms        *_arms;
        Legs        *_legs;
        Head        *_head;
};

#endif 				/* !__KOALABOT_HPP___ */
