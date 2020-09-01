/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:14:36 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:14:37 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intchr(char const *s, char const *accept)
{
	int	i;
	int	j;

	i = 0;
	if (s && accept)
	{
		while (s[i] != '\0')
		{
			j = 0;
			while (accept[j] != '\0')
			{
				if (accept[j] == s[i])
					return (i);
				++j;
			}
			++i;
		}
	}
	return (-1);
}
