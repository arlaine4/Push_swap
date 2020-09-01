/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:09:50 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:09:51 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char const *str, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = NULL;
	if ((size_t)ft_strlen(str) < n)
	{
		if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
			return (NULL);
	}
	else
	{
		if (!(dest = (char *)malloc(sizeof(char) * n + 1)))
			return (NULL);
	}
	while (str[i] && i < n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
