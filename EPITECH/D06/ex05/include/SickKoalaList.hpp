/*
** SickKoalaList.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jul 31 4:56:05 PM 2024 Paradis
** Last update Thu Jul 31 10:17:35 PM 2024 Paradis
*/

#include "SickKoala.hpp"

#ifndef 			__SICKKOALALIST_HPP__
	# define 		__SICKKOALALIST_HPP__

class	SickKoalaList
{
    public:
        SickKoalaList(SickKoala *sickKoala);
        ~SickKoalaList(void);

        SickKoala       *getContent(void) const;
        SickKoalaList   *getNext(void) const;
        
        bool            isEnd(void);
        void            append(SickKoalaList *nodeList); // add at the end a node of list
    protected:
    private:
        SickKoala       *_sickKoala; // data
        SickKoalaList   *_next; // ptr on the next node
};

#endif 				/* !__SICKKOALALIST_HPP___ */
