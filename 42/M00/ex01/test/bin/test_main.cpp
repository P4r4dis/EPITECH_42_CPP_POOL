#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

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

// Test(Contact, test_Contact_Getters_and_Setters)
// {
//     {
//         Contact     contact;
//         contact.setFirstName("Mark");
//         contact.setLastName("MarkX");
//         contact.setNickName("AllMark");
//         contact.setPhoneNb("0908070605");
//         contact.setDarkestSecret("secret1");
//         cr_assert(contact.getFirstName() == "Mark");
//         cr_assert(contact.getLastName() == "MarkX");
//         cr_assert(contact.getNickName() == "AllMark");
//         cr_assert(contact.getPhoneNb() == "0908070605");
//         cr_assert(contact.getDarkestSecret() == "secret1");
        
//     }
// }

// Test(PhoneBook, test_PhoneBook_CTOR_DTOR_call)
// {
//     {
//         PhoneBook   phoneBook;

//         cr_assert_not_null(&phoneBook);

//     }
// }

// Test(PhoneBook, test_PhoneBook_getters_and_setters)
// {
//     {
//         PhoneBook   phoneBook;

//         cr_assert(phoneBook.getNbContact() == 0);
//         cr_assert(phoneBook.getPtrContactTab() == nullptr);
//         for (int i = 0; i <= MAX_NB_CONTACT; i++)
//             cr_assert(phoneBook.getContactTab(i) == nullptr);
//     }
// }
// #include <iostream>

// Test(PhoneBook, test_PhoneBook_One_addContact)
// {
//     {
        // auto &f_cin = criterion::get_redirected_cin();
        // PhoneBook   phoneBook;

        // cr_assert(phoneBook.getNbContact() == 0);
        // cr_assert(phoneBook.getPtrContactTab() == nullptr);
        // for (int i = 0; i <= MAX_NB_CONTACT; i++)
        //     cr_assert(phoneBook.getContactTab(i) == nullptr);
        
        // Contact     contact;
        // if (phoneBook.getContactTab(0) == nullptr)
        // {
        //         f_cin << "0";
        //         f_cin.close();
        //         std::string name;
        //         std::cin >> name;
        //         contact.setFirstName(name);
        //         phoneBook.setContact(&contact);
        // }
        // for (int i = 0; i < MAX_NB_CONTACT; ++i)
        // {
        //     if (phoneBook.getContactTab(i) != nullptr)
        //     {
        //         cr_assert(phoneBook.getContactTab(i) != nullptr);
        //         std::cout   << "Verify: " 
        //                     << phoneBook.getContactTab(0)->getFirstName() 
        //                     << std::endl;
        //     }
        // }
    // }
// }

// Test(PhoneBook, test_PhoneBook_getContactArray)//, .init = redirect_all_stdout)
// {
//     // {
//         PhoneBook   phoneBook;

//         cr_assert(phoneBook.getNbContact() == 0);
//         Contact contact;

//         contact.setInfoContact("0", "0", "0", "0", "0");
//         phoneBook.addContact(contact);
//         // contact.setInfoContact("1", "1", "1", "1", "1");
//         // phoneBook.addContact(contact);
//         // contact.setInfoContact("2", "2", "2", "2", "2");
//         // phoneBook.addContact(contact);
//         // contact.setInfoContact("3", "3", "3", "3", "3");
//         // phoneBook.addContact(contact);
//         // contact.setInfoContact("4", "4", "4", "4", "4");
//         // phoneBook.addContact(contact);
//         // contact.setInfoContact("5", "5", "5", "5", "5");
//         // phoneBook.addContact(contact);
//         // contact.setInfoContact("6", "6", "6", "6", "6");
//         // phoneBook.addContact(contact);
//         // contact.setInfoContact("7", "7", "7", "7", "7");
//         // phoneBook.addContact(contact);

//         for (int  i = 0; i < phoneBook.getNbContact() + 1; i++)
//         {
//             std::cout << phoneBook.getContactArray(i).getFirstName() << std::endl;
//         }

//     // }
//     // cr_assert_stdout_eq_str
//     // (
//     //     "PhoneBook Constructor created\n"
//     //     "PhoneBook Destructor called\n"
//     // );
// }


// Test(PhoneBook, test_PhoneBook_process, .init = redirect_all_stdout)
// {
//     {
//         auto &f_cin = criterion::get_redirected_cin();
//         PhoneBook      phoneBook;
//         std::string    command;

//         f_cin << "exit";
//         f_cin.close();
//         std::cout << "Program starting." << std::endl;
//         std::cout << "Phonebook is open." << std::endl;
//         std::cout << "Command available: ADD | SEARCH | EXIT" << std::endl;
//         // phoneBook.process(commande);
//         while (command != "EXIT")
//         {
//             std::cin >> command;
//             for (size_t i = 0; i < command.length(); i++)
//                 command[i] = std::toupper(command[i]);
//             if (command != "ADD" && command != "SEARCH" && command != "EXIT")
//                     std::cout << "Wrong command\nCommand available: ADD | SEARCH | EXIT" << std::endl;
//             else if (command == "SEARCH")
//                 std::cout << "SEARCH COMMAND not implemented" << std::endl;
//             else if (command == "ADD")
//                 std::cout << "ADD COMMAND not implemented" << std::endl;
//         }
//         std::cout << "End of program." << std::endl;
//     }
//     cr_assert_stdout_eq_str
//     (
//         "PhoneBook Constructor created\n"
//         "Program starting.\n"
//         "Phonebook is open.\n"
//         "Command available: ADD | SEARCH | EXIT\n"
//         // "Wrong command\nCommand available: ADD | SEARCH | EXIT\n"
//         // "SEARCH COMMAND not implemented\n"
//         // "ADD COMMAND not implemented\n"
//         "End of program.\n"
//         "PhoneBook Destructor called\n"
//     );
// }


// Test(PhoneBook, test_PhoneBook_process)//, .init = redirect_all_stdout)
// {
//     {
//         PhoneBook      phoneBook;
//         Contact         contact0("Jhon0", "Doe0", "JhonSnow0", "0002030405", "secret0");
//         Contact         contact1("Jhon1", "Doe2", "JhonSnow1", "0102030405", "secret1");
//         Contact         contact2("Jhon2", "Doe2", "JhonSnow2", "0202030405", "secret2");
//         Contact         contact3("Jhon3", "Doe3", "JhonSnow3", "0302030405", "secret3");
//         Contact         contact4("Jhon4", "Doe4", "JhonSnow4", "0402030405", "secret4");
//         Contact         contact5("Jhon5", "Doe5", "JhonSnow5", "0502030405", "secret5");
//         Contact         contact6("Jhon6", "Doe6", "JhonSnow6", "0602030405", "secret6");
//         Contact         contact7("Jhon7", "Doe7", "JhonSnow7", "0702030405", "secret7");
//         Contact         contact8("Jhon8", "Doe8", "JhonSnow8", "0802030405", "secret8");
//         phoneBook.addContact(contact0);
//         for (int i = 0; i <= MAX_NB_CONTACT; i++)
//         {
//             std::cout   << phoneBook.getContactArray().getFirstName() << " | "
//                         << phoneBook.getContactArray().getLastName() << " | "
//                         << phoneBook.getContactArray().getNickName() << " | "
//                         << phoneBook.getContactArray().getPhoneNb() << " | "
//                         << phoneBook.getContactArray().getDarkestSecret() << " | "
//                         << std::endl;
//         }
//     }
    // cr_assert_stdout_eq_str
    // (
    //     "PhoneBook Constructor created\n"
        // "Program starting.\n"
        // "Phonebook is open.\n"
        // "Command available: ADD | SEARCH | EXIT\n"
        // "Wrong command\nCommand available: ADD | SEARCH | EXIT\n"
        // "SEARCH COMMAND not implemented\n"
        // "ADD COMMAND not implemented\n"
        // "End of program.\n"
    //     "PhoneBook Destructor called\n"
    // );
// }

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
