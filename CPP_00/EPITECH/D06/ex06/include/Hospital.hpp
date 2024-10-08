/*
** Hospital.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 6:04:18 PM 2024 Paradis
** Last update Tue Aug 12 6:48:58 PM 2024 Paradis
*/

#ifndef 			__HOSPITAL_HPP__
	# define 		__HOSPITAL_HPP__

#include "SickKoalaList.hpp"
#include "KoalaNurseList.hpp"
#include "KoalaDoctorList.hpp"

class	Hospital
{
    public:
        Hospital(void);
        ~Hospital(void);

        SickKoalaList   *getSickKoalaList(void) const;
        KoalaNurseList  *getKoalaNurseList(void) const;
        KoalaDoctorList *getKoalaDoctorList(void) const;
        
        void            addDoctor(KoalaDoctorList *doctorList);
        void            addNurse(KoalaNurseList *koalaNurseList);
        void            addSick(SickKoalaList *sickKoalaList);
        void            run(void);

    protected:
    private:
        SickKoalaList   *_sickKoalaList;
        KoalaNurseList  *_koalaNurseList;
        KoalaDoctorList *_koalaDoctorList;
};

#endif 				/* !__HOSPITAL_HPP___ */
