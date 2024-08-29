/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:36:16 by Paradis           #+#    #+#             */
/*   Updated: 2024/08/29 17:09:25 by Paradis          ###   ########.fr       */
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
    void            ponyOnTheHeap(std::string ponyName);
#endif  //          !_PONY_HPP__
    