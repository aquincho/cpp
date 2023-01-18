# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 09:55:51 by aquincho          #+#    #+#              #
#    Updated: 2023/01/18 11:17:00 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re