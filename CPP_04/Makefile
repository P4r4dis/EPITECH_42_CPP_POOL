# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 17:02:13 by Paradis           #+#    #+#              #
#    Updated: 2025/06/05 20:04:17 by Paradis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## RULES FOR 42 SCHOOL
# **************************************************************************** #
#																			   #
#								42 EX00										   #
#																			   #
# **************************************************************************** #
42_EX00_PATH 					= 	./42/M04/ex00
42_EX00_BIN_PATH 				= 	./42/M04/ex00/bin
42_EX00_SRC_PATH				=	./42/M04/ex00/source
42_EX00_INC_PATH				=	./42/M04/ex00/include
42_EX00_UT_PATH					=	./42/M04/ex00/test

42_EX00_NAME					=	Animal

42_EX00_UT_SRC					=	$(42_EX00_UT_PATH)/$(42_EX00_NAME)_test.cpp
42_EX00_UT_NAME 				= 	test_$(42_EX00_NAME)

42_EX00_SRC						=	$(42_EX00_SRC_PATH)/Animal.cpp \
									$(42_EX00_SRC_PATH)/Dog.cpp \
									$(42_EX00_SRC_PATH)/Cat.cpp \
									$(42_EX00_SRC_PATH)/WrongAnimal.cpp \
									$(42_EX00_SRC_PATH)/WrongCat.cpp \
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
42_EX01_PATH 					= 	./42/M04/ex01
42_EX01_BIN_PATH 				= 	./42/M04/ex01/bin
42_EX01_SRC_PATH				=	./42/M04/ex01/source
42_EX01_INC_PATH				=	./42/M04/ex01/include
42_EX01_UT_PATH					=	./42/M04/ex01/test

42_EX01_NAME					=	Brain

42_EX01_UT_SRC					=	$(42_EX01_UT_PATH)/$(42_EX01_NAME)_test.cpp
42_EX01_UT_NAME 				= 	test_$(42_EX01_NAME)

42_EX01_SRC						=	$(42_EX01_SRC_PATH)/Animal.cpp \
									$(42_EX01_SRC_PATH)/Dog.cpp \
									$(42_EX01_SRC_PATH)/Cat.cpp \
									$(42_EX01_SRC_PATH)/WrongAnimal.cpp \
									$(42_EX01_SRC_PATH)/WrongCat.cpp \
									$(42_EX01_SRC_PATH)/Brain.cpp \
									$(42_EX01_BIN_PATH)/main.cpp
42_EX01_OBJS					=	$(42_EX01_SRC:.cpp=.o)

42_ex01 						: 	fclean
									@$(MAKE) -C $(42_EX01_PATH)
									$(42_EX01_PATH)/$(42_EX01_NAME)

42_test_run_ex01				:	fclean
									@$(MAKE) -s -C $(42_EX01_UT_PATH)
									$(42_EX01_UT_PATH)/$(42_EX01_UT_NAME) --fail-fast --jobs=1 --verbose=2
#--fail-fast 
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
42_EX02_PATH 					= 	./42/M04/ex02
42_EX02_BIN_PATH 				= 	./42/M04/ex02/bin
42_EX02_SRC_PATH				=	./42/M04/ex02/source
42_EX02_INC_PATH				=	./42/M04/ex02/include
42_EX02_UT_PATH					=	./42/M04/ex02/test

42_EX02_NAME					=	Aanimal

42_EX02_UT_SRC					=	$(42_EX02_UT_PATH)/$(42_EX02_NAME)_test.cpp
42_EX02_UT_NAME 				= 	test_$(42_EX02_NAME)

42_EX02_SRC						=	$(42_EX02_SRC_PATH)/Aanimal.cpp \
									$(42_EX02_SRC_PATH)/Dog.cpp \
									$(42_EX02_SRC_PATH)/Cat.cpp \
									$(42_EX02_SRC_PATH)/WrongAnimal.cpp \
									$(42_EX02_SRC_PATH)/WrongCat.cpp \
									$(42_EX02_SRC_PATH)/Brain.cpp \
									$(42_EX02_BIN_PATH)/main.cpp
42_EX02_OBJS					=	$(42_EX02_SRC:.cpp=.o)

42_ex02 						: 	fclean
									@$(MAKE) -C $(42_EX02_PATH)
									$(42_EX02_PATH)/$(42_EX02_NAME)

42_test_run_ex02				:	fclean
									@$(MAKE) -s -C $(42_EX02_UT_PATH)
									$(42_EX02_UT_PATH)/$(42_EX02_UT_NAME) --fail-fast --jobs=1 --verbose=2
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
42_EX03_PATH 					= 	./42/M04/ex03
42_EX03_BIN_PATH 				= 	./42/M04/ex03/bin
42_EX03_SRC_PATH				=	./42/M04/ex03/source
42_EX03_INC_PATH				=	./42/M04/ex03/include
42_EX03_UT_PATH					=	./42/M04/ex03/test

42_EX03_NAME					=	Interface_Recap

42_EX03_UT_SRC					=	$(42_EX03_UT_PATH)/$(42_EX03_NAME)_test.cpp
42_EX03_UT_NAME 				= 	test_$(42_EX03_NAME)

42_EX03_SRC						=	$(42_EX03_SRC_PATH)/AMateria.cpp \
									$(42_EX03_SRC_PATH)/Ice.cpp \
									$(42_EX03_SRC_PATH)/Cure.cpp \
									$(42_EX03_SRC_PATH)/Character.cpp \
									$(42_EX03_SRC_PATH)/MateriaSource.cpp \
									$(42_EX03_BIN_PATH)/main.cpp
42_EX03_OBJS					=	$(42_EX03_SRC:.cpp=.o)

42_ex03 						: 	fclean
									@$(MAKE) -C $(42_EX03_PATH)
									$(42_EX03_PATH)/$(42_EX03_NAME)

42_test_run_ex03				:	fclean
									@$(MAKE) -s -C $(42_EX03_UT_PATH)
									$(42_EX03_UT_PATH)/$(42_EX03_UT_NAME) --fail-fast --jobs=1 --verbose=2
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
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Tue May 27 5:03:01 PM 2025 Paradis
## Last update Fri Jun 5 8:04:17 PM 2025 Paradis
##


# **************************************************************************** #
#																			   #
#								EPITECH EX00								   #
#																			   #
# **************************************************************************** #
EPITECH_EX00_PATH 				= 	./EPITECH/D10/ex00
EPITECH_EX00_BIN_PATH 			= 	./EPITECH/D10/ex00/bin
EPITECH_EX00_SRC_PATH			=	./EPITECH/D10/ex00/source
EPITECH_EX00_INC_PATH			=	./EPITECH/D10/ex00/include
EPITECH_EX00_UT_PATH			=	./EPITECH/D10/ex00/test

EPITECH_EX00_NAME				=	Fruits

EPITECH_EX00_UT_SRC				=	$(EPITECH_EX00_UT_PATH)/$(EPITECH_EX00_NAME)_test.cpp
EPITECH_EX00_UT_NAME 			= 	test_$(EPITECH_EX00_NAME)

EPITECH_EX00_SRC				=	$(EPITECH_EX00_SRC_PATH)/IFruit.cpp \
									$(EPITECH_EX00_SRC_PATH)/AFruit.cpp \
									$(EPITECH_EX00_SRC_PATH)/ABerry.cpp \
									$(EPITECH_EX00_SRC_PATH)/ACitrus.cpp \
									$(EPITECH_EX00_SRC_PATH)/ANut.cpp \
									$(EPITECH_EX00_SRC_PATH)/Lemon.cpp \
									$(EPITECH_EX00_SRC_PATH)/Orange.cpp \
									$(EPITECH_EX00_SRC_PATH)/Strawberry.cpp \
									$(EPITECH_EX00_SRC_PATH)/Almond.cpp \
									$(EPITECH_EX00_BIN_PATH)/main.cpp
EPITECH_EX00_OBJS				=	$(EPITECH_EX00_SRC:.cpp=.o)

EPITECH_ex00 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX00_PATH)
									$(EPITECH_EX00_PATH)/$(EPITECH_EX00_NAME)

EPITECH_valgrind_ex00 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX00_PATH) VALGRIND

EPITECH_test_run_ex00			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX00_UT_PATH)
									$(EPITECH_EX00_UT_PATH)/$(EPITECH_EX00_UT_NAME) --fail-fast --jobs=1 --verbose=2
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex00	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX00_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX01								   #
#																			   #
# **************************************************************************** #
EPITECH_EX01_PATH 				= 	./EPITECH/D10/ex01
EPITECH_EX01_BIN_PATH 			= 	./EPITECH/D10/ex01/bin
EPITECH_EX01_SRC_PATH			=	./EPITECH/D10/ex01/source
EPITECH_EX01_INC_PATH			=	./EPITECH/D10/ex01/include
EPITECH_EX01_UT_PATH			=	./EPITECH/D10/ex01/test

EPITECH_EX01_NAME				=	FruitBox

EPITECH_EX01_UT_SRC				=	$(EPITECH_EX01_UT_PATH)/$(EPITECH_EX01_NAME)_test.cpp
EPITECH_EX01_UT_NAME 			= 	test_$(EPITECH_EX01_NAME)

EPITECH_EX01_SRC				=	$(EPITECH_EX01_SRC_PATH)/IFruit.cpp \
									$(EPITECH_EX01_SRC_PATH)/AFruit.cpp \
									$(EPITECH_EX01_SRC_PATH)/ABerry.cpp \
									$(EPITECH_EX01_SRC_PATH)/ACitrus.cpp \
									$(EPITECH_EX01_SRC_PATH)/ANut.cpp \
									$(EPITECH_EX01_SRC_PATH)/Lemon.cpp \
									$(EPITECH_EX01_SRC_PATH)/Orange.cpp \
									$(EPITECH_EX01_SRC_PATH)/Strawberry.cpp \
									$(EPITECH_EX01_SRC_PATH)/Almond.cpp \
									$(EPITECH_EX01_SRC_PATH)/FruitBox.cpp \
									$(EPITECH_EX01_BIN_PATH)/main.cpp
EPITECH_EX01_OBJS				=	$(EPITECH_EX01_SRC:.cpp=.o)

EPITECH_ex01 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX01_PATH)
									$(EPITECH_EX01_PATH)/$(EPITECH_EX01_NAME)

EPITECH_valgrind_ex01 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX01_PATH) VALGRIND

EPITECH_test_run_ex01			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX01_UT_PATH)
									$(EPITECH_EX01_UT_PATH)/$(EPITECH_EX01_UT_NAME) --fail-fast --jobs=1 --verbose=2
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex01	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX01_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html


# **************************************************************************** #
#																			   #
#								EPITECH_EX02								   #
#																			   #
# **************************************************************************** #
EPITECH_EX02_PATH 				= 	./EPITECH/D10/ex02
EPITECH_EX02_BIN_PATH 			= 	./EPITECH/D10/ex02/bin
EPITECH_EX02_SRC_PATH			=	./EPITECH/D10/ex02/source
EPITECH_EX02_INC_PATH			=	./EPITECH/D10/ex02/include
EPITECH_EX02_UT_PATH			=	./EPITECH/D10/ex02/test

EPITECH_EX02_NAME				=	FruitSorter

EPITECH_EX02_UT_SRC				=	$(EPITECH_EX02_UT_PATH)/$(EPITECH_EX02_NAME)_test.cpp
EPITECH_EX02_UT_NAME 			= 	test_$(EPITECH_EX02_NAME)

EPITECH_EX02_SRC				=	$(EPITECH_EX02_SRC_PATH)/IFruit.cpp \
									$(EPITECH_EX02_SRC_PATH)/AFruit.cpp \
									$(EPITECH_EX02_SRC_PATH)/ABerry.cpp \
									$(EPITECH_EX02_SRC_PATH)/ACitrus.cpp \
									$(EPITECH_EX02_SRC_PATH)/ANut.cpp \
									$(EPITECH_EX02_SRC_PATH)/Lemon.cpp \
									$(EPITECH_EX02_SRC_PATH)/Orange.cpp \
									$(EPITECH_EX02_SRC_PATH)/Strawberry.cpp \
									$(EPITECH_EX02_SRC_PATH)/Almond.cpp \
									$(EPITECH_EX02_SRC_PATH)/FruitBox.cpp \
									$(EPITECH_EX02_SRC_PATH)/Grapefruit.cpp \
									$(EPITECH_EX02_SRC_PATH)/BloodOrange.cpp \
									$(EPITECH_EX02_SRC_PATH)/Raspberry.cpp \
									$(EPITECH_EX02_SRC_PATH)/Coconut.cpp \
									$(EPITECH_EX02_SRC_PATH)/FruitUtils.cpp \
									$(EPITECH_EX02_BIN_PATH)/main.cpp
EPITECH_EX02_OBJS				=	$(EPITECH_EX02_SRC:.cpp=.o)

EPITECH_ex02 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX02_PATH)
									$(EPITECH_EX02_PATH)/$(EPITECH_EX02_NAME)

EPITECH_valgrind_ex02 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX02_PATH) VALGRIND

EPITECH_test_run_ex02			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX02_UT_PATH)
									$(EPITECH_EX02_UT_PATH)/$(EPITECH_EX02_UT_NAME) --fail-fast --jobs=1 --verbose=2
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex02	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX02_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX03								   #
#																			   #
# **************************************************************************** #
EPITECH_EX03_PATH 				= 	./EPITECH/D10/ex03
EPITECH_EX03_BIN_PATH 			= 	./EPITECH/D10/ex03/bin
EPITECH_EX03_SRC_PATH			=	./EPITECH/D10/ex03/source
EPITECH_EX03_INC_PATH			=	./EPITECH/D10/ex03/include
EPITECH_EX03_UT_PATH			=	./EPITECH/D10/ex03/test

EPITECH_EX03_NAME				=	FruitPacker

EPITECH_EX03_UT_SRC				=	$(EPITECH_EX03_UT_PATH)/$(EPITECH_EX03_NAME)_test.cpp
EPITECH_EX03_UT_NAME 			= 	test_$(EPITECH_EX03_NAME)

EPITECH_EX03_SRC				=	$(EPITECH_EX03_SRC_PATH)/IFruit.cpp \
									$(EPITECH_EX03_SRC_PATH)/AFruit.cpp \
									$(EPITECH_EX03_SRC_PATH)/ABerry.cpp \
									$(EPITECH_EX03_SRC_PATH)/ACitrus.cpp \
									$(EPITECH_EX03_SRC_PATH)/ANut.cpp \
									$(EPITECH_EX03_SRC_PATH)/Lemon.cpp \
									$(EPITECH_EX03_SRC_PATH)/Orange.cpp \
									$(EPITECH_EX03_SRC_PATH)/Strawberry.cpp \
									$(EPITECH_EX03_SRC_PATH)/Almond.cpp \
									$(EPITECH_EX03_SRC_PATH)/FruitBox.cpp \
									$(EPITECH_EX03_SRC_PATH)/Grapefruit.cpp \
									$(EPITECH_EX03_SRC_PATH)/BloodOrange.cpp \
									$(EPITECH_EX03_SRC_PATH)/Raspberry.cpp \
									$(EPITECH_EX03_SRC_PATH)/Coconut.cpp \
									$(EPITECH_EX03_SRC_PATH)/FruitUtils.cpp \
									$(EPITECH_EX03_BIN_PATH)/main.cpp
EPITECH_EX03_OBJS				=	$(EPITECH_EX03_SRC:.cpp=.o)

EPITECH_ex03 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX03_PATH)
									$(EPITECH_EX03_PATH)/$(EPITECH_EX03_NAME)

EPITECH_valgrind_ex03 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX03_PATH) VALGRIND

EPITECH_test_run_ex03			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX03_UT_PATH)
									$(EPITECH_EX03_UT_PATH)/$(EPITECH_EX03_UT_NAME) --fail-fast --jobs=1 --verbose=2
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex03	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX03_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX04								   #
#																			   #
# **************************************************************************** #
EPITECH_EX04_PATH 				= 	./EPITECH/D10/ex04
EPITECH_EX04_BIN_PATH 			= 	./EPITECH/D10/ex04/bin
EPITECH_EX04_SRC_PATH			=	./EPITECH/D10/ex04/source
EPITECH_EX04_INC_PATH			=	./EPITECH/D10/ex04/include
EPITECH_EX04_UT_PATH			=	./EPITECH/D10/ex04/test

EPITECH_EX04_NAME				=	FruitFactory

EPITECH_EX04_UT_SRC				=	$(EPITECH_EX04_UT_PATH)/$(EPITECH_EX04_NAME)_test.cpp
EPITECH_EX04_UT_NAME 			= 	test_$(EPITECH_EX04_NAME)

EPITECH_EX04_SRC				=	$(EPITECH_EX04_SRC_PATH)/IFruit.cpp \
									$(EPITECH_EX04_SRC_PATH)/AFruit.cpp \
									$(EPITECH_EX04_SRC_PATH)/ABerry.cpp \
									$(EPITECH_EX04_SRC_PATH)/ACitrus.cpp \
									$(EPITECH_EX04_SRC_PATH)/ANut.cpp \
									$(EPITECH_EX04_SRC_PATH)/Lemon.cpp \
									$(EPITECH_EX04_SRC_PATH)/Orange.cpp \
									$(EPITECH_EX04_SRC_PATH)/Strawberry.cpp \
									$(EPITECH_EX04_SRC_PATH)/Almond.cpp \
									$(EPITECH_EX04_SRC_PATH)/FruitBox.cpp \
									$(EPITECH_EX04_SRC_PATH)/Grapefruit.cpp \
									$(EPITECH_EX04_SRC_PATH)/BloodOrange.cpp \
									$(EPITECH_EX04_SRC_PATH)/Raspberry.cpp \
									$(EPITECH_EX04_SRC_PATH)/Coconut.cpp \
									$(EPITECH_EX04_SRC_PATH)/FruitUtils.cpp \
									$(EPITECH_EX04_BIN_PATH)/main.cpp
EPITECH_EX04_OBJS				=	$(EPITECH_EX04_SRC:.cpp=.o)

EPITECH_ex04 					: 	fclean
									@$(MAKE) -C $(EPITECH_EX04_PATH)
									$(EPITECH_EX04_PATH)/$(EPITECH_EX04_NAME)

EPITECH_valgrind_ex04 			: 	fclean
									@$(MAKE) -C $(EPITECH_EX04_PATH) VALGRIND

EPITECH_test_run_ex04			:	fclean
									@$(MAKE) -s -C $(EPITECH_EX04_UT_PATH)
									$(EPITECH_EX04_UT_PATH)/$(EPITECH_EX04_UT_NAME) --fail-fast --jobs=1 --verbose=2
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
						
EPITECH_valgrind_test_run_ex04	:	fclean
									@$(MAKE) -s -C $(EPITECH_EX04_UT_PATH) VALGRIND
									gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html

# **************************************************************************** #
#																			   #
#								EPITECH_EX05								   #
#																			   #
# **************************************************************************** #
EPITECH_EX05_PATH 				= 	./EPITECH/D09/ex05
EPITECH_EX05_BIN_PATH 			= 	./EPITECH/D09/ex05/bin
EPITECH_EX05_SRC_PATH			=	./EPITECH/D09/ex05/source
EPITECH_EX05_INC_PATH			=	./EPITECH/D09/ex05/include
EPITECH_EX05_UT_PATH			=	./EPITECH/D09/ex05/test

EPITECH_EX05_NAME				=	ICharacter

EPITECH_EX05_UT_SRC				=	$(EPITECH_EX05_UT_PATH)/$(EPITECH_EX05_NAME)_test.cpp
EPITECH_EX05_UT_NAME 			= 	test_$(EPITECH_EX05_NAME)

EPITECH_EX05_SRC				=	$(EPITECH_EX05_SRC_PATH)/Peasant.cpp \
									$(EPITECH_EX05_SRC_PATH)/Knight.cpp \
									$(EPITECH_EX05_SRC_PATH)/Enchanter.cpp \
									$(EPITECH_EX05_SRC_PATH)/Priest.cpp \
									$(EPITECH_EX05_SRC_PATH)/Paladin.cpp \
									$(EPITECH_EX05_SRC_PATH)/ICharacter.cpp \
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
EPITECH_EX06_PATH 				= 	./EPITECH/D09/ex06
EPITECH_EX06_BIN_PATH 			= 	./EPITECH/D09/ex06/bin
EPITECH_EX06_SRC_PATH			=	./EPITECH/D09/ex06/source
EPITECH_EX06_INC_PATH			=	./EPITECH/D09/ex06/include
EPITECH_EX06_UT_PATH			=	./EPITECH/D09/ex06/test

EPITECH_EX06_NAME				=	IPotion

EPITECH_EX06_UT_SRC				=	$(EPITECH_EX06_UT_PATH)/$(EPITECH_EX06_NAME)_test.cpp
EPITECH_EX06_UT_NAME 			= 	test_$(EPITECH_EX06_NAME)

EPITECH_EX06_SRC				=	$(EPITECH_EX06_SRC_PATH)/Peasant.cpp \
									$(EPITECH_EX06_SRC_PATH)/Knight.cpp \
									$(EPITECH_EX06_SRC_PATH)/Enchanter.cpp \
									$(EPITECH_EX06_SRC_PATH)/Priest.cpp \
									$(EPITECH_EX06_SRC_PATH)/Paladin.cpp \
									$(EPITECH_EX06_SRC_PATH)/ICharacter.cpp \
									$(EPITECH_EX06_SRC_PATH)/IPotion.cpp \
									$(EPITECH_EX06_SRC_PATH)/HealthPotion.cpp \
									$(EPITECH_EX06_SRC_PATH)/PowerPotion.cpp \
									$(EPITECH_EX06_SRC_PATH)/PoisonPotion.cpp \
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
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX04_PATH)
									@$(MAKE) -s $(CLEAN) -C $(EPITECH_EX04_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX05_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX05_UT_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX06_PATH)
# @$(MAKE) -s $(CLEAN) -C $(EPITECH_EX06_UT_PATH)

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
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX04_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX04_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX05_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX05_UT_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX06_PATH)
# @$(MAKE) -s $(FCLEAN) -C $(EPITECH_EX06_UT_PATH)

tests_run						:	fclean \

capture							:
									@:
									
.PHONY							: 	all clean fclean re \
									tests_run capture