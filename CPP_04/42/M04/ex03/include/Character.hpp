/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:57:48 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/26 18:19:58 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __CHARACTER_HPP__
#define                 __CHARACTER_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

#define INVENTORY_SIZE 4

class                   Character   : public ICharacter
{
    public:
        Character(void);
        Character(const std::string &name);
        Character(const Character &character);
        Character       &operator=(const Character &character);
        virtual ~Character(void);

        virtual std::string const   &getName() const;
        virtual void                equip(AMateria *m);
        virtual void                unequip(int idx);
        virtual void                use(int idx, ICharacter& target);
    private:
        std::string     _name;
        AMateria        *_inventory[INVENTORY_SIZE];
};
#endif //               !_CHARACTER_HPP__