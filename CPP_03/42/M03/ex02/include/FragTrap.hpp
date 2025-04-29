/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:36:16 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/29 19:51:36 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef                 __FRAGTRAP_HPP__
    #define             __FRAGTRAP_HPP__

    #include "ClapTrap.hpp"

    class               FragTrap    :   public ClapTrap
    {
        public:
            FragTrap(void);
            FragTrap(const std::string &name);
            FragTrap(const FragTrap &fragTrap);
            ~FragTrap(void);

            FragTrap    &operator=(const FragTrap &fragTrap);

            void        highFivesGuy(void);
    };
#endif //               !_FRAGTRAP_HPP__