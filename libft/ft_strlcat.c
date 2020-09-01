/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:08:57 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:08:58 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	res;
	size_t	i;

	d_len = ft_strlen((char *)dest);
	s_len = ft_strlen((char *)src);
	i = 0;
	if (size < d_len + 1)
		res = s_len + size;
	else
	{
		res = s_len + d_len;
		ft_strncat(dest, src, size - ft_strlen(dest) - 1);
	}
	return (res);
}
