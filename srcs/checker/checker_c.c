/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:20:00 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:20:01 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	This function check if instructions are correct
*/

int		checker_instructions(char *t)
{
	if (t)
	{
		if (ft_strcmp(t, "sa\n") != 0 && ft_strcmp(t, "sb\n") != 0
		&& ft_strcmp(t, "ss\n") != 0 && ft_strcmp(t, "pa\n") != 0
		&& ft_strcmp(t, "pb\n") != 0 && ft_strcmp(t, "ra\n") != 0
		&& ft_strcmp(t, "rb\n") != 0 && ft_strcmp(t, "rr\n") != 0
		&& ft_strcmp(t, "rra\n") != 0 && ft_strcmp(t, "rrb\n") != 0
		&& ft_strcmp(t, "rrr\n"))
			return (0);
	}
	return (1);
}

/*
**	This function check if integers are sorted
*/

void	check_tri_c(t_checker s)
{
	int		i;

	i = 0;
	if (s.boo == 1)
	{
		ft_putendl("KO");
		return ;
	}
	while (i < s.n - 1)
	{
		if (s.a[i] > s.a[i + 1])
		{
			ft_putendl("KO");
			return ;
		}
		++i;
	}
	ft_putendl("OK");
}
