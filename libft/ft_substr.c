/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:22:06 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/03 11:42:11 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (!s || start >= ft_strlen((char *)s))
	{
		new = ft_calloc(1, sizeof(char));
		if (new != NULL)
			new[0] = '\0';
		return (new);
	}
	while (s[start + i] && i < len)
		i++;
	new = ft_calloc((i + 1), sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start + i] != '\0'))
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
