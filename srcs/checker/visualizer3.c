/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:19:37 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:19:38 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	decor2(t_visu v)
{
	int		i;

	i = WIN_X - 47;
	while (i < WIN_X)
	{
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 150, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 151, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 152, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 153, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 154, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 400, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 401, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 402, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 403, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 404, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 651, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 652, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 653, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 654, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 655, BLANC);
		++i;
	}
}

static void	decor(t_visu v)
{
	int		i;

	i = 0;
	while (i < 48)
	{
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 150, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 151, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 152, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 153, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 154, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 400, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 401, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 402, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 403, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 404, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 651, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 652, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 653, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 654, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 655, BLANC);
		++i;
	}
}

static void	horizontal(t_visu v)
{
	int		i;

	i = 47;
	while (i < WIN_X - 47)
	{
		if (i < WIN_X / 2 - 100 || i > WIN_X / 2 + 100)
		{
			mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 46, BLANC);
			mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 47, BLANC);
			mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 48, BLANC);
			mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 49, BLANC);
			mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 50, BLANC);
			mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 51, BLANC);
			mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, 52, BLANC);
		}
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, WIN_Y - 46, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, WIN_Y - 47, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, WIN_Y - 48, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, WIN_Y - 49, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, WIN_Y - 50, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, WIN_Y - 51, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i, WIN_Y - 52, BLANC);
		++i;
	}
}

static void	vertical(t_visu v)
{
	int		i;

	i = 47;
	while (i < WIN_Y - 47)
	{
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, WIN_X - 46, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, WIN_X - 47, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, WIN_X - 48, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, WIN_X - 49, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, WIN_X - 50, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, WIN_X - 51, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, WIN_X - 52, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 46, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 47, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 48, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 49, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 50, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 51, i, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, 52, i, BLANC);
		++i;
	}
}

void		put_forground(t_visu v)
{
	int		i;

	i = 0;
	while (i < IMG_X / 2)
	{
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i + 100, 696, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i + 100, 697, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i + 100, 698, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i + 100, 696, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i + 995, 696, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i + 995, 697, BLANC);
		mlx_pixel_put(v.mlx_ptr, v.win_ptr, i + 995, 698, BLANC);
		++i;
	}
	mlx_string_put(v.mlx_ptr, v.win_ptr, WIN_X / 2 - 75, 40, BLANC, TITLE);
	vertical(v);
	horizontal(v);
	decor(v);
	decor2(v);
}
