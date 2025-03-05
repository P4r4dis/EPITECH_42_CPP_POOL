/*
** DroidMemory.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Mar 5 5:33:31 PM 2025 Paradis
** Last update Thu Mar 5 6:50:00 PM 2025 Paradis
*/

#ifndef 			__DROIDMEMORY_HPP__
	# define 		__DROIDMEMORY_HPP__

#include <cstddef>
#include <ostream>
class	DroidMemory
{
    public:
        DroidMemory(void);
        DroidMemory(const DroidMemory &copyCTOR);
        ~DroidMemory(void);

        DroidMemory     &operator=(const DroidMemory &rhs);

        size_t          getFingerPrint(void) const;
        size_t          getExp(void) const;

        void            setFingerPrint(size_t fingerprint);
        void            setExp(size_t exp);

        DroidMemory     &operator+=(const size_t &rhs);
        DroidMemory     &operator+=(const DroidMemory &lhs);
        DroidMemory     &operator<<(const DroidMemory &lhs);
        DroidMemory     &operator>>(DroidMemory &rhs);
        DroidMemory     operator+(const DroidMemory &rhs);
        bool            operator==(const DroidMemory &rhs);
        bool            operator!=(const DroidMemory &rhs);
        bool            operator<(const DroidMemory &rhs);
        bool            operator<=(const DroidMemory &rhs);
        bool            operator>(const DroidMemory &rhs);
        bool            operator>=(const DroidMemory &rhs);
        bool            operator<(const size_t &rhs);
        bool            operator<=(const size_t &rhs);
        bool            operator>(const size_t &rhs);
        bool            operator>=(const size_t &rhs);
    protected:
    private:
        size_t          Fingerprint;
        size_t          Exp;
};

#endif 				/* !__DROIDMEMORY_HPP__ */
std::ostream            &operator<<(std::ostream &os, const DroidMemory &rhs);