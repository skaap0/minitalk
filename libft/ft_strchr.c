/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:06:42 by tfranchi          #+#    #+#             */
/*   Updated: 2023/05/24 09:45:10 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*first_occurence;

	i = 0;
	first_occurence = NULL;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
		{
			first_occurence = ((char *) s + i);
			return (first_occurence);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		first_occurence = ((char *) s + i);
		return (first_occurence);
	}
	return (first_occurence);
}
