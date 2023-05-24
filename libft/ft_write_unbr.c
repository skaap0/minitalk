/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:35:48 by tfranchi          #+#    #+#             */
/*   Updated: 2023/04/19 15:35:48 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	char			*c;
	int				len;

	len = ft_count(nb);
	c = (char *)malloc((len + 1) * sizeof(char));
	if (!c)
		return (0);
	c[len] = '\0';
	while (nb != 0)
	{
		c[len - 1] = (nb % 10 + 48);
		nb /= 10;
		len--;
	}
	return (c);
}

int	ft_write_unbr(unsigned int nb)
{
	int		len;
	char	*unbr_char;

	len = 0;
	if (nb == 0)
		return (ft_write('0'));
	else
	{
		unbr_char = ft_uitoa (nb);
		len = ft_write_str (unbr_char);
		free (unbr_char);
	}
	return (len);
}
