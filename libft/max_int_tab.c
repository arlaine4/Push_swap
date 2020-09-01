/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_int_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:12:04 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:12:05 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this function can give u the maximum value of an integer array
*/

int		max_int_tab(int *tab, unsigned int size)
{
	int		i;
	int		max;

	i = 0;
	if (tab == NULL || size == 0)
		return (0);
	max = tab[i];
	while (i < (int)size - 1)
	{
		++i;
		if (max < tab[i])
			max = tab[i];
	}
	return (max);
}
