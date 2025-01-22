/*
** Exam.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jan 21 6:30:03 PM 2025 Paradis
** Last update Thu Jan 22 2:37:07 AM 2025 Paradis
*/

#ifndef 			__EXAM_HPP__
	# define 		__EXAM_HPP__

class	Exam
{
    public:
        Exam(bool *ptr);
        ~Exam(void);

        void        start(int nb_Klingon);
        bool        isCheating(void) const;

        void        (Exam::*kobayashiMaru)(int);
        
        static bool cheat;
    protected:
    private:
};

#endif 				/* !__EXAM_HPP___ */
