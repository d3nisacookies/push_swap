#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac < 2)
		return (0);

	if (!validate_input(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}

	a = parse_input(ac, av);
	b = NULL;

	if (!check_duplicates(a))
	{
		write(2, "Error\n", 6);
		/* free stack */
		return (1);
	}

	index_stack(a);

	if (!is_sorted(a))
	{
		if (stack_size(a) <= 5)
			small_sort(&a, &b);
		else
			radix_sort(&a, &b);
	}

	free_stack(&a);
	free_stack(&b);
	return (0);
}