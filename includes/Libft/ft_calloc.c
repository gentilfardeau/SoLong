/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:52:51 by tbras             #+#    #+#             */
/*   Updated: 2023/12/12 13:52:52 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = nmemb * size;
	if ((!nmemb && size) || (!size && nmemb))
		i = 1;
	if (size && nmemb)
	{
		if (i > 4294967295 / size)
			return (NULL);
	}
	ptr = malloc(i);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, i);
	return (ptr);
}
