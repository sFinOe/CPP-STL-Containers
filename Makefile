NAME = ft_containers
TESTER = tester

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf
INCLUDE = $(wildcard ./includes/*.hpp ./containers/*.hpp ./utils/*.hpp)
INCLUDES = -I ./includes -I ./containers -I ./utils
TEST_INCLUDE = $(wildcard ./includes/*.hpp ./containers/*.hpp ./utils/*.hpp ./unit_test/*.hpp)
TEST_INCLUDES = -I ./unit_test/ -I ./includes -I ./containers -I ./utils 
SRC = $(wildcard ./*.cpp)
TEST_SRC = $(wildcard ./unit_test/*.cpp)
PREFIX = ./obj/


OBJS = $(addprefix $(PREFIX), $(SRC:.cpp=.o))
TEST_OBJS = $(addprefix $(PREFIX), $(TEST_SRC:.cpp=.o))

all: $(NAME)

$(PREFIX) :
	@mkdir -p $(PREFIX)
	@mkdir -p $(PREFIX)/unit_test

$(NAME): $(PREFIX) $(OBJS) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
	@printf "\033[2K\r\033[0;32;1mProgram is ready\n\033[0m"

$(TESTER) : $(PREFIX) $(TEST_OBJS) $(TEST_INCLUDE)
	@$(CC) $(CFLAGS) $(TEST_OBJS) $(TEST_INCLUDES) -o $(TESTER)
	@printf "\033[2K\r\033[0;32;1mTester is ready\n\033[0m"

$(PREFIX)%.o: %.cpp $(INCLUDE) $(TEST_INCLUDE)
	@$(CC) $(CFLAGS) $(INCLUDES) $(TEST_INCLUDES) -c $< -o $@
	@printf "\033[2K\r\033[0;32mCompiling $<\033[0m"


clean:
	@$(RM) $(OBJS)
	@rm -rf $(PREFIX)
	@printf "\033[2K\r\033[0;32mCleaned!\033[0m"

fclean: clean
	@$(RM) $(NAME) $(TESTER) $(TEST_OBJS)
	@printf "\033[2K\r\033[0;32mFile Cleaned!\033[0m"

re: fclean all

.PHONY: all clean fclean re


# Tests

test: $(TESTER)
	@printf "\033[2K\r\033[0;32m./tester\n\033[0m"
