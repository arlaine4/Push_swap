/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tri_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:13:18 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:13:19 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	croissant(int *tab, int size)
{
	int		i;

	i = 0;
	if (size >= 2)
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
				return (0);
			++i;
		}
	}
	return (1);
}

int			check_tri_tab(int *tab, int size)
{
	int		i;
	int		pos;

	i = 0;
	if (size == 0)
		return (0);
	pos = pos_min_int_tab(tab, size);
	if (croissant(tab, pos) == 0 || croissant(&tab[pos], size - pos) == 0)
		return (0);
	if (pos != 0 && tab[size - 1] > tab[0])
		return (0);
	return (1);
}
