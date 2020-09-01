/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:39:44 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/10 19:07:29 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pil *s)
{
	int		tmp;

	if (s->na > 1)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
	}
}

void	swap_b(t_pil *s)
{
	int		tmp;

	if (s->nb > 1)
	{
		tmp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = tmp;
	}
}

void	rotate_a(t_pil *s)
{
	int		i;
	int		tmp;

	i = 0;
	if (s->na > 1)
	{
		tmp = s->a[0];
		while (i < s->na - 1)
		{
			s->a[i] = s->a[i + 1];
			++i;
		}
		s->a[s->na - 1] = tmp;
	}
}

void	rotate_b(t_pil *s)
{
	int		i;
	int		tmp;

	i = 0;
	if (s->nb > 1)
	{
		tmp = s->b[0];
		while (i < s->nb - 1)
		{
			s->b[i] = s->b[i + 1];
			++i;
		}
		s->b[s->nb - 1] = tmp;
	}
}

void	reverse_rotate_a(t_pil *s)
{
	int		tmp;
	int		i;

	if (s->na > 1)
	{
		i = s->na - 1;
		tmp = s->a[s->na - 1];
		while (i > 0)
		{
			s->a[i] = s->a[i - 1];
			--i;
		}
		s->a[0] = tmp;
	}
}
