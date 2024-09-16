/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:51 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/11 17:08:13 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __REPLACER_HPP__
    #define             __REPLACER_HPP__

    #include <string>
    
    class               Replacer
    {
        public:
            Replacer(std::string fileName,
                    std::string s1, std::string s2);
            ~Replacer(void);

            void            sed(void);
            // std::string     readFile(std::ifstream &inputSteram);
            // std::string     replace(std::string line);
            // std::ofstream   createFile(std::string path);
        private:
            std::string _fileName;
            std::string _s1;
            std::string _s2;
    };
#endif //               !_REPLACER_HPP__