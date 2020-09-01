/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:20:37 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:20:59 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Check if there is duplicate integer
*/

static int	check_args(t_pil *s)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->n - 1)
	{
		j = i + 1;
		while (j < s->na)
		{
			if (s->a[i] == s->a[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
**	Parsing of string containing intger
*/

int			parsing_str_ps(t_pil *s, char *a)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s->a = (int *)ft_memalloc(number_of_number_in_str(a) * sizeof(int))))
		return (0);
	while (a[i])
	{
		while (a[i] == ' ' || a[i] == '\t')
			++i;
		if (a[i] == '\0')
			break ;
		if ((a[i] == '-' || a[i] == '+') && (a[i + 1] < '0' || a[i + 1] > '9'))
			return (0);
		if ((a[i] != '-' && a[i] != '+' && (a[i] < '0' || a[i] > '9'))
				|| ft_atol(&a[i]) != (long long)ft_atoi(&a[i]))
			return (0);
		s->a[j] = ft_atoi(&a[i]);
		s->n++;
		i = i + (int)number_of_digit(ft_atoi(&a[i]));
		++j;
	}
	s->na = s->n;
	return (1);
}

/*
**	Parsing of integer
*/

int			parsing_not_str_ps(t_pil *s, int ac, char **av, int i)
{
	int		j;

	if (!(s->a = (int *)ft_memalloc(sizeof(int) * (ac))))
		return (0);
	while (i < ac)
	{
		j = 0;
		if (ft_atol(av[i]) != (long)ft_atoi(av[i]))
			return (0);
		while (av[i][j] < '0' || av[i][j] > '9')
		{
			if (av[i][j] != ' ' && av[i][j] != '-' && av[i][j] != '+')
				return (0);
			++j;
		}
		s->a[i - 1] = ft_atoi(av[i]);
		s->n++;
		i++;
	}
	s->na = s->n;
	return (1);
}

/*
**	All parsing functions
*/

int			parsing_ps(t_pil *s, int ac, char **av)
{
	if (ac == 2)
	{
		if (parsing_str_ps(s, av[1]) == 0)
			return (0);
	}
	else if (ac > 2)
	{
		if (parsing_not_str_ps(s, ac, av, 1) == 0)
			return (0);
	}
	if (check_args(s) == 0 || !(s->b = (int *)ft_memalloc(s->n * sizeof(int))))
		return (0);
	return (1);
}
