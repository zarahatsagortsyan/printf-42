/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:50:13 by zhatsago          #+#    #+#             */
/*   Updated: 2021/04/03 14:50:16 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_char(t_lst list_flags, va_list argv)
{
	if (list_flags.minus == 1 && list_flags.width > 1)
	{
		ft_putchar_fd(va_arg(argv, int), 1);
		ft_add_width(' ', list_flags.width - 1);
		return (list_flags.width);
	}
	else if (list_flags.minus == 0 && list_flags.width > 1)
		ft_add_width((list_flags.zero) ? '0' : ' ', list_flags.width - 1);
	ft_putchar_fd(va_arg(argv, int), 1);
	if (list_flags.width > 1)
		return (list_flags.width);
	return (1);
}
