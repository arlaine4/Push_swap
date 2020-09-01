/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:13:30 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 16:13:31 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putstrsub(char const *s, int start, size_t len)
{
	if (s[start])
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		write(1, s + start, len);
	}
}
