/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_validate_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:56:10 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/16 17:08:38 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*this function checks that there are the correct number of blocks
empty spaces and newlines*/

static int	ft_check_errors(char *tetri_str)
{
	int	block_count;
	int	empty_count;
	int	newline_count;

	block_count = 0;
	empty_count = 0;
	newline_count = 0;
	if (tetri_str[20] != '\n' || tetri_str[19] != '\n')
		return (0);
	while (*tetri_str)
	{
		if (*tetri_str == '#')
			block_count++;
		if (*tetri_str == '.')
			empty_count++;
		if (*tetri_str == '\n')
			newline_count++;
		tetri_str++;
	}
	return (newline_count == 5 && block_count == 4 && empty_count == 12);
}

/*this function assigns memory for each new tetrimoni struct, and converts the
buf str into a 2d array, which is saved in the struct*/

static t_tetri	*ft_create_tetri(char *tetri_str)
{
	t_tetri	*new_piece;
	int		row;
	int		col;

	row = 0;
	col = 0;
	new_piece = (t_tetri *)malloc(sizeof(t_tetri));
	if (!new_piece)
		return (NULL);
	new_piece->cells = (char **)ft_memallocarray(4, 4);
	if (!new_piece)
		return (NULL);
	while (*tetri_str != '\0')
	{
		if (*tetri_str != '\n')
			new_piece->cells[row][col] = *tetri_str;
		col++;
		if (*tetri_str == '\n')
		{
			row++;
			col = 0;
		}
		tetri_str++;
	}
	return (new_piece);
}

/*this just fills in the remaining variables in the struct */

static void	ft_store_tetri(t_tetri *new_piece, int piece_nbr)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (new_piece->cells[x][y] == '#')
			{
				new_piece->x_coord[i] = x;
				new_piece->y_coord[i] = y;
				new_piece->ch = 'A' + piece_nbr;
				i++;
			}
			y++;
		}
		x++;
	}
}

/* this checks that the pieces are correctly aligned */

static int	ft_check_alignment(t_tetri *new_piece)
{
	int	i;
	int	j;
	int	temp;
	int	count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			temp = (ft_abs((new_piece->x_coord[i] - new_piece->x_coord[j]))) + \
			(ft_abs((new_piece->y_coord[i] - new_piece->y_coord[j])));
			if (temp == 1)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/*loops through each piece in the file, checks for errors,
coverts str to 2d array, and then stores in it the struct*/

void	ft_validate_tetri(char *buf, t_tetri **pieces, t_solution *solution)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	len = ft_strlen(buf);
	while (i < len)
	{
		temp = ft_strndup(&buf[i], 21);
		if (ft_check_errors(temp) != 1)
			ft_error("error", pieces, solution);
		pieces[i / 21] = ft_create_tetri(temp);
		if (pieces[i / 21] == NULL)
			ft_error("error", pieces, solution);
		ft_store_tetri(pieces[i / 21], i / 21);
		if ((ft_check_alignment(pieces[i / 21]) < 3))
			ft_error("error", pieces, solution);
		i += 21;
		ft_strdel(&temp);
	}
	solution->nbr_pieces = i / 21;
}
