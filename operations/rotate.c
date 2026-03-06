#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack *first;
	t_stack *last;

	if (!*a || !(*a)->next)
		return;

	first = *a;
	*a = (*a)->next;

	last = *a;
	while (last->next)
		last = last->next;

	last->next = first;
	first->next = NULL;

	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack *first;
	t_stack *last;

	if (!*b || !(*b)->next)
		return;

	first = *b;
	*b = (*b)->next;

	last = *b;
	while (last->next)
		last = last->next;

	last->next = first;
	first->next = NULL;

	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}