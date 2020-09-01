/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:16:31 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:16:32 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		howmany_num(long n, unsigned int base)
{
	long			i;

	i = 1;
	if (base < 2 || base > 16)
		return (0);
	if (n == -2147483648)
		return (11);
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

char			*ft_ltoa_base_maj(long n, unsigned int base)
{
	char		*ltoa;
	char		*radix;
	long		pow;
	long		nb;

	nb = n;
	radix = "0123456789ABCDEF";
	pow = howmany_num(n, base);
	if (!(ltoa = (char *)malloc(sizeof(char) * (unsigned long)pow + 1)))
		return (NULL);
	ltoa[pow--] = '\0';
	if (nb < 0 && base < 10)
	{
		ltoa[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		*ltoa = '0';
	while (nb > 0)
	{
		ltoa[pow--] = radix[(nb % base)];
		nb = nb / base;
	}
	return (ltoa);
}
