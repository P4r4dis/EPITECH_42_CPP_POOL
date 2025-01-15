/*
** BorgQueen.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Sat Oct 19 3:25:20 PM 2024 Paradis
** Last update Thu Jan 15 7:18:35 PM 2025 Paradis
*/


#ifndef 			__BorgQueen_HPP__
	# define 		__BorgQueen_HPP__

    namespace       Borg
    {
            class   BorgQueen;
    }

    #include "Borg.hpp"
    #include "Destination.hpp"

namespace           Borg
{
        class	    BorgQueen
        {
            private:

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
