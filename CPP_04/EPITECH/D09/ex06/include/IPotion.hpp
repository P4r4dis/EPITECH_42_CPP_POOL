/*
** IPotion.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 14 5:04:57 PM 2025 Paradis
** Last update Fri May 15 6:28:42 PM 2025 Paradis
*/

#ifndef __IPOTION_HPP__
#define __IPOTION_HPP__


class	IPotion
{
    public:
        virtual ~IPotion(void) = 0;

        virtual int     getValuePotion(void) const = 0;
        virtual int     getStatusPotion(void) const = 0;
    protected:
    private:
};

#endif 				/* !__IPOTION_HPP___ */
