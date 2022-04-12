/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:52:32 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/18 20:29:46 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pour(t_gob opt)
{
	char c;

	c = ' ';
	if (opt.opt.opt & 1)
		c = '0';
	while (((int)opt.opt.largeur > 1) && !(opt.opt.opt & 4))
	{
		ft_add(opt, c);
		opt.opt.largeur--;
	}
	ft_add(opt, '%');
	while (((int)opt.opt.largeur > 1) && (opt.opt.opt & 4))
	{
		ft_add(opt, ' ');
		opt.opt.largeur--;
	}
}
