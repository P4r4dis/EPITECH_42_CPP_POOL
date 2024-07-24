/*
** MyCat.hpp for MyCat in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex00/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Jul 19 6:18:01 PM 2024 Paradis
** Last update Thu Jul 24 4:37:36 PM 2024 Paradis
*/

#ifndef         MYCAT_HPP
    #define     MYCAT_HPP

#include <string>

class           MyCat 
{
    public:
        MyCat(void);
        ~MyCat(void);

        void            usage(void);
        bool            isDirectory(std::string directory);
        void            myCat(std::string fileName);
    protected:
    private:
};

#endif          /* !MYCAT_HPP */
