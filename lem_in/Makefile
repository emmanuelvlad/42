# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 16:48:29 by evlad             #+#    #+#              #
#    Updated: 2017/06/26 14:06:29 by evlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --silent

NAME = lem_in

SRC = src

LIST = main.c \
	   parsing.c \
	   init.c \
	   init2.c \
	   free.c \
	   free2.c \
	   check.c \
	   stock.c \
	   move.c \
	   find.c \
	   exit.c \
	   algo.c \
	   history.c \
	   debug.c \

FILES = $(LIST:%=./$(SRC)/%)

OBJ = $(LIST:%.c=%.o)
OBJ_PATH = ./obj/

PROGRAM = $(OBJ:%=$(OBJ_PATH)%)

LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = -L $(LIBFT_PATH) -lft

FLAGS = -Wextra -Werror -Wall

c_green = $$(tput setaf 2)
c_reset = $$(tput sgr0)
c_red = $$(tput setaf 1)
OK = "$(c_green)[OK]$(c_reset)"

$(OBJ_PATH)%.o: $(FILES) ./$(SRC)/$(NAME).h
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -c ./$(SRC)/$(@F:%.o=%.c) -o $(@F:%=$(OBJ_PATH)/%)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo -n '-> Compiling LIBFT .'
	@make -C $(LIBFT_PATH) -s
	@cp $(LIBFT_PATH)/*.h ./includes
	@echo -n '..			'
	@echo $(OK)

$(NAME): $(PROGRAM)
	@echo -n '-> Compiling LEM_IN ..'
	@gcc -o $(NAME) $(OBJ:%=$(OBJ_PATH)/%) $(LIBFT_INC)
	@echo -n '.			'
	@echo $(OK)

clean:
	@echo -n '-> Deleting object files ..'
	@/bin/rm -rf $(OBJ_PATH)
	@/bin/rm -rf ./includes/*.h
	@echo -n '.		'
	@make -C $(LIBFT_PATH) clean
	@echo $(OK)

fclean: clean
	@echo -n '-> Deleting executable files ..'
	@/bin/rm -f $(NAME)
	@echo -n '.	'
	@make -C $(LIBFT_PATH) fclean
	@echo $(OK)

re: fclean all

.PHONY: clean fclean re
