/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:13:43 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 19:59:16 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef                 __CAT_HPP__
    #define             __CAT_HPP__

    #include <string>
    #include "Animal.hpp"
    class               Cat :   public Animal
    {
        public:
            Cat(void);
            Cat(std::string type);
            Cat(const Cat &dog);
            Cat      &operator=(const Cat &dog);
            virtual ~Cat(void);
            
            virtual void makeSound(void) const;
        private:
    };
    
#endif //               !_CAT_HPP__