#include "../push_swap.h"

int	is_number(char *str)
{
	int i;

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
	t_stack *tmp;
	t_stack *cmp;

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

int	validate_input(int ac, char **av)
{
	char **split;
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split || !split[0])
			return (0);
		j = 0;
		while (split[j])
		{
			if (!is_number(split[j]))
			{
				/* free split */
				int k = j;
				while (split[k])
				{
					free(split[k]);
					k++;
				}
				free(split);
				return (0);
			}
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (1);
}
