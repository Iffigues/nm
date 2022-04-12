/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_println.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:09:05 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/25 16:45:42 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsprintf(t_gob *opt, const char *format, va_list ap)
{
	while (*format)
	{
		if ((*format) == '%' && *format++)
		{
			opt->opt = getopts(format);
			format += par(format, &opt->opt, ap);
			format += taille(format, &opt->opt);
			if (opt->opt.largeur < 0)
			{
				opt->opt.largeur = ABS(opt->opt.largeur);
				opt->opt.opt = opt->opt.opt | 4;
			}
			if (*format)
				ft_arrange(*opt, *format, ap);
			format++;
		}
		else if (*format)
			ft_add(*opt, *format++);
	}
	return (end(*opt));
}

int		ft_printf(const char *format, ...)
{
	int		a;
	va_list	arg;
	t_gob	gob;
	char	b[BUFF_SIZE + sizeof(int) * 2 + 1];

	a = 0;
	ft_bzero(b, BUFF_SIZE + sizeof(int));
	gob.b = b;
	if (format == NULL)
		return (0);
	va_start(arg, format);
	a = ft_vsprintf(&gob, format, arg);
	va_end(arg);
	return (a);
}
