/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:37:10 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/11 23:44:15 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	divide_groups(t_linked_stack *stack, t_linked_stack *b_stack, \
					t_linked_stack *copied, t_info **info_ptr)
{
	t_stack_node	*node;
	size_t			idx;
	int				pivot_a;
	int				pivot_b;

	if (select_pivot(copied, &pivot_a, &pivot_b) == ERROR)
		return (delete_single_stack(copied));
	*info_ptr = create_info(pivot_a, pivot_b);
	if (!(*info_ptr))
		return (delete_single_stack(copied));
	return (OK);
}

int	solution(t_linked_stack *a_stack, t_linked_stack *b_stack)
{
	t_linked_stack	*copied;
	t_info			*info;

	if (!a_stack || !b_stack || is_linked_stack_empty(a_stack))
		return (ERROR);
	if (copy_stack(a_stack, &copied) == ERROR)
		return (ERROR);
	bubble_sort(copied);
	set_index(a_stack, copied);
	if (divide_groups(a_stack, b_stack, copied, &info) == ERROR)
		return (ERROR);
	step_one(a_stack, b_stack, info);
	display_stack(a_stack);
	display_stack(b_stack);
	free(info);
	delete_single_stack(copied);
	return (OK);
}
