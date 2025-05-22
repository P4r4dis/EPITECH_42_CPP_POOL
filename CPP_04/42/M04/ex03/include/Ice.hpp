/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:01:32 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/22 20:32:42 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __ICE_HPP__
#define                 __ICE_HPP__
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class                   Ice :   public AMateria
{
    public:
        Ice(void);
        Ice(const std::string &type);
        Ice(const Ice &ice);
        Ice             &operator=(const Ice &ice);
        virtual ~Ice(void);

        virtual Ice     *clone(void) const;
        virtual void    use(ICharacter &target);
};
#endif //               !_ICE_HPP__