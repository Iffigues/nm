/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:46:03 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/03 19:36:45 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	aff_rest(long long a, t_gob opt)
{
	int	i;

	i = 0;
	if (a == 0)
		i = 1;
	a /= 10;
	while (a)
	{
		a /= 10;
		i++;
	}
	while (i < opt.opt.precision)
	{
		i++;
		ft_add(opt, '0');
	}
}

t_gob	ft_ar(t_gob opt, unsigned long long b)
{
	if (opt.opt.opt & 4 && b == 0)
	{
		if (opt.opt.conversion != 'o' && opt.opt.opt & 2)
			opt.opt.opt = opt.opt.opt ^ 2;
		if (opt.opt.conversion == 'o' && opt.opt.opt & 2 && !opt.opt.precision)
			opt.opt.largeur++;
	}
	return (opt);
}
