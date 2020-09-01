/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:10:36 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:10:39 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *rev)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(rev) - 1;
	while (i < j)
	{
		tmp = rev[i];
		rev[i++] = rev[j];
		rev[j--] = tmp;
	}
	return (rev);
}
