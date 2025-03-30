/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:12:00 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/16 15:13:43 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * The assignment suggests that custom header files won't be included, so we
 * have no choice but to redefine this in each file that references it.
 */
#ifndef GRID_SIZE
/**
 * Defines the length of the edges of the grid.
 * Compile with -D GRID_SIZE=n to set GRID_SIZE to n.
 */
#define GRID_SIZE 4
#endif

// x = ligne, y la colonne, num c'est le chiffre a chercher 
int	is_valid_cell(int grid[GRID_SIZE][GRID_SIZE], int x, int y, int num) //a definir ?)
{
	size_t	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (grid[x][i] == num || grid[i][y] == num)
		{
			return (0);
		}
		++i;
	}
	return (1);
}
