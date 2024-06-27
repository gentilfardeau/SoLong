/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:49:28 by tbras             #+#    #+#             */
/*   Updated: 2023/11/25 17:34:56 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sizeitoa(int n)
{
	size_t		i;
	long int	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb / 10 >= 1)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ps;
	long int	nb;
	size_t		i;

	nb = n;
	i = ft_sizeitoa(nb);
	ps = ft_calloc(sizeof(char), i + 1);
	if (!ps)
		return (NULL);
	ps[i] = '\0';
	if (nb < 0)
	{
		ps[0] = '-';
		nb *= -1;
	}
	while (i-- && ps[i] != '-')
	{
		ps[i] = nb % 10 + '0';
		nb = (nb - (nb % 10)) / 10;
	}
	return (ps);
}
