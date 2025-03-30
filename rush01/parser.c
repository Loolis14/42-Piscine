/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:09:33 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/16 16:19:25 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // provides size_t
#ifndef GRID_SIZE
#define GRID_SIZE 4
#endif

int	char_to_int(int c)
{
	return (c - '0');
}

int	is_digit(int n)
{
	return (n >= '0' && n <= '9');
}

void	parse_args(int hints[4][GRID_SIZE], char *argv)
{
	size_t	i;
	int	nbr_count;
	int	nbr;

	i = 0;
	nbr_count = 0;
	while (argv[i] != '\0')
	{
		if (!is_digit(argv[i]))
		{
			++i;
			continue ;
		}
		nbr = char_to_int(argv[i]);
		++nbr_count;
		hints[(nbr_count - 1) / GRID_SIZE][(nbr_count - 1) % GRID_SIZE] = nbr;
		++i;
	}
}
