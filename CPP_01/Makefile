# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2044/06/18 19:07:51 by Paradis           #+#    #+#              #
#    Updated: 2024/09/02 18:24:40 by Paradis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## RULES FOR 42 SCHOOL
# **************************************************************************** #
#																			   #
#								42 EX00										   #
#																			   #
# **************************************************************************** #
42_EX00_PATH 					= 	./42/M01/ex00
42_EX00_BIN_PATH 				= 	./42/M01/ex00/bin
42_EX00_SRC_PATH				=	./42/M01/ex00/source
42_EX00_INC_PATH				=	./42/M01/ex00/include
42_EX00_UT_PATH					=	./42/M01/ex00/test

42_EX00_NAME					=	Pony

42_EX00_UT_SRC					=	$(42_EX00_UT_PATH)/$(42_EX00_NAME)_test.cpp
42_EX00_UT_NAME 				= 	test_$(42_EX00_NAME)

42_EX00_SRC						=	$(42_EX00_SRC_PATH)/Pony.cpp \
									$(42_EX00_BIN_PATH)/main.cpp
42_EX00_OBJS					=	$(42_EX00_SRC:.cpp=.o)

42_ex00 						: 	fclean
									@$(MAKE) -C $(42_EX00_PATH)
									$(42_EX00_PATH)/$(42_EX00_NAME)

42_test_run_ex00				:	fclean
									@$(MAKE) -s -C $(42_EX00_UT_PATH)
									$(42_EX00_UT_PATH)/$(42_EX00_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
# @brave coverage.html

42_valgrind_ex00 				: 	fclean
									@$(MAKE) -C $(42_EX00_PATH) VALGRIND
									
42_valgrind_test_run_ex00		:	fclean
									@$(MAKE) -s -C $(42_EX00_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								42 EX01										   #
#																			   #
# **************************************************************************** #
42_EX01_PATH 					= 	./42/M01/ex01
42_EX01_BIN_PATH 				= 	./42/M01/ex01/bin
42_EX01_SRC_PATH				=	./42/M01/ex01/source
42_EX01_INC_PATH				=	./42/M01/ex01/include
42_EX01_UT_PATH					=	./42/M01/ex01/test

42_EX01_NAME					=	memoryLeak

42_EX01_UT_SRC					=	$(42_EX01_UT_PATH)/$(42_EX01_NAME)_test.cpp
42_EX01_UT_NAME 				= 	test_$(42_EX01_NAME)

42_EX01_SRC						=	$(42_EX01_SRC_PATH)/ex01.cpp \
									$(42_EX01_BIN_PATH)/main.cpp
42_EX01_OBJS					=	$(42_EX01_SRC:.cpp=.o)

42_ex01 						: 	fclean
									@$(MAKE) -C $(42_EX01_PATH)
									$(42_EX01_PATH)/$(42_EX01_NAME)

42_test_run_ex01				:	fclean
									@$(MAKE) -s -C $(42_EX01_UT_PATH)
									$(42_EX01_UT_PATH)/$(42_EX01_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
# @brave coverage.html

42_valgrind_ex01 				: 	fclean
									@$(MAKE) -C $(42_EX01_PATH) VALGRIND
									
42_valgrind_test_run_ex01		:	fclean
									@$(MAKE) -s -C $(42_EX01_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								42 EX02										   #
#																			   #
# **************************************************************************** #
42_EX02_PATH 					= 	./42/M01/ex02
42_EX02_BIN_PATH 				= 	./42/M01/ex02/bin
42_EX02_SRC_PATH				=	./42/M01/ex02/source
42_EX02_INC_PATH				=	./42/M01/ex02/include
42_EX02_UT_PATH					=	./42/M01/ex02/test

42_EX02_NAME					=	zombie

42_EX02_UT_SRC					=	$(42_EX02_UT_PATH)/$(42_EX02_NAME)_test.cpp
42_EX02_UT_NAME 				= 	test_$(42_EX02_NAME)

42_EX02_SRC						=	$(42_EX02_SRC_PATH)/Zombie.cpp \
									$(42_EX02_BIN_PATH)/main.cpp
42_EX02_OBJS					=	$(42_EX02_SRC:.cpp=.o)

42_ex02 						: 	fclean
									@$(MAKE) -C $(42_EX02_PATH)
									$(42_EX02_PATH)/$(42_EX02_NAME)

42_test_run_ex02				:	fclean
									@$(MAKE) -s -C $(42_EX02_UT_PATH)
									$(42_EX02_UT_PATH)/$(42_EX02_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
# @brave coverage.html

42_valgrind_ex02 				: 	fclean
									@$(MAKE) -C $(42_EX02_PATH) VALGRIND
									
42_valgrind_test_run_ex02		:	fclean
									@$(MAKE) -s -C $(42_EX02_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
# **************************************************************************** #
#																			   #
#								42 EX03										   #
#																			   #
# **************************************************************************** #
42_EX03_PATH 					= 	./42/M01/ex03
42_EX03_BIN_PATH 				= 	./42/M01/ex03/bin
42_EX03_SRC_PATH				=	./42/M01/ex03/source
42_EX03_INC_PATH				=	./42/M01/ex03/include
42_EX03_UT_PATH					=	./42/M01/ex03/test

42_EX03_NAME					=	zombie

42_EX03_UT_SRC					=	$(42_EX03_UT_PATH)/$(42_EX03_NAME)_test.cpp
42_EX03_UT_NAME 				= 	test_$(42_EX03_NAME)

42_EX03_SRC						=	$(42_EX03_SRC_PATH)/Zombie.cpp \
									$(42_EX03_BIN_PATH)/main.cpp
42_EX03_OBJS					=	$(42_EX03_SRC:.cpp=.o)

42_ex03 						: 	fclean
									@$(MAKE) -C $(42_EX03_PATH)
									$(42_EX03_PATH)/$(42_EX03_NAME)

42_test_run_ex03				:	fclean
									@$(MAKE) -s -C $(42_EX03_UT_PATH)
									$(42_EX03_UT_PATH)/$(42_EX03_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
# @brave coverage.html

42_valgrind_ex03 				: 	fclean
									@$(MAKE) -C $(42_EX03_PATH) VALGRIND
									
42_valgrind_test_run_ex03		:	fclean
									@$(MAKE) -s -C $(42_EX03_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								42 EX04										   #
#																			   #
# **************************************************************************** #
42_EX04_PATH 					= 	./42/M01/ex04
42_EX04_BIN_PATH 				= 	./42/M01/ex04/bin
42_EX04_SRC_PATH				=	./42/M01/ex04/source
42_EX04_INC_PATH				=	./42/M01/ex04/include
42_EX04_UT_PATH					=	./42/M01/ex04/test

42_EX04_NAME					=	zombie

42_EX04_UT_SRC					=	$(42_EX04_UT_PATH)/$(42_EX04_NAME)_test.cpp
42_EX04_UT_NAME 				= 	test_$(42_EX04_NAME)

42_EX04_SRC						=	$(42_EX04_BIN_PATH)/main.cpp
42_EX04_OBJS					=	$(42_EX04_SRC:.cpp=.o)

42_ex04 						: 	fclean
									@$(MAKE) -C $(42_EX04_PATH)
									$(42_EX04_PATH)/$(42_EX04_NAME)

42_test_run_ex04				:	fclean
									@$(MAKE) -s -C $(42_EX04_UT_PATH)
									$(42_EX04_UT_PATH)/$(42_EX04_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
# @brave coverage.html

42_valgrind_ex04 				: 	fclean
									@$(MAKE) -C $(42_EX04_PATH) VALGRIND
									
42_valgrind_test_run_ex04		:	fclean
									@$(MAKE) -s -C $(42_EX04_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Mon Aug 26 8:17:58 PM 2044 Paradis
## Last update Tue Sep 2 6:24:40 PM 2024 Paradis
##

## RULES FOR EPITECH SCHOOL

# **************************************************************************** #
#																			   #
#								EPITECH EX04								   #
#																			   #
# **************************************************************************** #


# **************************************************************************** #
#																			   #
#								GLOBAL RULES MAKEFILE						   #
#																			   #
# **************************************************************************** #
G++ 							= 	g++
INCFLAGS						= 	-I
CPPFLAGS 						= 	-Wall -Wextra -Werror -W -Wfatal-errors -std=c++98
CLEAN							=	clean
FCLEAN							=	fclean
RM								=	rm -rf

all								:	$(42_EX04_NAME)

$(42_EX04_NAME)					: 	$(42_EX04_OBJS)
									$(G++) $(CPPFLAGS) $(INCFLAGS)$(42_EX04_INC_PATH) $(42_EX04_OBJS) -o $(42_EX04_NAME)

clean							:	
									@$(MAKE) -s $(CLEAN) -C $(42_EX00_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX00_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX01_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX01_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX04_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX04_UT_PATH)
									

fclean							:	clean
									@$(MAKE) -s $(FCLEAN) -C $(42_EX00_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX00_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX01_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX01_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX04_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX04_UT_PATH)

tests_run						:	fclean \
									42_test_run_ex04

.PHONY							: 	all clean fclean re \
									tests_run \