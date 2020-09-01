/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:07:54 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:07:55 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char const *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (str)
	{
		if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
			return (NULL);
		while (str[i])
		{
			dest[i] = str[i];
			++i;
		}
		dest[i] = '\0';
	}
	return (dest);
}
