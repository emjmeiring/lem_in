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

FLAG=-Wall -Wextra -g#-Werror

RM=rm -f

INC= -L ./libft -lft

PATH_SRC= ./

PATH_HD= -I ./

SRC = $(PATH_SRC)main.c $(PATH_SRC)reading.c $(PATH_SRC)pop_farm.c

OBJ = main.o reading.o pop_farm.o

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	@echo "Compilied\t\033[33m$@\033[0m"
	@$(CC) $(FLAG) -c -o $@ $^ $(PATH_HD)

$(NAME): $(OBJ)
		@echo "Linking objects with the libraries..."
		@make re -C libft/
		@$(CC) $(FLAG) $(OBJ) -o $@ $(PATH_HD) $(INC)
		@echo "\033[32mDone!\033[0m\nManufactured\t\033[31m$@\033[0m..."

clean:
		@echo "Cleaning\t\033[34m$(NAME)\033[m"
		@$(RM) $(OBJ)
		@echo "**********Done!********"

fclean: clean
		@$(RM) $(NAME)

re: fclean all
