/*
** List.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 1 7:23:56 PM 2025 Paradis
** Last update Thu Jul 2 4:42:27 PM 2025 Paradis
*/

#ifndef 		        __LIST_HPP__
	# define 	        __LIST_HPP__

#include "IObject.hpp"
#include <exception>

class	                List
{
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

        class           Iterator
        {
            public:
                Iterator(Node *node = nullptr);
                virtual ~Iterator(void);
                IObject     *operator*(void) const;
                Iterator    &operator++(void);
                bool        operator==(const Iterator &it) const;
                // bool        operator!=(const Iterator *it) const;

                class   OutOfRangeException  :   public std::exception
                {
                    public:
                        const char *what(void) const throw()
                        {
                            return "Iterator out of range";
                        };
                };
            private:
                Node    *_currentNode;
        };
        
        List::Iterator  begin(void) const;
        List::Iterator  end(void) const;

    protected:
};

#endif 				/*  !_LIST_HPP__ */
