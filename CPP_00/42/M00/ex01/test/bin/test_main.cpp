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

Test(Contact, test_Contact_getFirstName_isEmpty)
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

Test(Contact, test_Contact_getLastName_isEmpty)
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

Test(Contact, test_Contact_getNickName_isEmpty)
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

Test(Contact, test_Contact_getPhoneNb_isEmpty)
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

Test(Contact, test_Contact_getDarkestSecret_isEmpty)
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

Test(PhoneBook, test_PhoneBook_setNbContact)
{
    {
        PhoneBook   phoneBook;

        cr_assert(phoneBook.getNbContact() == 0);
        phoneBook.setNbContact(5);
        cr_assert(phoneBook.getNbContact() == 5);
    }
}

Test(PhoneBook, test_PhoneBook_getContactTab)
{
    {
        PhoneBook   phoneBook;
        const Contact *contactTab = nullptr;
        contactTab = phoneBook.getContactTab();
        for (int i = 0; i < MAX_NB_CONTACT; ++i)
            cr_assert(not(zero(type(const Contact *), &contactTab[i])));
    }
}

Test(PhoneBook, test_PhoneBook_setContactTab)
{
    {
        PhoneBook phoneBook;
        Contact contact;

        for (int i = 0; i < MAX_NB_CONTACT; ++i)
            contact.setInfoContact("Contact",
                                    "Contact",
                                    "Contact",
                                    "Contact",
                                    "Contact");
        phoneBook.addContact(contact);
        cr_assert(phoneBook.getContactTab()->getFirstName() == "Contact");
        Contact newContactTab[MAX_NB_CONTACT];
        phoneBook.setContactTab(newContactTab);
        cr_assert(phoneBook.getContactTab()->getFirstName() != "Contact");
        cr_assert(phoneBook.getContactTab()->getFirstName() == "");
    } 
}

Test(PhoneBook, test_PhoneBook_fillContact, .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        Contact     contact;
        std::string input;
        auto &f_cin = criterion::get_redirected_cin();
        std::string firstName = "JhonMalkovitches\n";
        std::string lastName = "DupontMalkovitches\n";
        std::string nickname = "pseudonyme\n";
        std::string phoneNumber = "0102030405\n";
        std::string darkSecret = "i know the kungfu\n";

        f_cin   << firstName + lastName + nickname + phoneNumber + darkSecret;
        f_cin.close();
        contact = phoneBook.fillContact(contact, input);
        cr_assert(contact.getFirstName() == "JhonMalkovitches");
        cr_assert(contact.getLastName() == "DupontMalkovitches");
        cr_assert(contact.getNickName() == "pseudonyme");
        cr_assert(contact.getPhoneNb() == "0102030405");
        cr_assert(contact.getDarkestSecret() == "i know the kungfu");
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
        Contact     contact;

        cr_assert(phoneBook.getIndex() == 0);
        contact.setInfoContact("0", "0", "0", "0", "0");
        phoneBook.addContact(contact);
        cr_assert(phoneBook.getIndex() == 1);
    }
}

Test(PhoneBook, test_PhoneBook_setIndex)
{
    {
        PhoneBook   phoneBook;

        cr_assert(phoneBook.getIndex() == 0);
        phoneBook.setIndex(5);
        cr_assert(phoneBook.getIndex() == 5);
    }
}

Test(PhoneBook, test_PhoneBook_validindex_invalid_input, .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        auto &f_cin = criterion::get_redirected_cin();
        std::string index = "00fsdafads0\n";
        std::string index2 = "0\n";

        f_cin   << index + index2;
        f_cin.close();
        cr_assert(phoneBook.validIndex(index) == std::stoi(index2));
        cr_assert_stdout_eq_str
        (
            "Enter the contact index you wish to display:\n"
            "Invalid input. Please enter a number.\n"
            "Enter the contact index you wish to display:\n"
        );
    }
}

Test(PhoneBook, test_PhoneBook_validindex_input_outOfRange
                            , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        auto &f_cin = criterion::get_redirected_cin();
        std::string index = "100\n";
        std::string index3 = "0\n";

        f_cin   << index + index3;
        f_cin.close();
        
        cr_assert(phoneBook.validIndex(index) == std::stoi(index3));
        cr_assert_stdout_eq_str
        (
            "Enter the contact index you wish to display:\n"
            "Index out of range. Please try again.\n"
            "Enter the contact index you wish to display:\n"
        );
    }
}

Test(PhoneBook, test_PhoneBook_search_isDefined, .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        std::string index = "0";
        
        phoneBook.search(index);
        cr_assert_stdout_eq_str
        (
            "     index|first name| last name|  nickname\n"
        );
    }
}

Test(PhoneBook, test_PhoneBook_search, .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        Contact     contact;
        auto &f_cin = criterion::get_redirected_cin();
        std::string index = "0\n";

        contact.setInfoContact("0", "0", "0", "0", "0");
        phoneBook.addContact(contact);
        f_cin   << index;
        f_cin.close();
        phoneBook.search(index);
        cr_assert_stdout_eq_str
        (
            "     index|first name| last name|  nickname\n"
            "         0|         0|         0|         0\n"
            "Enter the contact index you wish to display:\n"
            "index: 0\n"
            "first name: 0\n"
            "last name: 0\n"
            "nickname: 0\n"
            "phone number: 0\n"
            "darkest secret: 0\n"
        );
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
    Contact     contact;

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
    Contact     contact;

    int index = 7;
    for (int i = 0 ; i < MAX_NB_CONTACT; i++)
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
        "index: 7\n"
        "first name: 7\n"
        "last name: 7\n"
        "nickname: 7\n"
        "phone number: 7\n"
        "darkest secret: 7\n"
    );
}

Test(PhoneBook, test_PhoneBook_displayContact_not_enregistered
                , .init = redirect_all_stdout)
{
    PhoneBook   phoneBook;
    Contact     contact;

    int index = 7;
    for (int i = 0 ; i < 5; i++)
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
        "There is no contact enregistered to this index.\n"
    );
}


Test(PhoneBook, test_PhoneBook_truncString, .init = redirect_all_stdout)
{
    PhoneBook   phoneBook;
    Contact     contact;
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
    Contact     contact;

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


Test(PhoneBook, test_PhoneBook_exit_isDefined
                        , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;

        phoneBook.exit();
        cr_assert_stdout_eq_str
        (
            ""
        );
    }
}

Test(PhoneBook, test_PhoneBook_exit_deleteAllContact
                        , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        Contact     contact;

        contact.setInfoContact(
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)", 
            "std::to_string(i)");
        phoneBook.addContact(contact);
        phoneBook.displayAllContact();
        phoneBook.exit();
        phoneBook.displayAllContact();
        cr_assert_stdout_eq_str
        (
            "     index|first name| last name|  nickname\n"
            "         0|std::to_s.|std::to_s.|std::to_s.\n"
            "     index|first name| last name|  nickname\n"
        );
    }
}


Test(PhoneBook, test_PhoneBook_uppercase_isDefined)
{
    {
        PhoneBook   phoneBook;

        std::string str = "hello";
        phoneBook.uppercase(str);
    }
}

Test(PhoneBook, test_PhoneBook_uppercase, .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        std::string str = "hello""";

        std::cout << phoneBook.uppercase(str) << std::endl;
        cr_assert_stdout_eq_str("HELLO\n");
    }
}

Test(PhoneBook, test_PhoneBook_handleInput_with_bad_input
                            , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;

        phoneBook.handleInput("test");
        cr_assert_stdout_eq_str
        (
            "Bad input, choose command: ADD | SEARCH | EXIT\n"
        );
    }
}

Test(PhoneBook, test_PhoneBook_handleInput_with_ADD_input
                            , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;

        phoneBook.handleInput("add");
        cr_assert_stdout_eq_str
        (
            ""
        );
    }
}

Test(PhoneBook, test_PhoneBook_handleInput_with_SEARCH_input
                                , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;

        phoneBook.handleInput("search");
        cr_assert_stdout_eq_str
        (
            ""
        );
    }
}

Test(PhoneBook, test_PhoneBook_handleInput_with_EXIT_input
                            , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;

        phoneBook.handleInput("exit");
        cr_assert_stdout_eq_str
        (
            ""
        );
    }
}

Test(PhoneBook, test_PhoneBook_runProcess_ADD_with_EXIT
                            , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        auto &f_cin = criterion::get_redirected_cin();
        std::string addCommand = "add\n";
        std::string exitCommand = "exit\n";
        std::string index = "0\n";
        std::string firstName = "JhonMalkovitches\n";
        std::string lastName = "DupontMalkovitches\n";
        std::string nickname = "pseudonyme\n";
        std::string phoneNumber = "0102030405\n";
        std::string darkSecret = "i know the kungfu\n";

        f_cin   << addCommand + firstName + lastName + nickname + phoneNumber + darkSecret + exitCommand + exitCommand;
        f_cin.close();
        phoneBook.runProcess();
        cr_assert_stdout_eq_str
        (
            "Enter First Name:\n"
            "JhonMalkovitches\n"
            "Enter Last Name:\n"
            "DupontMalkovitches\n"
            "Enter Nickname:\n"
            "pseudonyme\n"
            "Enter Phone number:\n"
            "0102030405\n"
            "Enter Darkest secret:\n"
            "i know the kungfu\n"
        );
    }
}

Test(PhoneBook, test_PhoneBook_runProcess_ADD_SEARCH_EXIT
                            , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        auto &f_cin = criterion::get_redirected_cin();
        std::string addCommand = "add\n";
        std::string searchCommand = "search\n";
        std::string exitCommand = "exit\n";
        std::string index = "0\n";
        std::string firstName = "JhonMalkovitches\n";
        std::string lastName = "DupontMalkovitches\n";
        std::string nickname = "pseudonyme\n";
        std::string phoneNumber = "0102030405\n";
        std::string darkSecret = "i know the kungfu\n";

        f_cin   << addCommand + firstName + lastName + nickname + phoneNumber + darkSecret + searchCommand + index + exitCommand + searchCommand + exitCommand + exitCommand;
        f_cin.close();
        phoneBook.runProcess();
        cr_assert_stdout_eq_str
        (
            "Enter First Name:\n"
            "JhonMalkovitches\n"
            "Enter Last Name:\n"
            "DupontMalkovitches\n"
            "Enter Nickname:\n"
            "pseudonyme\n"
            "Enter Phone number:\n"
            "0102030405\n"
            "Enter Darkest secret:\n"
            "i know the kungfu\n"
            "     index|first name| last name|  nickname\n"
            "         0|JhonMalko.|DupontMal.|pseudonym.\n"
            "Enter the contact index you wish to display:\n"
            "index: 0\n"
            "first name: JhonMalkovitches\n"
            "last name: DupontMalkovitches\n"
            "nickname: pseudonyme\n"
            "phone number: 0102030405\n"
            "darkest secret: i know the kungfu\n"
            "     index|first name| last name|  nickname\n"
        );
    }
}

// not finished
Test(PhoneBook, test_PhoneBook_process_with_ADD_input
                        , .init = redirect_all_stdout)
{
    {
        PhoneBook   phoneBook;
        auto &f_cin = criterion::get_redirected_cin();
        std::string addCommand = "add\n";
        std::string searchCommand = "search\n";
        std::string exitCommand = "exit\n";
        std::string index = "0\n";
        std::string firstName = "JhonMalkovitches\n";
        std::string lastName = "DupontMalkovitches\n";
        std::string nickname = "pseudonyme\n";
        std::string phoneNumber = "0102030405\n";
        std::string darkSecret = "i know the kungfu\n";

        f_cin   << addCommand + firstName + lastName + nickname + phoneNumber + darkSecret + searchCommand + index + exitCommand + searchCommand + exitCommand + exitCommand;
        f_cin.close();
        phoneBook.process();
        cr_assert_stdout_eq_str
        (
            "PHONEBOOK starting...\n"
            "Choose command: ADD | SEARCH | EXIT\n"
            "Enter First Name:\n"
            "JhonMalkovitches\n"
            "Enter Last Name:\n"
            "DupontMalkovitches\n"
            "Enter Nickname:\n"
            "pseudonyme\n"
            "Enter Phone number:\n"
            "0102030405\n"
            "Enter Darkest secret:\n"
            "i know the kungfu\n"
            "     index|first name| last name|  nickname\n"
            "         0|JhonMalko.|DupontMal.|pseudonym.\n"
            "Enter the contact index you wish to display:\n"
            "index: 0\n"
            "first name: JhonMalkovitches\n"
            "last name: DupontMalkovitches\n"
            "nickname: pseudonyme\n"
            "phone number: 0102030405\n"
            "darkest secret: i know the kungfu\n"
            "     index|first name| last name|  nickname\n"
            "Program end\n"
        );
    }
}