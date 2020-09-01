/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:16:09 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:16:15 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	neg(long *n, char **ltoa, unsigned int i)
{
	*ltoa[0] = '-';
	*n = -(*n);
	return (i + 1);
}

char				*ltoa(long n)
{
	unsigned int	i;
	unsigned int	digit;
	long			pow;
	char			*ltoa;

	i = 0;
	pow = power_of_ten(n);
	digit = number_of_digit(n);
	if (!(ltoa = (char *)malloc(4 * digit + 1)))
		return (NULL);
	n < 0 ? (i = neg(&n, &ltoa, i)) : 1;
	while (n > 0 || digit--)
	{
		if (pow != 0)
		{
			ltoa[i++] = n / pow + '0';
			n = n - ((n / pow) * pow);
		}
		pow /= 10;
	}
	ltoa[i] = '\0';
	return (ltoa);
}
