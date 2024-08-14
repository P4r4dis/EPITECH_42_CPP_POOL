##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex02/test
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Fri Jul 26 8:02:46 PM 2024 Paradis
## Last update Wed Jul 30 5:02:30 PM 2024 Paradis
##

G++           	= 	g++
#############################################
SRC_PATH		= 	../source
INC_PATH 		= 	../include
BIN_PATH 		= 	./bin

NAME          	= 	test_nurse
#############################################

INCFLAGS     	+= 	-I $(INC_PATH)
CRITFLAGS    	+=  --coverage -lcriterion
CPPFLAGS     	+= 	-g -Wall -Wextra -Werror -W -Wfatal-errors -std=c++11 $(INCFLAGS) $(CRITFLAGS)

SRCS         	= 	$(BIN_PATH)/test_main.cpp \
               		$(SRC_PATH)/SickKoala.cpp \
					$(SRC_PATH)/KoalaNurse.cpp

OBJS         	= 	$(SRCS:.cpp=.o)
OBJS_GCDA    	= 	$(SRCS:.cpp=.gcda)
OBJS_GCNO    	= 	$(SRCS:.cpp=.gcno)
COVERAGE	 	= 	../../../../coverage.*
LOG 			= 	*.log 

all				: 	$(NAME)

$(NAME)			: 	$(OBJS)
					$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME)
					@echo "Current working directory: $$PWD"
					@valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all --error-exitcode=1 ./$(NAME) 2>&1 | tee valgrind_output.log || true
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