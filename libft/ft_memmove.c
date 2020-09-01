/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:17:39 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:17:40 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, void const *src, size_t len)
{
	unsigned char	*src_uc;
	unsigned char	*dest_uc;
	size_t			i;

	i = 0;
	src_uc = (unsigned char *)src;
	dest_uc = (unsigned char *)dest;
	if (src_uc >= dest_uc)
	{
		while (i < len)
		{
			dest_uc[i] = src_uc[i];
			i++;
		}
	}
	while (i < len)
	{
		dest_uc[len - 1 - i] = src_uc[len - 1 - i];
		i++;
	}
	return (dest);
}
