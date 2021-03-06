/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:26:11 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/15 21:58:02 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef enum e_type
{
	TRUE = 1,
	FALSE = 0,
	ERROR = -1,
}	t_type;

typedef enum e_command
{
	PA = 1,
	PB = 2,
	RA = 3,
	RB = 4,
	RR = 5,
	RRA = 6,
	RRB = 7,
	RRR = 8,
	SA = 9,
	SB = 10,
	SS = 11,
}	t_command;

typedef struct s_stack_node
{
	long				value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_linked_stack
{
	ssize_t			element_count;
	t_stack_node	top_node;
}	t_linked_stack;

typedef struct s_information
{
	long		pivot_a;
	long		pivot_b;
	ssize_t		pa_count;
	ssize_t		pb_count;
	ssize_t		ra_count;
	ssize_t		rb_count;
}	t_info;

int				push_swap(int ac, char **av);
/**************************************************************** 
Function : Function for stack
*****************************************************************/
t_stack_node	*create_node(long value);
void			create_stacks(t_linked_stack **a_ptr, t_linked_stack **b_ptr);
int				is_linked_stack_empty(t_linked_stack *stack);
int				delete_all_stack(t_linked_stack *as, \
									t_linked_stack *bs);
void			find_minimum_two(t_linked_stack *as, long *min_ptr, \
									long *second_min_ptr);
/**************************************************************** 
Function : Function for stack action
*****************************************************************/
t_stack_node	*pop_on_top(t_linked_stack *stack);
t_stack_node	*pop_on_bottom(t_linked_stack *stack);
int				push_top(t_linked_stack *stack, long value);
int				push_bottom(t_linked_stack *stack, long value);
int				push(t_linked_stack *push_stack, t_linked_stack *pop_stack, \
						t_command command);
/**************************************************************** 
Function : Function for swap
*****************************************************************/
int				single_swap(t_linked_stack *stack, t_command command);
int				both_swap(t_linked_stack *as, t_linked_stack *bs);
/**************************************************************** 
Function : Function for reverse rotate
*****************************************************************/
int				single_reverse_rotate(t_linked_stack *stack, t_command command);
int				both_reverse_rotate(t_linked_stack *as, t_linked_stack *bs);
/**************************************************************** 
Function : Function for stack rotate
*****************************************************************/
int				single_rotate(t_linked_stack *stack, t_command command);
int				both_rotate(t_linked_stack *as, t_linked_stack *bs);
/**************************************************************** 
Function : Function for optimazation
*****************************************************************/
int				opt3(t_linked_stack *as, t_linked_stack *bs);
void			opt3_case1(t_linked_stack *as, t_linked_stack *bs, long *tmb);
void			opt3_case2(t_linked_stack *as, t_linked_stack *bs, long *tmb);

int				opt_actual3(t_linked_stack *as);
void			opt_actual3_case1(t_linked_stack *as, long *tmb);
void			opt_actual3_case2(t_linked_stack *as, long *tmb);

int				reversed_opt3(t_linked_stack *as, t_linked_stack *bs);
void			reversed_opt3_case1(t_linked_stack *as, \
										t_linked_stack *bs, long *tmb);
void			reversed_opt3_case2(t_linked_stack *as, \
										t_linked_stack *bs, long *tmb);

int				reversed_opt_actual3(t_linked_stack *as, \
											t_linked_stack *bs);
void			reversed_actual3_case1(t_linked_stack *as, \
										t_linked_stack *bs, long *tmb);
void			reversed_actual3_case2(t_linked_stack *as, \
										t_linked_stack *bs, long *tmb);

int				opt2(t_linked_stack *as, t_linked_stack *bs);

int				reversed_opt2(t_linked_stack *as, t_linked_stack *bs);

int				opt5(t_linked_stack *as, t_linked_stack *bs);

int				a_opt(t_linked_stack *as, t_linked_stack *bs, ssize_t k);
int				b_opt(t_linked_stack *as, t_linked_stack *bs, ssize_t k);
/**************************************************************** 
Function : Function for handling exception						*
*****************************************************************/
int				response_error(void);
int				is_swap_exception(t_linked_stack *as);
int				free_struct_helper(t_info *info, t_type flag);
/**************************************************************** 
Function : Function for validation
*****************************************************************/
void			validator(int ac, char **av, \
							t_linked_stack *as, t_linked_stack *bs);
/**************************************************************** 
Function : Function for mapping information
*****************************************************************/
t_info			*create_info(long pivot_a, long pivot_b);
/**************************************************************** 
Function : Function for sort
*****************************************************************/
int				solution(t_linked_stack *as, t_linked_stack *bs);
int				select_pivot(t_linked_stack *stack, ssize_t range, \
								long *pivot_a_ptr, long *pivot_b_ptr);
int				is_sorted(t_linked_stack *stack, ssize_t range);
int				rollback_stacks(t_linked_stack *as, t_linked_stack *bs, \
								t_info *info);
int				a_to_b(t_linked_stack *as, t_linked_stack *bs, \
							ssize_t count);
int				b_to_a(t_linked_stack *as, t_linked_stack *bs, ssize_t count);
int				run_rotate(t_linked_stack *stack, t_command cmd, t_info *info);
int				run_push(t_linked_stack *as, t_linked_stack *bs, \
							t_command cmd, t_info *info);
void			divide_groups(t_linked_stack *as, t_info **info_ptr, \
								ssize_t count);
#endif