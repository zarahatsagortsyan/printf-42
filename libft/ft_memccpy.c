/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:31:14 by zhatsago          #+#    #+#             */
/*   Updated: 2021/04/05 15:31:17 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	src = (unsigned char *)source;
	ch = (unsigned char)c;
	while (i < n)
	{
		d[i] = src[i];
		if (src[i] == ch)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
