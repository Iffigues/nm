/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tries.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:25:13 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/16 18:16:38 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int mama(char t) {

	if (t >= 'A' && t <= 'Z')
		return 0;
	if (t >= 'a' && t <= 'z')
		return 0;
	if (t >= '0' && t <= '9')
		return 0;
	if (t == '$')
		return 0;
	return 1;
}

unsigned long	ge(char *t)
{
	unsigned long	l;

	l = 0;
	while (t[l] && mama(t[l]))
		l++;
	return (l);
}

char	lo(char t)
{
	if (t >= 'A' && t <= 'Z')
		return (t + ('a' - 'A'));
	return (t);
}

int	place(char *s1, char *s2)
{
	while (*s1 && *s2 && (lo(*s1) == lo(*s2)))
	{
		s1++;
		s2++;
		while (*s1 && mama(*s1))
			s1++;
		while (*s2 && mama(*s2))
			s2++;
	}
	while (*s1 && (mama(*s1)))
		s1++;
	while (*s2 && (mama(*s2)))
		s2++;
	return (lo(*s1) - lo(*s2));
}

void	swap(t_tab *e, unsigned long j)
{
	t_tab			k;
	unsigned long	m;
	unsigned long	f;
	int				h;

	m = ge(e[j + 1].name);
	f = ge(e[j].name);
	h = place(&e[j + 1].name[m], &e[j].name[f]);
	if ((h == 0 && (ft_strlen(&e[j].name[f]) > ft_strlen(&e[j + 1].name[m]))) || (h < 0 || ((h == 0) && m > 0)))
	{
		k = e[j];
		e[j] = e[j + 1];
		e[j + 1] = k;
	}
}

unsigned long	getsize(t_tab *e)
{
	unsigned long	j;

	j = 0;
	while (e[j].end == 0)
		j++;
	return (j);
}
