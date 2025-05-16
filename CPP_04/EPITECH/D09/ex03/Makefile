##
## Makefile for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_03/EPITECH/D09/ex01
##
## Made by Paradis
## Login   <Adil Denia>
##
## Started on  Wed May 7 5:35:42 PM 2025 Paradis
## Last update Tue May 12 7:10:44 PM 2025 Paradis
##

# # Compilateur
G++			=	g++
##############################################
BIN_PATH	=	./bin
SRC_PATH	=	./source
INC_PATH	=	./include
UT_PATH		=	./test


NAME		=	Priest
UT_NAME 	= 	test_$(NAME)
##############################################

# # Options de compilation
INCFLAGS	+=	-I $(INC_PATH)
CPP_VERSION	+=	-std=c++23
CPPFLAGS	+= 	-g -Wall -Wextra -Werror -W -Wfatal-errors -Wshadow -Wno-shadow $(CPP_VERSION) $(INCFLAGS)

# # Files sources
SRCS		=	$(SRC_PATH)/Peasant.cpp \
				$(SRC_PATH)/Knight.cpp \
				$(SRC_PATH)/Enchanter.cpp \
				$(SRC_PATH)/Priest.cpp \
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

ARGS		=	"$(filter-out $@,$(MAKECMDGOALS))"

VALGRIND	:	$(NAME)
				@valgrind --trace-children=yes --quiet --leak-check=full --show-leak-kinds=all  --error-exitcode=1 ./$(NAME) $(ARGS) 2>&1 | tee valgrind_output.log || true
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