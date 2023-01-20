# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 13:18:32 by aquincho          #+#    #+#              #
#    Updated: 2023/01/20 13:51:02 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

INC_DIR = ./
IFLAGS = -I $(INC_DIR)

SRCS = main.cpp Fixed.cpp
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