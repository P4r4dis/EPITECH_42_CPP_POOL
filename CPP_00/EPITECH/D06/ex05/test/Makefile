##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex05/test
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Wed Jul 31 4:51:42 PM 2024 Paradis
## Last update Sat Aug 30 5:22:14 PM 2024 Paradis
##


G++           	= 	g++
#############################################
SRC_PATH		= 	../source
INC_PATH 		= 	../include
BIN_PATH 		= 	./bin

NAME          	= 	test_list
#############################################

INCFLAGS     	+= 	-I $(INC_PATH)
CRITFLAGS    	+=  --coverage -lcriterion
CPPFLAGS     	+= 	-g -Wall -Wextra -Werror -W -Wfatal-errors -std=c++11 $(INCFLAGS) $(CRITFLAGS)

SRCS         	= 	$(BIN_PATH)/test_main.cpp \
               		$(SRC_PATH)/SickKoala.cpp \
					$(SRC_PATH)/KoalaNurse.cpp \
					$(SRC_PATH)/KoalaDoctor.cpp \
					$(SRC_PATH)/SickKoalaList.cpp \
					$(SRC_PATH)/KoalaNurseList.cpp \
					$(SRC_PATH)/KoalaDoctorList.cpp

OBJS         	= 	$(SRCS:.cpp=.o)
OBJS_GCDA    	= 	$(SRCS:.cpp=.gcda)
OBJS_GCNO    	= 	$(SRCS:.cpp=.gcno)
COVERAGE	 	= 	../../../../coverage.*
LOG 			= 	*.log 
VGCORE			=	vgcore.*
all				: 	$(NAME)

$(NAME)			: 	$(OBJS)
					$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME)

VALGRIND		:	$(NAME)
					@echo "Current working directory: $$PWD"
					@valgrind --trace-children=yes --quiet --leak-check=full --trace-children=yes --show-leak-kinds=all --error-exitcode=1 ./$(NAME) 2>&1 | tee valgrind_output.log || true
					@if ! grep -q "definitely lost" valgrind_output.log; \
					then \
						echo -e "\033[32mNo memory leaks detected, running unit tests...\033[0m"; \
					else \
						echo -e "\033[31mMemory leaks detected, aborting.\033[0m"; \
						exit 1; \
					fi

RM 				= 	rm -rf

clean			:
					$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO) $(COVERAGE) $(LOG) $(VGCORE)

fclean			: 	clean
					$(RM) $(NAME)

re				: 	fclean all

.PHONY			: all clean fclean re