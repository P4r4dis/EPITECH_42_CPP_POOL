/*
** Toy.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jul 31 6:21:09 PM 2025 Paradis
** Last update Wed Aug 5 6:52:38 PM 2025 Paradis
*/

#ifndef 			__TOY_HPP__
	# define 		__TOY_HPP__

#include <string>

#include "Picture.hpp"

class	Toy
{
    public:
        enum    ToyType
        {
            BASIC_TOY = 0,
            ALIEN
        };

        Toy(void);
        Toy(ToyType toyType, const std::string &name, const std::string &file);
        Toy(const Toy &toy);
        Toy     &operator=(const Toy &toy);
        virtual ~Toy();

        ToyType         getType(void) const;

        std::string     getName(void) const;
        void            setName(const std::string &name);

        std::string     getAscii(void) const;
        bool            setAscii(const Picture picture);

    protected:
    private:
        ToyType         _type;
        std::string     _name;
        std::string     _fileName;
        Picture         _picture;
};

#endif 				/* !__TOY_HPP__ */
