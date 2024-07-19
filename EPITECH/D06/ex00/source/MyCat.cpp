#include <iostream>
#include "../include/MyCat.hpp"

MyCat::MyCat(void)
{}

MyCat::~MyCat(void)
{}

void            MyCat::usage(void)
{
    std::cout << "my_cat: Usage: ./my_cat file [...]" << std::endl;
}