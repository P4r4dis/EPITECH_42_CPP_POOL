/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:36:16 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/28 21:17:59 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef             __PONY_HPP__
    #define         __PONY_HPP__

    #include <string>

    class           Pony
    {
        private:
            std::string     _name;
        public:
            Pony(std::string name);
            ~Pony();

            std::string     getName(void) const;

            void            setName(std::string name);
    };

    void            ponyOnTheStack(std::string ponyName);
#endif  //          !_PONY_HPP__
    