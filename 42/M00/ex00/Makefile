# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 16:48:09 by Paradis           #+#    #+#              #
#    Updated: 2024/06/19 16:56:33 by Paradis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

# # Compilateur
G++			=	g++
##############################################
BIN_PATH	=	./bin
SRC_PATH	=	./source
INC_PATH	=	./include
UT_PATH		=	./test


NAME		=	Megaphone
UT_NAME 	= 	test_$(NAME)
##############################################

# # Options de compilation
INCFLAGS	+=	-I $(INC_PATH)
CPPFLAGS	+= -g -Wall -Wextra -Werror -W -std=c++23 $(INCFLAGS)

# # Files sources
SRCS		=	$(SRC_PATH)/Fruit.cpp \
				$(SRC_PATH)/Lemon.cpp \
				$(SRC_PATH)/Banana.cpp \
				$(SRC_PATH)/FruitBox.cpp \
				$(SRC_PATH)/LittleHand.cpp \
				$(SRC_PATH)/Lime.cpp \
				$(SRC_PATH)/Coconut.cpp \
				$(SRC_PATH)/Mixer.cpp \
				$(SRC_PATH)/MixerBase.cpp \
				$(BIN_PATH)/main.cpp

UT_SRC		=	$(UT_PATH)/$(NAME)_test.cpp

# # Files object
OBJS		=	$(SRCS:.cpp=.o)

CLEAN		=	clean
FCLEAN		=	fclean
RM			=	rm -rf

# # Règle par défaut pour tout compiler
all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME) 

# # Règle pour nettoyer les fichiers compilés
clean		:
				$(RM) $(OBJS)
				@$(MAKE) $(CLEAN) -C $(UT_PATH)

# # Target for clean files object
fclean		:	clean
				$(RM) $(NAME) $(UT_NAME)
				@$(MAKE) $(FCLEAN) -C $(UT_PATH)

re			: 	clean fclean all

# # Start units test
tests_run	:	fclean
				@$(MAKE) -C $(UT_PATH)
				$(UT_PATH)/$(UT_NAME)

.PHONY		: 	all clean fclean re tests_run