/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:42:08 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 20:06:46 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef                 __WRONGCAT_HPP__
    #define             __WRONGCAT_HPP__

    #include <string>
    #include "WrongAnimal.hpp"
    class               WrongCat :   public WrongAnimal
    {
        public:
            WrongCat(void);
            WrongCat(std::string type);
            WrongCat(const WrongCat &dog);
            WrongCat      &operator=(const WrongCat &dog);
            virtual ~WrongCat(void);
            
            void        makeSound(void) const;
        private:
    };
    
#endif //               !_WRONGCAT_HPP__