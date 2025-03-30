/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:23:03 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/15 10:13:15 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_space(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= '\t' && str[i] <= '\r'))
	{
		++i;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	sum;
	unsigned int	minus;

	i = ft_space(str);
	minus = 0;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			++minus;
		++i;
	}
	sum = 0;
	while (ft_isnum(str[i]))
	{
		sum = sum * 10 + str[i] - '0';
		++i;
	}
	if (minus % 2 == 0)
		return (sum);
	else if (minus % 2 != 0)
		return (-sum);
	else
		return (0);
}
