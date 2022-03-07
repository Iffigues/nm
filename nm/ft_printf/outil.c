/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:12:17 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/21 18:10:54 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hexa(t_gob opt, char c, int g, int a)
{
	if ((c == 'x' && (opt.opt.opt & 2)) || c == 'p')
	{
		if (g && a)
		{
			ft_add(opt, '0');
			ft_add(opt, 'x');
		}
		return (2);
	}
	if (c == 'X' && (opt.opt.opt & 2))
	{
		if (g && a)
		{
			ft_add(opt, '0');
			ft_add(opt, 'X');
		}
		return (2);
	}
	if (c == 'o' && (opt.opt.opt & 2))
	{
		if ((g || opt.opt.precision == 0) && a)
			ft_add(opt, '0');
		return (1);
	}
	return (0);
}

int		or(int a, int b, int g, t_gob opt)
{
	if ((b & 16) && (g > 0) && (opt.opt.precision > 0))
		a = 0;
	return (a);
}

int		signe(t_gob opt, int b, int c)
{
	if (c == -1)
		return (0);
	if (opt.opt.opt & 16 && b >= 0)
	{
		if (c)
			ft_add(opt, '+');
		if (opt.opt.precision > -1)
			return (0);
		return (0);
	}
	if (b < 0)
	{
		if (c)
			ft_add(opt, '-');
		return (1);
	}
	return (0);
}

void	affre(t_gob opt, int a, int b)
{
	char		pp;

	pp = opts(opt, b);
	if (b >= 0 && ((opt.opt.opt & 8) || (opt.opt.opt & 16)))
		opt.opt.largeur--;
	if ((opt.opt.opt & 1) && opt.opt.precision > 0 && opt.opt.precision != 'c')
		opt.opt.opt = opt.opt.opt ^ 1;
	if (opt.opt.conversion != 'o')
		opt.opt.largeur -= hexa(opt, opt.opt.conversion, opt.opt.opt & 2, 0);
	if (opt.opt.conversion == 'o' && opt.opt.opt & 2 && opt.opt.precision < 0)
		opt.opt.largeur--;
	if (opt.opt.opt & 1)
		hexa(opt, opt.opt.conversion, opt.opt.opt & 2, 1);
	opt.opt.largeur -= signe(opt, b, 0);
	if ((opt.opt.opt & 1) && !(opt.opt.opt & 4))
		signe(opt, b, 1);
	opt.opt.largeur = largeur(opt, a, b, pp);
	if (!(opt.opt.opt & 1))
		opt.opt.largeur -= hexa(opt, opt.opt.conversion, opt.opt.opt & 2, 1);
	if (((opt.opt.opt & 4) || !(opt.opt.opt & 1)))
		signe(opt, b, 1);
	if (opt.opt.conversion == 'o' && opt.opt.opt & 2)
		opt.opt.precision--;
	while (opt.opt.precision > a)
		opt.opt.precision -= moin(opt, '0');
}

void	offre(t_gob opt, int a, int b)
{
	int gg;

	opt.opt.largeur -= signe(opt, b, 0);
	gg = hexa(opt, opt.opt.conversion, 0, 1);
	opt.opt.largeur -= gg;
	if (opt.opt.conversion == 'o' && opt.opt.opt & 2 && opt.opt.precision > 0)
		opt.opt.largeur++;
	if ((opt.opt.opt & 16) && (b >= 0) && (opt.opt.precision > 0))
		opt.opt.largeur--;
	if (opt.opt.opt & 4)
		while (opt.opt.largeur > opt.opt.precision
		&& opt.opt.largeur > or(a, opt.opt.opt, b, opt))
			opt.opt.largeur -= moin(opt, ' ');
}
