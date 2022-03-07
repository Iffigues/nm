/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 23:20:35 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/21 12:52:51 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rot(int *largeur, int y, int u, t_gob opt)
{
	char c;

	c = ' ';
	if (opt.opt.opt & 1)
		c = '0';
	while ((*largeur > y) && u)
	{
		ft_add(opt, c);
		*largeur -= 1;
	}
}

void	ft_null(t_gob opt, char *b)
{
	if (opt.opt.precision > 0)
		opt.opt.largeur -= opt.opt.precision;
	while (opt.opt.largeur > 6)
	{
		ft_add(opt, ' ');
		opt.opt.largeur--;
	}
	if (opt.opt.precision >= 0)
		while (*b && opt.opt.precision)
		{
			ft_add(opt, *b++);
			opt.opt.precision--;
		}
	else
		while (*b)
			ft_add(opt, *b++);
}

int		moin(t_gob opt, char c)
{
	ft_add(opt, c);
	return (1);
}

int		largeur(t_gob opt, int a, int b, char pp)
{
	if (!(opt.opt.opt & 4) && (opt.opt.largeur > 0) && (opt.opt.largeur > a))
		while (opt.opt.largeur > opt.opt.precision
				&& opt.opt.largeur > or(a, opt.opt.opt, b, opt))
			opt.opt.largeur -= moin(opt, pp);
	return (opt.opt.largeur);
}

void	ft_nulls(t_gob opt)
{
	char c;

	c = ' ';
	if (opt.opt.opt & 1)
		c = '0';
	if (opt.opt.largeur > 0 && opt.opt.precision == 0)
		while (opt.opt.largeur)
		{
			ft_add(opt, c);
			opt.opt.largeur--;
		}
	else
		ft_null(opt, "(null)");
}
