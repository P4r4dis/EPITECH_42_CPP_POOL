/*
** Droid.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Mar 3 4:54:59 PM 2025 Paradis
** Last update Tue Mar 3 5:13:06 PM 2025 Paradis
*/


#ifndef 			__DROID_HPP__
	#define 		__DROID_HPP__

#include <string>

#define ID ""
#define ENERGY 50
#define ATTACK 25
#define TOUGHNESS 15
#define STATUS "Standing by"

class	            Droid
{
    public:
        Droid(void) = delete;
        Droid(std::string Id);
        Droid(const Droid &copyCTOR);
        ~Droid(void);

        Droid           &operator=(const Droid &droid);
        Droid           &operator<<(size_t &rhs);
        bool           operator==(const Droid &droid);
        bool           operator!=(const Droid &droid);

        std::string     getId(void) const;
        size_t          getEnergy(void) const;
        size_t          getAttack(void) const;
        size_t          getToughness(void) const;
        std::string     *getStatus(void) const;

        void            setId(std::string id);
        void            setEnergy(size_t energy);
        void            setStatus(std::string *status);



    protected:
    private:
        std::string     Id;
        size_t          Energy;
        const size_t    Attack;
        const size_t    Toughness;
        std::string     *Status;
};

std::ostream            &operator<<(std::ostream &os, Droid const &rhs);

#endif 				/* !_DROID_HPP___ */
