/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:15 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/15 21:54:24 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	opt_actual3(t_linked_stack *as)
{
	long	tmb[3];

	if (!as || as->element_count != 3)
		response_error();
	tmb[0] = as->top_node.next->value;
	tmb[1] = as->top_node.next->next->value;
	tmb[2] = as->top_node.prev->value;
	if (is_sorted(as, as->element_count) == TRUE)
		return (TRUE);
	else
	{
		opt_actual3_case1(as, tmb);
		opt_actual3_case2(as, tmb);
	}
	return (TRUE);
}

int	opt5(t_linked_stack *as, t_linked_stack *bs)
{
	long			min_value;
	long			second_min_value;
	t_stack_node	*node;

	if (!as || !bs)
		response_error();
	if (is_sorted(as, 5) != TRUE)
	{
		find_minimum_two(as, &min_value, &second_min_value);
		while (as->element_count > 3)
		{
			node = as->top_node.next;
			if (as->element_count == 3)
				break ;
			if (node->value == min_value || node->value == second_min_value)
				push(bs, as, PB);
			else
				single_rotate(as, RA);
		}
		single_reverse_rotate(as, RRA);
		single_reverse_rotate(as, RRA);
		opt3(as, bs);
		reversed_opt2(as, bs);
	}
	return (TRUE);
}

int	opt3(t_linked_stack *as, t_linked_stack *bs)
{
	long	tmb[3];

	if (!as || !bs || as->element_count < 3)
		response_error();
	tmb[0] = as->top_node.next->value;
	tmb[1] = as->top_node.next->next->value;
	tmb[2] = as->top_node.next->next->next->value;
	if (is_sorted(as, 3) == TRUE)
		return (TRUE);
	else
	{
		opt3_case1(as, bs, tmb);
		opt3_case2(as, bs, tmb);
	}
	return (TRUE);
}

int	opt2(t_linked_stack *as, t_linked_stack *bs)
{
	if (!as || !bs)
		response_error();
	if (as->top_node.next->value > as->top_node.next->next->value)
		single_swap(as, SA);
	return (TRUE);
}

int	a_opt(t_linked_stack *as, t_linked_stack *bs, ssize_t k)
{
	if (!as || !bs)
		response_error();
	else if (as->element_count == 5)
		return (opt5(as, bs));
	else if (k == 3 && as->element_count > 3)
		return (opt3(as, bs));
	else if (k == 3 && as->element_count == 3)
		return (opt_actual3(as));
	else if ((k == 3 && as->element_count < 2) || (0 <= k && k <= 2))
		return (opt2(as, bs));
	return (FALSE);
}
