/*
** Borg.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Sep 24 7:17:49 PM 2024 Paradis
** Last update Thu Sep 25 8:07:48 PM 2024 Paradis
*/

#ifndef 			__BORG_HPP__
	# define 		__BORG_HPP__

    #include "WarpSystem.hpp"
    #include "Destination.hpp"

    namespace       Borg
    {
        class	    Ship
        {
            public:
                Ship(void);
                ~Ship(void);


                void    setupCore(WarpSystem::Core *coreReactor);
                void    checkCore(void);
            protected:
            private:
                int     _side;
                short   _maxWarp;
                WarpSystem::Core *_coreReactor;
                Destination      _home;
                Destination      _location;
        };
    }

#endif 				/* !__BORG_HPP___ */
