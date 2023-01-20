# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 09:55:51 by aquincho          #+#    #+#              #
#    Updated: 2023/01/20 10:59:22 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

INC_DIR = ./
IFLAGS = -I $(INC_DIR)

SRCS = main.cpp StrReplace.cpp
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

.PHONY: all clean flcean re