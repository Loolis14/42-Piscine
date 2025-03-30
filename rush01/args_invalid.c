/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_invalid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:53:40 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/16 16:22:12 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#ifndef GRID_SIZE
#define GRID_SIZE 4
#endif

int	is_valid_nbr(int n)
{
	return (n > 0 && n <= GRID_SIZE);
}

int	char_to_int(int c);

int	is_odd(size_t n)
{
	return (n % 2 != 0);
}

int	is_digit(int n);

int	are_valid_args(int argc, char *argv)
{
	int	nbr_count;
	size_t	i;

	if (argc != 2)
		return (0);
	i = 0;
	nbr_count = 0;
	while (argv[i] != '\0')
	{
		if (is_odd(i))
		{
			if (argv[i] != ' ')
				return (0);
		}
		else
		{
			if (!is_digit(argv[i]) || !is_valid_nbr(char_to_int(argv[i])))
				return (0);
			++nbr_count;
		}
		++i;
	}
	if (nbr_count != GRID_SIZE * 4)
		return (0);
	return (1);
}
