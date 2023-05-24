/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:52:19 by tfranchi          #+#    #+#             */
/*   Updated: 2023/04/06 08:52:19 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_define_format(const char str, va_list args)
{
	if (str == '%')
		return (ft_write('%'));
	else if (str == 'c')
		return (ft_write(va_arg(args, int)));
	else if (str == 's')
		return (ft_write_str(va_arg(args, char *)));
	else if (str == 'd' || str == 'i')
		return (ft_write_nbr(va_arg(args, int)));
	else if (str == 'u')
		return (ft_write_unbr(va_arg(args, unsigned int)));
	else if (str == 'p')
		return (ft_write_ptr(va_arg(args, unsigned long long)));
	else if (str == 'x' || str == 'X')
		return (ft_write_hex(va_arg(args, unsigned int), str));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			size += ft_define_format (*str, args);
		}
		else
		{
			ft_write (*str);
			size++;
		}
		str++;
	}
	va_end (args);
	return (size);
}
