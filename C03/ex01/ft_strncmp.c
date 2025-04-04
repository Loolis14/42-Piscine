/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:34:59 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/11 16:16:59 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (n > 0 && s1[i])
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		else if (n == 1 && s1[i] == s2[i])
		{
			--n;
		}
		else
		{
			++i;
			--n;
		}
	}
	return (s1[i] - s2[i]);
}
