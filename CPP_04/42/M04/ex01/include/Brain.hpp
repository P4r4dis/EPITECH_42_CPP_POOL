/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:41:07 by Paradis           #+#    #+#             */
/*   Updated: 2025/05/19 18:11:03 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __BRAIN_HPP__
#define                 __BRAIN_HPP__
#include <string>

#define SIZE 100

class                   Brain
{
    public:
        Brain(void);
        Brain(const Brain &brain);
        Brain           &operator=(const Brain &brain);
        virtual ~Brain(void);

        std::string     *getIdeas(void) const;
        void            setIdeas(std::string *newIdeas);

        std::string     getIdea(size_t index) const;
        void            setIdea(size_t index, std::string idea);
    private:
        std::string     *ideas;

};
#endif //               !_BRAIN_HPP__