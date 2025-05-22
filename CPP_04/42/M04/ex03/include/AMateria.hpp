/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:08:10 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/21 20:38:50 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                     __AMATERIA_HPP__
#define                     __AMATERIA_HPP__

#include <string>
class                       AMateria
{
    public:
        AMateria(void);
        AMateria(std::string const &type);
        AMateria(const AMateria &amateria);
        AMateria            &operator=(const AMateria &amateria);
        virtual ~AMateria(void);

        std::string const   &getType(void) const; //Returns the materia type
        // virtual AMateria    *clone(void) const = 0;
        // virtual void        use(ICharacter& target);
    private:
        std::string         _type;
};
#endif   //              !_AMATERIA_HPP__