# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 11:43:01 by aquincho          #+#    #+#              #
#    Updated: 2023/02/10 10:48:02 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

GREEN = \033[32m
RED = \033[31m
BLUE = \033[34m
DEFAULT = \033[0m

CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98
MKDIR = mkdir -p
RM = rm -f
RMDIR = rm -rf

INC_DIR = ./include
IFLAGS = -I$(INC_DIR)

SRC_DIR = ./src/

SRC_NAMES = main Span
SRC_FILES = $(addsuffix .cpp, $(SRC_NAMES))


OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:%.cpp=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@
	@echo "$(GREEN)=== Compilation classes \t\tDONE$(DEFAULT)"

all: $(NAME)

clean:
	@$(RMDIR) $(OBJ_DIR)
	@echo "$(BLUE)=== Cleaning objects \t\t\tDONE$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)=== Cleaning executable \t\tDONE$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re