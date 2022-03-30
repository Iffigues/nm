/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:20:48 by bordenoy          #+#    #+#             */
/*   Updated: 2022/03/30 18:27:07 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	trie(t_tab *e)
{
	unsigned long	h;
	unsigned long	j;
	unsigned long	k;

	h = getsize(e);
	k = 0;
	while (k < (h - 1))
	{
		j = 0;
		while (j < (h - 1 - k))
		{
			swap(e, j);
			j++;
		}
		k++;
	}
}
