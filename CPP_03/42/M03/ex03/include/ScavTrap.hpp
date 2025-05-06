/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:36:57 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/30 18:44:14 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __SCAVTRAP_HPP__
    #define             __SCAVTRAP_HPP__

    #include "ClapTrap.hpp"

    class               ScavTrap    :   virtual public ClapTrap
    {
        public:
            ScavTrap(void);
            ScavTrap(const std::string &name);
            ScavTrap(const ScavTrap &scavTrap);
            virtual ~ScavTrap(void);

            ScavTrap    &operator=(const ScavTrap &scavTrap);

            void        attack(const std::string &target);
            void        guardGate(void);

            bool        getGuardGate(void) const;

        private:
            bool        _guardGate;
    };
#endif //               !_SCAVTRAP_HPP__