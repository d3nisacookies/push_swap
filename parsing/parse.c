/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:40:48 by akaung            #+#    #+#             */
/*   Updated: 2026/03/11 15:40:48 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*parse_input(int ac, char **av)
{
	t_stack	*a;
	char	**split;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (NULL);
		j = 0;
		while (split[j])
		{
			add_back(&a, new_node(ft_atoi(split[j])));
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (a);
}
