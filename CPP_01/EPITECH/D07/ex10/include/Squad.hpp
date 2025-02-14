/*
** Squad.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 7:50:00 PM 2025 Paradis
** Last update Sat Feb 14 4:47:52 PM 2025 Paradis
*/

#ifndef 			__SQUAD_HPP__
	# define 		__SQUAD_HPP__

    #include "Skat.hpp"

    #define POS_X_INCREMENT 10
    #define POS_Y_INCREMENT 15
class	            Squad
{
    public:
        Squad(int posXBegin = 0, int posYBegin = 0,
            Phaser::AmmoType ammoType = Phaser::ROCKET, int size = 5);
        ~Squad(void);

        int                 getPosXBegin(void) const;
        int                 getPosYBegin(void) const;
        Phaser::AmmoType    getAmmoType(void) const;
        Skat                **getPtrSkat(void) const;
        
        int                 size(void) const;

        void                foreach(int beginIdx,
                                    void (Skat::*actionPtr)(void));
        void                fire(void);
        void                localisation(void);
    protected:
    private:
        int                 _posXBegin;
        int                 _posYBegin;
        Phaser::AmmoType    _ammoType;
        int                 _size;
        Skat                **_Skat;
};

#endif 				/* !__SQUAD_HPP___ */
