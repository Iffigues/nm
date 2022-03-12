#include "ft_nm.h"

void affiche(t_tab *c)
{
	int i;

	i = 0;
	while (c[i].end == 0)
	{
		if (c[i].exa)
			ft_printf("%08x %c %s\n", c[i].exa, c[i].t, c[i].name);
		else 
			ft_printf("%8c %c %s\n",' ', c[i].t ,c[i].name);
		i++;
	}
}
