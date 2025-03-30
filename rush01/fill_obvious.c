/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obvious.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:06:01 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/16 16:17:14 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> // provides size_t
#ifndef GRID_SIZE
# define GRID_SIZE 4
#endif

void	fill_col_up(int grid[GRID_SIZE][GRID_SIZE], int n, int y)
{
    size_t	i;

    if (n == 1)
    {
        grid[y][0] = GRID_SIZE;
    }
    else if (n == GRID_SIZE)
    {
        i = 0;
        while (i < GRID_SIZE)
        {
            grid[y][i] = i + 1;
            ++i;
        }
    }
}

void	fill_col_down(int grid[GRID_SIZE][GRID_SIZE], int n, int y)
{
    size_t	i;

    if (n == 1)
    {
        grid[y][GRID_SIZE - 1] = GRID_SIZE;
    }
    else if (n == GRID_SIZE)
    {
        i = GRID_SIZE - 1;
        while (i > 0)
        {
            grid[y][i] = GRID_SIZE - i;
            --i;
        }
    }
}

void	fill_row_left(int grid[GRID_SIZE][GRID_SIZE], int n, int x)
{
    size_t	i;

    if (n == 1)
    {
        grid[0][x] = GRID_SIZE;
    }
    else if (n == GRID_SIZE)
    {
        i = 0;
        while (i < GRID_SIZE)
        {
            grid[i][x] = i + 1;
            ++i;
        }
    }
}

void	fill_row_right(int grid[GRID_SIZE][GRID_SIZE], int n, int x)
{
    size_t	i;

    if (n == 1)
    {
        grid[GRID_SIZE - 1][x] = GRID_SIZE;
    }
    else if (n == GRID_SIZE)
    {
        i = GRID_SIZE - 1;
        while (i < GRID_SIZE)
        {
            grid[i][x] = GRID_SIZE - i;
            --i;
        }
    }
}

void	fill_obvious(int hints[4][GRID_SIZE], int grid[GRID_SIZE][GRID_SIZE])
{
    size_t	i;
    size_t	j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < GRID_SIZE)
        {
            if (i == 0)
                fill_col_up(grid, hints[i][j], j);
            if (i == 1)
                fill_col_down(grid, hints[i][j], j);
            if (i == 2)
                fill_row_left(grid, hints[i][j], j);
            if (i == 3)
                fill_row_right(grid, hints[i][j], j);
            ++j;
        }
        ++i;
    }
}
