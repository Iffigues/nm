/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:32:46 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/18 20:19:10 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	zeze(unsigned long *a, unsigned long *h)
{
	*a = 0;
	*h = 0;
}

int term(t_elf fle, unsigned int size) {
	while (size < fle.len) {
		if (!*((char *)fle.ptr + size))
			return 1;
		size++;
	}
	return 0;
}
