/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:32:03 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/29 20:47:14 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __ZOMBIE_HPP__
    #define             __ZOMBIE_HPP__

    #include <string>
    class               Zombie
    {
        public:
            Zombie(std::string name);
            ~Zombie(void);

            std::string getName(void) const;

            void        setName(std::string name);
        private:
            std::string _name;
    };
#endif //               !_ZOMBIE_HPP__