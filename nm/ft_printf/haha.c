/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haha.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:04:45 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/03 19:41:58 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prt(t_opt *opt, va_list ap)
{
	opt->largeur = va_arg(ap, int);
	return (1);
}

int	pst(t_opt *opt, va_list ap)
{
	opt->precision = va_arg(ap, int);
	return (1);
}

int	pft(t_opt *opt, const char *f, int c)
{
	opt->precision = ft_atoi(&f[c]);
	return (1);
}

int	ptt(t_opt *opt, t_ch ch, int c, const char *f)
{
	opt->opt = opt->opt & ch.opt;
	return (ft_atoi(&f[c]));
}

int	plt(t_opt *opt, int i)
{
	opt->taille = i;
	return (1);
}
