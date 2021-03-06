/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:03:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/17 00:51:18 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_bottom(t_linked_stack *stack, long value)
{
	t_stack_node	*node;

	node = create_node(value);
	if (!stack || !node)
		response_error();
	if (is_linked_stack_empty(stack) == TRUE)
	{
		node->prev = node;
		node->next = node;
		stack->top_node.next = node;
	}
	else
	{
		node->next = stack->top_node.next;
		node->prev = stack->top_node.prev;
		stack->top_node.prev->next = node;
		stack->top_node.next->prev = node;
	}
	stack->top_node.prev = node;
	stack->element_count++;
	return (TRUE);
}

int	push_top(t_linked_stack *stack, long value)
{
	t_stack_node	*node;

	node = create_node(value);
	if (!node || !stack)
		response_error();
	if (is_linked_stack_empty(stack) == TRUE)
	{
		node->next = node;
		node->prev = node;
		stack->top_node.prev = node;
	}
	else
	{
		node->next = stack->top_node.next;
		node->prev = stack->top_node.prev;
		stack->top_node.next->prev = node;
		stack->top_node.prev->next = node;
	}
	stack->top_node.next = node;
	stack->element_count++;
	return (TRUE);
}

t_stack_node	*pop_on_top(t_linked_stack *stack)
{
	t_stack_node	*top_node;

	if (!stack)
		response_error();
	if (is_linked_stack_empty(stack) == TRUE)
		return (NULL);
	top_node = stack->top_node.next;
	stack->top_node.next = top_node->next;
	stack->top_node.next->prev = stack->top_node.prev;
	stack->top_node.prev->next = stack->top_node.next;
	stack->element_count--;
	return (top_node);
}

t_stack_node	*pop_on_bottom(t_linked_stack *stack)
{
	t_stack_node	*bottom_node;

	if (!stack)
		response_error();
	if (is_linked_stack_empty(stack) == TRUE)
		return (NULL);
	bottom_node = stack->top_node.prev;
	stack->top_node.prev = bottom_node->prev;
	stack->top_node.next->prev = stack->top_node.prev;
	stack->top_node.prev->next = stack->top_node.next;
	stack->element_count--;
	return (bottom_node);
}

int	push(t_linked_stack *push_stack, t_linked_stack *pop_stack, \
			t_command command)
{
	t_stack_node	*pop_node;
	t_type			flag;

	if (!push_stack || !pop_stack)
		response_error();
	pop_node = pop_on_top(pop_stack);
	if (!pop_node)
		response_error();
	flag = push_top(push_stack, pop_node->value);
	free(pop_node);
	if (command == PA && flag == TRUE)
		write(1, "pa\n", 3);
	else if (command == PB && flag == TRUE)
		write(1, "pb\n", 3);
	return (TRUE);
}
