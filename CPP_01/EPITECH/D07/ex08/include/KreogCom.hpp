/*
** KreogCom.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex08/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Feb 5 3:49:21 PM 2025 Paradis
** Last update Tue Feb 10 6:51:15 PM 2025 Paradis
*/

#ifndef 			__KREOGCOM_HPP__
	# define 		__KREOGCOM_HPP__
    
class	            KreogCom
{
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom(void);

        void        addCom(int x, int y, int serial);
        void        removeCom();
        KreogCom    *getCom(void);

        void        ping();
        // void        locateSquad();
        // void display()
        // {
        //     KreogCom* current = _next;
        //     while (current) {
        //         std::cout << "KreogCom " << current->m_serial << std::endl;
        //         // << " at ("
        //         // << current->_x << ", " << current->_y << ")" << std::endl;
        //         current = current->_next;
        //     }
        // }

        int         getX() const;

// void locateSquad() const {

//     // if (_next) {
//     //     _next->locateSquad();
//     // }
//     // ping();
// ///////////////
//  KreogCom* current = _next;
//     while (current != nullptr) {
//         current->ping();
//         current = current->_next;
//     }
//     // Affiche le KreogCom actuel à la fin
//     ping();
// }
    protected:
    private:
        const int   m_serial;
        int         _x;
        int         _y;
        KreogCom    *_next;
};

#endif 				/* !__KREOGCOM_HPP__ */
