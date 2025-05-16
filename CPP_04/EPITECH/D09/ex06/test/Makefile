##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex05/test
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Tue May 13 5:56:43 PM 2025 Paradis
## Last update Thu May 14 4:51:58 PM 2025 Paradis
##



G++           	= 	g++
#############################################
SRC_PATH		= 	../source
INC_PATH 		= 	../include
BIN_PATH 		= 	./bin

NAME          	= 	test_IPotion
#############################################

INCFLAGS     	+= 	-I $(INC_PATH)
CPP_VERSION		+=	-std=c++23
CRITFLAGS    	+=  --coverage -lcriterion
CPPFLAGS     	+= 	-g -Wall -Wextra -Werror -W -Wfatal-errors -Wshadow -Wno-shadow $(CPP_VERSION) $(INCFLAGS) $(CRITFLAGS)

SRCS         	= 	$(SRC_PATH)/Peasant.cpp \
					$(SRC_PATH)/Knight.cpp \
					$(SRC_PATH)/Enchanter.cpp \
					$(SRC_PATH)/Priest.cpp \
					$(SRC_PATH)/Paladin.cpp \
					$(SRC_PATH)/ICharacter.cpp \
					$(SRC_PATH)/IPotion.cpp \
					$(SRC_PATH)/HealthPotion.cpp \
					$(SRC_PATH)/PowerPotion.cpp \
					$(SRC_PATH)/PoisonPotion.cpp \
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