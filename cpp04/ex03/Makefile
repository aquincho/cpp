# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <aquincho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:36:07 by aquincho          #+#    #+#              #
#    Updated: 2023/01/30 15:36:03 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

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

MAIN_NAMES = main
MAIN_FILES = $(addsuffix .cpp, $(MAIN_NAMES))

CLASS_DIR = class/
CLASS_NAMES = AMateria Character Cure Ice MateriaSource
CLASS_FILES = $(addsuffix .cpp, $(CLASS_NAMES))
CLASS = $(addprefix $(CLASS_DIR), $(CLASS_FILES))

SRC_FILES = $(MAIN_FILES) $(CLASS)

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