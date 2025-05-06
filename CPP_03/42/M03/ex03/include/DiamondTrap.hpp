/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:44:27 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/30 17:48:46 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __DIAMONDTRAP_HPP__
    #define             __DIAMONDTRAP_HPP__

    #include "ScavTrap.hpp"
    #include "FragTrap.hpp"
    #include <string>

    class               DiamondTrap  :  public FragTrap, public ScavTrap
    {
        public:
            DiamondTrap(void);
            DiamondTrap(const std::string &name);
            DiamondTrap(const DiamondTrap &diamonTrap);
            virtual ~DiamondTrap(void);

            DiamondTrap &operator=(const DiamondTrap &diamonTrap);

            std::string getName(void) const;
            void        setName(std::string name);

            void        whoAmI(void);

        private:
            std::string _name;
    };
#endif //               !_DIAMONDTRAP_HPP__