/*
** DirectoryLister.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 25 6:26:10 PM 2025 Paradis
** Last update Thu Jun 25 6:26:14 PM 2025 Paradis
*/

#ifndef 			    __DIRECTORYLISTER_HPP__
	# define 		    __DIRECTORYLISTER_HPP__

#include <dirent.h>
#include "IDirectoryLister.hpp"

class	                DirectoryLister :   public IDirectoryLister
{
    public:
        DirectoryLister(void);
        DirectoryLister(const std::string& path, bool hidden);
        DirectoryLister(const DirectoryLister &obj) = delete;
        DirectoryLister &operator=(const DirectoryLister &rhs) = delete;
        virtual ~DirectoryLister();

        std::string     getPath(void) const;
        bool            getHidden(void) const;
        std::string     getElemOfListByIndex(size_t idx) const;
        size_t          getSize(void) const;
        size_t          getIndex(void) const;
        size_t          getCapacity(void) const;

        std::string     get(void);
        bool            open(const std::string& path, bool hidden);
        void            clean(void);
        void            resize(void);
    protected:
    private:
        std::string     _path;
        bool            _hidden;
        std::string     **_list;
        size_t          _size;
        size_t          _index;   
        size_t          _capacity;    
        struct dirent   *_entry;                                        
};

#endif 				/*  !_DIRECTORYLISTER_HPP__ */
