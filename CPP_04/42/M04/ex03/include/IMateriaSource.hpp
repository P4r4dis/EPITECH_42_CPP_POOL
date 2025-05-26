/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:28:25 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/26 19:42:47 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __IMATERIASOURCE_HPP__
#define                 __IMATERIASOURCE_HPP__

#include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void        learnMateria(AMateria*) = 0;
        virtual AMateria    *createMateria(std::string const & type) = 0;
};
#endif //               !_IMATERIASOURCE_HPP__