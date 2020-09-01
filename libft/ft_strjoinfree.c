/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:08:49 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:08:50 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function work like strjoin but
**	if d_s == 0 nothing is freed
**	if d_s == 1, dest is freed
**	if d_s == 2, src is freed
**	if d_s == 3, src and dest is freed,
*/

char		*ft_strjoinfree(char *d, char *s, int d_s)
{
	char	*str;

	str = ft_strjoin(d, s);
	if (str == NULL)
		return (NULL);
	if (d_s == 1 || d_s == 3)
		ft_strdel(&d);
	if (d_s == 2 || d_s == 3)
		ft_strdel(&s);
	return (str);
}
