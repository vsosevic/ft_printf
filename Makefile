# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 18:51:27 by vsosevic          #+#    #+#              #
#    Updated: 2017/02/20 18:57:40 by vsosevic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

G = gcc

FLAG = -Wall -Wextra -Werror

SRC = 	ft_printf.c				\
		fill_width_with.c		\
		ft_max_min.c			\
		ft_pf_putchar.c			\
		ft_pf_putstr.c			\
		ft_putnbr_base.c		\
		ft_putnstr.c			\
		ft_putwchar.c			\
		get_params.c			\
		get_unsigned_length.c	\
		handle_char.c			\
		handle_hex.c			\
		handle_int.c			\
		handle_ob.c				\
		handle_string.c			\
		handle_uint.c			\
		handle_unbr.c			\
		handle_wchar.c			\
		handle_wstr.c

HDR = ft_printf.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
		make -C libft
		ar -cru $(NAME) $(OBJ) libft/*.o
		ranlib $(NAME)
		@echo libftprintf.a has been made.

%.o: %.c
		$(G) $(CFLAGS) -c -o $@ $<

clean:
		make clean -C ./libft
		$(DEL) $(OBJ)
		@echo OBJ_libftprintf have been cleaned.

fclean: clean
		make fclean -C ./libft
		$(DEL) $(NAME)
		@echo libftprintf.a and *.o have been cleaned.

re: all
		make all -C ./libft
		@echo everything have been cleaned.
