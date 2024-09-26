/*
** Federation.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 9:12:42 PM 2024 Paradis
** Last update Fri Sep 26 7:54:55 PM 2024 Paradis
*/

#ifndef 			__FEDERATION_HPP__
	# define 		__FEDERATION_HPP__

    #include <string>
    #include "WarpSystem.hpp"
    #include "Destination.hpp"
    
    namespace Federation
    {
        namespace Starfleet
        {
            class Ship;
            class Captain;
            class Ensign;
        }

        class Ship;
    }
    
    namespace       Federation
    {
        namespace   Starfleet
        {
            class   Ship
            {
                public:
                    Ship(int length = 289, int width = 132, std::string name = "Kreog", short maxWarp = 6, int torpedo = 0);
                    ~Ship(void);

                    void        setupCore(WarpSystem::Core *coreReactor);
                    void        checkCore(void);
                    void        promote(Federation::Starfleet::Captain *captain);
                    
                    std::string getName(void) const;
                    Destination getLocation(void) const;
                    short       getMaxWarp(void) const;
                    int         getShield(void) const;
                    int         getTorpedo(void) const;

                    void        setShield(int shield);
                    void        setTorpedo(int torpedo);
                    
                    bool        move(int warp, Destination d);
                    bool        move(int warp);
                    bool        move(Destination d);
                    bool        move(void);
                protected:
                private:
                    int                                 _length;
                    int                                 _width;
                    std::string                         _name;
                    short                               _maxWarp;
                    WarpSystem::Core                    *_coreReactor;
                    Federation::Starfleet::Captain      *_captain;
                    Destination                         _home;
                    Destination                         _location;
                    int                                 _shield;
                    int                                 _photonTorpedo;

            };

            class   Captain
            {
                public:
                    Captain(std::string name);
                    ~Captain(void);

                    std::string     getName(void) const;
                    int             getAge(void) const;
                    void            setAge(int age);
                private:
                    std::string     _name;
                    int             _age;
            };

            class   Ensign
            {
                public:
                    explicit Ensign(std::string name);
                    ~Ensign(void);
                private:
                    std::string _name;
            };
        }

        class   Ship
        {
            public:
                Ship(int length, int width, std::string name);
                ~Ship(void);

                short               getMaxWarp(void) const;
                void                setupCore(WarpSystem::Core *coreReactor);
                void                checkCore(void);
                WarpSystem::Core    *getCore(void) const;
                Destination         getLocation(void) const;
                
                bool                move(int warp, Destination d);
                bool                move(int warp);
                bool                move(Destination d);
                bool                move(void);
            protected:
            private:
                int                                 _length;
                int                                 _width;
                std::string                         _name;
                short                               _maxWarp;
                WarpSystem::Core                    *_coreReactor;
                Destination                         _home;
                Destination                         _location;
        };
    }

#endif 				/* !__FEDERATION_HPP___ */
