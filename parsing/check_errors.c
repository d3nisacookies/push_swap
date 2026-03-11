/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:37:05 by akaung            #+#    #+#             */
/*   Updated: 2026/03/11 15:37:05 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*cmp;

	tmp = a;
	while (tmp)
	{
		cmp = tmp->next;
		while (cmp)
		{
			if (tmp->value == cmp->value)
				return (0);
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	check_split_numbers(char **split)
{
	int	j;

	if (!split || !split[0])
		return (0);
	j = 0;
	while (split[j])
	{
		if (!is_number(split[j]))
			return (0);
		j++;
	}
	return (1);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	validate_input(int ac, char **av)
{
	char	**split;
	int		i;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!check_split_numbers(split))
		{
			if (split)
				free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (1);
}
