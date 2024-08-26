##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/EPITECH/D06/ex00
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Fri Jul 19 6:35:05 PM 2024 Paradis
## Last update Tue Aug 26 4:11:53 PM 2024 Paradis
##

# # Compilateur
G++			=	g++
##############################################
BIN_PATH	=	./bin
SRC_PATH	=	./source
INC_PATH	=	./include
UT_PATH		=	./test
FILE_TEST	=	$(UT_PATH)/D06_ex00_fileTest1.txt \
				$(UT_PATH)/D06_ex00_fileTest2.txt

NAME		=	my_cat
UT_NAME 	= 	test_$(NAME)
##############################################

# # Options de compilation
INCFLAGS	+=	-I $(INC_PATH)
CPPFLAGS	+= 	-Wall -Wextra -Werror -W -Wfatal-errors -std=c++98 $(INCFLAGS)

# # Files sources
SRCS		=	$(SRC_PATH)/MyCat.cpp \
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

VALGRIND	:	$(OBJS)
				$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME)
				@valgrind --leak-check=full --show-leak-kinds=all  --error-exitcode=1 ./$(NAME) $(FILE_TEST) 2>&1 | tee valgrind_output.log || true
				@if ! grep -q "definitely lost" valgrind_output.log; \
				then \
					echo -e "\033[32mNo memory leaks detected, running binary...\033[0m"; \
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