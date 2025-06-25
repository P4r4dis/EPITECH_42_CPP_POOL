/*
** main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex01/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 25 6:18:03 PM 2025 Paradis
** Last update Thu Jun 25 6:26:02 PM 2025 Paradis
*/

#include <iostream>

#include "../include/DirectoryLister.hpp"


void    myLs(const std::string &directory)
{
    try
    {
        SafeDirectoryLister     dl(directory, false);

        std::cout << directory << ":" << std::endl;
        for (std::string file = dl.get(); true; file = dl.get())
            std::cout << file << std::endl;
    } 
    catch (const IDirectoryLister::NoMoreFileException &e)
    {
        return;
    }
    throw std::runtime_error("should not happen");
}

int main ( void )
{
    try
    {
        myLs("./test/");
        myLs("./not_exist/");
        myLs("./test/");
    } 
    catch (const IDirectoryLister::OpenFailureException &e)
    {
        std::cerr << "failure: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "unexpected error: " << e.what() << std::endl;
    }
    return 0;
}