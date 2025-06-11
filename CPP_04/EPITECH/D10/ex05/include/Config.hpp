/*
** Config.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Wed Jun 11 7:45:17 PM 2025 Paradis
** Last update Thu Jun 11 7:47:37 PM 2025 Paradis
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