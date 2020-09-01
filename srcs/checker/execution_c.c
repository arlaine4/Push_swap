/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:19:48 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:19:49 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*free_t_pil_n_return(t_pil *pil, t_checker *s)
{
	ft_memcpy(s->a, pil->a, sizeof(int) * s->n);
	free(pil->a);
	pil->a = NULL;
	free(pil->b);
	pil->b = NULL;
	pil->na = 0;
	pil->nb = 0;
	pil->n = 0;
	pil->step == NULL ? 1 : free(pil->step);
	pil->step = NULL;
	return (s->a);
}

/*
**	This function initialize t_val to execut instructions
*/

void		init_for_exec(t_pil *pil, t_checker s)
{
	int		i;

	i = 0;
	if (!(pil->a = (int *)ft_memalloc(s.n * sizeof(int))))
		return ;
	while (i < s.n)
	{
		pil->a[i] = s.a[i];
		++i;
	}
	pil->n = s.n;
	pil->na = s.n;
	pil->nb = 0;
	pil->step = NULL;
	pil->i_step = 0;
	if (!(pil->b = (int *)ft_memalloc(s.n * sizeof(int))))
		return ;
}

static void	do_operations(t_checker *s, t_pil *t, int i)
{
	if (s->ins[i][0] == 'p')
	{
		if (s->ins[i][1] == 'a')
			push_a(t);
		else if (s->ins[i][1] == 'b')
			push_b(t);
	}
	else if (s->ins[i][0] == 'r')
	{
		if (s->ins[i][1] == 'a' || (s->ins[i][1] == 'r'
					&& ft_strlen(s->ins[i]) == 2))
			rotate_a(t);
		else if (s->ins[i][1] == 'b' || (s->ins[i][1] == 'r'
					&& ft_strlen(s->ins[i]) == 2))
			rotate_b(t);
		else if (s->ins[i][2] == 'a' || s->ins[i][2] == 'r')
			reverse_rotate_a(t);
		else if (s->ins[i][2] == 'b' || s->ins[i][2] == 'r')
			reverse_rotate_b(t);
	}
}

/*
**	This function execute instructions on t
*/

int			*exec_instruc(t_checker *s)
{
	int		i;
	t_pil	t;

	i = 0;
	init_for_exec(&t, *s);
	while (s->ins[i])
	{
		if (s->ins[i][0] == 's')
		{
			if (s->ins[i][1] == 'a' || s->ins[i][1] == 's')
				swap_a(&t);
			if (s->ins[i][1] == 'b' || s->ins[i][1] == 's')
				swap_b(&t);
		}
		else
			do_operations(s, &t, i);
		++i;
	}
	t.n != t.na ? s->boo = 1 : 1;
	return (free_t_pil_n_return(&t, s));
}
