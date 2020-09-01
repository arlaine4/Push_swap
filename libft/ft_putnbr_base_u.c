/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:05:37 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:05:38 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_base_u(unsigned long nb, unsigned int base)
{
	char	*radix;

	if (base < 2 || base > 16)
		return ;
	radix = "0123456789abcdef";
	if (nb >= (unsigned long)base)
	{
		ft_putnbr_base(nb / (unsigned long)base, base);
		ft_putnbr_base(nb % (unsigned long)base, base);
	}
	else
		ft_putchar(radix[nb]);
}
