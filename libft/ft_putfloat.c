/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:04:44 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:04:45 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(float nb)
{
	long	n;
	long	digit;
	float	decimal;

	digit = 0;
	ft_putnbr_l((n = (long)nb));
	decimal = nb - n;
	write(1, ".", 1);
	n = 0;
	while (digit < 7)
	{
		decimal = 10 * decimal;
		++digit;
	}
	digit = 1000000;
	n = (long)decimal;
	while (n / digit == 0)
	{
		digit /= 10;
		write(1, "0", 1);
	}
	(n % 10) - 5 < 0 ? ft_putnbr_l(n / 10) : ft_putnbr_l((n / 10) + 1);
}
