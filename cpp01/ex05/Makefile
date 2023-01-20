NAME = harl

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

INC_DIR = ./
IFLAGS = -I $(INC_DIR)

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re