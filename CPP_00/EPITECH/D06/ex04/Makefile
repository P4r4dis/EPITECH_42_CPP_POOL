##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex04
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Tue Jul 30 5:30:32 PM 2024 Paradis
## Last update Tue Aug 26 5:11:40 PM 2024 Paradis
##


# # Compilateur
G++			=	g++
##############################################
BIN_PATH	=	./bin
SRC_PATH	=	./source
INC_PATH	=	./include
UT_PATH		=	./test

NAME		=	doctor
UT_NAME 	= 	test_$(NAME)
##############################################

# # Options de compilation
INCFLAGS	+=	-I $(INC_PATH)
CPPFLAGS	+= 	-Wall -Wextra -Werror -W -Wfatal-errors -std=c++98 $(INCFLAGS)

# # Files sources
SRCS		=	$(SRC_PATH)/SickKoala.cpp \
				$(SRC_PATH)/KoalaNurse.cpp \
				$(SRC_PATH)/KoalaDoctor.cpp \
				$(BIN_PATH)/main.cpp

UT_SRC		=	$(UT_PATH)/$(NAME)_test.cpp

# # Files object
OBJS		=	$(SRCS:.cpp=.o)

# # Log file
LOG			=	*.log

CLEAN		=	clean
FCLEAN		=	fclean
RM			=	rm -rf

# # Default rules for compilation
all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME) 

VALGRIND	:	$(NAME)
				@echo "Current working directory: $$PWD"
				@valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all --error-exitcode=1 ./$(NAME) 2>&1 | tee valgrind_output.log || true
				@if ! grep -q "definitely lost" valgrind_output.log; \
				then \
					echo -e "\033[32mNo memory leaks detected, running unit tests...\033[0m"; \
				else \
					echo -e "\033[31mMemory leaks detected, aborting.\033[0m"; \
					exit 1; \
				fi			
# # Rule for clean files object
clean		:
				$(RM) $(OBJS) $(LOG)
				@$(MAKE) -s $(CLEAN) -C $(UT_PATH)

# # Target for clean name and files object
fclean		:	clean
				$(RM) $(NAME) $(UT_NAME)
				@$(MAKE) -s $(FCLEAN) -C $(UT_PATH)

re			: 	clean fclean all

# # Start units test
tests_run	:	fclean
				@$(MAKE) -s -C $(UT_PATH)
				$(UT_PATH)/$(UT_NAME)

.PHONY		: 	all clean fclean re tests_run