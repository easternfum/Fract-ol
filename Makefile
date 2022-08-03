# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 09:28:59 by kfum              #+#    #+#              #
#    Updated: 2022/08/03 12:46:03 by kfum             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Directories
INC_PATH = ./include
SRC_PATH = ./src/

# Flags
CC = gcc
FLAGS = -Wall -Wextra -Werror
MINILIB = -I /usr/local/include -L /usr/local/lib -l mlx -l ft -framework OpenGL -framework Appkit
INC_LIB = -Llibft

# Files to compile
FILES = color control fractol graphic print window

# Files
SRCS = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(SRC_PATH), $(addsuffix .o, $(FILES)))
LIB_MLX = libft/libft.a

all : $(NAME)
.SILENT : $(OBJS)

libft/libft.a :
	@echo "$(GREEN)Compiling libft files...$(DEFAULT)"
	@$(MAKE) -sC libft/ all
	@echo "$(GREEN)\nLibft compilation done.\n$(DEFAULT)"
	@echo "$(GREEN)Compiling fractol files...$(DEFAULT)"
	

$(NAME) : $(LIB_MLX) $(OBJS)
	@echo -n '.'
	@$(CC) $^ -o $@ $(FLAGS) $(INC_LIB) $(MINILIB)
	@echo "$(GREEN)\nFractol compilation done.$(DEFAULT)"

clean :
	@echo "$(RED)Cleaning libft .o and .a files...$(DEFAULT)"
	@$(MAKE) fclean -sC libft
	@echo "$(GREEN)DONE.\n$(DEFAULT)"
	@echo "$(RED)Cleaning $(NAME) .o files...$(DEFAULT)"
	@rm -f $(OBJS)
	@echo "$(GREEN)DONE.\n$(DEFAULT)"

fclean : clean
	@echo "$(RED)Deleting .fractol...$(DEFAULT)" 
	@rm -f $(NAME)
	@echo "$(GREEN)DONE.\n$(DEFAULT)"

re : fclean all

.PHONY: all clean fclean re

# Output colors
DEFAULT	:=\033[0m
GREEN	:=\033[0;32m
RED		:=\033[0;31m
