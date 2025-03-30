/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:25:50 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/12 09:53:34 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_len(char *dest)
{
	size_t	len_d;
	size_t	i;

	len_d = 0;
	i = 0;
	while (dest[i])
	{
		len_d += 1;
		++i;
	}
	return (len_d);
}

char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	len_d;

	len_d = ft_len(dest);
	i = 0;
	while (src[i])
	{
		dest[len_d + i] = src[i];
		++i;
	}
	dest[len_d + i] = '\0';
	return (dest);
}
