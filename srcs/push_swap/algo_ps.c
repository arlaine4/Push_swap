/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:20:31 by arlaine           #+#    #+#             */
/*   Updated: 2019/06/17 15:20:32 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*find_best_algo(t_pil s)
{
	char	*t;

	if (s.n < 4)
		t = algo_small_sort(&s);
	else if (s.n < 7)
		t = bad_quick_sort(s);
	else
		t = quick_sort(s, NULL);
	return (t);
}
