/*
** ToyStory.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_06/EPITECH/D12/ex06/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Aug 7 5:06:06 PM 2025 Paradis
** Last update Sun Aug 23 4:56:14 PM 2025 Paradis
*/

#include "../include/ToyStory.hpp"

#include <cstring>
#include <fstream>
#include <iostream>

void            ToyStory::printToyPictures(Toy &toy1, Toy &toy2)
{
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
}

void            ToyStory::tellMeAStory(const std::string &fileName,
                            Toy &toy1,
                            bool (Toy::*func1) (const std::string &),
                            Toy &toy2,
                            bool (Toy::*func2) (const std::string &))
{
    std::fstream    fs(fileName);
    size_t          pos;
    std::string     path;

    printToyPictures(toy1, toy2);

    if (fs.is_open()) 
    {
        std::string line;
        for (int count = 0; std::getline(fs, line); ++count)
        {
            pos = line.find("picture:");

            if (count % 2 == 0)
            {
                if (pos == 0)
                    path = line.substr(8, line.length());
                if (count % 2 == 0 && !path.empty())
                {
                    if (toy1.setAscii(path) == false)
                    {
                        auto e = toy1.getLastError();
                        if (e.type == Toy::Error::PICTURE)
                            std::cout   << "Error in " << e.where() 
                                        << ": " << e.what() << std::endl;
                        fs.close();
                        return ;
                    }
                    std::cout << toy1.getAscii() << std::flush;
                    path.clear();
                    count -= 1;
                }
                else
                    (toy1.*func1)(line);
            }
            else
            {
                if (pos == 0)
                    path = line.substr(8, line.length());
                if (!path.empty())
                {
                    if (toy2.setAscii(path) == false)
                    {
                        auto e = toy2.getLastError();
                        if (e.type == Toy::Error::PICTURE)
                            std::cout   << "Error in " << e.where() 
                                        << ": " << e.what() << std::endl;
                        fs.close();
                        return ;
                    }
                    std::cout << toy2.getAscii() << std::flush;
                    path.clear();
                    count += 1;
                }
                else
                {
                    if ((toy2.*func2)(line) == false)
                    {
                        auto e = toy2.getLastError();
                        if (e.type == Toy::Error::SPEAK)
                            std::cout   << "Error in " << e.where() 
                                        << ": " << e.what() << std::endl;
                        fs.close();
                        return ;
                    }
                }
            }
        }
        fs.close();
    }
    else
        std::cout << "Bad Story" << std::endl;
}