/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:41:24 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/15 15:23:08 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	void	*fp;
	int		ret_size;

	ret_size = 0;
	if (!format)
		return (ERR);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == PERCENT)
				ret_size += conversion_percent();
			else if (assign_func(&fp, *format) == OK)
				ret_size += (*(t_func)fp)(&ap);
		}
		else
			ret_size += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (ret_size);
}
