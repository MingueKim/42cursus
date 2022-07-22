/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:50:59 by mingkim         #+#    #+#             */
/*   Updated: 2022/07/21 22:07:14 by mingkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	response_error(char *msg, int signal)
{
	write(2, msg, ft_strlen(msg));
	exit(signal);
}
