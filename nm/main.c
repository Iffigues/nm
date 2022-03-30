/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:38:54 by bordenoy          #+#    #+#             */
/*   Updated: 2022/03/26 11:38:58 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_help());
	if (argc == 2)
		while (*++argv)
			ft_nm(*argv);
	if (argc > 2)
	{
		while (*++argv)
		{
			ft_printf("%s:\n", *argv);
			ft_nm(*argv);
			ft_printf("\n");
		}
	}
	return (EXIT_SUCCESS);
}
