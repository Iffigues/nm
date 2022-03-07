/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:10:27 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/21 20:04:45 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_hexa(char c)
{
	if ((c == 'd') || (c == 'u') || (c == 'i'))
		return ("0123456789");
	if (c == 'b')
		return ("01");
	if (c == 'o')
		return ("01234567");
	if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	if (c == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}

void	ft_putnbr(va_list ap, t_gob opt)
{
	int			a;
	int			c;
	long long	b;

	b = va_arg(ap, long long);
	c = opt.opt.conversion;
	if (opt.opt.taille == 0)
		a = ft_ret((int)b, my_hexa(c), 1, opt);
	if (opt.opt.taille == 1)
		a = ft_ret((long)b, my_hexa(c), 1, opt);
	if (opt.opt.taille == 2)
		a = ft_ret(b, my_hexa(c), 1, opt);
	if (opt.opt.taille == 4)
		a = ft_ret((short)b, my_hexa(c), 1, opt);
	if (opt.opt.taille == 6)
		a = ft_ret((char)b, my_hexa(c), 1, opt);
	if ((int)b < 0)
		offre(opt, a, -1);
	else
		offre(opt, a, 0);
}

void	ft_putnbr_address(va_list ap, t_gob opt)
{
	int			a;
	uintptr_t	t;

	opt.opt.opt = opt.opt.opt | 2;
	t = va_arg(ap, uintptr_t);
	if (opt.opt.largeur && opt.opt.precision > 0 && opt.opt.opt & 4)
		opt.opt.largeur += 2;
	a = ft_u_b(t, my_hexa(opt.opt.conversion), 1, opt);
	offre(opt, a, 0);
}

void	ft_putnbr_unsigned(va_list ap, t_gob opt)
{
	int					a;
	char				c;
	unsigned long long	b;

	b = va_arg(ap, long long);
	c = opt.opt.conversion;
	if (opt.opt.conversion == 'o' && b == 0
	&& opt.opt.precision == 0 && opt.opt.opt & 2)
		opt.opt.largeur--;
	if (opt.opt.taille == 0)
		a = ft_retu((unsigned int)b, my_hexa(c), 1, opt);
	if (opt.opt.taille == 1)
		a = ft_retu((unsigned long)b, my_hexa(c), 1, opt);
	if (opt.opt.taille == 2)
		a = ft_retu(b, my_hexa(c), 1, opt);
	if (opt.opt.taille == 4)
		a = ft_retu((unsigned short)b, my_hexa(c), 1, opt);
	if (opt.opt.taille == 6)
		a = ft_retu((unsigned char)b, my_hexa(c), 1, opt);
	opt = ft_ar(opt, b);
	offre(opt, a, 0);
}

void	ft_putchar(va_list ap, t_gob opt)
{
	int		u;
	int		nbr;
	char	p;

	p = ' ';
	if (opt.opt.opt & 1)
		p = '0';
	nbr = va_arg(ap, int);
	u = (opt.opt.opt & 4);
	while (((int)opt.opt.largeur > 1) && !(u))
	{
		ft_add(opt, p);
		opt.opt.largeur--;
	}
	opt.opt.opt = 0;
	ft_add(opt, nbr);
	while (((int)opt.opt.largeur > 1) && (u))
	{
		ft_add(opt, ' ');
		opt.opt.largeur--;
	}
}
