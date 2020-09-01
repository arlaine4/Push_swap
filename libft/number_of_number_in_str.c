/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_number_in_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:12:53 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:12:54 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		This function count the number of numbers in a string but if the string
**		is false
**	(presence of a non numerique character or space between signe and nmber)
*/

int		number_of_number_in_str(char *tab)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (tab[i] != ' ')
		{
			if (tab[i] == '-' || tab[i] == '+')
				++i;
			if (tab[i] < '0' || tab[i] > '9')
				return (-1);
			while (tab[i] >= '0' && tab[i] <= '9')
				++i;
			++count;
		}
		else
			++i;
	}
	return (count);
}
