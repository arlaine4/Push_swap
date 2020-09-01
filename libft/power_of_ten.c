/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_of_ten.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:13:18 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:13:19 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This fuction gives the power of ten the closest to n
** Exemple :	if n = 123,   pow = 100;
**				if n = -1234, pow = 1000;
*/

long		power_of_ten(long n)
{
	long	pow;
	size_t	i;

	i = 0;
	pow = 10;
	n < 0 ? n = -n : 1;
	if (n < 10)
		return (1);
	while (n / pow >= 10)
		pow *= 10;
	return (pow);
}
