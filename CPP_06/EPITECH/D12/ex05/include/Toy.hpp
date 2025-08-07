/*
** Toy.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Aug 6 8:37:47 PM 2025 Paradis
** Last update Fri Aug 7 4:18:14 PM 2025 Paradis
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
            ALIEN,
            BUZZ,
            WOODY
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
        bool            setAscii(const std::string &picture);

        virtual bool    speak(const std::string &str);
        virtual bool    speak_es(const std::string &str);

        Toy             &operator<<(const std::string &str);

        class           Error
        {
            public:
                enum    ErrorType
                {
                    UNKNOWN = 0,
                    PICTURE,
                    SPEAK
                };

                Error(void) { type = UNKNOWN; };
                const std::string   what(void);
                const std::string   where(void);

                ErrorType           type;

        };

        Error   getLastError(void) const;
    protected:
    private:
        ToyType         _type;
        std::string     _name;
        std::string     _fileName;
        Picture         _picture;
        Error           _error;
};

std::ostream            &operator<<(std::ostream &os, const Toy &toy);
#endif 				/* !__TOY_HPP__ */
