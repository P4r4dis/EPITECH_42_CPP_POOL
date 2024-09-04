/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:17:31 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/04 16:11:03 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __HUMANB_HPP__
    #define             __HUMANB_HPP__

    #include <string>

    #include "Weapon.hpp"
    class               HumanB
    {
        public:
            HumanB(std::string name);
            ~HumanB(void);

            std::string     getName(void) const;
            const Weapon    *getWeapon(void) const;

            void            setName(std::string name);
            void            setWeapon(Weapon &weapon); // need ref because _weapon is on the stack and at the end of the function _weapon is disalocatted

            void            attack(void) const;
        private:
            std::string     _name;
            Weapon          *_weapon;

    };
#endif //               !_HUMANB_HPP__