/*
** KreogCom.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex08/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 5 3:49:21 PM 2025 Paradis
** Last update Thu Feb 5 5:36:20 PM 2025 Paradis
*/

#ifndef 			__KREOGCOM_HPP__
	# define 		__KREOGCOM_HPP__
#include <iostream>
class	            KreogCom
{
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom(void);

        void        addCom(int x, int y, int serial);
        // void        removeCom();
        // KreogCom    *getCom();

        // void        ping();
        // void        locateSquad();
        void display()
        {
            KreogCom* current = this;
            while (current) {
                std::cout << "KreogCom " << current->m_serial << " at ("
                << current->_x << ", " << current->_y << ")" << std::endl;
                current = current->_next;
            }
        }

    protected:
    private:
        const int   m_serial;
        int         _x;
        int         _y;
        KreogCom    *_next;
};

#endif 				/* !__KREOGCOM_HPP__ */
