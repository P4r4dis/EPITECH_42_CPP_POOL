/*
** IDirectoryLister.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 25 6:26:20 PM 2025 Paradis
** Last update Thu Jun 25 6:44:58 PM 2025 Paradis
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

    class                       OpenFailureException : public std::exception
    {
        public:
            virtual             const char *what(void) const throw();
    };

    class                       NoMoreFileException : public std::exception
    {
        public:
            virtual             const char *what(void) const throw();
    };
    protected:
    private:
};

#endif 				        /*  !_IDIRECTORYLISTER_HPP__ */
