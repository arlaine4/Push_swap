/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:20:51 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:20:53 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_t_pil(t_pil *s)
{
	if (s->a != NULL)
	{
		free(s->a);
		s->a = NULL;
	}
	if (s->b != NULL)
	{
		free(s->b);
		s->b = NULL;
	}
	s->na = 0;
	s->nb = 0;
	s->n = 0;
	if (s->step != NULL)
	{
		free(s->step);
		s->step = NULL;
	}
	s->i_step = 0;
	return (0);
}

static int	error_n_free_t_pil(t_pil *s)
{
	if (s->a != NULL)
	{
		free(s->a);
		s->a = NULL;
	}
	if (s->b != NULL)
	{
		free(s->b);
		s->b = NULL;
	}
	if (s->step != NULL)
	{
		free(s->step);
		s->step = NULL;
	}
	s->na = 0;
	s->nb = 0;
	s->n = 0;
	ft_putendl("Error");
	return (0);
}

static void	init_val_t_pil(t_pil *s)
{
	s->na = 0;
	s->nb = 0;
	s->n = 0;
	s->a = NULL;
	s->b = NULL;
	s->ign = 0;
	s->tour = 0;
	s->i_step = 0;
	s->step = NULL;
}

static void	init_t_pil(t_pil *s, int boo)
{
	int		i;
	int		count;

	count = 0;
	if (boo == 1)
	{
		i = s->na;
		while (i > 0)
		{
			i /= 2;
			++count;
		}
		if (!(s->step = (int *)ft_memalloc((size_t)sizeof(int)
						* (size_t)count)))
			return ;
	}
	else
		init_val_t_pil(s);
}

int			main(int ac, char **av)
{
	t_pil	s;
	char	*operations;

	if (ac < 2)
		return (0);
	operations = NULL;
	init_t_pil(&s, 0);
	if (parsing_ps(&s, ac, av) == 0)
		return (error_n_free_t_pil(&s));
	if (s.n <= 1 || check_tri_ps(s.a, s.na) == 1)
		return (free_t_pil(&s));
	init_t_pil(&s, 1);
	if ((operations = find_best_algo(s)) == NULL)
		return (error_n_free_t_pil(&s));
	write(1, operations, ft_strlen(operations));
	if (operations != NULL)
		ft_strdel(&operations);
	else
		error_n_free_t_pil(&s);
	return (free_t_pil(&s));
}
