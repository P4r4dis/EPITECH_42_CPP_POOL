/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyCat.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:59:02 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/19 19:59:05 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef         MYCAT_HPP
    #define     MYCAT_HPP

#include <string>

class           MyCat 
{
    public:
        MyCat(void);
        ~MyCat(void);

        void            usage(void);
        bool            isDirectory(std::string directory);
        void            myCat(std::string fileName);
    protected:
    private:
};

#endif          /* !MYCAT_HPP */
