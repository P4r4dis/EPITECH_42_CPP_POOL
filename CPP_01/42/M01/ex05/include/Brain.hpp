/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:01:05 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/03 16:13:18 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __BRAIN_HPP__
    #define             __BRAIN_HPP__

    #include <string>
    class               Brain
    {
        public:
            Brain(void);
            ~Brain(void);

            std::string identify(void);
    };
#endif