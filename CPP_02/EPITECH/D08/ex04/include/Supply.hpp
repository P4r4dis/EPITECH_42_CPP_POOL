/*
** Supply.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Mar 18 5:48:52 PM 2025 Paradis
** Last update Thu Mar 19 11:17:18 PM 2025 Paradis
*/

#ifndef 			__SUPPLY_HPP__
	# define 		__SUPPLY_HPP__

    #include "Droid.hpp"
#include <cstddef>
#include <ostream>
class	Supply
{
    public:
        enum    Types
        {
            Iron = 1,
            Silicon = 2,
            Wreck = 3
        };

        Supply(Types type, size_t Amount);
        Supply(Types type, size_t Amount, Droid **Wreck);
        ~Supply(void);

        Types           getType(void) const;
        size_t          getAmount(void) const;
        Droid           **getPtrWreck(void) const;
        size_t          getNbDroid(void) const;

                        operator size_t(void) const;
        Droid           *operator*(void);
        Supply          &operator--(void);
        Supply          &operator++(void);

    protected:
    private:
        Types           _type;
        size_t          _amount;
        Droid           **_wreck;
        size_t          _nbDroids;

        Supply(void) = delete;
        Supply(const Supply &supply) = delete;
        Supply          &operator=(const Supply &supply) = delete;

};

std::ostream            &operator<<(std::ostream &os, const Supply &supply);
#endif 				/* !__SUPPLY_HPP___ */
