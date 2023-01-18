# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 15:01:49 by aquincho          #+#    #+#              #
#    Updated: 2023/01/18 09:55:58 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon

CC = g++
CFLAGS = -std=c++98 -Wall -Werror -Wextra 
RM = rm -f

INC_DIR = ./
INC_FLAGS = -I $(INC_DIR)

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re