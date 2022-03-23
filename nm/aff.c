#include "ft_nm.h"
#include <stdio.h>

int	affiche(t_tab *c, int ii)
{
	int	i;

	i = 0;
	while (c[i].end == 0)
	{
		if (!ii)
		{
			if (c[i].t != 'v' && c[i].t != 'w' && c[i].t != 'U')
				ft_printf("%08x %c %s\n", c[i].exa, c[i].t, c[i].name);
			else
				ft_printf("%8c %c %s\n", ' ', c[i].t, c[i].name);
		}
		else
		{
			if (c[i].t != 'v' && c[i].t != 'w' && c[i].t != 'U')
				printf("%016lx %c %s\n", c[i].exa, c[i].t, c[i].name);
			else
				ft_printf("%16c %c %s\n", ' ', c[i].t, c[i].name);
		}
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}
