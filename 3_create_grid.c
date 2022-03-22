/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_create_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:13:47 by trnguyen          #+#    #+#             */
/*   Updated: 2022/03/21 12:33:15 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* calculate the minimum size of the grid */
void	ft_get_min_grid_size(t_solution *solution)
{
	int	cells;

	cells = solution->nbr_pieces * 4;
	if (ft_sqrt(cells) > 0)
		solution->min_size = ft_sqrt(cells);
	else
		solution->min_size = ft_find_next_sqrt(cells);
}

/* malloc char array for grid and fill it with '.'*/
void	ft_create_grid(t_solution *solution)
{
	int	i;

	i = 0;
	if (solution)
	{
		solution->grid = (char **)ft_memallocarray(solution->min_size, \
		solution->min_size);
		while (i < solution->min_size)
		{
			ft_memset(solution->grid[i], '.', solution->min_size);
			i++;
		}
	}
}

/* place the piece in the solution grid with the designated character*/
void	ft_place_piece(t_solution *solution, t_tetri *piece, char ch)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		solution->grid[piece->x_coord[i]][piece->y_coord[i]] = ch;
		i++;
	}
}
