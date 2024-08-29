# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:07:51 by Paradis           #+#    #+#              #
#    Updated: 2024/08/29 18:00:25 by Paradis          ###   ########.fr        #
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

42_EX00_SRC						=	$(42_EX00_SRC_PATH)/Megaphone.cpp \
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

##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Mon Aug 26 8:17:58 PM 2024 Paradis
## Last update Fri Aug 29 6:00:25 PM 2024 Paradis
##

## RULES FOR EPITECH SCHOOL

# **************************************************************************** #
#																			   #
#								EPITECH EX00								   #
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

all								:	$(42_EX00_NAME)

$(42_EX00_NAME)					: 	$(42_EX00_OBJS)
									$(G++) $(CPPFLAGS) $(INCFLAGS)$(42_EX00_INC_PATH) $(42_EX00_OBJS) -o $(42_EX00_NAME)

clean							:	
									@$(MAKE) -s $(CLEAN) -C $(42_EX00_UT_PATH)
									@$(MAKE) -s $(CLEAN) -C $(42_EX00_PATH)

fclean							:	clean
									@$(MAKE) -s $(FCLEAN) -C $(42_EX00_UT_PATH)
									@$(MAKE) -s $(FCLEAN) -C $(42_EX00_PATH)

tests_run						:	fclean \
									42_test_run_ex00

.PHONY							: 	all clean fclean re \
									tests_run \