/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:37:41 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/18 20:29:27 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long nbr, char *base, int aa, t_gob opt)
{
	int len;

	if (opt.opt.precision == 0 && nbr == 0)
	{
		if (opt.opt.opt & 2)
			opt.opt.opt = opt.opt.opt ^ 2;
		affre(opt, 0, nbr);
		return (0);
	}
	len = ft_strlen(base);
	if (nbr / len)
		aa = ft_putnbr_base(nbr / len, base, aa + 1, opt);
	if (!(nbr / len))
		affre(opt, aa, nbr);
	ft_add(opt, base[ABS(nbr) % len]);
	return (aa);
}

int	ft_u_b(unsigned long long n, char *b, int aa, t_gob opt)
{
	int len;

	if (opt.opt.precision == 0 && n == 0)
	{
		if (opt.opt.opt & 2)
			opt.opt.opt = opt.opt.opt ^ 2;
		affre(opt, 0, n);
		return (0);
	}
	len = ft_strlen(b);
	if (n / len)
		aa = ft_u_b(n / len, b, aa + 1, opt);
	if (!(n / len))
		affre(opt, aa, n);
	ft_add(opt, b[ABS(n) % len]);
	return (aa);
}
