/*
** Borg.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Sep 24 7:17:49 PM 2024 Paradis
** Last update Thu Oct 2 5:55:04 PM 2024 Paradis
*/

#ifndef 			__BORG_HPP__
	# define 		__BORG_HPP__

    namespace       Borg
    {
        class       Ship;
    }
    
    #include "Federation.hpp"
    #include "WarpSystem.hpp"
    #include "Destination.hpp"

    namespace       Borg
    {
        class	    Ship
        {
            public:
                Ship(int weaponFrequency, short repair = 3);
                ~Ship(void);


                void            setupCore(WarpSystem::Core *coreReactor);
                void            checkCore(void);

                Destination     getLocation(void) const;
                int             getShield(void) const;
                int             getWeaponFrequency(void) const;
                short           getRepair(void) const;

                void            setShield(int shield);
                void            setWeaponFrequency(int weaponFrequency);
                void            setRepair(short repair);
                
                bool            move(int warp, Destination d);
                bool            move(int warp);
                bool            move(Destination d);
                bool            move(void);
                void            fire(Federation::Starfleet::Ship *target);
                void            fire(Federation::Ship *target);
                void            repair(void);
            protected:
            private:
                int                 _side;
                short               _maxWarp;
                WarpSystem::Core    *_coreReactor;
                Destination         _home;
                Destination         _location;
                int                 _shield;
                int                 _weaponFrequency;
                short               _repair;
        };
    }

#endif 				/* !__BORG_HPP___ */
