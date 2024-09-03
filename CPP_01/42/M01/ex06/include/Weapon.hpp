/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:44:44 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 19:49:49 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __WEAPON_HPP__
    #define             __WEAPON_HPP__
    #include <string>
    
    class               Weapon
        {
            public:
                Weapon(std::string type);
                ~Weapon(void);

                const std::string   &getType(void) const;
                void                setType(const std::string &type);
            private:
                std::string         _type;
        };
#endif //               !_WEAPON_HPP__