# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Paradis <adil.d.pro@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 21:14:51 by Paradis           #+#    #+#              #
#    Updated: 2024/09/11 20:53:40 by Paradis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G++           	= 	g++
#############################################
SRC_PATH		= 	../source
INC_PATH 		= 	../include
BIN_PATH 		= 	./bin

NAME          	= 	test_replacer
#############################################

INCFLAGS     	+= 	-I $(INC_PATH)
CRITFLAGS    	+=  --coverage -lcriterion
CPPFLAGS     	+= 	-g -Wall -Wextra -Werror -W -Wfatal-errors -std=c++11 $(INCFLAGS) $(CRITFLAGS)

SRCS         	= 	$(SRC_PATH)/Replacer.cpp \
					$(BIN_PATH)/test_main.cpp

OBJS         	= 	$(SRCS:.cpp=.o)
OBJS_GCDA    	= 	$(SRCS:.cpp=.gcda)
OBJS_GCNO    	= 	$(SRCS:.cpp=.gcno)
COVERAGE	 	= 	../../../../coverage.*
LOG 			= 	*.log 
FILE			=	*.replace

all				: 	$(NAME)

$(NAME)			: 	$(OBJS)
					$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME)

VALGRIND		:	$(NAME)
					@valgrind --trace-children=yes --quiet --leak-check=full --show-leak-kinds=all  --error-exitcode=1 --show-reachable=yes ./$(NAME) 2>&1 | tee valgrind_output.log || true
					@if ! grep -q "definitely lost" valgrind_output.log; \
					then \
						echo -e "\033[32mNo memory leaks detected, running unit tests...\033[0m"; \
					else \
						echo -e "\033[31mMemory leaks detected, aborting.\033[0m"; \
						exit 1; \
					fi

RM 				= 	rm -rf

clean			:
					$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO) $(COVERAGE) $(LOG) $(FILE)

fclean			: 	clean
					$(RM) $(NAME)

re				: 	fclean all

.PHONY			: 	all clean fclean re