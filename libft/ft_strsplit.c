/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:10:46 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:10:47 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	words(char const *s, char c)
{
	int			i;
	int			cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c)
			cpt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cpt);
}

static unsigned long	letter(char const *s, int start, char c)
{
	int			i;

	i = 0;
	while (s[start] != c && s[start])
	{
		start++;
		i++;
	}
	return (i);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**wds;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	if (!s || !c || !(wds = (char **)malloc(sizeof(char *) * words(s, c) + 1)))
		return (NULL);
	while (s[x])
	{
		while (s[x] == c && s[x])
			x++;
		if (s[x])
		{
			if (!(wds[i] = ft_strsub(s, x, letter(s, x, c))))
				return (NULL);
			while (s[x] != c && s[x])
				x++;
			i++;
		}
	}
	wds[i] = NULL;
	return (wds);
}
