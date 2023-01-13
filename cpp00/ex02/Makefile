# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:23:57 by aquincho          #+#    #+#              #
#    Updated: 2023/01/13 14:07:50 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
IFLAGS = -I $(INC_DIR)
RM = rm -f

INC_DIR = ./
SRCS = Account.cpp tests.cpp
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