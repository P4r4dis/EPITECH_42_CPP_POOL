/*
** KreogCom.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex10/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 12 3:57:24 PM 2025 Paradis
** Last update Sat Feb 14 6:36:02 PM 2025 Paradis
*/

#ifndef 			__KREOGCOM_HPP__
	# define 		__KREOGCOM_HPP__
    
class	            KreogCom
{
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom(void);

        void        addCom(int x, int y, int serial);
        void        addCom(KreogCom *com);
        void        removeCom();
        KreogCom    *getCom(void);

        void        ping();
        void        locateSquad();

        int         getX() const;
        KreogCom    *getNext(void) const;

    protected:
    private:
        const int   m_serial;
        int         _x;
        int         _y;
        KreogCom    *_next;
};

#endif 				/* !__KREOGCOM_HPP__ */
