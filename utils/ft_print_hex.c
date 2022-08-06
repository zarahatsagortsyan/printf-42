/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:51:12 by zhatsago          #+#    #+#             */
/*   Updated: 2021/04/03 14:51:14 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		check_hex_precision(t_lst list_flags, int size)
{
	int	i;

	if (list_flags.precision)
	{
		i = -1;
		while (++i < list_flags.precision - size)
			ft_putchar_fd('0', 1);
		return (i);
	}
	return (0);
}

int		print_hex_width(t_lst list_flags, int size)
{
	int	count;

	count = 0;
	if (list_flags.zero && !list_flags.minus && list_flags.precision < 0)
		count = ft_add_width('0', list_flags.width - size);
	else if (list_flags.precision >= size)
		count = ft_add_width(' ', list_flags.width - list_flags.precision);
	else
		count = ft_add_width(' ', list_flags.width - size);
	return (count);
}

int		check_minus_hex(t_lst list_flags, int size, char *str)
{
	int count;

	count = 0;
	if (list_flags.minus)
	{
		count += check_hex_precision(list_flags, size);
		ft_putstr_fd(str, 1);
		count += size;
		count += print_hex_width(list_flags, size);
	}
	else if (!list_flags.minus)
	{
		count += print_hex_width(list_flags, size);
		count += check_hex_precision(list_flags, size);
		ft_putstr_fd(str, 1);
		count += size;
	}
	return (count);
}

int		ft_print_hex(char *array_hex, t_lst list_flags, va_list argv)
{
	char			*str;
	int				size;
	int				count;
	unsigned int	num;

	count = 0;
	if (!(num = va_arg(argv, unsigned int)))
		str = ft_strdup("0");
	else
		str = ft_convert_pointer(array_hex, num);
	size = ft_strlen(str);
	if (list_flags.precision == 0 && str[0] == '0')
	{
		count += ft_add_width(' ', list_flags.width);
		return (count);
	}
	count += check_minus_hex(list_flags, size, str);
	free(str);
	return (count);
}
