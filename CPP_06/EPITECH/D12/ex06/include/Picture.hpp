/*
** Picture.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex06/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 7 4:55:31 PM 2025 Paradis
** Last update Fri Aug 7 4:55:33 PM 2025 Paradis
*/

#ifndef 			    __PICTURE_HPP__
	# define 		    __PICTURE_HPP__

#include <string>
class	                Picture
{
    public:
        Picture(void);
        Picture(const std::string &file);
        Picture(const Picture &picture);
        Picture         &operator=(const Picture &picture);
        virtual ~Picture(void);

        bool            getPictureFromFile(const std::string &file);
        
        std::string     data;
        
    protected:
    private:
        std::string     _file;
};

#endif 				/* !__PICTURE_HPP__ */
