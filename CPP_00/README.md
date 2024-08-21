
# CPP Pool for 42 and EPITECH school
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

For Epitech CPP begins to Day 06 before we continue to work with C / C modular.
For 42 school, CPP starts to Day 00.
With a series of exercises we will learning different C++ concepts.
___

## Table Of Contents

* [Setup CPP and Criterion](#setup-cpp-and-criterion)  
* [Description](#description)
* [Objectifs](#objectifs)
    * [42 Module 00 Objectifs](#42-module-00-objectifs)
    * [EPITECH Day 06 Objectifs](#epitech-day-06-objectifs)
* [Key Learnings](#key-learnings)
    * [Input/Output](#inputoutput)
* [Lessons](#lessons)
* [Installation](#installation)
* [Usage / Examples](#usage-/-examples)
* [Running Tests](#running-tests)

___
___

## Setup CPP and Criterion
[(Back to top)](#table-of-contents)

* __Prerequisites__
    * The library is supported on Linux, macOS, FreeBSD, and Windows.
    * The following compilers are supported to compile both the library and the tests:
        * GCC 4.9+ (Can be relaxed to GCC 4.6+ when not using C++)
        * Clang 3.4+
        * MSVC 14+ (Included in Visual Studio 2015 or later)
* __Building from source__
    * First, install dependencies:
        * C/C++ compiler
        * Meson, Ninja
        * CMake (for subprojects)
        * pkg-config
        * libffi (libffi-dev)
        * libgit2 (libgit2-dev __version: libgit2-1:*5.1-2, new version doesn't work__)
        * Other runtime dependencies will be bundled if they are not available on the system (BoxFort, debugbreak, klib, nanomsg, nanopb).
    * Clone this repository:
        * ```bash
            $ git clone --recursive https://github.com/Snaipe/Criterion
    * Then, run the following commands to build Criterion:
    
        * ```bash
            $ meson build
            $ ninja -C build
    * Installing the library and language files (Linux, macOS, FreeBSD)
    * Run with an elevated shell:
        * ```bash
            $ ninja -C build install
    * On Linux systems, update the dynamic linker runtime bindings:
        * ```bash
            $ ldconfig
    * Usage
        * To compile your tests with Criterion, you need to make sure to:
            * Add the include directory to the header search path
            * Install the library to your library search path
            * Link Criterion to your executable.

This should be all you need.

Sources:
*   https://github.com/Snaipe/Criterion
*   https://criterion.readthedocs.io/en/v2.2.1/index.html#
*   https://epitech-2022-technical-documentation.readthedocs.io/en/latest/index.html
___

## Description
[(Back to top)](#table-of-contents)

These modules are designed to introduce you to Object-Oriented Programming.
Several languages are recommended for learning OOP. Because it is
derived from your good old friend C, we have chosen the C++ language.

* __Compiling__
    * Compile your code with c++ and the flags __-Wall -Wextra -Werror__
    * Your code should compile if you add the flag __-std=c++98__ ~~but personnaly i will use the last version of C++ with the flag __-std=c++23__~~.
    * Format and naming conventions- The exercise folders will be named as follows: __ex00, ex01, ..., exn__
    * Name your __files, classes, functions, member functions and attributes__ as specified in the instructions:
        * Write your class names in __UpperCamelCase__ format.
        * Files containing the code for a class will use the name of the class. For example:
            * __ClassName.hpp/ClassName.h, ClassName.cpp...__
            * So if a header file contains the definition of a __"BrickWall"__ class, its name will be __BrickWall.hpp__.
    * Unless otherwise specified, all messages must be terminated by a __carriage return__ and be displayed on __standard output__.

* __What's allowed and what isn't__
    * You can use almost the entire __standard library__. So rather than sticking to familiar ground, try to use as many C++ versions of the C++ versions of the C functions you're used to.
    * However, you cannot use any other __external library__.
    * Certain functions remain __prohibited__. Using the following functions will result in a score of 0: __*printf(), *alloc(), open(), fopen(), and free()__.
    * Unless explicitly stated otherwise, the keywords using __namespace <ns_name>__ and __friend__ keywords are __prohibited__.
    * You are only allowed to use the __STL later__. Until then, the use of __Containers (vector/list/map/etc.) and Algorithms (anything that requires to include <algorithm>) is prohibited.__

* __Design requirements__
    * Memory leaks also exist in C++. When you allocate memory (using the __new__ keyword), __you must not have any memory leaks__.
    * Your classes must conform to the __canonical form__, in other word, __Coplien form__ unless explicitly specified otherwise.
    * A function implemented in a header file (except in the case of a template) will be given a score of 0.
    * You must be able to use your header files separately from each other.
    This is why they must include all the dependencies they require necessary. However, __you should avoid the problem of double inclusion by protecting them with include guards.__

---


## Objectifs
[(Back to top)](#table-of-contents)

#### 42 Module 00 Objectifs
[(Back to top)](#table-of-contents)

*   | ex00                  | Megaphone                 |
    | -------               | --------                  |
    | Turn-in directory     | ex00/                     |
    | Files to turn-in      | Makefile, Megaphone.cpp   |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |

    To make sure everyone is awake, write a program that behaves as follows:
    ```
    $>./megaphone "shhhhh... I think the students are asleep..."
    SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
    $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
    DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
    $>./megaphone
    * LOUD AND UNBEARABLE FEEDBACK NOISE *
    $>
    ```
    ___
*   | ex01                  | My Awesome PhoneBook      |
    | -------               | --------                  |
    | Turn-in directory     | ex01/                     |
    | Files to turn-in      | Makefile, *.cpp, *.hpp    |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |

    Welcome in the 80s and its unbelievable technology !
    * Write a program that behaves like a crappy awesome phonebook software. Please take some time to give your executable a relevant name.
    * When the program starts, the user is prompted for input: you should accept the __ADD command__, the __SEARCH command__ or the __EXIT command__. Any other input is discarded.
    * The program __starts empty (no contacts)__, __doesn’t use any dynamic allocation__ and can’t store more than __8 contacts__. If the user tries to add a 9th contact, replace the oldest with this one.
    * If the command is __EXIT__:
        * The program quits and the contacts are lost forever.
    * Else if the command is __ADD__:
        * The program will prompt the user to __input a new contact’s informations__, one field at a time, until every field is accounted for.
        * A contact is defined by the following fields : __first name, last name, nickname, login, postal address, email address, phone number, birthday date, favorite meal, underwear color and darkest secret__.
        * A contact __MUST__ be represented as an __instance of a class__ in your code. You’re free to design the class as you like, but the peer evaluation will check the consistency of your choices. Go look at today’s videos again if you don’t understand what I mean (and I don’t mean "use everything" before you ask).
    * Else if the command is __SEARCH__:
        * The program will display a list of the available non-empty contacts in 4 columns : __index, first name, last name and nickname__.
        * Each column __must be 10 chars wide, right aligned and separated by a ’|’ character__. Any output longer than the columns’ width is truncated and the last displayable character is replaced by a dot (’.’).
        * Then the program will prompt again for the index of the desired entry and displays the contact’s information, one field per line. If the input makes no sense, define a relevant behavior.
    * Else the input is __discarded__.
    * When a command has been correctly executed, the program waits for another __ADD or SEARCH command until an EXIT command__.
    * Once done, ask students around you to test your ADD command. That way you’ll know their darkest secret by using the SEARCH command after they left, which is obviously the only relevant part of this exercice. They will have no clue of your evil plot, huehehe.
    ___

*   | ex02                  | The Job Of Your Dreams    |
    | -------               | --------                  |
    | Turn-in directory     | ex02/                     |
    | Files to turn-in      | Makefile, Account.cpp, Account.hpp, tests.cpp    |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    * It's your first day at _GlobalBanksters United_. 
    After successfully completing the various recruitment process (thanks to this friend who had the good idea of showing you some _Microsoft Office_ tips), you've joined the dev team.
    You know that your lightning installation of _Adobe Reader_ made a big impression.
    This little extra made all the difference and enabled you to beat your enemies (yes, the other candidates)! You've done it!
    * That's not all, but your manager has just given you a job. 
    Your first mission: to __recreate a missing file__. Something has gone wrong and a source file has been deleted by mistake.
    Unfortunately, your colleagues don't know Git and are using USB sticks to share the code.
    It would make sense to get out of there now.
    Despite this, you decide to stay and take up the challenge.
    * You are sent some files. Compiling __tests.cpp__ confirms that the missing is __Account.cpp__.
    Fortunately, the header file __Account.hpp__ is unharmed, as is a __log file__.
    Perhaps you could use the latter to understand how the Account (bank account) class was implemented.
    * You start to __remake the Account.cpp file__. In just a few minutes, you typed out some genius lines of C++.
    After a few failed compilations, your program passes the tests. Its output corresponds perfectly to that contained in the log (except for the __timestamp__, which is bound to be different because the tests saved in the log were run long before you arrived).
    Bloody hell, what a talent!

#### EPITECH Day 06 Objectifs
[(Back to top)](#table-of-contents)

__Exercise 00 - IOStream__
*   | ex00                  | my_cat                    |
    | -------               | --------                  |
    | Turn-in directory     | ex00/                     |
    | Files to turn-in      | Makefile, myCat.cpp       |
    | Forbidden functions   | None                      |
    | Remarks               | You must turn in your complete program, including your main function.<br>Your Makefile must generate a my_cat executable.|


    *   __Write a simplified `cat(1)` command.__
    *   Your executable must take __one or several files as parameters__, and does not  need to handle the special case of the standard input.
    *   Upon error (__file not found, permission denied, etc.__), you must write the following message to the error output:
    `my_cat: file: No such file or directory`
        *   __file must be replaced with the name of the file for which the error was encountered.__
    *   If no parameter is passed to your program, you must write the following message to the error output:
    `my_cat: Usage: ./ my_cat file [...]`

___

__Exercise 01 - Temperature Conversion__
*   | ex01                  | my_convert_temp           |
    | -------               | --------                  |
    | Turn-in directory     | ex01/                     |
    | Files to turn-in      | Makefile, MyConvertTemp.cpp |
    | Forbidden functions   | None                      |
    | Remarks               | You must turn in your complete program, including your main function.<br>Your Makefile must generate a my_convert_temp executable.|

    *   The purpose of this exercise is to write a program that converts temperatures from the Celsius scale to the Fahrenheit scale, and vice-versa.
    *   The __conversion formula__ to use is the following (we know, it isn’t the exact right one!):
    __Celsius = 5.0 / 9.0 * ( Fahrenheit - 32 )__
    *   Your program must read from its standard input (separated by one or more spaces):
        *   A temperature
        *   A scale
    *   Any additional input must be ignored.
    ```
    ∼/B-PDG-300> ./my_convert_temp << EOF
    -10 Celsius
    EOF
             14.000      Fahrenheit
    ∼/B-PDG-300> ./my_convert_temp << EOF
    46.400 Fahrenheit
    EOF
              8.000         Celsius
    ```
    *   Results must be displayed within __two columns, right-aligned__ with a __padding of 16 composed of spaces__ and a __precision to the 1000th__.
___

__Exercise 2 - The Patient__
*   | ex02                  | patient                   |
    | -------               | --------                  |
    | Turn-in directory     | ex02/                     |
    | Files to turn-in      | Makefile<br>SickKoala.hpp, SickKoala.cpp |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |

    *   You are now working on a simulation of your dear Koalas’ health.
        To get started, you’ll need patients to treat.
    *   Therefore, it is time to __create a SickKoala class__.
    *   Here are the information you need to implement this class:
        *   They can’t be instantiated without a name `string`
        *   Following their destruction, the __standard output__ must display:
            `Mr.[name]: Kreooogg!! I'm cuuuured!`
        *   A `poke` member function taking no parameters or return value and displaying the following when called:
            `Mr.[name]: Gooeeeeerrk!!`
        *   A `takeDrug` function taking a `string` as parameter and returning `true` if the `string` matches `Mars` or `Kinder` (case sensitive).
            *   The function must then display, respectively:
                `Mr.[name]: Mars, and it kreogs!`
                or
                `Mr.[name]: There is a toy inside!`
            *   In any other case, the function returns false and displays:
                `Mr.[name]: Goerkreog!`
        *   Sometimes, `SickKoalas` go crazy when their fever is too high.
            To simulate this, `SickKoalas` have an `overDrive` member function that returns nothing and takes a `string` as parameter.
            It displays the `string` passed as parameter, preceded by "`Mr.[name]: `", within which all occurences of "`Kreog!`" are replaced by "`1337!`".
            *   For instance:
                `Kreog! How's it going?`
                becomes:
                `Mr.[name]: 1337! How's it going?`
    *   For all outputs in this exercise, `[name]` must be replaced by the name of the `SickKoala`
___

__Exercise 03 - The Nurse__
*   | ex03                  | nurse                     |
    | -------               | --------                  |
    | Turn-in directory     | ex03/                     |
    | Files to turn-in      | Makefile<br>SickKoala.hpp, SickKoala.cpp<br>KoalaNurse.hpp, KoalaNurse.cpp |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |

    *   Now that we have patients, we need a nurse to take care of them.
        You are now coding the nurse for the koala: __the `KoalaNurse` class__.
        Here is the information you need in order to create the `KoalaNurse`:
        *   Each `KoalaNurse` has a numerical identifier (ID) which must be provided when the object is created, but it is not possible to create a nurse without specifying her ID.
        *   When a `KoalaNurse` is destroyed, it’ll express its relief like so:
            `Nurse [ID]: Finally some rest!`
        *   The nurse can give drugs to patients, through a `giveDrug` member function with the following parameters a `string` (Drug) and a `pointer` to the patient.
            This member function does not return anything.
            When it is called, the nurse gives medication to the patient.
        *   The nurse can read the doctor’s report through a `readReport` member function that takes a filename `string` as parameter:
            *   The filename is built from the sick Koala’s name, followed by the `.report` extension.
            *   The file contains the name of the drug to give to the patient.
            *   This member function returns the name of the drug as a `string` and prints the following to the standard output:
                `Nurse [ID]: Kreog! Mr.[patientName] needs a [drugName]!`
                *   If the .report file doesn’t exist or is not valid, nothing must be displayed and the return value must be an empty `string`.
        *   The nurse can clock in thanks to a `timeCheck` member function that takes no parameter and doesn’t return anything.
            The nurse calls this member function when it starts working and when it stops working (as it is a very diligent worker).
            *   When it clocks in at the start of her job, it says:
                `Nurse [ID]: Time to get to work!`
            *   When it stops working, it says:
                `Nurse [ID]: Time to go home to my eucalyptus forest!`
            *   It is up to you to figure out a way to find out when it starts and stops working.
            *   By default, when the program starts, the nurse is not working yet.
            *   The `KoalaNurse` being very diligent, it will take any job. Even outsided the hospital.
            *   Only a call to the `timeCheck` member function lets the `KoalaNurse` change her working status: if it is not working, it starts to work; if it is working, it stops.
    *   In this exercise, `[ID]` must be replaced with the `KoalaNurse’s ID` in any output.
___

__Exercise 04 - The Doctor__
*   | ex04                  | doctor                     |
    | -------               | --------                  |
    | Turn-in directory     | ex04/                     |
    | Files to turn-in      | Makefile<br>SickKoala.hpp/cpp<br>KoalaNurse.hpp/cpp<br>KoalaDoctor.hpp/cpp |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |

    *   Before we get started, add a `getName` member function to the `SickKoala` class, taking no parameters and returning the name of the patient as a `string`.
    *   We now have patients and nurses taking care of them.
        We still need a doctor to give instructions to the nurses.
       __Implement a simulation of the doctor__ with the `KoalaDoctor` class.
        Here’s what we know about the KoalaDoctor:
        *   It must be instantiated with a name `string`.
            During construction, it must print the following to the standard output:
            `Dr.[name]: I'm Dr.[name]! How do you kreog?`
        *   It can diagnose patients using the `diagnose` member function that takes a `pointer` to the patient to diagnose as parameter.
            *   This member function prints the following to the standard output:
                `Dr.[name]: So what's goerking you Mr.[patientName]?`
            *   It then calls the `poke` member function of the `SickKoala`.
            *   The doctor then writes a report for nurses, in a file named `[patientname].report`.
            *   This file contains the name of the drug to give to the patient. The name will be picked at random from the following list:
                *   Mars
                *   Kinder
                *   Crunch
                *   Maroilles
                *   Eucalyptus leaf
                    *   To do this, you must use `random()% 5` on the previous list, in the given order.
                    The `srandom` function will be called by the correction main.
        *   The KoalaDoctor clocks in through a `timeCheck` member function, which takes no parameters and does not return anything.
            *   When it starts working, it says:
                `Dr.[name]: Time to get to work!`
            *   When it stops working, it says:
                `Dr.[name]: Time to go home to my eucalyptus forest!`
        *   The `KoalaDoctor` being very diligent, it will take any job. Even outside the hospital.
    *   In this exercise, any occurence of `[name]` must be replaced with the name of the `KoalaDoctor`, and occurences of `[patientName]` must be replaced with the name of the `SickKoala` that is currently being treated.

___

__Exercise 05 - Lists__
*   | ex05                  | list                     |
    | -------               | --------                  |
    | Turn-in directory     | ex05/                     |
    | Files to turn-in      | Makefile<br>SickKoala.hpp/cpp<br>KoalaNurse.hpp/cpp<br>KoalaDoctor.hpp/cpp<br>SickKoalaList.hpp/cpp<br>KoalaNurseList.hpp/cpp<br>KoalaDoctorList.hpp/cpp |
    | Forbidden functions   | None                      |
    | Remarks               | Recursive programming can save you a lot of development time... |

    *   Before we get started, modify your `KoalaNurse` and `KoalaDoctor` classes:
        *   Add a `getID` member function to the `KoalaNurse` class.
            *   This function takes no parameter and returns an `int`.
        *   Add a `getName` member function to the `KoalaDoctor` class.
            *   This function takes no parameter and returns a `string`.
    *   We now need to watch over all these people working together in harmony.
        It is necessary to be able to handle several patients, doctors and/or nurses at the same time.
        To do so, we need a list for each of these categories.
    *   For this exercise, a node of a list is a `List *object`.
    *   __Implement the 3 following classes__:
        *   __SickKoalaList__
            *   Takes a `pointer` to a `SickKoala` as a constructor parameter.
                *   This `pointer` can be a `nullptr`.
            *   Has an `isEnd` member function which takes no parameter and returns a boolean set to `true` if the `SickKoalaList` is the last node of its list.
            *   Has an `append` member function which takes a `pointer` to a `SickKoalaList` as a parameter and does not return anything.
                *   The node passed as parameter is added to the end of the linked list.
            *   Has a `getFromName` member function which takes a `string` as a parameter and returns a `pointer` to the first `SickKoala` in the list whose name matches that `string`.
            *   Has a `remove` member function which takes a `pointer` to a `SickKoalaList` as a parameter and removes the `SickKoalaList` matching this `pointer` from the list.
                *   It returns a `pointer` to the first node of the list.
            *   Has a `removeFromName` member function which takes a `string` as a parameter and removes the first `SickKoalaList` whose content’s name matches that `string` from the list.
                *   It returns a `pointer` to the first node of the list.
            *   Has a `getContent` member function which takes no parameter and returns a `pointer` to the element held in the current instance.
            *   Has a `getNext` member function which takes no parameter and returns a `pointer` to the next node of the list.
                *   If there is no such node, the function returns a `nullptr`.
            *   Has a `dump` member function which takes no parameter and does not return anything.
                *   It displays the name of all the `SickKoalas` in the list in order (begin -> end):
                    `Patients: name1 , name2 , ..., nameX.`
                *   If an element is missing, the name to display is `[nullptr]`.
        <br>
        <br>
        <br>
        *   __KoalaNurseList__
            *   Takes a `pointer` to a `KoalaNurse` as a constructor parameter.
                *   This `pointer` can be a `nullptr`.
            *   Has an `isEnd` member function which takes no parameter and returns a boolean set to `true` if the `KoalaNurseList` is the last node of its list.
            *   Has an `append` member function which takes a `pointer` to a `KoalaNurseList` as a parameter and does not return anything.
                *   The node passed as parameter is added to the end of the linked list.
            *   Has a `getFromID` member function which takes an int as a parameter and returns a `pointer` to the first `KoalaNurse` in the list whose ID matches that `int`.
            *   Has a `remove` member function which takes a `pointer` to a `KoalaNurseList` and removes the `KoalaNurseList` matching this `pointer` from the list.
                *   It returns a `pointer` to the first node of the list.
            *   Has a `removeFromID` member function which takes an `int` as parameter and removes the first `KoalaNurseList` whose content’s ID matches that `int` from the list.
                *   It returns a `pointer` to the first node of the list.
            *   Has a `dump` member function which takes no parameter and does not return anything.
                *   It displays the ID of all the `KoalaNurses` in the list in order (begin -> end):
                    `Nurses: id1 , id2 , ..., idX.`
                *   If an element is missing, the ID to display is `[nullptr]`.
        <br>
        <br>
        <br>
        *   __KoalaDoctorList__
            *   Takes a `pointer` to a `KoalaDoctor` as a constructor parameter.
                *   This `pointer` can be a `nullptr`.
            *   Has an `isEnd` member function which takes no parameter and returns a boolean set to `true` if the `KoalaDoctorList` is the last node of its list.
            *   Has an `append` member function which takes a `pointer` to a `KoalaDoctorList` as a parameter and does not return anything.
                *   The node passed as parameter is added to the end of the linked list.
            *   Has a `getFromName` member function which takes a `string` as a parameter and returns the first `KoalaDoctor` in the list whose name matches that `string`.
            *   Has a `remove` member function which takes a `pointer` to a `KoalaDoctorList` as a parameter and removes the `KoalaDoctorList` matching this `pointer` from the list.
                *   It returns a `pointer` to the first node of the list.
            *   Has a `removeFromName` member function which takes a `string` as a parameter and removes the first `KoalaDoctorLis` whose content’s name matches that `string` from the list.
                *   It returns a `pointer` to the first node of the list.
            *   Has a `dump` member function which takes no parameter and does not return anything.
                *   It displays the name of all `KoalaDoctors` in the list in order (begin -> end):
                    `Doctors: name1 , name2 , ..., nameX.`
                *   If an element is missing, the name to display is `[nullptr]`.
___
__Exercise 06 - Hospital__
*   | ex06                  | hospital                  |
    | -------               | --------                  |
    | Turn-in directory     | ex06/                     |
    | Files to turn-in      | Makefile<br>SickKoala.hpp/cpp<br>KoalaNurse.hpp/cpp<br>KoalaDoctor.hpp/cpp<br>SickKoalaList.hpp/cpp<br>KoalaNurseList.hpp/cpp<br>KoalaDoctorList.hpp/cpp<br>Hospital.hpp/cpp  |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   It is now possible to manage several patients, nurses and doctors.
    *   It is time to move on and manage the entire Hospital!
    *   __You will now code without any help.__
    *   You must __deduce__ the member functions of the `Hospital` based on the sample `main` function you will find below.
    *   The `Hospital` must distribute work between doctors and nurses.
    *   For this exercise, you may have to modify existing classes.
    *   You are responsible for these modifications, as long as they comply with the requirements and descriptions of the previous exercises!
    ```C++
    #include <iostream>
    #include <string>
    #include <cstdlib>
    #include "SickKoala.hpp"
    #include "KoalaNurse.hpp"
    #include "KoalaDoctor.hpp"
    #include "SickKoalaList.hpp"
    #include "KoalaNurseList.hpp"
    #include "KoalaDoctorList.hpp"
    #include "Hospital.hpp"
    int main(void)
    {
        srandom(42);
        KoalaDoctor cox("Cox");
        KoalaDoctor house("House");
        KoalaDoctor tired("Boudur-Oulot");
        KoalaDoctorList doc1(&cox);
        KoalaDoctorList doc2(&house);
        KoalaDoctorList doc3(&tired);
        KoalaNurse ratched(1);
        KoalaNurse betty(2);
        KoalaNurseList nurse1(&ratched);
        KoalaNurseList nurse2(&betty);
        SickKoala cancer("Ganepar");
        SickKoala gangrene("Scarface");
        SickKoala measles("RedFace");
        SickKoala smallpox("Varia");
        SickKoala fracture("Falter");
        SickKoalaList sick1(&cancer);
        SickKoalaList sick4(&gangrene);
        SickKoalaList sick3(&measles);
        SickKoalaList sick2(&smallpox);
        SickKoalaList sick5(&fracture);
        {
            Hospital bellevue;
            bellevue.addDoctor(&doc1);
            bellevue.addDoctor(&doc2);
            bellevue.addDoctor(&doc3);
            bellevue.addSick(&sick1);
            bellevue.addSick(&sick2);
            bellevue.addSick(&sick3);
            bellevue.addSick(&sick4);
            bellevue.addSick(&sick5);
            bellevue.addNurse(&nurse1);
            bellevue.addNurse(&nurse2);
            bellevue.addSick(&sick4);
            bellevue.run();
        }
        if (nurse*isEnd() && sick*isEnd() && doc*isEnd())
            std::cout << "Lists cleaned up." << std::endl;
        else
            std::cerr << "You fail! Boo!" << std::endl;
        return (0);
    }

    ∼/B-PDG-300> ./a.out
    Dr.Cox: I'm Dr.Cox! How do you kreog?
    Dr.House: I'm Dr.House! How do you kreog?
    Dr.Boudur-Oulot: I'm Dr.Boudur-Oulot! How do you kreog?
    [HOSPITAL] Doctor Cox just arrived!
    Dr.Cox: Time to get to work!
    [HOSPITAL] Doctor House just arrived!
    Dr.House: Time to get to work!
    [HOSPITAL] Doctor Boudur-Oulot just arrived!
    Dr.Boudur-Oulot: Time to get to work!
    [HOSPITAL] Patient Ganepar just arrived!
    [HOSPITAL] Patient Varia just arrived!
    [HOSPITAL] Patient RedFace just arrived!
    [HOSPITAL] Patient Scarface just arrived!
    [HOSPITAL] Patient Falter just arrived!
    [HOSPITAL] Nurse 1 just arrived!
    Nurse 1: Time to get to work!
    [HOSPITAL] Nurse 2 just arrived!
    Nurse 2: Time to get to work!
    [HOSPITAL] Work starting with:
    Doctors: Cox, House, Boudur-Oulot.
    Nurses: 1, 2.
    Patients: Ganepar, Varia, RedFace, Scarface, Falter.
    Dr.Cox: So what's goerking you Mr.Ganepar?
    Mr.Ganepar: Gooeeeeerrk!!
    Nurse 1: Kreog! Mr.Ganepar needs a Kinder!
    Mr.Ganepar: There is a toy inside!
    Dr.House: So what's goerking you Mr.Varia?
    Mr.Varia: Gooeeeeerrk!!
    Nurse 2: Kreog! Mr.Varia needs a Mars!
    Mr.Varia: Mars, and it kreogs!
    Dr.Boudur-Oulot: So what's goerking you Mr.RedFace?
    Mr.RedFace: Gooeeeeerrk!!
    Nurse 1: Kreog! Mr.RedFace needs a Kinder!
    Mr.RedFace: There is a toy inside!
    Dr.Cox: So what's goerking you Mr.Scarface?
    Mr.Scarface: Gooeeeeerrk!!
    Nurse 2: Kreog! Mr.Scarface needs a Kinder!
    Mr.Scarface: There is a toy inside!
    Dr.House: So what's goerking you Mr.Falter?
    Mr.Falter: Gooeeeeerrk!!
    Nurse 1: Kreog! Mr.Falter needs a Crunch!
    Mr.Falter: Goerkreog!
    Nurse 1: Time to go home to my eucalyptus forest!
    Nurse 2: Time to go home to my eucalyptus forest!
    Dr.Cox: Time to go home to my eucalyptus forest!
    Dr.House: Time to go home to my eucalyptus forest!
    Dr.Boudur-Oulot: Time to go home to my eucalyptus forest!
    Lists cleaned up.
    Mr.Falter: Kreooogg!! I'm cuuuured!
    Mr.Varia: Kreooogg!! I'm cuuuured!
    Mr.RedFace: Kreooogg!! I'm cuuuured!
    Mr.Scarface: Kreooogg!! I'm cuuuured!
    Mr.Ganepar: Kreooogg!! I'm cuuuured!
    Nurse 2: Finally some rest!
    Nurse 1: Finally some rest!
    ```

## Key Learnings
[(Back to top)](#table-of-contents)
*   [Input/Output](#inputoutput)
    *   [C++ Input/Output Library](#c-inputoutput-library)
    *   [IOStream](#iostream)
        *   [Stream in C++?](#stream-in-c)
            *   [Definition](#iostream-stream-in-c-definition-anchor)
        *   __Stream in C++__
    *   __Fstream__
    *   __IOmanip__
*   __Classes__
    *   __Constructor(Default and Custrom)__, __Destructor__
    *   __Member Functions__
    *   __Initialisation lists__
    *   __Visibility/Encapsuslation__
    *   __Getter and Setter (Accessors and Mutators)__
    *   __Class VS Struct__
* __Non-Member Attribute & Non-Member Function__
* __Pointer to Members__
    *   __Pointer to Data Members__
    *   __Pointer to Members Functions__
* __const__
* __static__ 
* __auto__
* __string__
    
## Lessons Learned
[(Back to top)](#table-of-contents)
### Input/Output
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
#### C++ Input/Output Library
*   C++ offers several types of input/output libraries:
    *   __Stream-based I/O library__: An object-oriented, stream-based approach to handle various input/output operations.
    *   __Print-based functions__ (since C++23): Functions for formatted text output.
    *   __C-style I/O functions__: Compatibility with traditional C I/O functions like fopen, getc, etc.
*   __Stream-based I/O__
    *   The stream-based I/O abstracts input/output devices, allowing uniform __handling of files__, __memory streams__, and __other devices__ (e.g., compression).
*   __Class Hierarchy__
    ![Standard I/O complete inheritance](https://upload.cppreference.com/mwiki/images/0/06/std-io-complete-inheritance.svg)
#### IOstream:
##### Stream in C++?
*   **<a id="iostream-stream-in-c-definition-anchor"></a>Definition:**
    *   A **stream** is an abstraction that represents a sequence of data, either coming from an input source (e.g., keyboard) or going to an output destination (e.g., screen or file).
    *   In C++, streams are handled with the `<iostream>` library, which provides three standard streams:
        *   `cin` (standard input): Reads data from the user (usually the keyboard).
        *   `cout` (standard output): Writes data to the screen.
        *   `cerr` (standard error): Used to display error messages.
        *   `clog` (standard logging): Used for logging messages, similar to `cerr`, but it's buffered.
        *   | **Predefined standard stream objects** | **Header** | **Description** | **Type** |
            |----------------------------------------|------------|-----------------|----------|
            | `cin`, `wcin` | `<iostream>` | Reads from the standard C input stream `stdin` | Global object |
            | `cout`, `wcout` | `<iostream>` | Writes to the standard C output stream `stdout` | Global object |
            | `cerr`, `wcerr` | `<iostream>` | Writes to the standard C error stream `stderr`, unbuffered | Global object |
            | `clog`, `wclog` | `<iostream>` | Writes to the standard C error stream `stderr` | Global object |
*  **Why Use Streams?**
    *   Streams allow for consistent handling of input and output, whether it's from the keyboard, a file, or other sources.
*   #### Standard Input and Output Streams:
*  **Output with `cout`:**
    *   Used to print data to the screen.
    *   The `<<` operator is used to send data to the output stream.
    *   `std::endl` stands for "end line" and is used to insert a   newline character and flush the output buffer, ensuring the message is immediately displayed on the screen.
    *   __Syntax / Example__:
        ```C++
        #include <iostream>
        std::cout << "Message to display" << std::endl;
        ```
2.  **Input with `cin`:**
    *   Used to read data from the keyboard.
    *   The `<<` operator is used to send data to the output stream.
    *   The `>>` operator is used to extract data from the input stream.
    *   `std::endl` stands for "end line" and is used to insert a   newline character and flush the output buffer, ensuring the message is immediately displayed on the screen.
    *   Syntax:
        ```C++
        #include <iostream>
        std::cin >> variable;
        ```
    *   Example:
        ```C++
        #include <iostream>
        int age;
        std::cout << "Enter your age: ";
        std::cin >> age;
        std::cout << "You are " << age << " years old." << std::endl;
        ```
3.  **Error Output with `cerr`:**
    *   Used to display error messages. Unlike `cout`, `cerr` is __unbuffered__, meaning the message is displayed immediately without waiting for the buffer to be flushed.
    *   The `<<` operator is used to send data to the output stream.
    *   `std::endl` stands for "end line" and is used to insert a   newline character and flush the output buffer, ensuring the message is immediately displayed on the screen.
    *   __Syntax / Example__:
        ```C++
        #include <iostream>
        std::cerr << "Error: Invalid value!" << std::endl;
        ```
4.  **Logging Output with `clog`:**
    *   Used for logging messages. Unlike `cerr`, `clog` is __buffered__, meaning it waits until the buffer is full or `std::endl` is encountered before sending the message to the output. This can be more efficient for logging large amounts of data.
    *   The `<<` operator is used to send data to the output stream.
    *   `std::endl` stands for "end line" and is used to insert a   newline character and flush the output buffer, ensuring the message is immediately displayed on the screen.
    *   __Syntax / Example__:
        ```C++
        #include <iostream>
        std::clog << "Log: Processing data..." << std::endl;
        ```

    *   ####    Fstream
        In C++, the classes `fstream`, `ifstream`, and `ofstream` are used to handle file input/output operations. They are part of the `<fstream>` library. Here's the main difference between them:
        *  **`fstream`:**
            *   __Definition__: The fstream class is a combination of both `ifstream` (input) and `ofstream` (output). It allows you to open a file for both __reading and writing__.
            *   __Usage__: You use `fstream` when you want to both __read and write__ to a file.
            *   __Constructor__:
                *   `std::fstream file("filename");`
                *   You can open the file using specific modes (__`std::ios::in`, `std::ios::out`__, etc.).
                *   By default, it opens the file in read/write mode. You need to specify modes if you want particular behavior (read-only or write-only).
            *   __Syntax / Example__:
                ```C++
                #include <fstream>
                std::fstream file("example.txt", std::ios::in | std::ios::out);
                    ```
        2.  **`ifstream` (Input File Stream):**
            *   __Definition__: `ifstream` is used only to __read__ data from a file (input).
            *   __Usage__: You use `ifstream` when you want to __read__ data from a file.
            *   __Constructor__:
                *   `std::ifstream file("filename");`
                *   Opens the file in __read-only__ mode by default (__`std::ios::in`__).
            *   __Reading from a File:__ Use `ifstream` to __read__ data from a file, using the same operators (`>>` and `getline`) as for `cin`.
            *   __Checking if a File Opened Successfully:__ Always check if the file opened correctly before trying to __read__ or __write__.
            *   __Syntax / Example__:
                ```C++
                #include <iostream>
                #include <fstream>
                std::ifstream readFile("readFile.txt");

                if (!readFile.is_open()) {
                    std::cerr << "Error: Could not open files." << std::endl;
                    return 1;
                }

                std::string line;
                while (std::getline(readFile, line, '\0')) {
                    std::cout << line << std::endl;
                }

                readFile.close();
                return 0;
                ```
        3.  **`ofstream` (Output File Stream):**
            *   __Definition__: `ofstream` is used only to __write__ data to a file (output).
            *   __Usage__: You use `ofstream` when you want to __write__ data to a file.
            *   __Constructor__:
                *   `std::ofstream file("filename");`
                *   Opens the file in __write-only__ mode by default (__`std::ios::out`__).
                *   If the file exists, its content will be __erased__.
                *   If the file doesn’t exist, `ofstream` will __create__ a new file.
            *   __Writing to a File:__ Use `ofstream` to __write__ to a file, just like `cout`.
            *   __Checking if a File Opened Successfully:__ Always check if the file opened correctly before trying to __read__ or __write__.
            *   __Syntax / Example__:
                ```C++
                #include <iostream>
                #include <fstream>
                std::ofstream writeFile("writeFile.txt");

                if (!writeFile.is_open()) {
                    std::cerr << "Error: Could not open files." << std::endl;
                    return 1;
                }

                std::string line = "im writting in a file!";
   
                writeFile << line << std::endl;

                writeFile.close();
                ```
        4.  **Summary of Differences:**
            *   | Class | Default Opening Mode | Usage |
                |-------|----------------------|-------|
                | `fstream` |	Read and write (`std::ios::in` or `std::ios::out`) | To read / write data from a file |
                | `ifstream` | Read-only (`std::ios::in`)	| To read data from a file |
                | `ofstream` | Write-only (`std::ios::out`) | To write data to a file |
    *   #### IOmanip
        *   The `<iomanip>` library in C++ provides functions and manipulators that help format the input and output of data in a more flexible and readable manner. It is especially useful when working with floating-point numbers, controlling spacing between outputs, and aligning the text in a certain format.
        *   `<iomanip>` stands for __I/O manipulators__, which help in formatting the output by altering the appearance of printed data without changing the actual values.
        *   The functions from `<iomanip>` are often used with __`std::cout`__ (standard output) to display data in a particular format (e.g., floating-point precision, alignment of text or numbers).
        *  __`setw` Manipulator__
            *   __Definition:__ The `setw` manipulator stands for __set width__.
            *   __Usage:__ 
                *   It is used to specify the minimum number of characters to be used when displaying the next value in the output.
                *   If the value to be displayed is shorter than the specified width, spaces will be added to the left (by default) to fill the gap.
            *   __Syntax / Example:__
                ```C++
                #include <iostream>
                #include <iomanip> // Required for setw

                int main() {
                    std::cout << std::setw(10) << 123 << std::endl;
                    std::cout << std::setw(10) << 4567 << std::endl;
                    std::cout << std::setw(10) << "C++" << std::endl;

                    return 0;
                }
                output:
                         123
                         4567
                         C++
                ```
        2.  __`fixed` Manipulator__
            *   __Definition__: 
                *   The `fixed` manipulator is used to display floating-point numbers in __fixed-point notation__.
                *   By default, floating-point numbers in C++ are printed in scientific notation if the number is too large or too small. 
            *   __Usage__: Using `fixed` forces the output to show the decimal part as a    fixed number of digits, even if the number is very large or small.
            *   __Syntax / Example__:
                ```C++
                #include <iostream>
                #include <iomanip> // Required for fixed

                int main() {
                    double pi = 3.14159265358979;
                    
                    std::cout << "Default notation: " << pi << std::endl;
                    std::cout << std::fixed << "Fixed notation: " << pi << std::endl;

                    return 0;
                }

                output:
                Default notation: 3.14159
                Fixed notation: 3.141593 // with std::fixed
                ```
        3.  __`setprecision` Manipulator__
            *   __Definition:__
                *   The `setprecision` manipulator controls the number of __significant digits__ or __decimal__ places to display for floating-point numbers.
                *   It can __work with or without__ the `fixed` manipulator, but its behavior changes depending on whether `fixed` is used.
            *   __Syntax / Example:__
                *   Example without `fixed`:
                    ```C++
                    // USAGE WITHOUT FIXED
                    #include <iostream>
                    #include <iomanip> // Required for setprecision

                    int main() {
                        double pi = 3.14159265358979;
                        
                        std::cout << std::setprecision(4) << pi << std::endl;
                        std::cout << std::setprecision(8) << pi << std::endl;

                        return 0;
                    }
                    output:
                    3.142
                    3.1415927
                    ```
                *   Example with `fixed`:
                    ```C++
                    // USAGE WITH FIXED
                    #include <iostream>
                    #include <iomanip> // Required for setprecision and fixed

                    int main() {
                        double pi = 3.14159265358979;

                        std::cout << std::fixed << std::setprecision(4) << pi << std::endl;
                        std::cout << std::fixed << std::setprecision(2) << pi << std::endl;

                        return 0;
                    }
                    output:
                    3.1416
                    3.14
                    ```
        4.  __Sunnary__
            | Manipulator | Description | Example Usage |
            |-------------|-------------|---------------|
            | `setw`      |	Sets the minimum width of the next output field. | `std::cout << std::setw(10);` |
            | `fixed` | Forces floating-point numbers to be printed in fixed-point notation. | `std::cout << std::fixed;` |
            | `setprecision` | Controls the number of significant digits or decimal places. |`std::cout << std::setprecision(3);` |

___
#### Class
In C++, __classes__ are one of the fundamental concepts of __object-oriented programming__ (OOP). They allow you to model objects by grouping data and functions (methods) that operate on that data. This course will cover the syntax, key concepts, and advanced topics related to classes in C++.
*   __What is a Class?__
    *   A class is a blueprint or template for **creating objects**. It defines the **properties** (data) and **behavior** (methods) of objects. A class may contain:
        *   **Access Specifiers**:
            *   **`public`**: Members are accessible from outside the class.
            *   **`protected`**: Members are accessible within the class and its derived (inherited) classes.
            *   **`private`**: Members are only accessible within the class itself.
        *   **Constructor**:
            *   Is a special method that is **automatically called** when an object is **created**.
            *   It has the same name as the class and has no return type.
        *   **Destructor**:
            *   Is a special method **automatically called** when an object is **destroyed**.
            *   It is mainly used to **free** resources.
            *   The **destructor** has the same name as the class, preceded by the **`~`** symbol, and takes no parameters.
        *   **Attributes** (or data members): **Variables** that represent the object's **properties**.
        *   **Methods** (or member functions): Functions that manipulate the data or perform specific actions.
        *   **Keywords `this`**:
            *   Inside a class method, the keyword **`this` pointer** refers to the **current instance of the class** (the object the method is acting upon).
            *   It is often used to resolve name conflicts between class attributes and method parameters.
        *   **Initialization list**: 
            *   **Definition**:
                *   An **initialization list** is a mechanism used to directly initialize class members before the constructor body is executed.
                *   This approach is **cleaner** and **more efficient**, especially in cases where certain members cannot be assigned values in the constructor body.
            *   **Efficiency**:
                *   Initialization lists are more **efficient** than assigning values in the constructor body.
                *   When initializing a member in the constructor body, **the object is first constructed** (possibly using a default constructor), and then **reassigned**.
                *   Using an initialization list, the member is **initialized directly, avoiding unnecessary reassignments**.
            *   **Order of Member Initialization**:
                *   One important aspect is that the order in which members are initialized is **not determined by the order in the initialization list**, but rather by the **order in which they are declared in the class**.
            *   **Necessary for const and Reference Members.**
        *   **Visibility and Encapsulation**:
            *    In C++, **visibility and encapsulation** are core concepts of object-oriented programming (OOP).
            *   They enable the control of access to class members (attributes and methods) to ensure **data security** and **integrity**.
            *   **Encapsulation** improves code **modularity** and **maintainability**.
            *   **Encapsulation**:
                *   **Definition**:
                    *   **Encapsulation** is the concept of bundling data (attributes) and methods that operate on that data within a single entity: the **class**.
                    *   It also **restricts access** to these members, **protecting** them from unauthorized modification or **access** from outside the class.
                *   **Usage**:
                    *   The main goal of **encapsulation** is to **prevent** users from directly **modifying the internal attributes of a class** and to **enforce controlled access methods**.
            *   **Visibility**:
                *   **Definition**:
                    *   **Visibility**, or **access specifiers**, define how class members (attributes and methods) can be accessed.
                    *   **Three levels of visibility**:
                        *   **`public`**: Members are accessible from outside the class.
                        *   **`protected`**: Members are accessible within the class and its derived (inherited) classes.
                        *   **`private`**: Members are only accessible within the class itself.
            *   **Benefits of Encapsulation and Visibility**
                *   **Data Protection**
                *   **Clean Interface**
                *   **Flexibility and Scalability**
                *   **Access Control**
        *   **Getters and Setters**:
            *   **Usage**:
                *   To **allow controlled access to private or protected attributes**, **getters** and **setters** are often used.
            *   **Getter**: Is a method that **returns the value of an attribute**.
            *   **Setter**: Is a method that **modifies an attribute in a controlled way**.
    *   **Syntax / Example**:
        ```C++
        // file: Example.hpp
        #ifndef     __EXAMPLE_HPP__
            #define __EXAMPLE_HPP__
            
        #include <string>
        class Example // Keyword `class` followed by the class name `Example`
        {
            public: // Access specifier
                Example(std::string name, int age); // Constructor
                ~Example(void); // Destructor

                void                methodExample(void); // Method or Member function

                int                 getAge(void) const; // Getter
                void                setAge(int age); // Setter
            protected: // Access specifier

            private: // Access specifier
                int                 _number; // Attribute or Data member
                int                 _age;
                const std::string   _name;

        }; // `;` Very important for close class and avoid some issues.

        #endif //   !__EXAMPLE_HPP__

        // ----------------------------------------------------------------
        // file: Example.cpp
        
        #include <iostream>
        #include "Example.hpp"
        // Constrcutor
        Example::Example(std::string name, int age) :   _age(age), _name(name) // Initialization list with correct order
        {
            this->_number = 10; // Attribute with keyword `this`
            
            // Error:
            //this->_name = name; Error: _name is const and can't be assigned;
            std::cout << "Constructor called!" << std::endl;
        }

        // Destructor
        Example::~Example(void)
        {
            std::cout << "Destructor called!" << std::endl;
        }

        // Method or Member function
        void    Example::methodExample(void)
        {
            std::cout << "Attribute number equals to: " << _number << std::endl;
        }

        // Getter Function
        int     Example::getAge(void) const
        {
            return _age;
        }

        // Setter Function
        void    Example::setAge(int age)
        {
            _age = age;
        }
        // ----------------------------------------------------------------
        // file: main.cpp
        #include <iostream>
        #include "Example.hpp"

        int main(void)
        {
            Example     example("Jhon Doe", 18);    // Object created
        // If constructor has int parameter for example:
        // Example  example(10);

            example.methodExample(); // method called
        
        // Error
        //  std::cout << "Age equals to: " << example._age << std::endl; // Error: We can't access to _age because is private.
            std::cout << "Age equals to: " << example.getAge() << std::endl; // With getter we can have access to _age attribute.

            std::cout << "Next year" << std::endl;

        // Error
        //  example._age = 19; // Error: We can't access to _age and modify because is private.
            example.setAge(19); // With setter we can modify _age attribute
            std::cout << "Age equals to: " << example.getAge() << std::endl;
            return 0;
        }
        // ----------------------------------------------------------------
        output:
        Constructor called!
        Attribute number equals to: 10
        Age equals to: 18
        Next year
        Age equals to: 19
        Destructor called!
        ```
___
#### Non-Member Attribute & Non-Member Function
*   **Definition**:
    *   **Non-member variables**: 
        *   Variables **defined outside of the class**, often **used to store global** or **shared information** across multiple instances of the class.
        *   **Non-member variables** are typically **global** or **static variables** defined outside of the class.
    *   **Non-member functions**: Functions defined **outside of the class that operate on** or **use objects of the class**.
*   **Usage**:
    *   **Encapsulation and Abstraction**:
        *   **Non-member functions & Attributes** allow for **maintaining a separation** between a class’s public **interface** and the **operations** that can be performed on that class.
        *   This preserves **encapsulation** while providing additional functionality.
    *   **Reducing Coupling**:
        *   Using **non-member functions & Attributes** can reduce coupling between classes, meaning that classes are **less dependent** on one another, making the code **more modular** and **easier to maintain.**
*   **Syntax / Example**:
    ```C++
    // file: Example.hpp
    #ifndef     __EXAMPLE_HPP__
        #define __EXAMPLE_HPP__
        
    #include <string>
    class Example // Keyword `class` followed by the class name `Example`
    {
        public: // Access specifier
            Example(void); // Constructor
            ~Example(void); // Destructor

            static int          getNbInstance(void); // Getter and Non-Member Function
        protected: // Access specifier

        private: // Access specifier
            static int          _numberInstance; // Non-Member Attribute

    }; // `;` Very important for close class and avoid some issues.

    #endif //   !__EXAMPLE_HPP__

    // ----------------------------------------------------------------
    // file: Example.cpp
    
    #include <iostream>
    #include "Example.hpp"

    // Non-Member attribute Initialization
    int  Example::_numberInstance = 0;


    // Constrcutor
    Example::Example(void)
    {
        std::cout << "Constructor called!" << std::endl;
        Example::_numberInstance += 1; // syntax
    }

    // Destructor
    Example::~Example(void)
    {
        std::cout << "Destructor called!" << std::endl;
        Example::_numberInstance -= 1;
    }

    // Getter Non-Member Function
    int     Example::getNbInstance(void)
    {
        return Example::_numberInstance;
    }

    // ----------------------------------------------------------------
    // file: main.cpp
    #include <iostream>
    #include "Example.hpp"

    void    f0(void)
    {
        Example     example;
        std::cout   << "Number of instances of Example Class: " 
                    << Example::getNbInstance() << std::endl;
    }

    void    f1(void)
    {
        Example     example;
        std::cout   << "Number of instances of Example Class: " 
                    << Example::getNbInstance() << std::endl;
        f0();
    }

    int     main(void)
    {
        std::cout   << "Number of instances of Example Class: " 
                    << Example::getNbInstance() << std::endl;
        f1();
        std::cout   << "Number of instances of Example Class: " 
                    << Example::getNbInstance() << std::endl;
        return 0;
    }
    // ----------------------------------------------------------------
    output:
    Number of instances of Example Class: 0
    Constructor called!
    Number of instances of Example Class: 1
    Constructor called!
    Number of instances of Example Class: 2
    Destructor called!
    Destructor called!
    Number of instances of Example Class: 0
    ```
*   **Advantages and Disadvantages of Non-Member Attributes & Non-Member Functions:**
    *   **Advantages**:
        *   **Flexibility**: **Non-member functions & attributes** can be **added** or **modified** without **changing the class definition**.
        *   **Encapsulation**: **Non-member functions & attributes** can manipulate objects without exposing their internal details.
        *   **Reduced Coupling**: Helps **reduce dependencies** between classes.
    *   **Disadvantages**:
        *   **Limited Access**: **Non-member functions & attributes** do **not have direct access to private/protected** class members (unless they are `friend` functions).
        *   **Managing Friend Functions**: Excessive use of `friend` functions can compromise **encapsulation**.
___
#### Pointer to Members and Pointer to Members Functions
*   **Pointer to Members**:
    *   **Definition**:
        *   A **member pointer** is a **pointer that doesn't point to a memory address (like a regular pointer), but rather to a specific member (either a variable or a function) of a class**.
        *   However, this **pointer does not point to a concrete value within a specific object**.
        *   Instead, it **points** to the "**location**" of a member relative to any object of that class.
    *   **Syntax and basic example**:
        ```C++
        #include <iostream>
        class Example {
        public:
            int x;  // A data member
            int y;  // Another data member
        };

        int main() {
            Example obj1, obj2;  // Two objects of the Example class

            int Example::*ptr = &Example::x;  // Pointer to the `x` member of the Example class

            obj*x = 10;
            obj2.x = 20;

            // Using the pointer to access the `x` member of each object
            std::cout << "obj*x = " << obj**ptr << std::endl;  // Access `x` in obj1
            std::cout << "obj2.x = " << obj2.*ptr << std::endl;  // Access `x` in obj2

            // We can change the pointer to point to another member
            ptr = &Example::y;
            obj*y = 30;
            obj2.y = 40;

            std::cout << "obj*y = " << obj**ptr << std::endl;  // Access `y` in obj1
            std::cout << "obj2.y = " << obj2.*ptr << std::endl;  // Access `y` in obj2

            return 0;
        }
        ```
        *   **Explanation**:
            *   **Declaration**: **`int Example::*ptr`** declares a pointer **`ptr`** that can **point to an int member in the Example class**.
            *   **Initialization**: **`ptr = &Example::x`** assigns the **address** of the **`x` member to `ptr`**.
            *   **Usage**: **`obj**ptr`** uses **`ptr` to access `x` in the `obj1` object**.
    *   **Why is this useful?**
        *   This allows you to **dynamically manipulate different members of the class without writing specific code for each member**. 
        *   You can **change** which member is pointed to by the pointer, and the same code can then **access** or **modify** different members.
*   **Pointer to Members Functions**;
    *   **Definition**:
        *   A **member pointer** is a **pointer that doesn't point to a memory address (like a regular pointer), but rather to a specific member (either a variable or a function) of a class**.
        *   However, this **pointer does not point to a concrete value within a specific object**.
        *   Instead, it **points** to the "**location**" of a member relative to any object of that class.
    *   **Syntax and basic example**:
        ```C++
        #include <iostream>
        class Calculator {
        public:
            int add(int a, int b) { return a + b; }
            int subtract(int a, int b) { return a - b; }
            int multiply(int a, int b) { return a * b; }
            int divide(int a, int b) { return b != 0 ? a / b : 0; }
        };

        int main() {
            Calculator calc;

            // Declaration of a pointer to member function
            int (Calculator::*op)(int, int) = nullptr;

            char operation = '*';  // Operation determined dynamically, for example.

            // Dynamically choosing which member function to call
            if (operation == '+')
                op = &Calculator::add;
            else if (operation == '-')
                op = &Calculator::subtract;
            else if (operation == '*')
                op = &Calculator::multiply;
            else if (operation == '/')
                op = &Calculator::divide;

            // Calling the member function via the pointer
            if (op) {
                std::cout << "Result: " << (calc.*op)(10, 5) << std::endl;  // Executes the chosen operation
            }

            return 0;
        }
        ```
        *   **Explanation**:
            *   **Declaration**: **`int (Calculator::*op)(int, int)`** declares a pointer **`op`** that can point to a **member function of the `Calculator`** class that takes two **`int`** parameters and returns an **`int`**.
            *   **Initialization**: **`op = &Calculator::multiply`** assigns the **address of the `multiply` function to `op`**.
            *   **Usage**: **`(calc.*op)(10, 5)`** calls the member function pointed to **`(multiply)` with arguments 10 and 5**.
    *   **Why is this useful?**
        *   This allows you to **dynamically choose which method** of the class will be executed based on the **program's needs**. 
        *   For example, in a **`calculator`**, you can **choose which operation to apply based on user input**.
*   **Summary**
    *  **Member pointers allow you to**:
        *   **Flexibility**: 
            *   **Dynamically** choose which member or function of a class to manipulate or call.
            *   **Reduce Repetitive Code**: Avoid writing specific code for each member or function.
            *   **Modularity**: Separate the program logic into reusable and dynamic components.
*   **Conclusion**
    *   Although member pointers **are not necessary for every program**, they are very **useful** in scenarios where **flexibility** and **dynamic** behavior are needed.
    *   They are often **used in complex environments**, such as **user interfaces** or **event-driven systems**, where it is **necessary to select specific members to manipulate** or **execute based on runtime conditions**.
___
#### Keyword `const`
*   **Basic Usage of const with Variables**
    *   The simplest use of **`const`** is to declare a constant variable.
    *   Once a variable is declared as **`const`**, its value cannot be changed.
    *   **Syntax / Example**:
        ```C++
        const int maxScore = 100;
        maxScore = 200;  // Error: Cannot modify a const variable
        ```
*   **`const` Member Functions**
    *   In C++, a member function can be declared as **`const`** to indicate that it does not modify the state of the object.
    *   A **`const`** member function is only allowed to call other **`const`** member functions and cannot modify any non-mutable member variables.
    *   **Syntax / Example**:
        ```C++
        class MyClass {
        public:
            int getValue() const {  // This function will not modify any member variables
                return value;
            }

            void setValue(int val) {
                value = val;
            }

        private:
            int value;
        };
        ```
___

#### `static` Keyword
*   **`static` Local Variables**
    *   When a variable is declared as **`static`** inside a function, it retains its value between function calls.
    *   Unlike regular local variables, which are created and destroyed each time a function is called, a **`static` local variable is initialized only once and persists for the lifetime of the program**.
    *   **Syntax / Example**:
        ```C++
        #include <iostream>
        void counter() {
            static int count = 0;  // Static local variable
            count++;
            std::cout << "Count: " << count << std::endl;
        }

        int main() {
            counter();  // Outputs: Count: 1
            counter();  // Outputs: Count: 2
            counter();  // Outputs: Count: 3
            return 0;
        }
        ```
        *   **Explanation**:
            *   **Initialization**: The `count` variable is initialized only once, when the function is called for the first time.
            *   **Persistence**: The value of `count` persists between subsequent calls to `counter()`.
*   **static Global Variables**
    *   When a **global variable** is declared as **`static`**, its scope is limited to the file in which it is declared.
    *   This means that it **cannot be accessed or modified from other files** (translation units), even if they are part of the same program.
    *   **Syntax / Example**:
        ```C++
        #include <iostream>
        // File*cpp
        static int globalVar = 10;  // Static global variable

        void printVar() {
            std::cout << "globalVar: " << globalVar << std::endl;
        }

        // File2.cpp
        extern void printVar();

        int main() {
            printVar();  // This works
            // std::cout << globalVar << std::endl;  // Error: globalVar is not accessible here
            return 0;
        }
        ```
        *   **Explanation**:
            *   **File Scope**: 
                *   The `globalVar` is only accessible within File*cpp.
                *   It cannot be accessed directly from File2.cpp, which helps to prevent naming conflicts and accidental modifications.
*   **`static` with Functions**
    *   **`static` Member Functions**
        *   In a class, a member function can be declared as **`static`**.
        *   This means that the function c**an be called without an instance of the class**.
        *   **`static` member functions do not have access to non-static member variables or this pointer** because they do not belong to any particular instance of the class.
        *   **Syntax / Example**:
            ```C++
            #include <iostream>
            class Example {
            public:
                static void displayMessage() {
                    std::cout << "Hello from static function!" << std::endl;
                }
            };

            int main() {
                Example::displayMessage();  // Calling static member function without an object
                return 0;
            }
            ```
            *   **Explanation**:
                *   **No Instance Required**: `displayMessage()` is called directly on the class, not on an instance of the class.
                *   **No Access to Non-Static Members**: The **`static`** function cannot access instance-specific data (non-static members).
*   **`static` Global Functions**
    *   A function defined as **`static`** at global scope has internal linkage.
    *   This means **it can only be called within the file it is defined in**, preventing other files from using it directly.
    *   **Syntax / Example**:
        ```C++
        #include <iostream>
        // File*cpp
        static void hiddenFunction() {
            std::cout << "This function is hidden from other files." << std::endl;
        }

        int main() {
            hiddenFunction();  // This works
            return 0;
        }

        // File2.cpp
        extern void hiddenFunction();

        int main() {
            hiddenFunction();  // Error: hiddenFunction() is not visible here
            return 0;
        }
        ```
        *   **Explanation**:
            *   **Internal Linkage**: The `hiddenFunction` is only accessible within File*cpp, providing a f**orm of encapsulation** at the file level.
*   **`static` with Class Members**
    *   **``static`` Member Variables**
        *   **`static` member variables** belong to the class rather than any particular instance.
        *   This means that **all instances of the class share the same `static` member variable**.
        *   The **`static` variable** is initialized only once, and its **lifetime is the entire program duration**.
    *   **`static` Member Functions**
        *   **`static` member functions** can only access **`static` member variables** because they do not operate on a specific instance of the class.
        *   This is **useful** for functions that need to work with **shared data** or **provide utility functions** related to the class.
    *   **Syntax / Example**:
        ```C++
        #include <iostream>
        class Example {
        public:
            static int count;  // Static member variable

            Example() {
                count++;
            }

            ~Example() {
                count--;
            }

            static int getCount() {  // Static member function
                return count;
            }
        };

        int Example::count = 0;  // Definition and initialization of static member variable

        int main() {
            Example ex1;
            Example ex2;

            std::cout << "Count: " << Example::getCount() << std::endl;  // Outputs: Count: 2

            return 0;
        }
        ```
        *   **Explanation**:
            *   **Shared Among All Instances**: 
                *   `count` is **shared by all instances** of `Example`. 
                *   **Each time** an `Example` object is **created** or **destroyed**, `count` is **incremented** or **decremented**, respectively.
            *   **Global Lifetime**: `count` **exists for the entire duration of the program** and is initialized outside the class definition.
*   **Advantages of Using `static`**
    *   **Memory Efficiency**: **`static` variables and functions** reduce memory usage by avoiding duplication across multiple instances or files.
    *   **Encapsulation**: **`static` global variables and functions** help encapsulate data and functions within a single file, preventing unintended access or modification from other files.
    *   **Utility Functions**: **`static` member functions** can be used to provide utility methods that are related to a class but do not require an instance of the class to operate.
*   **Common Use Cases**
    *   **Counters**: Keeping track of the number of instances of a class.
    *   **Singletons**: Ensuring a class has only one instance by using static member variables and functions.
    *   **File-Scope Functions**: Encapsulating helper functions within a single file to avoid polluting the global namespace.
    *   **Configuration or Settings**: Storing global settings or configurations that should be shared across all instances of a class.
___
####    `auto` Keyword
*   **Basic Usage of `auto`**
    *   The **`auto`** keyword is used in place of a type name in variable declarations. The compiler deduces the type of the variable from the type of the initializer.
    *   **Syntax / Example**:
        ```C++
        #include <iostream>
        int main() {
            auto x = 10;     // `x` is deduced as `int`
            auto y = 3.14;   // `y` is deduced as `double`
            auto s = "Hello"; // `s` is deduced as `const char*`

            std::cout << x << ", " << y << ", " << s << std::endl;
            return 0;
        }
        ```
*   **``auto`` with Complex Types**
    *   One of the most powerful uses of **`auto`** is with **complex types**, such as **iterators**, **function return types**, or **template types**, where manually specifying the type would be cumbersome or unclear.
    *   **Syntax / Example**:
        ```C++
        #include <vector>
        #include <iostream>

        int main() {
            std::vector<int> numbers = {1, 2, 3, 4, 5};

            for (auto it = numbers.begin(); it != numbers.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
            return 0;
        }
        ```
___

####    `std::string`
*   **Definition**:
    *   **`std::string`** is a part of the **C++ Standard Library**, provided by the **`<string>` header**.
    *   It is one of the most commonly used data types in C++ because it offers a convenient way to **work with sequences of characters**, **providing many features** and **functions to manipulate** and **handle strings**.
    *   A **`std::string`** is a sequence of characters (like a **`char` array**).
    *   It **automatically manages memory**,** handles string concatenation**, and **provides a range of methods to manipulate strings**.
    *   **Syntax / Example**:
        ```C++
        #include <iostream>
        #include <string>

        int main() {
            std::string s1;               // Default constructor: empty string
            std::string s2("Hello");      // Initialization with a C-string literal
            std::string s3 = "World";     // Copy initialization
            std::string s4(s2);           // Copy constructor
            std::string s5(5, 'a');       // 5 repetitions of the character 'a'

            std::cout << s1 << std::endl; // Outputs: (empty string)
            std::cout << s2 << std::endl; // Outputs: Hello
            std::cout << s3 << std::endl; // Outputs: World
            std::cout << s4 << std::endl; // Outputs: Hello
            std::cout << s5 << std::endl; // Outputs: aaaaa

            return 0;
        }
        ```
    
*   **Common Operations on `std::string`**
    *   **Concatenation**:
        *   Strings can be concatenated using the **`+`** operator or the **`+=`** operator.
        *   **Syntax / Example**:
            ```cpp
            #include <string>
            #include <iostream>
            std::string s1 = "Hello";
            std::string s2 = "World";

            std::string s3 = s1 + " " + s2;   // Concatenation using +
            s1 += " Everyone";                // Concatenation using +=

            std::cout << s3 << std::endl;     // Outputs: Hello World
            std::cout << s1 << std::endl;     // Outputs: Hello Everyone
            ```
    *   **Accessing Characters**:
        *   You can access individual characters in a string using the **`[]`** operator or the **`.at()`** method.
        *   **`.at()`** performs bounds checking and throws an exception if the index is out of range, while **`[]`** does not.
        *   **Syntax / Example**:
            ```cpp
            #include <string>
            #include <iostream>
            std::string s = "Hello";

            char first = s[0];            // Access first character using []
            char last = s.at(s.size() - 1); // Access last character using .at()

            std::cout << first << std::endl;  // Outputs: H
            std::cout << last << std::endl;   // Outputs: o
            ```
    *   **String Length**:
        *   The length (or size) of a string can be determined using **`.size()`** or **`.length()`** methods.
        *   Both **`.size()`** and **`.length()`** are interchangeable and provide the number of characters in the string.
        *   **Syntax / Example**:
            ```cpp
            #include <string>
            #include <iostream>
            std::string s = "Hello";
            std::cout << "Length: " << s.size() << std::endl; // Outputs: Length: 5
            std::cout << "Length: " << s.length() << std::endl; // Outputs: Length: 5
            ```
*   **Modifying Strings**:
    *   **Appending and Inserting**:
        *   **Appending**:
            *   Add characters or strings to the end of an existing string.
            *   **Syntax / Example**:
                ```cpp
                #include <string>
                #include <iostream>
                std::string s = "Hello";
                s.append(" World");       // Appends " World" to s
                s.append(3, '!');         // Appends "!!!" to s
                std::cout << s << std::endl;  // Outputs: Hello World!!!
                ```
        *   **Inserting**:
            *   Insert characters or strings at a specified position.
            *   **Syntax / Example**:
                ```cpp
                #include <string>
                #include <iostream>
                std::string s = "Hello";
                s.insert(5, " Everyone");  // Inserts " Everyone" at position 5
                std::cout << s << std::endl; // Outputs: Hello Everyone
                ```
*   **Replacing and Erasing**:
    *   **Replacing**: 
        *   Replace a portion of the string with another string.
        *   **Syntax / Example**:
            ```cpp
            #include <string>
            #include <iostream>
            std::string s = "Hello World";
            s.replace(6, 5, "C++"); // Replaces "World" with "C++" starting at position 6
            std::cout << s << std::endl; // Outputs: Hello C++
            ```
    *   **Erasing**:
        *   Remove characters from the string.
        *   **Syntax / Example**:
            ```cpp
            #include <string>
            #include <iostream>
            std::string s = "Hello World";
            s.erase(5, 6);            // Erases " World" starting at position 5
            std::cout << s << std::endl; // Outputs: Hello
            ```
*   **Clearing a String**:
    *   **Clearing**:
        *   To remove all content from a string, use the **`.clear()`** method.
        *   **Syntax / Example**:
            ```cpp
            #include <string>
            #include <iostream>
            std::string s = "Hello";
            s.clear();
            std::cout << s.empty() << std::endl; // Outputs: 1 (true)
            ```
*   **Searching and Substrings**:
    *   **Finding Substrings**:
        *   You can search for a substring within a string using the **`.find()`** method.
        *   **`std::string::npos`** is a constant representing the end of the string, returned if the substring is not found.
        *   **Syntax / Example**:
            ```cpp
            #include <string>
            #include <iostream>
            std::string s = "Hello World";
            std::size_t pos = s.find("World");

            if (pos != std::string::npos) {  // Check if the substring is found
                std::cout << "Found 'World' at position: " << pos << std::endl;
            } else {
                std::cout << "'World' not found" << std::endl;
            }
            ```
    *   **Extracting Substrings**:
        *   The **`.substr()`** method allows you to extract a substring from a string.
        *   **Syntax / Example**:
            ```cpp
            #include <string>
            #include <iostream>
            std::string s = "Hello World";
            std::string sub = s.substr(6, 5); // Extracts "World" starting at position 6

            std::cout << sub << std::endl;  // Outputs: World
            ```
*   **Comparison of Strings**:
    *   Strings can be compared using comparison operators (**`==`**, **`!=`**, **`<`**, **`>`**, **`<=`**, **`>=`**), or the **`.compare()`** method.
    *   Comparisons are case-sensitive and performed lexicographically (dictionary order).
    *   **Syntax / Example**:
        ```cpp
        #include <string>
        #include <iostream>
        std::string s1 = "Hello";
        std::string s2 = "World";

        if (s1 == s2) {
            std::cout << "Strings are equal" << std::endl;
        } else if (s1 < s2) {
            std::cout << s1 << " is less than " << s2 << std::endl;
        } else {
            std::cout << s1 << " is greater than " << s2 << std::endl;
        }
        ```
*   **C-String Compatibility**:
    *   **`std::string`** can be converted to a C-string (**`const char*`**) using the **`.c_str()`** method, which is useful for compatibility with C-style functions.
    *   **Syntax / Example**:
        ```cpp
        #include <string>
        #include <iostream>
        std::string s = "Hello";
        const char* cstr = s.c_str();

        std::cout << cstr << std::endl; // Outputs: Hello
        ```
*   **Advanced Features**:
    *   **Iterating Over Stringstream**:
        *   **Iterating**:
            *   You can iterate over a string using a for loop, a range-based for loop, or iterators.
            *   **Syntax / Example**:
                ```cpp
                #include <string>
                #include <iostream>
                std::string s = "Hello";

                // Range-based for loop
                for (char c : s) {
                    std::cout << c << " ";
                }
                std::cout << std::endl;

                // Iterator-based loop
                for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
                ```
        *   **String Streams**:
            *   **`std::stringstream`** can be used for string manipulation and conversion, providing functionality similar to input/output streams.
            *   **Syntax / Example**:
                ```cpp
                #include <string>
                #include <iostream>
                #include <sstream>

                int main() {
                    std::stringstream ss;
                    ss << "Hello" << " " << "World!";
                    
                    std::string s = ss.str();  // Combines all output into a single string
                    std::cout << s << std::endl; // Outputs: Hello World!
                    
                    return 0;
                }
                ```
*   **Memory Management and Performance**
    *   **`std::string`** manages its **memory dynamically**, meaning it can grow or shrink as needed.
    *   The underlying memory is managed by the C++ Standard Library, but there are some considerations:
        *   **Capacity and Reserve**:
            *   You can pre-allocate memory using the **`.reserve()`** method to improve performance if you know the size in advance.
            *   **Syntax / Example**:
                ```cpp
                #include <string>
                #include <iostream>
                std::string s;
                s.reserve(100);  // Reserves space for 100 characters
                ```
        *   **Efficiency**: 
            *   Small strings are often optimized in modern C++ compilers using the "short string optimization" (SSO), which avoids dynamic memory allocation for short strings.
___

## Installation
[(Back to top)](#table-of-contents)

* Dowmload the project:
```
# Clone this repository
$ git clone https://github.com/P4r4dis/The_hospital.git

$ cd project
```

* After downloaded the project and gone to the root path SimpleCatCommand repository you can use the __Makefile__ for compile the program or the units tests and generate a __bynary__:

    * ```bash 
        $ make ex00
    * ```bash
         $ make test_run_ex00
## Usage/Examples
[(Back to top)](#table-of-contents)
```javascript
import Component from 'my-project'

function App() {
  return <Component />
}
```


## Running Tests
[(Back to top)](#table-of-contents)

To run tests, run the following command

```bash
  npm run test
```