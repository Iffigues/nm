/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   64s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:53:26 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/03 20:27:53 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

Elf64_Sym	*getsym64(t_elf fle, Elf64_Shdr *ph, unsigned int y)
{
	Elf64_Sym		*z;
	unsigned int	i;
	Elf64_Sym		p;

	z = (Elf64_Sym *)malloc(sizeof(Elf64_Sym) * y);
	if (z == NULL)
		return (NULL);
	i = 0;
	while (i < y)
	{
		p = *(Elf64_Sym *)(fle.ptr + ph->sh_offset + (sizeof(Elf64_Sym) * i));
		if (fle.sihdr[ph->sh_link].sh_offset + p.st_name > fle.len)
		{
			free(z);
			return (NULL);
		}
		z[i++] = p;
	}
	return (z);
}

t_tab	symo64(t_elf fle, Elf64_Sym sys, Elf64_Shdr *ph)
{
	t_tab	t;

	t.vs = 1;
	t.error = 0;
	t.t = sletter(fle, &sys);
	t.exa = fle.sihdr[sys.st_shndx].sh_addr;
	t.exa = sys.st_value;
	t.name = (char *)fle.ptr + fle.sihdr[ph->sh_link].sh_offset + sys.st_name;
	return (t);
}

t_tab	*gettab64(unsigned long sym, Elf64_Sym *sys, t_elf fle, Elf64_Shdr *ph)
{
	unsigned long	l;
	int				a;
	t_tab			*t;

	l = 0;
	t = (t_tab *)malloc(sizeof(t_tab) * sym);
	if (t == NULL)
		return (NULL);
	while (l < sym)
	{
		a = ELF64_ST_TYPE(sys[l].st_info);
		t[l].vs = 0;
		if (a == STT_FUNC || a == STT_OBJECT || a == STT_NOTYPE)
		{
			t[l] = symo64(fle, sys[l], ph);
			if (t[l].error < 0)
			{
				free(t);
				return (NULL);
			}
		}
		l++;
	}
	return (t);
}

static t_tab	*fi(t_tab *t, unsigned long x, t_tab *e)
{
	t[x].end = 1;
	free(e);
	return (t);
}

t_tab	*nettoie64(t_tab *e, unsigned long sym, unsigned long h)
{
	t_tab			*t;
	unsigned long	x;

	x = 0;
	while (h < sym)
	{
		if (e[h].vs && ft_strlen(e[h].name) > 0)
			x++;
		h++;
	}
	t = (t_tab *)malloc((sizeof(t_tab) * (x + 1)));
	if (t == NULL)
		return (NULL);
	zeze(&x, &h);
	while (h < sym)
	{
		if (e[h].vs && ft_strlen(e[h].name) > 0)
		{
			t[x] = e[h];
			t[x].end = 0;
			x++;
		}
		h++;
	}
	return (fi(t, x, e));
}
