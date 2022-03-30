/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ars.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:36:01 by bordenoy          #+#    #+#             */
/*   Updated: 2022/03/31 00:36:48 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	*ft_memalloc(size_t size)
{
	void	*o;

	o = (void *)malloc(size);
	if (!o)
		return ((void *)0);
	return (ft_memset(o, 0, size));
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*g;

	str = ft_memalloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	g = str;
	while (*s1)
		ft_memset(str++, *s1++, 1);
	ft_memset(str, 0, 1);
	return (g);
}

char	*namer(char *p)
{
	int	i;
	char	*r;

	i = 0;
	while (p[i] && p[i] != '\n')
		i++;
	i++;
	if (p[i])
		r = ft_strdup(&p[i]);
	else
		return (NULL);
	i = 0;
	while (r[i])
	{
		if (r[i] == '\n')
			r[i] = '\0';
		i++;
	}
	return (r);
}

int	getelf(const char *ptr)
{
	int	i;

	i = 0;
	while (ft_strncmp(&ptr[i], "ELF", 3))
		i++;
	return (i - 1);
}

void	grab(const char *ptr, t_elf fle)
{
	t_elf	g;

	g.ptr = ptr;
	g.len = fle.len;
	getstat(g);
}
