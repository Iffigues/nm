/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:31:00 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/18 20:23:10 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size(unsigned int a)
{
	int y;

	y = 1;
	while (--a > 1)
		y *= 10;
	return (y);
}

void	ft_fl_base(long long a, char *b, t_gob opt)
{
	int len;

	len = ft_strlen(b);
	if (a / len)
		ft_fl_base(a / len, b, opt);
	ft_add(opt, b[ABS(a) % len]);
}

int		float_count(long long a)
{
	int	b;

	b = 1;
	while (a /= 10)
		b++;
	return (b);
}

char	ft_floatzero(t_gob opt)
{
	if ((opt.opt.opt & 1) && !(opt.opt.opt & 4))
		return ('0');
	return (' ');
}

void	float_optafter(long long a, t_gob opt)
{
	int i;

	i = (opt.opt.precision > 0) + opt.opt.precision;
	i += float_count(a);
	while ((int)opt.opt.largeur > i && (opt.opt.opt & 4))
	{
		ft_add(opt, ft_floatzero(opt));
		opt.opt.largeur--;
	}
}
