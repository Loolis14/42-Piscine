/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:18:09 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/17 10:21:20 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*p;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	p = malloc(sizeof (int) * (max - min));
	if (p == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (min < max)
	{
		p[i] = min;
		++min;
		++i;
	}
	p[i] = '\0';
	return (p);
}
