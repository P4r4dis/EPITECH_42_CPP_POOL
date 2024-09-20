/*
** Federation.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 9:12:42 PM 2024 Paradis
** Last update Sat Sep 20 9:13:36 PM 2024 Paradis
*/

#ifndef 			__FEDERATION_HPP__
	# define 		__FEDERATION_HPP__

    #include <string>
    namespace       Federation
    {
        namespace   Starfleet
        {
            class   Ship
            {
                public:
                    Ship(int length, int width, std::string name, short maxWarp);
                    ~Ship(void);

                protected:
                private:
                    int         _length;
                    int         _width;
                    std::string _name;
                    short       _maxWarp;
            };
        }
    }

#endif 				/* !__FEDERATION_HPP___ */
