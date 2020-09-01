/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:21:19 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:21:20 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Sort 3 elements on A
*/

char	*for_3(t_pil *s)
{
	if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[0] > s->a[2])
	{
		rotate_a(s);
		return ("ra\n");
	}
	else if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[0] < s->a[2])
	{
		swap_a(s);
		return ("sa\n");
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] < s->a[2])
	{
		reverse_rotate_a(s);
		swap_a(s);
		return ("rra\nsa\n");
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] > s->a[2])
	{
		reverse_rotate_a(s);
		return ("rra\n");
	}
	return ("");
}

char	*small_sort(t_pil *s)
{
	if (s->na == 2 && s->a[0] > s->a[1])
	{
		swap_a(s);
		return ("sa\n");
	}
	else if (s->na == 3)
	{
		if (s->a[0] > s->a[1] && s->a[1] > s->a[2] && s->a[0] > s->a[2])
		{
			swap_a(s);
			reverse_rotate_a(s);
			return ("sa\nrra\n");
		}
		else
			return (for_3(s));
	}
	return ("");
}

/*
**	Sort 3 elements on B
*/

char	*for_3_reverse(t_pil *s)
{
	if (s->b[0] > s->b[1] && s->b[1] < s->b[2] && s->b[0] > s->b[2])
	{
		reverse_rotate_b(s);
		swap_b(s);
		return ("rrb\nsb\n");
	}
	else if (s->b[0] > s->b[1] && s->b[1] < s->b[2] && s->b[0] < s->b[2])
	{
		reverse_rotate_b(s);
		return ("rrb\n");
	}
	else if (s->b[0] < s->b[1] && s->b[1] > s->b[2] && s->b[0] < s->b[2])
	{
		rotate_b(s);
		return ("rb\n");
	}
	else if (s->b[0] < s->b[1] && s->b[1] > s->b[2] && s->b[0] > s->b[2])
	{
		swap_b(s);
		return ("sb\n");
	}
	return ("");
}

char	*small_sort_reverse(t_pil *s)
{
	if (s->nb == 2 && s->b[0] < s->b[1])
	{
		swap_b(s);
		return ("sb\n");
	}
	else if (s->nb == 3)
	{
		if (s->b[0] < s->b[1] && s->b[1] < s->b[2] && s->b[0] < s->b[2])
		{
			swap_b(s);
			reverse_rotate_b(s);
			return ("sb\nrrb\n");
		}
		else
			return (for_3_reverse(s));
	}
	return ("");
}
