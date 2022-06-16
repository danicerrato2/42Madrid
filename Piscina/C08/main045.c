#include <stdio.h>
#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

int main(int argc, char *argv[])
{
	struct s_stock_str	*tabla;

	if (argc < 2)
		return (-1);
	tabla = ft_strs_to_tab(argc - 1, &argv[1]);
	ft_show_tab(tabla);
}
