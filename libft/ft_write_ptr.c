/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:26:59 by tfranchi          #+#    #+#             */
/*   Updated: 2023/04/20 12:26:59 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(uintptr_t num)
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

void	ft_ptrtoa(uintptr_t num)
{
	if (num >= 16)
	{
		ft_ptrtoa(num / 16);
		ft_ptrtoa(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_write((num + '0'));
		else
			ft_write((num - 10 + 'a'));
	}
}

int	ft_write_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += ft_write_str("0x");
	if (ptr == 0)
		print_length += ft_write('0');
	else
	{
		ft_ptrtoa(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
