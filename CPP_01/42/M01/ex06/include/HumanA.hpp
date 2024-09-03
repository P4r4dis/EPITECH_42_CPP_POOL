/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:17:31 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 20:38:12 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __HUMANA_HPP__
    #define             __HUMANA_HPP__

    #include <string>

    #include "Weapon.hpp"
    class               HumanA
    {
        public:
            HumanA(std::string name, const Weapon &weapon);
            ~HumanA(void);

            std::string     getName(void) const;
            const Weapon    &getWeapon(void) const;

            void            setName(std::string name);
            void            setWeapon(const Weapon &weapon);
        private:
            std::string     _name;
            const Weapon    _weapon;

    };
#endif //               !_HUMANA_HPP__