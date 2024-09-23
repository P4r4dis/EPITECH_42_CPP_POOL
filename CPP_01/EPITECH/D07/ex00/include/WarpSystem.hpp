/*
** WarpSystem.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 9:27:43 PM 2024 Paradis
** Last update Tue Sep 23 6:20:11 PM 2024 Paradis
*/

#ifndef 			__WARPSYSTEM_HPP__
	# define 		__WARPSYSTEM_HPP__

namespace       WarpSystem
    {
        class	    QuantumReactor
        {
            public:
                QuantumReactor(void);
                ~QuantumReactor(void);

                bool    isStable(void) const;
                void    setStability(bool stability);

            protected:
            private:
                bool    _stability;
        };

        class       Core
        {
            public:
                Core(QuantumReactor *coreReactor);
                ~Core(void);

                QuantumReactor  *checkReactor(void);
            private:
                QuantumReactor  *_coreReactor;
        };
    }

#endif 				/* !__WARPSYSTEM_HPP___ */
