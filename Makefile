# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:07:51 by Paradis           #+#    #+#              #
#    Updated: 2024/06/25 07:06:50 by Paradis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

42_EX00_PATH 			= 	./42/M00/ex00
42_EX00_SRC_PATH		=	./42/M00/ex00/source
42_EX00_INC_PATH		=	./42/M00/ex00/include
42_EX00_UT_PATH			=	./42/M00/ex00/test
42_EX00_NAME			=	Megaphone
42_EX00_UT_SRC			=	$(42_EX00_UT_PATH)/$(42_EX00_NAME)_test.cpp
42_EX00_UT_NAME 		= 	test_$(42_EX00_NAME)

# EPITECH_EX00_PATH 		= 	./Ex0_Fruit
# EPITECH_EX00_SRC_PATH	=	./Ex0_Fruit/source
# EPITECH_EX00_UT_PATH	=	./Ex0_Fruit/test
# EPITECH_EX00_INC_PATH	=	./Ex0_Fruit/include
# EPITECH_EX00_NAME		=	Ex0
# EPITECH_EX00_UT_SRC		=	$(42_EX00_UT_PATH)/$(42_EX00_NAME)_test.cpp
# EPITECH_EX00_UT_NAME 	= 	test_$(42_EX00_NAME)
##########################################################################
# # Fichiers source
# SRC1 = main1.c
# SRC2 = main2.c

# # Binaires cibles
# BIN1 = prog1
# BIN2 = prog2

# # Compilateur et options de compilation
# CC = gcc
# CFLAGS = -Wall -Wextra

# # Règle par défaut pour tout compiler
# all: $(BIN1) $(BIN2)

# # Règles pour compiler chaque programme
# $(BIN1): $(SRC1)
#     $(CC) $(CFLAGS) -o $(BIN1) $(SRC1)

# $(BIN2): $(SRC2)
#     $(CC) $(CFLAGS) -o $(BIN2) $(SRC2)

# # Règle pour nettoyer les fichiers compilés
# clean:
#     rm -f $(BIN1) $(BIN2)

# # Compilateur et options de compilation
G++ 					= 	g++
INCFLAGS				= 	-I #$(42_EX00_INC_PATH)
CPPFLAGS 				= 	-Wall -Wextra -Werror -std=c++23 $(INCFLAGS)

# # Règle par défaut pour tout compiler
all						:	$(42_ex00)

#
CLEAN					=	clean
FCLEAN					=	fclean
RM						=	rm -rf

# # Règle pour nettoyer les fichiers compilés
clean					:	
							@$(MAKE) -s $(CLEAN) -C $(42_EX00_UT_PATH)

# # Règle pour nettoyer les objets
fclean					:	clean
							$(RM) $(NAME) $(TEST_42_EX00_NAME)
							@$(MAKE) -s $(FCLEAN) -C $(42_EX00_UT_PATH)
							@$(MAKE) -s $(FCLEAN) -C $(42_EX00_PATH)

re						: 	clean fclean all
##########################################################################
42_ex00 				: 	fclean
							@$(MAKE) -C $(42_EX00_PATH)
							$(42_EX00_PATH)/$(42_EX00_NAME)


42_test_run_ex00		:	fclean
							@$(MAKE) -s -C $(42_EX00_UT_PATH)
							$(42_EX00_UT_PATH)/$(42_EX00_UT_NAME)
							gcovr --exclude-unreachable-branches --exclude-throw-branches -r . --html --txt --html-details coverage.html
# @brave coverage.html


tests_run				:	fclean
							@$(MAKE) 42_test_run_ex00
							@echo "Press Enter to continue to the next test (ex01)..."
							@read dummy
							@echo "=====END====="
 
.PHONY					: 	all clean fclean re \
							tests_run \
							Ex0 test_run_Ex0 \
							Ex1 test_run_Ex1 \
							Ex2 test_run_Ex2 \
							Ex3 test_run_Ex3 \
							Ex4 test_run_Ex4