/*
** SafeDirectoryLister.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex01/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 25 7:42:32 PM 2025 Paradis
** Last update Thu Jun 25 7:44:57 PM 2025 Paradis
*/

#ifndef 			    __SAFEDIRECTORYLISTER_HPP__
	# define 		    __SAFEDIRECTORYLISTER_HPP__

#include <dirent.h>
#include "IDirectoryLister.hpp"

class	                SafeDirectoryLister :   public IDirectoryLister
{
    public:
        SafeDirectoryLister(void);
        SafeDirectoryLister(const std::string& path, bool hidden);
        SafeDirectoryLister(const SafeDirectoryLister &obj) = delete;
        SafeDirectoryLister &operator=(const SafeDirectoryLister &rhs) = delete;
        virtual ~SafeDirectoryLister();

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

#endif 				/*  !_SAFEDIRECTORYLISTER_HPP__ */
