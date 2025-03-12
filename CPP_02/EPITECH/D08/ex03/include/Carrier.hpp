/*
** Carrier.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex03/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Mar 11 6:26:48 PM 2025 Paradis
** Last update Thu Mar 12 8:11:07 PM 2025 Paradis
*/

#ifndef 			__CARRIER_HPP__
	# define 		__CARRIER_HPP__
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

            void            setId(std::string id);
            void            setEnergy(size_t energy);
            void            setSpeed(size_t Speed);
            void            setDroids(size_t pos, Droid *droid);

            Carrier         &operator<<(Droid *&droid);
        protected:
        private:
            std::string     Id;
            size_t          Energy;
            const size_t    Attack;
            const size_t    Toughness;
            size_t          Speed;
            Droid           *Droids[MAX_SIZE];
    };

#endif 				/* !__CARRIER_HPP___ */
