/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhatsago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:51:48 by zhatsago          #+#    #+#             */
/*   Updated: 2021/04/03 14:51:49 by zhatsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		check_precesion_str(char *str, int size, t_lst list_flags)
{
	int	i;

	i = 0;
	if (list_flags.precision >= 0 && list_flags.precision >= size)
		while (str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	else if (list_flags.precision >= 0 && list_flags.precision < size)
		while (i < list_flags.precision)
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	else
		while (str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	return (i);
}

int		check_prec(char *str, int size, t_lst list_flags)
{
	int	i;

	i = 0;
	if (list_flags.precision >= 0 && list_flags.precision >= size)
		while (str[i])
			i++;
	else if (list_flags.precision >= 0 && list_flags.precision < size)
		while (i < list_flags.precision)
			i++;
	else
		while (str[i])
			i++;
	return (i);
}

int		check_minus_str(char *str, int size, t_lst list_flags)
{
	int count;
	int res_prec;

	count = 0;
	res_prec = check_prec(str, size, list_flags);
	if (!list_flags.minus && list_flags.width > res_prec)
	{
		count += ft_add_width((list_flags.zero) ? '0' : ' ',
				list_flags.width - res_prec);
		count += check_precesion_str(str, size, list_flags);
	}
	else if (list_flags.minus && list_flags.width > res_prec)
	{
		count += check_precesion_str(str, size, list_flags);
		count += ft_add_width(' ', list_flags.width - res_prec);
	}
	else
		count += check_precesion_str(str, size, list_flags);
	return (count);
}

int		ft_print_str(t_lst list_flags, va_list argv)
{
	char	*str;
	int		size;
	int		count;

	count = 0;
	if (!(str = va_arg(argv, char *)))
		str = ft_strdup("(null)");
	size = ft_strlen(str);
	count += check_minus_str(str, size, list_flags);
	return (count);
}
