/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyCat.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:59:12 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/19 20:46:33 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <dirent.h>

#include "../include/MyCat.hpp"

MyCat::MyCat(void)
{}

MyCat::~MyCat(void)
{}

void            MyCat::usage(void)
{
    std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
}

bool            MyCat::isDirectory(std::string directory)
{
    DIR *dir;

    dir = opendir(directory.c_str());
    if (dir)
    {
        std::cerr << "my_cat: " << directory << ": Is a directory" << std::endl;
        closedir(dir);
        return true;
    }
    else
        return false;

}
void            MyCat::myCat(std::string fileName)
{
    std::fstream    fs;
    std::string     line;

    fs.open(fileName.c_str(), std::ios_base::in);
    if (!fs.is_open())
    {
        std::cerr << "my_cat: " << fileName << ": " << std::strerror(errno) << std::endl;
        return ;
    }
    else if (isDirectory(fileName))
        return ;
    else
        while (getline(fs, line, '\0'))
            std::cout << line << std::flush;
    fs.close();
}