/*
** SickKoalaList.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/source
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jul 31 4:56:58 PM 2024 Paradis
** Last update Thu Jul 31 5:08:18 PM 2024 Paradis
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *sickKoala)  :   _sickKoala(sickKoala)
{
}

SickKoalaList::~SickKoalaList(void)
{
}

SickKoala       *SickKoalaList::getContent(void) const
{
    return _sickKoala;
}