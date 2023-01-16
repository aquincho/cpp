NAME = zombie

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

INC_DIR = ./
INC_FLAGS = -I $(INC_DIR)

SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re