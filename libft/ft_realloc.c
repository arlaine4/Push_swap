/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:06:33 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:06:34 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char *str;

	if (size == 0)
	{
		str = ft_strdup((char *)ptr);
		free(ptr);
		return ((void *)str);
	}
	if (!(ptr = malloc(size)))
		if (!(str = (char *)malloc(sizeof(char) * size)))
			return (NULL);
	return (NULL);
}
