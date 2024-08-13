/*
** KoalaDoctorList.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 5:16:16 PM 2024 Paradis
** Last update Wed Aug 13 5:33:37 PM 2024 Paradis
*/


#include "KoalaDoctor.hpp"

#ifndef 			__KOALADOCTORLIST_HPP__
	# define 		__KOALADOCTORLIST_HPP__

class	KoalaDoctorList
{
    public:
        KoalaDoctorList(KoalaDoctor *koalaDoctor);
        ~KoalaDoctorList(void);

        KoalaDoctor         *getContent(void) const;
        KoalaDoctorList     *getNext(void) const;
        KoalaDoctor         *getFromName(std::string koalaDoctorName) const;
                
        bool                isEnd(void);
        void                append(KoalaDoctorList *nodeList);
        KoalaDoctorList     *remove(KoalaDoctorList *nodeList);
        KoalaDoctorList     *removeFromName(std::string koalaDoctorName);
        void                dump(void);
    protected:
    private:
        KoalaDoctor         *_koalaDoctor;
        KoalaDoctorList     *_next;
};

#endif 				/* !__KOALADOCTORLIST_HPP___ */
