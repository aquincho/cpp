# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 12:51:04 by aquincho          #+#    #+#              #
#    Updated: 2023/01/20 12:51:06 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

CC = g++
CFLAGS = -std=c++98 -Wall -Werror -Wextra
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