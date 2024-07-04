/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:20:29 by Paradis           #+#    #+#             */
/*   Updated: 2024/07/04 15:52:33 by Paradis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef                 __PHONEBOOK_HPP__
    #define             __PHONEBOOK_HPP__

    #include <string>

    #include "Contact.hpp"

    #define MAX_NB_CONTACT 8
    class                   PhoneBook
    {
        public:
            PhoneBook(void);
            ~PhoneBook(void);

            int             getIndex(void) const;
            int             getNbContact(void) const;
            const Contact   *getContactTab(void) const;

            void            addContact(Contact contact);
            void            search(int index);
            void            displayAllContact(void);
            void            displayContact(int index);
            std::string     truncString(std::string str);
        private:

            int             _nbContact;
            int             _index;
            Contact         _contactTab[MAX_NB_CONTACT];
    };
#endif //               __PHONEBOOK_HPP__ END !
