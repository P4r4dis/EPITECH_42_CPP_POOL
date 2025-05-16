/*
** Enchanter.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon May 12 6:06:59 PM 2025 Paradis
** Last update Wed May 13 6:36:59 PM 2025 Paradis
*/

#ifndef 			__ENCHANTER_HPP__
	# define 		__ENCHANTER_HPP__

    #include "Peasant.hpp"
    
class	            Enchanter   :   virtual public Peasant
{
    public:
        Enchanter(void);
        Enchanter(const std::string &name, int power);
        Enchanter(const Enchanter &obj);
        Enchanter   &operator=(const Enchanter &obj);
        virtual ~Enchanter();

        int         attack(void);
        int         special(void);
        void        rest(void);

    protected:
    private:
};

#endif 				/* !__ENCHANTER_HPP___ */
