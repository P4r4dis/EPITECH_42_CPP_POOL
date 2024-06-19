
# CPP Pool for 42 and EPITECH school
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

For Epitech CPP begins to Day 06 before we continue to work with C / c modular.
For 42 school, CPP starts to Day 00.
With a series of exercises we will learning different C++ concepts.



## Table Of Contents

* [Setup](#setup)  
* [Description](#description)
* [Objectifs](#objectifs)
    * [42 Objectifs](#42-objectifs)
    * [EPITECH Objectifs](#epitech-objectifs)
* [Key Learnings](#key-learnings)
* [Lessons](#lessons)
* [Installation](#installation)
* [Usage / Examples](#usage-/-examples)
* [Running Tests](#running-tests)
* [License](#license)
## Setup
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
        * libgit2 (libgit2-dev __version: libgit2-1:1.5.1-2, new version doesn't work__)
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
* ## Description
[(Back to top)](#table-of-contents)
These modules are designed to introduce you to Object-Oriented Programming.
Several languages are recommended for learning OOP. Because it is
derived from your good old friend C, we have chosen the C++ language.\

* __Compiling__
    * Compile your code with c++ and the flags __-Wall -Wextra -Werror__
    * Your code should compile if you add the flag __-std=c++98__ but personnaly i will use the last version of C++ with the flag __-std=c++23__.
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
    * Certain functions remain __prohibited__. Using the following functions will result in a score of 0: __*printf(), *alloc() and free()__.
    * Unless explicitly stated otherwise, the keywords using __namespace <ns_name>__ and __friend__ keywords are __prohibited__.
    * You are only allowed to use the __STL later__. Until then, the use of __Containers (vector/list/map/etc.) and Algorithms (anything that requires to include <algorithm>) is prohibited.__

* __Design requirements__
    * Memory leaks also exist in C++. When you allocate memory (using the __new__ keyword), __you must not have any memory leaks__.
    * Your classes must conform to the __canonical form__, in other word, __Coplien form__ unless explicitly specified otherwise.
    * A function implemented in a header file (except in the case of a template) will be given a score of 0.
    * You must be able to use your header files separately from each other.
    This is why they must include all the dependencies they require necessary. However, __you should avoid the problem of double inclusion by protecting them with include guards.__

## Objectifs
[(Back to top)](#table-of-contents)

#### 42 Objectifs
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
## Key Learnings
[(Back to top)](#table-of-contents)
* __Namespaces__
* __Classes__
* __Constructor(Default and Custrom)__, __Destructor__
* __Member Functions__
* __Initialisation lists__
* __Visibility/Encapsuslation__
* __Getter and Setter (Accessors and Mutators)__
* __stdio__, __iostream__, __iomanip__
* __static__, __const__
* __auto__
* __string__
    
## Lessons Learned
[(Back to top)](#table-of-contents)

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


## License
[(Back to top)](#table-of-contents)

[MIT](https://choosealicense.com/licenses/mit/)

