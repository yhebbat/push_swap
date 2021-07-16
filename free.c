#include "prj.h"

void	ft_free(t_list *head)
{
	if(head)
	{
		while (head->header != NULL)
		{
			ft_depiler(head);
		}
	free(head);
	}
}


void	ft_exit()
{
	ft_putstr("Error\n");
	exit(0);
}

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
}