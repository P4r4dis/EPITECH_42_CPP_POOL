#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>
#include <iostream>

#include "../../include/PhoneBook.hpp"
#include "../../include/Contact.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Contact, test_Contact_CTOR_isDefined)
{
    {
        Contact     contact;

        cr_assert_not_null(&contact);
    }
}

Test(Contact, test_Contact_set_and_getFirstName_isEmpty)
{
    {
        Contact     contact;

        cr_assert(contact.getFirstName().empty() == true);
    }
}

Test(Contact, test_Contact_set_and_getFirstName)
{
    {
        Contact     contact;

        cr_assert(contact.getFirstName().empty() == true);
        contact.setFirstName("0");
        cr_assert(contact.getFirstName().empty() == false);
        cr_assert(contact.getFirstName() == "0");


    }
}

Test(Contact, test_Contact_set_and_getLastName_isEmpty)
{
    {
        Contact     contact;

        cr_assert(contact.getLastName().empty() == true);
    }
}

Test(Contact, test_Contact_set_and_getLastName)
{
    {
        Contact     contact;

        cr_assert(contact.getLastName().empty() == true);
        contact.setLastName("0");
        cr_assert(contact.getLastName().empty() == false);
        cr_assert(contact.getLastName() == "0");


    }
}

Test(Contact, test_Contact_set_and_getNickName_isEmpty)
{
    {
        Contact     contact;

        cr_assert(contact.getNickName().empty() == true);
    }
}

Test(Contact, test_Contact_set_and_getNickName)
{
    {
        Contact     contact;

        cr_assert(contact.getNickName().empty() == true);
        contact.setNickName("0");
        cr_assert(contact.getNickName().empty() == false);
        cr_assert(contact.getNickName() == "0");


    }
}

Test(Contact, test_Contact_set_and_getPhoneNb_isEmpty)
{
    {
        Contact     contact;

        cr_assert(contact.getPhoneNb().empty() == true);
    }
}

Test(Contact, test_Contact_set_and_getPhoneNb)
{
    {
        Contact     contact;

        cr_assert(contact.getPhoneNb().empty() == true);
        contact.setPhoneNb("0");
        cr_assert(contact.getPhoneNb().empty() == false);
        cr_assert(contact.getPhoneNb() == "0");


    }
}

Test(Contact, test_Contact_set_and_getDarkestSecret_isEmpty)
{
    {
        Contact     contact;

        cr_assert(contact.getDarkestSecret().empty() == true);
    }
}

Test(Contact, test_Contact_set_and_getDarkestSecret)
{
    {
        Contact     contact;

        cr_assert(contact.getDarkestSecret().empty() == true);
        contact.setDarkestSecret("0");
        cr_assert(contact.getDarkestSecret().empty() == false);
        cr_assert(contact.getDarkestSecret() == "0");


    }
}

Test(Contact, test_Contact_setInfoContact)
{
    {
        Contact     contact;

        contact.setInfoContact("Mark", "MarkX", "AllMark", "0908070605", "secret1");
        cr_assert(contact.getFirstName() == "Mark");
        cr_assert(contact.getLastName() == "MarkX");
        cr_assert(contact.getNickName() == "AllMark");
        cr_assert(contact.getPhoneNb() == "0908070605");
        cr_assert(contact.getDarkestSecret() == "secret1");
    }
}

Test(PhoneBook, test_PhoneBook_CTOR_isDefined)
{
    {
        PhoneBook   phoneBook;

        cr_assert_not_null(&phoneBook);
    }
}

Test(PhoneBook, test_PhoneBook_getNbContact)
{
    {
        PhoneBook   phoneBook;

        cr_assert(phoneBook.getNbContact() == 0);
    }
}

Test(PhoneBook, test_PhoneBook_addContact_isDefined)
{
    {
        PhoneBook   phoneBook;
        Contact     contact;

        phoneBook.addContact(contact);
    }
}

Test(PhoneBook, test_PhoneBook_one_addContact, .init = redirect_all_stdout)
{
    {
        PhoneBook       phoneBook;
        Contact         contact;
        const Contact   *tab;

        contact.setInfoContact("0", "0", "0", "0", "0");
        phoneBook.addContact(contact);
        tab = phoneBook.getContactTab();
        for (int i = 0; i < phoneBook.getNbContact(); i++)
            std::cout << tab[i].getFirstName() << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "0\n"
    );
}

Test(PhoneBook, test_PhoneBook_addContact_with_several_contact
                , .init = redirect_all_stdout)
{
    {
        PhoneBook       phoneBook;
        Contact         contact;
        const Contact   *tab;

        contact.setInfoContact("0", "0", "0", "0", "0");
        phoneBook.addContact(contact);

        contact.setInfoContact("1", "1", "1", "1", "1");
        phoneBook.addContact(contact);

        contact.setInfoContact("2", "2", "2", "2", "2");
        phoneBook.addContact(contact);

        contact.setInfoContact("3", "3", "3", "3", "3");
        phoneBook.addContact(contact);

        contact.setInfoContact("4", "4", "4", "4", "4");
        phoneBook.addContact(contact);

        contact.setInfoContact("5", "5", "5", "5", "5");
        phoneBook.addContact(contact);

        contact.setInfoContact("6", "6", "6", "6", "6");
        phoneBook.addContact(contact);

        contact.setInfoContact("7", "7", "7", "7", "7");
        phoneBook.addContact(contact);

        tab = phoneBook.getContactTab();
        for (int i = 0; i < phoneBook.getNbContact(); i++)
            std::cout << tab[i].getFirstName() << std::endl;
    }
    cr_assert_stdout_eq_str
    (
        "0\n"
        "1\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
    );
}

Test(PhoneBook, test_PhoneBook_addContact_with_more_8_contacts
                , .init = redirect_all_stdout)
{
    
        PhoneBook       phoneBook;
        Contact         contact;
        const Contact   *tab;

        contact.setInfoContact("0", "0", "0", "0", "0");
        phoneBook.addContact(contact);

        contact.setInfoContact("1", "1", "1", "1", "1");
        phoneBook.addContact(contact);

        contact.setInfoContact("2", "2", "2", "2", "2");
        phoneBook.addContact(contact);

        contact.setInfoContact("3", "3", "3", "3", "3");
        phoneBook.addContact(contact);

        contact.setInfoContact("4", "4", "4", "4", "4");
        phoneBook.addContact(contact);

        contact.setInfoContact("5", "5", "5", "5", "5");
        phoneBook.addContact(contact);

        contact.setInfoContact("6", "6", "6", "6", "6");
        phoneBook.addContact(contact);

        contact.setInfoContact("7", "7", "7", "7", "7");
        phoneBook.addContact(contact);

        contact.setInfoContact("8", "8", "8", "8", "8");
        phoneBook.addContact(contact);

        contact.setInfoContact("9", "9", "9", "9", "9");
        phoneBook.addContact(contact);

        tab = phoneBook.getContactTab();
        for (int i = 0; i < phoneBook.getNbContact(); ++i)
            std::cout << tab[i].getFirstName() << std::endl;
    
    cr_assert_stdout_eq_str
    (
        "8\n"
        "9\n"
        "2\n"
        "3\n"
        "4\n"
        "5\n"
        "6\n"
        "7\n"
    );
 
}

Test(PhoneBook, test_PhoneBook_getIndex)
{
    {
        PhoneBook   phoneBook;

        cr_assert(phoneBook.getIndex() == 0);
        
        Contact         contact;

        contact.setInfoContact("0", "0", "0", "0", "0");
        phoneBook.addContact(contact);
        cr_assert(phoneBook.getIndex() == 1);
    }
}

Test(PhoneBook, test_PhoneBook_search_isDefined, .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        int index = 0;
        phoneBook.search(index);
    }
}

Test(PhoneBook, test_PhoneBook_displayAllContact_without_contact
                , .init = redirect_all_stdout)
{
    PhoneBook   phoneBook;

    phoneBook.displayAllContact();
    cr_assert_stdout_eq_str
    (
        "     index|first name| last name|  nickname\n"
    );
}

Test(PhoneBook, test_PhoneBook_displayAllContact_with_contact
                , .init = redirect_all_stdout)
{
    PhoneBook   phoneBook;
    Contact         contact;

    // int index = 7;

    for (int i = 0 ; i < 8; i++)
    {
        contact.setInfoContact(
            std::to_string(i), 
            std::to_string(i), 
            std::to_string(i), 
            std::to_string(i), 
            std::to_string(i));
        phoneBook.addContact(contact);
    }
    phoneBook.displayAllContact();
    cr_assert_stdout_eq_str
    (
        "     index|first name| last name|  nickname\n"
        "         0|         0|         0|         0\n"
        "         1|         1|         1|         1\n"
        "         2|         2|         2|         2\n"
        "         3|         3|         3|         3\n"
        "         4|         4|         4|         4\n"
        "         5|         5|         5|         5\n"
        "         6|         6|         6|         6\n"
        "         7|         7|         7|         7\n"
    );
}

Test(PhoneBook, test_PhoneBook_displayContact
                , .init = redirect_all_stdout)
{
    PhoneBook   phoneBook;
    Contact         contact;

    int index = 7;

    for (int i = 0 ; i < 8; i++)
    {
        contact.setInfoContact(
            std::to_string(i), 
            std::to_string(i), 
            std::to_string(i), 
            std::to_string(i), 
            std::to_string(i));
        phoneBook.addContact(contact);
    }
    phoneBook.displayContact(index);
    cr_assert_stdout_eq_str
    (
        "     index|first name| last name|  nickname|phone numb|darkest secret\n"
        "         7|         7|         7|         7|         7|         7\n"
    );
}

Test(PhoneBook, test_PhoneBook_truncString, .init = redirect_all_stdout)
{
    PhoneBook   phoneBook;
    Contact contact;

    std::string result;
        contact.setInfoContact(
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)");
        phoneBook.addContact(contact);

    result = phoneBook.truncString(contact.getFirstName());
    std::cout << result << std::endl;

    cr_assert_stdout_eq_str
    (
        "std::to_s.\n"
    );
}

Test(PhoneBook, test_PhoneBook_DisplayAllContact_with_truncString
                                    , .init = redirect_all_stdout)
{
    PhoneBook   phoneBook;
    Contact contact;

    std::string result;
        contact.setInfoContact(
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)");
        phoneBook.addContact(contact);

    phoneBook.displayAllContact();


    cr_assert_stdout_eq_str
    (
        "     index|first name| last name|  nickname\n"
        "         0|std::to_s.|std::to_s.|std::to_s.\n"
    );
    
}

// char rot13_char(char c)
// {
//     return std::isalpha(c) ? (c - 'a' + 13) % 26 + 'a' : c;
// }

// void rot13_io(void)
// {
//     std::string s;

//     // std::getline(std::cin, s);
//     std::cin >> s;
//     for (size_t i = 0; i < s.length(); ++i)
//         s[i] = rot13_char(s[i]);
//     std::cout << s << std::flush;
// }

// Test(redirect, rot13){//, .init = cr_redirect_stdout) {
//     auto &f_cin = criterion::get_redirected_cin();

    // f_cin << "the quick brown fox jumps over the lazy dog";
    // f_cin.close();

//     rot13_io();

//     // cr_assert_stdout_eq_str("gur dhvpx oebja sbk whzcf bire gur ynml qbt");
// }
