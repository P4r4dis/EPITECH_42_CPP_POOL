/*
** Droid.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Feb 27 4:59:40 PM 2025 Paradis
** Last update Fri Feb 27 6:32:36 PM 2025 Paradis
*/

#ifndef 			__DROID_HPP__
	#define 		__DROID_HPP__

    #include <cstddef>
#include <string>
    
    #define ID ""
    #define ENERGY 50
    #define ATTACK 25
    #define TOUGHNESS 15
    #define STATUS "Standing by"

class	            Droid
{
    public:
        Droid(void);
        Droid(std::string Id);
        Droid(const Droid &copyCTOR);
        ~Droid(void);

        Droid           &operator=(const Droid &droid);

        std::string     getId(void) const;
        size_t          getEnergy(void) const;
        size_t          getAttack(void) const;
        size_t          getToughness(void) const;
        std::string     *getStatus(void) const;

    protected:
    private:
        std::string     Id;
        size_t          Energy;
        const size_t    Attack;
        const size_t    Toughness;
        std::string     *Status;
};

#endif 				/* !__DROID_HPP___ */
