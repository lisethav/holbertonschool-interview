#include "sandpiles.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * print_grid - prints 3 x 3 matrix of integers with 1 space in the horizontal
 *
 * @grid: 3 x3 matrix of integers to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple_grid - any integer in grid over 4 is "toppled,"
 *
 * @grid: 3 x 3 matrix of integers
 * @t_points: array of matrix coordinates determined to need toppling;
 * t_points[n][0] of -1 serves as terminal byte in series
 */
void topple_grid(int grid[3][3], int t_points[9][2])
{
	int i, j, k;

	for (k = 0; k < 9 && t_points[k][0] != -1; k++)
	{
		i = t_points[k][0];
		j = t_points[k][1];
		/* spill left */
		if (j > 0)
			grid[i][j - 1]++;
		/* spill right */
		if (j < 2)
			grid[i][j + 1]++;
		/* spill up */
		if (i > 0)
			grid[i - 1][j]++;
		/* spill down */
		if (i < 2)
			grid[i + 1][j]++;
		/* subtract spillage */
		grid[i][j] -= 4;
	}
}

/**
 * sandpiles_sum - adds two matrices of integers and then redistributes values
 *
 * @grid1: 3 by 3 matrix of integers, will contain toppled sum of grid1 + grid2
 * @grid2: 3 by 3 matrix of integers to add to grid1
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, k;
	int t_points[9][2];
	bool stable;

	/* sum matricies */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	do {
		/* check stability and set topple points */
		stable = true;
		k = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					stable = false;
					t_points[k][0] = i;
					t_points[k][1] = j;
					k++;
				}
			}
		}
		if (k < 8)
			t_points[k][0] = -1;

		if (!stable)
		{
			printf("=\n");
			print_grid(grid1);

			topple_grid(grid1, t_points);
		}

	} while (!stable);
}
