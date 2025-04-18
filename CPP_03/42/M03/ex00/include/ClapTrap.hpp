/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:42:41 by Paradis           #+#    #+#             */
/*   Updated: 2025/04/18 20:53:14 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __CLAPTRAP_HPP__
    #define             __CLAPTRAP_HPP__

    #include <string>
    
    class               ClapTrap
    {
        public:
            ClapTrap(const std::string &name);
            ClapTrap(const ClapTrap &clapTrap);
            ~ClapTrap(void);

            ClapTrap            &operator=(const ClapTrap &clapTrap);

            const std::string   &getName(void) const;
            void                setName(const std::string &name);

            size_t              getHit(void) const;
            void                setHit(size_t hit);

            size_t              getEnergy(void) const;
            void                setEnergy(size_t energy);

            size_t              getAttack(void) const;
            void                setAttack(size_t attack);

            void                attack(const std::string &target);
            void                takeDamage(unsigned int amount);
            void                beRepaired(unsigned int amount);
        
        private:
            std::string _name;
            size_t      _hit;
            size_t      _energy;
            size_t      _attack;
    };
#endif //               !_CLAPTRAP_HPP__