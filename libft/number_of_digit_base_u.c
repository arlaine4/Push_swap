/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_digit_base_u.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:12:38 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:12:39 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function gives the number of digit of the number
** Exemple :	n = 10,  i = 2;
**				n = -10, i = 3;
**				n = 0;   i = 1;
*/

size_t		number_of_digit_base_u(unsigned long n, unsigned int base)
{
	size_t i;

	i = 0;
	while (n >= base)
	{
		n = n / base;
		++i;
	}
	return (i + 1);
}
