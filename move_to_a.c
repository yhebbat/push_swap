#include "prj.h"

void	from_upa(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] > 0)
	{
		rotate(head_a);
		ft_putstr("ra\n");
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{	
		reverse_rotate(head_b);
		ft_putstr("rrb\n");
		t[NBB]--;
	}
	push(head_a, head_b);
	ft_putstr("pa\n");
}

void	from_upb(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] > 0)
	{
		reverse_rotate(head_a);
		ft_putstr("rra\n");
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		rotate(head_b);
		ft_putstr("rb\n");
		t[NBB]--;
	}
	push(head_a, head_b);
	ft_putstr("pa\n");
}

void	from_upab(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] > 0 && t[NBB] > 0)
	{
		rotate(head_a);
		rotate(head_b);
		ft_putstr("rr\n");
		t[NBA]--;
		t[NBB]--;
	}
	while (t[NBA] > 0)
	{
		rotate(head_a);
		ft_putstr("ra\n");
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		rotate(head_b);
		ft_putstr("rb\n");	
		t[NBB]--;
	}
	push(head_a, head_b);
	ft_putstr("pa\n");
}

void	from_downab(int *t, t_list *head_a, t_list *head_b)
{
	while (t[NBA] > 0 && t[NBB] > 0)
	{
		reverse_rotate(head_a);
		reverse_rotate(head_b);
		ft_putstr("rrr\n");
		t[NBA]--;
		t[NBB]--;
	}
	while (t[NBA] > 0)
	{
		reverse_rotate(head_a);
		ft_putstr("rra\n");
		t[NBA]--;
	}
	while (t[NBB] > 0)
	{
		reverse_rotate(head_b);
		ft_putstr("rrb\n");
		t[NBB]--;
	}
	push(head_a, head_b);
	ft_putstr("pa\n");
}

void	actions(int *t, t_list *head_a, t_list *head_b)
{
	if (t[UPA] == 1 && t[UPB] == 0)
		from_upa(t, head_a, head_b);
	else if (t[UPB] == 1 && t[UPA] == 0)
		from_upb(t, head_a, head_b);
	else if (t[UPA] == 1 && t[UPB] == 1)
		from_upab(t, head_a, head_b);
	else if (t[UPA] == 0 && t[UPB] == 0)
		from_downab(t, head_a, head_b);
}