/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_max_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:13:05 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:13:06 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function can give u the index of the maximum value of an integer array
*/

int		pos_max_int_tab(int *tab, unsigned int size)
{
	int		i;
	int		pos;
	int		max;

	i = 1;
	pos = 0;
	if (tab == NULL || size == 0)
		return (-1);
	max = tab[i - 1];
	while (i < (int)size)
	{
		if (max < tab[i])
		{
			max = tab[i];
			pos = i;
		}
		++i;
	}
	return (pos);
}
