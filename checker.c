#include "prj.h"

static void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		write(1, &c[i++], 1);
}

void	ft_checker(t_list *head)
{
	t_stack	*to_check;

	to_check = head->header;
	while (to_check->suivant != NULL)
	{
		if (to_check->value > to_check->suivant->value)
		{
			ft_putstr("KO\n");
			return ;
		}
		to_check = to_check->suivant;
	}
	ft_putstr("OK\n");
}

int	main(int ac, char **av)
{
	t_list	*header;
	t_list	*header_b;
	t_stack *a;
	t_stack *x;

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
				ft_remplir(header, atoi(av[ac - 1]));
			ac--;
		}
		// ft_get(header, header_b);
		// ft_checker(header);
		a = header->header;
		printf("header : %d\n", header->header->value);
		printf("footer : %d\n",header->footer->value);
		while (a != NULL)
		{
			printf("%d\n",a->value);
			a = a->suivant;
		}
		printf("%d",header->header->value);
		x = header->footer;
		printf("header : %d\n", header->header->value);
		printf("footer : %d\n",header->footer->value);
		while (x != NULL)
		{
			printf("%d\n",x->value);
			x = x->preced;
		}
		ft_free(header);
		ft_free(header_b);
		exit(0);
	}
	else
		ft_exit();
}
//411 412 413 414 415 416 417 418 419 420 421 422 423 424 425 426 427 428 429 430 431 432 433 434 435 436 437 438 439 440 441 442 443 444 445 446 447 448 449 450 451 452 453 454 455 456 457 458 45