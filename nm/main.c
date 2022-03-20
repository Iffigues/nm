#include "ft_nm.h"

int main (int argc, char **argv) 
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
