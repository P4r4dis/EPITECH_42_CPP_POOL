/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:32:03 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/02 14:50:59 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __ZOMBIE_HPP__
    #define             __ZOMBIE_HPP__

    #include <string>
    class               Zombie
    {
        public:
            Zombie(void);
            Zombie(std::string name);
            ~Zombie(void);

            std::string getName(void) const;

            void        setName(std::string name);

            void        announce(void);
        private:
            std::string _name;
    };

    Zombie              *newZombie(std::string name);
    void                randomChump(std::string name);
    Zombie              *zombieHorde(int N, std::string name);
#endif //               !_ZOMBIE_HPP__