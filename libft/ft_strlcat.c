/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:25:26 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/03 12:38:37 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = -1;
	if (dstsize == 0 && dst == NULL)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	while (src[++i] && i < dstsize - len - 1)
		dst[len + i] = src[i];
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
