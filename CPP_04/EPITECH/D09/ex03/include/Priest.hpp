/*
** Priest.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex03/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 7:02:15 PM 2025 Paradis
** Last update Tue May 12 7:08:48 PM 2025 Paradis
*/

#ifndef 			__PRIEST_HPP__
	# define 		__PRIEST_HPP__

    #include "Enchanter.hpp"
    #include <string>

class	            Priest  :   public Enchanter
{
    public:
        Priest(void);
        Priest(const std::string &name, int power);
        Priest(const Priest &obj);
        Priest      &operator=(const Priest &obj);
        ~Priest();

        void        rest(void);

    protected:
    private:
};

#endif 				/* !__PRIEST_HPP___ */
