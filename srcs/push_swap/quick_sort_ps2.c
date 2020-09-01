/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_ps2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:21:12 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:21:12 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	The 2 next functions are for sorting 3 elements or		less on B
*/

static char	*for_3_b(t_pil *s)
{
	if (s->b[0] > s->b[1] && s->b[1] < s->b[2] && s->b[0] > s->b[2])
	{
		rotate_b(s);
		return ("rb\n");
	}
	else if (s->b[0] > s->b[1] && s->b[1] < s->b[2] && s->b[0] < s->b[2])
	{
		swap_b(s);
		return ("sb\n");
	}
	else if (s->b[0] < s->b[1] && s->b[1] > s->b[2] && s->b[0] < s->b[2])
	{
		reverse_rotate_b(s);
		swap_b(s);
		return ("rrb\nsb\n");
	}
	else if (s->b[0] < s->b[1] && s->b[1] > s->b[2] && s->b[0] > s->b[2])
	{
		reverse_rotate_b(s);
		return ("rrb\n");
	}
	return ("");
}

static char	*small_sort_b(t_pil *s)
{
	if (s->nb == 2 && s->b[0] > s->b[1])
	{
		swap_b(s);
		return ("sb\n");
	}
	else if (s->nb == 3)
	{
		if (s->b[0] > s->b[1] && s->b[1] > s->b[2] && s->b[0] > s->b[2])
		{
			swap_b(s);
			reverse_rotate_b(s);
			return ("sb\nrrb\n");
		}
		else
			return (for_3_b(s));
	}
	return ("");
}

int			catetallo(char **t)
{
	if (*t == NULL)
	{
		if (!(*t = ft_strnew(BIG_SIZE)))
			return (0);
	}
	return (1);
}

void		put_n_order_3_last_of_b(t_pil *s, char **t)
{
	*t = ft_strcat(*t, small_sort_b(s));
	while (s->nb > 0)
	{
		push_a(s);
		rotate_a(s);
		*t = ft_strcat(*t, "pa\nra\n");
		s->ign++;
	}
}

void		r_to_tri(t_pil *pil, char **t)
{
	int		min;

	min = min_int_tab(pil->a, pil->na);
	while (pil->a[0] != min)
	{
		rotate_a(pil);
		*t = ft_strcat(*t, "ra\n");
	}
}
