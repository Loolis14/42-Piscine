/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:07:36 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/16 16:17:48 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#ifndef GRID_SIZE
#define GRID_SIZE 4
#endif

int	are_valid_args(int argc, char *args);
void	parse_args(int hints[4][GRID_SIZE], char *args);
void	fill_obvious(int hints[4][GRID_SIZE], int grid[GRID_SIZE][GRID_SIZE]);
void	print_grid(int grid[GRID_SIZE][GRID_SIZE]);

void	init_grid(int grid[GRID_SIZE][GRID_SIZE])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < GRID_SIZE)
	{
		j = 0;
		while (j < GRID_SIZE)
		{
			grid[i][j] = 0;
			++j;
		}
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int	hints[4][GRID_SIZE];
	int	grid[GRID_SIZE][GRID_SIZE];

	if (!are_valid_args(argc, argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	parse_args(hints, argv[1]);
	init_grid(grid);
	fill_obvious(hints, grid);
	print_grid(grid);
	/** 
	  if (!bruteforce(hints, grid))
	  {
	  write(STDOUT_FILENO, "Error\n", 6);
	  return (EXIT_FAILURE);
	  }
	  */
}
