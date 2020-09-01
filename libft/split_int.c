/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:13:42 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:13:43 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This functions can transforme a char * to int *
**	Exemple str =	"     +10 5	44 01 -4"
**			return	{10,5,44,1,-1}
**	If you have an invalid char like "- 2" ou "a" return NULL
*/

int		*split_int(char *s)
{
	int		i;
	int		j;
	int		*tab;

	i = 0;
	j = 0;
	tab = NULL;
	if (!(tab = (int *)ft_memalloc(sizeof(int) * number_of_number_in_str(s))))
		return (NULL);
	while (i < number_of_number_in_str(s))
	{
		while (s[j] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
			++j;
		if ((s[j] != '-' && s[j] != '+' && (s[j] < '0' || s[j] > '9'))
				|| ((s[j] == '-' || s[j] == '+')
					&& (s[j + 1] < '0' || s[j + 1] > '9')))
		{
			free(tab);
			return (NULL);
		}
		tab[i++] = ft_atoi(&s[j]);
		while ((s[j] >= '0' && s[j] <= '9') || s[j] == '-' || s[j] == '+')
			++j;
	}
	return (tab);
}
