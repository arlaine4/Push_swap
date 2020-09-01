/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:16:21 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:16:22 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		howmany_num(long n, unsigned int base)
{
	long		i;

	i = 1;
	if (base < 2 || base > 16)
		return (0);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > (long)base - 1)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_ltoa_base(long n, unsigned int base)
{
	char		*ltoa;
	char		*radix;
	long		pow;

	radix = "0123456789abcdef";
	pow = howmany_num(n, base);
	if (!(ltoa = (char *)malloc(sizeof(char) * (unsigned long)pow + 1)))
		return (NULL);
	ltoa[pow--] = '\0';
	if (n < 0 && base <= 10)
	{
		ltoa[0] = '-';
		n = -n;
	}
	if (n == 0)
		*ltoa = '0';
	while (n > 0)
	{
		ltoa[pow--] = radix[(n % base)];
		n = n / base;
	}
	return (ltoa);
}
