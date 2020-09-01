/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyhamrou <lyhamrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:15:51 by lyhamrou          #+#    #+#             */
/*   Updated: 2018/11/17 19:07:59 by lyhamrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = NULL;
	if (!(link = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		if (!(link->content = (void *)malloc(content_size)))
		{
			free(link);
			return (NULL);
		}
		link->content = ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
