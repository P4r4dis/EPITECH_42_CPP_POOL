/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:20:29 by Paradis           #+#    #+#             */
/*   Updated: 2024/07/01 16:57:34 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __PHONEBOOK_HPP__
    #define             __PHONEBOOK_HPP__

    #include <string>

    #include "Contact.hpp"

    #define MAX_NB_CONTACT 7
    class               PhoneBook
    {
        public:
            PhoneBook(void);
            ~PhoneBook(void);

            int         getNbContact(void) const;
            Contact     *getPtrContactTab(void) const;
            Contact     *getContactTab(int index) const;

            void        setContact(Contact *contact);
            // void        addContact(Contact contact);
        private:

            int         _nbContact;
            Contact     *_contactTab[MAX_NB_CONTACT];
    };
#endif //               __PHONEBOOK_HPP__ END !