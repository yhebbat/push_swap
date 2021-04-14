void		ft_exit()
{
	printf("Error\n");
	exit(0);
}

void	ft_get(t_list *header_a, t_list *header_b)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (strcmp(line, "") == 0)
			break ;
		ft_command(header_a, header_b, line);
		free(line);
	}
}

void	ft_free(t_list *head)
{
	t_stack *to_free;

	to_free = head->header;
	while (to_free->suivant != NULL)
	{
		ft_depiler(head);
		to_free = to_free->suivant;
	}
	free(head);
}

void	ft_checker(t_list *head)
{
	t_stack *to_check;

	to_check = head->header;
	while (to_check->suivant != NULL)
	{
		if (to_check->value > to_check->suivant->value)
		{
			printf("KO\n");
			ft_free(head);
			exit(0);
		}
		to_check = to_check->suivant;	
	}
	printf("OK\n");
	ft_free(head);
}

int main(int ac, char **av)
{
	t_list *header;
	t_list *header_b;
	t_stack *a;
	// t_stack *b;

	//a = NULL;
	if (ac > 1)
	{
		//i = ac - 1;
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
		// //b = header_b->header;
        printf("|a|\n");
		while (a != NULL)
		{
			printf("%d\n",a->value);
			a = a->suivant;
		}
		ft_checker(header);
		// while (b != NULL)
		// {
		// 	printf("|b|%d\n",b->value);
		// 	b = b->suivant;
		// }
	}
	else
		ft_exit();
}