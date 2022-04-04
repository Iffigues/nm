/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:23:20 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/03 20:33:44 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	affer(char *t)
{
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (t[i] && t[i] != '/')
		i++;
	write(1, t, i);
	write(1, ":\n", 2);
}

static void	fr(char *str)
{
	if (str != NULL)
		free(str);
}

static void	wily(t_elf fle, int i, char *str, struct ar_hdr *header)
{
	while (fle.ptr)
	{
		header = (struct ar_hdr *)fle.ptr;
		if (ft_atoi(header->ar_size) <= 0)
			return (fr(str));
		if (i == 0 && ft_strncmp(header->ar_name, "//", 2) == 0)
		{
			str = namer(header->ar_name);
			if (str == NULL)
				return ;
			i = 0;
		}
		else
		{
			i = 1;
			if (header->ar_name[0] == '/')
				affer(&str[ft_atoi(&header->ar_name[1])]);
			else
				affer(header->ar_name);
			grab(fle.ptr + getelf(fle.ptr), fle);
		}
		fle.ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	}
	fr(str);
}

void	ar(t_elf fle, int i)
{
	char			*str;
	struct ar_hdr	*header;

	str = NULL;
	fle.ptr += SARMAG;
	header = (struct ar_hdr *)fle.ptr;
	fle.ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	wily(fle, i, str, header);
}
