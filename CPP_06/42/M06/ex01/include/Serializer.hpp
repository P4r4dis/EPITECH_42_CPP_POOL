/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:27:15 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/29 16:02:33 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __SERIALIZER_HPP__
#define                 __SERIALIZER_HPP__

#include <cstdint>
class                   Serializer
{
    public:
        typedef struct  Data
        {
            int _data;
        }               Data;

        static uintptr_t    serialize(Data *ptr);
        static Data         *deserialize(uintptr_t raw);
    private:
        Serializer(void) {};
        Serializer(const Serializer &obj) {
            static_cast<void>(obj);
        };
        Serializer &operator=(const Serializer &rhs) {
            static_cast<void>(rhs);
            return *this;
        };
        virtual ~Serializer(void) {};

};
#endif //               !_SERIALIZER_HPP__