/*
** Phaser.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 3:59:55 PM 2025 Paradis
** Last update Thu Feb 12 3:59:57 PM 2025 Paradis
*/



#ifndef 			__PHASER_HPP__
	# define 		__PHASER_HPP__

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

        int                 getCurrentAmmos(void) const;
        int                 getMaxAmmo(void) const;
        AmmoType            getType(void) const;
        static int          getEmptyMagazine(void);
        AmmoType            *getMagazine(void) const;

        void                fire(void);
        void                ejectClip(void);
        void                changeType(AmmoType type);
        void                reload(void);
        void                addAmmo(AmmoType type);

    protected:
    private:
        static const int    Empty;
        int                 _maxAmmo;
        int                 _nbAmmos;
        AmmoType            _type;
        AmmoType            *_magazine;
};

#endif 				/* !__PHASER_HPP___ */
