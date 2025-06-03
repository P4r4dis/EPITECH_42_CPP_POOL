/*
** FruitUtils.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 3:06:56 PM 2025 Paradis
** Last update Wed Jun 3 3:28:28 PM 2025 Paradis
*/

#ifndef 			__FRUITUTILS_HPP__
	# define 		__FRUITUTILS_HPP__

#include "FruitBox.hpp"
class	FruitUtils
{
    public:
        FruitUtils(void);
        FruitUtils(const FruitUtils &fruitUtils) = delete;
        FruitUtils  &operator=(const FruitUtils &fruitUtils) = delete;
        virtual ~FruitUtils();

        static void        sort(FruitBox &unsorted,
                                FruitBox &lemon,
                                FruitBox& citrus,
                                FruitBox &berry);
    protected:
    private:
};

#endif 				/* !__FRUITUTILS_HPP__ */
