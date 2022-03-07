/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:15:13 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/21 12:48:44 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_at(const char *str, size_t a)
{
	while (str[a])
		a++;
	return (a);
}

char	opts(t_gob opt, int nb)
{
	if ((opt.opt.precision >= 0) & (opt.opt.opt & 1))
		opt.opt.opt = opt.opt.opt - 1;
	if (opt.opt.opt & 8 && nb >= +0 && !(opt.opt.opt & 16))
		ft_add(opt, ' ');
	if (opt.opt.opt & 1)
		return ('0');
	return (' ');
}

size_t	ft_strlen(const char *c)
{
	int y;

	y = 0;
	while (c[y])
		y++;
	return (y);
}

void	ft_pourcentage(t_gob opt)
{
	ft_add(opt, opt.opt.conversion);
}

void	ft_putster(va_list ap, t_gob opt)
{
	int		y;
	int		u;
	char	*nbr;

	y = 0;
	if (!((nbr = va_arg(ap, char *))))
		return (ft_nulls(opt));
	u = (opt.opt.opt & 4);
	if (nbr && *nbr)
		y = ft_strlen(nbr);
	if ((opt.opt.precision > -1) && (opt.opt.precision <= y))
		y = opt.opt.precision;
	ft_rot(&opt.opt.largeur, y, !(u), opt);
	opt.opt.opt = 0;
	if (opt.opt.precision >= 0 && nbr && nbr)
		while (nbr && *nbr && opt.opt.precision--)
			ft_add(opt, *nbr++);
	else
		while (nbr && *nbr)
			ft_add(opt, *nbr++);
	ft_rot(&opt.opt.largeur, y, u, opt);
}
