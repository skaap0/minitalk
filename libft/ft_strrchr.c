/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:09:46 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/03 13:03:59 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occurence;

	i = ft_strlen(s);
	last_occurence = NULL;
	if (c == '\0')
	{
		last_occurence = ((char *)&s[i]);
		return (last_occurence);
	}
	if (s[1] == '\0')
		return (NULL);
	while ((char)c != s[i] && i != 0)
	{
		i--;
		if ((char)c == s[i])
			last_occurence = ((char *)&s[i]);
	}
	if ((char)c == s[i])
		last_occurence = ((char *)&s[i]);
	return (last_occurence);
}
