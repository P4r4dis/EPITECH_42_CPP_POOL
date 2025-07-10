/*
** IDirectoryLister.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 25 5:36:04 PM 2025 Paradis
** Last update Thu Jun 25 5:46:04 PM 2025 Paradis
*/

#ifndef 			            __IDIRECTORYLISTER_HPP__
	# define 		            __IDIRECTORYLISTER_HPP__

#include <string>
class	                        IDirectoryLister
{
    public:
        virtual ~IDirectoryLister() {};

        virtual std::string     get(void) = 0;
        virtual bool            open(const std::string& path, bool hidden) = 0;
    protected:
    private:
};

#endif 				        /*  !_IDIRECTORYLISTER_HPP__ */
