/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:39:21 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/13 15:09:39 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <stdio.h>

int	affiche(t_tab *c, int ii)
{
	int	i;

	i = 0;
	while (c[i].end == 0)
	{
		if (!ii)
		{
			if (c[i].t != 'v' && c[i].t != 'w' && c[i].t != 'U') {
				ft_printf("%08x %c", c[i].exa, c[i].t);
				ft_printf(" %s\n", c[i].name);
			}
			else {
				ft_printf("%8c %c", ' ', c[i].t);
				ft_printf(" %s\n", c[i].name);
			}
		}
		else
		{
			if (c[i].t != 'v' && c[i].t != 'w' && c[i].t != 'U') {
				ft_printf("%016lx %c", c[i].exa, c[i].t);
				ft_printf(" %s\n",c[i].name);
			}
			else {
				ft_printf("%16c %c", ' ', c[i].t);
				ft_printf(" %s\n", c[i].name);
			}
		}
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}
