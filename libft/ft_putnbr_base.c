/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:05:16 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:05:17 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		limit_long(long nb)
{
	ft_putstr("-9");
	nb = nb % 1000000000000000000;
	return (nb);
}

void			ft_putnbr_base(long nb, unsigned int base)
{
	char	*radix;

	if (base < 2 || base > 16)
		return ;
	radix = "0123456789abcdef";
	if (nb == LONG_MIN)
		nb = -limit_long(nb);
	if (nb < 0 && base == 10)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= (long)base)
	{
		ft_putnbr_base(nb / (long)base, base);
		ft_putnbr_base(nb % (long)base, base);
	}
	else
		ft_putchar(radix[nb]);
}
