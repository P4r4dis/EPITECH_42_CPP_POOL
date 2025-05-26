/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:56:37 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/26 20:33:19 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource(void)  :   IMateriaSource()
{
    for (int i = 0; i < STOCK_SIZE; ++i)
        _stockMateria[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)  :   IMateriaSource()
{
    for (int i = 0; i < STOCK_SIZE; ++i)
    {
        if (materiaSource._stockMateria[i])
            _stockMateria[i] = materiaSource._stockMateria[i]->clone();
        else
            _stockMateria[i] = nullptr;
    }
}

MateriaSource           &MateriaSource::operator=(const MateriaSource &materiaSource)
{
    if (this != &materiaSource)
    {
        for (int i = 0; i < STOCK_SIZE; ++i)
        {
            if (_stockMateria[i])
            {
                delete _stockMateria[i];
                _stockMateria[i] = nullptr;
            }
        }

        for (int i = 0; i < STOCK_SIZE; ++i)
        {
            if (materiaSource._stockMateria[i])
                _stockMateria[i] = materiaSource._stockMateria[i]->clone();
            else
                _stockMateria[i] = nullptr;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < STOCK_SIZE; ++i)
        if (_stockMateria[i])
            delete _stockMateria[i];
}

AMateria                *MateriaSource::getMateria(int idx) const
{
    if (idx >= 0 && idx < STOCK_SIZE)
        return _stockMateria[idx];
    return nullptr;
}

void                    MateriaSource::learnMateria(AMateria *materia)
{
    if (materia)
    {
        for (int i = 0; i < STOCK_SIZE; ++i)
        {
            if (!_stockMateria[i])
            {
                _stockMateria[i] = materia;
                return ;
            }
        }
    }
    delete materia;
}

AMateria                *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < STOCK_SIZE; ++i)
    {
        if (_stockMateria[i] && _stockMateria[i]->getType() == type)
            return _stockMateria[i]->clone();
    }
    return 0;
}