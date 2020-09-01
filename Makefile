# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlaine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 18:09:59 by arlaine           #+#    #+#              #
#    Updated: 2019/06/13 10:51:18 by lyhamrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

CFLAGS = -Wall -Wextra -Werror
COMPIL = $(CC) $(CFLAGS)

LIBFT_PATH = libft/
MLX_PATH = minilibx_macos/
HEADER = includes/push_swap.h
P_S_I = -I includes/ -I libft/ -I minilibx_macos/
MLX_LDLIBS = -Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LIBFT_LDLIBS = -Llibft/ -lft
ALL_LDLIBS = $(MLX_LDLIBS) $(LIBFT_LDLIBS)

SRC_PATH = srcs/
SRC_PATH_PS = srcs/push_swap/
SRC_PATH_C = srcs/checker/
SRC_PATH_OP = srcs/operations/
SRC_NAME_PS = main_ps.c parsing_ps.c algo_ps.c small_sort.c quick_sort_ps.c \
			  bad_quick_sort_ps.c algo_small_sort.c quick_sort_ps2.c
SRC_NAME_C = checker_c.c main_c.c parsing_c.c execution_c.c visualizer.c \
			 visualizer2.c visualizer3.c
SRC_NAME_OP = op1.c op2.c op3.c
SRC_PS = $(addprefix $(SRC_PATH_PS),$(SRC_NAME_PS))
SRC_C = $(addprefix $(SRC_PATH_C),$(SRC_NAME_C))
SRC_OP = $(addprefix $(SRC_PATH_OP),$(SRC_NAME_OP))

OBJ_PATH = .obj/
OBJ_NAME_PS = $(SRC_NAME_PS:.c=.o)
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
OBJ_NAME_OP = $(SRC_NAME_OP:.c=.o)
OBJ_PS = $(addprefix $(OBJ_PATH),$(OBJ_NAME_PS))
OBJ_C = $(addprefix $(OBJ_PATH),$(OBJ_NAME_C))
OBJ_OP = $(addprefix $(OBJ_PATH),$(OBJ_NAME_OP))
OBJ_LIB_NAME = add_n_char_at_pos.o char_to_str.o check_tri_tab.o \
check_tri_tab_reverse.o count_char_in_str.o find_char_in_str.o free_2d_char.o \
ft_abs.o ft_atoi.o ft_atol.o ft_bzero.o ft_intchr.o ft_isalnum.o ft_isalpha.o \
ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_itoa_base.o ft_lstadd.o \
ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_ltoa.o \
ft_ltoa_base.o ft_ltoa_base_maj.o ft_memalloc.o ft_memccpy.o ft_memchr.o \
ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_put_address.o \
ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putfloat.o \
ft_putnbr.o ft_putnbr_base.o ft_putnbr_base_maj.o ft_putnbr_base_u.o \
ft_putnbr_base_u_maj.o ft_putnbr_fd.o ft_putnbr_l.o ft_putnbr_lu.o \
ft_putnbr_u.o ft_putstr.o ft_putstr_fd.o ft_realloc.o ft_recursive_power.o \
ft_split_whitespaces.o ft_sqrt.o ft_strcat.o ft_strchr.o ft_strclr.o \
ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o \
ft_striteri.o ft_strjoin.o ft_strjoinfree.o ft_strlcat.o ft_strlen.o \
ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strndup.o \
ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strrev.o ft_strsplit.o \
ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o get_next_line.o \
max_int_tab.o min_int_tab.o number_of_digit.o number_of_digit_base.o \
number_of_digit_base_u.o number_of_number_in_str.o poeist.o pos_max_int_tab.o \
pos_min_int_tab.o power_of_ten.o putfloat_prec.o putstrsub.o \
sort_integer_table.o split_int.o tab_2d_len.o
OBJ_LIB = $(addprefix $(LIBFT_PATH),$(OBJ_LIB_NAME))

LIBFT_A = $(addprefix $(LIBFT_PATH),libft.a)

all: $(NAME) $(NAME2)

$(NAME): $(LIBFT_A) $(OBJ_PS) $(OBJ_OP)
	@$(COMPIL) -o $(NAME) $(OBJ_PS) $(OBJ_OP) $(LIBFT_LDLIBS) $(P_S_I)

$(NAME2): $(LIBFT_A) $(OBJ_C) $(OBJ_OP) $(HEADER)
	@make -C $(MLX_PATH)
	@$(COMPIL) -o $(NAME2) $(OBJ_C) $(OBJ_OP) $(ALL_LDLIBS) $(P_S_I)

$(LIBFT_A): $(OBJ_LIB)
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH_PS)%.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	@$(COMPIL) $(P_S_I) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PATH_C)%.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	@$(COMPIL) $(P_S_I) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PATH_OP)%.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	@$(COMPIL) $(P_S_I) -o $@ -c $<

savetheworld: fclean
	@git add .
	@git commit -m "auto-save"
	@git push

3: all
	@sh testeur/3.sh

5: all
	@for n in {1..5}; do sh testeur/5.sh; done

100: all
	@for n in {1..5}; do sh testeur/100.sh; done

500: all
	@for n in {1..5}; do sh testeur/500.sh; done

fdubois: all
	@sh testeur/fdubois_script_test.sh

norm: fclean
	@norminette libft/ srcs/ includes/

error_test: all
	@sh testeur/error.sh

clean:
	@$(RM) -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)
#	@make clean -C $(MLX_PATH)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME2)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY : all clean fclean savetheworld re
