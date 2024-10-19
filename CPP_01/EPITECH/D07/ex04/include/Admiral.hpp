/*
** Admiral.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex03/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Oct 3 3:27:07 PM 2024 Paradis
** Last update Sun Oct 19 2:36:38 PM 2024 Paradis
*/



#ifndef 			__ADMIRAL_HPP__
	# define 		__ADMIRAL_HPP__

    namespace       Federation
    {
        namespace   Starfleet
        {
            class   Admiral;
        }
    }
    #include <string>

    #include "Federation.hpp"
    #include "Destination.hpp"

namespace           Federation
{
    namespace       Starfleet
    {
        class	    Admiral
        {
            private:
                std::string     _name;

            public:
                Admiral(std::string name);
                ~Admiral(void);

                bool (Federation::Starfleet::Ship::*movePtr)(Destination d);
                void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *ptr);

                void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
                bool move(Federation::Starfleet::Ship *ship, Destination dest);
            protected:

        };
    }
}


#endif 				/* !__ADMIRAL_HPP___ */
