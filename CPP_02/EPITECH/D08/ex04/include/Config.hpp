/*
** Config.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex04/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Mar 20 6:22:47 PM 2025 Paradis
** Last update Fri Mar 20 6:25:00 PM 2025 Paradis
*/

#ifndef CONFIG_HPP
#define CONFIG_HPP


#ifdef __has_include
#  if __has_include(<valgrind/valgrind.h>)
#    include <valgrind/valgrind.h>
#  else
#    define RUNNING_ON_VALGRIND 0
#  endif
#else
#  define RUNNING_ON_VALGRIND 0
#endif

#ifdef RUNNING_ON_VALGRIND
    #define GCOV_EXCL_IF_VALGRIND_START
    #define GCOV_EXCL_IF_VALGRIND_STOP
    #define GCOV_EXCL_IF_NOT_VALGRIND_START // GCOVR_EXCL_START
    #define GCOV_EXCL_IF_NOT_VALGRIND_STOP // GCOVR_EXCL_STOP
#else
    #define GCOV_EXCL_IF_VALGRIND_START // GCOVR_EXCL_START
    #define GCOV_EXCL_IF_VALGRIND_STOP // GCOVR_EXCL_STOP
    #define GCOV_EXCL_IF_NOT_VALGRIND_START __attribute__((no_instrument_function))
    #define GCOV_EXCL_IF_NOT_VALGRIND_STOP
#endif

#endif // CONFIG_HPP