/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/03/11 15:26:04 by akaung            #+#    #+#             */
/*   Updated: 2026/03/11 15:26:04 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	error_return(void)
{
	return(write(2, "Error\n", 6));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (!validate_input(ac, av))
		return (error_return());
	a = parse_input(ac, av);
	b = NULL;
	if (!check_duplicates(a))
		return (error_return());
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
