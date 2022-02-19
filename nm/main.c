#include "ft_nm.h"

int main (int argc, char **argv) 
{
	if (argc == 1)
		return (ft_help());
	while (*++argv) 
		ft_nm(*argv);
	return (EXIT_SUCCESS);
}
