# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 09:37:08 by aquincho          #+#    #+#              #
#    Updated: 2023/01/25 13:38:50 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

INC_DIR = ./
IFLAGS = -I $(INC_DIR)

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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