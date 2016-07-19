# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomeirin- <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/25 11:32:01 by jomeirin-         #+#    #+#              #
#    Updated: 2016/07/02 07:31:52 by jomeirin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem_in

CC=gcc

CFLAGS=-Wall -Wextra -Werror -g

RM=rm -f

INC_LIBFT= -L./libft -lft

FCLEAN_LIB=make -C libft/ fclean

PATH_SRC= ./

PATH_HD= -I ./

SRC = $(PATH_SRC)main.c $(PATH_SRC)reading.c

OBJ = main.o reading.o

$(NAME):
	@echo "Compiling binaries..."
#	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT)
	@echo "*********Compilation was successful!**********"

all: $(NAME)

x11:
	@echo "Compiling binaries..."
	@make re -C libft/	
	@$(CC) $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm $(INC_LIBFT) 
	@echo "Compilation was successful!------^^&^&^"

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@make -C libft/ clean
	@echo "Done cleaning!"
fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ1) $(OBJ2)
	@echo "Cleaning libft object & binary files..."
#	@make -C libft/ fclean
	@echo "Cleaning binaries..."
	@$(RM) $(CHEC) $(PUSH)
	@echo "Done cleaning!"

norme:
	@clear
	@norminette $(SRC)

re: fclean all
