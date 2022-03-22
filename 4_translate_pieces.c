/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_translate_pieces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:52:54 by deelliot          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/17 14:27:56 by deelliot         ###   ########.fr       */
=======
/*   Updated: 2022/03/21 12:32:13 by trnguyen         ###   ########.fr       */
>>>>>>> e3d9b7e172bf12407f56705be3e00770450c9787
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*finds the lowest value in the array, and subtracts it from
<<<<<<< HEAD
each element in the array with the translate array function.*/

=======
each element in the array with the translate array function above.*/
>>>>>>> e3d9b7e172bf12407f56705be3e00770450c9787
void	ft_move_top_left(int *array)
{
	int	min;
	int	i;

	i = 0;
	min = array[i];
	while (i < 3)
	{
		if (min > array[i + 1])
			min = array[i + 1];
		i++;
	}
	ft_translate_array(array, (-min));
}

/* moves the pieces to the top most left area possible, and checks if the min
size is smaller than the max width/height of individual piece */
void	ft_translate_pieces(t_tetri **pieces, t_solution *solution)
{
	int	i;

	i = 0;
	while (i < solution->nbr_pieces)
	{
		ft_move_top_left(pieces[i]->x_coord);
		ft_move_top_left(pieces[i]->y_coord);
		i++;
	}
}

/* moves the rest of the pieces to the top-left most position */
void	ft_reset_pieces(t_tetri **pieces, int p)
{
	while (pieces[p])
	{
		ft_move_top_left(pieces[p]->x_coord);
		ft_move_top_left(pieces[p]->y_coord);
		p++;
	}
}
