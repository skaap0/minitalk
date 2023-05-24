/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:37:26 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/02 14:39:04 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	res = n;
	if (res > 9)
	{
		ft_putnbr_fd(res / 10, fd);
		res %= 10;
	}
	ft_putchar_fd('0' + res, fd);
}
