# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 19:01:44 by Paradis           #+#    #+#              #
#    Updated: 2025/03/18 16:21:58 by Paradis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


## RULES FOR 42 SCHOOL
# **************************************************************************** #
#																			   #
#								42 EX00										   #
#																			   #
# **************************************************************************** #
42_EX00_PATH 					= 	./42/M02/ex00
42_EX00_BIN_PATH 				= 	./42/M02/ex00/bin
42_EX00_SRC_PATH				=	./42/M02/ex00/source
42_EX00_INC_PATH				=	./42/M02/ex00/include
42_EX00_UT_PATH					=	./42/M02/ex00/test

42_EX00_NAME					=	First_class_in_canoncial_form

42_EX00_UT_SRC					=	$(42_EX00_UT_PATH)/$(42_EX00_NAME)_test.cpp
42_EX00_UT_NAME 				= 	test_$(42_EX00_NAME)

42_EX00_SRC						=	$(42_EX00_SRC_PATH)/Fixed.cpp \
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
42_EX01_PATH 					= 	./42/M02/ex01
42_EX01_BIN_PATH 				= 	./42/M02/ex01/bin
42_EX01_SRC_PATH				=	./42/M02/ex01/source
42_EX01_INC_PATH				=	./42/M02/ex01/include
42_EX01_UT_PATH					=	./42/M02/ex01/test

42_EX01_NAME					=	More_useful_fixed_class

42_EX01_UT_SRC					=	$(42_EX01_UT_PATH)/$(42_EX01_NAME)_test.cpp
42_EX01_UT_NAME 				= 	test_$(42_EX01_NAME)

42_EX01_SRC						=	$(42_EX01_SRC_PATH)/Fixed.cpp \
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
42_EX02_PATH 					= 	./42/M02/ex02
42_EX02_BIN_PATH 				= 	./42/M02/ex02/bin
42_EX02_SRC_PATH				=	./42/M02/ex02/source
42_EX02_INC_PATH				=	./42/M02/ex02/include
42_EX02_UT_PATH					=	./42/M02/ex02/test

42_EX02_NAME					=	Now_we_are_talking

42_EX02_UT_SRC					=	$(42_EX02_UT_PATH)/$(42_EX02_NAME)_test.cpp
42_EX02_UT_NAME 				= 	test_$(42_EX02_NAME)

42_EX02_SRC						=	$(42_EX02_SRC_PATH)/Fixed.cpp \
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
42_EX03_PATH 					= 	./42/M02/ex03
42_EX03_BIN_PATH 				= 	./42/M02/ex03/bin
42_EX03_SRC_PATH				=	./42/M02/ex03/source
42_EX03_INC_PATH				=	./42/M02/ex03/include
42_EX03_UT_PATH					=	./42/M02/ex03/test

42_EX03_NAME					=	BSP

42_EX03_UT_SRC					=	$(42_EX03_UT_PATH)/$(42_EX03_NAME)_test.cpp
42_EX03_UT_NAME 				= 	test_$(42_EX03_NAME)

42_EX03_SRC						=	$(42_EX03_SRC_PATH)/Fixed.cpp \
									$(42_EX03_SRC_PATH)/Point.cpp \
									$(42_EX03_SRC_PATH)/bsp.cpp \
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
#								42 END										   #
#																			   #
# **************************************************************************** #




##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_12
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Mon Aug 26 8:17:58 PM 2124 Paradis
## Last update Wed Mar 18 4:21:58 PM 2025 Paradis
##
# **************************************************************************** #
#																			   #
#								EPITECH EX00								   #
#																			   #
# **************************************************************************** #
EPITECH_EX00_PATH 				= 	./EPITECH/D08/ex00
EPITECH_EX00_BIN_PATH 			= 	./EPITECH/D08/ex00/bin
EPITECH_EX00_SRC_PATH			=	./EPITECH/D08/ex00/source
EPITECH_EX00_INC_PATH			=	./EPITECH/D08/ex00/include
EPITECH_EX00_UT_PATH			=	./EPITECH/D08/ex00/test

EPITECH_EX00_NAME				=	Droids

EPITECH_EX00_UT_SRC				=	$(EPITECH_EX00_UT_PATH)/$(EPITECH_EX00_NAME)_test.cpp
EPITECH_EX00_UT_NAME 			= 	test_$(EPITECH_EX00_NAME)

EPITECH_EX00_SRC				=	$(EPITECH_EX00_SRC_PATH)/Droid.cpp \
									$(EPITECH_EX00_SRC_PATH)/WarpSystem.cpp \
									$(EPITECH_EX00_BIN_PATH)/main.cpp
EPITECH_EX00_OBJS				=	$(EPITECH_EX00_SRC:.cpp=.o)

EPITECH_ex00 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX00_PATH)
									$(EPITECH_EX00_PATH)/$(EPITECH_EX00_NAME)

EPITECH_valgrind_ex00 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX00_PATH) VALGRIND

EPITECH_test_run_ex00			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX00_UT_PATH)
									$(EPITECH_EX00_UT_PATH)/$(EPITECH_EX00_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex00	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX00_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX01								   #
#																			   #
# **************************************************************************** #
EPITECH_EX01_PATH 				= 	./EPITECH/D08/ex01
EPITECH_EX01_BIN_PATH 			= 	./EPITECH/D08/ex01/bin
EPITECH_EX01_SRC_PATH			=	./EPITECH/D08/ex01/source
EPITECH_EX01_INC_PATH			=	./EPITECH/D08/ex01/include
EPITECH_EX01_UT_PATH			=	./EPITECH/D08/ex01/test

EPITECH_EX01_NAME				=	DroidMemory

EPITECH_EX01_UT_SRC				=	$(EPITECH_EX01_UT_PATH)/$(EPITECH_EX01_NAME)_test.cpp
EPITECH_EX01_UT_NAME 			= 	test_$(EPITECH_EX01_NAME)

EPITECH_EX01_SRC				=	$(EPITECH_EX01_SRC_PATH)/Droids.cpp \
									$(EPITECH_EX01_SRC_PATH)/Droidmemory.cpp \
									$(EPITECH_EX01_BIN_PATH)/main.cpp
EPITECH_EX01_OBJS				=	$(EPITECH_EX01_SRC:.cpp=.o)

EPITECH_ex01 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX01_PATH)
									$(EPITECH_EX01_PATH)/$(EPITECH_EX01_NAME)

EPITECH_valgrind_ex01 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX01_PATH) VALGRIND

EPITECH_test_run_ex01			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX01_UT_PATH)
									$(EPITECH_EX01_UT_PATH)/$(EPITECH_EX01_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex01	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX01_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html


# **************************************************************************** #
#																			   #
#								EPITECH_EX02								   #
#																			   #
# **************************************************************************** #
EPITECH_EX02_PATH 				= 	./EPITECH/D08/ex02
EPITECH_EX02_BIN_PATH 			= 	./EPITECH/D08/ex02/bin
EPITECH_EX02_SRC_PATH			=	./EPITECH/D08/ex02/source
EPITECH_EX02_INC_PATH			=	./EPITECH/D08/ex02/include
EPITECH_EX02_UT_PATH			=	./EPITECH/D08/ex02/test

EPITECH_EX02_NAME				=	RogerRoger

EPITECH_EX02_UT_SRC				=	$(EPITECH_EX02_UT_PATH)/$(EPITECH_EX02_NAME)_test.cpp
EPITECH_EX02_UT_NAME 			= 	test_$(EPITECH_EX02_NAME)

EPITECH_EX02_SRC				=	$(EPITECH_EX02_SRC_PATH)/Droids.cpp \
									$(EPITECH_EX02_SRC_PATH)/Droidmemory.cpp \
									$(EPITECH_EX02_BIN_PATH)/main.cpp
EPITECH_EX02_OBJS				=	$(EPITECH_EX02_SRC:.cpp=.o)

EPITECH_ex02 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX02_PATH)
									$(EPITECH_EX02_PATH)/$(EPITECH_EX02_NAME)

EPITECH_valgrind_ex02 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX02_PATH) VALGRIND

EPITECH_test_run_ex02			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX02_UT_PATH)
									$(EPITECH_EX02_UT_PATH)/$(EPITECH_EX02_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex02	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX02_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX03								   #
#																			   #
# **************************************************************************** #
EPITECH_EX03_PATH 				= 	./EPITECH/D08/ex03
EPITECH_EX03_BIN_PATH 			= 	./EPITECH/D08/ex03/bin
EPITECH_EX03_SRC_PATH			=	./EPITECH/D08/ex03/source
EPITECH_EX03_INC_PATH			=	./EPITECH/D08/ex03/include
EPITECH_EX03_UT_PATH			=	./EPITECH/D08/ex03/test

EPITECH_EX03_NAME				=	Carrier

EPITECH_EX03_UT_SRC				=	$(EPITECH_EX03_UT_PATH)/$(EPITECH_EX03_NAME)_test.cpp
EPITECH_EX03_UT_NAME 			= 	test_$(EPITECH_EX03_NAME)

EPITECH_EX03_SRC				=	$(EPITECH_EX03_SRC_PATH)/Droids.cpp \
									$(EPITECH_EX03_SRC_PATH)/DroidMemory.cpp \
									$(EPITECH_EX03_SRC_PATH)/Carrier.cpp \
									$(EPITECH_EX03_BIN_PATH)/main.cpp
EPITECH_EX03_OBJS				=	$(EPITECH_EX03_SRC:.cpp=.o)

EPITECH_ex03 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX03_PATH)
									$(EPITECH_EX03_PATH)/$(EPITECH_EX03_NAME)

EPITECH_valgrind_ex03 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX03_PATH) VALGRIND

EPITECH_test_run_ex03			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX03_UT_PATH)
									$(EPITECH_EX03_UT_PATH)/$(EPITECH_EX03_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex03	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX03_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX04								   #
#																			   #
# **************************************************************************** #
EPITECH_EX04_PATH 				= 	./EPITECH/D08/ex04
EPITECH_EX04_BIN_PATH 			= 	./EPITECH/D08/ex04/bin
EPITECH_EX04_SRC_PATH			=	./EPITECH/D08/ex04/source
EPITECH_EX04_INC_PATH			=	./EPITECH/D08/ex04/include
EPITECH_EX04_UT_PATH			=	./EPITECH/D08/ex04/test

EPITECH_EX04_NAME				=	Commanders

EPITECH_EX04_UT_SRC				=	$(EPITECH_EX04_UT_PATH)/$(EPITECH_EX04_NAME)_test.cpp
EPITECH_EX04_UT_NAME 			= 	test_$(EPITECH_EX04_NAME)

EPITECH_EX04_SRC				=	$(EPITECH_EX04_SRC_PATH)/Droids.cpp \
									$(EPITECH_EX04_SRC_PATH)/WarpSystem.cpp \
									$(EPITECH_EX04_SRC_PATH)/Borg.cpp \
									$(EPITECH_EX04_SRC_PATH)/Admiral.cpp \
									$(EPITECH_EX04_SRC_PATH)/BorgQueen.cpp \
									$(EPITECH_EX04_BIN_PATH)/main.cpp
EPITECH_EX04_OBJS				=	$(EPITECH_EX04_SRC:.cpp=.o)

EPITECH_ex04 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX04_PATH)
									$(EPITECH_EX04_PATH)/$(EPITECH_EX04_NAME)

EPITECH_valgrind_ex04 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX04_PATH) VALGRIND

EPITECH_test_run_ex04			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX04_UT_PATH)
									$(EPITECH_EX04_UT_PATH)/$(EPITECH_EX04_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex04	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX04_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX05								   #
#																			   #
# **************************************************************************** #
EPITECH_EX05_PATH 				= 	./EPITECH/D08/ex05
EPITECH_EX05_BIN_PATH 			= 	./EPITECH/D08/ex05/bin
EPITECH_EX05_SRC_PATH			=	./EPITECH/D08/ex05/source
EPITECH_EX05_INC_PATH			=	./EPITECH/D08/ex05/include
EPITECH_EX05_UT_PATH			=	./EPITECH/D08/ex05/test

EPITECH_EX05_NAME				=	Exam

EPITECH_EX05_UT_SRC				=	$(EPITECH_EX05_UT_PATH)/$(EPITECH_EX05_NAME)_test.cpp
EPITECH_EX05_UT_NAME 			= 	test_$(EPITECH_EX05_NAME)

EPITECH_EX05_SRC				=	$(EPITECH_EX05_SRC_PATH)/Exam.cpp \
									$(EPITECH_EX05_BIN_PATH)/main.cpp

EPITECH_EX05_OBJS				=	$(EPITECH_EX05_SRC:.cpp=.o)

EPITECH_ex05 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX05_PATH)
									$(EPITECH_EX05_PATH)/$(EPITECH_EX05_NAME)

EPITECH_valgrind_ex05 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX05_PATH) VALGRIND

EPITECH_test_run_ex05			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX05_UT_PATH)
									$(EPITECH_EX05_UT_PATH)/$(EPITECH_EX05_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex05	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX05_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX06								   #
#																			   #
# **************************************************************************** #
EPITECH_EX06_PATH 				= 	./EPITECH/D08/ex06
EPITECH_EX06_BIN_PATH 			= 	./EPITECH/D08/ex06/bin
EPITECH_EX06_SRC_PATH			=	./EPITECH/D08/ex06/source
EPITECH_EX06_INC_PATH			=	./EPITECH/D08/ex06/include
EPITECH_EX06_UT_PATH			=	./EPITECH/D08/ex06/test

EPITECH_EX06_NAME				=	Meeeeeeedic

EPITECH_EX06_UT_SRC				=	$(EPITECH_EX06_UT_PATH)/$(EPITECH_EX06_NAME)_test.cpp
EPITECH_EX06_UT_NAME 			= 	test_$(EPITECH_EX06_NAME)

EPITECH_EX06_SRC				=	$(EPITECH_EX06_SRC_PATH)/Skat.cpp \
									$(EPITECH_EX06_BIN_PATH)/main.cpp

EPITECH_EX06_OBJS				=	$(EPITECH_EX06_SRC:.cpp=.o)

EPITECH_ex06 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX06_PATH)
									$(EPITECH_EX06_PATH)/$(EPITECH_EX06_NAME)

EPITECH_valgrind_ex06 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX06_PATH) VALGRIND

EPITECH_test_run_ex06			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX06_UT_PATH)
									$(EPITECH_EX06_UT_PATH)/$(EPITECH_EX06_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex06	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX06_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX07								   #
#																			   #
# **************************************************************************** #
EPITECH_EX07_PATH 				= 	./EPITECH/D08/ex07
EPITECH_EX07_BIN_PATH 			= 	./EPITECH/D08/ex07/bin
EPITECH_EX07_SRC_PATH			=	./EPITECH/D08/ex07/source
EPITECH_EX07_INC_PATH			=	./EPITECH/D08/ex07/include
EPITECH_EX07_UT_PATH			=	./EPITECH/D08/ex07/test

EPITECH_EX07_NAME				=	KoalaBot

EPITECH_EX07_UT_SRC				=	$(EPITECH_EX07_UT_PATH)/$(EPITECH_EX07_NAME)_test.cpp
EPITECH_EX07_UT_NAME 			= 	test_$(EPITECH_EX07_NAME)

EPITECH_EX07_SRC				=	$(EPITECH_EX07_SRC_PATH)/Parts.cpp \
									$(EPITECH_EX07_SRC_PATH)/KoalaBot.cpp \
									$(EPITECH_EX07_BIN_PATH)/main.cpp

EPITECH_EX07_OBJS				=	$(EPITECH_EX07_SRC:.cpp=.o)

EPITECH_ex07 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX07_PATH)
									$(EPITECH_EX07_PATH)/$(EPITECH_EX07_NAME)

EPITECH_valgrind_ex07 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX07_PATH) VALGRIND

EPITECH_test_run_ex07			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX07_UT_PATH)
									$(EPITECH_EX07_UT_PATH)/$(EPITECH_EX07_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex07	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX07_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX08								   #
#																			   #
# **************************************************************************** #
EPITECH_EX08_PATH 				= 	./EPITECH/D08/ex08
EPITECH_EX08_BIN_PATH 			= 	./EPITECH/D08/ex08/bin
EPITECH_EX08_SRC_PATH			=	./EPITECH/D08/ex08/source
EPITECH_EX08_INC_PATH			=	./EPITECH/D08/ex08/include
EPITECH_EX08_UT_PATH			=	./EPITECH/D08/ex08/test

EPITECH_EX08_NAME				=	KreogCom

EPITECH_EX08_UT_SRC				=	$(EPITECH_EX08_UT_PATH)/$(EPITECH_EX08_NAME)_test.cpp
EPITECH_EX08_UT_NAME 			= 	test_$(EPITECH_EX08_NAME)

EPITECH_EX08_SRC				=	$(EPITECH_EX08_SRC_PATH)/KreogCom.cpp \
									$(EPITECH_EX08_BIN_PATH)/main.cpp

EPITECH_EX08_OBJS				=	$(EPITECH_EX08_SRC:.cpp=.o)

EPITECH_ex08 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX08_PATH)
									$(EPITECH_EX08_PATH)/$(EPITECH_EX08_NAME)

EPITECH_valgrind_ex08 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX08_PATH) VALGRIND

EPITECH_test_run_ex08			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX08_UT_PATH)
									$(EPITECH_EX08_UT_PATH)/$(EPITECH_EX08_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex08	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX08_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html


# **************************************************************************** #
#																			   #
#								EPITECH_EX09								   #
#																			   #
# **************************************************************************** #
EPITECH_EX09_PATH 				= 	./EPITECH/D08/ex09
EPITECH_EX09_BIN_PATH 			= 	./EPITECH/D08/ex09/bin
EPITECH_EX09_SRC_PATH			=	./EPITECH/D08/ex09/source
EPITECH_EX09_INC_PATH			=	./EPITECH/D08/ex09/include
EPITECH_EX09_UT_PATH			=	./EPITECH/D08/ex09/test

EPITECH_EX09_NAME				=	Phaser

EPITECH_EX09_UT_SRC				=	$(EPITECH_EX09_UT_PATH)/$(EPITECH_EX09_NAME)_test.cpp
EPITECH_EX09_UT_NAME 			= 	test_$(EPITECH_EX09_NAME)

EPITECH_EX09_SRC				=	$(EPITECH_EX09_SRC_PATH)/Phaser.cpp \
									$(EPITECH_EX09_BIN_PATH)/main.cpp

EPITECH_EX09_OBJS				=	$(EPITECH_EX09_SRC:.cpp=.o)

EPITECH_ex09 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX09_PATH)
									$(EPITECH_EX09_PATH)/$(EPITECH_EX09_NAME)

EPITECH_valgrind_ex09 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX09_PATH) VALGRIND

EPITECH_test_run_ex09			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX09_UT_PATH)
									$(EPITECH_EX09_UT_PATH)/$(EPITECH_EX09_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex09	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX09_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html


# **************************************************************************** #
#																			   #
#								EPITECH_EX10								   #
#																			   #
# **************************************************************************** #
EPITECH_EX10_PATH 				= 	./EPITECH/D08/ex10
EPITECH_EX10_BIN_PATH 			= 	./EPITECH/D08/ex10/bin
EPITECH_EX10_SRC_PATH			=	./EPITECH/D08/ex10/source
EPITECH_EX10_INC_PATH			=	./EPITECH/D08/ex10/include
EPITECH_EX10_UT_PATH			=	./EPITECH/D08/ex10/test

EPITECH_EX10_NAME				=	GSquad

EPITECH_EX10_UT_SRC				=	$(EPITECH_EX10_UT_PATH)/$(EPITECH_EX10_NAME)_test.cpp
EPITECH_EX10_UT_NAME 			= 	test_$(EPITECH_EX10_NAME)

EPITECH_EX10_SRC				=	$(EPITECH_EX10_SRC_PATH)/Skat.cpp \
									$(EPITECH_EX10_BIN_PATH)/main.cpp

EPITECH_EX10_OBJS				=	$(EPITECH_EX10_SRC:.cpp=.o)

EPITECH_ex10 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX10_PATH)
									$(EPITECH_EX10_PATH)/$(EPITECH_EX10_NAME)

EPITECH_valgrind_ex10 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX10_PATH) VALGRIND

EPITECH_test_run_ex10			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX10_UT_PATH)
									$(EPITECH_EX10_UT_PATH)/$(EPITECH_EX10_UT_NAME)
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex10	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX10_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
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
LOG								=	*.log
%								: 	capture
									@:

all								:	$(42_EX12_NAME)

$(42_EX12_NAME)					: 	$(42_EX12_OBJS)
									$(G++) $(CPPFLAGS) $(INCFLAGS)$(42_EX12_INC_PATH) $(42_EX12_OBJS) -o $(42_EX12_NAME)

clean							:	
									$(RM) $(LOG)
									@$(MAKE) -s $(CLEAN) -C $(42_EX00_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX00_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX01_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX01_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX02_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX02_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX03_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX03_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX00_PATH)
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX00_UT_PATH)	
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX01_PATH)
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX01_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX02_PATH)
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX02_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX03_PATH)
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX03_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX04_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX04_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX05_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX05_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX06_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX06_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX07_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX07_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX08_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX08_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX09_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX09_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX10_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX10_UT_PATH)

fclean							:	clean
									@$(MAKE) -s $(FCLEAN) -C $(42_EX00_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX00_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX01_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX01_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX02_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX02_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX03_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX03_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX00_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX00_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX01_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX01_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX02_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX02_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX03_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX03_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX04_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX04_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX05_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX05_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX06_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX06_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX07_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX07_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX08_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX08_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX09_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX09_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX10_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX10_UT_PATH)

tests_run						:	fclean \

capture							:
									@:
									
.PHONY							: 	all clean fclean re \
									tests_run capture