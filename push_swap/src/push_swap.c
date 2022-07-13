/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:54:27 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/13 16:23:01 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_linked_stack	*a_stack;
	t_linked_stack	*b_stack;
	t_linked_stack	*simulate_stack;

	create_stacks(&a_stack, &b_stack);
	validator(ac, av, a_stack, b_stack);
	if (is_sorted(a_stack) == OK || is_sorted(a_stack) == ERROR)
		return (delete_all_stack(a_stack, b_stack));
	if (a_stack->element_count == 3)
		return (opt_three(a_stack));
	if (a_stack->element_count == 2)
		return (opt_two(a_stack));
	solution(a_stack, b_stack);
	delete_all_stack(a_stack, b_stack);
	return (0);
}
