#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* parsing */
t_stack	*parse_input(int ac, char **av);
int		check_duplicates(t_stack *a);
int		validate_input(int ac, char **av);

/* stack */
t_stack	*new_node(int value);
void	add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *a);
void	free_stack(t_stack **stack);

/* operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* sorting */
void	index_stack(t_stack *a);
void	radix_sort(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);

/* utils */
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

#endif