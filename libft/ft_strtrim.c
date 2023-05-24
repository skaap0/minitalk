/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:20:06 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/03 13:07:35 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_char(char const c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_check_start(const char *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_check_char(s1[i], set) == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	ft_check_end(char const *s1, char const *set, size_t i)
{
	while (i > 0)
	{
		i--;
		if (ft_check_char(s1[i], set) == 0)
			break ;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	int		i;
	char	*new;

	if (!s1 || !set)
		return (0);
	e = ft_strlen(s1);
	s = ft_check_start(s1, set);
	if (s != e)
		e = ft_check_end(s1, set, e);
	new = (char *)ft_calloc(((e - s) + 1), sizeof(char));
	if (new != NULL)
	{
		i = 0;
		while (s < e)
		{
			new[i] = s1[s];
			i++;
			s++;
		}
		new[i] = '\0';
	}
	return (new);
}
