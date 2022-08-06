/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:50:46 by zhatsago          #+#    #+#             */
/*   Updated: 2021/04/03 14:50:49 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_precent(t_lst list_flags)
{
	int count;

	count = 0;
	if (list_flags.minus)
	{
		ft_putchar_fd('%', 1);
		count += ft_add_width(' ', list_flags.width - 1);
	}
	else if (!list_flags.minus)
	{
		if (list_flags.zero)
			count += ft_add_width('0', list_flags.width - 1);
		else
			count += ft_add_width(' ', list_flags.width - 1);
		ft_putchar_fd('%', 1);
	}
	return (count + 1);
}
