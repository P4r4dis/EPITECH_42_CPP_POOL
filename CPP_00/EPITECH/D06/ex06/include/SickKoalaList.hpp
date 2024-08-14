/*
** SickKoalaList.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 5:25:27 PM 2024 Paradis
** Last update Wed Aug 13 5:33:56 PM 2024 Paradis
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
        SickKoala       *getFromName(std::string sickKoalaName) const;
                
        bool            isEnd(void);
        void            append(SickKoalaList *nodeList);
        SickKoalaList   *remove(SickKoalaList *nodeList);
        SickKoalaList   *removeFromName(std::string sickKoalaName);
        void            dump(void);
    protected:
    private:
        SickKoala       *_sickKoala;
        SickKoalaList   *_next;
};

#endif 				/* !__SICKKOALALIST_HPP___ */
