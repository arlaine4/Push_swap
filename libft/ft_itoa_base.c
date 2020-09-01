/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:15:29 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:15:32 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		howmany_num(int n, unsigned int base)
{
	int			i;

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
	while (n > (int)base - 1)
	{
		n = n / (int)base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int n, unsigned int base)
{
	char		*itoa;
	char		*radix;
	int			pow;
	long		nb;

	nb = n;
	radix = "0123456789abcdef";
	pow = howmany_num(n, base);
	if (!(itoa = (char *)malloc(sizeof(char) * (unsigned long)pow + 1)))
		return (NULL);
	itoa[pow--] = '\0';
	if (nb < 0 && base < 10)
	{
		itoa[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		*itoa = '0';
	while (nb > 0)
	{
		itoa[pow--] = radix[(nb % base)];
		nb = nb / base;
	}
	return (itoa);
}
