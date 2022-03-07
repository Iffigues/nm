/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:32:43 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/18 20:23:49 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_typemoi(long double a)
{
	return ((1.0 / a) == (-1.0 / 0.0));
}

void	ft_signe(t_gob opt, long double a)
{
	if (a < 0.0)
		ft_add(opt, '-');
	if (a == 0.0)
		if (ft_typemoi(a))
			ft_add(opt, '-');
}

void	ft_inf(t_gob opt, char *v, int a)
{
	a += (opt.opt.opt & 16) || (opt.opt.opt & 8);
	while (!(opt.opt.opt & 4) && ((int)opt.opt.largeur > a))
	{
		ft_add(opt, ' ');
		opt.opt.largeur--;
	}
	if ((*v == 'i') && (opt.opt.opt & 16))
		ft_add(opt, '+');
	else if ((*v == 'i') && (opt.opt.opt & 8))
		ft_add(opt, ' ');
	while (*v)
		ft_add(opt, *v++);
	while ((opt.opt.opt & 4) && ((int)opt.opt.largeur > a))
	{
		ft_add(opt, ' ');
		opt.opt.largeur--;
	}
}

int		ft_nan(long double a, t_gob opt)
{
	if (a != a)
	{
		ft_inf(opt, "NaN", 3);
		return (1);
	}
	if (a == (-1.0 / 0.0))
	{
		ft_inf(opt, "-inf", 4);
		return (1);
	}
	if (a == (1.0 / 0.0))
	{
		ft_inf(opt, "inf", 3);
		return (1);
	}
	return (0);
}
