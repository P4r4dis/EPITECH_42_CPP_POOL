# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:07:51 by Paradis           #+#    #+#              #
#    Updated: 2024/06/25 20:30:43 by Paradis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

42_EX00_PATH 			= 	./42/M00/ex00
42_EX00_BIN_PATH 		= 	./42/M00/ex00/bin
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
# # Compilation and options compilation
G++ 					= 	g++
INCFLAGS				= 	-I $(42_EX00_INC_PATH)
CPPFLAGS 				= 	-Wall -Wextra -Werror -W -Wfatal-errors -std=c++98 $(INCFLAGS)

# # Files sources
42_EX00_SRC				=	$(42_EX00_SRC_PATH)/Megaphone.cpp \
							$(42_EX00_BIN_PATH)/main.cpp

# # Files object
42_EX00_OBJS			=	$(42_EX00_SRC:.cpp=.o)

# # Default rule for compile all
all						:	$(42_EX00_NAME)

# # Rule for compiling all binaries
$(42_EX00_NAME)			: 	$(42_EX00_OBJS)
							$(G++) $(CPPFLAGS) $(42_EX00_OBJS) -o $(42_EX00_NAME)

# $(NAME)					:	$(OBJS)
# 							$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME) 
# # Default rules for Clean, Fclean and RM
CLEAN					=	clean
FCLEAN					=	fclean
RM						=	rm -rf

# # Rule compiling object files
clean					:	
							@$(MAKE) -s $(CLEAN) -C $(42_EX00_UT_PATH)

# # Rule compiling object files and binaries name
fclean					:	clean
							$(RM) $(42_EX00_NAME)
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