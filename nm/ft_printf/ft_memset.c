/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 22:16:22 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/09 16:35:55 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*h;

	h = (char *)b;
	while (len)
		if (len--)
			*h++ = (unsigned char)c;
	return (b);
}
