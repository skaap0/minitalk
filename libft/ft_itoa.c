/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 08:39:53 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/02 14:28:10 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int nb)
{
	unsigned int	n;

	n = 0;
	if (nb <= 0)
		n++;
	while (nb)
	{
		n++;
		nb /= 10;
	}
	return (n);
}

char	*ft_itoa(int nb)
{
	char			*c;
	unsigned int	s;
	int				l;

	s = nb;
	l = ft_count(nb);
	if (nb < 0)
		s *= -1;
	c = (char *)ft_calloc((l + 1), sizeof(char));
	if (c != NULL)
	{
		c[l] = '\0';
		if (nb < 0)
			c[0] = '-';
		else if (nb == 0)
			c[0] = '0';
		while (s != 0)
		{
			l--;
			c[l] = (s % 10 + '0');
			s /= 10;
		}
	}
	return (c);
}
