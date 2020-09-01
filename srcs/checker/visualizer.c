/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:19:23 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:19:24 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_instr_visu(t_pil *pil, char *instr)
{
	if (ft_strcmp(instr, "pa") == 0)
		push_a(pil);
	else if (ft_strcmp(instr, "pb") == 0)
		push_b(pil);
	else if (ft_strcmp(instr, "sa") == 0 || ft_strcmp(instr, "ss") == 0)
		swap_a(pil);
	else if (ft_strcmp(instr, "sb") == 0 || ft_strcmp(instr, "ss") == 0)
		swap_b(pil);
	else if (ft_strcmp(instr, "ra") == 0 || ft_strcmp(instr, "rr") == 0)
		rotate_a(pil);
	else if (ft_strcmp(instr, "rb") == 0 || ft_strcmp(instr, "rr") == 0)
		rotate_b(pil);
	else if (ft_strcmp(instr, "rra") == 0 || ft_strcmp(instr, "rrr") == 0)
		reverse_rotate_a(pil);
	else if (ft_strcmp(instr, "rrb") == 0 || ft_strcmp(instr, "rrr") == 0)
		reverse_rotate_b(pil);
}

void	pil_to_img_b(t_pil pil, t_visu *v, int h_pxl)
{
	int		i;
	int		j;
	int		x;
	int		pos;
	int		l_pxl;

	x = 0;
	pos = 0;
	while (x < pil.nb)
	{
		j = 0;
		l_pxl = (poeist(pil.b[x], v->a, pil.n) + 1) * (IMG_X / pil.n);
		while (j < h_pxl)
		{
			i = -1;
			while (++i < l_pxl)
				v->data[pos++] = BLEU;
			while (i++ < v->sl / (int)sizeof(int))
				v->data[pos++] = NOIR;
			++j;
		}
		++x;
	}
}

void	pil_to_img_a(t_pil pil, t_visu *v, int h_pxl)
{
	int		i;
	int		j;
	int		x;
	int		pos;
	int		l_pxl;

	x = 0;
	pos = 0;
	while (x < pil.na)
	{
		j = 0;
		l_pxl = (poeist(pil.a[x], v->a, pil.n) + 1) * (IMG_X / pil.n);
		while (j < h_pxl)
		{
			i = -1;
			while (++i < l_pxl)
				v->data[pos++] = JAUNE;
			while (i++ < v->sl / (int)sizeof(int))
				v->data[pos++] = NOIR;
			++j;
		}
		++x;
	}
}

void	write_into_img(t_visu *v, t_pil pil)
{
	ft_memset(v->data, 0, sizeof(int) * IMG_X * IMG_Y);
	pil_to_img_a(pil, v, IMG_Y / pil.n);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img, 100, 151);
	ft_memset(v->data, 0, sizeof(int) * IMG_X * IMG_Y);
	pil_to_img_b(pil, v, IMG_Y / pil.n);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img, IMG_X + 102, 151);
}

void	exec_visu(t_checker s)
{
	int		i;
	t_visu	v;
	t_pil	pil;

	i = 0;
	init_for_exec(&pil, s);
	init_t_visu(&v, s);
	put_seperation_n_title(v);
	write_into_img(&v, pil);
	while (i < tab_2d_len(s.ins))
	{
		mlx_do_sync(v.mlx_ptr);
		exec_instr_visu(&pil, s.ins[i]);
		mlx_put_image_to_window(v.mlx_ptr, v.win_ptr, v.img2, 385, IMG_Y + 175);
		write_into_img(&v, pil);
		put_exec_n_nb_op(v, s.ins, i);
		if (!mlx_key_hook(v.win_ptr, key_event, &v))
			return ;
		++i;
	}
	mlx_loop(v.mlx_ptr);
	free_visu_n_val(&v, &pil);
}
