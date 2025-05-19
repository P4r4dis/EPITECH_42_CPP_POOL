/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:39:34 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/16 20:06:55 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __WRONGANIMAL_HPP__
    #define             __WRONGANIMAL_HPP__

    #include <string>
    class               WrongAnimal
    {
        public:
            WrongAnimal(void);
            WrongAnimal(std::string type);
            WrongAnimal(const WrongAnimal &animal);
            WrongAnimal      &operator=(const WrongAnimal &animal);
            virtual ~WrongAnimal(void);

            std::string getType(void) const;
            void        setType(std::string type);

            void        makeSound(void) const;
        protected:
            std::string _type;
    };
    
#endif //               !_WRONGANIMAL_HPP__