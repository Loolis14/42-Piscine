/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:10:56 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/16 16:20:53 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // provides size_t, STDOUT_FILENO, write
#ifndef GRID_SIZE
#define GRID_SIZE 4
#endif

void	print_digit(int n)
{
	n += '0';
	write(1, &n, 1);
}

void	print_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			print_digit(grid[i][j]);
			++j;
			if (j < GRID_SIZE)
			{
				write(1, " ", 1);
			}
			else
			{
				write(1, "\n", 1);
			}
		}
		++i;
	}
}

