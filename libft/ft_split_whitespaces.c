/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:06:45 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:06:45 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		c_l(char *str)
{
	int			i;

	i = 0;
	while (str[i] > ' ')
		i++;
	return (i + 1);
}

static int		c_w(char *str)
{
	int			i;
	int			words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		while (str[i] > ' ')
			i++;
		if (str[i - 1] == ' ' || str[i] == '\0')
			words++;
	}
	return (words + 1);
}

char			**ft_split_whitespaces(char *str)
{
	int			i;
	int			j;
	int			x;
	char		**words;

	i = 0;
	x = 0;
	if (!(words = (char **)malloc(sizeof(char) * c_w(str))))
		return (NULL);
	while (str[x])
	{
		j = 0;
		while (str[x] == ' ')
			x++;
		if (str[x])
		{
			if (!(words[i] = (char *)malloc(sizeof(char) * c_l(&str[x]))))
				return (NULL);
			while (str[x] > ' ')
				words[i][j++] = str[x++];
			words[i++][j] = '\0';
		}
	}
	words[i] = NULL;
	return (words);
}
