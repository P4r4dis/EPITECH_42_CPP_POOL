/*
** FruitBox.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed May 28 6:43:49 PM 2025 Paradis
** Last update Wed Jun 3 2:11:12 PM 2025 Paradis
*/

#ifndef 			__FRUITBOX_HPP__
	# define 		__FRUITBOX_HPP__

#include "IFruit.hpp"
class	            FruitBox
{
    public:
        FruitBox(void);
        FruitBox(unsigned int sizeBox);
        FruitBox(const FruitBox& fruitBox) = delete;
        FruitBox    &operator=(const FruitBox& fruitBox) = delete;
        virtual ~FruitBox();

        unsigned int    getSize(void) const;
        unsigned int    nbFruit(void);
        bool            pushFruit(IFruit *fruit);
        IFruit          *popFruit(void);
        IFruit          *getFruit(size_t idx) const;
    protected:
    private:
        unsigned int    _size;
        unsigned int    _nbFruit;
        IFruit          **_fruitBox;
        
};
std::ostream        &operator<<(std::ostream &os, const FruitBox &fruit);
#endif 				/* !__FRUITBOX_HPP__ */
