/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:25:32 by Paradis           #+#    #+#             */
/*   Updated: 2024/06/25 04:32:30 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef             __MEGAPHONE_HPP__
    #define         __MEGAPHONE_HPP__

    class           Megaphone
    {
        public:
            Megaphone(int ac, char **av);
            ~Megaphone(void);

        private:
            int             _ac;
            char            **_av;
    };
#endif //           __MEGAPHONE_HPP__ END FILE