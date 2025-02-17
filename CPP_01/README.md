
# CPP Pool for 42 and EPITECH school
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

*   __42 SCHOOL__: 
    *   MODULE 1 EXERCISES
*   __EPITECH SCHOOL__:
    *   DAY 07 EXERCICES
<br>
*   __With a series of exercises we will learning different C++ concepts.__
___

## MODULE 1 (42 SCHOOL) / DAY 07 (EPITECH SCHOOL)
___
## Table Of Contents

* [Setup CPP and Criterion](#setup-cpp-and-criterion)  
* [Description](#description)
* [Objectifs](#objectifs)
    * [42 Module 01 Objectifs](#42-module-01-objectifs)
    * [EPITECH Day 07 Objectifs](#epitech-day-07-objectifs)
* [Key Learnings](#key-learnings)
    *   [Memory Management](#memory-managment)
        *   [The Stack](#memory-managment-stack-anchor)
            *   [Characteristics of the Stack](#memory-managment-stack-characteristics-anchor)
            *   [Usage of the Stack](#memory-managment-stack-usage-anchor)
            *   [syntax / Example](#memory-managment-stack-example-anchor)
        *   [The Heap](#memory-managment-heap-anchor)
            *   [Characteristics of the Heap](#memory-managment-heap-characteristics-anchor)
            *   [Usage of the Heap](#memory-managment-heap-usage-anchor)
            *   [syntax / Example](#memory-managment-heap-example-anchor)
        *   [Comparison Between Stack and Heap](#memory-managment-comparaison-anchor)
    *   [Dynamic Memory Allocation](#dynamic-memory-allocation)
        *   [**`new`** Operator](#dynamic-memory-allocation-new-anchor)
            *   [Allocating a single instance with **`new`** Operator](#dynamic-memory-allocation-new-single-instance-anchor)
            *   [Allocating Dynamic Arrays with **`new`** Operator](#dynamic-memory-allocation-new-dynamic-array-anchor)
            *   [Initialization with **`new`** Operator](#dynamic-memory-allocation-new-initialization-anchor)
            *   [Initializing an object with **`new`** Operator](#dynamic-memory-allocation-new-initialization-object-anchor)
        *   [**`delete`** Operator](#dynamic-memory-allocation-delete-anchor)
            *   [Delete a single instance with **`delete`** Operator](#dynamic-memory-allocation-delete-single-instance-anchor)
            *  [Delete Dynamic Arrays with **`delete`** Operator](#dynamic-memory-allocation-delete-dynamic-array-anchor)
        *   [**`new`** and **`delete`** Operator Complete Example](#dynamic-memory-allocation-example-anchor)
    *   [Reference **`&`** Operator](#reference--operator)
        *   [Definition](#reference-definition)
        *   [Reference vs Pointer](#reference-reference-vs-pointer)
        *   [Types of References](#reference-types)
        *   [Usage of References](#reference-usage)
    *   [**`FStream`**](#fstream)
        *   [**`fstream`**](#fstream-file-inputoutput-stream-fstream-anchor)
        *   [**`ifsteram`**](#fsteram-file-inputoutput-stream-ifstream-anchor)
        *   [**`ofstream`**](#fsteram-file-inputoutput-stream-ofstream-anchor)
        *   [Summary of Differences](#fsteram-file-inputoutput-stream-summary-anchor)
    *   [Pointer to Members and Pointer to Members Functions](#pointer-to-members-and-pointer-to-members-functions)
        *   [Pointer to Members](#pointer-to-members-and-pointer-to-members-functions-pointer-to-members-anchor)
        *   [Pointer to Members Functions](#pointer-to-members-and-pointer-to-members-functions-pointer-to-members-functions-anchor)
    *   [Parametric Polymorphism](#parametric-polymorphism)
        *   [How Does it Work](#parametric-polymorphism-how-does-it-work-anchor)
        *   [Advantages](#parametric-polymorphism-advantages-anchor)
    *   [Default values](#default-values)
        *   [Advantages](#default-value-advantages-anchor)
    *   [**`static`** Keyword](#static-keyword)
        *   [**`static`** Global Variables](#static-global-variables-anchor)
        *   [**`static`** with Functions](#static-functions-anchor)
        *   [**`static`** Global Functions](#static-global-functions-anchor)
        *   [**`static`** with Class Members](#static-class-members-anchor)
    *   [**`explicit`** Keyword](#explicit-keyword)
        *   [The Problem of Implicit Conversions](#explicit-problem-implicit-conversion-anchor)
        *   [Avoid Implicit Conversion With **`explicit`**](#explicit-avoid-implicit-conversion-anchor)
        *   [Advantages of `explicit`](#explicit-advantages-anchor)
    *   [**`const`** Keyword](#const-keyword)
    *   [Smart Pointers](#smart-pointers)
    *   [Why Use Smart Pointers](#smart-pointers-why-use-smart-pointers-anchor)
    *   [Types of Smart Pointers](#smart-pointers-types-smart-pointers-anchor)
        *   [**`std::unique_ptr`**](#smart-pointers-types-smart-pointers-unique-ptr-anchor)
        *   [**`std::shared_ptr`**](#smart-pointers-types-smart-pointers-shared-ptr-anchor)
        *   [**`std::weak_ptr`**](#smart-pointers-types-smart-pointers-weak-ptr-anchor)
* [Installation](#installation)
* [Usage / Examples](#usageexamples)
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

#### 42 Module 01 Objectifs
[(Back to top)](#table-of-contents)

*   | ex00                  | Heap of quadrupeds        |
    | -------               | --------                  |
    | Turn-in directory     | ex00/                     |
    | Files to turn-in      | Makefile<br>Pony.cpp/hpp  |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |

    *   An easy one, to start with.
    *   Make a __Pony class__, containing whatever you think adequately describes a pony.
    *   Then, create two functions, **`ponyOnTheHeap`** and **`ponyOnTheStack`**, in which you will allocate a **`Pony`**, and make it do some stuff.
    *   Of course, in the first one, the **`Pony`** must be **allocated** on the **heap**, on in the second one it must be **allocated** on the **stack**.
    *   You will provide a main with enough code to prove what you made works as intended.
    *   In both cases, the **`Pony`** objects must not exist after the function hands off control.
    (Your main will also have to demonstrate this during the correction !)
    ___
*   | ex01                  | Plumbing problem          |
    | -------               | --------                  |
    | Turn-in directory     | ex01/                     |
    | Files to turn-in      | Makefile<br>ex01.cpp/hpp  |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   Again, a simple exercise.
    *   You must turn in the following function, after **correcting the memory leak** contained in it.
    *   Of course, you must play with the **memory allocation/deallocation** here.
    *   Simply re-moving the variable, or otherwise fiddling around the problem without actually sorting it out, will be considered a wrong answer...

    *   
        ```C++
        void memoryLeak()
        {
            std::string* panthere = new std::string("String panthere");
            std::cout << *panthere << std::endl;
        }
        ```
    ___

*   | ex02                  | BraiiiiiiinnnzzzZ         |
    | -------               | --------                  |
    | Turn-in directory     | ex02/                     |
    | Files to turn-in      | Makefile<br>Zombie.cpp/hpp<br>newZombie.cpp<br>randomChump.cpp    |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    
    *   First, implement a **`Zombie class`**.
        *   It has a string private attribute name.
        *   Add a member function **`void announce(void);`** to the **`Zombie class`**.
            *   Zombies announce themselves as follows:
                *   `<name>: BraiiiiiiinnnzzzZ...`
                    *   Don’t print the angle brackets (< and >).
                *   For a zombie named Foo, the message would be:
                    *   `Foo: BraiiiiiiinnnzzzZ...`
    *   Then, implement the two following functions:
        *   **`Zombie* newZombie(std::string name);`**
            *   It **creates a zombie**, **`name`** it, and **return it** so you can use it outside of the function scope.
        *   **`void randomChump(std::string name);`**
            *   It **creates a zombie**, **`name`** it, and the **zombie announces itself**.
    *   Now, what is the actual point of the exercise?
        *   You have to **determine in what case it’s better to allocate the zombies on the stack or heap**.
        *   Zombies must be **destroyed** when you don’t need them anymore.
        *   The **destructor** must **print a message with the `name` of the zombie** for debugging purposes.
___
*   | ex03                  | Moar brainz!              |
    | -------               | --------                  |
    | Turn-in directory     | ex03/                     |
    | Files to turn-in      | Makefile<br>Zombie.cpp/hpp<br>newZombie.cpp<br>randomChump.cpp<br>zombieHorde.cpp    |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    
    *   Time to create a **horde of Zombies**!
    *   Implement the following function in the appropriate file:
        *   **`Zombie* zombieHorde(int N, std::string name);`**
        *   It must **allocate N Zombie objects in a single allocation**.
        *   Then, it has to **initialize** the zombies, giving each one of them the **`name`** passed as parameter.
        *   The function **returns a pointer to the first zombie**.
        *   Implement your own tests to ensure your **`zombieHorde()`** function works as expected.
        *   Try to call **`announce()`** for each one of the zombies.
        *   Don’t forget to **delete all the zombies** and check for **memory leaks**.
___
*   | ex04                  | HI THIS IS BRAIN          |
    | -------               | --------                  |
    | Turn-in directory     | ex04/                     |
    | Files to turn-in      | Makefile<br>main.cpp      |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |

    *   Write a program that contains:
        *   A **string variable initialized to "`HI THIS IS BRAIN`"**.
        *   **`stringPTR`**: A pointer to the string.
        *   **`stringREF`**: A reference to the string.
    *   Your program has to print:
        *   The **memory address** of the string variable.
        *   The **memory address** held by **`stringPTR`**.
        *   The **memory address** held by **`stringREF`**.
    *   And then:
        *   The **value** of the string variable.
        *   The **value** pointed to by **`stringPTR`**.
        *   The **value** pointed to by **`stringREF`**.

    *   That’s all, no tricks.
    *   **The goal of this exercise is to demystify references which can
seem completely new**.
    *   Although there are some little differences, this is another syntax for something you already do: **address manipulation**.
___
*   | ex05                  | HI BRAIN THIS IS HUMAN    |
    | -------               | --------                  |
    | Turn-in directory     | ex05/                     |
    | Files to turn-in      | Makefile<br>Brain.cpp/hpp<br>Human.cpp/hpp<br>main.cpp      |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   Create a **Brain class**, with whatever you think befits a brain.
        *   It will have an **`identify()`** function, that returns a **`string`** containing the brain’s **address in memory**, in **hexadecimal** format, prefixed by **0x (For example, "0x194F87EA")**.
    *   Then, make a **Human class**, that has a **constant Brain attribute**, with the same lifetime.
        *   It has an **`identify()`** function, that just calls the **`identify()`** function of its **Brain** and **returns its result**.
    *   Now, make it so this code compiles and displays two identical adresses :
        ```C++
        int main()
        {
            Human bob;
            std::cout << bob.identify() << std::endl;
            std::cout << bob.getBrain().identify() << std::endl;
        }
        ```
        *   This code must be turned in as your **main**, and whatever you add to the **Human** or **Brain classes** in order to make it work must be **justified** (With another argument than "Er, yeah, well, i fiddled with it until it worked").
___
*   | ex06                  | Unnecessary violence    |
    | -------               | --------                  |
    | Turn-in directory     | ex06/                     |
    | Files to turn-in      | Makefile<br>Weapon.cpp/hpp<br>HumanA.cpp/hpp<br>HumanB.cpp/hpp<br>main.cpp      |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   Implement a **`Weapon` class** that has:
        *   A **private** attribute **`type`**, which is a **`string`**.
        *   A **`getType()`** member function that **returns a const reference to type**.
        *   A **`setType()`** member function that sets **`type` using the new one passed as parameter**.
    *   Now, create two **classes**: 
        *   **`HumanA`** and **`HumanB`**.
        *   They both have a **`Weapon`** and a **`name`**.
        *   They also have a member function **`attack()`** that displays (of course, without the angle brackets):
            *   **`<name> attacks with their <weapon type>`**
        *   **`HumanA`** and **`HumanB`** are almost the same except for these two tiny details:
            *   While **`HumanA`** takes the **`Weapon`** in its **constructor**, **`HumanB` doesn’t**.
            *   **`HumanB`** may not always have a **`Weapon`**, whereas **`HumanA` will always be armed**.
    *   If your implementation is correct, executing the following code will print an attack with "**crude spiked club**" then a second attack with "**some other type of club**" for both test cases:
        ```C++
        int main()
        {
            {
                Weapon club = Weapon("crude spiked club");
                HumanA bob("Bob", club);
                bob.attack();
                club.setType("some other type of club");
                bob.attack();
            }
            {
                Weapon club = Weapon("crude spiked club");
                HumanB jim("Jim");
                jim.setWeapon(club);
                jim.attack();
                club.setType("some other type of club");
                jim.attack();
            }
            return 0;
        }
        ```
    *   **Don’t forget to check for memory leaks**.
    *   In which case do you think it would be best to use a **pointer** to
        Weapon? And a **reference** to Weapon? Why? Think about it before
        starting this exercise.
___
*   | ex07                  | Sed is for losers         |
    | -------               | --------                  |
    | Turn-in directory     | ex07/                     |
    | Files to turn-in      | Makefile<br>*.cpp/hpp<br>main.cpp |
    | Forbidden functions   | std::string::replace      |
    | Remarks               | n/a                       |
    *   Create a program that takes three parameters in the following order:
        *   a **filename** and two **`strings`**, **s1** and **s2**.
    *   It will **open the file` <filename>`** and **copies its content into a new file `<filename>.replace`**, **replacing every occurrence of s1 with s2**.
    *   Using **C file manipulation functions is forbidden** and will be considered cheating.
    *   All the member functions of the class **`std::string`** are allowed, **except replace**.
    *   Use them wisely!
    *   Of course, **handle unexpected inputs and errors**.
    *   You have to create and turn in your own tests to ensure your program works as expected.
___
*   | ex08                  | I ain’t heard of no fancy switches |
    | -------               | --------                  |
    | Turn-in directory     | ex08/                     |
    | Files to turn-in      | Makefile<br>Human.cpp/hpp<br>main.cpp      |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   Use the following Human class :
        ```C++
        class Human
        {
            private:
                void meleeAttack(std::string const & target);
                void rangedAttack(std::string const & target);
                void intimidatingShout(std::string const & target);
            public:
                void action(std::string const & action_name, std::string const & target);
        };
        ```
    *   **Implement all these functions**, the first three will simply output something to the standard output so you can see they’ve been called, and the last one will have to call the appropriate action on the appropriate target.
    *   You must use an **array of pointers to members** to select which function to call:
        *   **using multiple if statements, or switch statements, is forbidden.**
___
*   | ex09                  | I ain’t heard of no fancy switches |
    | -------               | --------                  |
    | Turn-in directory     | ex09/                     |
    | Files to turn-in      | Makefile<br>Logger.cpp/hpp<br>main.cpp |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   Make a **`Logger` class** that must, well, do some logging.
    *   It will have two **private functions**, **`logToConsole`** and **`logToFile`**, that both take a **`string`** and will respectively **write** it to the **standard output** and **append** it to a **file**, **which name will be stored in the Logger at creation time**.
    *   You will also make a **private function** called **`makeLogEntry`** that will take a simple message as a **`string`**, and return a new **`string`** containing the **message formatted to look like a legitimate log entry**.
    *   At the very minimum, **add the current date before the message**, so we see when it’s been logged.
    *   Finally, create a **`log(std::string const & dest, std::string const & message)`**, that will make a log entry with the message, and pass it to **`logToFile`** or **`logToConsole`**, depending on the **`dest`** parameter.
    *   As in the previous exercise, **you have to use pointers to members** to select which function to call.
___
*   | ex10                  | Harl 2.0 |
    | -------               | --------                  |
    | Turn-in directory     | ex10/                     |
    | Files to turn-in      | Makefile<br>Harl.cpp/hpp<br>main.cpp |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   Do you know Harl? We all do, do we? In case you don’t, find below the kind of comments Harl makes.
    *   They are classified by levels:
        *   **"DEBUG" level**:
            *   Debug messages contain contextual information.
            *   They are mostly used for problem diagnosis.
            *   Example:
                *   **`"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"`**
        *   **"INFO" level**:
            *   These messages contain extensive information.
            *   They are helpful for tracing program execution in a production environment.
            *   Example:
                *   **`"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"`**
        *   **"WARNING" level**:
            *   Warning messages indicate a potential issue in the system.
            *   However, it can be handled or ignored.
            *   Example:
                *   **`"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."`**
        *   **"ERROR" level**:
            *   These messages indicate an unrecoverable error has occurred.
            *   This is usually a critical issue that requires manual intervention.
            *   Example:
                *   **`"This is unacceptable! I want to speak to the manager now."`**
    *   You are going to automate Harl.
    *   It won’t be difficult since it always says the same things.
    *   You have to create a **`Harl` class** with the following **`private` member functions**:
        *   **`void debug( void );`**
        *   **`void info( void );`**
        *   **`void warning( void );`**
        *   **`void error( void );`**
        *   **`Harl`** also has a **`public` member function** that calls the four member functions above depending on the level passed as parameter:
            *   **`void complain( std::string level );`**
    *   The **goal** of this exercise is to use **pointers to member functions**.
    *   **This is not a suggestion**.
    *   **`Harl` has to complain without using a forest of if/else if/else**.
    *   It doesn’t think twice!
    *   Create and turn in tests to show that Harl complains a lot.
    *   You can use the examples of comments listed above in the subject or choose to use comments of your own.
___
*   | ex11                  | Harl filter |
    | -------               | --------                  |
    | Turn-in directory     | ex11/                     |
    | Files to turn-in      | Makefile<br>Harl.cpp/hpp<br>main.cpp |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   Sometimes you don’t want to pay attention to everything Harl says.
    *   Implement a system to filter what Harl says depending on the log levels you want to listen to.
    *   **Create a program that takes as parameter one of the four levels.**
    *   **It will display all messages from this level and above.**
    *   For example:
        ```
        $> ./harlFilter "WARNING"
        [ WARNING ]
        I think I deserve to have some extra bacon for free.
        I've been coming for years whereas you started working here since last month.

        [ ERROR ]
        This is unacceptable, I want to speak to the manager now.

        $> ./harlFilter "I am not sure how tired I am today..."
        [ Probably complaining about insignificant problems ]
        ```
    *   Although there are several ways to deal with Harl, **one of the most effective is to `SWITCH` it off**.
    *   Give the name **harlFilter** to your executable.
    *   You must use, and maybe discover, the **`switch` statement** in this exercise.
___
*   | ex12                  | Cat o’ nine tails |
    | -------               | --------                  |
    | Turn-in directory     | ex12/                     |
    | Files to turn-in      | Makefile<br>*.cpp/hpp<br>main.cpp |
    | Forbidden functions   | None                      |
    | Remarks               | n/a                       |
    *   Make a **cato9tails** program that does the same thing as the system’s **`cat`** command without options.
    *   It can take **read from files and/or the standard input**.
    * Be thorough in your testing, this is not as simple as it seems.
___
#### EPITECH Day 07 Objectifs
[(Back to top)](#table-of-contents)
##### Day 07 Morning
___
__Exercise 00 - The Federation__
*   | ex00                  | Federation                |
    | -------               | --------                  |
    | Turn-in directory     | ex00/                     |
    | Files to turn-in      | Makefile,<br> Federation.cpp/hpp,<br>WarpSystem.cpp/hpp|
    | Forbidden functions   | None                      |
    | Remarks               | You must turn in your complete program, including your main function.<br>Your Makefile must generate a a.aout or Federation executable.|

    *   The __United Planets Federation__ is an alliance of people able to travel through space.
    *   They all possess the distortion speed – or warp – technology, letting them travel through subspace, and all share common values.
    *   __Starfleet__ is an organization tightly coupled to the __Federation__.
    *   Its primary mission is to collect as much information as possible about the __Universe__ (and life and everything).
    *   The fleet also has a defensive purpose (which is why all their vessels are prepped and armed), which can turn offensive if need be.
    *   You must create a Federation namespace, which contains all the elements that allow the __Federation__ to exist.
    *   Within the __`Federation` namespace__, create a nested __`Starfleet` namespace__.
    *   It contains a __`Ship` class__, which will be used to create spaceships.
    *   Each Ship must have the following attributes:
        *   __`int _length;`__
        *   __`int _width;`__
        *   __`std::string _name;`__
        *   __`short _maxWarp;`__
            *   These properties must all be provided during the __`Ship’__'s construction, and cannot be later modified.
    *   The class constructor must have the following prototype:
        *   __`Ship(int length, int width, std::string name, short maxWarp);`__
        *   Upon creation, each Ship prints the following to the standard output:
            *   ```
                The ship USS [NAME] has been finished.
                It is [LENGTH] m in length and [WIDTH] m in width.
                It can go to Warp [MAXWARP]!
            *   You must of course replace [NAME], [LENGTH], [WIDTH] and [MAXWARP] with the approriate values.
    *   Each Ship requires a complex system to navigate through space, which you must have to provide.
    *   As this system is not exclusive to the __Federation’s `Ships`__, you must create a new __`WarpSystem`__ namespace.
    *   This namespace will house the __`QuantumReactor` class__, with a single attribute:
        *   __`bool _stability;`__
        *   which will not be provided during the object’s construction, but will instead be set to `true` by default.
    *   You must also provide an __`isStable` member function__ which verifies the stability of the __`QuantumReactor`__, as well as a __`setStability` member function__ which can modify it:
        *   __`bool isStable();`__
        *   __`void setStability(bool stability);`__
    *   __`WarpSystem`__ will also contain a __`Core` class__ with a single attribute:
        *   __`QuantumReactor *_coreReactor;`__
        *   This pointer to __`QuantumReactor`__ must be provided when constructing the object.
        *   A __`checkReactor()` member function__ will provide access to the reactor, by returning a __pointer__ to the __`QuantumReactor`__.<br><br><br><br>
    *   The __`Ship` class__ can now have a __``setupCore`` member function__, taking a __pointer__ to a __`Core`__ as a parameter and returning nothing.
    *   This function will hold the __`Core`__ in the __`Ship`__ and print the following to the standard output:
        *   `USS [NAME]: The core is set.`
    *   __`Ship`__ should also have a __`checkCore` member function__ taking no parameters and printing the following to the standard output:
        *   `USS [NAME]: The core is [STABILITY] at the time.`
    *   `[STABILITY]` must be replaced by “stable” if `stability` is `true` and by “unstable” otherwise.
    *   It must also be possible to create __`Ship` objects__ that do not belong to the __`Starfleet`__.
    *   These __objects have the same functions and attributes as the other Ships__, but the __building process is slightly different__.
    *   An __`independent ship`__ has a maximum speed of 1. Upon creation, it prints the following:
        *   ```
            The independent ship [NAME] just finished its construction.
            It is [LENGTH] m in length and [WIDTH] m in width.
    *   The other function's output may also be different, as you will see in the example.<br>
    *   The following code must compile and print out what follows:
        ```CPP
        int main()
        {
            Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
            Federation::Ship Independent(150, 230, "Greok");
            WarpSystem::QuantumReactor QR;
            WarpSystem::QuantumReactor QR2;
            WarpSystem::Core core(&QR);
            WarpSystem::Core core2(&QR2);
            UssKreog.setupCore(&core);
            UssKreog.checkCore();
            Independent.setupCore(&core2);
            Independent.checkCore();
            QR.setStability(false);
            QR2.setStability(false);
            UssKreog.checkCore();
            Independent.checkCore();

            return 0;
        }
        ```
        ```CPP
        output:
        ∼/B-CPP-300> g++ -W -Wall -Werror -Wextra *.cpp
        ∼/B-CPP-300> ./a.out | cat -e
        The ship USS Kreog has been finished.$
        It is 289 m in length and 132 m in width.$
        It can go to Warp 6!$
        The independent ship Greok just finished its construction.$
        It is 150 m in length and 230 m in width.$
        USS Kreog: The core is set.$
        USS Kreog: The core is stable at the time.$
        Greok: The core is set.$
        Greok: The core is stable at the time.$
        USS Kreog: The core is unstable at the time.$
        Greok: The core is unstable at the time.$
        ```
___

__Exercise 01 - The Borgs__
*   | ex01                  | Borg           |
    | -------               | --------                  |
    | Turn-in directory     | ex01/                     |
    | Files to turn-in      | Makefile,<br> Federation.cpp/hpp,<br>WarpSystem.cpp/hpp<br> Borg.cpp/hpp |
    | Forbidden functions   | None                      |
    | Remarks               | You must turn in your complete program, including your main function.<br>Your Makefile must generate a Borg executable.|

    *   You must reuse the __`Federation`__ and __`WarpSystem`__ files from the previous exercise.
    *   The universe is a big place.
        Spreading their influence from the Delta quandrant, the Borgs are a dangerous race and have incredible technology in their possession, thanks to their power of assimilation.
    *   Create a __`Borg`__ namespace containing a __`Ship`__ class.
    *   The __`Borg’s Ships`__ are different from the Federation’s in many aspects:
        *   first and foremost, they have the shape of a cube. Thus, they have no width and height, but a single side length;
        *   they have no name either.
    *   Their attributes must be:
        *   __`int _side;`__
        *   __`short _maxWarp;`__
    *   The Borg vessels are built from a unique model:
        *   their side is 300 meters long
        *   their maximum speed is Warp 9.
        *   These values are not provided upon construction.
    *   When a __`Borg Ship`__ is built, it prints the following to the standard output:
        ```
        We are the Borgs. Lower your shields and surrender yourselves unconditionally.
        Your biological characteristics and technologies will be assimilated.
        Resistance is futile.
        ```
    *   A Borg vessel does not print anything when installing a __Core__.
    *   When verifying it however, it prints, if stability is `true`:
        *   `Everything is in order.`
        *   or, if stability is not `true`:
        *   `Critical failure imminent.`
___

## Key Learnings
[(Back to top)](#table-of-contents)
*   [Memory Management](#memory-managment)
    *   [The Stack](#memory-managment-stack-anchor)
        *   [Characteristics of the Stack](#memory-managment-stack-characteristics-anchor)
        *   [Usage of the Stack](#memory-managment-stack-usage-anchor)
        *   [syntax / Example](#memory-managment-stack-example-anchor)
    *   [The Heap](#memory-managment-heap-anchor)
        *   [Characteristics of the Heap](#memory-managment-heap-characteristics-anchor)
        *   [Usage of the Heap](#memory-managment-heap-usage-anchor)
        *   [syntax / Example](#memory-managment-heap-example-anchor)
    *   [Comparison Between Stack and Heap](#memory-managment-comparaison-anchor)
*   [Dynamic Memory Allocation](#dynamic-memory-allocation)
    *   [**`new`** Operator](#dynamic-memory-allocation-new-anchor)
        *   [Allocating a single instance with **`new`** Operator](#dynamic-memory-allocation-new-single-instance-anchor)
        *   [Allocating Dynamic Arrays with **`new`** Operator](#dynamic-memory-allocation-new-dynamic-array-anchor)
        *   [Initialization with **`new`** Operator](#dynamic-memory-allocation-new-initialization-anchor)
        *   [Initializing an object with **`new`** Operator](#dynamic-memory-allocation-new-initialization-object-anchor)
    *   [**`delete`** Operator](#dynamic-memory-allocation-delete-anchor)
        *   [Delete a single instance with **`delete`** Operator](#dynamic-memory-allocation-delete-single-instance-anchor)
        *  [Delete Dynamic Arrays with **`delete`** Operator](#dynamic-memory-allocation-delete-dynamic-array-anchor)
    *   [**`new`** and **`delete`** Operator Complete Example](#dynamic-memory-allocation-example-anchor)
*   [Reference **`&`** Operator](#reference--operator)
    *   [Definition](#reference-definition)
    *   [Reference vs Pointer](#reference-reference-vs-pointer)
    *   [Types of References](#reference-types)
    *   [Usage of References](#reference-usage)
*   [**`FStream`**](#fstream)
    *   [**`fstream`**](#fstream-file-inputoutput-stream-fstream-anchor)
    *   [**`ifsteram`**](#fsteram-file-inputoutput-stream-ifstream-anchor)
    *   [**`ofstream`**](#fsteram-file-inputoutput-stream-ofstream-anchor)
    *   [Summary of Differences](#fsteram-file-inputoutput-stream-summary-anchor)
*   [Pointer to Members and Pointer to Members Functions](#pointer-to-members-and-pointer-to-members-functions)
    *   [Pointer to Members](#pointer-to-members-and-pointer-to-members-functions-pointer-to-members-anchor)
    *   [Pointer to Members Functions](#pointer-to-members-and-pointer-to-members-functions-pointer-to-members-functions-anchor)
*   [Parametric Polymorphism](#parametric-polymorphism)
    *   [How Does it Work](#parametric-polymorphism-how-does-it-work-anchor)
    *   [Advantages](#parametric-polymorphism-advantages-anchor)
*   [Default values](#default-values)
    *   [Advantages](#default-value-advantages-anchor)
*   [**`static`** Keyword](#static-keyword)
    *   [**`static`** Global Variables](#static-global-variables-anchor)
    *   [**`static`** with Functions](#static-functions-anchor)
    *   [**`static`** Global Functions](#static-global-functions-anchor)
    *   [**`static`** with Class Members](#static-class-members-anchor)
*   [**`explicit`** Keyword](#explicit-keyword)
    *   [The Problem of Implicit Conversions](#explicit-problem-implicit-conversion-anchor)
    *   [Avoid Implicit Conversion With **`explicit`**](#explicit-avoid-implicit-conversion-anchor)
    *   [Advantages of `explicit`](#explicit-advantages-anchor)
*   [**`const`** Keyword](#const-keyword)
*   [Smart Pointers](#smart-pointers)
*   [Why Use Smart Pointers](#smart-pointers-why-use-smart-pointers-anchor)
*   [Types of Smart Pointers](#smart-pointers-types-smart-pointers-anchor)
    *   [**`std::unique_ptr`**](#smart-pointers-types-smart-pointers-unique-ptr-anchor)
    *   [**`std::shared_ptr`**](#smart-pointers-types-smart-pointers-shared-ptr-anchor)
    *   [**`std::weak_ptr`**](#smart-pointers-types-smart-pointers-weak-ptr-anchor)
## Lessons Learned
[(Back to top)](#table-of-contents)
#### Memory Managment
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
*   In C++, __memory__ is divided into several regions:
    *   **Static Memory**:
        *   Used for **global variables** and **constants**.
        *   It is **allocated** at the **beginning** of the program's execution and **remains allocated** until the **end**.
    *   **Stack Memory**:
        *   Used for **local variables** and **function** calls.
    *   **Heap Memory**:
        *   Used for **dynamic memory**, **manually allocated** by the programmer.
*   **<a id="memory-managment-stack-anchor"></a>The Stack:**
    *   **<a id="memory-managment-stack-characteristics-anchor"></a>Characteristics of the Stack:**
        *   **Size**:
            *   The **stack** has a **limited size**, usually defined by the operating system or the program’s settings.
        *   **Speed**:
            *   Access to the **stack** is very **fast** because the **stack** is **managed automatically** by the processor.
        *   **Organization**:
            *   The **stack** follows a **LIFO (Last In, First Out)** structure.
            *   This means that the **last piece of data added will be the first one removed**.
        *   **Allocation and Deallocation**:
            *   **Memory** on the **stack** is **allocated** and **deallocated automatically**.
            *   When you enter a function, **local variables** are **allocated** on the **stack**, and when the function ends, these **variables** are **automatically deallocated**.
    *   **<a id="memory-managment-stack-usage-anchor"></a>Usage of the Stack:**
        *   The stack is primarily used for:
            *   **Local Variables**:
                *   **All variables defined** within a function (**that are not static**) are **stored** on the **stack**.
            *   **Function Calls**:
                *   When a **function** is **called**, a **memory block** (called a **stack frame**) is **created** to **store local variables** and **return information**.
    *   **<a id="memory-managment-stack-example-anchor"></a>Syntax / Example:**
        *   ```C++
            void function() {
                int a = 10;  // Stored on the stack
                int b = 20;  // Stored on the stack
            }
            ```
        *   In this example, the variables **`a`** and **`b`** are **allocated** on the **stack**.
        *   They are **automatically deallocated** when the **function ends**.
*   **<a id="memory-managment-heap-anchor"></a>The Heap:**
    *   **<a id="memory-managment-heap-characteristics-anchor"></a>Characteristics of the Heap:**
        *   **Size**:
            *   The **heap** has a much **larger size** than the **stack**, but it is **limited** by the **physical memory** of the machine.
        *   **Speed**:
            *   **Access** to the **heap** is ((slower)) than access to the **stack** because **memory management** is more **complex**.
        *   **Organization**:
            *   The **heap** is **less organized** than the **stack**.
            *   It is a **free memory space** where **memory** can be **allocated** and **deallocated in any order**.
        *   **Allocation and Deallocation**:
            *   **Memory** on the **heap** must be **manually allocated** and **deallocated** by the programmer using the **`new`** and **`delete`** operators in C++.
    *   **<a id="memory-managment-heap-usage-anchor"></a>Usage of the Heap:**
        *   The **heap** is used for:
            *   **Objects with a lifetime beyond a single function**:
                *   If an **object** or **variable** needs to **persist** even after a function ends, it is best to **allocate** it on the **heap**.
            *   **Large Data Structures**:
                *   **Large structures** like **dynamic arrays**, **linked lists**, etc., are usually **allocated** on the **heap**.
    *   **<a id="memory-managment-heap-example-anchor"></a>Syntax / Example:**
        *   ```C++
            void function() {
                int* p = new int;   // Dynamic allocation on the heap
                *p = 10;
                delete p;           // Freeing the memory
            }
            ```
        *   In this example, an integer is **dynamically allocated** on the **heap** using the **`new`** operator.
        *   It is **important to free** this **memory** with **`delete`** to **avoid memory leaks**.
    *   **<a id="memory-managment-comparaison-anchor"></a>Comparison Between Stack and Heap:**
        *   | Characteristic | Stack | Heap |
            |----------------|-------|------|
            | Size | Limited | Large<br>depends on available memory |
            | Speed | Very fast | Slower than the **stack** |
            | Management | Automatic | Manual (**`new`**/**`delete`**) |
            | Organization | LIFO | No specific organization |
            | Usage | Local variables<br>function calls | Dynamic memory<br>objects with long lifetimes |
___
### Dynamic Memory Allocation
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
*   The **`new`** and **`delete`** operators are used for **dynamic memory management**, meaning memory that is **manually allocated** during the program's execution. 
*   Understanding how to use these operators is crucial for creating **flexible** and **efficient** programs.
*   **Memory Management**:
    *   **Stack**:
        *   **Static Memory Allocation**:
            *   **Memory** is **allocated at compile time**, and the size of variables must be known in advance.
            *   This **memory** is **automatically released** at the end of the variable's scope.
    *   **Heap**:
        *   **Dynamic Memory Allocation**:
            *   **Memory** is **allocated at runtime**, and the **size** of the data can be **determined dynamically**.
            *   This **memory** must be **explicitly released manually**.
<br>

*   **<a id="dynamic-memory-allocation-new-anchor"></a>`new` Operator:**
    *   The **`new`** operator **allocates memory on the heap** and **returns a pointer to that memory**.
    *   It can be used to allocate a single instance of a data type or an array of instances.
    *   **<a id="dynamic-memory-allocation-new-single-instance-anchor"></a>Allocating a single instance with `new` Operator:**
        *   **Syntax / Example**:
            *   `int* ptr = new int;   // Allocates an integer on the heap`
    *   **<a id="dynamic-memory-allocation-new-dynamic-array-anchor"></a>Allocating Dynamic Arrays with `new` Operator:**
        *   You can also use **`new`** to **allocate dynamic arrays**.
        *   **Syntax / Example**:
            *   `int* array = new int[10];  // Allocates an array of 10 integers on the heap`
    *   **<a id="dynamic-memory-allocation-new-initialization-anchor"></a> Initialization with `new` Operator:**
        *   The **`new`** operator can also be used to **initialize values during allocation**.
        *   **Syntax / Example**:
            *   `int* ptr = new int(25);  // Allocates an integer and initializes it to 25`
    *   **<a id="dynamic-memory-allocation-new-initialization-object-anchor"></a> Initializing an object with `new` Operator:**
        *   The **`new`** operator can also be used to **initialize Object during allocation**.
        *   **Syntax / Example**:   
            ```C++
            // file.hpp
            #include <iostream>
            #include <string>

            class Student
            {
                public:
                    Student(void);
                    Student(std::string login);
                    ~Student(void);
                    
                private:
                    std::string     _login;
            };

            // file.cpp
            Student::Student(void)
            {
                std::cout << "Student created!" << std::endl;
            }

            Student::Student(std::string login) :   _login(login)
            {
                std::cout << "Student " << _login << " created!" << std::endl;
            }

            Student::~Student(void)
            {
                std::cout << "Student " << _login << " destroyed!" << std::endl;
            }
            
            // main.cpp
            int main(void)
            {
                Student     bob_student = Student("Bob"); // Allocates an object on the Stack
                Student     *joe_student = new Student("Joe"); // Allocates an dynamic object on the Heap

                delete joe_student; // free Object allocated on the Heap
                
                Student     *students = new Student[5]; // Allocated an array of 5 Student object on the Heap

                delete [] students; // free Array Object allocated on the Heap
                return 0;
            }

            output:
            Student Bob created!
            Student Joe created!
            Student Joe destroyed!
            Student created!
            Student created!
            Student created!
            Student created!
            Student created!
            Student destroyed!
            Student destroyed!
            Student destroyed!
            Student destroyed!
            Student destroyed!
            Student Bob destroyed!
            ```
*   **<a id="dynamic-memory-allocation-delete-anchor"></a>`delete` Operator:**
    *   The **`delete`** operator is used to **free memory** that was **dynamically allocated by `new`**.
    *   **<a id="dynamic-memory-allocation-delete-single-instance-anchor"></a>Delete a single instance with `delete` Operator:**
        *   **Syntax / Example**:
            *   `delete ptr;  // Frees the memory allocated for an integer`
    *   **<a id="dynamic-memory-allocation-delete-dynamic-array-anchor"></a>Delete Dynamic Arrays with `delete` Operator:**
        *   When you **allocate a dynamic array with `new[]`**, you must **free the memory with `delete[]`**.
        *   **Syntax / Example**:
            *   `delete[] array;  // Frees the memory allocated for an array of 10 integers`
*   **<a id="dynamic-memory-allocation-example-anchor"></a>`new` and `delete` Operator Complete Example:**
    *   **Syntax / Example**:   
        ```C++
        // file.hpp
        #include <iostream>
        #include <string>

        class Student
        {
            public:
                Student(void);
                Student(std::string login);
                ~Student(void);
                
                std::string     getLogin(void) const;
                void            setLogin(std::string login);
            private:
                std::string     _login;
        };

        // file.cpp
        Student::Student(void)
        {
            std::cout << "Student created!" << std::endl;
        }

        Student::Student(std::string login) :   _login(login)
        {
            std::cout << "Student " << _login << " created!" << std::endl;
        }

        Student::~Student(void)
        {
            std::cout << "Student " << _login << " destroyed!" << std::endl;
        }
        
        std::string     Student::getLogin(void) const
        {
            return _login;
        }
        
        void            Student::setLogin(std::string login)
        {
            _login = login;
        }

        // main.cpp
        int main(void)
        {
            Student     bob_student = Student("Bob"); // Allocates an object on the Stack
            Student     *joe_student = new Student("Joe"); // Allocates an dynamic object on the Heap

            delete joe_student; // free Object allocated on the Heap
            
            Student     *students = new Student[5];
            
            for (int i = 0; i < 5; ++i)
                students[i].setLogin(std::to_string(i));
                
            for (int i = 0; i < 5; ++i)
                std::cout << "Student number: " << students[i].getLogin() << std::endl;

            delete [] students;

            // No need delete for `bob_student` object because he allocated on the stack.
            // `bob_student` is automatically deleted at the end
            return 0;
        }

        output:
        Student Bob created!
        Student Joe created!
        Student Joe destroyed!
        Student created!
        Student created!
        Student created!
        Student created!
        Student created!
        Student number: 0
        Student number: 1
        Student number: 2
        Student number: 3
        Student number: 4
        Student 4 destroyed!
        Student 3 destroyed!
        Student 2 destroyed!
        Student 1 destroyed!
        Student 0 destroyed!
        Student Bob destroyed! // Automatically free, no need delete operator
        ```
___
### Reference `&` Operator
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
*   **<a id="reference-definition"></a>Definition:**
    *   A reference is defined using the **`&`** operator.
    *   A reference in C++ is an **alias** for an existing variable.
    *   A reference is a **constant pointer**, which is **always dereferenced** and a reference is **never `NULL` / `nullptr`**.
    *   **Syntax:**
        ```C++
        int a = 5;
        int& ref = a; // 'ref' is a reference to 'a'
        ```
*   **<a id="reference-reference-vs-pointer"></a>Reference vs Pointer:**
    *   **Pointers**:
        *   Can be **reassigned to point to different variables**.
        *   They can also be **`nullptr`**.
        *   You have to **dereferenced pointer to have access to value**.
    *   **References**:
        *   **Cannot be reassigned once initialized**.
        *   **They are always bound to the variable they were initialized with**.
        *   A reference is **always dereferenced**.
    *   **Example**:
        ```C++
        int y = 5;
        int* p = &y;
        int& r = y;
        *p = 10;   // changes y to 10
        r = 15;    // also changes y to 15
        ```
*   **<a id="reference-types"></a>Types of References:**
    *   **Lvalue References**:
        *   **Definition**:
            *   The standard **reference** type that binds to **lvalues** (variables with a specific memory location).
            *   **Example**:
                ```C++
                int x = 100;
                int& ref = x;  // lvalue reference
                ```
    *   **Rvalue References**:
        *   **Definition**:
            *   Introduced in **C++11** to enable **`move` semantics**.
            *   They **bind** to **rvalues** (temporary objects).
            *   **Rvalue references** are used to **optimize performance** by enabling **`move` semantics**.
        *   **Syntax / Example**:
            ```C++
            int&& rref = 10;  // rvalue reference to a temporary integer
            void process(int&& value) {
                // Do something with value
            }

            process(20);  // 20 is an rvalue and optimize performance by move semantic
            ```
    *   **Const References**:
        *   **Definition**:
            *   Used to create a **read-only reference** to a variable.
            *   You **cannot modify the value of the variable through a const reference**.
        *   **Syntax / Example**:
            ```C++
            const int x = 10;
            const int& ref = x;
            // ERROR:
            // ref = 6; ref is const, impossible to modify the value.
            ```
*   **<a id="reference-usage"></a>Usage of References:**
    *   **Passing by Reference**:
        *   **Function Arguments**:
            *   **Non-const Reference**:
                *   Allows **modification** of the **argument**.
                *   **Syntax / Example**:
                    ```C++
                    void increment(int& value) {
                        value++;
                    }

                    int num = 5;
                    increment(num);  // num becomes 6
                    ```
            *   **Const Reference**:
                *   **Prevents modification** of the argument.
                *   Useful for passing large objects to **avoid copying**.
                *   **Syntax / Example**:
                    ```C++
                    void print(const std::string& str) {
                        std::cout << str << std::endl;
                    }

                    std::string text = "Hello, World!";
                    print(text);  // text remains unchanged\
                    ```
    *   **Returning by Reference**:
        *   **Returning by Reference**:
            *   Can be used to **return** a **reference to a variable or object**.
            *   Be careful not to **return a reference to a local variable as it will be destroyed once the function exits**.
            *   **Syntax / Example**:
                ```C++
                int global = 100;

                int& getGlobal() {
                    return global;
                }

                int& ref = getGlobal();
                ```
___
### FStream
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
In C++, the classes **`fstream`**, **`ifstream`**, and **`ofstream`** are used to handle file input/output operations.
They are part of the **`<fstream>`** library. Here's the main difference between them:
*   **<a id="fstream-file-inputoutput-stream-fstream-anchor"></a>`fstream`:**
    *   __Definition__:
        *   The **`fstream`** class is a combination of both **`ifstream`** (input) and **`ofstream`** (output).
        *   It allows you to open a file for both __reading and writing__.
    *   __Usage__: 
        *   You use **`fstream`** when you want to both __read and write__ to a file.
    *   __Constructor__:
        *   **`std::fstream file("filename");`**
        *   You can open the file using specific modes (__`std::ios::in`, `std::ios::out`__, etc.).
        *   By default, it opens the file in **read/write** mode.
        *   You need to specify modes if you want particular behavior (read-only or write-only).
    *   __Syntax / Example__:
        ```C++
        #include <fstream>
        std::fstream file("example.txt", std::ios::in | std::ios::out);
        ```
*   **<a id="fsteram-file-inputoutput-stream-ifstream-anchor"></a>`ifstream`:**
    *   __Definition__: 
        *   **`ifstream`** is used only to __read__ data from a file (input).
    *   __Usage__: 
        *   You use **`ifstream`** when you want to __read__ data from a file.
    *   __Constructor__:
        *   **`std::ifstream file("filename");`**
        *   Opens the file in __read-only__ mode by default (__`std::ios::in`__).
    *   __Reading from a File:__ 
        *   Use **`ifstream`** to __read__ data from a file, using the same operators (**`>>`** and **`getline`**) as for **`std::cin`**.
    *   __Checking if a File Opened Successfully:__
        *   Always check if the file opened correctly before trying to __read__ or __write__.
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
*   **<a id="fsteram-file-inputoutput-stream-ofstream-anchor"></a>`ofstream`:**
    *   __Definition__: 
        *   **`ofstream`** is used only to __write__ data to a file (output).
    *   __Usage__: 
        *   You use **`ofstream`** when you want to __write__ data to a file.
    *   __Constructor__:
        *   **`std::ofstream file("filename");`**
        *   Opens the file in __write-only__ mode by default (__`std::ios::out`__).
        *   If the file exists, its content will be __erased__.
        *   If the file doesn’t exist, **`ofstream`** will __create__ a new file.
    *   __Writing to a File:__ 
        *   Use **`ofstream`** to __write__ to a file, just like **`std::cout`**.
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
*   **<a id="fsteram-file-inputoutput-stream-summary-anchor"></a>Summary of Differences:**
    *   | Class | Default Opening Mode | Usage |
        |-------|----------------------|-------|
        | `fstream` |	Read and write (`std::ios::in` or `std::ios::out`) | To read / write data from a file |
        | `ifstream` | Read-only (`std::ios::in`)	| To read data from a file |
        | `ofstream` | Write-only (`std::ios::out`) | To write data to a file |
___
### Pointer to Members and Pointer to Members Functions
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
*   **<a id="pointer-to-members-and-pointer-to-members-functions-pointer-to-members-anchor"></a>Pointer to Members:**
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
*   **<a id="pointer-to-members-and-pointer-to-members-functions-pointer-to-members-functions-anchor"></a>Pointer to Members Functions:**
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
### Parametric Polymorphism
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
*   In C++, you can **create multiple functions with the same name but different parameter types**.
*   This is called **function overloading**.
*   It allows handling different types of **arguments**, which is a straightforward form of **polymorphism**.

*   **Example**:
    ```C++
    #include <iostream>

    void add(int a, int b) {
        int result = a + b;
        std::cout << "Addition of int: " << result << std::endl;
    }

    void add(float a, float b) {
        float result = a + b;
        std::cout << "Addition of float: " << result << std::endl;
    }

    void add(double a, double b) {
        double result = a + b;
        std::cout << "Addition of double: " << result << std::endl;
    }

    int main() {
        add(3, 4);         // Calls the int version
        add(3.2f, 4.3f);   // Calls the float version
        add(3.14, 2.71);   // Calls the double version

        return 0;
    }
    ```
*   **<a id="parametric-polymorphism-how-does-it-work-anchor"></a> How Does it Work:**
    *   **Function overloading**:
        *   You write **multiple functions with the same name**, but with **different parameter types** (**`int`**, **`float`**, **`double`**, etc...).
        *   The compiler selects the correct function based on the argument types you pass.
        *   The same function name, add, can be used for different data types.
*   **<a id="parametric-polymorphism-advantages-anchor"></a>Advantages:**
    *   **Simple and efficient**:
        *   No need to dive into complex concepts like templates.
    *   **Flexible**:
        *   You can easily add more versions of the function for other **types**, like **`long`**, **`short`**, etc.
___
### Default Values
*   A **default value** is a **value assigned to a function parameter**.
*   If an **argument is not provided for that parameter during the function call, the default value will be used**.
*   In C++, you can specify default values for parameters directly in the **function declaration**.
*   **Example**:
    ```C++
    #include <iostream>

    void greet(const std::string& name = "Guest") {
        std::cout << "Hello, " << name << "!" << std::endl;
    }

    int main() {
        greet("Alice");   // Call with an argument: "Alice"
        greet();          // Call without an argument, uses default value "Guest"

        return 0;
    }
    ```
*   **Parameters with default values must be placed after parameters without default values in the function definition**.
*   **Example**:
    ```C++
    // ERROR:
    void example(int a = 10, int b);  // Error: b has no default value but comes after a which has one.

    // CORRECT:
    void example(int a, int b = 10);  // Correct: a must be provided, b can be omitted.
    ```
*   **<a id="default-value-advantages-anchor"></a>Advantages:**
    *   **Simplicity**:
        *   You don’t have to provide values every time, especially if they are often the same.
    *   **Clarity**:
        *   The code is **more readable** when you don’t have to specify non-essential arguments in every function call.
    *   **Flexibility**:
        *   You can easily modify the function’s behavior without overloading it for simple variations.
___
### `static` Keyword
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
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
*   **<a id="static-global-variables-anchor"></a>static Global Variables:**
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
*   **<a id="static-functions-anchor"></a>`static` with Functions:**
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
*   **<a id="static-global-functions-anchor"></a>`static` Global Functions:**
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
            *   **Internal Linkage**: The `hiddenFunction` is only accessible within File.cpp, providing a **form of encapsulation** at the file level.
*   **<a id="static-class-members-anchor"></a>`static` with Class Members:**
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
### `explicit` Keyword
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
*   The **`explicit` keyword** in C++ is used to **prevent unwanted implicit conversions** and **accidental calls to constructors that take a single argument**.
*   It **provides more control** and **clarity** regarding when type conversions or function calls should occur.
*   **<a id="explicit-problem-implicit-conversion-anchor"></a>The Problem of Implicit Conversions:**
    *   In C++, when a constructor accepts a single argument, **the compiler may automatically convert one type to another by calling that constructor, sometimes unintentionally**.
    *   This can lead to **unexpected behaviors**.
    *   **Example**:
        ```C++
        #include <iostream>

        class MyClass {
        public:
            MyClass(int x) { std::cout << "Constructor called with " << x << std::endl; }
        };

        void func(MyClass obj) {
            std::cout << "Function called" << std::endl;
        }

        int main() {
            func(5);  // Implicit conversion: int -> MyClass
            return 0;
        }
        ```
    *   **Explanation**:
        *   Here, **`func` expects an object of type `MyClass`**.
        *   When you pass **`5`**, **the compiler automatically converts the integer `5` to a `MyClass` object by calling the constructor with that argument**.
        *   **The constructor is called implicitly**, even though that may not have been the intention.
Introducing the explicit Keyword
*   **<a id="explicit-avoid-implicit-conversion-anchor"></a>Avoid Implicit Conversion With `explicit` keyword:**
    *   To **avoid these implicit conversions**, you can use the **`explicit` keyword** before constructors that take a single argument.
    *   **This forces conversions to be done explicitly**, making the code **safer** and **clearer**.
    *   **Example**:
        ```C++
        #include <iostream>

        class MyClass {
        public:
            explicit MyClass(int x) { std::cout << "Constructor called with " << x << std::endl; }
        };

        void func(MyClass obj) {
            std::cout << "Function called" << std::endl;
        }

        int main() {
            // func(5);  // Error: no implicit conversion possible

            MyClass obj(5);  // Correct: explicit construction
            func(obj);       // Pass an object explicitly
            return 0;
        }
        ```
        *   **Explanation**:
            *   By adding **`explicit`** to the **constructor**, the implicit conversion from int to **`MyClass`** is forbidden.
            *   To call **`func`**, you must first explicitly create a MyClass object with **`MyClass obj(5);`**.
            *   This makes the code **clearer**:
                *   it is evident that a **`MyClass`** object is being created, rather than an implicit conversion from an integer.
*   **<a id="explicit-advantages-anchor"></a>Advantages of `explicit`:**
    *   **Prevents Unintentional Conversions**:
        *   The **`explicit` keyword** ensures that type conversions do **not occur automatically**.
        *   This **prevents bugs** due to accidental calls of constructors or **implicit conversions**.
    *   **Improves Readability**:
        *   The **code is more `explicit`** (hence the name of the keyword), making it easier to understand exactly what the program is doing.
    *   **Enhances Type Safety**:
        *   You **gain better control over the types used** and **how objects are created and passed to functions**.
___
### `const` Keyword
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
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
        test
___
### Smart Pointers
[(Back to top)](#table-of-contents)
[(Back to Key Learnings)](#key-learnings)
*   **Smart pointers** in C++ **are objects that automatically manage memory**.
*   They are **used to handle the lifetime of dynamic objects** and to **avoid memory leaks** and **management errors**.
*   Here’s an overview of the most common types of smart pointers and their usage.
*   **<a id="smart-pointers-why-use-smart-pointers-anchor"></a>Why Use Smart Pointers:**
    *   **Automatic Memory Management**:
        *   **Smart pointers** **automatically release memory** when they are no longer needed.
    *   **Prevention of Memory Leaks**:
        *   They **help avoid memory leaks** caused by forgetting to call **`delete`**.
    *   **Safety**:
        *   **They reduce the risk of accessing invalid pointers (dangling pointers)**.
*   **<a id="smart-pointers-types-smart-pointers-anchor"></a>Types of Smart Pointers:**
    *   **<a id="smart-pointers-types-smart-pointers-unique-ptr-anchor"></a>`std::unique_ptr`:**
        *   **Description**:
            *   A **smart pointer** that **exclusively owns an object**.
            *   No other **`unique_ptr`** can own the same object.
        *   **Usage**:
            *   **Ideal for managing the lifetime of objects that you own exclusively**.
        *   **Example**:
            ```C++
            #include <iostream>
            #include <memory>

            class MyClass {
            public:
                MyClass() { std::cout << "MyClass created\n"; }
                ~MyClass() { std::cout << "MyClass destroyed\n"; }
            };

            int main() {
                std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
                // MyClass will be destroyed automatically when ptr goes out of scope.
                return 0;
            }
            ```
    *   **<a id="smart-pointers-types-smart-pointers-shared-ptr-anchor"></a>`std::shared_ptr`:**
        *   **Description**:
            *   A **smart pointer** that allows **multiple `shared_ptr` instances to share ownership of the same object**.
            *   A **reference** count is used to **track how many `shared_ptr` point to the same object**.
        *   **Usage**:
            *   **Ideal when multiple parts of the code need to share ownership of the same object**.
        *   **Example**:
            ```C++
            #include <iostream>
            #include <memory>

            int main() {
                std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
                {
                    std::shared_ptr<int> ptr2 = ptr1; // ptr2 shares ownership with ptr1
                    std::cout << "Value: " << *ptr2 << ", Count: " << ptr2.use_count() << std::endl; // Count: 2
                } // ptr2 is destroyed here, but ptr1 still exists
                std::cout << "Count after ptr2 goes out of scope: " << ptr1.use_count() << std::endl; // Count: 1
                return 0;
            }
            ```
    *   **<a id="smart-pointers-types-smart-pointers-weak-ptr-anchor"></a>`std::weak_ptr`:**
        *   **Description**:
            *   A **smart pointer** that provides a **non-owning reference to an object** managed by a **`shared_ptr`**.
            *   It is used to **avoid reference cycles**.
        *   **Usage**:
            *   **Ideal for referencing an object without taking ownership, thus preventing memory leaks due to reference cycles**.
        *   **Example**:
            ```C++
            #include <iostream>
            #include <memory>

            class MyClass {
            public:
                MyClass() { std::cout << "MyClass created\n"; }
                ~MyClass() { std::cout << "MyClass destroyed\n"; }
            };

            int main() {
                std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();
                std::weak_ptr<MyClass> weakPtr = sharedPtr; // weakPtr does not change the reference count

                if (auto sp = weakPtr.lock()) { // Checks if the object still exists
                    std::cout << "MyClass is still alive\n";
                } else {
                    std::cout << "MyClass has been destroyed\n";
                }

                sharedPtr.reset(); // MyClass object is destroyed here
                if (auto sp = weakPtr.lock()) {
                    std::cout << "MyClass is still alive\n";
                } else {
                    std::cout << "MyClass has been destroyed\n";
                }

                return 0;
            }
            ```
___
## Installation
[(Back to top)](#table-of-contents)

* Dowmload the project:
```bash
# Clone this repository
$ git clone git@github.com:P4r4dis/EPITECH_42_CPP_POOL.git
# or 
$ git clone https://github.com/P4r4dis/EPITECH_42_CPP_POOL.git


$ cd CPP_01
```
___
## Usage/Examples
[(Back to top)](#table-of-contents)
* After downloaded the project and gone to the root path CPP_01 folder, you can use the __Makefile__ for compile the programs and generate a __bynary__ and run it directly.
*   __run the following command__:

    *   
        ```bash 
        $ cd EPITECH_42_CPP_POOL/CPP_01

        # Choose an 42 or EPITECH exercise:
        # 42 example:
        $ make 42_ex00

        # EPITECH example:
        $ make EPITECH_ex00
        ```
    *   
        ```bash
        $ cd EPITECH_42_CPP_POOL/CPP_01

        # You can check if there are memory leak:
        # Choose an 42 or EPITECH exercise:
        # 42 example:
        $ make 42_valgrind_ex00

        # EPITECH example:
        $ make EPITECH_valgrind_ex00
        ```

___
## Running Tests
[(Back to top)](#table-of-contents)
* After downloaded the project and gone to the root path CPP_01 folder, you can use the __Makefile__ for compile the units tests and generate a unit test __binary__ and run it directly.
* To run tests, run the following command:

    *   
        ```bash 
        $ cd EPITECH_42_CPP_POOL/CPP_01

        # Choose an 42 or EPITECH exercise:
        # 42 example:
        $ make 42_test_run_ex00

        # EPITECH example:
        $ make EPITECH_test_run_ex00

        # you can run units tests for all 42 and EPITECH exercices:
        $ make tests_run
        ```
    *   
        ```bash
        $ cd EPITECH_42_CPP_POOL/CPP_01

        # You can check if there are memory leak:
        # Choose an 42 or EPITECH exercise:
        # 42 example:
        $ make 42_valgrind_test_run_ex00

        # EPITECH example:
        $ make EPITECH_valgrind_test_run_ex00
        ```