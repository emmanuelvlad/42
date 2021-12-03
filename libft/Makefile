# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evlad <evlad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 16:35:16 by evlad             #+#    #+#              #
#    Updated: 2021/12/03 19:20:16 by evlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_LIST = ft_memset.c \
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
			 ft_strisdigit.c \
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
			 ft_printf.c \
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
			 get_next_line.c \

LIBFT_OBJ = $(LIBFT_LIST:%.c=%.o)

OBJ_PATH = ./obj/

LIBFT_FILES = $(LIBFT_OBJ:%=$(OBJ_PATH)%)

FLAGS = -Wextra -Werror -Wall

LIBFT_NAME = libft.a

c_green = $$(tput setaf 2)
c_reset = $$(tput sgr0)
c_red = $$(tput setaf 1)
OK = "$(c_green)[OK]$(c_reset)"

$(OBJ_PATH)%.o: $(LIBFT_LIST) ./printf.h ./libft.h ./get_next_line.h
	@echo -e '  compiling: ${@}'
	@gcc $(FLAGS) -c $(@F:%.o=%.c) -o $@

all: $(LIBFT_NAME)

prepare:
	@mkdir -p $(OBJ_PATH)

$(LIBFT_NAME): prepare $(LIBFT_FILES)
	@ar rc $(LIBFT_NAME) $(LIBFT_FILES)
	@ranlib $(LIBFT_NAME)

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(LIBFT_NAME)

re: fclean all

.PHONY: clean fclean re
