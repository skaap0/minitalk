/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:35:37 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/03 13:08:00 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ret;

	if (!s)
		return (0);
	ret = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (ret != NULL)
	{
		i = 0;
		while (s[i])
		{
			ret[i] = (*f)(i, s[i]);
			i++;
		}
		ret[i] = 0;
	}
	return (ret);
}
