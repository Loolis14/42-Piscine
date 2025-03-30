/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:17:15 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/14 09:16:53 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *dest)
{
	size_t	len_d;

	len_d = 0;
	while (dest[len_d])
	{
		++len_d;
	}
	return (len_d);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (j < nb && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	len_max;
	size_t	len_d;
	size_t	len_s;
	size_t	n;

	len_s = ft_len(src);
	len_d = ft_len(dest);
	len_max = ft_len(dest) + ft_len(src);
	if (len_d >= size)
	{
		return (size + len_s);
	}
	else
	{
		n = size - len_d - 1;
		ft_strncat(dest, src, n);
	}
	return (len_max);
}
