# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 11:03:58 by evlad             #+#    #+#              #
#    Updated: 2016/12/15 08:31:45 by evlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --silent

LIST = get_next_line.c main.c

FILES = $(LIST:%=./src/%)

OBJ = $(LIST:%.c=%.o)
OBJ_PATH = ./obj/

PROGRAM = $(OBJ:%=$(OBJ_PATH)%)

FLAGS = -g -Wextra -Werror -Wall 

NAME = get_next_line

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = -L $(LIBFT_PATH) -lft

c_green = $$(tput setaf 2)
c_reset = $$(tput sgr0)
c_red = $$(tput setaf 1)
OK = "$(c_green)[OK]$(c_reset)"

$(OBJ_PATH)%.o: $(FILES) ./src/$(NAME).h
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -c ./src/$(@F:%.o=%.c) -o $(@F:%=$(OBJ_PATH)/%)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo -n '-> Compiling LIBFT .'
	@make -C $(LIBFT_PATH) -s
	@cp $(LIBFT_PATH)/*.h ./includes
	@echo -n '..			'
	@echo $(OK)

$(NAME): $(PROGRAM)
	@echo -n '-> Compiling.'
	@gcc -o $(NAME) $(OBJ:%=$(OBJ_PATH)/%) $(LIBFT_INC)
	@echo -n '..	'
	@echo $(OK)

clean:
	@echo -n '-> Deleting object files...	'
	@/bin/rm -rf $(OBJ_PATH)
	@/bin/rm -f ./includes/*.h
	@make -C $(LIBFT_PATH) clean
	@echo $(OK)

fclean: clean
	@echo -n '-> Deleting executable file...	'
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@echo $(OK)

re: fclean all

it: re 
	@echo -n '-> Deleting object files...'
	@/bin/rm -f $(OBJ)
	@echo $(OK)
