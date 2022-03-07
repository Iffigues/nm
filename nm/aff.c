#include "ft_nm.h"

void affiche(t_tab *c)
{
	int i;

	i = 0;
	while (c[i].end == 0)
	{
		ft_printf("%08x %s\n", c[i].exa, c[i].name);
		i++;
	}
}
