# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:36:40 by evlad             #+#    #+#              #
#    Updated: 2017/04/12 16:29:49 by evlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --silent

LIST = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_itoa_base.c \
	   ft_itoa_base_uint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_countword.c \
	   ft_countsword.c \
	   ft_countletter.c \
	   ft_countsletter.c \
	   ft_strtoupper.c \
	   ft_strtolower.c \
	   ft_binary_complete.c \
	   ft_wstrlen.c \
	   ft_putwchar.c \

LIBFT_PATH = $(OBJ_PATH)libft/

LIBFT_FILES = $(LIST:%=./libft/%)

LIBFT_OBJ = $(LIST:%.c=%.o)

LIBFT = $(LIBFT_OBJ:%=$(LIBFT_PATH)%)

PRINTF_LIST = ft_printf.c \
			  init_struct.c \
			  formating.c \
			  check_flags.c \
			  apply_flags.c \
			  apply_flags_2.c \
			  apply_precision.c \
			  apply_zero.c \
			  apply_diese.c \
			  conv_1.c \
			  conv_2.c \
			  cast.c \
			  freemalloc.c \
			  strsubwchar.c \

PRINTF_PATH = $(OBJ_PATH)printf/

PRINTF_FILES = $(PRINTF_LIST:%=./printf/%)

PRINTF_OBJ = $(PRINTF_LIST:%.c=%.o)

PRINTF = $(PRINTF_OBJ:%=$(PRINTF_PATH)%)

OBJ_PATH = ./obj/

FLAGS = -Wextra -Werror -Wall

NAME = libftprintf.a

c_green = $$(tput setaf 2)
c_reset = $$(tput sgr0)
c_red = $$(tput setaf 1)
OK = "$(c_green)[OK]$(c_reset)"

$(LIBFT_PATH)%.o: $(LIBFT_FILES) ./libft/libft.h ./printf/printf.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(LIBFT_PATH)
	@gcc $(FLAGS) -c ./libft/$(@F:%.o=%.c) -o $@


$(PRINTF_PATH)%.o: $(PRINTF_FILES) ./printf/printf.h ./libft/libft.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(PRINTF_PATH)
	@gcc $(FLAGS) -c ./printf/$(@F:%.o=%.c) -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF)
	@echo -n '-> Compiling'
	@echo -n '.'
	@ar rc $(NAME) $(LIBFT) $(PRINTF)
	@echo -n '.'
	@ranlib $(NAME)
	@echo -n '.		'
	@echo $(OK)
	
clean:
	@echo -n '-> Deleting object files...	'
	@/bin/rm -rf $(OBJ_PATH)
	@echo $(OK)

fclean: clean
	@echo -n '-> Deleting executable file...	'
	@/bin/rm -f $(NAME)
	@echo $(OK)

re: fclean all
