/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:07:55 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/02 14:28:19 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*src;

	src = (char *)s;
	i = 0;
	if (!n)
		return (NULL);
	while ((i < n - 1) && (char)c != src[i])
		i++;
	if ((char)c == src[i])
		return ((char *) s + i);
	else
		return (NULL);
}
