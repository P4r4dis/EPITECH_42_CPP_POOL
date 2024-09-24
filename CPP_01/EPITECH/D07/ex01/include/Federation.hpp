/*
** Federation.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 9:12:42 PM 2024 Paradis
** Last update Wed Sep 24 5:29:15 PM 2024 Paradis
*/

#ifndef 			__FEDERATION_HPP__
	# define 		__FEDERATION_HPP__

    #include <string>
    #include "WarpSystem.hpp"
    
    namespace       Federation
    {
        namespace   Starfleet
        {
            class   Ship
            {
                public:
                    Ship(int length, int width, std::string name, short maxWarp);
                    ~Ship(void);

                    void    setupCore(WarpSystem::Core *coreReactor);
                    void    checkCore(void);
                protected:
                private:
                    int                                 _length;
                    int                                 _width;
                    std::string                         _name;
                    short                               _maxWarp;
                    WarpSystem::Core                    *_coreReactor;
            };
        }

        class   Ship
        {
            public:
                Ship(int length, int width, std::string name);
                ~Ship(void);

                short   getMaxWarp(void) const;
                void    setupCore(WarpSystem::Core *coreReactor);
                void    checkCore(void);
            protected:
            private:
                int                                 _length;
                int                                 _width;
                std::string                         _name;
                short                               _maxWarp;
                WarpSystem::Core                    *_coreReactor;
        };
    }

#endif 				/* !__FEDERATION_HPP___ */
