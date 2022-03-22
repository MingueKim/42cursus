/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:50:09 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/11 21:43:22 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (dstsize <= len_dest)
		return (dstsize + len_src);
	if (dstsize > len_dest)
	{
		while ((len_dest + i + 1) < dstsize && src[i])
		{
			dest[len_dest + i] = src[i];
			i++;
		}
	}
	dest[len_dest + i] = 0x00;
	return (len_dest + len_src);
}
