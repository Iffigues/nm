/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:10:49 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/25 16:55:28 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		aff(char *b, int bb)
{
	return (ft_putstrlensize(b, bb));
}

int		ft_getsize(char *b, int c)
{
	return (b[sizeof(int) * c]);
}

int		end(t_gob opt)
{
	int a;

	a = 0;
	if (opt.b)
		*(int *)&opt.b[sizeof(int)] += aff(&opt.b[sizeof(int) * 2], *opt.b);
	a = *(int *)&opt.b[sizeof(int)];
	ft_bzero(opt.b, BUFF_SIZE + sizeof(int) * 2);
	return (a);
}

void	ft_add(t_gob opt, const char c)
{
	opt.b[sizeof(int) * 2 + *opt.b] = c;
	*(int *)opt.b += 1;
	opt.b[sizeof(int) * 2 + *opt.b] = '\0';
	if (*opt.b == BUFF_SIZE)
	{
		*(int *)&opt.b[sizeof(int)] += aff(&opt.b[sizeof(int)], *opt.b);
		*(int*)opt.b = 0;
	}
}
//char b[sizeof(int)];
//*(int *)b = 10;
