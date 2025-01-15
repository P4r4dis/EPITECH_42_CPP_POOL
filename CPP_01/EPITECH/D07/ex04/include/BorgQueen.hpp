/*
** BorgQueen.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Sat Oct 19 3:25:20 PM 2024 Paradis
** Last update Sun Oct 19 3:38:56 PM 2024 Paradis
*/


#ifndef 			__BorgQueen_HPP__
	# define 		__BorgQueen_HPP__

    namespace       Borg
    {
            class   BorgQueen;
    }
    #include <string>

    #include "Borg.hpp"
    #include "Destination.hpp"

namespace           Borg
{
        class	    BorgQueen
        {
            private:
                std::string     _name;

            public:
                BorgQueen(void);
                ~BorgQueen(void);

                bool (Borg::Ship::*movePtr)(Destination d);
                void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *ptr);
                void (Borg::Ship::*destroyPtr)(Federation::Ship *ptr);

                void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
                void destroy(Borg::Ship *ship, Federation::Ship *target);
                bool move(Borg::Ship *ship, Destination dest);
            protected:

        };
}


#endif 				/* !__BorgQueen_HPP___ */
