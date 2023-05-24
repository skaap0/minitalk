/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:08:43 by tfranchi          #+#    #+#             */
/*   Updated: 2023/05/01 11:08:43 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_hextoa(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_hextoa(num / 16, format);
		ft_hextoa(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_write((num + '0'));
		else
		{
			if (format == 'x')
				ft_write((num - 10 + 'a'));
			if (format == 'X')
				ft_write((num - 10 + 'A'));
		}
	}
}

int	ft_write_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hextoa(num, format);
	return (ft_hex_len(num));
}
