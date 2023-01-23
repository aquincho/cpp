# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 13:18:32 by aquincho          #+#    #+#              #
#    Updated: 2023/01/23 14:09:31 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
RM = rm -f

INC_DIR = ./
IFLAGS = -I $(INC_DIR)

SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re