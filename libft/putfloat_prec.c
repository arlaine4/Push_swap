/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putfloat_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:13:25 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:13:25 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putfloat_prec(float f, unsigned int p)
{
	uintmax_t		n;
	unsigned int	i;
	unsigned int	pp;

	pp = p;
	f < 0 ? write(1, "-", 1) : 1;
	f < 0 ? (f = -f) : 1;
	n = (uintmax_t)f;
	f = f - n;
	ft_putnbr_lu((unsigned long long)n);
	p > 0 ? write(1, ".", 1) : 1;
	while (pp > 0)
	{
		f = f * 10;
		--pp;
	}
	n = (uintmax_t)f;
	i = number_of_digit_base_u((unsigned long long)n, 10);
	while (i < p)
	{
		write(1, "0", 1);
		i++;
	}
	n != 0 ? ft_putnbr_lu(n) : 1;
	n == 0 && p != 0 ? write(1, "0", 1) : 1;
}
