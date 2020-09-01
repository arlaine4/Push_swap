/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:19:42 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:19:43 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function check if there is duplicate integer
*/

static int	check_args(t_checker s)
{
	int		i;
	int		j;

	i = 0;
	while (i < s.n - 1)
	{
		j = i + 1;
		while (j < s.n)
		{
			if (s.a[i] == s.a[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

/*
**	This function parse instructions of standard input for checker
*/

static int	pars_stdin(t_checker *s)
{
	char	*buf;
	char	*tmp;

	buf = NULL;
	if (!(tmp = ft_strnew(0)))
		return (0);
	while (get_next_line(STDIN, &buf) > 0)
	{
		if (checker_instructions(buf) == 0
				|| (tmp = ft_strjoinfree(tmp, buf, 3)) == NULL)
		{
			ft_strdel(&tmp);
			return (0);
		}
	}
	if ((s->ins = ft_strsplit(tmp, '\n')) == NULL)
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

/*
**	This function pars integer list with only one sting in argument
*/

static int	parstr_c(t_checker *s, char *a)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s->a = (int *)ft_memalloc(number_of_number_in_str(a) * sizeof(int))))
		return (0);
	while (a[j])
	{
		while (a[j] == ' ' || a[j] == '\t')
			++j;
		if ((a[j] == '-' || a[j] == '+') && (a[j + 1] < '0' || a[j + 1] > '9'))
			return (0);
		if (ft_atol(&a[j]) != (long long)ft_atoi(&a[j]))
			return (0);
		s->a[i++] = a[j] != '\0' ? ft_atoi(&a[j]) : s->n--;
		while (((a[j] >= '0' && a[j] <= '9') || a[j] == '-' || a[j] == '+')
				&& a[j])
			++j;
		s->n++;
	}
	return (s->n < 1 ? 0 : 1);
}

/*
**	This function pars integer list
*/

static int	pars_nbr_c(t_checker *s, int ac, char **a)
{
	int		i;
	int		j;

	i = 1;
	if (!(s->a = (int *)ft_memalloc(sizeof(int) * ac)))
		return (0);
	ft_strcmp(a[1], "-v") == 0 ? ++i : 1;
	while (i < ac)
	{
		j = 0;
		if (ft_atol(a[i]) != (long long)ft_atoi(a[i]))
			return (0);
		while (a[i][j] == ' ' || a[i][j] == '\t')
			j++;
		if (a[i][j] != '-' && a[i][j] != '+'
				&& (a[i][j] < '0' || a[i][j] > '9'))
			return (0);
		if ((a[i][j] == '-' || a[i][j] == '+') && (a[i][j + 1] < '0'
					|| a[i][j + 1] > '9'))
			return (0);
		s->a[i - 1 - (ft_strcmp(a[1], "-v") == 0)] = ft_atoi(a[i]);
		s->n++;
		++i;
	}
	return (1);
}

/*
**	This function call all parsing functions and instructions
*/

int			parsing_c(t_checker *s, int ac, char **a)
{
	int		i;

	i = 0;
	if (ac == 2 && ft_strcmp(a[1], "-v") == 0)
		return (0);
	if (ac == 2 || (ac == 3 && ft_strcmp(a[1], "-v") == 0))
	{
		i = ft_strcmp(a[1], "-v") != 0 ? parstr_c(s, a[1]) : parstr_c(s, a[2]);
		if (i == 0)
			return (0);
	}
	if (i == 0 && pars_nbr_c(s, ac, a) == 0)
		return (0);
	if (check_args(*s) == 0)
		return (0);
	if (pars_stdin(s) == 0)
		return (0);
	return (1);
}
