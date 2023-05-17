# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 10:33:36 by aquincho          #+#    #+#              #
#    Updated: 2023/05/17 10:40:09 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
IFLAGS = -I $(INC_DIR)
RM = rm -f

INC_DIR = ./include/
SRC_DIR = ./src/
SRC_FILES = main.cpp PmergeMe.cpp
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re