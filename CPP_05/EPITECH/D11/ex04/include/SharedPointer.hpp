/*
** SharedPointer.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 1 4:03:57 PM 2025 Paradis
** Last update Wed Jul 1 6:47:18 PM 2025 Paradis
*/

#ifndef 			    __SHAREDPOINTER_HPP__
	# define 		    __SHAREDPOINTER_HPP__

#include "IObject.hpp"

class	                SharedPointer   :   public IObject
{
    public:
        SharedPointer(void);
        SharedPointer(IObject *object);
        SharedPointer(const SharedPointer &object);
        SharedPointer   &operator=(const SharedPointer &rhs);
        SharedPointer   &operator=(IObject *rhs);
        virtual ~SharedPointer();

        virtual void    touch(void);
        IObject         &operator*(void);
        IObject         *operator->(void);
        void            reset(IObject *ptr = nullptr);
        void            swap(SharedPointer &ptr);
        size_t          use_count(void);

    protected:
    private:
        IObject         *_sharedPtr;
        size_t          *_count;
};

#endif 				/* !_SHAREDPOINTER_HPP__ */
