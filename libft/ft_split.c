/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:41:18 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/05 13:09:27 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_str(const char *s, char c)
{
	int	nbr_str;

	nbr_str = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != '\0' && *s != c)
				s++;
			nbr_str++;
			continue ;
		}
		s++;
	}
	return ((nbr_str));
}

static char	**ft_free_array(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	ft_is_char(const char*s, char c)
{
	if (*s == c)
		return (1);
	return (0);
}

static int	ft_next_char(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && !ft_is_char(s + i, c))
		i++;
	return (i);
}

char	**ft_split(const char *s, char c)
{
	int		nbs;
	char	**array;
	int		i;
	int		stop;

	if (!s)
		return (NULL);
	nbs = ft_nb_str(s, c);
	array = (char **)ft_calloc(((nbs) + 1), sizeof(char *));
	i = -1;
	if (!array)
		return (NULL);
	while (++i < (nbs))
	{
		while (*s && ft_is_char(s, c))
			s++;
		stop = ft_next_char(s, c);
		array[i] = ft_substr(s, 0, stop);
		if (!array[i])
			return (ft_free_array(array, i));
		s += stop;
	}
	array[i] = NULL;
	return (array);
}
