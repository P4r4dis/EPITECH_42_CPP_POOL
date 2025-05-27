/*
** AFruit.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 5:16:39 PM 2025 Paradis
** Last update Wed May 27 8:30:54 PM 2025 Paradis
*/

#ifndef 			__AFRUIT_HPP__
	# define 		__AFRUIT_HPP__

#include "IFruit.hpp"
class	            AFruit  :   public IFruit
{
    public:
        AFruit(void) = delete;
        AFruit(const std::string& name, unsigned int vitamins, bool peeled = false);
        AFruit(const AFruit& aFruit) = delete;
        AFruit      &operator=(const AFruit& aFruit) = delete;
        virtual ~AFruit() {}

        virtual unsigned int    getVitamins(void) const;
        virtual std::string     getName(void) const;
        virtual bool            isPeeled(void) const;
        virtual void            peel(void);
    protected:
        unsigned int            _vitamins;
        std::string             _name;
        bool                    _peeled;
    private:
};

#endif 				/* !__AFRUIT_HPP__ */
