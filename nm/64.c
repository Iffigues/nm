/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   64.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:43:32 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/18 21:51:53 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	symb64(t_elf fle, Elf64_Shdr *ph, int y)
{
	unsigned int	sym;
	Elf64_Sym		*sys;
	t_tab			*e;

	sym = ph->sh_size / sizeof(Elf64_Sym);
	sys = getsym64(fle, ph, sym);
	if (sys == NULL)
		return (-1);
	e = gettab64(sym, sys, fle, ph);
	if (e == NULL)
	{
		free(sys);
		return (-1);
	}
	e = nettoie64(e, sym, 0);
	if (e == NULL)
		return (-1);
	trie(e);
	y = affiche(e, 1);
	free(sys);
	free(e);
	return (y);
}

Elf64_Shdr	*getsh64( unsigned char *ptr, Elf64_Ehdr *eh)
{
	int			i;
	Elf64_Shdr	*f;

	i = 0;
	f = NULL;
	f = (Elf64_Shdr *)malloc(sizeof(Elf64_Shdr) * /*eh->e_shoff*/ eh->e_shnum);
	if (f == NULL)
		return (NULL);
	while (i < eh->e_shnum)
	{
		f[i] = *(Elf64_Shdr *)(ptr + (sizeof(Elf64_Shdr) * i));
		i++;
	}
	return (f);
}

static void	frey(t_elf fle)
{
	free(fle.sihdr);
}

static void	fini(t_elf fle, int y)
{
	if (!y)
		ft_printf("./ft_nm: %s: no symbols\n", fle.name);
	free(fle.sihdr);
}

void	ft_64(t_elf fle, int y)
{
	Elf64_Ehdr		*eh;
	Elf64_Shdr		*ph;
	unsigned char	*ptr;
	int				i;

	i = 0;
	eh = (Elf64_Ehdr *)fle.ptr;
	if (!eh->e_shnum) {
		ft_printf("./ft_nm: %s", fle.name);
		ft_printf(": file format not recognized\n");
		return ;
	}
	if ((eh->e_shoff + (sizeof(Elf64_Shdr) * eh->e_shnum)) > fle.len) {
		ft_printf("./ft_nm: %s", fle.name);
		ft_printf(": file truncated\n");
		return ;
	}
	ptr = (unsigned char *)fle.ptr + eh->e_shoff;
	fle.sihdr = getsh64(ptr, eh);
	if (fle.sihdr == NULL)
		return ;
	while (i < eh->e_shnum)
	{
		ph = (Elf64_Shdr *)(ptr + (sizeof(Elf64_Shdr) * i));
		if (ph->sh_type == SHT_SYMTAB)
		{
			y = symb64(fle, ph, y);
			if (y < 0)
				return (frey(fle));
		}
		i++;
	}
	fini(fle, y);
}
