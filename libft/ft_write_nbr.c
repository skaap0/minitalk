/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:50:47 by tfranchi          #+#    #+#             */
/*   Updated: 2023/04/19 14:50:47 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int nb)
{
	unsigned int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char			*c;
	unsigned int	s;
	int				l;

	s = nb;
	l = ft_size(nb);
	if (nb < 0)
		s *= -1;
	c = (char *)malloc((l + 1) * sizeof(char));
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

int	ft_write_nbr(int nb)
{
	int		len;
	char	*nb_char;

	len = 0;
	nb_char = ft_itoa (nb);
	len = ft_write_str (nb_char);
	free (nb_char);
	return (len);
}
