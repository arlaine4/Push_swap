/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:17:04 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:17:05 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*buf;

	buf = NULL;
	if (!(buf = (void *)malloc(size)))
		return (NULL);
	return (ft_memset(buf, 0, size));
}
