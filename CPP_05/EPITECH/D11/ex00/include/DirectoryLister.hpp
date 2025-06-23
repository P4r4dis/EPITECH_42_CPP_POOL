/*
** DirectoryLister.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Mon Jun 23 7:03:58 PM 2025 Paradis
** Last update Tue Jun 23 7:04:03 PM 2025 Paradis
*/

#ifndef 			    __DIRECTORYLISTER_HPP__
	# define 		    __DIRECTORYLISTER_HPP__

#include <string>
class	                DirectoryLister
{
    public:
        DirectoryLister(void);
        DirectoryLister(const std::string& path, bool hidden);
        DirectoryLister(const DirectoryLister &obj) = delete;
        DirectoryLister &operator=(const DirectoryLister &rhs) = delete;
        virtual ~DirectoryLister();

        std::string     getPath(void) const;
        bool            getHidden(void) const;

    protected:
    private:
        std::string     _path;
        bool            _hidden;
};

#endif 				/*  !_DIRECTORYLISTER_HPP__ */
