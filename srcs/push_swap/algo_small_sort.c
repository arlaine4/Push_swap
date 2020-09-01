/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:20:36 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:20:37 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Sort 3 elements on A
*/

static void	for_3(t_pil *s, char **t)
{
	if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[0] > s->a[2])
	{
		rotate_a(s);
		*t = ft_strcpy(*t, "ra\n");
	}
	else if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[0] < s->a[2])
	{
		swap_a(s);
		*t = ft_strcpy(*t, "sa\n");
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] < s->a[2])
	{
		reverse_rotate_a(s);
		swap_a(s);
		*t = ft_strcpy(*t, "rra\nsa\n");
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] > s->a[2])
	{
		reverse_rotate_a(s);
		*t = ft_strcpy(*t, "rra\n");
	}
}

char		*algo_small_sort(t_pil *s)
{
	char	*t;

	t = NULL;
	if (!(t = (char *)ft_memalloc(LIL_SIZE)))
		return (NULL);
	if (s->na == 2 && s->a[0] > s->a[1])
	{
		swap_a(s);
		t = ft_strcpy(t, "sa\n");
	}
	else if (s->na == 3)
	{
		if (s->a[0] > s->a[1] && s->a[1] > s->a[2] && s->a[0] > s->a[2])
		{
			swap_a(s);
			reverse_rotate_a(s);
			t = ft_strcpy(t, "sa\nrra\n");
		}
		else
			for_3(s, &t);
	}
	return (t);
}

/*
**	Sort 3 elements on B
*/

static void	for_3_reverse(t_pil *s, char **t)
{
	if (s->b[0] > s->b[1] && s->b[1] < s->b[2] && s->b[0] > s->b[2])
	{
		reverse_rotate_b(s);
		swap_b(s);
		*t = ft_strcpy(*t, "rrb\nsb\n");
	}
	else if (s->b[0] > s->b[1] && s->b[1] < s->b[2] && s->b[0] < s->b[2])
	{
		reverse_rotate_b(s);
		*t = ft_strcpy(*t, "rrb\n");
	}
	else if (s->b[0] < s->b[1] && s->b[1] > s->b[2] && s->b[0] < s->b[2])
	{
		rotate_b(s);
		*t = ft_strcpy(*t, "rb\n");
	}
	else if (s->b[0] < s->b[1] && s->b[1] > s->b[2] && s->b[0] > s->b[2])
	{
		swap_b(s);
		*t = ft_strcpy(*t, "sb\n");
	}
}

char		*algo_small_sort_reverse(t_pil *s)
{
	char	*t;

	t = NULL;
	if (!(t = (char *)ft_memalloc(LIL_SIZE)))
		return (NULL);
	if (s->nb == 2 && s->b[0] < s->b[1])
	{
		swap_b(s);
		t = ft_strcpy(t, "sb\n");
	}
	else if (s->nb == 3)
	{
		if (s->b[0] < s->b[1] && s->b[1] < s->b[2] && s->b[0] < s->b[2])
		{
			swap_b(s);
			reverse_rotate_b(s);
			t = ft_strcpy(t, "sb\nrrb\n");
		}
		else
			for_3_reverse(s, &t);
	}
	return (t);
}
