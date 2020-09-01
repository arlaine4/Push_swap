/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_n_char_at_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:10:10 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:10:11 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function place n characters c at the pos position of str
** Exemple : add_n_char_at_pos('0', "123456", 2, 0) --> 00123456
** The function return NULL if pos is higer than the size of str and if str or
** c are null.
*/

char	*add_n_char_at_pos(char c, char *str, size_t n, size_t pos)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	if (n == 0)
		return (str);
	if (pos > ft_strlen(str))
		pos = ft_strlen(str);
	if (!(new = ft_memalloc(n + ft_strlen(str) + 1)))
	{
		free(str);
		return (NULL);
	}
	while (i < pos)
		new[j++] = str[i++];
	while (n--)
		new[j++] = c;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}
