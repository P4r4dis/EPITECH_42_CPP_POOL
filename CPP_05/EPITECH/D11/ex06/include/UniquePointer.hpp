/*
** UniquePointer.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 8 7:17:04 PM 2025 Paradis
** Last update Thu Jul 9 6:25:06 PM 2025 Paradis
*/

#ifndef 			    __UNIQUEPOINTER_HPP__
	# define 		    __UNIQUEPOINTER_HPP__

#include "IObject.hpp"

class	                UniquePointer   :   public IObject
{
    public:
        UniquePointer(void);
        UniquePointer(IObject *object);
        UniquePointer(const UniquePointer &object) = delete;
        UniquePointer(UniquePointer &&object);
        UniquePointer   &operator=(UniquePointer &&rhs);
        UniquePointer   &operator=(IObject *rhs);
        virtual ~UniquePointer();

        virtual void    touch(void);
        IObject         &operator*(void);
        IObject         *operator->(void);
        void            reset(IObject *ptr = nullptr);
        void            swap(UniquePointer &ptr);
        IObject         *getUniquePointer(void) const;

    protected:
    private:
        IObject         *_uniquePtr;
};

#endif 				/* !_UNIQUEPOINTER_HPP__ */
