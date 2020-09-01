/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:04:54 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:04:55 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		lim_of_neg(int n)
{
	ft_putchar('-');
	ft_putchar('2');
	n = n % 1000000000;
	return (n);
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
		n = -lim_of_neg(n);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
