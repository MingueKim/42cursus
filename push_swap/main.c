/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:07:19 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/17 22:23:10 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	push_swap(ac, av);
	// system("leaks push_swap > leaks_result; cat leaks_result | \
    // grep leaked && rm -rf leaks_result && rm -rf libft/libft.h.gch && rm -rf push_swap.h.gch");
	return (0);
}
