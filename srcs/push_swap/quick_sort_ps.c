/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:21:07 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:21:08 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		split_b2(t_pil *s, char **t, int pivot, int *n_step)
{
	if (s->nb > 1 && s->b[0] == min_int_tab(s->b, s->nb) && s->b[0] < pivot)
	{
		push_a(s);
		rotate_a(s);
		*t = ft_strcat(*t, "pa\nra\n");
		s->ign++;
	}
	else
	{
		push_a(s);
		*t = ft_strcat(*t, "pa\n");
		*n_step = *n_step + 1;
	}
}

/*
**	This function split B with all integers bigger than pivot on A
**	Define a pivot and push all integers bigger than pivot on A
*/

static void	split_b(t_pil *s, char **t)
{
	int		i;
	int		pivot;
	int		n_step;

	i = 0;
	n_step = 0;
	pivot = median(s->b, s->nb);
	while (i < s->nb)
	{
		if (s->b[0] >= pivot || s->b[0] == min_int_tab(s->b, s->nb))
			split_b2(s, t, pivot, &n_step);
		else
		{
			rotate_b(s);
			*t = ft_strcat(*t, "rb\n");
			++i;
		}
	}
	s->i_step++;
	s->step[s->i_step] = n_step;
}

static int	split_a(t_pil *s, char **t)
{
	int		i;

	i = 0;
	while (i < s->step[s->i_step])
	{
		if (poeist(s->a[0], s->a, s->na) == s->ign
				&& s->a[0] < min_int_tab(s->b, s->nb))
		{
			rotate_a(s);
			*t = ft_strcat(*t, "ra\n");
			s->ign++;
		}
		else
		{
			push_b(s);
			*t = ft_strcat(*t, "pb\n");
		}
		++i;
	}
	s->i_step--;
	return (i);
}

/*
**	This function split A when quick sort start : integers smaller than pivot
**	are push on B
**	Define a pivot and push all integers smaller than pivot on B
*/

static int	split_a1(t_pil *s, char **t)
{
	int		i;
	int		pivot;

	i = 0;
	if (s->tour > 0)
		return (split_a(s, t));
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
	s->step[s->i_step] = s->na;
	return (i);
}

char		*quick_sort(t_pil s, char *t)
{
	if (catetallo(&t) == 0)
		return (NULL);
	split_a1(&s, &t);
	while (s.nb > 3)
		split_b(&s, &t);
	s.nb > 0 ? put_n_order_3_last_of_b(&s, &t) : 1;
	if (s.i_step >= 0 && check_tri_ps(s.a, s.na) == 0)
	{
		s.tour++;
		quick_sort(s, t);
	}
	else
		r_to_tri(&s, &t);
	return (t);
}
