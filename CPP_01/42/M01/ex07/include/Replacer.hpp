/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:51 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/06 16:10:13 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __REPLACER_HPP__
    #define             __REPLACER_HPP__

    #include <fstream>
    #include <string>
    
    class               Replacer
    {
        public:
            Replacer(std::string fileName, std::string s1, std::string s2);
            ~Replacer(void);

            std::ifstream   openFile(std::string file);
            std::string     readFile(std::ifstream &inputSteram);
        private:
            std::string _fileName;
            std::string _s1;
            std::string _s2;
    };
#endif //               !_REPLACER_HPP__