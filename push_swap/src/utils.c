/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:27:25 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/08 17:18:29 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (9 <= c && 13 >= c))
		return (1);
	return (0);
}

long long	a_to_longlong(const char *str)
{
	long long	nbr;
	int			sign;
	size_t		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 2147483647 && sign == 1)
			response_error();
		else if (nbr > 2147483648 && sign == -1)
			response_error();
		i++;
	}
	return (sign * nbr);
}

int	is_greater(int a, int b)
{
	if (a < b)
		return (FALSE);
	return (OK);
}

int	is_sorted(t_linked_stack *stack)
{
	size_t			idx;
	t_stack_node	*node;
	t_stack_node	*next_node;

	if (!stack)
		return (ERROR);
	if (stack->element_count == 1)
		return (OK);
	idx = 0;
	node = stack->top_node.next;
	while (idx < stack->element_count)
	{
		next_node = node->next;
		if (is_greater(node->value, next_node->value) == FALSE)
			return (FALSE);
		node = next_node;
		idx++;
	}
	return (OK);
}