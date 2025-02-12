/*
** Skat.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 3:54:32 PM 2025 Paradis
** Last update Thu Feb 12 5:15:56 PM 2025 Paradis
*/

#ifndef 			__SKAT_HPP__
	# define 		__SKAT_HPP__

#include <string>
#include "KreogCom.hpp"
#include "Phaser.hpp"

#define AMMUNITION 20

class	Skat
{
    public:
        Skat(const std::string &name, int stimPaks, int serial, int x, int y,
            Phaser::AmmoType type);
        ~Skat(void);
        
        int                 &stimPaks(void);
        const std::string   &name(void);
        void                shareStimPaks(int number, int &stock);
        void                addStimPaks(unsigned int number);
        void                addStimPaks(int number);
        void                useStimPaks(void);
        void                status(void);

        int                 getSkatSerial(void) const;
        int                 getSkatX(void) const;
        int                 getSkatY(void) const;
        Phaser::AmmoType    getSkatType(void) const;
        KreogCom            *getPtrKreogCom(void) const;
        Phaser              *getPtrPhaser(void) const;
    protected:
    private:

        const std::string   &_name;
        int                 _stimPaks;
        int                 _serial;
        int                 _x;
        int                 _y;
        Phaser::AmmoType    _type;
        KreogCom            *_KreogCom;
        Phaser              *_Phaser;


};

#endif 				/* !__SKAT_HPP___ */
