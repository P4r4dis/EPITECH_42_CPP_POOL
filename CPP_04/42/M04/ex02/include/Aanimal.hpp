/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 03:22:44 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 03:23:32 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef                 __AANIMAL_HPP__
    #define             __AANIMAL_HPP__

    #include <string>
    #include "Brain.hpp"
    class               Aanimal
    {
        public:
            Aanimal(void);
            Aanimal(std::string type);
            Aanimal(const Aanimal &animal);
            Aanimal      &operator=(const Aanimal &animal);
            virtual ~Aanimal(void);

            std::string getType(void) const;
            void        setType(std::string type);

            virtual void        makeSound(void) const = 0;
            virtual Brain       *getBrain(void) const = 0;
        protected:
            std::string _type;
    };
    
#endif //               !_AANIMAL_HPP__