/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:47:33 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/03 20:29:55 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <stdio.h>
#include <string.h>

static int	symb32(t_elf fle, Elf32_Shdr *ph, int y)
{
	unsigned int	sym;
	Elf32_Sym		*sys;
	t_tab			*e;

	sym = ph->sh_size / sizeof(Elf32_Sym);
	sys = getsym(fle, ph, sym);
	if (sys == NULL)
		return (-1);
	e = gettab(sym, sys, fle, ph);
	if (e == NULL)
	{
		free(sys);
		return (-1);
	}
	e = nettoie(e, sym, 0);
	if (e == NULL)
		return (-1);
	trie(e);
	y = affiche(e, 0);
	free(sys);
	free(e);
	return (y);
}

Elf32_Shdr	*getsh( unsigned char *ptr, Elf32_Ehdr *eh)
{
	int			i;
	Elf32_Shdr	*f;

	i = 0;
	f = NULL;
	f = (Elf32_Shdr *)malloc(sizeof(Elf32_Shdr) * eh->e_shoff);
	if (f == NULL)
		return (NULL);
	while (i < eh->e_shnum)
	{
		f[i] = *(Elf32_Shdr *)(ptr + (sizeof(Elf32_Shdr) * i));
		i++;
	}
	return (f);
}

void	frey(t_elf fle)
{
	free(fle.shdr);
}

void	fini(t_elf fle, int y)
{
	if (!y)
		ft_printf("No Sym\nb");
	free(fle.shdr);
}

void	ft_32(t_elf fle, int y)
{
	Elf32_Ehdr		*eh;
	Elf32_Shdr		*ph;
	unsigned char	*ptr;
	int				i;

	i = 0;
	eh = (Elf32_Ehdr *)fle.ptr;
	if ((eh->e_shoff + (sizeof(Elf32_Shdr) * eh->e_shnum)) > fle.len)
		return ;
	ptr = (unsigned char *)fle.ptr + eh->e_shoff;
	fle.shdr = getsh(ptr, eh);
	if (fle.shdr == NULL)
		return ;
	while (i < eh->e_shnum)
	{
		ph = (Elf32_Shdr *)(ptr + (sizeof(Elf32_Shdr) * i));
		if (ph->sh_type == SHT_SYMTAB)
		{
			y = symb32(fle, ph, y);
			if (y < 0)
				return (frey(fle));
		}
		i++;
	}
	fini(fle, y);
}
