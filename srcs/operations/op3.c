/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:20:21 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:20:22 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		median(int *tab, int size)
{
	int		i;
	int		j;
	int		less;

	i = 0;
	while (i < size)
	{
		j = 0;
		less = 0;
		while (j < size)
		{
			if (j != i)
				tab[j] > tab[i] ? 1 : ++less;
			++j;
		}
		if (less == size / 2)
			return (tab[i]);
		++i;
	}
	return (0);
}

void	separate_pil_a(t_pil *s, char **t)
{
	int		i;
	int		pivot;

	i = 0;
	pivot = median(s->a, s->na);
	while (i < s->na)
	{
		if (s->a[0] < pivot)
		{
			push_b(s);
			*t = ft_strcat(*t, "pb\n");
		}
		else
		{
			rotate_a(s);
			*t = ft_strcat(*t, "ra\n");
			++i;
		}
	}
}

void	separate_pil_b(t_pil *s, char **t)
{
	int		i;
	int		pivot;

	i = 0;
	pivot = median(s->b, s->nb);
	while (i < s->nb)
	{
		if (s->b[0] >= pivot)
		{
			push_a(s);
			*t = ft_strcat(*t, "pa\n");
		}
		else
		{
			rotate_b(s);
			*t = ft_strcat(*t, "rb\n");
			++i;
		}
	}
}
