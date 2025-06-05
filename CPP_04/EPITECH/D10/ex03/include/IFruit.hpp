/*
** IFruit.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue May 27 3:50:36 PM 2025 Paradis
** Last update Thu May 28 6:17:36 PM 2025 Paradis
*/

#ifndef 			__IFRUIT_HPP__
	# define 		__IFRUIT_HPP__

#include <string>
#include <ostream>

class	            IFruit
{
    public:
        virtual ~IFruit() {}

        virtual unsigned int    getVitamins(void) const = 0;
        virtual std::string     getName(void) const = 0;
        virtual bool            isPeeled(void) const = 0;
        virtual void            peel(void) = 0;

    protected:
    private:
};

std::ostream        &operator<<(std::ostream &os, const IFruit &fruit);
#endif 				/* !__IFRUIT_HPP__ */
