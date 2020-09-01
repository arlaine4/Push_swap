/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:19:29 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:19:30 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_visu_n_val(t_visu *v, t_pil *pil)
{
	free(pil->a);
	free(pil->b);
	pil->na = 0;
	pil->nb = 0;
	pil->n = 0;
	mlx_destroy_image(v->mlx_ptr, v->img);
	mlx_destroy_image(v->mlx_ptr, v->img2);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
}

void	init_t_visu(t_visu *v, t_checker s)
{
	v->a = s.a;
	v->mlx_ptr = mlx_init();
	v->win_ptr = mlx_new_window(v->mlx_ptr, WIN_X, WIN_Y, WIN_TITLE);
	v->img = mlx_new_image(v->win_ptr, IMG_X, IMG_Y);
	v->img2 = mlx_new_image(v->win_ptr, IMG_X, 50);
	v->data = (int *)mlx_get_data_addr(v->img, &v->bpp, &v->sl, &v->endian);
	v->data2 = (int *)mlx_get_data_addr(v->img2, &v->bpp, &v->sl, &v->endian);
	ft_memset(v->data2, NOIR, sizeof(int) * IMG_X * 50);
}

void	put_seperation_n_title(t_visu v)
{
	int		i;

	i = 0;
	while (i < WIN_Y - 244)
	{
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 95, 98 + i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, IMG_X + 101, 98 + i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 2 * IMG_X + 105, 98 + i, BLANC);
		++i;
	}
	i = 96;
	while (i < 2 * IMG_X + 104)
	{
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 99, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 145, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 655, BLANC);
		++i;
	}
	mlx_string_put(v.mlx_ptr, v.win_ptr, 100, 110, JAUNE, VISU_A);
	mlx_string_put(v.mlx_ptr, v.win_ptr, IMG_X + 100, 110, BLEU, VISU_B);
	put_forground(v);
}

void	put_exec_n_nb_op(t_visu v, char **ins, int i)
{
	char	*tmp;

	tmp = ft_itoa(i);
	mlx_string_put(v.mlx_ptr, v.win_ptr, IMG_X - 150, 685, BLANC, VISU_EXEC);
	mlx_string_put(v.mlx_ptr, v.win_ptr, IMG_X + 60, 685, BLANC, VISU_OP);
	mlx_string_put(v.mlx_ptr, v.win_ptr, IMG_X - 75, 685, BLANC, ins[i]);
	mlx_string_put(v.mlx_ptr, v.win_ptr, IMG_X + 300, 685, BLANC, tmp);
	free(tmp);
}

int		key_event(int key, t_visu *v)
{
	if (key == 53)
	{
		exit(EXIT_SUCCESS);
		v->mlx_ptr = NULL;
	}
	else if (key == 49)
	{
		sleep(3);
	}
	return (1);
}
