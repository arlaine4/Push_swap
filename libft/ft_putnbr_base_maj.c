/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:05:27 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:05:28 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_maj(long nb, unsigned int base)
{
	char *radix;

	if (base < 2 || base > 16)
		return ;
	radix = "0123456789ABCDEF";
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base)
	{
		ft_putnbr_base_maj(nb / base, base);
		ft_putnbr_base_maj(nb % base, base);
	}
	else
		ft_putchar(radix[nb]);
}
