/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:06:56 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:06:57 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char const *src)
{
	int		i;
	int		len_d;

	i = 0;
	len_d = ft_strlen(dest);
	if (src == NULL)
		return (dest);
	while (src[i])
	{
		dest[i + len_d] = src[i];
		++i;
	}
	dest[i + len_d] = '\0';
	return (dest);
}
