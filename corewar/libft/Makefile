# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpipart <fpipart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/10 14:21:45 by fpipart           #+#    #+#              #
#    Updated: 2017/07/19 16:53:57 by fpipart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --silent

LIST = conversion_diouxx.c conversion_type.c ft_printf.c	\
		 conversion_dou.c conversion_pct.c conversion_cc.c	\
		 conversion_ptr.c conversion_str.c ft_memset.c		\
		 ft_bzero.c ft_memcpy.c ft_memccpy.c				\
		 ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c	\
		 ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c	\
		 ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c	\
		 ft_strstr.c ft_strnstr.c ft_strcmp.c  ft_strncmp.c	\
		 ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c	\
		 ft_isascii.c ft_isprint.c ft_toupper.c				\
		 ft_tolower.c ft_lowerstr.c ft_memalloc.c			\
		 ft_memdel.c	ft_strnew.c	 ft_strdel.c ft_strclr.c\
		 ft_striter.c ft_striteri.c ft_strmap.c 			\
		 ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c 	\
		 ft_strjoin.c ft_strjoin_free.c ft_strtrim.c		\
		 ft_strsplit.c ft_itoa.c ft_itoa_max.c 				\
		 ft_itoa_base_max.c ft_putchar.c ft_putstr.c 		\
		 ft_putendl.c ft_putnbr.c ft_putchar_fd.c			\
		 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c		\
		 ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c	\
		 ft_lstiter.c ft_lstmap.c ft_pow.c ft_abs.c			\
		 ft_wordcount.c ft_wordlen.c ft_memcpy_rev.c		\
		 ft_putwchar_fd.c ft_putwstr_fd.c ft_putwchar.c		\
		 ft_putwstr.c ft_strwlen.c ft_strwnew.c				\
		 ft_strwncpy.c ft_strwttlen.c ft_strwsub.c			\
		 ft_wcharlen.c no_conversion.c ft_strwdel.c			\
		 conversion_diouxx_bis.c ft_is_sort.c				\
		 get_next_line.c

OBJ = $(LIST:%.c=%.o)

OBJ_PATH = ../obj/

LIBFT_PATH = ../obj/libft/

FILES = $(OBJ:%=$(LIBFT_PATH)%)

FLAGS = -Wextra -Werror -Wall -Wno-unused-but-set-parameter

NAME = libft.a

$(OBJ_PATH)%.o: $(LIST) ./libft.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(LIBFT_PATH)
	@gcc $(FLAGS) -c $(@F:%.o=%.c) -o $@

all: $(NAME)

$(NAME): $(FILES)
	@ar rc $(NAME) $(FILES)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(LIBFT_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
