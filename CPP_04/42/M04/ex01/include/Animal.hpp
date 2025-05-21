/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:43:55 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 03:14:57 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __ANIMAL_HPP__
    #define             __ANIMAL_HPP__

    #include <string>
    #include "Brain.hpp"
    class               Animal
    {
        public:
            Animal(void);
            Animal(std::string type);
            Animal(const Animal &animal);
            Animal      &operator=(const Animal &animal);
            virtual ~Animal(void);

            std::string getType(void) const;
            void        setType(std::string type);

            virtual void        makeSound(void) const = 0;
            virtual Brain       *getBrain(void) const = 0;
        protected:
            std::string _type;
    };
    
#endif //               !_ANIMAL_HPP__