/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:17:23 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:17:24 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *dest, void const *src, size_t n)
{
	unsigned char const *d;
	unsigned char const *s;

	d = dest;
	s = src;
	if (dest == src || n == 0)
		return (0);
	while (n > 0)
	{
		if (*d != *s)
			return (*d - *s);
		n--;
		d++;
		s++;
	}
	return (0);
}
