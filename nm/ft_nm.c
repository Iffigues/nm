/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:06:32 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/18 20:22:43 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	failed(char *a)
{
	write(1, a, ft_strlen(a));
	return ;
}

void	getstat(t_elf fle)
{
	if (!verif(&fle)) {
		ft_printf("./ft_nm: %s", fle.name);
		return (failed(": file format not recognized\n"));
	}
	if (fle.sys != 3)
	{
		if (!endian(&fle))
			return (failed("not un indien"));
		if (!systems(&fle))
			return (failed("not 64_32"));
		if (fle.sys == 1)
			ft_32(fle, 0);
		if (fle.sys == 2) {
			ft_64(fle, 0);
		}
	}
	else
		ar(fle, 0);
}

void	ft_nm(char *a)
{
	int		fd;
	t_elf	fle;

	fd = open(a, O_RDONLY);
	if (fd < 0) {
		ft_printf("./ft_nm: \'%s\': ", a);
		return (failed("No such file\n"));
	}
	if ((fstat(fd, &fle.buf)) < 0)
		return (failed("error with fstats"));
	fle.ptr = mmap(0, fle.buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (fle.ptr == MAP_FAILED)
		return ;
	fle.name = a;
	fle.len = fle.buf.st_size;
	if (fle.len > 0)
		getstat(fle);
	if (munmap((void *)fle.ptr, fle.buf.st_size) < 0)
	{}
	close(fd);
}
