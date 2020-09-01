/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tri_tab_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:13:26 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:13:28 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	decroissant(int *tab, int size)
{
	int		i;

	i = 0;
	if (size >= 2)
	{
		while (i < size - 1)
		{
			if (tab[i] < tab[i + 1])
				return (0);
			++i;
		}
	}
	return (1);
}

int			check_tri_tab_reverse(int *tab, int size)
{
	int		i;
	int		pos;

	i = 0;
	if (size == 0)
		return (0);
	pos = pos_max_int_tab(tab, size);
	if (decroissant(tab, pos) == 0 || decroissant(&tab[pos], size - pos) == 0)
		return (0);
	if (pos != 0 && tab[size - 1] < tab[0])
		return (0);
	return (1);
}
