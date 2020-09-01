# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlaine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 15:10:04 by arlaine           #+#    #+#              #
#    Updated: 2019/06/17 15:10:04 by arlaine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = ./

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
ft_putstr.c ft_putstr_fd.c ft_split_whitespaces.c ft_strcat.c ft_strchr.c\
ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c\
ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c\
ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
ft_lstmap.c ft_lstiter.c ft_strrev.c ft_strndup.c ft_sqrt.c\
ft_recursive_power.c ft_realloc.c putstrsub.c ft_putnbr_base.c \
ft_putnbr_base_maj.c ft_putnbr_l.c ft_putnbr_lu.c ft_putnbr_u.c \
ft_put_address.c ft_putfloat.c ft_itoa_base.c ft_ltoa.c ft_ltoa_base.c \
ft_ltoa_base_maj.c power_of_ten.c number_of_digit.c ft_intchr.c char_to_str.c \
add_n_char_at_pos.c find_char_in_str.c ft_putnbr_base_u.c \
number_of_digit_base.c number_of_digit_base_u.c ft_putnbr_base_u_maj.c \
putfloat_prec.c get_next_line.c tab_2d_len.c ft_atol.c split_int.c \
max_int_tab.c min_int_tab.c pos_min_int_tab.c pos_max_int_tab.c \
sort_integer_table.c count_char_in_str.c check_tri_tab.c \
check_tri_tab_reverse.c number_of_number_in_str.c ft_abs.c poeist.c \
free_2d_char.c ft_strjoinfree.c

OBJS = $(SRCS:.c=.o)

HEADER = libft.h get_next_line.h

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
