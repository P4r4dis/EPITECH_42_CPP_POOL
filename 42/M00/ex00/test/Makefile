G++           	= g++
#############################################
SRC_PATH		= ../ex00/source
INC_PATH 		= ../ex00/include
BIN_PATH 		= ./bin

NAME          	= test_Megaphone
#############################################

INCFLAGS     	+= -I $(INC_PATH)
CRITFLAGS    	+=  --coverage -lcriterion
CPPFLAGS     	+= -g -Wall -Wextra -Werror -W -Wfatal-errors std=c++23 $(INCFLAGS) $(CRITFLAGS)

SRCS         = $(BIN_PATH)/test_main.cpp \
               $(SRC_PATH)/test.cpp

OBJS         = $(SRCS:.cpp=.o)
OBJS_GCDA    = $(SRCS:.cpp=.gcda)
OBJS_GCNO    = $(SRCS:.cpp=.gcno)
COVERAGE	 = ../../coverage.* 

all: $(NAME)

$(NAME): $(OBJS)
	$(G++) $(CPPFLAGS) $(OBJS) -o $(NAME)

RM = rm -rf

clean:
	$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO) $(COVERAGE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re