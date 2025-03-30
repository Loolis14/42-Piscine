/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:00:07 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/16 15:05:34 by mmeurer          ###   ########.fr       */
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
# define GRID_SIZE 4
#endif

int	check_col_up(int grid[GRID_SIZE][GRID_SIZE], int hint, size_t col)
{
	int	highest_seen;
	int	seen_count;
	size_t	row;

	row = 0;
	highest_seen = 0;
	seen_count = 0;
	while (row < GRID_SIZE)
	{
		if (grid[row][col] > highest_seen)
		{
			highest_seen = grid[row][col];
			++seen_count;
		}
		++row;
	}
	return (seen_count == hint);
}

int	check_col_down(int grid[GRID_SIZE][GRID_SIZE], int hint, size_t col)
{
	int	highest_seen;
	int	seen_count;
	size_t	row;

	row = GRID_SIZE - 1;
	highest_seen = 0;
	seen_count = 0;
	while (row >= 0)
	{
		if (grid[row][col] > highest_seen)
		{
			highest_seen = grid[row][col];
			++seen_count;
		}
		--row;
	}
	return (seen_count == hint);
}

int	check_row_left(int grid[GRID_SIZE][GRID_SIZE], int hint, size_t row)
{
	int	highest_seen;
	int	seen_count;
	size_t	col;

	col = 0;
	highest_seen = 0;
	seen_count = 0;
	while (col < GRID_SIZE)
	{
		if (grid[row][col] > highest_seen)
		{
			highest_seen = grid[row][col];
			++seen_count;
		}
		++col;
	}
	return (seen_count == hint);
}

int	check_row_right(int grid[GRID_SIZE][GRID_SIZE], int hint, size_t row)
{
	int	highest_seen;
	int	seen_count;
	size_t	col;

	col = GRID_SIZE - 1;
	highest_seen = 0;
	seen_count = 0;
	while (col >= 0)
	{
		if (grid[row][col] > highest_seen)
		{
			highest_seen = grid[row][col];
			++seen_count;
		}
		--col;
	}
	return (seen_count == hint);
}

int check_grid(int grid[GRID_SIZE][GRID_SIZE], int hints[4][GRID_SIZE])
{
	if (check_col_down != 0 
			|| check_col_up != 0 
			|| check_row_left != 0 
			|| check_row_right != 0)
	{
		return (0);
	}
	return (1);
}
