/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:40:37 by akaung            #+#    #+#             */
/*   Updated: 2026/03/11 15:40:37 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_stack(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*cmp;
	int		index;

	tmp = a;
	while (tmp)
	{
		index = 0;
		cmp = a;
		while (cmp)
		{
			if (cmp->value < tmp->value)
				index++;
			cmp = cmp->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}
