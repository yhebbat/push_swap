#include "prj.h"
/*
void	ft_pushswap(t_list *head, t_list *head_b)
{

}
*/
int main(int ac, char **av)
{
	t_list *header;
	t_list *header_b;
	t_stack *a;

	if (ac > 1)
	{
		header = malloc(sizeof(t_list));
		header_b = malloc(sizeof(t_list));
		header->header = NULL;
		header_b->header = NULL;
		while (ac - 1 > 0)
		{
			if (check_value(header, av[ac - 1]))
				ft_exit();
			else
				ft_remplir(header, atoi(av[ac - 1]));
			ac--;
		}
		ft_get(header, header_b);
		a = header->header;
        printf("|a|\n");
		while (a != NULL)
		{
			printf("%d\n",a->value);
			a = a->suivant;
		}
		//ft_checker(header);
		ft_pushswap(header, header_b);
	}
	else
		ft_exit();
}