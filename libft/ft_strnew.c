/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:10:09 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:10:12 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (!(str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
