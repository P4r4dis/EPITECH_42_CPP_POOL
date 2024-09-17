/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:51 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/17 17:17:07 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __LOGGER_HPP__
    #define             __LOGGER_HPP__

    #include <string>
    #include <fstream>
    
    class Logger
    {
        public:
            Logger(std::string fileName);
            ~Logger(void);

            std::string             getFileName(void) const;
            const std::ofstream     &getFileStream(void) const;
        private:
            std::string     _fileName;
            std::ofstream   _fileStream;

            void                    logToConsole(std::string msg);
    };

#endif //               !_LOGGER_HPP__