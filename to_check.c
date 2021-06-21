#include "prj.h"

int			is_digit(char *str)
{
	if (*(str + 1) != '\0' && (*str == '+' || *str == '-'))
		str++;
	while (*str)
	{
		if(*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int			check_duplicate(t_list *head, char *str)
{
	t_stack *a;

	if (head->header != NULL)
	{
		a = head->header;
		while (a != NULL)
		{
			if (a->value == atoi(str))
				return (1);
			a = a->suivant;
		}
	}
	return (0);
}

int			check_overflow(char *str)
{
	long long r;

	r = atoi(str);
	if (r > 2147483647 || r < -2147483648)
		return (1);
	return (0);
}

int	check_value(t_list *head, char *str)
{
	if (is_digit(str) || check_overflow(str) || check_duplicate(head, str))
		return (1);
	return (0);
}