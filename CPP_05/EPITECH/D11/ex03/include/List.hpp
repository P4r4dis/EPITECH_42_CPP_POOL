/*
** List.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex03/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jun 27 6:34:16 PM 2025 Paradis
** Last update Wed Jul 1 3:29:24 PM 2025 Paradis
*/

#ifndef 		        __LIST_HPP__
	# define 	        __LIST_HPP__

#include "IObject.hpp"
#include <exception>

class	                List
{
    public:
        List(void);
        List(const List &list) = delete;
        List            &operator=(const List &rhs) = delete;
        virtual ~List(void);

        void            display(void);

        bool            empty(void) const;
        size_t          size(void) const;
        IObject         *&front(void);
        IObject         *front(void) const;
        IObject         *&back(void);
        IObject         *back(void) const;
        void            pushBack(IObject *element);
        void            pushFront(IObject *element);
        void            popFront(void);
        void            popBack(void);
        void            clear(void);
        void            forEach(void (*function)(IObject *));

        class           InvalidOperationException : public std::exception
        {
            public:
                virtual const char *what(void) const throw()
                {
                    return ("Invalid operation on a list");
                };
        };
        
    protected:
    private:
        class           Node
        {
            public:
                Node(IObject *obj) : element(obj), next(nullptr)
                {};

                IObject *element;
                Node    *next;
        };

        Node    *_head;
        size_t  _size;
};

#endif 				/*  !_LIST_HPP__ */
