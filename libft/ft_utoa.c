/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:34:50 by zhatsago          #+#    #+#             */
/*   Updated: 2021/04/05 15:34:52 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_num(long n)
{
	int	i;

	i = 1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_utoa(unsigned int n)
{
	char	*str;
	int		size;
	long	num;

	num = n;
	size = count_num(num);
	if (n == 0)
		return (str = ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * size)))
		return (0);
	str[--size] = '\0';
	while (num / 10 >= 1)
	{
		str[--size] = (num % 10) + '0';
		num /= 10;
	}
	str[0] = (num % 10) + '0';
	return (str);
}
