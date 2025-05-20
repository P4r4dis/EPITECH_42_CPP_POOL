/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:13:43 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/20 20:16:25 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef                 __CAT_HPP__
    #define             __CAT_HPP__

    #include <string>
    #include "Animal.hpp"
    #include "Brain.hpp"
    class               Cat :   public Animal
    {
        public:
            Cat(void);
            Cat(std::string type);
            Cat(const Cat &dog);
            Cat      &operator=(const Cat &dog);
            virtual ~Cat(void);
            
            virtual void    makeSound(void) const;
            Brain           *getBrain(void) const;
            void            setBrain(const Brain *brain);
        private:
            Brain           *_brain;
    };
    
#endif //               !_CAT_HPP__