/*
** UniquePointer.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jun 26 2:19:37 PM 2025 Paradis
** Last update Fri Jun 26 6:25:48 PM 2025 Paradis
*/

#ifndef 			    __UNIQUEPOINTER_HPP__
	# define 		    __UNIQUEPOINTER_HPP__

#include "IObject.hpp"

class	                UniquePointer   :   public IObject
{
    public:
        UniquePointer(void);
        UniquePointer(IObject *object);
        // UniquePointer(const UniquePointer &object) = delete;
        UniquePointer   &operator=(IObject *rhs);
        virtual ~UniquePointer();

        // IObject *getUniquePtr(void) const;
    protected:
    private:
        IObject         *_uniquePtr;
};

#endif 				/* !_UNIQUEPOINTER_HPP__ */
