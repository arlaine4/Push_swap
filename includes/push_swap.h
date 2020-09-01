/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:29:41 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:09:12 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "mlx.h"

# define STDIN 0

/*
**	---------------------------------------------------------------------------
**	--------------------------------------------------------- Macros for colors
**	---------------------------------------------------------------------------
*/

# define NOIR 0x0
# define BLANC 0xffffff
# define VERT 0x056C1E
# define JAUNE 0xE8D214
# define CYAN 0xffff0
# define BLEU 0x1B53F3
# define VIOLET 0x7148E8
# define TAUPE 0xF9903D
# define MARRON 0x44300E
# define ROUGE 0xB22222
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define MAGENTA "\033[35m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define WHITE "\033[0m"

/*
**	---------------------------------------------------------------------------
**	----------------------------------------------------- Macros for visualizer
**	---------------------------------------------------------------------------
*/

# define LIL_SIZE 8
# define MID_SIZE 48
# define BIG_SIZE 50000
# define WIN_X 1400
# define WIN_Y 800
# define IMG_X 600
# define IMG_Y 500
# define WIN_TITLE "push_swag"
# define VISU_EXEC "exec : "
# define VISU_OP "number of operations : "
# define VISU_A "-------------------------- Pile A --------------------------"
# define VISU_B "-------------------------- Pile B --------------------------"
# define TITLE "P U S H_S W A G"

/*
**	This struct is for push_swap and checker
*/

typedef	struct		s_pil
{
	int				*a;
	int				*b;
	int				*step;
	int				na;
	int				nb;
	int				n;
	int				ign;
	int				tour;
	int				i_step;
}					t_pil;

/*
**	This struct is for checker
*/

typedef	struct		s_checker
{
	char			**ins;
	int				*a;
	int				n;
	int				boo;
}					t_checker;

/*
**	This structt contain the mlx variables
*/

typedef	struct		s_visu
{
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img;
	int				*data;
	void			*img2;
	int				*data2;
	int				*a;
	int				bpp;
	int				sl;
	int				endian;
}					t_visu;

/*
**	---------------------------------------------------------------------------
**	---------------------------------------------------------------- Operations
**	---------------------------------------------------------------------------
*/

void				swap_a(t_pil *s);
void				swap_b(t_pil *s);
void				push_a(t_pil *s);
void				push_b(t_pil *s);
void				rotate_a(t_pil *s);
void				rotate_b(t_pil *s);
void				reverse_rotate_a(t_pil *s);
void				reverse_rotate_b(t_pil *s);

/*
**	---------------------------------------------------------------------------
**	---------------------------------------------------------------------------
**	---------------------------------------------------------------------------
*/

/*
**	===========================================================================
**	================================================================= Push_swap
**	===========================================================================
*/

int					parsing_ps(t_pil *s, int ac, char **av);
char				*find_best_algo(t_pil s);
int					check_tri_ps(int *pil, int size);
void				print_operations(char *operations);
int					median(int *pil, int size);
int					catetallo(char **t);
char				*algo_small_sort(t_pil *s);
char				*algo_small_sort_reverse(t_pil *s);
char				*small_sort(t_pil *s);
char				*small_sort_reverse(t_pil *s);
char				*bad_quick_sort(t_pil s);
char				*quick_sort(t_pil s, char *t);
void				separate_pil_a(t_pil *s, char **t);
void				separate_pil_b(t_pil *s, char **t);
void				r_to_tri(t_pil *pil, char **t);
void				put_n_order_3_last_of_b(t_pil *s, char **t);

/*
**	===========================================================================
**	===========================================================================
**	===========================================================================
*/

/*
**	---------------------------------------------------------------------------
**	------------------------------------------------------------------- Checker
**	---------------------------------------------------------------------------
*/

void				init_for_exec(t_pil *t, t_checker s);
int					checker_instructions(char *str);
int					parsing_c(t_checker *s, int ac, char **av);
int					*exec_instruc(t_checker *s);
void				check_tri_c(t_checker s);

/*
**	---------------------------------------------------------------------------
**	---------------------------------------------------------------------------
**	---------------------------------------------------------------------------
*/

/*
**	===========================================================================
**	================================================================ Visualizer
**	===========================================================================
*/

void				exec_visu(t_checker s);
void				init_t_visu(t_visu *v, t_checker s);
int					key_event(int key, t_visu *v);
void				put_exec_n_nb_op(t_visu v, char **ins, int i);
void				put_seperation_n_title(t_visu v);
void				init_t_visu(t_visu *v, t_checker s);
void				free_visu_n_val(t_visu *v, t_pil *pil);
void				put_forground(t_visu v);

/*
**	===========================================================================
**	===========================================================================
**	===========================================================================
*/

#endif
