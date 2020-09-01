/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:55:09 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/10 19:08:43 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_tri_ps(int *s, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (s[i] >= s[i + 1])
			return (0);
		++i;
	}
	return (1);
}

void	push_a(t_pil *s)
{
	if (s->nb > 0)
	{
		s->na++;
		reverse_rotate_a(s);
		s->a[0] = s->b[0];
		rotate_b(s);
		s->nb--;
	}
}

void	push_b(t_pil *s)
{
	int		tmp;

	tmp = s->a[0];
	if (s->na > 0)
	{
		s->nb++;
		if (s->nb > 0)
			reverse_rotate_b(s);
		s->b[0] = tmp;
		rotate_a(s);
		s->na--;
	}
}

void	reverse_rotate_b(t_pil *s)
{
	int		tmp;
	int		i;

	tmp = s->b[s->nb - 1];
	if (s->nb > 1)
	{
		i = s->nb - 1;
		while (i > 0)
		{
			s->b[i] = s->b[i - 1];
			--i;
		}
		s->b[0] = tmp;
	}
}
