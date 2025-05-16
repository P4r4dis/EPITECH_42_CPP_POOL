/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:26:22 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 19:52:02 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __DOG_HPP__
    #define             __DOG_HPP__

    #include <string>
    #include "Animal.hpp"
    class               Dog :   public Animal
    {
        public:
            Dog(void);
            Dog(std::string type);
            Dog(const Dog &dog);
            Dog      &operator=(const Dog &dog);
            virtual ~Dog(void);
            
            virtual void    makeSound(void) const;
        private:
    };
    
#endif //               !_DOG_HPP__