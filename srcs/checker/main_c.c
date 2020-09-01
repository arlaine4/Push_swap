/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:19:54 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:19:54 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_t_checker(t_checker *s)
{
	int			i;

	i = 0;
	if (s->ins)
	{
		while (s->ins[i])
		{
			free(s->ins[i]);
			s->ins[i] = NULL;
			++i;
		}
		free(s->ins);
		s->ins = NULL;
	}
	if (s->a != NULL)
		free(s->a);
	s->a = NULL;
	s->n = 0;
	s->boo = 0;
	return (0);
}

static int	init_t_checker(t_checker *s)
{
	s->a = NULL;
	s->ins = NULL;
	s->n = 0;
	s->boo = 0;
	return (1);
}

static int	error_n_free_t_checker(t_checker *s)
{
	int			i;

	i = 0;
	write(2, "Error\n", 6);
	if (s->ins != NULL)
	{
		while (s->ins[i])
			ft_strdel(&s->ins[i++]);
		free(s->ins);
		s->ins = NULL;
	}
	if (s->a != NULL)
		free(s->a);
	s->a = NULL;
	s->n = 0;
	return (0);
}

int			main(int ac, char **av)
{
	t_checker	s;

	if (ac < 1 || init_t_checker(&s) == 0)
		return (error_n_free_t_checker(&s));
	if (ac == 1)
		return (free_t_checker(&s));
	if (parsing_c(&s, ac, av) == 0)
		return (error_n_free_t_checker(&s));
	if (ft_strcmp(av[1], "-v") != 0)
	{
		s.a = exec_instruc(&s);
		check_tri_c(s);
	}
	else if (s.n <= IMG_Y && s.n > 7)
		exec_visu(s);
	else
		ft_putendl("Check the number of elements");
	return (free_t_checker(&s));
}
