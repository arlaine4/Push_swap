/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_int_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:12:12 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:12:14 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function can give u the minimum value of an integer array
*/

int		min_int_tab(int *tab, unsigned int size)
{
	int		i;
	int		min;

	i = 0;
	if (tab == NULL || size == 0)
		return (0);
	min = tab[i];
	while (i < (int)size - 1)
	{
		++i;
		if (min > tab[i])
			min = tab[i];
	}
	return (min);
}
