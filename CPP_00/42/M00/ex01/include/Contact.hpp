/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:20:29 by Paradis           #+#    #+#             */
/*   Updated: 2024/06/26 20:07:52 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __CONTACT_HPP__
    #define             __CONTACT_HPP__

    #include <string>

    class               Contact
    {
        public:
            Contact(void);
            ~Contact(void);
            
            std::string getFirstName(void) const;
            std::string getLastName(void) const;
            std::string getNickName(void) const;
            std::string getPhoneNb(void) const;
            std::string getDarkestSecret(void) const;
            
            void        setFirstName(std::string firstName);
            void        setLastName(std::string lastName);
            void        setNickName(std::string nickName);
            void        setPhoneNb(std::string phoneNb);
            void        setDarkestSecret(std::string darkest_secret);
            void        setInfoContact( std::string firstName, std::string lastName,
                                        std::string nickName, std::string phoneNb,
                                        std::string darkest_secret);
        private:
            std::string _firstName;
            std::string _lastName;
            std::string _nickName;
            std::string _phoneNb;
            std::string _darkest_secret;
    };
#endif //               __CONTACT_HPP__ END !