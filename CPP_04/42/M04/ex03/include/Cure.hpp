/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:01:32 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/22 20:09:16 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __CURE_HPP__
#define                 __CURE_HPP__
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class                   Cure    :   public AMateria
{
    public:
        Cure(void);
        Cure(const std::string &type);
        Cure(const Cure &ice);
        Cure             &operator=(const Cure &ice);
        virtual ~Cure(void);

        virtual Cure    *clone(void) const;
        virtual void    use(ICharacter &target);
};
#endif //               !_CURE_HPP__