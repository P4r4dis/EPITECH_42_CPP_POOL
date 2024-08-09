/*
** Hospital.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Aug 9 6:04:18 PM 2024 Paradis
** Last update Sat Aug 9 9:30:22 PM 2024 Paradis
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
        void            addSick(SickKoalaList *sickKoalaList);

    protected:
    private:
        SickKoalaList   *_sickKoalaList;
        KoalaNurseList  *_koalaNurseList;
        KoalaDoctorList *_koalaDoctorList;
};

#endif 				/* !__HOSPITAL_HPP___ */
