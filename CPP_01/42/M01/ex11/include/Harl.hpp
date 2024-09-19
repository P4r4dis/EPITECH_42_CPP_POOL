/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:51 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/17 19:11:33 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __HARL_HPP__
    #define             __HARL_HPP__
    
    #include <string>
    class Harl
    {
        public:
            Harl(void);
            ~Harl(void);

            void        complain(std::string level);
            void        dispatcher(std::string level);
        private:
            void        debug(void);
            void        info(void);
            void        warning(void);
            void        error(void);
    };

#endif //               !_HARL_HPP__