##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_04/EPITECH/D10/ex01/test
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Wed May 28 6:40:38 PM 2025 Paradis
## Last update Sat Jun 6 5:52:17 PM 2025 Paradis
##


G++           	= 	g++
#############################################
SRC_PATH		= 	../source
INC_PATH 		= 	../include
BIN_PATH 		= 	./bin

NAME          	= 	test_FruitFactory
#############################################

INCFLAGS     	+= 	-I $(INC_PATH)
CPP_VERSION		+=	-std=c++23
CRITFLAGS    	+=  --coverage -lcriterion
CPPFLAGS     	+= 	-g -Wall -Wextra -Werror -W -Wfatal-errors -Wshadow -Wno-shadow $(CPP_VERSION) $(INCFLAGS) $(CRITFLAGS)

SRCS         	= 	$(SRC_PATH)/IFruit.cpp \
					$(SRC_PATH)/AFruit.cpp \
					$(SRC_PATH)/ABerry.cpp \
					$(SRC_PATH)/ACitrus.cpp \
					$(SRC_PATH)/ANut.cpp \
					$(SRC_PATH)/Lemon.cpp \
					$(SRC_PATH)/Orange.cpp \
					$(SRC_PATH)/Strawberry.cpp \
					$(SRC_PATH)/Almond.cpp \
					$(SRC_PATH)/FruitBox.cpp \
					$(SRC_PATH)/Grapefruit.cpp \
					$(SRC_PATH)/BloodOrange.cpp \
					$(SRC_PATH)/Raspberry.cpp \
					$(SRC_PATH)/Coconut.cpp \
					$(SRC_PATH)/FruitUtils.cpp \
					$(SRC_PATH)/FruitFactory.cpp \
					$(BIN_PATH)/test_main.cpp

OBJS         	= 	$(SRCS:.cpp=.o)
OBJS_GCDA    	= 	$(SRCS:.cpp=.gcda)
OBJS_GCNO    	= 	$(SRCS:.cpp=.gcno)
COVERAGE	 	= 	../../../../coverage.*
LOG 			= 	*.log 

all				: 	$(NAME)

$(NAME)			: 	$(OBJS)
					$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME)

VALGRIND		:	$(NAME)
					@valgrind --trace-children=yes --quiet --leak-check=full --show-leak-kinds=all  --error-exitcode=1 ./$(NAME) 2>&1 | tee valgrind_output.log || true
					@if ! grep -q "definitely lost" valgrind_output.log; \
					then \
						echo -e "\033[32mNo memory leaks detected, running unit tests...\033[0m"; \
					else \
						echo -e "\033[31mMemory leaks detected, aborting.\033[0m"; \
						exit 1; \
					fi

RM 				= 	rm -rf

clean			:
					$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO) $(COVERAGE) $(LOG)

fclean			: 	clean
					$(RM) $(NAME)

re				: 	fclean all

.PHONY			: all clean fclean re