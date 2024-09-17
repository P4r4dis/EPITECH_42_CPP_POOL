/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:08:51 by Paradis           #+#    #+#             */
/*   Updated: 2024/09/17 19:11:33 by Paradis          ###   ########.fr       */
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
            std::ofstream           &getFileStream(void);

            void                    log(std::string const & dest,
                                        std::string const & message);
        private:
            std::string     _fileName;
            std::ofstream   _fileStream;

            void                    logToConsole(std::string msg);
            void                    logToFile(std::string msg);
            std::string             makeLogEntry(std::string msg);
    };

#endif //               !_LOGGER_HPP__