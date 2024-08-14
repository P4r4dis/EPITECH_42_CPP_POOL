/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:20:29 by Paradis           #+#    #+#             */
/*   Updated: 2024/07/10 21:35:18 by Paradis          ###   ########.fr       */
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
            void            setIndex(int index);

            int             getNbContact(void) const;
            void            setNbContact(int nbContact);
            
            const Contact   *getContactTab(void) const;
            void            setContactTab(Contact newContactTab[]);
            
            void            addContact(Contact contact);
            void            search(std::string input);
            PhoneBook       *exit(void);
            void            process(void);
            void            displayAllContact(void);
            void            displayContact(int index);
            std::string     truncString(std::string str);
            std::string     uppercase(std::string str);
            void            handleInput(std::string input);
            Contact         fillContact(Contact contact, std::string str); // do UT
            void            runProcess(void);
            int             validIndex(std::string input);
        private:

            int             _nbContact;
            int             _index;
            Contact         _contactTab[MAX_NB_CONTACT];
            std::string     _input;
            int             _exitCount;
    };
#endif //               __PHONEBOOK_HPP__ END !
