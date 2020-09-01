/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u_maj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:05:46 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:05:47 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_u_maj(unsigned long nb, unsigned int base)
{
	char *radix;

	if (base < 2 || base > 16)
		return ;
	radix = "0123456789ABCDEF";
	if (nb >= base)
	{
		ft_putnbr_base_u_maj(nb / base, base);
		ft_putnbr_base_u_maj(nb % base, base);
	}
	else
		ft_putchar(radix[nb]);
}
