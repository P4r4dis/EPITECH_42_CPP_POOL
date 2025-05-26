/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:30:45 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/26 20:13:55 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __MATERIASOURCE_HPP__
#define                 __MATERIASOURCE_HPP__
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#define STOCK_SIZE 4
class                   MateriaSource   :   public IMateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &materiaSource);
        MateriaSource   &operator=(const MateriaSource &materiaSource);
        ~MateriaSource(void);

        virtual void        learnMateria(AMateria *materia);
        virtual AMateria    *createMateria(std::string const &type);

        AMateria            *getMateria(int idx) const;
    private:
        AMateria            *_stockMateria[STOCK_SIZE];
};
#endif //               !_MATERIASOURCE_HPP__