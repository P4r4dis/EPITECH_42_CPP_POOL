/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:35:17 by Paradis           #+#    #+#             */
/*   Updated: 2025/07/29 16:41:48 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __UTILS_HPP__
#define                 __UTILS_HPP__

#include "Base.hpp"

Base    *generate(void);
void    identify(Base *p);
void    identify(Base &p);
#endif //               !_UTILS_HPP__