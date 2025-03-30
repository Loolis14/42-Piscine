/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:21:13 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/14 09:23:03 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		++len;
	}
	write(1, str, len);
	write(1, "\n", 1);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		++i;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort(char **argv, int argc)
{
	int	i;
	int	comp;
	int	swap;

	while (1)
	{
		i = 1;
		swap = 0;
		while (i < argc)
		{
			comp = ft_strcmp(argv[i - 1], argv[i]);
			if (comp > 0)
			{
				ft_swap(&argv[i - 1], &argv[i]);
				swap = 1;
			}
			++i;
		}
		if (!swap)
			break ;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	ft_sort(argv + 1, argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		++i;
	}
}
