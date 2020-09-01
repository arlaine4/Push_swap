/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:12:20 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:12:21 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function gives the number of digit of the number
** Exemple :	n = 10,  i = 2;
**				n = -10, i = 3;
**				n = 0;   i = 1;
*/

size_t		number_of_digit(long n)
{
	size_t i;

	i = 0;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		++i;
	}
	return (i + 1);
}
