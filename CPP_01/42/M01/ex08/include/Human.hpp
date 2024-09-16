/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:51 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/16 17:48:22 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __HUMAN_HPP__
    #define             __HUMAN_HPP__

    #include <string>
    
    class Human
    {
        private:
            void meleeAttack(std::string const & target);
            void rangedAttack(std::string const & target);
            void intimidatingShout(std::string const & target);
        public:
            void action(std::string const & action_name, std::string const & target);
    };

#endif //               !_HUMAN_HPP__