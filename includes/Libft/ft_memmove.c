/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:36:19 by tbras             #+#    #+#             */
/*   Updated: 2023/11/23 16:19:20 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptemp;
	char	*pdest;

	if (!src && !dst)
		return (NULL);
	i = 0;
	ptemp = (char *)src;
	pdest = (char *)dst;
	if (pdest > ptemp)
	{
		while (len-- > 0)
			pdest[len] = ptemp[len];
	}
	else
	{
		while (i < len)
		{
			pdest[i] = ptemp[i];
			i++;
		}
	}
	return (pdest);
}
