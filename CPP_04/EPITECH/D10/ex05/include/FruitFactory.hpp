/*
** FruitFactory.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jun 6 4:15:37 PM 2025 Paradis
** Last update Thu Jun 11 2:09:47 AM 2025 Paradis
*/

#ifndef 			__FRUITFACTORY_HPP__
	# define 		__FRUITFACTORY_HPP__

#include "IFruit.hpp"
#include <cstddef>
class	            FruitFactory
{
    public:
        FruitFactory(void);
        FruitFactory(IFruit *fruit);
        FruitFactory(const FruitFactory &factory);
        FruitFactory    &operator=(const FruitFactory &factory);
        virtual ~FruitFactory();

        void        registerFruit(IFruit *fruit);
        void        unregisterFruit(const std::string &name);
        IFruit      *createFruit(const std::string &name) const;
        void        display(void) const;
    protected:
    private:
        size_t      _nbFruit;
        IFruit      **_save;
};

#endif 				/* !__FRUITFACTORY_HPP___ */
