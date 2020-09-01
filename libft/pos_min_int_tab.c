/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_min_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:13:12 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:13:13 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function can give u the index of the minimum value of an integer array
*/

int		pos_min_int_tab(int *tab, unsigned int size)
{
	int		i;
	int		pos;
	int		min;

	i = 1;
	pos = 0;
	if (tab == NULL || size == 0)
		return (-1);
	min = tab[i - 1];
	while (i < (int)size)
	{
		if (min > tab[i])
		{
			min = tab[i];
			pos = i;
		}
		++i;
	}
	return (pos);
}
