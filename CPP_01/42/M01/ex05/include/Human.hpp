/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:45:10 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 18:13:17 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __HUMAN_HPP__
    #define             __HUMAN_HPP__

    #include "Brain.hpp"
class                   Human
    {
        public:
            Human(void);
            ~Human(void);

            std::string identify(void) const;
            const Brain       &getBrain(void) const;
        private:
            const Brain _brain;
    };
#endif //               !_HUMAN_HPP__