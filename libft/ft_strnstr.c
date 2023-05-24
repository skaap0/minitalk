/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:05:57 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/02 14:43:16 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *tf, size_t len)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = NULL;
	if (len == 0 && !s1)
		return (NULL);
	if (tf[0] == '\0' || (len > 0 && s1 == tf))
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		while ((s1[i] != tf[0]) && s1[i] != '\0')
			i++;
		if (((i + ft_strlen(tf)) > len))
			return (NULL);
		if ((ft_strncmp(&s1[i], tf, ft_strlen(tf)) == 0))
		{
			ptr = (char *) &s1[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
