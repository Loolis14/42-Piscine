/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:59:22 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/27 16:40:49 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_len(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

int	check_base(char *base)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = ft_len(base);
	if (size < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		++i;
	}
	i = 0;
	while (base[i])
	{
		j= i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sum;
	int	minus;
	int	size;

	size = ft_len(base);
	if (!check_base(base))
		return (0);
	i = 0;
        while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
                ++i;
        minus = 1;
        while (str[i] == '+' || str[i] == '-')
        {
                if (str[i] == '-')
                        minus *= -1;
                ++i;
        }
	sum = 0;
	while (str[i])
	{
		if (is_base(str[i], base) != -1)
		{
			sum = sum * size + is_base(str[i], base);
			++i;
		}
		else
			break ;
	}
	return (sum * minus);
}
