/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:07:42 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/03 19:31:24 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	g_array[SIZE_OPT] = {
{{5, 0, -1, 0, 0, '%'}, NULL},
{{29, 0, -1, 0, 0, 'd'}, &ft_putnbr},
{{7, 0, -1, 0, 0, 'x'}, &ft_putnbr_unsigned},
{{7, 0, -1, 0, 0, 'X'}, &ft_putnbr_unsigned},
{{7, 0, -1, 0, 0, 'u'}, &ft_putnbr_unsigned},
{{7, 0, -1, 0, 0, 'o'}, &ft_putnbr_unsigned},
{{31, 0, -1, 0, 0, 'b'}, &ft_putnbr_unsigned},
{{29, 0, -1, 0, 0, 'i'}, &ft_putnbr},
{{31, 0, 6, 10, 0, 'f'}, &ft_getf},
{{5, 0, -1, 0, 0, 's'}, &ft_putster},
{{5, 0, 6, 10, 0, 'c'}, &ft_putchar},
{{4, 0, -1, 0, 0, 'p'}, &ft_putnbr_address}
};

int	isin(char c, char *str)
{
	int	g;

	g = 1;
	while (*str)
	{
		if (*str++ == c)
			return (g);
		g *= 2;
	}
	return (0);
}

int	par(const char *f, t_opt *opt, va_list ap, int c)
{
	int		i;
	t_ch	ch;

	ch.opt = 0;
	while (isin(f[c], "0#- +"))
	{
		ch.opt = ch.opt | isin(f[c], "0#- +");
		c = c + 1;
	}
	i = ptt(opt, ch, c, f);
	if (i)
		opt->largeur = i;
	if (f[c] == '*')
		c = c + prt(opt, ap);
	while (f[c] >= '0' && f[c] <= '9')
		c++;
	if ((f[c] == '.'))
	{
		c = c + pft(opt, f, c);
		if (opt->precision == 0 && f[c] == '*')
				c = pst(opt, ap);
	}
	while ((f[c] && f[c] >= '0' && f[c] <= '9') || f[c] == '*')
		c++;
	return (c);
}

t_opt	getopts(const char *str)
{
	t_opt	opt;
	int		i;

	opt.opt = 0;
	while (*str)
	{
		i = 0;
		while (i < SIZE_OPT)
		{
			if (*str == g_array[i].opt.conversion)
				return (g_array[i].opt);
			i++;
		}
		str++;
	}
	return (opt);
}

int	taille(const char *format, t_opt *opt)
{
	int	i;

	i = 0;
	if (format[0] == 'l')
	{
		i = i + plt(opt, 1);
		if (format[1] == 'l')
			i = i + plt(opt, 2);
	}
	if (format[0] == 'h')
	{
		i = i + plt(opt, 4);
		if (format[1] == 'h')
			i = i + plt(opt, 6);
	}
	if (format[0] == 'L')
		i = i + plt(opt, 8);
	return (i);
}

void	ft_arrange(t_gob opt, char format, va_list ap)
{
	int	y;

	y = 1;
	if (format == '%')
	{
		ft_pour(opt);
		return ;
	}
	if (format)
	{
		while (y < SIZE_OPT)
		{
			if (g_array[y].opt.conversion == format)
				return (g_array[y].ptf(ap, opt));
			y++;
		}
	}
}
