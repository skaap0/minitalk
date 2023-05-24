/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:45:20 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/03 11:41:15 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	size1;
	unsigned int	size2;

	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	new = (char *)ft_calloc((size1 + size2 + 1), sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, (char *)s1, size1 + 1);
	ft_strlcat(new, (char *)s2, size1 + 1 + size2);
	return (new);
}
