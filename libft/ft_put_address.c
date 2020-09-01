/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:04:06 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:04:07 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** to get adress of a variable
*/

void	ft_put_address(unsigned long nb, unsigned int base, int i)
{
	char			*radix;

	radix = "0123456789abcdef";
	if (base != 16)
		return ;
	if (i == 1)
		ft_putstr("0x");
	if (nb >= base)
	{
		ft_put_address(nb / base, base, 0);
		ft_put_address(nb % base, base, 0);
	}
	else
		ft_putchar(radix[nb]);
}
