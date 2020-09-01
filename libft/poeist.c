/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poeist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:12:59 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:13:00 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Pos of element if sort tab
**	This function return the index of the integer in parameter in the tab sorted
**	If an error occured (integer not found in the tab) the function return -1
*/

int		poeist(int x, int *tab, int size)
{
	int		i;
	int		check;
	int		less;

	i = 0;
	check = 0;
	less = 0;
	while (i < size)
	{
		if (tab[i] == x)
			check = 1;
		else if (tab[i] < x)
			++less;
		++i;
	}
	return (check == 1 ? less : -1);
}
