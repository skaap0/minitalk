/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:38:38 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/02 15:00:47 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ret;

	if (n == SIZE_MAX)
		return (NULL);
	ret = malloc(size * n);
	if (ret == NULL)
		return (0);
	if (ret != NULL || (n != 0 && size != 0))
		ft_bzero(ret, size * n);
	else
		ret = NULL;
	return (ret);
}
