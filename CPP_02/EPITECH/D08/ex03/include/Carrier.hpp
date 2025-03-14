/*
** Carrier.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex03/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Mar 11 6:26:48 PM 2025 Paradis
** Last update Sat Mar 14 6:21:34 PM 2025 Paradis
*/

#ifndef 			__CARRIER_HPP__
	# define 		__CARRIER_HPP__
    #include <ostream>
#define MAX_SIZE 5
    #include "Droid.hpp"
    #include <string>
    class	        Carrier
    {
        public:
            Carrier(void) = delete;
            Carrier(std::string Id = "");
            ~Carrier(void);

            Carrier         &operator=(const Carrier &carrier) = delete;

            std::string     getId(void) const;
            size_t          getEnergy(void) const;
            size_t          getAttack(void) const;
            size_t          getToughness(void) const;
            size_t          getSpeed(void) const;
            Droid           *getDroids(size_t nb) const;
            size_t          getNbDroid(void);

            void            setId(std::string id);
            void            setEnergy(size_t energy);
            void            setSpeed(size_t Speed);
            void            setDroids(size_t pos, Droid *droid);

            void            updateSpeed(void);

            Carrier         &operator<<(Droid *&droid);
            Carrier         &operator>>(Droid *&droid);
            Droid           *&operator[](size_t index);
            Carrier         &operator~(void);
            bool            operator()(int x, int y);
        protected:
        private:
            std::string     Id;
            size_t          Energy;
            const size_t    Attack;
            const size_t    Toughness;
            size_t          Speed;
            Droid           *Droids[MAX_SIZE];
            size_t          NbDroid;
    };

std::ostream        &operator<<(std::ostream &os, Carrier &carrier);
#endif 				/* !__CARRIER_HPP___ */
