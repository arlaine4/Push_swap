/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:15:22 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:15:23 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		howmany_num(int n)
{
	int			i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*itoa;
	int			pow;
	long		nb;

	nb = n;
	pow = howmany_num(n);
	if (!(itoa = (char *)malloc(sizeof(char) * (unsigned long)pow + 1)))
		return (NULL);
	itoa[pow--] = '\0';
	if (nb < 0)
	{
		itoa[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		*itoa = '0';
	while (nb > 0)
	{
		itoa[pow--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (itoa);
}
