/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:15 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/14 18:02:55 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	opt_three(t_linked_stack *stack)
{
	int	top;
	int	mid;
	int	bottom;
	int	temp;

	top = stack->top_node.next->value;
	mid = stack->top_node.next->next->value;
	bottom = stack->top_node.prev->value;
	if (top < bottom && bottom < mid)
		temp = single_swap(stack, SA) * single_rotate(stack, RA);
	else if (mid < bottom && bottom < top)
		temp = single_rotate(stack, RA);
	else if (mid < top && top < bottom)
		temp = single_swap(stack, SA);
	else if (bottom < mid && mid < top)
		temp = single_swap(stack, SA) * single_reverse_rotate(stack, RRA);
	else
		temp = single_reverse_rotate(stack, RRA);
	return (temp);
}

int	opt_two(t_linked_stack *stack)
{
	if (!stack)
		response_error();
	return (single_swap(stack, SA));
}

int	opt_five(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	t_stack_node	*node;
	int				min_value;

	if (!a_stack || !b_stack || a_stack->element_count != 5)
		response_error();
	min_value = find_min_value(a_stack);
	while (a_stack->element_count > 3)
	{
		node = a_stack->top_node.next;
		if (node->value == min_value)
		{
			push(b_stack, a_stack, PB);
			min_value = find_min_value(a_stack);
		}
		single_rotate(a_stack, RA);
	}
	if (a_stack->element_count == 3)
		opt_three(a_stack);
	node = b_stack->top_node.next;
	if (node->value < node->next->value)
		single_swap(b_stack, SB);
	push(a_stack, b_stack, PA);
	push(a_stack, b_stack, PA);
	return (OK);
}

int	a_optimization(t_linked_stack *as, t_linked_stack *bs)
{
	if (!as || !bs)
		response_error();
	else if (is_sorted(as))
		return (OK);
	else if (as->element_count == 2)
		return (opt_two(as));
	else if (as->element_count == 3)
		return (opt_three(as));
	else if (as->element_count == 5)
		return (opt_five(as, bs));
	return (FALSE);
}
