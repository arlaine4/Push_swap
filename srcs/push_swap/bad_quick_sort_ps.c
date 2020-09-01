/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_quick_sort_ps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:20:43 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:20:44 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_elem_a(int x, t_pil *s, char **t, int i)
{
	int		tmp;

	while (x > 0)
	{
		tmp = 1;
		push_a(s);
		*t = ft_strcat(*t, "pa\n");
		++i;
		while (s->a[0] > s->a[1])
		{
			swap_a(s);
			*t = ft_strcat(*t, "sa\n");
			while (s->a[0] < s->a[1] && ++tmp <= i)
			{
				rotate_a(s);
				*t = ft_strcat(*t, "ra\n");
			}
		}
		while (--tmp > 0)
		{
			reverse_rotate_a(s);
			*t = ft_strcat(*t, "rra\n");
		}
		--x;
	}
}

void	sort_elem_reverse_b(int x, t_pil *s, char **t, int i)
{
	int		tmp;

	while (x > 0)
	{
		tmp = 1;
		push_b(s);
		++i;
		*t = ft_strcat(*t, "pb\n");
		while (s->b[0] < s->b[1])
		{
			swap_b(s);
			*t = ft_strcat(*t, "sb\n");
			while (s->b[0] > s->b[1] && ++tmp <= i)
			{
				rotate_b(s);
				*t = ft_strcat(*t, "rb\n");
			}
		}
		while (--tmp > 0)
		{
			reverse_rotate_b(s);
			*t = ft_strcat(*t, "rrb\n");
		}
		--x;
	}
}

char	*bad_quick_sort(t_pil s)
{
	int		x;
	char	*t;

	if (!(t = ft_strnew(MID_SIZE)))
		return (NULL);
	separate_pil_a(&s, &t);
	while (s.nb > 3)
	{
		separate_pil_b(&s, &t);
	}
	t = ft_strcat(t, small_sort_reverse(&s));
	x = s.nb == 3 ? s.n / 2 - 3 : s.n / 2 - 2;
	sort_elem_reverse_b(x, &s, &t, 0);
	while (s.na > 3)
		separate_pil_a(&s, &t);
	t = ft_strcat(t, small_sort(&s));
	x = s.na == 3 ? s.n / 2 - 3 : s.n / 2 - 2;
	sort_elem_a(x, &s, &t, 0);
	while (s.nb > 0)
	{
		push_a(&s);
		t = ft_strcat(t, "pa\n");
	}
	return (t);
}
