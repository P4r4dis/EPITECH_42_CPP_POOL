/*
** Phaser.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex09/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Feb 10 9:18:53 PM 2025 Paradis
** Last update Tue Feb 10 9:49:39 PM 2025 Paradis
*/

#ifndef 			__PHASER_HPP__
	# define 		__PHASER_HPP__

    #include "Sounds.hpp"
class	            Phaser
{
    public:
        enum        AmmoType
        {
            Regular,
            Plasma,
            Rocket
        };

        Phaser();
        ~Phaser();

    protected:
    private:
};

#endif 				/* !__PHASER_HPP___ */
