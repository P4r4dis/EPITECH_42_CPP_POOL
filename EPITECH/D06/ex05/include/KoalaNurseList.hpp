/*
** KoalaNurseList.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 8 9:18:20 PM 2024 Paradis
** Last update Wed Aug 13 5:29:58 PM 2024 Paradis
*/



#include "KoalaNurse.hpp"

#ifndef 			__KOALANURSELIST_HPP__
	# define 		__KOALANURSELIST_HPP__

class	KoalaNurseList
{
    public:
        KoalaNurseList(KoalaNurse *koalaNurse);
        ~KoalaNurseList(void);

        KoalaNurse         *getContent(void) const;
        KoalaNurseList     *getNext(void) const;
        KoalaNurse         *getFromID(int koalaNurseID) const;
                
        bool                isEnd(void);
        void                append(KoalaNurseList *nodeList);
        KoalaNurseList     *remove(KoalaNurseList *nodeList);
        KoalaNurseList     *removeFromID(int koalaNurseID);
        void                dump(void);
    protected:
    private:
        KoalaNurse         *_koalaNurse;
        KoalaNurseList     *_next;
};

#endif 				/* !__KOALANURSELIST_HPP___ */
