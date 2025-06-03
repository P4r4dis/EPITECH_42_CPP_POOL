/*
** BloodOrange.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex02/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jun 3 2:20:46 PM 2025 Paradis
** Last update Wed Jun 3 2:21:59 PM 2025 Paradis
*/

#ifndef 			__BLOODORANGE_HPP__
	# define 		__BLOODORANGE_HPP__
#include "Orange.hpp"
class	BloodOrange :   public Orange
{
    public:
        BloodOrange(void);
        BloodOrange(const std::string& name, unsigned int vitamins, bool peeled = false);
        BloodOrange(const BloodOrange& bloodOrange) = delete;
        BloodOrange       &operator=(const BloodOrange& bloodOrange);
        virtual ~BloodOrange();

    protected:
    private:
};

#endif 				/* !__BLOODORANGE_HPP__ */
