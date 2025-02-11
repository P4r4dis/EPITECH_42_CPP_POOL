/*
** Phaser.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex09/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Feb 10 9:18:53 PM 2025 Paradis
** Last update Wed Feb 11 5:40:26 PM 2025 Paradis
*/

#ifndef 			__PHASER_HPP__
	# define 		__PHASER_HPP__

    #include "Sounds.hpp"
class	            Phaser
{
    public:
        enum        AmmoType
        {
            REGULAR,
            PLASMA,
            ROCKET
        };

        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser(void);

        int                 getNbAmmos(void) const;
        int                 getMaxAmmo(void) const;
        AmmoType            getType(void) const;
        static int          getEmptyMagazine(void);
        AmmoType            *getMagazine(void) const;

        void                fire(void);

    protected:
    private:
        static const int    Empty;
        int                 _maxAmmo;
        int                 _nbAmmos;
        AmmoType            _type;
        AmmoType            *_magazine;
};

#endif 				/* !__PHASER_HPP___ */
