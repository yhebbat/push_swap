#include "prj.h"

int	main(int ac, char **av)
{
	t_list	*header;
	t_list	*header_b;

	if (ac > 1)
	{
		header = malloc(sizeof(t_list));
		header_b = malloc(sizeof(t_list));
		header->header = NULL;
		header_b->header = NULL;
		header->footer = NULL;
		header_b->footer = NULL;
		while (ac - 1 > 0)
		{
			if (check_value(header, av[ac - 1]))
				ft_exit();
			else
				ft_remplir(header, atoi(av[ac - 1]), -1);
			ac--;
		}
		ft_get(header, header_b);
		if (ft_checker(header))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		ft_free(header);
		ft_free(header_b);
		exit(0);
	}
}
