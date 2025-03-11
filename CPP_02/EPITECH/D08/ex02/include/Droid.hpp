/*
** Droid.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Mar 5 5:33:43 PM 2025 Paradis
** Last update Wed Mar 11 5:40:57 PM 2025 Paradis
*/


#ifndef 			__DROID_HPP__
	#define 		__DROID_HPP__

#include "DroidMemory.hpp"
#include <string>

#define ID ""
#define ENERGY 50
#define ATTACK 25
#define TOUGHNESS 15
#define STATUS "Standing by"
#define COST 10

class	            Droid
{
    public:
        Droid(void) = delete;
        Droid(std::string Id);
        Droid(const Droid &copyCTOR);
        ~Droid(void);

        Droid           &operator=(const Droid &droid);
        Droid           &operator<<(size_t &rhs);
        bool            operator==(const Droid &droid);
        bool            operator!=(const Droid &droid);
        bool            operator()(const std::string *task, size_t expRequired);

        std::string     getId(void) const;
        size_t          getEnergy(void) const;
        size_t          getAttack(void) const;
        size_t          getToughness(void) const;
        std::string     *getStatus(void) const;
        DroidMemory     *getBattleData(void) const;

        void            setId(std::string id);
        void            setEnergy(size_t energy);
        void            setStatus(std::string *status);
        void            setBattleData(const DroidMemory *battleData);
    protected:
    private:
        std::string     Id;
        size_t          Energy;
        const size_t    Attack;
        const size_t    Toughness;
        std::string     *Status;
        DroidMemory     *BattleData;
};

std::ostream            &operator<<(std::ostream &os, Droid const &rhs);

#endif 				/* !_DROID_HPP___ */
