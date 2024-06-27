/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:41:16 by tbras             #+#    #+#             */
/*   Updated: 2023/11/22 20:22:37 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	tc;

	i = 0;
	str = (char *)s;
	tc = (char)c;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (str[i] == tc)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
