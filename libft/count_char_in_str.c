/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:12:49 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:12:51 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_char_in_str(char c, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (c && str)
	{
		while (str[i])
		{
			if (str[i] == c)
				++count;
			++i;
		}
	}
	return (count);
}
