#include "../push_swap.h"

t_stack *parse_input(int ac, char **av)
{
	t_stack *a = NULL;
	char **split;
	int i;
	int j;

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