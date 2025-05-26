/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:57:13 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/23 19:12:59 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __ICHARACTER_HPP__
#define                 __ICHARACTER_HPP__
#include "AMateria.hpp"
#include <string>
class                   ICharacter
{
    public:
        virtual ~ICharacter() {}
        
        virtual std::string const   &getName() const = 0;
        virtual void                equip(AMateria* m) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
        // virtual AMateria            *getMateria(int idx) const = 0;
};
#endif //               !_ICHARACTER_HPP__