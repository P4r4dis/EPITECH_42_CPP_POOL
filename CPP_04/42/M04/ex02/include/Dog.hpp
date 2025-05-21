/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:26:22 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 03:24:00 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __DOG_HPP__
    #define             __DOG_HPP__

    #include <string>
    #include "Aanimal.hpp"
    #include "Brain.hpp"
    
    class               Dog :   public Aanimal
    {
        public:
            Dog(void);
            Dog(std::string type);
            Dog(const Dog &dog);
            Dog      &operator=(const Dog &dog);
            virtual ~Dog(void);
            
            virtual void    makeSound(void) const;
            
            Brain           *getBrain(void) const;
            void            setBrain(const Brain *brain);
        private:
            Brain           *_brain;
    };
    
#endif //               !_DOG_HPP__